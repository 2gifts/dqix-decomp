#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d23bc {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned char pad1[14];
};

// USA: func_ov017_021d23bc
ARM void EnqueueEventTag158_021d23bc(unsigned short a) {
	LocalEvt021d23bc buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x9e;
	buf.field4 = a;
	func_0205e330(p, &buf, 0);
}
