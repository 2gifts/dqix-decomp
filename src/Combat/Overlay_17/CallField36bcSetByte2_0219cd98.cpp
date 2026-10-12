#include <globaldefs.h>

#if defined(jpn)
enum { ACTIVE_FIELD_OFFSET = 0x34ac };
#else
enum { ACTIVE_FIELD_OFFSET = 0x36bc };
#endif


#if defined(jpn)
#define CallField36bcSetByte2_0219cd98 func_ov017_0219d88c
#endif

extern "C" void* func_ov017_0219c6f4(void*);

// USA: func_ov017_0219cd98
#if defined(jpn)
extern "C"
#endif
ARM void CallField36bcSetByte2_0219cd98(void* obj) {
	void* p = *(void**)((char*)obj + ACTIVE_FIELD_OFFSET);
	if (!p) return;
	void* r = func_ov017_0219c6f4(p);
	if (r) *((unsigned char*)r + 0x2) = 1;
}
