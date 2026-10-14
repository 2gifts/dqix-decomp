#include <globaldefs.h>

bool IsFieldAEqual4020ae4c8();
extern "C" void* func_02012fe4(void);

struct Obj0201b600;
struct Elem0201b600 { unsigned short key; unsigned short flags; };
struct Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);

// USA: func_020ae694
ARM void SetOrClearElemFlag0x4ByKeys_020ae694(int mode, int key1, unsigned short key2) {
    struct Elem0201b600* elem;
    if (key2 == 0) return;
    if (IsFieldAEqual4020ae4c8()) return;
    elem = FindElemByKeys((struct Obj0201b600*)func_02012fe4(), key1, key2);
    if (elem == 0) return;
    if (mode == 0) {
        elem->flags |= 0x4;
    } else {
        elem->flags &= ~0x4;
    }
}
