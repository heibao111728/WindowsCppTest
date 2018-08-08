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
*   功能：
*       把线程封装成类，方便后续使用，创建线程时需要指定线程名称，如果不指定，则使用默认名称 "myThread".
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
    *   作用：
    *       设置线程的名称，调试时使用；日常代码中使用成员变量 'm_threadName' 即可。
    */
    void SetThreadName(const char* threadName);

private:
    int m_value;
    bool m_bRuning;
    char m_threadName[40];
    DWORD m_threadId;               //线程ID
    HANDLE m_threadHandle;          //线程句柄

    /**
    *   变量名：m_ExitEvent
    *   作用：线程函数执行完成正常结束，或者收到该事件则立即结束; 通过控制该事件状态来强制结束线程
    */
    HANDLE m_ExitEvent; 
};


#endif // !__MYTEST_H__