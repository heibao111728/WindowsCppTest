#if 0
#include <stdio.h>

class CA
{
public:
	CA():m_ia(3) {}
	~CA() {};

	void printMem() { printf("m_ia=%d\n", m_ia); }
private:
	int m_ia;
};

#endif


#if 0
int main()
{
#if 0
	int* p = 0;
	delete p;
#endif

#if 0
	CA a;
	a.printMem();
#endif

	int i;
	printf("input the value of i\n");
	scanf("%d", &i);
	printf("i = %d\n", i);

	printf("done\n");
	getchar();
	getchar();
	return 0;
}
#endif

#if 0
#include<stdio.h>
#define height 10
int calculate(int a, int b, int c)
{
	int x = a*b*c;
	return x;
}
int main()
{
	int mylong;
	int weight;
	int result;

	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ÎµÄ¸ß¶ï¿½Îªï¿½ï¿½%d\n", height);
	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ë³¤ï¿½ï¿½ï¿½ÎµÄ³ï¿½ï¿½ï¿½:\n");
	scanf("%d", &mylong);

	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ë³¤ï¿½ï¿½ï¿½ÎµÄ¿ï¿½È£ï¿½\n");
	scanf("%d", &weight);

	result = calculate(mylong, weight, height);
	printf("ï¿½ï¿½ï¿½ï¿½ï¿½Îµï¿½ï¿½ï¿½ï¿½Îªï¿½ï¿?d\n", result);
	getchar();
	getchar();
	getchar();

	return 0;

}
#endif 

#if 0
#include<stdio.h>

char a = 'A';
void exercise1()
{
	int iInt = 345;

	printf("iInt=%d\n", iInt);
}

void exercise4()
{
	extern char a;
	printf("ï¿½â²¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½%c\n", a);
}

void main()
{
	exercise4();
	getchar();
}

#endif

#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

class CA
{
public:
	CA(int a);
	void PrintVal() { cout << m_iTmp << endl; }
private:
	int m_iTmp;
};

CA::CA(int a ):
	m_iTmp(a)
{

}

class CB
{
public:
	CB(int a);
	void PrintVal() {  m_ca.PrintVal(); }
private:
	CA m_ca;
};

CB::CB(int a):
m_ca(a)
{
}

int main()
{
	CA a(5);
	CB b(6);
	a.PrintVal();
	b.PrintVal();
	getchar();
}
#endif

#if 0
#include <stdio.h>
#define a 7
#define b 5
#define c a
#define a b

#define c 6

int main()
{
	printf("%d\n", a);
	getchar();
	return 0;
}
#endif

#if 0
#include <stdio.h>

struct A
{
	int a;
	int b;
};

class CB
{
public:
	CB() 
	{ 
		m_struct_a.a = 3; 
		m_struct_a.b = 4;
	}

	void myprint() 
	{ 
		printf("m_struct_a.a=%d\n", m_struct_a.a);
		printf("m_struct_a.a=%d\n", m_struct_a.b);
	}
private:
	A m_struct_a;
};

int main()
{
	A str_a;
	str_a.a = 3;
	str_a.b = 4;

	CB b;
	b.myprint();
	printf("str_a.a = %d\n", str_a.a);
	printf("str_a.b = %d\n", str_a.b);
	getchar();
}

#endif

#if 0
#include <iostream>

using namespace std;

int main()
{
	wstring msg = L"123#abc#456#defghi#7890";
	wstring info;
	wstring imgUrl;
	wstring::size_type index = msg.rfind(L"#");
	if (wstring::npos != index)
	{
		//ï¿½ï¿½ï¿½Ò³É¹ï¿½ï¿½ï¿½
		imgUrl = msg.substr(index+1);
		info = msg.erase(index+1);
	}
	else
	{
		//ï¿½ï¿½ï¿½ï¿½Ê§ï¿½Ü£ï¿½ï¿½ï¿½ï¿½ï¿½
		return -1;
	}

	if (!info.empty()/* || !imgUrl.empty()*/)
	{
		
	}
	getchar();
	return 0;
}
#endif


#if 0
#include <iostream>

using namespace std;

int main()
{
	char* pBuf;
	pBuf = new char[1 * 1024 * 1024 ];
	memset(pBuf, 0x61, 1 * 1024 * 1024 );
	cout << pBuf << endl;

	/*int *a = new int[100];
	for (int i = 0; i<100; i++) {
		cout << a[i] <<endl;
	}*/

	getchar();
}

#endif

#if 0
#include <iostream>
#include "test.h"


using namespace std;

int main()
{
	int i = 0;
	CTthreadTest testThread;
	testThread.start();

	while (1)
	{
		testThread.setValue(i++);
		Sleep(1 * 1000);

		if (i > 9)
		{
			testThread.stop();
		}
	}
	
	return 0;
}

#endif

#if 0
/**
*	ï¿½ï¿½ï¿½ï¿½unsign char ï¿½ï¿½charï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
*/

#include <iostream>

using namespace std;


void f(char v)
{
	char c_c = v;
	unsigned char uc_c = v;

	unsigned int ui_a = c_c;
	unsigned int ui_b = uc_c;

	int i_i = c_c;
	int i_j = uc_c;

	printf("----------------\n");
	printf("%%c: %c, %c\n", c_c, uc_c);
	printf("%%X: %X, %X\n", c_c, uc_c);
	printf("%%u: %u, %u\n", ui_a, ui_b);
	printf("%%d: %d, %d\n", i_i, i_j);

}
int main()
{
	f(0x80);
	f(0x7F);

	getchar();

	return 0;
}

#endif

#if 0
/**
*	ï¿½ï¿½ï¿½ï¿½unsign char ï¿½ï¿½charï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
*/

#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <tchar.h>


using namespace std;

#define CREATE_DEBUG_CONSOLE \
	FILE* fpDebugOut = NULL; \
	FILE* fpDebugIn = NULL; \
	FILE* fpDebugErr = NULL; \
	if( !AllocConsole() ) \
	{}\
	SetConsoleTitle(TEXT("Debug Window")); \
	_tfreopen_s(&fpDebugOut, TEXT("CONOUT$"),TEXT("w"), stdout); \
	_tfreopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); \
	_tfreopen_s(&fpDebugErr, TEXT("CONOUT$"),TEXT("w"), stderr);

BOOL GetLocalIPList(vector<string>& vIPList)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err = 0;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		printf("%s","GetLocalIPList	: WSAStartup failed !");
		return FALSE;
	}

	char szhn[256] = { 0 };
	int nStatus = gethostname(szhn, sizeof(szhn));
	if (nStatus == SOCKET_ERROR)
	{
		printf("%s", "Socket	: Gethostname failed, Error code: %d", WSAGetLastError());
		return FALSE;
	}

	vIPList.clear();

	HOSTENT* host = gethostbyname(szhn);
	if (host != NULL)
	{
		for (int i = 0; ; i++)
		{
			vIPList.push_back(inet_ntoa(*(IN_ADDR*)host->h_addr_list[i]));
			if (host->h_addr_list[i] + host->h_length >= host->h_name)
			{
				break;
			}
		}
	}

	WSACleanup();
	return TRUE;
}

char* GethostIp(char* pHostIp, int nBufLen)
{
	if (pHostIp == NULL)
	{
		return NULL;
	}
	struct hostent* pH = NULL;
	char pHostName[100] = { 0 };
	gethostname(pHostName, 100);
	string hostNmae = pHostName;//ï¿½Ë´ï¿½ï¿½ï¿½Ã±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
	pH = gethostbyname(pHostName);

	char* pTmpHostIP = inet_ntoa(*((struct in_addr*)pH->h_addr_list[0]));//ï¿½Ë´ï¿½ï¿½ï¿½Ã±ï¿½ï¿½ï¿½IP

	strcpy_s(pHostIp, nBufLen, pTmpHostIP);

	return pHostIp;
}

bool createNewConsoleWindow()
{
	FILE* fpDebugOut = NULL; 
	FILE* fpDebugIn = NULL; 
	FILE* fpDebugErr = NULL; 
	if (!AllocConsole()) 
	{
		return false;
	}
	SetConsoleTitle(TEXT("Debug Window")); 

	//_tfreopen_s(&fpDebugOut, TEXT("CONOUT$"), TEXT("w"), stdout); 
	//_tfreopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); 
	//_tfreopen_s(&fpDebugErr, TEXT("CONOUT$"), TEXT("w"), stderr);

	freopen_s(&fpDebugOut, TEXT("CONOUT$"), TEXT("w"), stdout); 
	freopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); 
	freopen_s(&fpDebugErr, TEXT("CONOUT$"), TEXT("w"), stderr);

	freopen_s(&fpDebugOut, "CONOUT$", "w", stdout);
	freopen_s(&fpDebugIn, "CONIN$", "r", stdin);
	freopen_s(&fpDebugErr, "CONOUT$", "w", stderr);

	return true;
}

int main()
{
	int buf[10] = { 1,3,5,7,9,11 };
	for each (int var in buf)
	{
		printf("%d\n", var);
	}
	vector<string> hostipVector;
	GetLocalIPList(hostipVector);
	/*char hostIP[100] = { 0 };
	GethostIp(hostIP, 100);*/

	/*createNewConsoleWindow();
	printf("hello world\n");
	printf("ï¿½ï¿½ï¿½\n");*/

	char tmpSDP[4096] = { 0 };
	sprintf_s(tmpSDP, 4096,
		"v=0\r\n"
		"o=%s 0 0 IN IP4 %s\r\n"
		"s=Play\r\n"
		"c=IN IP4 %s\r\n",
		"123456789",
		"admin",
		"172.17.11.117");

	char* tmp = "abcd"
		"efgh"
		"igklmn";

	int iLen = strlen(tmp);


	printf("%s\n", tmpSDP);

	getchar();

	return 0;
}

#endif



#if 0

#include <iostream>

using namespace std;

int main()
{
	int a = 3;
	switch ( a )
	{
		case 1:
		{
			printf("a = 1\n");
		}
		case 2:
		{
			printf("a = 2\n");
		}

		case 3:
		{
			printf("a = 3\n");
		}

		case 4:
		{
			printf("a = 4\n");
		}

		default :
		{
			printf("a = 0\n");
		}
		
	}

	getchar();

	return 0;
}

#endif


#if 0

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//vector<> vct1;
	

	getchar();

	return 0;
}

#endif



#if 0

//c++ï¿½ì³£ï¿½ï¿½ï¿½Ô³ï¿½ï¿½ï¿½
#include <iostream>

using namespace std;

class myexception : public std::exception 
{
	public:
	myexception(std::string s) : exception(s.c_str()) {
	}

	virtual const char *what() const 
	{
		return exception::what();
	}
};

class A 
{
public:
	~A() 
	{
		printf("A's destructor\n");
	}
};

class B 
{
public:
	~B() 
	{
		printf("B's destructor\n");
	}

};

void Func() 
{
	A a;
	try 
	{
		int *p = NULL;
		if (p == NULL) 
		{
			throw myexception("p is NULL");  
		}
	}
	catch (myexception e) 
	{
		printf("%s\n", e.what());
		throw;
	}
	catch (std::exception e) 
	{
		printf("%s", e.what());
	}

	B b;
}


void Func2() 
{
	Func();
}

int main() 
{
	int a = 2;
	int b = 3;
	int c = 0;
	int sum;
	try
	{
		//Func2();
		//sum = a / c;
		throw 1;
	}
	catch (std::exception e)
	{
		printf("main exception \n");
		printf("%s", e.what());
	}
	catch(...)
	{
	}

	system("PAUSE");
	return 0;
}

#endif

#if 0
// c++ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô³ï¿½ï¿½ï¿?
/**
*	ï¿½ï¿½rand()ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ð¶ï¿½Îºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½Í¬ï¿½Ä£ï¿½Ô­ï¿½ï¿½ï¿½ï¿½Ä¬ï¿½Ïµï¿½ï¿½ï¿½ï¿½Ó¶ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½Ã¿ï¿½ï¿½Ö´ï¿½Ð²ï¿½ï¿½ï¿½ï¿½ï¿½
*	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¬ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½Ã²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½Ó£ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Îªï¿½Î¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó£ï¿½srand((int)time(NULL))ï¿½ï¿½Ã¿ï¿½ï¿½Ö´ï¿½ï¿½ï¿½ï¿½ï¿½Ó²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½É²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*
*
*	(a,b) (rand()%((b)-(a)+1))+(a)-1
*	[a,b) (rand()%((b)-(a)+1)-1)+(a)
*	(a,b] (rand()%((b)-(a)+1)-1)+(a)+1
*	[a,b] (rand()%((b)-(a)+1))+(a)
*/
#include <iostream>
#include<stdlib.h>
#include<time.h> 

#define RANDOM1(a,b)  (rand()%((b)-(a)+1))+(a)-1		//(a,b)
#define RANDOM2(a,b)  (rand()%((b)-(a)+1)-1)+(a)		//[a,b)
#define RANDOM3(a,b)  (rand()%((b)-(a)+1)-1)+(a)+1		//(a,b]
#define RANDOM4(a,b)  (rand()%((b)-(a)+1))+(a)			//[a,b]
using namespace std;

int Random(int m, int n)
{
	int pos, dis;
	if (m == n)
	{
		return m;
	}
	else if (m > n)
	{
		pos = n;
		dis = m - n + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = m;
		dis = n - m + 1;
		return rand() % dis + pos;
	}
}

 int getPort(int start, int end)
{
	int result = RANDOM4(start, end);
	return (result % 2) ? result + 1 : result;
}

int main()
{
	int tmp = 50000;
	int tmp2;
	short tmp3 = (short)tmp;
	tmp2 = tmp3;
	int i;
	srand((int)time(NULL)); //Ã¿ï¿½ï¿½Ö´ï¿½ï¿½ï¿½ï¿½ï¿½Ó²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½É²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?

	for (i = 0; i<10; i++)  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	{
		printf("%d\n", getPort(50000,50000));
	}

	system("pause");
	return 0;
}
#endif

#if 0
/** 
*   ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½outputï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*/
#include <iostream>
#include <stdio.h>
#include <Windows.h>
//#include <afx.h>

using namespace std;

int mysum(int a[], unsigned len)
{
	int i, sum = 0;
	for (i = 0; i <= len - 1;i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int sum = 0;

	sum = mysum(a, 5);
	printf("sum = %d\n", sum);

	//TRACE("***********ITMS_CCTV_StopPreview Ç° Ç°*************\r\n");

	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");

	system("pause");
	return 0;
}

#endif

#if 0

#include <iostream>
#include <stdio.h>
#include <WinSock2.h>
//#include "myMathLib\myMath.h"
#include "myMathDll\myMath.h"

using namespace std;


int main(int argc, char* argv[])
{
    int a = 200;
    int b = 3;

    int sum = 0;

    sum = add(a, b);

    printf("sum = %d\n", sum);


    system("pause");
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <string.h>

//ï¿½ï¿½1
struct S
{
    int a;
    char b;
};

//ï¿½ï¿½2
struct S2
{
    char x1;
    short x2;
    float x3;
    char x4;
};

//ï¿½ï¿½3
struct S3
{
    char a[10];
    int b;
};

//Ê¾ï¿½ï¿½2
class B
{
public:
    B() { printf("B()\n"); }
    virtual ~B() { printf("~B()\n"); }
private:
    int m_b;
};

class D : public B
{
public:
    D() { printf("D()\n"); }
    ~D() { printf("~D()\n"); }
private:
    int m_d;
};

int main()
{
    B* pB = new D();
    delete pB;
    
    return 0;
}

#endif

#if 0
/**
*   È·ï¿½ï¿½ï¿½ï¿½ï¿½Ðºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½constï¿½ï¿½ï¿½ï¿½ï¿½Ã£ï¿½
*   ï¿½ï¿½ï¿½ï¿½ï¿?
*       ï¿½ï¿½ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½constï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ¸Ã³ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Þ¸ï¿½ï¿½ï¿½Ä³ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*/

#include <stdio.h>
class A
{
public:
    A() {}
    virtual ~A() {}

public:
    int func1() const;

private:
    int m_a;
};

int A::func1() const
{
    printf("in func1()\n");
    return 0;
}

typedef struct _MyStruct
{
    int a;
    char pData[0];
} MyStruct;

int main(int argc, char* argv[], char *envp[])
{

    printf("sizeof(MyStruct):%d\n",sizeof(MyStruct));

    A a;
    a.func1();

    int i = 0;
    while (NULL != envp[i])
    {
        printf("envp[%d]= %s\n", i, envp[i]);
        i++;
    }

    return 0;
}

#endif


/**
*   hidden and override(Òþ²ØºÍ¸²¸Ç)
*   Òþ²Ø£ºµ±×ÓÀàÖÐµÄº¯ÊýÃûÓë¸¸ÀàÖÐµÄº¯ÊýÃû³ÆÒ»ÑùÊ±£¬²»ÂÛ²ÎÊýÁÐ±íÊÇ·ñÏàÍ¬£¬×ÓÀà¶¼»á½«¸¸ÀàµÄÍ¬Ãûº¯ÊýÒþ²Øµô£¬¼´×ÓÀà¶ÔÏó²»¿ÉÒÔ
*           Ê¹ÓÃ±»Òþ²ØµÄº¯Êý¡£
*   ¸²¸Ç£ºµ±

*   ·µ»ØÖµ²»ÄÜ×÷ÎªÖØÔØµÄÒÀ¾Ý£¬ÒòÎªÖØÔØµÄÔ­ÀíÊÇ±àÒëÆ÷ÖØÐÂÉú³ÉÁËº¯ÊýÃû£¬¶øÖØÐÂÉú³ÉµÄº¯ÊýÃû²»°üº¬·µ»ØÖµÐÅÏ¢¡£
*/
#if 0
#include <stdio.h>
#include <iostream>

class B 
{
public:
    virtual int fun1() = 0;

    int fun2(int a) { printf("fun2() in B fun2.\n"); return 0; }
    virtual void fun2(int a, int b) { printf("fun2() in B fun2.\n"); }
};

//int B::fun1()
//{
//    return 0;
//}

class S : public B
{
public:
    virtual int fun1();

    int fun2() { printf("fun2() in S fun2.\n"); return 0; }
};

int S::fun1()
{
    int a = 1;
    int b = 2;
    return a + b;
}

int main()
{
    S s;
    s.fun2();
	system("pause");
	return 0;
}

#endif

/**
*   function pointer
*/
#if 0

#include <stdio.h>

typedef int(*callback_add)(int a, int b);

int add(int a, int b)
{
    printf("%d+%d=%d\n",a, b, a + b);
    return 0;
}

#endif

#if 0

#include "stdio.h"

int main()
{
    printf("\n\nhuipo i love you !\n\n\n\n");
    //system()
    return 0;
}



int main()
{
    callback_add fun;
    fun = add;
    fun(2,3);

    return 0;
}
#endif

/**
*   virtual function and overload
*/
# if 0
#include <stdio.h>
class A
{
public:

    void func1() {}
    virtual void func1() {}
};

int main()
{
    A a;
    return 0;
}
#endif

/**
*   difference of delete and delete[]
*/
#if 0
#include <iostream>

using namespace std;

class A
{
private:
    int m_data;
public:
    A() { }
    ~A() { cout << "delete object." << endl; }
};

int main()
{
    A *a = new A[10];
    delete []a;
    //delete a;

    return 0;
}
#endif


//Éî¿½±´

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class media_packet
{
public:
    media_packet()
    {
        m_media_data = NULL;
        m_media_data_length = 0;
    }

    ~media_packet()
    {
        if (!m_media_data)
        {
            free(m_media_data);
            m_media_data = NULL;
        }
    }

    media_packet(unsigned char* data, int size)
    {
        m_media_data = (unsigned char*)malloc(size);

        if (NULL != m_media_data && 0 < size)
        {
            memcpy(m_media_data, data, size);
            m_media_data_length = size;
        }
        else
        {
            m_media_data_length = 0;
        }
    }

    media_packet& operator = (media_packet packet)
    {
        if (m_media_data == packet.m_media_data)
        {
            return *this;
        }
        if (NULL != m_media_data)
        {
            free(m_media_data);
            m_media_data = NULL;
            m_media_data_length = 0;

            if (!packet.m_media_data)
            {
                return *this;
            }

            m_media_data_length = packet.m_media_data_length;

            m_media_data = (unsigned char*)malloc(m_media_data_length);
            if (m_media_data)
            {
                memcpy(m_media_data, packet.m_media_data, m_media_data_length);
            }
        }
        else
        {
            m_media_data_length = packet.m_media_data_length;
            m_media_data = (unsigned char*)malloc(m_media_data_length);
            if (m_media_data)
            {
                memcpy(m_media_data, packet.m_media_data, m_media_data_length);
            }
        }
        return *this;
    }

    bool is_valid()
    {
        return (m_media_data && 0 < m_media_data_length);
    }

private:
    unsigned char* m_media_data;
    int m_media_data_length;

};

int main()
{
    media_packet packet_a;
    media_packet packet_c;

    packet_a = packet_a;
    //packet_c = packet_a;

    media_packet packet_b((unsigned char*)"abcdefghi", 10);
    //packet_c = packet_a = packet_b;
    //packet_a = packet_a;

    packet_b = packet_a;
    return 0;
}
#endif

/**
*   test string
*/
#if 0
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string m_sdp_info;

void generate_sdp_info(char* device_id,
    char* media_receive_ip, unsigned int media_receive_port)
{
    m_sdp_info =
        ("v=0\r\n"
            "o=[device_id] 0 0 IN IP4 [media_receive_ip]\r\n"
            "s=Play\r\n"
            "c=IN IP4 [media_receive_ip]\r\n"
            "t=0 0\r\n"
            "m=video [media_receive_port] RTP/AVP 96 98 97\r\n"
            "a=recvonly\r\n"
            "a=rtpmap:96 PS/90000\r\n"
            "a=rtpmap:98 H264/90000\r\n"
            "a=rtpmap:97 MPEG-4/90000\r\n"
            "y=[ssrc]\r\n"
            "f=\r\n");

    char media_recv_port_c[20];
    sprintf(media_recv_port_c, "%d", media_receive_port);
    string media_recv_port_tmp(media_recv_port_c);

    string media_recv_id("[device_id]");
    string media_recv_ip("[media_receive_ip]");
    string media_recv_port("[media_receive_port]");

    int pos = -1;
    while ((pos = m_sdp_info.find(media_recv_id)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_id.length(), device_id);
    }

    while ((pos = m_sdp_info.find(media_recv_ip)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_ip.length(), media_receive_ip);
    }

    while ((pos = m_sdp_info.find(media_recv_port)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_port.length(), media_recv_port_tmp);
    }
}

int main()
{
    generate_sdp_info("1234567890", "192.168.0.102", 50000);
    cout << m_sdp_info << endl;

    return 0;
}
#endif

#if 0

#include <stdio.h>

int main()
{
    int a = 1;
    while (true)
    {
        //a++;
    }
    return 0;
}

#endif


#if 0
#include <stdio.h>

class CA
{
public:
	CA():m_ia(3) {}
	~CA() {};

	void printMem() { printf("m_ia=%d\n", m_ia); }
private:
	int m_ia;
};

#endif


#if 0
int main()
{
#if 0
	int* p = 0;
	delete p;
#endif

#if 0
	CA a;
	a.printMem();
#endif

	int i;
	printf("input the value of i\n");
	scanf("%d", &i);
	printf("i = %d\n", i);

	printf("done\n");
	getchar();
	getchar();
	return 0;
}
#endif

#if 0
#include<stdio.h>
#define height 10
int calculate(int a, int b, int c)
{
	int x = a*b*c;
	return x;
}
int main()
{
	int mylong;
	int weight;
	int result;

	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ÎµÄ¸ß¶ï¿½Îªï¿½ï¿½%d\n", height);
	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ë³¤ï¿½ï¿½ï¿½ÎµÄ³ï¿½ï¿½ï¿½:\n");
	scanf("%d", &mylong);

	printf("ï¿½ï¿½ï¿½ï¿½ï¿½ë³¤ï¿½ï¿½ï¿½ÎµÄ¿ï¿½È£ï¿½\n");
	scanf("%d", &weight);

	result = calculate(mylong, weight, height);
	printf("ï¿½ï¿½ï¿½ï¿½ï¿½Îµï¿½ï¿½ï¿½ï¿½Îªï¿½ï¿?d\n", result);
	getchar();
	getchar();
	getchar();

	return 0;

}
#endif 

#if 0
#include<stdio.h>

char a = 'A';
void exercise1()
{
	int iInt = 345;

	printf("iInt=%d\n", iInt);
}

void exercise4()
{
	extern char a;
	printf("ï¿½â²¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½%c\n", a);
}

void main()
{
	exercise4();
	getchar();
}

#endif

#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

class CA
{
public:
	CA(int a);
	void PrintVal() { cout << m_iTmp << endl; }
private:
	int m_iTmp;
};

CA::CA(int a ):
	m_iTmp(a)
{

}

class CB
{
public:
	CB(int a);
	void PrintVal() {  m_ca.PrintVal(); }
private:
	CA m_ca;
};

CB::CB(int a):
m_ca(a)
{
}

int main()
{
	CA a(5);
	CB b(6);
	a.PrintVal();
	b.PrintVal();
	getchar();
}
#endif

#if 0
#include <stdio.h>
#define a 7
#define b 5
#define c a
#define a b

#define c 6

int main()
{
	printf("%d\n", a);
	getchar();
	return 0;
}
#endif

#if 0
#include <stdio.h>

struct A
{
	int a;
	int b;
};

class CB
{
public:
	CB() 
	{ 
		m_struct_a.a = 3; 
		m_struct_a.b = 4;
	}

	void myprint() 
	{ 
		printf("m_struct_a.a=%d\n", m_struct_a.a);
		printf("m_struct_a.a=%d\n", m_struct_a.b);
	}
private:
	A m_struct_a;
};

int main()
{
	A str_a;
	str_a.a = 3;
	str_a.b = 4;

	CB b;
	b.myprint();
	printf("str_a.a = %d\n", str_a.a);
	printf("str_a.b = %d\n", str_a.b);
	getchar();
}

#endif

#if 0
#include <iostream>

using namespace std;

int main()
{
	wstring msg = L"123#abc#456#defghi#7890";
	wstring info;
	wstring imgUrl;
	wstring::size_type index = msg.rfind(L"#");
	if (wstring::npos != index)
	{
		//ï¿½ï¿½ï¿½Ò³É¹ï¿½ï¿½ï¿½
		imgUrl = msg.substr(index+1);
		info = msg.erase(index+1);
	}
	else
	{
		//ï¿½ï¿½ï¿½ï¿½Ê§ï¿½Ü£ï¿½ï¿½ï¿½ï¿½ï¿½
		return -1;
	}

	if (!info.empty()/* || !imgUrl.empty()*/)
	{
		
	}
	getchar();
	return 0;
}
#endif


#if 0
#include <iostream>

using namespace std;

int main()
{
	char* pBuf;
	pBuf = new char[1 * 1024 * 1024 ];
	memset(pBuf, 0x61, 1 * 1024 * 1024 );
	cout << pBuf << endl;

	/*int *a = new int[100];
	for (int i = 0; i<100; i++) {
		cout << a[i] <<endl;
	}*/

	getchar();
}

#endif

#if 0
#include <iostream>
#include "test.h"


using namespace std;

int main()
{
	int i = 0;
	CTthreadTest testThread;
	testThread.start();

	while (1)
	{
		testThread.setValue(i++);
		Sleep(1 * 1000);

		if (i > 9)
		{
			testThread.stop();
		}
	}
	
	return 0;
}

#endif

#if 0
/**
*	ï¿½ï¿½ï¿½ï¿½unsign char ï¿½ï¿½charï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
*/

#include <iostream>

using namespace std;


void f(char v)
{
	char c_c = v;
	unsigned char uc_c = v;

	unsigned int ui_a = c_c;
	unsigned int ui_b = uc_c;

	int i_i = c_c;
	int i_j = uc_c;

	printf("----------------\n");
	printf("%%c: %c, %c\n", c_c, uc_c);
	printf("%%X: %X, %X\n", c_c, uc_c);
	printf("%%u: %u, %u\n", ui_a, ui_b);
	printf("%%d: %d, %d\n", i_i, i_j);

}
int main()
{
	f(0x80);
	f(0x7F);

	getchar();

	return 0;
}

#endif

#if 0
/**
*	ï¿½ï¿½ï¿½ï¿½unsign char ï¿½ï¿½charï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
*/

#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
//#include <tchar.h>


using namespace std;

#define CREATE_DEBUG_CONSOLE \
	FILE* fpDebugOut = NULL; \
	FILE* fpDebugIn = NULL; \
	FILE* fpDebugErr = NULL; \
	if( !AllocConsole() ) \
	{}\
	SetConsoleTitle(TEXT("Debug Window")); \
	_tfreopen_s(&fpDebugOut, TEXT("CONOUT$"),TEXT("w"), stdout); \
	_tfreopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); \
	_tfreopen_s(&fpDebugErr, TEXT("CONOUT$"),TEXT("w"), stderr);

BOOL GetLocalIPList(vector<string>& vIPList)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err = 0;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		printf("%s","GetLocalIPList	: WSAStartup failed !");
		return FALSE;
	}

	char szhn[256] = { 0 };
	int nStatus = gethostname(szhn, sizeof(szhn));
	if (nStatus == SOCKET_ERROR)
	{
		printf("%s", "Socket	: Gethostname failed, Error code: %d", WSAGetLastError());
		return FALSE;
	}

	vIPList.clear();

	HOSTENT* host = gethostbyname(szhn);
	if (host != NULL)
	{
		for (int i = 0; ; i++)
		{
			vIPList.push_back(inet_ntoa(*(IN_ADDR*)host->h_addr_list[i]));
			if (host->h_addr_list[i] + host->h_length >= host->h_name)
			{
				break;
			}
		}
	}

	WSACleanup();
	return TRUE;
}

char* GethostIp(char* pHostIp, int nBufLen)
{
	if (pHostIp == NULL)
	{
		return NULL;
	}
	struct hostent* pH = NULL;
	char pHostName[100] = { 0 };
	gethostname(pHostName, 100);
	string hostNmae = pHostName;//ï¿½Ë´ï¿½ï¿½ï¿½Ã±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
	pH = gethostbyname(pHostName);

	char* pTmpHostIP = inet_ntoa(*((struct in_addr*)pH->h_addr_list[0]));//ï¿½Ë´ï¿½ï¿½ï¿½Ã±ï¿½ï¿½ï¿½IP

	strcpy_s(pHostIp, nBufLen, pTmpHostIP);

	return pHostIp;
}

bool createNewConsoleWindow()
{
	FILE* fpDebugOut = NULL; 
	FILE* fpDebugIn = NULL; 
	FILE* fpDebugErr = NULL; 
	if (!AllocConsole()) 
	{
		return false;
	}
	SetConsoleTitle(TEXT("Debug Window")); 

	//_tfreopen_s(&fpDebugOut, TEXT("CONOUT$"), TEXT("w"), stdout); 
	//_tfreopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); 
	//_tfreopen_s(&fpDebugErr, TEXT("CONOUT$"), TEXT("w"), stderr);

	freopen_s(&fpDebugOut, TEXT("CONOUT$"), TEXT("w"), stdout); 
	freopen_s(&fpDebugIn, TEXT("CONIN$"), TEXT("r"), stdin); 
	freopen_s(&fpDebugErr, TEXT("CONOUT$"), TEXT("w"), stderr);

	freopen_s(&fpDebugOut, "CONOUT$", "w", stdout);
	freopen_s(&fpDebugIn, "CONIN$", "r", stdin);
	freopen_s(&fpDebugErr, "CONOUT$", "w", stderr);

	return true;
}

int main()
{
	int buf[10] = { 1,3,5,7,9,11 };
	for each (int var in buf)
	{
		printf("%d\n", var);
	}
	vector<string> hostipVector;
	GetLocalIPList(hostipVector);
	/*char hostIP[100] = { 0 };
	GethostIp(hostIP, 100);*/

	/*createNewConsoleWindow();
	printf("hello world\n");
	printf("ï¿½ï¿½ï¿½\n");*/

	char tmpSDP[4096] = { 0 };
	sprintf_s(tmpSDP, 4096,
		"v=0\r\n"
		"o=%s 0 0 IN IP4 %s\r\n"
		"s=Play\r\n"
		"c=IN IP4 %s\r\n",
		"123456789",
		"admin",
		"172.17.11.117");

	char* tmp = "abcd"
		"efgh"
		"igklmn";

	int iLen = strlen(tmp);


	printf("%s\n", tmpSDP);

	getchar();

	return 0;
}

#endif



#if 0

#include <iostream>

using namespace std;

int main()
{
	int a = 3;
	switch ( a )
	{
		case 1:
		{
			printf("a = 1\n");
		}
		case 2:
		{
			printf("a = 2\n");
		}

		case 3:
		{
			printf("a = 3\n");
		}

		case 4:
		{
			printf("a = 4\n");
		}

		default :
		{
			printf("a = 0\n");
		}
		
	}

	getchar();

	return 0;
}

#endif


#if 0

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//vector<> vct1;
	

	getchar();

	return 0;
}

#endif



#if 0

//c++ï¿½ì³£ï¿½ï¿½ï¿½Ô³ï¿½ï¿½ï¿½
#include <iostream>

using namespace std;

class myexception : public std::exception 
{
	public:
	myexception(std::string s) : exception(s.c_str()) {
	}

	virtual const char *what() const 
	{
		return exception::what();
	}
};

class A 
{
public:
	~A() 
	{
		printf("A's destructor\n");
	}
};

class B 
{
public:
	~B() 
	{
		printf("B's destructor\n");
	}

};

void Func() 
{
	A a;
	try 
	{
		int *p = NULL;
		if (p == NULL) 
		{
			throw myexception("p is NULL");  
		}
	}
	catch (myexception e) 
	{
		printf("%s\n", e.what());
		throw;
	}
	catch (std::exception e) 
	{
		printf("%s", e.what());
	}

	B b;
}


void Func2() 
{
	Func();
}

int main() 
{
	int a = 2;
	int b = 3;
	int c = 0;
	int sum;
	try
	{
		//Func2();
		//sum = a / c;
		throw 1;
	}
	catch (std::exception e)
	{
		printf("main exception \n");
		printf("%s", e.what());
	}
	catch(...)
	{
	}

	system("PAUSE");
	return 0;
}

#endif

#if 0
// c++ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ô³ï¿½ï¿½ï¿?
/**
*	ï¿½ï¿½rand()ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ö´ï¿½Ð¶ï¿½Îºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½ï¿½ï¿½Í¬ï¿½Ä£ï¿½Ô­ï¿½ï¿½ï¿½ï¿½Ä¬ï¿½Ïµï¿½ï¿½ï¿½ï¿½Ó¶ï¿½ï¿½ï¿?ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½ï¿½Ã¿ï¿½ï¿½Ö´ï¿½Ð²ï¿½ï¿½ï¿½ï¿½ï¿½
*	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Í¬ï¿½ï¿½ï¿½ï¿½Òªï¿½ï¿½ï¿½Ã²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½Ó£ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê±ï¿½ï¿½Îªï¿½Î¿ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ó£ï¿½srand((int)time(NULL))ï¿½ï¿½Ã¿ï¿½ï¿½Ö´ï¿½ï¿½ï¿½ï¿½ï¿½Ó²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½É²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*
*
*	(a,b) (rand()%((b)-(a)+1))+(a)-1
*	[a,b) (rand()%((b)-(a)+1)-1)+(a)
*	(a,b] (rand()%((b)-(a)+1)-1)+(a)+1
*	[a,b] (rand()%((b)-(a)+1))+(a)
*/
#include <iostream>
#include<stdlib.h>
#include<time.h> 

#define RANDOM1(a,b)  (rand()%((b)-(a)+1))+(a)-1		//(a,b)
#define RANDOM2(a,b)  (rand()%((b)-(a)+1)-1)+(a)		//[a,b)
#define RANDOM3(a,b)  (rand()%((b)-(a)+1)-1)+(a)+1		//(a,b]
#define RANDOM4(a,b)  (rand()%((b)-(a)+1))+(a)			//[a,b]
using namespace std;

int Random(int m, int n)
{
	int pos, dis;
	if (m == n)
	{
		return m;
	}
	else if (m > n)
	{
		pos = n;
		dis = m - n + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = m;
		dis = n - m + 1;
		return rand() % dis + pos;
	}
}

 int getPort(int start, int end)
{
	int result = RANDOM4(start, end);
	return (result % 2) ? result + 1 : result;
}

int main()
{
	int tmp = 50000;
	int tmp2;
	short tmp3 = (short)tmp;
	tmp2 = tmp3;
	int i;
	srand((int)time(NULL)); //Ã¿ï¿½ï¿½Ö´ï¿½ï¿½ï¿½ï¿½ï¿½Ó²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½É²ï¿½Í¬ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?

	for (i = 0; i<10; i++)  //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?0ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	{
		printf("%d\n", getPort(50000,50000));
	}

	system("pause");
	return 0;
}
#endif

#if 0
/** 
*   ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½outputï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*/
#include <iostream>
#include <stdio.h>
#include <Windows.h>
//#include <afx.h>

using namespace std;

int mysum(int a[], unsigned len)
{
	int i, sum = 0;
	for (i = 0; i <= len - 1;i++)
	{
		sum += a[i];
	}
	return sum;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	int sum = 0;

	sum = mysum(a, 5);
	printf("sum = %d\n", sum);

	//TRACE("***********ITMS_CCTV_StopPreview Ç° Ç°*************\r\n");

	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");
	OutputDebugString("***********yangdong***********\n");

	system("pause");
	return 0;
}

#endif

#if 0

#include <iostream>
#include <stdio.h>
#include <WinSock2.h>
//#include "myMathLib\myMath.h"
#include "myMathDll\myMath.h"

using namespace std;


int main(int argc, char* argv[])
{
    int a = 200;
    int b = 3;

    int sum = 0;

    sum = add(a, b);

    printf("sum = %d\n", sum);


    system("pause");
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <string.h>

//ï¿½ï¿½1
struct S
{
    int a;
    char b;
};

//ï¿½ï¿½2
struct S2
{
    char x1;
    short x2;
    float x3;
    char x4;
};

//ï¿½ï¿½3
struct S3
{
    char a[10];
    int b;
};

//Ê¾ï¿½ï¿½2
class B
{
public:
    B() { printf("B()\n"); }
    virtual ~B() { printf("~B()\n"); }
private:
    int m_b;
};

class D : public B
{
public:
    D() { printf("D()\n"); }
    ~D() { printf("~D()\n"); }
private:
    int m_d;
};

int main()
{
    B* pB = new D();
    delete pB;
    
    return 0;
}

#endif

#if 0
/**
*   È·ï¿½ï¿½ï¿½ï¿½ï¿½Ðºï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½constï¿½ï¿½ï¿½ï¿½ï¿½Ã£ï¿½
*   ï¿½ï¿½ï¿½ï¿½ï¿?
*       ï¿½ï¿½ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½constï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ¸Ã³ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Þ¸ï¿½ï¿½ï¿½Ä³ï¿½Ô±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
*/

#include <stdio.h>
class A
{
public:
    A() {}
    virtual ~A() {}

public:
    int func1() const;

private:
    int m_a;
};

int A::func1() const
{
    printf("in func1()\n");
    return 0;
}

typedef struct _MyStruct
{
    int a;
    char pData[0];
} MyStruct;

int main(int argc, char* argv[], char *envp[])
{

    printf("sizeof(MyStruct):%d\n",sizeof(MyStruct));

    A a;
    a.func1();

    int i = 0;
    while (NULL != envp[i])
    {
        printf("envp[%d]= %s\n", i, envp[i]);
        i++;
    }

    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <iostream>

class B 
{
public:
    virtual int fun1() = 0;
};

//int B::fun1()
//{
//    return 0;
//}

class S : public B
{
public:
    virtual int fun1();
};

int S::fun1()
{
    int a = 1;
    int b = 2;
    return a + b;
}

int main()
{
    S s;
	system("pause");
	return 0;
}

#endif

/**
*   function pointer
*/
#if 0

#include <stdio.h>

typedef int(*callback_add)(int a, int b);

int add(int a, int b)
{
    printf("%d+%d=%d\n",a, b, a + b);
    return 0;
}

int main()
{
    callback_add fun;
    fun = add;
    fun(2,3);

    return 0;
}
#endif

#if 0

#include "stdio.h"

class ca
{
public:
    ca() 
    {
        printf("constructort.\n");
    }

    ca(ca &) 
    {
        printf("copy constructor.\n");
    }

    ~ca() 
    {
        printf("desconstructor.\n");
    }

    ca& operator=(const ca& ca1)
    {
        ca ca2;
        printf("operator = ().\n");

        return ca2;
    }
};

void func1(ca ca1)
{
    ca b;
    b = ca1;
}

int main()
{
    ca ca1;
    func1(ca1);

    return 0;
}
#endif

#if 0

#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include "command_line_parser.h"

using namespace std;

//bool parse(char* schema, char* args[], int argc)
//{
//    char* _schema = NULL;
//    char* _args = NULL;
//    if (schema && args[0])
//    {
//        _schema = (char*)malloc(strlen(schema));
//        sprintf(_schema, "%s", schema);
//
//        char* temp_schema = strtok(_schema, ",");
//        while (temp_schema)
//        {
//            printf("%s ", temp_schema);
//            if ('\0' == temp_schema[1])
//            {
//                printf("bool \n");
//            }
//            else if (temp_schema[1] == '#')
//            {
//                printf("int \n");
//            }
//            else if (temp_schema[1] == '*')
//            {
//                printf("string \n");
//            }
//
//            temp_schema = strtok(NULL, ",");
//        }
//
//        for (int i = 0; i<argc; i++)
//        {
//            printf("%s\n", args[i]);
//            if (args[i][0] == '-')
//            {
//                //key
//                if (args[i + 1][0] == '-')
//                {
//
//                }
//                printf("%s", args[i]);
//            }
//            else
//            {
//
//            }
//        }
//
//    }
//
//    free(_schema);
//    free(_args);
//
//    return false;
//}

int main(int argc, char* argv[])
{
    if (2 > argc)
    {
        printf("error, please check in put param.\n");
    }

    char* schema = argv[1];
    char* args[100] = { 0 };

    int param_num = 0;

    for (int i = 0; i < argc - 2; i++)
    {
        args[i] = argv[i + 2];
        param_num++;
    }

    command_line_parser cmd_line_parase;

    cmd_line_parase.parse(schema, args, param_num);
    cmd_line_parase.printf_param_values();

    return 0;
}

#endif

/**
*   virtual function and overload
*/
# if 0
#include <stdio.h>
class A
{
public:

    void func1() {}
    virtual void func1() {}
};

int main()
{
    A a;
    return 0;
}
#endif

/**
*   difference of delete and delete[]
*/
#if 0
#include <iostream>

using namespace std;

class A
{
private:
    int m_data;
public:
    A() { }
    ~A() { cout << "delete object." << endl; }
};

int main()
{
    A *a = new A[10];
    delete []a;
    //delete a;

    return 0;
}
#endif


//Éî¿½±´

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class media_packet
{
public:
    media_packet()
    {
        m_media_data = NULL;
        m_media_data_length = 0;
    }

    ~media_packet()
    {
        if (!m_media_data)
        {
            free(m_media_data);
            m_media_data = NULL;
        }
    }

    media_packet(unsigned char* data, int size)
    {
        m_media_data = (unsigned char*)malloc(size);

        if (NULL != m_media_data && 0 < size)
        {
            memcpy(m_media_data, data, size);
            m_media_data_length = size;
        }
        else
        {
            m_media_data_length = 0;
        }
    }

    media_packet& operator = (media_packet packet)
    {
        if (m_media_data == packet.m_media_data)
        {
            return *this;
        }
        if (NULL != m_media_data)
        {
            free(m_media_data);
            m_media_data = NULL;
            m_media_data_length = 0;

            if (!packet.m_media_data)
            {
                return *this;
            }

            m_media_data_length = packet.m_media_data_length;

            m_media_data = (unsigned char*)malloc(m_media_data_length);
            if (m_media_data)
            {
                memcpy(m_media_data, packet.m_media_data, m_media_data_length);
            }
        }
        else
        {
            m_media_data_length = packet.m_media_data_length;
            m_media_data = (unsigned char*)malloc(m_media_data_length);
            if (m_media_data)
            {
                memcpy(m_media_data, packet.m_media_data, m_media_data_length);
            }
        }
        return *this;
    }

    bool is_valid()
    {
        return (m_media_data && 0 < m_media_data_length);
    }

private:
    unsigned char* m_media_data;
    int m_media_data_length;

};

int main()
{
    media_packet packet_a;
    media_packet packet_c;

    packet_a = packet_a;
    //packet_c = packet_a;

    media_packet packet_b((unsigned char*)"abcdefghi", 10);
    //packet_c = packet_a = packet_b;
    //packet_a = packet_a;

    packet_b = packet_a;
    return 0;
}
#endif

/**
*   test string
*/
#if 0
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string m_sdp_info;

void generate_sdp_info(char* device_id,
    char* media_receive_ip, unsigned int media_receive_port)
{
    m_sdp_info =
        ("v=0\r\n"
            "o=[device_id] 0 0 IN IP4 [media_receive_ip]\r\n"
            "s=Play\r\n"
            "c=IN IP4 [media_receive_ip]\r\n"
            "t=0 0\r\n"
            "m=video [media_receive_port] RTP/AVP 96 98 97\r\n"
            "a=recvonly\r\n"
            "a=rtpmap:96 PS/90000\r\n"
            "a=rtpmap:98 H264/90000\r\n"
            "a=rtpmap:97 MPEG-4/90000\r\n"
            "y=[ssrc]\r\n"
            "f=\r\n");

    char media_recv_port_c[20];
    sprintf(media_recv_port_c, "%d", media_receive_port);
    string media_recv_port_tmp(media_recv_port_c);

    string media_recv_id("[device_id]");
    string media_recv_ip("[media_receive_ip]");
    string media_recv_port("[media_receive_port]");

    int pos = -1;
    while ((pos = m_sdp_info.find(media_recv_id)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_id.length(), device_id);
    }

    while ((pos = m_sdp_info.find(media_recv_ip)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_ip.length(), media_receive_ip);
    }

    while ((pos = m_sdp_info.find(media_recv_port)) != -1)
    {
        m_sdp_info.replace(pos, media_recv_port.length(), media_recv_port_tmp);
    }
}

int main()
{
    generate_sdp_info("1234567890", "192.168.0.102", 50000);
    cout << m_sdp_info << endl;

    return 0;
}
#endif

/**
    c++ map±éÀúÉ¾³ý
*/
#if 0

#include<stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, char*> tmp_map;
    tmp_map[0] = "yang";
    tmp_map[1] = "dong";
    tmp_map[2] = "shi";
    tmp_map[3] = "ge";
    tmp_map[4] = "hao";
    tmp_map[5] = "nan";
    tmp_map[6] = "ren";

    for (map<int, char*>::iterator it = tmp_map.begin(); it != tmp_map.end(); /*it++*/)
    {
        //it = tmp_map.erase(it);
        tmp_map.erase(it++);
    }

    return 0;
}
#endif

#if 0

#include "stdio.h"

int main()
{
    int * pdata;

    printf("%d\n", sizeof(short*));

    return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    ~A() {}

    void fun1() 
    {
        fun2();
        fun3();
    };

    virtual void fun2() 
    {
        cout << "fun2() at father class A" << endl;
    };

    void fun3()
    {
        cout << "fun3() at father class A" << endl;
    }

private:
};

class B : public A
{
public:
    B() {}
    ~B() {}

    //¸²¸Ç
    virtual void fun2()
    {
        cout << "fun2() at son class B" << endl;
    }

    //Òþ²Ø
    void fun3()
    {
        cout << "fun3() at son class B" << endl;
    }

    //ÖØÔØ
    void fun3(int a)
    {
        cout << "fun3(int a) at son class B" << endl;
    }

    void fun4()
    {
        fun3();
        fun3(5);
    }

};

int main()
{
    B b;
    b.fun1();
    b.fun4();

    return 0;
}

#endif

#if 0

#include <set>

using namespace std;

int main()
{
    std::set<int*> m_b2buaCallSet;
    std::set<int*> mySet;

    int * p1 = new int(1);
    int * p2 = new int(2);

    m_b2buaCallSet.insert(p1);
    m_b2buaCallSet.insert(p2);
    return 0;
}

#endif

#if 0
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#define ElemType int
#define P 13

typedef struct HashNode {
    ElemType data;
    struct HashNode* link;
}HashNode;

typedef HashNode* HashTable[P];

void init_hash(HashTable ht) {
    for (int i = 0; i < P; ++i) {
        ht[i] = NULL;
    }
}

int hash(ElemType key) {
    return key % P;
}
void insert_hash_table(HashTable ht, ElemType x) {
    int index = hash(x);
    HashNode* s = (HashNode*)malloc(sizeof(HashNode));
    assert(s != NULL);
    s->data = x;

    //Í·²å
    s->link = ht[index];
    ht[index] = s;
}

void show_hash_table(HashTable ht) {
    for (int i = 0; i < P; ++i) {
        printf("%d: ", i);
        HashNode* p = ht[i];
        while (NULL != p) {
            printf("%d->", p->data);
            p = p->link;
        }
        printf("Nul.\n");
    }
}
HashNode* search_hash_table(HashTable ht, ElemType x) {
    int index = hash(x);
    HashNode* p = ht[index];
    while (NULL != p && p->data != x) {
        p = p->link;
    }
    return p;
}
bool remove_hash_node(HashTable ht, ElemType x) {
    HashNode* p = search_hash_table(ht, x);
    if (NULL == p)return false;

    int index = hash(x);
    HashNode* q = ht[index];
    if (p == q) {
        ht[index] = p->link;
        free(p);
        return true;
    }
    while (q->link != p) {
        q = q->link;
    }
    q->link = p->link;
    free(p);
    return true;
}
int main() {

    HashTable ht;
    init_hash(ht);

    ElemType ar[] = { 19,14,23,1,68,20,84,27,55,11,10,79 };
    int n = sizeof(ar) / sizeof(ElemType);

    for (int i = 0; i < n; ++i) {
        insert_hash_table(ht, ar[i]);
    }

    show_hash_table(ht);

    ElemType key = 68;
    HashNode* p = search_hash_table(ht, key);
    if (NULL != p) {
        printf("%d\n", p->data);
    }

    remove_hash_node(ht, key);
    show_hash_table(ht);

    return 0;

}
#endif

#if 0
#include<map>  
#include<vector>
#include<string>  
#include<iostream> 
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;

ostream& operator<<(ostream& out, const PAIR& p) {
    return out << p.first << "\t" << p.second;
}

template <class T>
struct greater : binary_function<T, T, bool>
{
    bool operator()
        (const T& x, const T& y) const
    {
        return x>y;
    }
};

bool compair_by_value(const PAIR& lhs, const PAIR& rhs)
{
    return lhs.second < rhs.second;
};

int main() {
    //map<string, int> name_score_map;
    map<string, int, greater<string>> name_score_map;
    name_score_map["Zhangsan"] = 90;
    name_score_map["Lisi"] = 79;
    name_score_map.insert(make_pair("Wangwu", 99));

    vector<PAIR> name_score_vec(name_score_map.begin(), name_score_map.end());
    sort(name_score_vec.begin(), name_score_vec.end(), compair_by_value);

    for (map<string, int>::iterator iter = name_score_map.begin(); iter != name_score_map.end(); ++iter) 
    {
        cout << *iter << endl;
    }

    //for(int i = 0; i != name_score_vec.size(); ++i)
    //{
    //    cout << name_score_vec[i] << endl;
    //}

    return 0;
}


#endif

#if 0
#include <list>
#include <iostream>

using namespace std;

void printListData(list<int>& _list)
{
    list<int>::iterator it = _list.begin();

    while (it != _list.end())
    {
        cout << *it << endl;
        it++;
    }
}

void eraseValueFromList(list<int>& _list, int value)
{
    list<int>::iterator it = _list.begin();
    while (it != _list.end())
    {
        if (value == (*it))
        {
            _list.erase(it);
            break;
        }

        it++;
    }
}

int main()
{
    list<int> list_int;

    list_int.push_back(1);
    list_int.push_back(2);
    list_int.push_back(3);
    list_int.push_back(4);
    list_int.push_back(5);

    printListData(list_int);

    list<int>::iterator it = list_int.begin();

    //list_int.remove(4);
    eraseValueFromList(list_int, 4);
    eraseValueFromList(list_int, 3);
    eraseValueFromList(list_int, 3);

    printf("after delete data\n");
    printListData(list_int);


    return 0;
}
#endif

#if 0
#include "DniuHashTable.h"
#include "DniuB2buaCall.h"


int main()
{
    CHashTable<std::string, CDniuB2buaCall*> table;

    CDniuB2buaCall call1("call1");
    CDniuB2buaCall call2("call2");
    CDniuB2buaCall call3("call3");
    CDniuB2buaCall call4("call4");

    CHashTable<std::string, CDniuB2buaCall*>::HashNode node1;
    //CHashTable<std::string, CDniuB2buaCall*>::HashNode node2;
    CHashTable<std::string, CDniuB2buaCall*>::HashNode node3;
    CHashTable<std::string, CDniuB2buaCall*>::HashNode node4;

    node1.m_key = "001";
    node1.m_value = &call1;

    //node2.m_key = "002";
    //node2.m_value = &call2;
    CHashTable<std::string, CDniuB2buaCall*>::HashNode node2("002", &call2);

    node3.m_key = "002";
    node3.m_value = &call3;

    node4.m_key = "002";
    node4.m_value = &call4;

    table.insertNode(node1);
    table.insertNode(node2);
    table.insertNode(node3);
    table.insertNode(node4);

    table.printData();

    table.removeNode(node4);
    table.removeNode(node4);
    table.removeNode(node4);
    table.removeNode(node3);
    table.removeNode(node2);

    std::cout << "after remove node:" << std::endl;

    table.printData();

    return 0;
}

#endif

#if 0
#include <map>
#include <iostream>
#include <string>
using namespace std;

class CDniuCallManager
{
public:
    void addb2buacall()
    {

    }

private:
    multimap<string, string> m_CallMultimap;
};

int main()
{
    multimap<string, string> mlty_map;
    mlty_map.insert(pair<string, string>("001", "call1"));
    mlty_map.insert(pair<string, string>("001", "call2"));
    mlty_map.insert(pair<string, string>("001", "call3"));

    mlty_map.insert(pair<string, string>("002", "call1"));
    mlty_map.insert(pair<string, string>("002", "call2"));
    mlty_map.insert(pair<string, string>("002", "call2"));
    mlty_map.insert(pair<string, string>("002", "call2"));
    mlty_map.insert(pair<string, string>("002", "call3"));

    multimap<string, string>::iterator it_begin = mlty_map.lower_bound("005");
    multimap<string, string>::iterator it_end = mlty_map.upper_bound("005");

    if (it_begin == it_end)
    {
        it_begin++;
        bool b1 = true;
    }

    //for (multimap<string, string>::iterator iter = mlty_map.begin(); 
    //    iter != mlty_map.end(); iter = mlty_map.upper_bound(iter->first))
    //{
    //    std::cout << iter->first << std::endl;
    //    multimap<string, string>::iterator it_begin = mlty_map.lower_bound(iter->first);
    //    multimap<string, string>::iterator it_end = mlty_map.upper_bound(iter->first);
    //    //std::pair<multimap<string, string>::iterator, multimap<string, string>::iterator> res = mlty_map.equal_range(iter->first);
    //    for (; it_begin != it_end; ++it_begin)
    //    {
    //        std::cout << "******" << it_begin->second << std::endl;
    //    }
    //}

    /*multimap<string, string>::iterator it1 = mlty_map.find("001");*/
    //cout << "first:" << it1->first << "; second:" << it1->second << endl;

    //int count = mlty_map.count("001");
    //for (int i = 0; i < count; i++)
    //{
    //    cout << "first:" << it1->first << "; second:" << it1->second << endl;
    //    it1++;
    //}


    //mlty_map.find(pair<string, string>("002", "call1"));

    //mlty_map.erase("001");

    //multimap<string, string>::iterator it_begin = mlty_map.lower_bound("001");
    //multimap<string, string>::iterator it_end = mlty_map.upper_bound("001");

    //while (it_begin != it_end)
    //{
    //    if ("call3" == it_begin->second)
    //    {
    //        it_begin = mlty_map.erase(it_begin);
    //        continue;
    //    }
    //    cout << "first:" << it_begin->first << "; second:" << it_begin->second << endl;
    //    it_begin++;
    //}


    //cout << "001, count():" << mlty_map.count("001") <<endl;

    //cout << "**************************" << endl;

    //for (multimap<string, string>::iterator it = mlty_map.begin(); it != mlty_map.end(); it++) 
    //{
    //    cout << "first:" << it->first << "; second:" << it->second << endl;
    //}

    return 0;
}

#endif


#if 0
#include <iostream>

using namespace std;

int main()
{
    int a = 2;
    switch (a)
    {
    case 1:
    case 2:
        cout << "2" << endl;
        cout << "2.1" << endl;
    default:
        cout << "default" << endl;
    }
}
#endif

#if 0
/**
*   ÖÇÄÜÖ¸Õë
*/
// auto_ptr_release.cpp
// compile with: /EHsc
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

class Int
{
public:
    Int(int i)
    {
        x = i;
        cout << "Constructing " << (void*)this << " Value: " << x << endl;
    };
    ~Int() {
        cout << "Destructing " << (void*)this << " Value: " << x << endl;
    };

    int x;

};

int main()
{
    auto_ptr<Int> pi(new Int(5));
    //pi.reset(new Int(6));
    //Int* pi2 = pi.get();
    //Int* pi3 = pi.get();

    //Int* pi2 = pi.release();
    //Int* pi3 = pi.release();

    //Int* pi4 = pi.get();

    //auto_ptr<Int> pi2 = pi;
    auto_ptr<Int> pi2(pi);

    //*(pi.get()) = 100;

    cout << pi->x << endl;
    cout << pi2->x << endl;

    //Int* pi3 = pi.release();
    //if (pi2 == pi3)
    //    cout << "pi2 == pi3" << endl;
    //delete pi3;
    return 0;
}

#endif

#if 0

#include <memory>
#include <iostream>
#include <vector>
using namespace std;

int myAtoI(char* p)
{
    if (NULL == p)
    {
        return -1;
    }

    char* tmp = p;
    int value = 0;
    for (int i = 0; '\0' != tmp[i]; i++)
    {
        if (tmp[i] >= '0' && tmp[i] <= '9')
        {
            value = value * 10 + (tmp[i] - '0');
        }
        else
        {
            return -1;
        }
    }

    return value;
}

int FindNextChar(char* src, char dest)
{
    if (NULL == src)
    {
        return -1;
    }

    char* tmp = src;

    for (int i = 0; tmp[i] != '\0'; i++)
    {
        if (dest == tmp[i])
        {
            return i;
        }
    }

    return -1;
}

typedef struct
{
    int left;
    int top;
    int right;
    int bottom;

}Rect_t;

int CovertToRect(char* p, Rect_t* pRect)
{

    if (NULL == p || NULL == pRect)
    {
        return -1;
    }

    int ileft = 0;
    int itop = 0;
    int iright = 0;
    int ibottom = 0;

    char pleft[20] = { 0 };
    char ptop[20] = { 0 };
    char pright[20] = { 0 };
    char pbottom[20] = { 0 };

    int index = -1;
    char* tmp = p;

    index = FindNextChar(tmp, ',');
    for (int j = 0; j < index; j++)
    {
        pleft[j] = tmp[j];
    }
    tmp = tmp + index+1;

    index = FindNextChar(tmp, ',');
    for (int j = 0; j < index; j++)
    {
        ptop[j] = tmp[j];
    }
    tmp = tmp + index+1;

    index = FindNextChar(tmp, ',');
    for (int j = 0; j < index; j++)
    {
        pright[j] = tmp[j];
    }
    tmp = tmp + index+1;

    for (int j = 0; tmp[j] != '\0'; j++)
    {
        pbottom[j] = tmp[j];
    }

    ileft = myAtoI(pleft);
    itop = myAtoI(ptop);
    iright = myAtoI(pright);
    ibottom = myAtoI(pbottom);

    pRect->left = ileft;
    pRect->top = itop;
    pRect->right = iright;
    pRect->bottom = ibottom;

    return 0;
}

int main()
{
    char buf[] = "hello";

    //int a = sizeof(buf);
    //int b = strlen(buf);

    char* argv[6] = {0};    //Ö¸ÕëÊý×é£¬Êý×é¿ÉÒÔ±£´æ6¸öÔªËØ£¬Ã¿¸öÔªËØ¶¼ÊÇÒ»¸ö char* ÀàÐÍµÄ±äÁ¿£» 
    char (*pa)[6] = NULL;   //Êý×éÖ¸Õë£¬ÆäÖ¸ÏòÒ»¸ö³¤¶ÈÎª6µÄÒ»Î¬Êý×é£»

    //Ö¸ÕëÊý×é±È½Ï³£¼û£¬±ÈÈçmainº¯ÊýµÄµÚ¶þ¸ö²ÎÊý¾ÍÊÇÒ»¸öÖ¸ÕëÊý×é£»
    //ÏÂÃæÎÒÃÇ¾Ù¸öÀý×ÓÈçºÎ¸øÊý×éÖ¸Õë¸³Öµ£º

    char buf[] = "hello";
    pa = &buf;

    pa[1];

    printf("%s\n", pa[0]);

    //Rect_t* pRect = new Rect_t;
    //CovertToRect("1,23,100,200", pRect);



    //int b = FindNextChar("hello world!", 'w');

    //int a = myAtoI("12800");

    return 0;
}
#endif

#if 1

#include<queue>
#include <functional>
#include<iostream>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> myQueue;
    myQueue.push(1);
    myQueue.push(10);
    myQueue.push(5);
    myQueue.push(5);
    myQueue.push(8);
    myQueue.push(2);

    while (!myQueue.empty())
    {
        int n = myQueue.top();
        myQueue.pop();
        cout << n << endl;
    }
    return 0;
}

#endif
