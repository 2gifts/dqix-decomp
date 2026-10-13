#include <globaldefs.h>

#if defined(jpn)
#define SetHalfFields__021d1c84_021d1c84 func_ov017_021d2108
#endif

enum {
#if defined(jpn)
    kSaveHalfwordOffset = 0x27f4, kSaveSecondHalfwordOffset = 0x27f6
#else
    kSaveHalfwordOffset = 0x27b4, kSaveSecondHalfwordOffset = 0x27b6
#endif
};

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void* func_02012fe4(void);

struct Obj_021d1c84 { unsigned char pad[4]; unsigned char field4; unsigned char field5; };

// USA: func_ov017_021d1c84
#if defined(jpn)
extern "C"
#endif
ARM void SetHalfFields__021d1c84_021d1c84(int unused0, Obj_021d1c84* obj, int unused1, int unused2, struct SearchStruct0202c1a4* search) {
	if (GetSearchStructCurrentArrEntry(search) == 0) return;
	unsigned char* base = (unsigned char*)func_02012fe4();
	*(unsigned short*)(base + kSaveHalfwordOffset) = obj->field4;
	*(unsigned short*)(base + kSaveSecondHalfwordOffset) = obj->field5;
}
