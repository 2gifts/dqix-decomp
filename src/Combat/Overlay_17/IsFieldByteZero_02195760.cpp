#include <globaldefs.h>

#if defined(jpn)
#define POINTER_OFFSET 0x16c
#else
#define POINTER_OFFSET 0x41c
#endif
struct S02195760 { char pad[POINTER_OFFSET]; unsigned char* p; };

// JPN: func_ov017_02196328
// USA: func_ov017_02195760  (semantic: IsFieldByteZero_02195760)
extern "C" ARM int func_ov017_02195760(unsigned char* base) {
	S02195760* s = (S02195760*)(base + 0x4000);
	return s->p[0] == 0;
}
