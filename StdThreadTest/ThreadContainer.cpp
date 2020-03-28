#include "ThreadContainer.h"
#include <iostream>

using namespace std;

thread_container::thread_container()
{
    m_a = 5;
    m_b = 10;
}

thread_container::~thread_container()
{
    //m_dthread_producer.join();
    //m_dthread_customer.join();
}

void thread_container::producer_func(int a)
{
    cout << a << endl;
}

void thread_container::customer_func(int a)
{
    cout << a << endl;
}

int thread_container::start()
{
    m_dthread_producer.set_work(producer_thread_func, this);
    m_dthread_producer.start();
    //m_dthread_producer.join();

    m_dthread_customer.set_work(consumer_thread_func, this);
    m_dthread_customer.start();
   // m_dthread_customer.join();

    return 0;
}

int thread_container::stop()
{
    m_dthread_producer.stop();
    m_dthread_customer.stop();
    return 0;
}

void* thread_container::producer_thread_func(void* param)
{
    thread_container* container = (thread_container*)param;
    if (NULL != container)
    {
        container->producer_func(container->m_a);
    }

    return NULL;
}

void* thread_container::consumer_thread_func(void* param)
{
    thread_container* container = (thread_container*)param;
    if (NULL != container)
    {
        container->customer_func(container->m_b);
    }

    return NULL;
}