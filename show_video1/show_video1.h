
// show_video1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cshow_video1App:
// See show_video1.cpp for the implementation of this class
//

class Cshow_video1App : public CWinApp
{
public:
	Cshow_video1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cshow_video1App theApp;