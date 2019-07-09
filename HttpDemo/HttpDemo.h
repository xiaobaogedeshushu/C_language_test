
// HttpDemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CHttpClient.h" 


// CHttpDemoApp:
// See HttpDemo.cpp for the implementation of this class
//

class CHttpDemoApp : public CWinApp
{
public:
	CHttpDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();
	CHttpClient http;
	CString strUrl, strContent;

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHttpClient http;