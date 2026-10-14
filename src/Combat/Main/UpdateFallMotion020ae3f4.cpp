#include <globaldefs.h>
#include "System/Matrix.h"

struct Obj020ae3f4 {
    char pad0[0x44];
    Vector3i position;
    char pad1[0x140 - 0x50];
    int counter;
    char pad2[0x168 - 0x144];
    int field168;
    char pad3[0x178 - 0x16c];
    int field178;
};

// USA: func_020ae3f4
ARM void UpdateFallMotion020ae3f4(struct Obj020ae3f4* obj) {
    int count = obj->counter + 1;
    obj->counter = count;
    int factor = count * count;
    Vector3i localVec;
    localVec = obj->position;
    localVec.y += (int)(((float)factor * 0.005f) * 4096.0f);
    obj->position = localVec;
    obj->field168 += (int)(((float)factor * 0.005f) * 4096.0f);
    obj->field178 += (int)(((float)factor * 0.005f) * 4096.0f);
}
