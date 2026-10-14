#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c8c04 {
	unsigned char tag;
	unsigned char pad0[3];
	int field4;
	unsigned short field8;
	unsigned char fielda;
	unsigned char pad2[9];
};

// USA: func_ov017_021c8c04
ARM void EnqueueEventTag83_021c8c04(int a, int b, int c) {
	LocalEvt021c8c04 buf;
	void* p = GetData02100044();
	buf.tag = 0x53;
	buf.field8 = a;
	buf.fielda = b;
	buf.field4 = c;
	func_0205e330(p, &buf, 0);
}
