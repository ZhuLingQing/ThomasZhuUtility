#include "ThomasZhuUtilityWin32.h"
#include <assert.h>
#include "Log.h"


CLog::CLog()
{
	m_log = new vector<LOG_ITEM*>[LOG_END];
}

CLog::~CLog(void)
{
	Clear();
	delete m_log;
}

void CLog::Clear()
{
	vector<LOG_ITEM*>::iterator it;
	for(it = m_log[LOG_ALL].begin(); it !=  m_log[LOG_ALL].end(); it++)
		delete *it;
	for(int i = 0; i < LOG_END; i++)
		m_log[i].clear();
}
void CLog::PushBack(LPCTSTR _log, LOG_LEVEL lvl)
{
	LOG_ITEM *item;
	assert((lvl > LOG_ALL) && (lvl < LOG_END));

	item = new LOG_ITEM;
	GetLocalTime(&item->sys_tm);
	item->level = lvl;
	item->str_log = _log;
	m_log[LOG_ALL].push_back(item);
	m_log[lvl].push_back(item);
}

static const TCHAR s_log_level[] = {_T('A'),_T('I'),_T('W'),_T('E')};

STRING CLog::GetLog(LOG_LEVEL lvl,unsigned int param)
{
	vector<LOG_ITEM*>::iterator it;
	STRING s,tmp;
	assert(lvl < LOG_END);
	for(it = m_log[lvl].begin(); it !=  m_log[lvl].end(); it++)
	{

		if(lvl == LOG_ALL)
		{
			tmp = STR_FMT(tmp,_T("%c]"),s_log_level[(*it)->level]);
			s += tmp;
		}
 		if(param & LOG_PARAM_TIMESTAMP)
		{
 			tmp = STR_FMT(tmp,_T("[%4d-%02d-%02d %2d:%02d:%02d:%03d]"),
			(*it)->sys_tm.wYear,(*it)->sys_tm.wMonth,(*it)->sys_tm.wDay,
			(*it)->sys_tm.wHour,(*it)->sys_tm.wMinute,(*it)->sys_tm.wSecond,(*it)->sys_tm.wMilliseconds);
			s += tmp;
		}

		s += (*it)->str_log;

		if(param & LOG_PARAM_CRLF)
			s += _T("\r\n");
	}
	return s;
}

DWORD CLog::Save(LPCTSTR pathName,LOG_LEVEL lvl,unsigned int param)
{
	HANDLE hFile = CreateFile(pathName,GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		STRING s = GetLog(lvl,param);
		DWORD sz = s.length();
		WriteFile(hFile,s.c_str(),sz,&sz,NULL);
		CloseHandle(hFile);
		return 0;
	}
	else
		return GetLastError();
}