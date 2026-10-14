#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);

struct Struct02290d10_022384f8 { Header_0223bd28* header; unsigned char pad[0x1e - 4]; unsigned char field1e; };
extern Struct02290d10_022384f8* data_ov031_02290d10;

extern "C" void func_ov031_022381c8(int);
extern "C" void func_ov031_0223e2b8(void*, int);
extern "C" void func_ov031_022385e4(int);
extern "C" void func_ov031_02238588(int);

// USA: func_ov031_022384f8  (semantic: ExtractAndDispatchByThreshold_022384f8)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_022384f8(void* arg) {
	unsigned int outHi, outLo;
	ExtractPackedHiLo_0223bd28(data_ov031_02290d10->header, 0, &outHi, &outLo);
	outLo = outLo + 0xc;
	func_ov031_022381c8((int)outLo);
	if ((int)outLo < 0xc0) return;
	if (data_ov031_02290d10->field1e != 0) {
		func_ov031_0223e2b8(arg, (int)func_ov031_02238588);
	} else {
		func_ov031_0223e2b8(arg, (int)func_ov031_022385e4);
	}
}
