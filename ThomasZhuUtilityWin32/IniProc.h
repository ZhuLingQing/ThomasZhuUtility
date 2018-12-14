#pragma once

class THOMASZHUUTILITYWIN32_API CIniProc
{
public:
	CIniProc(void);
	~CIniProc(void);
	void Open(LPCTSTR pathName);
	unsigned int ReadValueDec(LPTSTR section, LPCTSTR item, unsigned int defaultVal = 0);
	unsigned int ReadValueHex(LPTSTR section, LPCTSTR item, unsigned int defaultVal = 0);
	double ReadValueDbl(LPTSTR section, LPCTSTR item, double defaultVal = 0.0);
	void ReadString(LPCTSTR section, LPCTSTR item, LPTSTR val, unsigned int maxLength, LPCTSTR defaultVal = _T(""));

	void WriteValueDec(LPTSTR section, LPCTSTR item, unsigned int value);
	void WriteValueHex(LPTSTR section, LPCTSTR item, unsigned int value);
	void WriteValueDbl(LPTSTR section, LPCTSTR item, double value);
	void WriteString(LPCTSTR section, LPCTSTR item, LPTSTR val);

protected:
	TCHAR m_pathName[MAX_PATH];
};
