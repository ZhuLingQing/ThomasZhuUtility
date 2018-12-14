#include "ThomasZhuUtilityWin32.h"
#include "PreciseTime.h"

CPreciseTime::CPreciseTime(void)
{
	QueryPerformanceFrequency(&liFreq);
}

CPreciseTime::~CPreciseTime(void)
{
}

void CPreciseTime::Start()
{
	QueryPerformanceCounter(&liStart);
}

double CPreciseTime::SecondPassed()
{
	double result;
	LARGE_INTEGER liNow;
	QueryPerformanceCounter(&liNow);
	result = (liNow.QuadPart - liStart.QuadPart);
	result = result / liFreq.QuadPart;
	return result;
}

unsigned long long CPreciseTime::MicroSecondPassed()
{
	unsigned long long result;
	LARGE_INTEGER liNow;
	QueryPerformanceCounter(&liNow);
	result = (liNow.QuadPart - liStart.QuadPart) * 1000000;
	result = result / liFreq.QuadPart;
	return result;
}