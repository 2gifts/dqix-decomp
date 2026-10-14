#include <globaldefs.h>
#include "World/Object3D.h"

struct Shorts5c_374e0;

struct FieldsA020408c8 {
    char pad1c[0x1c];
    int a;
    int b;
    int c;
};
struct Node020408c8 {
    char pad[0x14];
    struct FieldsA020408c8* f14;
    void* f18;
    void* f1c;
};

// USA: func_020408c8
ARM void SetActiveChildShorts020408c8(struct Node020408c8* obj, short a, short b, short c) {
    struct FieldsA020408c8* p = obj->f14;
    if (p != NULL) {
        p->a = a;
        p->b = b;
        p->c = c;
        return;
    }
    if (obj->f18 != NULL) {
        ((Object3D*)((struct Shorts5c_374e0*)obj->f18))->SetScale(a, b, c);
        return;
    }
    if (obj->f1c != NULL) {
        ((Object3D*)((struct Shorts5c_374e0*)obj->f1c))->SetScale(a, b, c);
    }
}
