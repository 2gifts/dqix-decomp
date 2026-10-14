#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc340 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	unsigned char pad1[2];
	unsigned char field9;
	unsigned char pad2[10];
};

// USA: func_ov017_021cc340
ARM void EnqueueEventTag7_021cc340(int a, int b, int c) {
	void* p = GetData02100044_0202ae24();

	LocalEvt021cc340 buf;
	buf.tag = 7;
	buf.field6 = a;
	buf.field9 = b;
	buf.field5 = 1;
	buf.field4 = c;
	func_0205e330(p, &buf, 0);
}
