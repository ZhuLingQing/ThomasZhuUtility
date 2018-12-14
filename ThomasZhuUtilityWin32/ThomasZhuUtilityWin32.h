// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the THOMASZHUUTILITYWIN32_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// THOMASZHUUTILITYWIN32_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef THOMASZHUUTILITYWIN32_EXPORTS
#define THOMASZHUUTILITYWIN32_API __declspec(dllexport)
#else
#define THOMASZHUUTILITYWIN32_API __declspec(dllimport)
#endif

#include <vector>
#include <string>
using namespace std;

#ifdef UNICODE
#define SPRINTF	swprintf_s
#define SSCANF	swscanf_s
#define STRCPY	wcscpy_s
#define STRING	wstring
#define STR_FMT	zlibFormatWstring
#define STR_DUMP zlibDumpWstring
#else
#define SPRINTF sprintf_s
#define SSCANF	sscanf_s
#define STRCPY	strcpy_s
#define STRING	string
#define STR_FMT	zlibFormatString
#define STR_DUMP zlibDumpString
#endif

#include <tchar.h>
#include "ComputeHash.h"
#include "PreciseTime.h"
#include "IniProc.h"
#include "Log.h"

THOMASZHUUTILITYWIN32_API HANDLE zlibOpenCom(UINT portIndex);

THOMASZHUUTILITYWIN32_API unsigned int zlibLengthAlign(unsigned int length, unsigned int align);


THOMASZHUUTILITYWIN32_API UINT16 zlibCrc16( const void *data, unsigned int length, UINT16 seed = 0xFFFF);
THOMASZHUUTILITYWIN32_API UINT32 zlibChecksum32( const void *data, unsigned int length, UINT32 seed = 0);

THOMASZHUUTILITYWIN32_API UINT64 zlibSwapUint64(UINT64 val);
THOMASZHUUTILITYWIN32_API UINT32 zlibSwapUint32(UINT32 val);
THOMASZHUUTILITYWIN32_API UINT16 zlibSwapUint16(UINT16 val);

THOMASZHUUTILITYWIN32_API LPCTSTR zlibFindFileExt(LPCTSTR pathName);
THOMASZHUUTILITYWIN32_API LPCTSTR zlibFindFileName(LPCTSTR pathName);

THOMASZHUUTILITYWIN32_API string & zlibFormatString(string & _str, const char * _Format, ...);
THOMASZHUUTILITYWIN32_API wstring & zlibFormatWstring(wstring & _str, const wchar_t * _Format, ...);

THOMASZHUUTILITYWIN32_API string & zlibDumpString(string & _str, const unsigned char *buf, unsigned int length, unsigned int address, unsigned char width = 1);
THOMASZHUUTILITYWIN32_API wstring & zlibDumpWstring(wstring & _str, const unsigned char *buf, unsigned int length, unsigned int address, unsigned char width = 1);