// 用C++11实现的一个简单线程池

#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future> // std::packaged_task
#include <thread>

// 提前声明
class ThreadPool;

class Worker {
public:
  Worker(ThreadPool* tp) : _pool(tp) {}
  void operator()();
  
private:
  ThreadPool* _pool;
};

class ThreadPool {
public:
  ThreadPool(const size_t threadcount);
  ~ThreadPool();
  
  // &&是右值引用
  // 注意：模板函数必须写在头文件里面！
  template<typename Func, typename Args>
  void enqueue(Func&& func, Args&& args) {
	  //create a shared pointer to a task and then put a lambda that
	  //executes that task in the queue
	  using rettype = typename std::result_of<Func(Args)>::type;
	  auto task = std::make_shared<std::packaged_task<rettype()>>(
				  std::bind(std::forward<Func>(func), std::forward<Args>(args)));

	  std::unique_lock<std::mutex> lock (_mutex);
	  _task_queue.push([task]() { (*task)(); } );
	  lock.unlock();

	  _condition.notify_one();
  }

  void wait();
  
private:
  friend Worker;
  std::vector<std::thread> _workers;
  std::queue<std::function<void()>> _task_queue;
  size_t _inprogress;
  
  std::mutex _mutex;
  std::condition_variable _condition;
  
  bool _stop;
};

#endif  // _THREAD_POOL_H_
