#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

// USA: func_ov005_02157190
ARM int CheckFlag30Or401_02157190(void*) {
	int result = 0;
	if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x30)) {
		if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x401)) result = 1;
	}
	return result;
}
