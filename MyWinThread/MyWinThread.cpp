#include "MyWinThread.h"

/**
*   作用：
*       全局函数，做测试用，无实际作用（可删除）。
*/
int myPrintfVal(int a)
{
    int its_a = a;
    Sleep(its_a * 1000);
    return its_a;
}

CMyWinTthread::CMyWinTthread(const char* threadName )
{
    m_value = 0;
    m_bRuning = true;
    if(NULL != threadName)
    { 
        sprintf_s(m_threadName, "%s", threadName);
    }
}

CMyWinTthread::~CMyWinTthread()
{
}

void CMyWinTthread::threadProc(void * pVoid)
{
    if (NULL != pVoid)
    {
        ((CMyWinTthread*)pVoid)->threadFunc();
    }
}

void CMyWinTthread::startThread()
{
    m_threadHandle = (HANDLE)_beginthread(threadProc, 0, (void*)this);
}

void CMyWinTthread::threadFunc()
{
    m_threadId = GetCurrentThreadId();
    while (m_bRuning)
    {
        printf("in thread:%s   m_value = %d\n",m_threadName, myPrintfVal(m_value));
        Sleep(1 * 1000);

        if (m_value > 9)
        {
            stop();
        }
    }
}

void CMyWinTthread::setValue(int i)
{
    m_value = i;
}

void CMyWinTthread::start()
{
    m_bRuning = true;

    m_threadHandle = (HANDLE)_beginthread(threadProc, 0, (void*)this);

    m_ExitEvent = CreateEvent(
        NULL,    // default security attributes
        TRUE,    // manual reset event
        FALSE,   // not signaled
        NULL);   // no name
}

void CMyWinTthread::stop()
{
    //m_bRuning = false;
    SetEvent(m_ExitEvent);
}

void CMyWinTthread::join()
{
    WaitForSingleObject(m_ExitEvent, INFINITE);
}

void CMyWinTthread::SetThreadName(const char* threadName)
{
    THREADNAME_INFO threadInfo;   //保存线程名的结构体
    threadInfo.dwType = 0x1000;
    threadInfo.szName = threadName;
    threadInfo.dwThreadID = m_threadId;
    threadInfo.dwFlags = 0;

    __try 
    {
        RaiseException(MS_VC_EXCEPTION, 0, sizeof(threadInfo) / sizeof(ULONG_PTR), (ULONG_PTR*)&threadInfo);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) 
    {
    }
}
