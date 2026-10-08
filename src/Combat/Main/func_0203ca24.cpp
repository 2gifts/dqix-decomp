#include <globaldefs.h>
#include "std_library_functions.h"

extern signed char data_020efc18;
extern char data_020efd54[];
extern char data_020efd60[];
extern char data_020efd6c[];
extern char data_020efd78[];
extern char data_020efd84[];

extern "C" float _fflt(int v);
extern "C" float _fsub(float a, float b);
extern "C" int _ffix(float v);

extern void ClearIntAt0x23c(unsigned char* obj);
extern int GetField0x70(void* obj);
extern void SetField0x23cTrue(void* obj);
struct Struct0203cedc;
extern void SetCombatFlags0x5c(struct Struct0203cedc* obj, int b, int c);
struct Obj0203f1e4;
extern "C" extern void _Z24SelectNamedEntry0203f1e4P11Obj0203f1e4PKc(struct Obj0203f1e4* obj, const char* name);

struct Obj0203ca24 {
    char pad0[0x4];
    int field4;
    char pad8[0x5c - 0x8];
    int field5c;
    char pad60[0x94 - 0x60];
    unsigned char field94;
    char pad95[0x98 - 0x95];
    int field98;
};

// USA: func_0203ca24
extern "C" ARM void func_0203ca24(struct Obj0203ca24* obj, void* p23c) {
    char buf[20];
    int a;
    int b;
    signed char v;

    ClearIntAt0x23c((unsigned char*)p23c);
    a = GetField0x70(p23c);
    b = _ffix(_fsub(25736.0f, _fflt(1608)));
    memset(buf, 0, 19);

    v = data_020efc18;
    if (v > -1) {
        if (v == 0) {
            goto pathB;
        }
    }
    if (a >= 1608) {
        if (b > a) {
            goto pathC;
        }
    }

pathB:
    if (obj->field98 > obj->field4) {
        memcpy(buf, data_020efd54, 11);
    } else {
        memcpy(buf, data_020efd60, 11);
    }
    data_020efc18 = 0;
    goto tail;

pathC:
    if (v > -1) {
        if (v == 1) {
            goto path1;
        }
    }
    if (a >= 12868) {
        goto path2;
    }

path1:
    memcpy(buf, data_020efd6c, 11);
    data_020efc18 = 1;
    goto tail;

path2:
    memcpy(buf, data_020efd78, 11);
    data_020efc18 = 2;

tail:
    if (obj->field5c & 0x20) {
        memcpy((char*)buf + 11, data_020efd84, 7);
        buf[19] = 0;
        obj->field94--;
        if (obj->field94 == 0) {
            SetCombatFlags0x5c((struct Struct0203cedc*)obj, 0, 0);
            obj->field94 = 0xf;
            SetField0x23cTrue(p23c);
            data_020efc18 = -1;
        }
    }

    _Z24SelectNamedEntry0203f1e4P11Obj0203f1e4PKc((struct Obj0203f1e4*)obj, buf);
}