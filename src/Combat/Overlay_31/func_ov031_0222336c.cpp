#include <globaldefs.h>

#include "Resource/UiArrayEntry.h"

extern "C" void func_ov031_022234d8(int a0, void* cb);
extern "C" ARM int LoadToSubBG0ScreenData(int arg0, int arg1, unsigned int arg2);
extern "C" int func_ov031_0223c560(int a, int b);
ARM int GetTableEntryByField0_022236d0(void);
extern "C" void func_ov031_0223c980(int a0, int a1, int a2, int a3, int s0, int s1, int s2, int s3);
ARM void SetFlagIfMatchesElem0_0223caec(void* ptr);

extern unsigned char data_ov031_02250bac;
extern int data_ov031_0224b1dc;
extern void* data_ov031_02290c4c;

// USA: func_ov031_0222336c
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0222336c(int a0, int a1, int a2) {
	if (data_ov031_02250bac != 0) {
		return 0;
	}
	func_ov031_022234d8((int)&data_ov031_0224b1dc, (void*)LoadToSubBG0ScreenData);
	*(int*)0x4001010 = 0x1920000;
	int r4 = func_ov031_0223c560(1, 0);
	int r5 = func_ov031_022276cc(data_ov031_02290c4c, a0, a1, a2);
	int table = GetTableEntryByField0_022236d0();
	func_ov031_0223c980(r4, 0x14, 0, 0xd8, 0x40, 2, table, r5);
	SetFlagIfMatchesElem0_0223caec((void*)r4);
	data_ov031_02250bac = 1;
	return 1;
}
