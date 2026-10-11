#include <globaldefs.h>

extern "C" int func_ov017_021b8468(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);

// JPN: func_ov017_021c8ba4
// USA: func_ov017_021c86f4
extern "C" ARM void func_ov017_021c86f4(int unused0, int* param1, int unused2, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    char* out;
    int* src;
    int i;
    unsigned char* table = *(unsigned char**)(base + 0x3000 + regionalOffset0);

	if (!func_ov017_021b8468(table)) {
		return;
	}
	out = (char*)_Z20GetField6b0_021b8470Pv(table);
	if (out == NULL) {
		return;
	}
	src = (int*)((char*)param1 + 4);
	for (i = 0; i < 4; i++) {
		int v = src[i];
		if (v >= 0) {
			int off = (i << 16) >> 14;
			*(int*)(out + off + 0x8e84) = v;
		}
	}
}
