#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj0RowEvent {
    char pad0[4];
    unsigned short kind;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    char padc[4];
    int field10;
    char pad14[0xc];
    int field20;
    int field24;
    unsigned char field28;
    unsigned char field29;
};

extern "C" void func_ov023_021f6ed8(void*);
extern "C" void func_ov023_021fd03c(void*, int);

// USA: func_ov023_021fcdd4
ARM int InitEvent14_021fcdd4(struct Obj0RowEvent* obj, int p1, int p2, int p3, int p4, int p5) {
    func_ov023_021f6ed8(obj);
    obj->kind = 0x14;
    obj->field6 = p2;
    obj->field8 = p3;
    obj->fielda = p4;
    obj->field10 = p5;
    ((Object3D*)((char*)obj + 0x20))->Initialize();
    func_ov023_021fd03c(obj, p1);
    return 1;
}
