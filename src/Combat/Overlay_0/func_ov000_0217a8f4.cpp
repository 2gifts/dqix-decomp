#include <globaldefs.h>

struct ElemSlot {
    char pad0[0xac];
    short x;
    short y;
    char padb0[0xc4 - 0xb0];
    unsigned char key;
    char padc5[0xe0 - 0xc5];
};

struct Struct_0205d81c {
    char pad0[0xfc];
    ElemSlot slots[7];
};

struct Element02161318 {
    char pad0[0x44];
    int posX;
    int posY;
};

struct Obj0217a8f4 {
    char pad0[0x17c];
    int elementId;
    char pad180[0x188 - 0x180];
    Struct_0205d81c elems;
};

struct SlotOffset {
    short key;
    short x;
    short y;
};

struct SlotLink {
    unsigned char a;
    unsigned char b;
};

extern SlotOffset data_ov000_02183548[];
extern SlotLink data_ov000_021834d4[];

extern "C" Element02161318* func_ov000_02161318(Obj0217a8f4* obj, int id);
extern "C" void func_ov000_02176210(Struct_0205d81c* elems, int keyA, int keyB);
extern "C" void _Z23ApplyElemFields0205d904Ph(unsigned char* obj);

// USA: func_ov000_0217a8f4
extern "C" ARM void func_ov000_0217a8f4(Obj0217a8f4* obj) {
    Element02161318* e = func_ov000_02161318(obj, obj->elementId);
    if (e == 0) {
        return;
    }
    int posX = e->posX;
    int posY = e->posY;
    ElemSlot* slot;
    int i;
    for (i = 0; i < 7; i++) {
        slot = &obj->elems.slots[i];
        int key = slot->key;
        int j;
        for (j = 0; data_ov000_02183548[j].key > 0; j++) {
            if (key == data_ov000_02183548[j].key) {
                slot->x = data_ov000_02183548[j].x + (posX >> 3);
                slot->y = data_ov000_02183548[j].y + (posY >> 3);
                break;
            }
        }
    }
#if defined(jpn)
    func_ov000_02176210(&obj->elems, 7, 33);
    func_ov000_02176210(&obj->elems, 15, 34);
    func_ov000_02176210(&obj->elems, 16, 35);
    func_ov000_02176210(&obj->elems, 17, 36);
    func_ov000_02176210(&obj->elems, 21, 22);

#else
    SlotLink* link = data_ov000_021834d4;
    while (true) {
        if (link->a == 0xff) {
            break;
        }
        func_ov000_02176210(&obj->elems, link->a, link->b);
        link++;
    }

#endif
    _Z23ApplyElemFields0205d904Ph((unsigned char*)&obj->elems);
}
