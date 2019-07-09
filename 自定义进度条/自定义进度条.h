
// 自定义进度条.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CcustomProCtrlApp:
// See 自定义进度条.cpp for the implementation of this class
//

class CcustomProCtrlApp : public CWinApp
{
public:
	CcustomProCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CcustomProCtrlApp theApp;