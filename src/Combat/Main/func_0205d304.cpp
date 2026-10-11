#include <globaldefs.h>

struct Vec2 { short x; short y; };

struct Struct_0205d81c;
struct Struct_0205bf3c;
struct Obj5d594;
struct ScaledElementList0204aa28;

extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c*, int);
extern "C" void _Z24CopyOrClearField0204c770PcPv(char*, void*);
void GetNibbles(struct Obj5d594*, unsigned char*, unsigned char*);
extern "C" void func_0204c980(void* self, int flag, int value, int r8, int r7, unsigned char a6, unsigned char a8);
int GetScaledElementPtr(struct ScaledElementList0204aa28*);
extern "C" void _Z18ResetState0205bf3cP15Struct_0205bf3c(struct Struct_0205bf3c*);
extern "C" void _Z23ApplyElemFields0205d904Ph(unsigned char*);

struct Elem0205d304 {
    char pad0[0x4];
    void* p4;
    char pad8[0x98];
    int a0;
    int a4;
    struct Vec2 s8[4];
    char padb8[0xa];
    short c2;
    unsigned char c4;
    unsigned char flags;
    char padc6;
    unsigned char c7;
    char padc8[0x18];
};

struct Ctx0205d304 {
    char pad0[0x54];
    char resetState[0x44];
    void* list98;
    struct Elem0205d304* list9c;
    struct Vec2 a0[4];
    unsigned char b0;
    unsigned char b1;
    char padb2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
};

// USA: func_0205d304
extern "C" ARM void func_0205d304(struct Ctx0205d304* obj, int flag, int r8arg, int r7arg,
                                       unsigned char a5, unsigned char a6, void* a7, unsigned char a8) {
    struct Elem0205d304* elem;
    struct Elem0205d304* e;
    unsigned char lowA, highA, lowB, highB;
    int matched;
    int j;
    unsigned char i;
    int value;
    int off;
    short tx;
    short ty;

    if (flag == 0 || obj->list98 == NULL || obj->list9c == NULL) return;
    if (obj->b3 <= obj->b4) return;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)obj, obj->b1) != 0) return;

    elem = &obj->list9c[obj->b4];
    ty = obj->a0[0].y;
    tx = obj->a0[0].x;
    elem->s8[0].x = tx;
    elem->s8[0].y = ty;
    ty = obj->a0[1].y;
    tx = obj->a0[1].x;
    elem->s8[1].x = tx;
    elem->s8[1].y = ty;
    ty = obj->a0[2].y;
    tx = obj->a0[2].x;
    elem->s8[2].x = tx;
    elem->s8[2].y = ty;
    ty = obj->a0[3].y;
    tx = obj->a0[3].x;
    elem->s8[3].x = tx;
    elem->s8[3].y = ty;
    if (a5) {
        elem->flags |= 8;
    } else {
        elem->flags &= ~8;
    }
    elem->c4 = obj->b1;
    if (obj->b5) {
        elem->flags |= 4;
    } else {
        elem->flags &= ~4;
    }
    if (obj->b6) {
        elem->flags |= 0x10;
    } else {
        elem->flags &= ~0x10;
    }
    elem->c7 = obj->b7;
    _Z24CopyOrClearField0204c770PcPv((char*)elem, a7);

    if (obj->b4 != 0) {
        matched = 0;
        GetNibbles((struct Obj5d594*)elem->p4, &lowA, &highA);
        for (j = obj->b4 - 1; j >= 0; j--) {
            off = j * 0xe0;
            e = (struct Elem0205d304*)((char*)obj->list9c + off);
            GetNibbles((struct Obj5d594*)e->p4, &lowB, &highB);
            if (lowA == lowB && highA == highB) {
                e = (struct Elem0205d304*)((char*)obj->list9c + off);
                value = e->a0 + e->a4;
                func_0204c980(elem, flag, value, r8arg, r7arg, a6, a8);
                matched = 1;
                break;
            }
        }
        if (!matched) {
            value = GetScaledElementPtr((struct ScaledElementList0204aa28*)elem->p4);
            func_0204c980(elem, flag, value, r8arg, r7arg, a6, a8);
        }
        elem->flags &= ~0x20;
        for (i = 0; i < obj->b4; i++) {
            e = &obj->list9c[i];
            e->c2 = 1;
        }
    } else {
        value = GetScaledElementPtr((struct ScaledElementList0204aa28*)elem->p4);
        func_0204c980(elem, flag, value, r8arg, r7arg, a6, a8);
        elem->flags &= ~0x20;
    }

    obj->b4++;
    _Z18ResetState0205bf3cP15Struct_0205bf3c((struct Struct_0205bf3c*)obj->resetState);
    obj->b0 = obj->b1;
    _Z23ApplyElemFields0205d904Ph((unsigned char*)obj);
}
