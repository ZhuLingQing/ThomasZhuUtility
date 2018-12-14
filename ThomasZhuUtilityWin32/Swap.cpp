#include "ThomasZhuUtilityWin32.h"

THOMASZHUUTILITYWIN32_API UINT64 zlibSwapUint64(UINT64 val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
	return (val << 32) | (val >> 32);
}
THOMASZHUUTILITYWIN32_API UINT32 zlibSwapUint32(UINT32 val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0x00FF00FF);
	return (val << 16) | (val >> 16);
}
THOMASZHUUTILITYWIN32_API UINT16 zlibSwapUint16(UINT16 val)
{
	return (val << 8) | (val >> 8);
}