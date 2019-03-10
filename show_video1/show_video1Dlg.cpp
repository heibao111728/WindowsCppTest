
// show_video1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "show_video1.h"
#include "show_video1Dlg.h"
#include "afxdialogex.h"
#include "bit_map.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cshow_video1Dlg dialog



Cshow_video1Dlg::Cshow_video1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHOW_VIDEO1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cshow_video1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cshow_video1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// Cshow_video1Dlg message handlers

BOOL Cshow_video1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cshow_video1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cshow_video1Dlg::OnPaint()
{
    show_bitmap();
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cshow_video1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cshow_video1Dlg::show_bitmap()
{
#if 0
    CPaintDC dc(this);
    //CBitmap bitmap;
    //bitmap.LoadBitmap(IDB_BITMAP1);
    //CDC dcCompatible;
    //dcCompatible.CreateCompatibleDC(&dc);
    //dcCompatible.SelectObject(bitmap);


    BYTE				buffer[sizeof(BITMAPINFOHEADER) + 3 * sizeof(RGBQUAD)];
    BITMAPINFO*			pBMI = (BITMAPINFO*)buffer;
    BITMAPINFOHEADER*	pHeader = &pBMI->bmiHeader;
    DWORD*				pColors = (DWORD*)&pBMI->bmiColors;
    BitMap bitmap;
    bitmap.Read("D:\\GithubPro\\WindowsCppTest\\show_video1\\res\\bitmap1.bmp");

    DWORD            dwInfoSize, dwBytesRead;
    BITMAPINFO     * pbmi;
    dwInfoSize = bitmap.fileHeader.bfOffBits - sizeof(BITMAPFILEHEADER);
    pbmi = (BITMAPINFO *)malloc(dwInfoSize);

    unsigned char* p_data = NULL;

    BITMAPINFO bmpInfo; //创建位图 
    //bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    //bmpInfo.bmiHeader.biWidth = 480;//宽度
    //bmpInfo.bmiHeader.biHeight = 480;//高度
    //bmpInfo.bmiHeader.biPlanes = 1;
    //bmpInfo.bmiHeader.biBitCount = 24;
    //bmpInfo.bmiHeader.biCompression = BI_RGB;

    bmpInfo.bmiHeader = bitmap.infoHeader;

    HBITMAP		   hBitmap;
    hBitmap = CreateDIBSection(0, &bmpInfo, DIB_RGB_COLORS, (void**)&p_data, 0, 0);
    if (hBitmap)
    {
        //HDC hdcMem;
        GetObject(hBitmap, sizeof(BITMAP), &bitmap); 
        //hdcMem = CreateCompatibleDC(&dc);
        //SelectObject(hdcMem, hBitmap); 
        //BitBlt(hdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY); 
        //DeleteDC(hdcMem);

        memcpy(p_data, bitmap.dataBuf, bitmap.bitCount);
    }
    else
    {
        printf("error.\n");
        exit(-1);
    }

    

    CDC dcCompatible;
    dcCompatible.CreateCompatibleDC(&dc);
    dcCompatible.SelectObject(hBitmap);

    //m_media_buffer = (unsigned char*)"123456789";

    //HBITMAP		   m_hBitmap;

    //BYTE				buffer[sizeof(BITMAPINFOHEADER) + 3 * sizeof(RGBQUAD)];
    //BITMAPINFO*			pBMI = (BITMAPINFO*)buffer;
    //BITMAPINFOHEADER*	pHeader = &pBMI->bmiHeader;
    //DWORD*				pColors = (DWORD*)&pBMI->bmiColors;
    //m_hBitmap = CreateDIBSection(0, pBMI, DIB_RGB_COLORS, (void**)&m_media_buffer, 0, 0);
    //::SelectObject(dcCompatible, m_hBitmap);

    CRect rect;
    GetClientRect(&rect);
    BitBlt(dc.m_hDC, 0, 0, rect.Width(), rect.Height(), 
        dcCompatible.m_hDC,0,0,SRCCOPY);
#endif

    CFile file("D:\\GithubPro\\WindowsCppTest\\show_video1\\res\\bitmap1.bmp", CFile::modeRead);
    char* bmpbuf = new char[file.GetLength() + 1];
    file.Read(bmpbuf, file.GetLength());
    //分析文件
    BITMAPFILEHEADER* bmpfileheader = (BITMAPFILEHEADER*)bmpbuf;//文件头
    BITMAPINFOHEADER* bmpinfoheader = (BITMAPINFOHEADER*)((char*)bmpbuf + sizeof(BITMAPFILEHEADER));//位图头
    BITMAPINFO* bmpinfo = (BITMAPINFO*)bmpinfoheader;//位图信息
    CClientDC dc(this);


    ////第一种方法
    //StretchDIBits(dc.GetSafeHdc(), 0, 0, bmpinfoheader->biWidth, bmpinfoheader->biHeight,
    //    0, 0, bmpinfoheader->biWidth, bmpinfoheader->biHeight,
    //    bmpbuf + bmpfileheader->bfOffBits,
    //    bmpinfo,
    //    DIB_RGB_COLORS,SRCCOPY);

    ////第二种方法
    //void* p = NULL;
    //HBITMAP hbmp = CreateDIBSection(dc.GetSafeHdc(),bmpinfo,DIB_RGB_COLORS,&p,NULL,0);//CreateDIBSection
    //memcpy(p,bmpbuf+bmpfileheader->bfOffBits,bmpinfoheader->biSizeImage);
    //CBitmap bitmap;
    //bitmap.Attach(hbmp);
    //CDC cmpDC;
    //cmpDC.CreateCompatibleDC(&dc);
    //CBitmap* oldbmp = cmpDC.SelectObject(&bitmap);
    //dc.StretchBlt(0,0,1024,768,&cmpDC,0,0,bmpinfoheader->biWidth,bmpinfoheader->biHeight,SRCCOPY);
    //cmpDC.SelectObject(oldbmp);
    //第三种方法
    HBITMAP hbitmap = CreateDIBitmap(dc.GetSafeHdc(),bmpinfoheader,CBM_INIT,bmpbuf+bmpfileheader->bfOffBits,bmpinfo,DIB_RGB_COLORS);
    CDC cmpDC;
    cmpDC.CreateCompatibleDC(&dc);
    HBITMAP oldbmp = (HBITMAP)::SelectObject(cmpDC.GetSafeHdc(),hbitmap);
    dc.BitBlt(0,0,1024,768,&cmpDC,0,0,SRCCOPY);
    cmpDC.SelectObject(oldbmp);

    printf("ok");
}

