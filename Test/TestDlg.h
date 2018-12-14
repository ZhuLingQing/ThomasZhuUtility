
// TestDlg.h : header file
//

#pragma once
#include "..\ThomasZhuUtilityMFC\ThomasZhuUtilityMFC.h"
#include "..\ThomasZhuUtilityWin32\ThomasZhuUtilityWin32.h"


// CTestDlg dialog
class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelfile();
	afx_msg void OnBnClickedButtonSelpath();

	CLog m_log;
};
