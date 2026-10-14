#include <globaldefs.h>
#include "System/Memory.h"

extern void* (*data_ov031_0224c994)(unsigned int);
extern int (*data_ov031_0224c9c0)(void*);

extern "C" void func_ov031_02209158(void* obj, void* out, int mode);
extern "C" void func_ov031_02209234(void* obj, void* out, int mode);
void InitTwoSections_022098ac(void* base, int b, int c);
extern "C" void* func_ov031_0220963c(void* ctx, void* data);
extern "C" void func_ov031_022037a8(void* a, void* b, int c, int d, void* e);

// USA: func_ov031_02209e98
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02209e98(void* self) {
	void* ctx = *(void**)((char*)self + 0xc);
	unsigned char* buf = (unsigned char*)data_ov031_0224c994(0x83);
	if (buf == NULL) {
		*(unsigned char*)((char*)ctx + 0x455) = 9;
		return 9;
	}

	buf[0] = 0x14;
	buf[1] = 0x3;
	buf[2] = 0;
	buf[3] = 0;
	buf[4] = 1;
	buf[5] = 1;
	VectorizedMemset((char*)ctx + 0x1cc, 0, 8);
	buf[6] = 0x16;
	buf[7] = 0x3;
	buf[8] = 0;
	buf[9] = 0;
	buf[0xa] = 0x28;
	buf[0xb] = 0x14;
	buf[0xc] = 0;
	buf[0xd] = 0;
	buf[0xe] = 0x24;
	VectorizedInvertedMemcpy((char*)ctx + 0x3a4, (char*)ctx + 0x3fc, 0x58);

	func_ov031_02209158(ctx, buf + 0xf, 0);
	VectorizedInvertedMemcpy((char*)ctx + 0x3fc, (char*)ctx + 0x3a4, 0x58);
	VectorizedInvertedMemcpy((char*)ctx + 0x2ec, (char*)ctx + 0x348, 0x5c);

	func_ov031_02209234(ctx, buf + 0x1f, 0);
	VectorizedInvertedMemcpy((char*)ctx + 0x348, (char*)ctx + 0x2ec, 0x5c);

	InitTwoSections_022098ac(ctx, (int)(buf + 0xb), 0x28);

	void* r = func_ov031_0220963c(ctx, buf + 0x6);
	func_ov031_022037a8(buf, (char*)r + 0x6, 0, 0, self);

	return data_ov031_0224c9c0(buf);
}
