#include <globaldefs.h>
#include "World/Object3D.h"

struct S02037418;
struct ClampTarget_0203fc84;
void ClampValueAndStoreAt0x2c(struct ClampTarget_0203fc84* obj, int value);

struct Entry_02164908 {
    int type;
    char pad[8];
    void* field0xc;
};

struct Sub_02164908 {
    char pad[0x14];
    void* field0x14;
    void* field0x18;
};

// USA: func_ov001_02164908  (semantic: DispatchEntryByType_02164908)
extern "C" ARM int func_ov001_02164908(struct Entry_02164908* arr, int idx, int val) {
    struct Entry_02164908* e;
    void* p;
    void* q;
    if (idx < 0 || idx >= 0x20) return 0;
    e = &arr[idx];
    switch (e->type) {
    case 0:
    case 1:
    case 4:
    case 5:
        p = e->field0xc;
        if (p == 0) return 0;
        ((Object3D*)((struct S02037418*)p))->SetInheritedAlpha(val);
        return 1;
    case 6:
        p = e->field0xc;
        if (p == 0) return 0;
        q = ((struct Sub_02164908*)p)->field0x18;
        if (q == 0) return 0;
        ((Object3D*)((struct S02037418*)q))->SetInheritedAlpha(val);
        return 1;
    case 2:
        p = e->field0xc;
        if (p == 0) return 0;
        q = ((struct Sub_02164908*)p)->field0x14;
        if (q == 0) return 0;
        ClampValueAndStoreAt0x2c((struct ClampTarget_0203fc84*)q, val);
    default:
        return 0;
    }
}
