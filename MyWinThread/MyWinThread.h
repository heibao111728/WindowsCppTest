#pragma once
#pragma once
#ifndef __MYTEST_H__
#define __MYTEST_H__

#include <Windows.h>
#include <process.h>
#include <stdio.h>

const DWORD MS_VC_EXCEPTION = 0x406D1388;

typedef struct tagTHREADNAME_INFO
{
    DWORD dwType; // Must be 0x1000.  
    LPCSTR szName; // Pointer to name (in user addr space).  
    DWORD dwThreadID; // Thread ID (-1=caller thread).  
    DWORD dwFlags; // Reserved for future use, must be zero.  
} THREADNAME_INFO;

class CMyWinTthread
{
public:
    CMyWinTthread(const char* threadName = "myThread");
    ~CMyWinTthread();

    void start();
    void stop();
    void join();

    static void threadProc(void * pVoid);
    //static void threadProc2(void * pVoid);
    //static void threadProc3(void * pVoid);

    void startThread();
    //void startThread2();
    //void startThread3();

    void threadFunc();
    //void threadFunc2();
    //void threadFunc3();

    void setValue(int i);
    void SetThreadName(const char* threadName);

private:
    int m_value;
    bool m_bRuning;
    THREADNAME_INFO m_threadInfo;   //�����߳����Ľṹ��
    DWORD m_threadId;               //�߳�ID

    HANDLE m_threadHandle;

    /**
    *   ��������m_ExitEvent
    *   ���ã��̺߳���ִ��������������������յ����¼�����������; ͨ�����Ƹ��¼�״̬��ǿ�ƽ����߳�
    */
    HANDLE m_ExitEvent; 

    //HANDLE m_threadHandle2;
    //HANDLE m_threadHandle3;
};


#endif // !__MYTEST_H__