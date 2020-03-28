/**
*   description:
*       universal thread. cross platform.
*
*   author:     yangdong
*   date:       20200328
*   home_page:  https://blog.csdn.net/heibao111728
*/

#ifndef __DTHREAD_H__
#define __DTHREAD_H__

#include <thread>
#include <mutex>

typedef void* (*thread_work)(void* thread_worker_param);

class dthread
{
public:
    dthread();
    ~dthread();

    void start();
    void stop();
    void join();

    void thread();

    bool joinable() const;
    bool is_running();

    void set_work(thread_work work, void* work_param);


private:
    std::thread m_thread;
    std::mutex  m_running_mutex;
    bool        m_is_running;

    thread_work m_work;
    void*       m_work_param;
};

#endif
