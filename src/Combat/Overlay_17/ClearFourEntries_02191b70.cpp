#include <globaldefs.h>

#if defined(jpn)
enum { kEntryLowOffset = 0x1ec, kEntryHighOffset = 0x4000 };
#else
enum { kEntryLowOffset = 0x9c, kEntryHighOffset = 0x4400 };
#endif


#if defined(jpn)
#define ClearFourEntries_02191b70 func_ov017_02192738
#endif

struct Entry02191b70 { unsigned char b0; unsigned char pad; unsigned short h2; };

// USA: func_ov017_02191b70
#if defined(jpn)
extern "C"
#endif
ARM void ClearFourEntries_02191b70(void* obj) {
	Entry02191b70* p = (Entry02191b70*)((char*)obj + kEntryLowOffset + kEntryHighOffset);
	int i;
	for (i = 0; i < 4; i++) {
		p->b0 = 0;
		p->h2 = 0;
		p++;
	}
}
