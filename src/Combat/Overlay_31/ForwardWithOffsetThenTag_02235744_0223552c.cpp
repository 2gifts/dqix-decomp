#include <globaldefs.h>

struct Ctx_0223552c {
	unsigned char pad0[0x12];
	unsigned short field12;
	unsigned char pad1[0x19 - 0x14];
	unsigned char field19;
	unsigned char pad2[0x1b - 0x1a];
	unsigned char field1b;
	unsigned char pad3[0x1d - 0x1c];
	unsigned char field1d;
};
extern Ctx_0223552c* data_ov031_02290cf4;
extern unsigned char data_ov031_022491f4[];

struct Pair_0223552c { unsigned short a; unsigned short b; };
extern "C" int func_ov031_0223d69c(void*);
ARM void ForwardWithOffsetThenTag_02235744(int);

// USA: func_ov031_0223552c  (semantic: ComputeAndForwardOffsetTag_0223552c)
extern "C" ARM void func_ov031_0223552c(void) {
	struct Pair_0223552c buf;
	func_ov031_0223d69c(&buf);
	Ctx_0223552c* ctx = data_ov031_02290cf4;
	unsigned int t = data_ov031_022491f4[ctx->field1b];
	int v = buf.b - ctx->field12;
	v -= t >> 1;
	if (v < 0) {
		v = 0;
	} else {
		int lim = ctx->field19 - t;
		if (v >= lim) v = lim;
	}
	ForwardWithOffsetThenTag_02235744(v);
	data_ov031_02290cf4->field1d = 3;
}
