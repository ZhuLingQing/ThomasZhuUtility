#include "ThomasZhuUtilityWin32.h"
#include <tchar.h>
#include "IniProc.h"

CIniProc::CIniProc(void)
{
	ZeroMemory(m_pathName,sizeof(m_pathName));
}

CIniProc::~CIniProc(void)
{
}

void CIniProc::Open(LPCTSTR pathName)
{
	STRCPY(m_pathName,MAX_PATH,pathName);
}

unsigned int CIniProc::ReadValueDec(LPTSTR section, LPCTSTR item, unsigned int defaultVal)
{
	unsigned int result;
	TCHAR s_default[MAX_PATH] = {0};
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_default,MAX_PATH,_T("%d"),defaultVal);
	GetPrivateProfileString(section,item,s_default,s_val,MAX_PATH,m_pathName);
	SSCANF(s_val,_T("%d"),&result);
	return result;
}
unsigned int CIniProc::ReadValueHex(LPTSTR section, LPCTSTR item, unsigned int defaultVal)
{
	unsigned int result;
	TCHAR s_default[MAX_PATH] = {0};
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_default,MAX_PATH,_T("%X"),defaultVal);
	GetPrivateProfileString(section,item,s_default,s_val,MAX_PATH,m_pathName);
	SSCANF(s_val,_T("%X"),&result);
	return result;
}
double CIniProc::ReadValueDbl(LPTSTR section, LPCTSTR item, double defaultVal)
{
	double result;
	TCHAR s_default[MAX_PATH] = {0};
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_default,MAX_PATH,_T("%lf"),defaultVal);
	GetPrivateProfileString(section,item,s_default,s_val,MAX_PATH,m_pathName);
	SSCANF(s_val,_T("%lf"),&result);
	return result;
}

void CIniProc::ReadString(LPCTSTR section, LPCTSTR item, LPTSTR val, unsigned int maxLength, LPCTSTR defaultVal)
{
	GetPrivateProfileString(section,item,defaultVal,val,maxLength,m_pathName);
}


void CIniProc::WriteValueDec(LPTSTR section, LPCTSTR item, unsigned int value)
{
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_val,MAX_PATH,_T("%d"),value);
	WritePrivateProfileString(section, item, s_val, m_pathName);
}
void CIniProc::WriteValueHex(LPTSTR section, LPCTSTR item, unsigned int value)
{
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_val,MAX_PATH,_T("%X"),value);
	WritePrivateProfileString(section, item, s_val, m_pathName);
}
void CIniProc::WriteValueDbl(LPTSTR section, LPCTSTR item, double value)
{
	TCHAR s_val[MAX_PATH] = {0};
	SPRINTF(s_val,MAX_PATH,_T("%lf"),value);
	WritePrivateProfileString(section, item, s_val, m_pathName);
}
void CIniProc::WriteString(LPCTSTR section, LPCTSTR item, LPTSTR val)
{
	WritePrivateProfileString(section, item, val, m_pathName);
}