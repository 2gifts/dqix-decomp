#include <globaldefs.h>
#include "Graphics/LightingManager.h"

struct Obj0201b600;
struct Elem0201b600;
struct Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);
struct Struct02013380;
void SetFlag0x40AndToggle0x4(struct Struct02013380* obj, int unused, int clear4);

struct S4_0201b8c8 { unsigned char v; unsigned char pad[3]; };
extern struct S4_0201b8c8 data_020e6e53[];
extern struct S4_0201b8c8 data_020e6e54[];
extern struct S4_0201b8c8 data_020e6e55[];
extern struct S4_0201b8c8 data_020e6e56[];

// USA: func_0201b8c8
ARM void ApplyElementFlags0201b8c8(struct Obj0201b600* obj, int a1, int a2, int a3) {
    struct Elem0201b600* e;
    int idx;
    int v;
    void* d;
    if (*(unsigned short*)obj != 0x170c) return;
    d = LightingManager::GetInstance();
    e = FindElemByKeys(obj, 0, 0xa);
    if (e != NULL) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, a1);
    e = FindElemByKeys(obj, 0, 0xb);
    if (e != NULL) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, a2);
    v = *(int*)((char*)d + 0x98);
    if (a3 != 0) {
        if (v == 3) idx = 0;
        else idx = 1;
    } else {
        if (v == 3) idx = 2;
        else idx = 3;
    }
    e = FindElemByKeys(obj, 0, 2);
    if (e != NULL) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, data_020e6e53[idx].v);
    e = FindElemByKeys(obj, 0, 0xc);
    if (e != NULL) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, data_020e6e54[idx].v);
    e = FindElemByKeys(obj, 0, 3);
    if (e != NULL) SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, data_020e6e55[idx].v);
    e = FindElemByKeys(obj, 0, 9);
    if (e == NULL) return;
    SetFlag0x40AndToggle0x4((struct Struct02013380*)e, 0, data_020e6e56[idx].v);
}
