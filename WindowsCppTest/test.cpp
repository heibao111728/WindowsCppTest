#include "test.h"

CTthreadTest::CTthreadTest()
{
	m_value = 0;
	m_bRuning = true;
}

CTthreadTest::~CTthreadTest()
{
}

void CTthreadTest::threadProc1(void * pVoid)
{
	if (NULL != pVoid)
	{
		((CTthreadTest*)pVoid)->threadFunc1();
	}
}

void CTthreadTest::threadProc2(void * pVoid)
{
	if (NULL != pVoid)
	{
		((CTthreadTest*)pVoid)->threadFunc2();
	}
}

void CTthreadTest::threadProc3(void * pVoid)
{
	if (NULL != pVoid)
	{
		((CTthreadTest*)pVoid)->threadFunc3();
	}
}

void CTthreadTest::startThread1()
{
	m_threadHandle1 = (HANDLE)_beginthread(threadProc1, 0, (void*)this);
}

void CTthreadTest::startThread2()
{
	m_threadHandle2 = (HANDLE)_beginthread(threadProc2, 0, (void*)this);
}

void CTthreadTest::startThread3()
{
	m_threadHandle3 = (HANDLE)_beginthread(threadProc3, 0, (void*)this);
}

void CTthreadTest::threadFunc1()
{
	while (m_bRuning)
	{
		printf("in thread1   m_value = %d\n", m_value);
		Sleep(1 * 1000);
	}
	
}

void CTthreadTest::threadFunc2()
{
	while (m_bRuning)
	{
		printf("in thread2   m_value = %d\n", m_value);
		Sleep(2 * 1000);
	}
}

void CTthreadTest::threadFunc3()
{
	while (m_bRuning)
	{
		printf("in thread3   m_value = %d\n", m_value);
		Sleep(3 * 1000);
	}
}

void CTthreadTest::setValue(int i)
{
	m_value = i;
}

void CTthreadTest::start()
{
	m_bRuning = true;

	startThread1();
	startThread2();
	startThread3();
}

void CTthreadTest::stop()
{
	m_bRuning = false;
}
