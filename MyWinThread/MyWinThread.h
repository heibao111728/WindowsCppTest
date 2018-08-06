#pragma once
#pragma once
#ifndef __MYTEST_H__
#define __MYTEST_H__

#include <Windows.h>
#include <process.h>
#include <stdio.h>

class CMyWinTthread
{
public:
    CMyWinTthread();
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

private:
    int m_value;
    bool m_bRuning;

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