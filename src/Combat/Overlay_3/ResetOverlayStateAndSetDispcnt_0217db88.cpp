#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue94_90 = 0x90 };
enum { kRegionValue98_94 = 0x94 };
enum { kRegionValue38_34 = 0x34 };
enum { kRegionValueA4_A0 = 0xa0 };
enum { kRegionValueB8_B4 = 0xb4 };
enum { kRegionValue3C_38 = 0x38 };
enum { kRegionValueCC_C8 = 0xc8 };
#else
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue94_90 = 0x94 };
enum { kRegionValue98_94 = 0x98 };
enum { kRegionValue38_34 = 0x38 };
enum { kRegionValueA4_A0 = 0xa4 };
enum { kRegionValueB8_B4 = 0xb8 };
enum { kRegionValue3C_38 = 0x3c };
enum { kRegionValueCC_C8 = 0xcc };
#endif


extern "C" void func_0205d048(void* obj);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);
struct ClearTarget0205a244;
void ClearField0And40205a244(struct ClearTarget0205a244* target);
void EmptyDestructor0205a494(void* obj);
struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40* p);

// USA: func_ov003_0217db88  (semantic: ResetOverlayStateAndSetDispcnt_0217db88)
// JPN: func_ov003_0217c828
extern "C" ARM void func_ov003_0217db88(void* obj) {
    unsigned char* o = (unsigned char*)obj;

    func_0205d048(*(void**)(o + kRegionValue90_8C));

    int i;
    for (i = 0; i < 2; i++) {
        ResetRecordList0204afb4((struct List0204afb4*)(*(char**)(o + kRegionValue94_90) + i * 0x20));
    }

    int j;
    for (j = 0; j < 1; j++) {
        ResetObject0204c754((struct Obj0204c754*)(*(char**)(o + kRegionValue98_94) + j * 0xe0));
    }

    ClearField0And40205a244((struct ClearTarget0205a244*)(*(void**)(o + kRegionValue38_34)));

    if (((SafeAllocator*)(o + kRegionValueA4_A0))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + kRegionValueA4_A0))->Destroy();
    }
    if (((SafeAllocator*)(o + kRegionValueB8_B4))->GetSignedAllocator() != NULL) {
        ((SafeAllocator*)(o + kRegionValueB8_B4))->Destroy();
    }
    EmptyDestructor0205a494(o + kRegionValue3C_38);
    ResetAndDetach020dfc6c((struct Struct020dfc40*)(o + kRegionValueCC_C8));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | ((unsigned int)*(int*)o << 8);
}
