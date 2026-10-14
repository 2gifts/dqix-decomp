#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#if defined(jpn)
#define data_020ee950 data_020eea14
#endif

struct HasDims020e1288;
int GetHalfProductField8(struct HasDims020e1288* obj);

extern VRAMSubregion data_020ee950[];

struct F3fFlags020e23f4 { unsigned char bit0 : 1; };

struct StreamDims020e23f4 {
    char pad0[0x30];
    int f30;
    int f34;
    char pad1[0x6];
    unsigned char f3e;
    unsigned char f3f;
};

struct Obj020e23f4 {
    unsigned char* field0;
    struct StreamDims020e23f4* field4;
};

// USA: func_020e23f4  (semantic: EncodeIfValid020e23f4)
extern "C" ARM void func_020e23f4(struct Obj020e23f4* obj) {
    struct StreamDims020e23f4* dims = obj->field4;
    if (dims == 0 || obj->field0 == 0) return;
    ((struct F3fFlags020e23f4*)&dims->f3f)->bit0 = 1;
    dims = obj->field4;
    int f30 = dims->f30;
    int half = GetHalfProductField8((struct HasDims020e1288*)dims);
    StageMemoryToVRAM(
        data_020ee950[dims->f3e],
        obj->field0 + f30,
        f30,
        dims->f34 + half,
        true, false);
}
