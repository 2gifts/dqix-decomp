#include <globaldefs.h>

void* GetField6b0_021b8470(void* obj);

struct Src021cbe50 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char bytes[8];
};

// JPN: func_ov017_021cc300
// USA: func_ov017_021cbe50
ARM void CopySrcBytesToWordArrayIfFieldMatch_021cbe50(int unused0, Src021cbe50* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* h = *(void**)(obj + 0x3000 + regionalOffset0);
	void* r = GetField6b0_021b8470(h);
	if (!r) return;

	void* ptr2 = *(void**)((char*)r + 0x8000 + 0xe18);
	unsigned short cmpVal = *(unsigned short*)((char*)ptr2 + 0x8);
	if (src->field4 != cmpVal) return;

	unsigned char* p = src->bytes;
	int i;
	for (i = 0; i < 8; p++) {
		unsigned int* dst = (unsigned int*)((char*)r + 0x8000 + 0xde0 + i * 4);
		*dst = *p;
		i++;
	}
}
