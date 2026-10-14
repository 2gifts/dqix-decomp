#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cf594 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char field6;
	unsigned char field7;
	unsigned char pad1[12];
};

// USA: func_ov017_021cf594
ARM void EnqueueEventTag58_021cf594(unsigned short a, int b, int c) {
	LocalEvt021cf594 buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x3a;
	buf.field4 = a;
	buf.field6 = b;
	buf.field7 = c;
	func_0205e330(p, &buf, 0);
}
