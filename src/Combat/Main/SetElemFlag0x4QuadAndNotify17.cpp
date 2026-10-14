#include <globaldefs.h>

bool IsFieldAEqual4020ae4c8();
extern "C" void* func_02012fe4(void);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

struct Obj0201b600;
struct Elem0201b600 { unsigned short key; unsigned short flags; };
struct Elem0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);

// USA: func_020ae880
ARM void SetElemFlag0x4QuadAndNotify17(int mode) {
    struct Obj0201b600* obj = (struct Obj0201b600*)func_02012fe4();
    if (*(unsigned short*)obj != 0x232f) return;

    struct Elem0201b600* elem5 = FindElemByKeys(obj, 0, 5);
    struct Elem0201b600* elem3 = FindElemByKeys(obj, 0, 3);
    struct Elem0201b600* elemF = FindElemByKeys(obj, 0, 0xf);
    struct Elem0201b600* elem11 = FindElemByKeys(obj, 0, 0x11);
    if (elem5 == 0 || elem3 == 0 || elemF == 0 || elem11 == 0) return;

    if (!IsFieldAEqual4020ae4c8()) {
        if (mode == 0) {
            elem3->flags &= ~0x4;
            elem11->flags &= ~0x4;
            elemF->flags |= 0x4;
            elem5->flags |= 0x4;
        } else {
            elem3->flags |= 0x4;
            elem11->flags |= 0x4;
            elemF->flags &= ~0x4;
            elem5->flags &= ~0x4;
        }
    }
    SetFlagBitAndNotifyOverlay17(0xc, mode != 0 ? 1 : 0);
}
