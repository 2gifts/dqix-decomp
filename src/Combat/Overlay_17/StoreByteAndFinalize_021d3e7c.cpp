#include <globaldefs.h>

#if defined(jpn)
enum { kFinalizeBaseOffset = 0x1860 };
#else
enum { kFinalizeBaseOffset = 0x1840 };
#endif


#if defined(jpn)
#define StoreByteAndFinalize_021d3e7c func_ov017_021d42cc
#endif

extern "C" int func_0202c540(void* p);
extern "C" void* func_02012fe4(void);
void SetByteIfDataAndCheckClear_021a01bc(unsigned char* self);

// USA: func_ov017_021d3e7c
#if defined(jpn)
extern "C"
#endif
ARM void StoreByteAndFinalize_021d3e7c(void* a, unsigned char* b, int c, unsigned char* d, void* e) {
	if (func_0202c540(e) == 0) return;
	int p = (int)func_02012fe4();
	unsigned char* base = (unsigned char*)(p + kFinalizeBaseOffset);
	*(int*)(base + 0xb3c) = b[4];
	SetByteIfDataAndCheckClear_021a01bc(d);
}
