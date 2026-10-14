#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cf4b0 {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char a;
	unsigned char b;
	unsigned char pad2[14];
};

// USA: func_ov017_021cf4b0
ARM void EnqueueEventTag57WithAB_021cf4b0(int a, int b) {
	void* p = GetData02100044_0202ae24();
	LocalEvt021cf4b0 buf;
	buf.tag = 0x39;
	buf.a = (unsigned char)a;
	buf.b = (unsigned char)b;
	func_0205e330(p, &buf, 0);
}
