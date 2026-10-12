#include <globaldefs.h>

struct Header_0223bd28;
extern "C" void _Z26ExtractPackedHiLo_0223bd28P15Header_0223bd28iPjS1_(Header_0223bd28*, int, unsigned int*, unsigned int*);
extern "C" void func_ov031_02222eb0(void*);
extern "C" void func_ov031_0223e2b8(void*, void*);
extern "C" void func_ov031_022231f0(int);

struct Struct0222318c_arr { int arr[1]; unsigned char pad[19]; unsigned char type; };
extern Struct0222318c_arr* data_ov031_02250ba8;

// USA: func_ov031_0222318c  (semantic: AdvanceCounterAndArm_0222318c)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222318c(void* a) {
	unsigned int outHi, outLo;
	Struct0222318c_arr* p = data_ov031_02250ba8;
	_Z26ExtractPackedHiLo_0223bd28P15Header_0223bd28iPjS1_((Header_0223bd28*)p->arr[2], 0, &outHi, &outLo);
	outLo += 4;
	func_ov031_02222eb0((void*)outLo);
	if ((int)outLo < 0xc0) return;
	func_ov031_0223e2b8(a, (void*)func_ov031_022231f0);
}
