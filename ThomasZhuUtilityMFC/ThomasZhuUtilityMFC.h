// ThomasZhuUtilityMFC.h : main header file for the ThomasZhuUtilityMFC DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

#ifdef THOMAS_ZHU_UTIL_MFC
#define THOMASZHUUTILITYMFC_API __declspec(dllexport)
#else
#define THOMASZHUUTILITYMFC_API __declspec(dllimport)
#endif

#include "TextProgressCtrl.h"

// CThomasZhuUtilityMFCApp
// See ThomasZhuUtilityMFC.cpp for the implementation of this class
//

class CThomasZhuUtilityMFCApp : public CWinApp
{
public:
	CThomasZhuUtilityMFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

THOMASZHUUTILITYMFC_API void SetWndFontSameWidth(CWnd * pWnd, int size);

//extFormat = _T("binary File(*.bin)|*.bin")
THOMASZHUUTILITYMFC_API CString GetFilePathName(BOOL bOpen, LPCTSTR extFormat);

THOMASZHUUTILITYMFC_API CString SelectPath(CWnd * pWnd = NULL);