#include <globaldefs.h>

struct Sub150_021612ac { unsigned char pad[0x56b]; unsigned char field56b : 4; };

// USA: func_ov001_021612ac
ARM int GetNibbleAt56b(void* p) {
#if defined(jpn)
    enum { regionalFieldOffset = 0x144 };
#else
    enum { regionalFieldOffset = 0x150 };
#endif
	struct Sub150_021612ac* q = *(struct Sub150_021612ac**)((char*)p + regionalFieldOffset);
	if (!q) return 0;
	return q->field56b;
}
