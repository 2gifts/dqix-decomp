#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern unsigned char data_ov005_0215cd20;

// USA: func_ov005_0215a930
ARM unsigned char GetTableByte0215a930(void *unused, int index) {
	if ((unsigned int)index >= 8) return 0;
	return (&data_ov005_0215cd20)[index];
}
