#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d440c {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char val;
	unsigned char pad2[15];
};

// USA: func_ov017_021d440c
ARM void EnqueueEventTag60Field_021d440c(int a) {
	LocalEvt021d440c buf;
	void* p = GetData02100044_0202ae24();
	buf.tag = 0x3c;
	buf.val = (unsigned char)a;
	func_0205e330(p, &buf, 0);
}
