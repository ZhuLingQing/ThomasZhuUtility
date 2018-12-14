#pragma once


typedef enum {
	LOG_ALL = 0,
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,

	LOG_END
}LOG_LEVEL;

typedef struct {
	LOG_LEVEL level;
	SYSTEMTIME sys_tm;
	STRING str_log;
}LOG_ITEM;

#define LOG_PARAM_TIMESTAMP		(1<<0)
#define LOG_PARAM_CRLF			(1<<1)

class THOMASZHUUTILITYWIN32_API CLog
{
public:
	CLog();
	~CLog(void);
	void Clear();
	void PushBack(LPCTSTR _log, LOG_LEVEL lvl = LOG_INFO);
	STRING GetLog(LOG_LEVEL lvl = LOG_INFO,unsigned int param = (LOG_PARAM_TIMESTAMP|LOG_PARAM_CRLF));
	DWORD Save(LPCTSTR pathName,LOG_LEVEL lvl = LOG_INFO,unsigned int param = (LOG_PARAM_TIMESTAMP|LOG_PARAM_CRLF));
protected:
	vector<LOG_ITEM*>* m_log;
	unsigned int m_param;
};
