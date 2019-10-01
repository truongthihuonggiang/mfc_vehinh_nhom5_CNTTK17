
// baive.h : main header file for the baive application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CbaiveApp:
// See baive.cpp for the implementation of this class
//

class CbaiveApp : public CWinApp
{
public:
	CbaiveApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CbaiveApp theApp;
