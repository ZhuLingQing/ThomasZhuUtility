#pragma once


#include <afxcmn.h>
// CTextProgressCtrl

class THOMASZHUUTILITYMFC_API CTextProgressCtrl : public CProgressCtrl
{
public:
	CTextProgressCtrl();
	~CTextProgressCtrl();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

protected:
	COLORREF m_prgsColor; //进度条进度部分颜色
	COLORREF m_freeColor; //进度条后面空余部分颜色
	COLORREF m_prgsTextColor; //进度部分字体颜色
	COLORREF m_freeTextColor; //空白部分字体颜色

	LARGE_INTEGER m_liStart;
	LARGE_INTEGER m_liFreq;

	int  m_iMin;    //进度条的最小值，通常是0
	int  m_iMax;    //进度条的最大值，通常是100
	int  m_iPos;    //当前的进度
	int  m_nBarWidth;  //进度条宽度
	int m_nStep;

public:
	int SetPos(int nPos);
	void SetRange32(int nLower, int nUpper);
	void SetStep(int nStep);
	int StepIt();
};


