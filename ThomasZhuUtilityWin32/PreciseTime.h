#pragma once
#include "windows.h"

class THOMASZHUUTILITYWIN32_API CPreciseTime
{
public:
	CPreciseTime(void);
	~CPreciseTime(void);
	void Start();
	double SecondPassed();
	unsigned long long MicroSecondPassed();
protected:
	LARGE_INTEGER liFreq,liStart;
};
