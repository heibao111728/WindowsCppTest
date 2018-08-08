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
    DWORD dwType;       // Must be 0x1000.  
    LPCSTR szName;      // Pointer to name (in user addr space).  
    DWORD dwThreadID;   // Thread ID (-1=caller thread).  
    DWORD dwFlags;      // Reserved for future use, must be zero.  
} THREADNAME_INFO;


/**
*   ���ܣ�
*       ���̷߳�װ���࣬�������ʹ�ã������߳�ʱ��Ҫָ���߳����ƣ������ָ������ʹ��Ĭ������ "myThread".
*/
class CMyWinTthread
{
public:
    CMyWinTthread(const char* threadName = "myThread");
    ~CMyWinTthread();

    void start();
    void stop();
    void join();

    static void threadProc(void * pVoid);
    void startThread();
    void threadFunc();
    void setValue(int i);

    /**
    *   ���ã�
    *       �����̵߳����ƣ�����ʱʹ�ã��ճ�������ʹ�ó�Ա���� 'm_threadName' ���ɡ�
    */
    void SetThreadName(const char* threadName);

private:
    int m_value;
    bool m_bRuning;
    char m_threadName[40];
    DWORD m_threadId;               //�߳�ID
    HANDLE m_threadHandle;          //�߳̾��

    /**
    *   ��������m_ExitEvent
    *   ���ã��̺߳���ִ��������������������յ����¼�����������; ͨ�����Ƹ��¼�״̬��ǿ�ƽ����߳�
    */
    HANDLE m_ExitEvent; 
};


#endif // !__MYTEST_H__