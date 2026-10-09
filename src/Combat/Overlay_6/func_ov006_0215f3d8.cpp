#include <globaldefs.h>

struct LookupByOffset0x362_021591ecStruct;
extern "C" unsigned short _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct(LookupByOffset0x362_021591ecStruct* s);
extern "C" short _Z26FindMappedMemberId02080468Pvi(void* obj, int id);
extern "C" void func_ov006_0215f4dc(void* obj);
extern "C" void func_ov006_0215f740(void* obj);

struct Struct0215f3d8 {
    unsigned char pad0[0x14];
    void* f14;
    unsigned char pad1[0x350 - 0x18];
    unsigned int input;
    unsigned char pad2[0x364 - 0x354];
    short scroll;
    unsigned char pad3[0x388 - 0x366];
    unsigned char cursor;
    unsigned char count;
    unsigned char pad4[0x394 - 0x38a];
    unsigned short flags;
};

// USA: func_ov006_0215f3d8
extern "C" ARM void func_ov006_0215f3d8(Struct0215f3d8* obj) {
    if ((obj->flags & 4) == 0) {
        return;
    }
    int moved = 0;
    if (obj->input & 0x10) {
        obj->cursor++;
        moved = 1;
    } else if (obj->input & 0x20) {
        obj->cursor--;
        moved = 1;
    }
    if (obj->cursor == 0xff) {
        obj->cursor = obj->count - 1;
    }
    if (obj->count <= obj->cursor) {
        obj->cursor = 0;
    }
    if (moved == 0) {
        return;
    }
    unsigned short total = _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct((LookupByOffset0x362_021591ecStruct*)obj);
    short offset = obj->scroll - _Z26FindMappedMemberId02080468Pvi(obj->f14, 0x11);
    short pos = offset + obj->cursor * 8;
    if (pos >= total) {
        pos = total - 1;
    }
    pos = pos % 8;
    obj->scroll = _Z26FindMappedMemberId02080468Pvi(obj->f14, 0x11) + pos;
    func_ov006_0215f4dc(obj);
    func_ov006_0215f740(obj);
}
