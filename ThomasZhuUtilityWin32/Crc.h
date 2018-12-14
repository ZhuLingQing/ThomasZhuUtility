#pragma once


class C

class CCrc16
{
public:
	CCrc16(void){};
	~CCrc16(void){};
	static unsigned short Calc(const void* pbyData, unsigned int dwLength, unsigned short seed = 0xFFFF);
};
