#include <globaldefs.h>

struct Inner02222ddc {
	unsigned char pad[0xc];
	int field0xc;
	unsigned char pad2[9];
	unsigned char field19;
};

struct Struct02250ba8 {
	Inner02222ddc *ptr;
};

extern Struct02250ba8 data_ov031_02250ba8;

extern "C" void func_ov031_0222318c(void*);
extern "C" int func_ov031_0223e2b8(int, void*);

// USA: func_ov031_02222ddc
ARM int TailCall_02222ddc(void) {
	Inner02222ddc *p = data_ov031_02250ba8.ptr;
	p->field19 = 1;
	Inner02222ddc *p2 = data_ov031_02250ba8.ptr;
	return func_ov031_0223e2b8(p2->field0xc, (void*)func_ov031_0222318c);
}
