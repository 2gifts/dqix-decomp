#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_02222eb0(void*);
extern "C" void func_ov031_0223e2b8(void*, void*);
extern "C" void func_ov031_02222fb0(void);

struct Struct02222f44_arr {
	int arr[1];
	unsigned char pad[19];
	unsigned char type;
};
extern Struct02222f44_arr* data_ov031_02250ba8;

// USA: func_ov031_02222f44
#pragma optimize_for_size off
ARM void Dispatch_02222f44(void* a) {
	unsigned int local0, local1;
	Struct02222f44_arr* p = data_ov031_02250ba8;
	ExtractPackedHiLo_0223bd28((Header_0223bd28*)p->arr[2], 0, &local0, &local1);
	local1 -= 4;
	func_ov031_02222eb0((void*)local1);
	if ((int)local1 > 0xa8) return;
	func_ov031_02222eb0((void*)0xa8);
	func_ov031_0223e2b8(a, (void*)func_ov031_02222fb0);
}
