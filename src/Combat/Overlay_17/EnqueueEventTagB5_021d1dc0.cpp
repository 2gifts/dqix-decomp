#include <globaldefs.h>

struct SearchStruct0202c1a4 {
	char pad[0x1038];
	signed char arr[16];
};

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d1dc0 {
	short a;
	short b;
	short c;
	short d;
	short scaledX;
	short scaledY;
	short scaledZ;
};

struct LocalEvt021d1dc0 {
	unsigned char tag;
	unsigned char pad0[3];
	Sub021d1dc0 sub;
	unsigned char pad1[2];
};

// USA: func_ov017_021d1dc0
ARM void EnqueueEventTagB5_021d1dc0(unsigned short a, int b, int* vec3, int c, int d) {
	if (!CheckField0NonZero_0202b7d8(func_0202ae18())) return;
	if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)func_0202ae18()) != 0) return;
	void* p = GetData02100044_0202ae24();

	struct LocalEvt021d1dc0 buf;
	buf.tag = 0xb5;
	buf.sub.a = a;
	buf.sub.b = b;
	buf.sub.c = c;
	buf.sub.d = (short)d;
	buf.sub.scaledX = (short)(vec3[0] >> 7);
	buf.sub.scaledY = (short)(vec3[1] >> 7);
	buf.sub.scaledZ = (short)(vec3[2] >> 7);
	func_0205e330(p, &buf, 0);
}
