#include <globaldefs.h>

char* GetOffset400_02235c70(void);
extern "C" void func_020ca408(void* src, void* dst, int size);
void GetFields181c_02227520(int* a, int* b);
extern "C" int func_ov031_02212d40(void* buf);
void CopyBlockToSlot_02213204(int slot, void* src);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02233d84(void* obj);

extern unsigned char data_ov031_022491d8[0xc];

struct Struct02233d84 {
	unsigned char flag0;
	unsigned char pad[3];
	int field4;
};
extern Struct02233d84 data_ov031_02290cd0;

// USA: func_ov031_02233b34  (semantic: RequestCopyAndDispatch_02233b34)
extern "C" ARM void func_ov031_02233b34(void) {
	unsigned char* o = (unsigned char*)GetOffset400_02235c70();
	unsigned char buf[0xc];
	func_020ca408(data_ov031_022491d8, buf, 0xc);

	int b;
	GetFields181c_02227520(0, &b);
	if (b == 2) {
		buf[0xa] = 4;
	} else {
		buf[0xa] = o[0xf4] + 1;
	}

	int r0 = func_ov031_02212d40(buf);
	data_ov031_02290cd0.field4 = r0;
	if (r0 != 0 && b == 0) {
		CopyBlockToSlot_02213204(o[0xf4], o);
	}

	CallWithZeroExtra_0223e218(0, (void*)func_ov031_02233d84, 0, 0x78);
}
