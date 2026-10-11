#include <globaldefs.h>
#if defined(jpn)
enum { kStatusOffset = 0x620 };
enum { kStatusValue = 0 };
#else
enum { kStatusOffset = 0x520 };
enum { kStatusValue = 4 };
#endif

#include "System/DMA.h"

extern "C" int LoadToMainOAM(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToSubOAM(int arg0, int arg1, unsigned int arg2);

extern int data_021052b4;
extern int data_021056b4;

struct Obj0203bdb0 {
    char pad[0xc];
    unsigned char flagA;
    unsigned char flagB;
};

// USA: func_0203bdb0
ARM void SyncMainSubOam0203bdb0(struct Obj0203bdb0* obj) {
    if (obj->flagA != 0) {
        LoadToMainOAM((int)&data_021052b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)&data_021052b4, 0xc0, 0x400);
    }
    if (obj->flagB != 0) {
        LoadToSubOAM((int)&data_021056b4, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)&data_021056b4, 0xc0, 0x400);
    }
    if (obj->flagA != 0 || obj->flagB != 0) {
        *(short*)((char*)obj + kStatusOffset) = kStatusValue;
    }
}
