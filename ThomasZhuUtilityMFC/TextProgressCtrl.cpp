// TextProgressCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "ThomasZhuUtilityMFC.h"
#include "TextProgressCtrl.h"


// CTextProgressCtrl#include "CTextProgressCtrl.h"



CTextProgressCtrl::CTextProgressCtrl()
{
	m_prgsColor = RGB(0,0,255); //���������Ȳ�����ɫ
	m_freeColor = RGB(255,255,255); //������������ಿ����ɫ
	m_prgsTextColor = RGB(255, 255, 255); //���Ȳ���������ɫ
	m_freeTextColor = RGB(0, 0, 255); //�հײ���������ɫ
	m_nStep = 1;
	QueryPerformanceFrequency(&m_liFreq);
}


CTextProgressCtrl::~CTextProgressCtrl()
{
}
void CTextProgressCtrl::DoDataExchange(CDataExchange* pDX)
{
	CProgressCtrl::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTextProgressCtrl, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()

int CTextProgressCtrl::SetPos(int nPos)
{
	if (!::IsWindow(m_hWnd))
	{
		return -1;
	}

	int nOldPos = m_iPos;
	m_iPos = nPos;
	if (m_iPos == m_iMin)
		QueryPerformanceCounter(&m_liStart);

	CRect rect;
	GetClientRect(rect);

	//�����ȼ���Ҫ��ʾ�Ľ�������ȣ������ͬһ���ȶ�λ��ƴ���

	double Fraction = (double)(m_iPos - m_iMin) / ((double)(m_iMax - m_iMin));
	int nBarWidth = (int)(Fraction * rect.Width());

	if (nBarWidth != m_nBarWidth)
	{
		m_nBarWidth = nBarWidth;
		RedrawWindow();
	}

	return nOldPos;
}

void CTextProgressCtrl::SetRange32(int nLower, int nUpper)
{
	m_iMax = nUpper;
	m_iMin = nLower;
	m_iPos = m_iMin;
	m_nBarWidth = 0;
}
void CTextProgressCtrl::SetStep(int nStep)
{
	m_nStep = nStep;
}

int CTextProgressCtrl::StepIt()
{
	return SetPos(m_iPos + m_nStep);
}


void CTextProgressCtrl::OnPaint()
{
	//�����ж������Ƿ���Ч
	if (m_iMin >= m_iMax)
	{
		return;
	}

	CPaintDC dc(this); // device context for painting
	// ��Ϊ��ͼ��Ϣ���� CProgressCtrl::OnPaint()


	//��ȡ��Ч�Ľ�������λ�úʹ�С
	CRect LeftRect, RightRect, ClientRect;
	GetClientRect(ClientRect);
	LeftRect = RightRect = ClientRect;

	//������ʾ���ȵı���
	double Fraction = (double)(m_iPos - m_iMin) / ((double)(m_iMax - m_iMin));

	//���������������е���Ч����
	LeftRect.right = LeftRect.left + (int)((LeftRect.right - LeftRect.left) * Fraction);
	dc.FillSolidRect(LeftRect, m_prgsColor);

	//����ʣ�����
	RightRect.left = LeftRect.right;
	dc.FillSolidRect(RightRect, m_freeColor);

	CString str;
	LARGE_INTEGER liNow;
	QueryPerformanceCounter(&liNow);
	unsigned int sec = (((liNow.QuadPart - m_liStart.QuadPart)) / m_liFreq.QuadPart);
	str.Format(_T("%.2f%% (%d By, %d Sec)"), (float)(Fraction*100.0), m_iPos, sec);

	//�������ֱ�����ɫΪ͸��
	dc.SetBkMode(TRANSPARENT);

	//Ϊ���ܹ��ڽ��Ⱥ�ʣ���������ʾ��ͬ��ɫ�����壬��Ҫ�ֱ��������ߵ�������ɫ����ͼ

	CRgn rgn;
	rgn.CreateRectRgn(LeftRect.left, LeftRect.top, LeftRect.right, LeftRect.bottom);
	dc.SelectClipRgn(&rgn);
	dc.SetTextColor(m_prgsTextColor);
	dc.DrawText(str, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rgn.DeleteObject();
	rgn.CreateRectRgn(RightRect.left, RightRect.top, RightRect.right, RightRect.bottom);
	dc.SelectClipRgn(&rgn);
	dc.SetTextColor(m_freeTextColor);
	dc.DrawText(str, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//�����������������ֻ��ʾһ��������ɫ����ô����ֱ�ӵ���
	//dc.SetTextColor(m_freeTextColor);
	//dc.DrawText(str, ClientRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}