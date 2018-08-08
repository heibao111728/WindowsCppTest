#include "MyWinThread.h"

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

//void CMyWinTthread::threadProc2(void * pVoid)
//{
//    if (NULL != pVoid)
//    {
//        ((CMyWinTthread*)pVoid)->threadFunc2();
//    }
//}
//
//void CMyWinTthread::threadProc3(void * pVoid)
//{
//    if (NULL != pVoid)
//    {
//        ((CMyWinTthread*)pVoid)->threadFunc3();
//    }
//}

void CMyWinTthread::startThread()
{
    m_threadHandle = (HANDLE)_beginthread(threadProc, 0, (void*)this);
}

//void CMyWinTthread::startThread2()
//{
//    m_threadHandle2 = (HANDLE)_beginthread(threadProc2, 0, (void*)this);
//}
//
//void CMyWinTthread::startThread3()
//{
//    m_threadHandle3 = (HANDLE)_beginthread(threadProc3, 0, (void*)this);
//}

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

//void CMyWinTthread::threadFunc2()
//{
//    while (m_bRuning)
//    {
//        printf("in thread2   m_value = %d\n", m_value);
//        Sleep(2 * 1000);
//    }
//}
//
//void CMyWinTthread::threadFunc3()
//{
//    while (m_bRuning)
//    {
//        printf("in thread3   m_value = %d\n", m_value);
//        Sleep(3 * 1000);
//    }
//}

void CMyWinTthread::setValue(int i)
{
    m_value = i;
}

void CMyWinTthread::start()
{
    m_bRuning = true;

    startThread();

    m_ExitEvent = CreateEvent(
        NULL,    // default security attributes
        TRUE,    // manual reset event
        FALSE,   // not signaled
        NULL);   // no name

    //startThread2();
    //startThread3();
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
    m_threadInfo.dwType = 0x1000;
    m_threadInfo.szName = threadName;
    m_threadInfo.dwThreadID = m_threadId;
    m_threadInfo.dwFlags = 0;

    __try 
    {
        RaiseException(MS_VC_EXCEPTION, 0, sizeof(m_threadInfo) / sizeof(ULONG_PTR), (ULONG_PTR*)&m_threadInfo);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) 
    {
    }
}

//  
// Usage: SetThreadName ((DWORD)-1, "MainThread");  
//  
//#include <windows.h>  
//const DWORD MS_VC_EXCEPTION = 0x406D1388;
//#pragma pack(push,8)  
//typedef struct tagTHREADNAME_INFO
//{
//    DWORD dwType; // Must be 0x1000.  
//    LPCSTR szName; // Pointer to name (in user addr space).  
//    DWORD dwThreadID; // Thread ID (-1=caller thread).  
//    DWORD dwFlags; // Reserved for future use, must be zero.  
//} THREADNAME_INFO;
//#pragma pack(pop)  
//void SetThreadName(DWORD dwThreadID, const char* threadName) {
//    THREADNAME_INFO info;
//    info.dwType = 0x1000;
//    info.szName = threadName;
//    info.dwThreadID = dwThreadID;
//    info.dwFlags = 0;
//#pragma warning(push)  
//#pragma warning(disable: 6320 6322)  
//    __try {
//        RaiseException(MS_VC_EXCEPTION, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
//    }
//    __except (EXCEPTION_EXECUTE_HANDLER) {
//    }
//#pragma warning(pop)  
//}