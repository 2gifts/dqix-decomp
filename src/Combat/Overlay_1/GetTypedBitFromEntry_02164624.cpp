#include <globaldefs.h>
#include "World/Object3D.h"

struct BitFlags02037170;

struct Entry0x10_02164624 { int type; char pad[8]; void* fieldC; };

// USA: func_ov001_02164624  (semantic: GetTypedBitFromEntry_02164624)
extern "C" ARM int func_ov001_02164624(Entry0x10_02164624* arr, int idx) {
    if (idx < 0 || idx >= 0x20) return 0;
    Entry0x10_02164624* e = arr + idx;
    switch (e->type) {
        case 0: case 1: case 4: case 5: {
            void* field = e->fieldC;
            if (field == NULL) return 0;
            return ((Object3D*)((struct BitFlags02037170*)field))->HasAnimationStopped();
        }
        case 6: {
            void* field = e->fieldC;
            if (field == NULL) return 0;
            void* field2 = *(void**)((char*)field + 0x18);
            if (field2 == NULL) return 0;
            return ((Object3D*)((struct BitFlags02037170*)field2))->HasAnimationStopped();
        }
        default:
            return 0;
    }
}
