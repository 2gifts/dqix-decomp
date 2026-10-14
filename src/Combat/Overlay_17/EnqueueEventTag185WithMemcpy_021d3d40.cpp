#include <globaldefs.h>
#include "System/Memory.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021d3d40  (semantic: EnqueueEventTag185WithMemcpy_021d3d40)
extern "C" ARM void func_ov017_021d3d40(const void* a0, int a1, int a2, int a3, int a4) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	unsigned char* q = buf + 4;
	unsigned char packed = *(unsigned char*)(q + 0xd);
	packed = (packed & ~0x70) | ((a3 & 0x7) << 4);
	buf[0] = 0xb9;
	packed = (packed & ~0x80) | ((a2 & 1) << 7);
	packed = (packed & ~0xf) | (a1 & 0xf);
	*(unsigned char*)(q + 0xd) = packed;
	*(short*)(q + 0xe) = (short)a4;
	VectorizedInvertedMemcpy(a0, q, a1);
	func_0205e330(p, buf, 0);
}
