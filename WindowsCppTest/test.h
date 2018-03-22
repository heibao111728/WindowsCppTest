#pragma once
#ifndef __MYTEST_H__
#define __MYTEST_H__

#include <Windows.h>
#include <process.h>
#include <stdio.h>

class CTthreadTest
{
public:
	CTthreadTest();
	~CTthreadTest();

	void start();
	void stop();

	static void threadProc1(void * pVoid);
	static void threadProc2(void * pVoid);
	static void threadProc3(void * pVoid);

	void startThread1();
	void startThread2();
	void startThread3();

	void threadFunc1();
	void threadFunc2();
	void threadFunc3();

	void setValue(int i);

private:
	int m_value;
	bool m_bRuning;

	HANDLE m_threadHandle1;
	HANDLE m_threadHandle2;
	HANDLE m_threadHandle3;
};


#endif // !__MYTEST_H__