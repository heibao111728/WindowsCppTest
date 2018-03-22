
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

	printf("长方形的高度为：%d\n", height);
	printf("请输入长方形的长度:\n");
	scanf("%d", &mylong);

	printf("请输入长方形的宽度：\n");
	scanf("%d", &weight);

	result = calculate(mylong, weight, height);
	printf("长方形的体积为：%d\n", result);
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
	printf("外部变量显示：%c\n", a);
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
		//查找成功，
		imgUrl = msg.substr(index+1);
		info = msg.erase(index+1);
	}
	else
	{
		//查找失败，返回
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
*	测试unsign char 与char的区别。
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
*	测试unsign char 与char的区别。
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
	string hostNmae = pHostName;//此处获得本机名称
	pH = gethostbyname(pHostName);

	char* pTmpHostIP = inet_ntoa(*((struct in_addr*)pH->h_addr_list[0]));//此处获得本机IP

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
	printf("你好\n");*/

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

//c++异常测试程序
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
// c++随机数测试程序
/**
*	用rand()函数产生的随机数，当程序执行多次后产生的值是相同的，原因是默认的种子都是1，想要程序每次执行产生的
*	随机数不相同，需要设置不同的种子，一般我们以时间为参考生成种子：srand((int)time(NULL))，每次执行种子不同，生成不同的随机数
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
	srand((int)time(NULL)); //每次执行种子不同，生成不同的随机数

	for (i = 0; i<10; i++)  //随机产生10个数。
	{
		printf("%d\n", getPort(50000,50000));
	}

	system("pause");
	return 0;
}
#endif

#if 1
#include <iostream>
#include <stdio.h>

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

	sum = mysum(a, 0);
	printf("sum = %d\n", sum);


	system("pause");
	return 0;
}

#endif