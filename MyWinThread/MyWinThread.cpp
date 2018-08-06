#include "MyWinThread.h"

CMyWinTthread::CMyWinTthread()
{
    m_value = 0;
    m_bRuning = true;
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
    while (m_bRuning)
    {
        printf("in thread1   m_value = %d\n", m_value++);
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