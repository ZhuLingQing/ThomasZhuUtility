// ThomasZhuUtilityMFC.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "ThomasZhuUtilityMFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CThomasZhuUtilityMFCApp

BEGIN_MESSAGE_MAP(CThomasZhuUtilityMFCApp, CWinApp)
END_MESSAGE_MAP()


// CThomasZhuUtilityMFCApp construction

CThomasZhuUtilityMFCApp::CThomasZhuUtilityMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CThomasZhuUtilityMFCApp object

CThomasZhuUtilityMFCApp theApp;


// CThomasZhuUtilityMFCApp initialization

BOOL CThomasZhuUtilityMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

THOMASZHUUTILITYMFC_API void zlibSetWndFontSameWidth(CWnd * pWnd, int size)
{
	CFont * f = new CFont;

	f->CreateFont(size, // nHeight

		0, // nWidth

		0, // nEscapement

		0, // nOrientation

		FW_DONTCARE,//FW_BOLD // nWeight

		FALSE, // bItalic

		FALSE, // bUnderline

		0, // cStrikeOut

		ANSI_CHARSET, // nCharSet

		OUT_DEFAULT_PRECIS, // nOutPrecision

		CLIP_DEFAULT_PRECIS, // nClipPrecision

		DEFAULT_QUALITY, // nQuality

		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily

		_T("Courier")); // lpszFac 

	pWnd->SetFont(f);      //IDC_EDIT_RECEIVE是Edit框标号
}

THOMASZHUUTILITYMFC_API CString zlibGetFilePathName(BOOL bOpen, LPCTSTR extFormat)
{
	CString sfmt;
	sfmt.Format(_T("%s|All files(*.*)|*.*||"),extFormat);
	CFileDialog dlg(bOpen,NULL,NULL,OFN_HIDEREADONLY,sfmt.GetBuffer());
	if(dlg.DoModal() == IDOK)
		return dlg.GetPathName();
	return _T("");
}

THOMASZHUUTILITYMFC_API CString zlibSelectPath(CWnd * pWnd)
{
	CString result;
	TCHAR pszPath[MAX_PATH];
	BROWSEINFO bi; 
	bi.hwndOwner      = pWnd?pWnd->GetSafeHwnd():NULL;
	bi.pidlRoot       = NULL;
	bi.pszDisplayName = NULL; 
	bi.lpszTitle      = _T("请选择文件夹"); 
	//bi.ulFlags        = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT;
	bi.ulFlags = 0x0040 | BIF_EDITBOX; //添加“新建文件夹项”
	bi.lpfn           = NULL; 
	bi.lParam         = 0;
	bi.iImage         = 0; 

	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	if (pidl == NULL)
	{
		return _T("");
	}

	if (SHGetPathFromIDList(pidl, pszPath))
	{
		int sl = wcslen(pszPath) - 1;
		if(pszPath[sl] != _T('\\'))
		{
			pszPath[sl] = _T('\\');
			pszPath[sl+1] = _T('\0');
			result = pszPath;
			return result;
		}
	}
	return _T("");
}