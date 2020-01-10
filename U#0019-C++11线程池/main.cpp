#include <iostream>
#include <cmath>
#include "thread_pool.h"

#define TASK_NUM   (32)
#define POOL_SIZE  (32)

// 必须是一个返回void类型的函数（线程池的任务规定的）
void my_sqrt(void* pData)
{
    float* p = (float*)(pData);

    *p = sqrt(*p);

    return;
}


int main(int argc, char* argv[])
{

    ThreadPool tp(POOL_SIZE); // 假设电脑上有32个逻辑核心(一般是16个PU，32个AS)

    float arr[TASK_NUM] = {0.0f};

    printf("before thread pool processing...\n");
    for(int i = 0; i < TASK_NUM; i++) {
        arr[i] = i;
        printf("arr[%d] = %f\n", i, arr[i]);
    }

    for(int i = 0; i < TASK_NUM; i ++) {
        tp.enqueue(my_sqrt, (void*)&arr[i]);
    }

    printf("after thread pool processing...\n");
    for(int i = 0; i < TASK_NUM; i++) {
        printf("arr[%d] = %f\n", i, arr[i]);
    }

    return 0;
}
