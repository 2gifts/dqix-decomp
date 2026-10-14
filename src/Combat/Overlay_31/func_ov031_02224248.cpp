#include <globaldefs.h>

struct Header_0223bd28;
void ExtractPackedHiLo_0223bd28(Header_0223bd28*, int, unsigned int*, unsigned int*);

struct Entity02224248 {
	unsigned char pad0[0xfc];
	Header_0223bd28* header;
	unsigned char pad1[0x11d - 0x100];
	unsigned char field11d;
};
extern Entity02224248* data_ov031_02250bfc;

extern "C" void func_ov031_02224ca4(int a, int idx, int off);
extern "C" void func_ov031_0222506c(void);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
void RunFourStagesA_022242d4(void);

#pragma optimize_for_size off
// USA: func_ov031_02224248
extern "C" ARM void func_ov031_02224248(void* obj) {
	unsigned int outHi, outLo;
	ExtractPackedHiLo_0223bd28(data_ov031_02250bfc->header, 0, &outHi, &outLo);
	int off = (int)outLo - 0xc;
	outLo = (unsigned int)off;
	if (off > 0xaa) {
		func_ov031_02224ca4(data_ov031_02250bfc->field11d, 4, off);
		return;
	}
	func_ov031_02224ca4(data_ov031_02250bfc->field11d, 4, 0xaa);
	func_ov031_0222506c();
	func_ov031_0223e2b8(obj, (int)RunFourStagesA_022242d4);
}
