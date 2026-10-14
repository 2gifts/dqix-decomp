#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021ce014 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned char pad1[10];
};

// USA: func_ov017_021ce014
ARM void EnqueueEventTag17_021ce014(int unused, unsigned short b, unsigned short c, unsigned short d) {
	LocalEvt021ce014 buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x11;
	buf.field4 = b;
	buf.field6 = c;
	buf.field8 = d;
	func_0205e330(p, &buf, 0);
}
