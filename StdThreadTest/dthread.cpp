#include "dthread.h"

dthread::dthread()
{

}
dthread::~dthread()
{
    m_thread.join();
}

void dthread::start()
{
    m_is_running = true;

    m_thread = std::thread(&dthread::thread, this);
}


void dthread::stop()
{
    m_running_mutex.lock();
    m_is_running = false;
    m_running_mutex.unlock();
}

void dthread::join()
{
    m_thread.join();
}

void dthread::thread()
{
    while (is_running())
    {
        if (NULL != m_work)
        {
            m_work(m_work_param);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(0));
    }
}

bool dthread::joinable() const
{
    return m_thread.joinable();
}

bool dthread::is_running() 
{
    bool ret = false;

    m_running_mutex.lock();
    ret = m_is_running;
    m_running_mutex.unlock();

    return ret;
}

void dthread::set_work(thread_work work, void* work_param)
{
    m_work = work;
    m_work_param = work_param;
}