
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

	printf("�����εĸ߶�Ϊ��%d\n", height);
	printf("�����볤���εĳ���:\n");
	scanf("%d", &mylong);

	printf("�����볤���εĿ�ȣ�\n");
	scanf("%d", &weight);

	result = calculate(mylong, weight, height);
	printf("�����ε����Ϊ��%d\n", result);
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
	printf("�ⲿ������ʾ��%c\n", a);
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
		//���ҳɹ���
		imgUrl = msg.substr(index+1);
		info = msg.erase(index+1);
	}
	else
	{
		//����ʧ�ܣ�����
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
*	����unsign char ��char������
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
*	����unsign char ��char������
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
	string hostNmae = pHostName;//�˴���ñ�������
	pH = gethostbyname(pHostName);

	char* pTmpHostIP = inet_ntoa(*((struct in_addr*)pH->h_addr_list[0]));//�˴���ñ���IP

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
	printf("���\n");*/

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

//c++�쳣���Գ���
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
// c++��������Գ���
/**
*	��rand()�����������������������ִ�ж�κ������ֵ����ͬ�ģ�ԭ����Ĭ�ϵ����Ӷ���1����Ҫ����ÿ��ִ�в�����
*	���������ͬ����Ҫ���ò�ͬ�����ӣ�һ��������ʱ��Ϊ�ο��������ӣ�srand((int)time(NULL))��ÿ��ִ�����Ӳ�ͬ�����ɲ�ͬ�������
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
	srand((int)time(NULL)); //ÿ��ִ�����Ӳ�ͬ�����ɲ�ͬ�������

	for (i = 0; i<10; i++)  //�������10������
	{
		printf("%d\n", getPort(50000,50000));
	}

	system("pause");
	return 0;
}
#endif

#if 0
/** 
*   �������ʾ��output�������
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

	//TRACE("***********ITMS_CCTV_StopPreview ǰ ǰ*************\r\n");

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

//��1
struct S
{
    int a;
    char b;
};

//��2
struct S2
{
    char x1;
    short x2;
    float x3;
    char x4;
};

//��3
struct S3
{
    char a[10];
    int b;
};

//ʾ��2
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
*   ȷ�����к��������const�����ã�
*   �����
*       ���Ա���������const�����������Ƹó�Ա���������޸���ĳ�Ա����������������
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

#if 0
/**
*   function pointer
*/
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

#if 1

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