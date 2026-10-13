#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
ARM int CallTailCallThenBdb0_0223be44(int a, int b);
ARM void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02223b60(void);

struct Target02223a64 {
	int field0;
	unsigned short field4;
};

struct Handle02223a64 {
	Target02223a64* field0;
	int field4;
	signed char field8;
};

extern Handle02223a64* data_ov031_02250bf8;
extern unsigned char data_ov031_022489a4[];

// USA: func_ov031_02223a64  (semantic: InitHandleOnce_02223a64)
extern "C" ARM void func_ov031_02223a64(int index) {
	if (data_ov031_02250bf8 != 0) {
		return;
	}
	Handle02223a64* h = (Handle02223a64*)func_ov031_0223cf4c(0xc, 4);
	unsigned char v = *(unsigned char*)&data_ov031_022489a4[index * 4];
	data_ov031_02250bf8 = h;
	h->field8 = (signed char)index;
	int r = CallTailCallThenBdb0_0223be44(0, v);

	h = data_ov031_02250bf8;
	h->field0 = (Target02223a64*)r;

	h = data_ov031_02250bf8;
	Target02223a64* c = h->field0;
	c->field0 = (c->field0 & 0xfe00ff00) | 0x26 | 0xe50000;

	h = data_ov031_02250bf8;
	c = h->field0;
	c->field4 = (c->field4 & ~0xc00) | 0x800;

	void* rr = CallWithZeroExtra_0223e218(0, (void*)func_ov031_02223b60, 0, 0x78);
	h = data_ov031_02250bf8;
	h->field4 = (int)rr;
}
