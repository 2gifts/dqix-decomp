#include <globaldefs.h>

#if defined(jpn)
struct S0219a370 { char pad[0xe58]; int count; };
#else
struct S0219a370 { char pad[0x78]; int count; };
#endif

// USA: func_ov017_0219a370
ARM int IsCountAtLeast4_0219a370(unsigned char* base) {
#if defined(jpn)
	S0219a370* s = (S0219a370*)(base + 0x3000);
#else
	S0219a370* s = (S0219a370*)(base + 0x4000);
#endif
	return s->count >= 4;
}
