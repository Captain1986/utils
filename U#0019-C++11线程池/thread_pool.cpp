#include "thread_pool.h"

void Worker::operator()() {
  while(!_pool->_stop) {
    std::unique_lock<std::mutex> lock(_pool->_mutex);
    while(!_pool->_stop && _pool->_task_queue.empty()) {
      _pool->_condition.wait(lock);
    }
    if (_pool->_stop) {
      //lock.unlock();
      return;
    }
    
    //get the first task in the queue
    std::function<void()> task = _pool->_task_queue.front();
    _pool->_task_queue.pop();
    _pool->_inprogress++;
    lock.unlock();
    
    task(); //run the task
    
    //notify the task is finished - this is for the wait() function
    lock.lock();
    _pool->_inprogress--;
    _pool->_condition.notify_all();
    lock.unlock();
  }
}

ThreadPool::ThreadPool(const size_t threadcount)
    : _inprogress(0), _stop(false) {
  for (size_t i = 0; i < threadcount; i++) {
    Worker wk (this);
    _workers.push_back(std::thread(wk));
  }
}

ThreadPool::~ThreadPool() {
  std::unique_lock<std::mutex> lock(_mutex);
  _stop = true;
  _condition.notify_all();
  lock.unlock();
  
  for (size_t i = 0; i < _workers.size(); i++) {
    _workers.at(i).join();
  }
}

void ThreadPool::wait() {
  std::unique_lock<std::mutex> lock(_mutex);
  while(!_stop && (!_task_queue.empty() || _inprogress != 0)) {
    _condition.wait(lock);
  }
  //unlock releases
}
