#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj020d7b04;
#if defined(jpn)
enum { QueueStride = 0x50, ListOffset = 0x34ec, ActiveOffset = 0x868, StateOffset = 0x17e2 };
struct QueueBlockFlags { unsigned char low : 2; unsigned char blocked : 1; unsigned char high : 5; };
#define QUEUE_BLOCKED(p) (((QueueBlockFlags*)((p) + 0x17ff))->blocked)
extern "C" void func_02045d88(void*, void*, int);
#else
enum { QueueStride = 0x70, ListOffset = 0x36fc, ActiveOffset = 0x998, StateOffset = 0x19b2 };
#define QUEUE_BLOCKED(p) ((p)[0x19d0])
#endif

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21GetEffectiveDeltaTimeEv(void* self);
extern "C" int _Z17GetGlobal02109400v();
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" int _Z18AlwaysTrue02094b4cv(int a);
extern "C" void* func_ov017_0218b5b0();
extern "C" int _Z14ListContainsIdP16ListHead02046b60i(void* list, int id);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);
extern "C" void _Z21BlankFunction02094b3cv(int a, int b);
extern "C" void _Z21BlankFunction02094b30v(int a, int b, int c);
extern "C" void func_02046380(void* p);
extern "C" void func_0204500c(void* p, void* a, int b, int c);
extern "C" void _Z18InitFields02042b3cPv(void* p);
extern "C" void func_02094ab0(int a);
extern "C" void _Z24ReinitController02043204Pc(char* p);

extern char data_020f2348[];

struct Flags020d7b04 {
    unsigned char lo : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct Obj020d7b04 {
    signed char f0;
#if defined(jpn)
    unsigned char pad01[0x4e];
    struct { unsigned char lo : 7; unsigned char bit7 : 1; } b6f;
#else
    unsigned char pad01[0x6e];
    struct Flags020d7b04 b6f;
#endif
    unsigned char pad70[0x80];
#if defined(jpn)
    unsigned char padF0[0x20];
#else
    unsigned char padF0[0x60];
#endif
    struct Flags020d7b04 flags;
    unsigned char pad151;
    unsigned short field152;
};

// USA: func_020d7b04
// JPN: func_020d7b04
extern "C" ARM void func_020d7b04(struct Obj020d7b04* obj) {
    char buf[0xc8];
    void* gs = _ZN9GameState11GetInstanceEv();
    int g = _Z17GetGlobal02109400v();
    unsigned char* g1c = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
    void* list;
    unsigned short dt;
    int ok;

    if (obj->flags.bit7) {
        if (_Z18AlwaysTrue02094b4cv(g) == 0) goto END;
    }

    list = *(void**)((char*)func_ov017_0218b5b0() + ListOffset);
    if (_Z14ListContainsIdP16ListHead02046b60i(list, 0x25) != 0) goto END;
    if (_Z14ListContainsIdP16ListHead02046b60i(list, 0x26) != 0) goto END;

    dt = (unsigned short)_ZNK9GameState21GetEffectiveDeltaTimeEv(gs);

    if (obj->field152 == 0) goto L2;
    if (dt < obj->field152) {
        obj->field152 = obj->field152 - dt;
        goto END;
    }
    if (QUEUE_BLOCKED(g1c) != 0) goto END;
    obj->field152 = 0;
    if (obj->flags.lo == 0) goto END;
    memcpy(obj, (char*)obj + QueueStride, QueueStride);
    memcpy((char*)obj + QueueStride, (char*)obj + 2 * QueueStride, QueueStride);
    obj->flags.lo = (unsigned char)(obj->flags.lo + 0xff);
    if (obj->flags.lo != 0) goto END;
    func_ov016_0218b5c0(1, -1);
    func_ov017_0218b5f8(-1);
    goto END;

L2:
    if (QUEUE_BLOCKED(g1c) != 0) goto END;
    if (obj->flags.lo == 0) goto L3;
    if (obj->b6f.lo == 0) goto L4;
    ok = 1;
    if (obj->b6f.bit7) {
        ok = _Z14ListContainsIdP16ListHead02046b60i(list, 0xc) == 0;
    }
    if (ok == 0) goto L4;
    _Z21BlankFunction02094b3cv(g, 0xa);
    _Z21BlankFunction02094b30v(g, 0x1f9, 0);
    obj->b6f.lo = 0;
    obj->flags.bit7 = 1;
    goto END;

L4:
    sprintf(buf, data_020f2348, obj);
    if (obj->flags.lo > 1) {
        obj->field152 = 0x3e8;
    } else {
        obj->field152 = 0xbb8;
    }
    if (obj->f0 != 0) {
#if defined(jpn)
        func_02045d88(g1c, buf, 0);
#else
        func_02046380(g1c);
        if (obj->b6f.bit6) {
            func_0204500c(g1c, buf, 0, 0xe3);
        } else {
            func_0204500c(g1c, buf, 0, 0x100);
        }
#endif
        _Z18InitFields02042b3cPv(g1c);
        *(int*)(g1c + ActiveOffset) = 1;
        *(unsigned char*)(g1c + StateOffset) = 1;
        obj->flags.bit6 = 1;
        goto END;
    }
    obj->flags.bit6 = 0;
    obj->field152 = 0;
    obj->flags.lo = 0;
    goto END;

L3:
    if (obj->flags.bit7) {
        func_02094ab0(g);
        obj->flags.bit7 = 0;
    }
    if (obj->flags.bit6) {
        _Z24ReinitController02043204Pc((char*)_Z26GetGlobalField0x1c020421a0v());
        obj->flags.bit6 = 0;
    }
    obj->field152 = 0;
    obj->flags.lo = 0;

END:
    return;
}
