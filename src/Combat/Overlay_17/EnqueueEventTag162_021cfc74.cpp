#include <globaldefs.h>

extern "C" void func_0202ae18(void);
extern "C" int func_0202c540(void);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cfc74 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned char field4;
	unsigned char pad1[15];
};

// USA: func_ov017_021cfc74
ARM void EnqueueEventTag162_021cfc74(unsigned char a) {
	func_0202ae18();
	if (func_0202c540() == 0) {
		LocalEvt021cfc74 buf;
		void* p = GetData02100044_0202ae24();
		buf.tag = 0xa2;
		buf.field4 = a;
		func_0205e330(p, &buf, 0);
	}
}
