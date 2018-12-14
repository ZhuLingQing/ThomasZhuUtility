// ThomasZhuUtilityWin32.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "ThomasZhuUtilityWin32.h"
#include <assert.h>
#include <tchar.h>

THOMASZHUUTILITYWIN32_API HANDLE zlibOpenCom(UINT portIndex)
{
	TCHAR path[MAX_PATH] = {0};
	SPRINTF(path,MAX_PATH,_T("\\\\.\\COM%d"),portIndex);
	return CreateFile(
		path,           //   address   of   name   of   the   communications   device   
		GENERIC_READ | GENERIC_WRITE,                     //   access   (read-write)   mode   
		0,                                     //   share   mode   
		NULL,                               //   address   of   security   descriptor   
		OPEN_EXISTING,             //   how   to   create   
		0,                                     //   file   attributes   
		NULL                                 //   handle   of   file   with   attributes   to   copy   
		);
}

THOMASZHUUTILITYWIN32_API unsigned int zlibLengthAlign(unsigned int length, unsigned int align)
{
	if(length & (align - 1))
	{
		length += align;
		length &=~(align - 1);
	}
	return length;
}

THOMASZHUUTILITYWIN32_API LPCTSTR zlibFindFileExt(LPCTSTR pathName)
{
	LPCTSTR lastPoint = NULL;

	pathName = zlibFindFileName(pathName);
	if(pathName == NULL) return NULL;

	while(*pathName)
	{
		if(*pathName == _T('.'))
			lastPoint = pathName + 1;
		pathName ++;
	}
	return ((*lastPoint)?lastPoint:NULL);
}

THOMASZHUUTILITYWIN32_API LPCTSTR zlibFindFileName(LPCTSTR pathName)
{
	LPCTSTR lastPoint = NULL;

	while(*pathName)
	{
		if(*pathName == _T('\\'))
			lastPoint = pathName + 1;
		pathName ++;
	}
	return ((*lastPoint)?lastPoint:NULL);
}

THOMASZHUUTILITYWIN32_API std::string & zlibFormatString(std::string & _str, const char * _Format, ...) {
	std::string tmp;

	va_list marker = NULL;
	va_start(marker, _Format);

	size_t num_of_chars = _vscprintf(_Format, marker);

	if (num_of_chars > tmp.capacity()) {
		tmp.resize(num_of_chars + 1);
	}

	vsprintf_s((char *)tmp.data(), tmp.capacity(), _Format, marker);

	va_end(marker);

	_str = tmp.c_str();
	return _str;
}

THOMASZHUUTILITYWIN32_API std::wstring & zlibFormatWstring(std::wstring & _str, const wchar_t * _Format, ...) {
	std::wstring tmp;

	va_list marker = NULL;
	va_start(marker, _Format);

	size_t num_of_chars = _vscwprintf(_Format, marker);

	if (num_of_chars > tmp.capacity()) {
		tmp.resize(num_of_chars + 1);
	}

	vswprintf_s((wchar_t *)tmp.data(), tmp.capacity(), _Format, marker);

	va_end(marker);

	_str = tmp.c_str();
	return _str;
}

THOMASZHUUTILITYWIN32_API string & zlibDumpString(string & _str, const unsigned char *buf, unsigned int length, unsigned int address, unsigned char width)
{
	unsigned int i = 0;
	char * p, *t;

	assert((width == 1)||(width == 2)||(width == 4));

	p = new char[length * 3 * 2];
	ZeroMemory(p,length * 3 * 2);
	t = p;
	while(i < length)
	{
		if(i++ % 16 == 0)
			t += sprintf_s(t,length * 3 * 2 - (t - p),"\r\n%08X:",address++);
		t += sprintf_s(t,length * 3 * 2 - (t - p)," %02X",*buf++);
	}
	_str = p;
	delete p;
	return _str;
}

THOMASZHUUTILITYWIN32_API wstring & zlibDumpWstring(wstring & _str, const unsigned char *buf, unsigned int length, unsigned int address, unsigned char width)
{
	unsigned int i = 0;
	wchar_t * p, *t;

	assert((width == 1)||(width == 2)||(width == 4));

	p = new wchar_t[length * 3 * 2];
	ZeroMemory(p,length * 3 * 2);
	t = p;
	while(i < length)
	{
		if(i++ % 16 == 0)
			t += swprintf_s(t,length * 3 * 2 - (t - p),_T("\r\n%08X:"),address++);
		t += swprintf_s(t,length * 3 * 2 - (t - p),_T(" %02X"),*buf++);
	}
	_str = p;
	delete p;
	return _str;
}