#pragma once


#include <afxcmn.h>
// CTextProgressCtrl

class THOMASZHUUTILITYMFC_API CTextProgressCtrl : public CProgressCtrl
{
public:
	CTextProgressCtrl();
	~CTextProgressCtrl();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

protected:
	COLORREF m_prgsColor; //���������Ȳ�����ɫ
	COLORREF m_freeColor; //������������ಿ����ɫ
	COLORREF m_prgsTextColor; //���Ȳ���������ɫ
	COLORREF m_freeTextColor; //�հײ���������ɫ

	LARGE_INTEGER m_liStart;
	LARGE_INTEGER m_liFreq;

	int  m_iMin;    //����������Сֵ��ͨ����0
	int  m_iMax;    //�����������ֵ��ͨ����100
	int  m_iPos;    //��ǰ�Ľ���
	int  m_nBarWidth;  //���������
	int m_nStep;

public:
	int SetPos(int nPos);
	void SetRange32(int nLower, int nUpper);
	void SetStep(int nStep);
	int StepIt();
};


