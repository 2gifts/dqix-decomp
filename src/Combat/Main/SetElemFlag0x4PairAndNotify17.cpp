#include <globaldefs.h>

bool IsFieldAEqual4020ae4c8();
extern "C" void* func_02012fe4(void);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

struct Obj0201b600;
struct Elem0201b600 { unsigned short key; unsigned short flags; };
struct Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);

// USA: func_020ae7d4
ARM void SetElemFlag0x4PairAndNotify17(int mode) {
    struct Obj0201b600* obj = (struct Obj0201b600*)func_02012fe4();
    if (*(unsigned short*)obj != 0x1bbd) return;

    struct Elem0201b600* elem1 = FindElemByKeys(obj, 0, 0xd);
    struct Elem0201b600* elem2 = FindElemByKeys(obj, 0, 0xf);
    if (elem1 == 0 || elem2 == 0) return;

    if (!IsFieldAEqual4020ae4c8()) {
        if (mode == 0) {
            elem1->flags &= ~0x4;
            elem2->flags |= 0x4;
        } else {
            elem1->flags |= 0x4;
            elem2->flags &= ~0x4;
        }
    }
    SetFlagBitAndNotifyOverlay17(9, mode != 0 ? 1 : 0);
}
