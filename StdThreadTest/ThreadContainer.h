#ifndef __THREAD_CONTAINER_H__
#define __THREAD_CONTAINER_H__

#include "dthread.h"

class thread_container
{
public:
    thread_container();
    ~thread_container();

    void producer_func(int a);
    void customer_func(int a);

    int start();
    int stop();

    static void* producer_thread_func(void* param);
    static void* consumer_thread_func(void* param);

    int m_a;
    int m_b;

    dthread m_dthread_producer;
    dthread m_dthread_customer;

private:
    //dthread m_dthread_producer;
    //dthread m_dthread_customer;

};

#endif // !__THREAD_CONTAINER_H__

