#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);
extern "C" struct TaggedValue02030b44* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct TaggedValue02030b44* obj, int* outVec);

struct GameState;
extern "C" struct GameState* _ZN9GameState11GetInstanceEv(void);
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(struct GameState* self);

extern "C" char* func_0205ec34();
int TestBitInByteArray(int, unsigned char*, int);
extern "C" int _Z23TestBitWithBias0206eb98Phi(unsigned char*, int);
extern "C" void _Z26UnlinkNodeByByteId0206dd68Pvi(void*, int);
extern "C" void _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(struct Rec0206bf2c*);
extern "C" void func_0206db48(void*, struct Rec0206bf2c*);

struct Data02108cec {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned short field0xc;
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec data_02108cec;

struct Rec0206bf2c {
    unsigned char field0x0;
    unsigned char pad1;
    unsigned short field0x2;
    unsigned char pad2[0x6];
    unsigned char flags0xa;
    unsigned char pad3[0x10 - 0xb];
    int vec0x10[3];
    short field0x1c;
    unsigned char field0x1e;
    unsigned char pad4[0x44 - 0x1f];
    unsigned short id0x44;
};

// USA: func_0206d4e0
extern "C" ARM int func_0206d4e0(void* param0, int param1) {
    if (param1 < 9) {
        return 0;
    }
    data_02108cec.field0xa++;
    bool even = false;
    if (param1 % 2 == 0) {
        even = true;
    }
    int n;
    int second;
    int half = (even ? param1 - 8 : param1 - 7) / 2;
    char* ctx = func_0205ec34();
    struct Variant02030b0c* arg = (struct Variant02030b0c*)param0;
    for (n = half; n > 0; n--) {
        int packed = _ZNK6Script9Parameter5ToIntEv(arg);
        struct Variant02030b0c* next = (struct Variant02030b0c*)((char*)arg + 8);
        arg = (struct Variant02030b0c*)((char*)arg + 0x10);
        second = _ZNK6Script9Parameter5ToIntEv(next);
        int mode = packed >> 16;
        if (mode == 1) {
            int hit = TestBitInByteArray((int)ctx, (unsigned char*)(ctx + 0x8c), (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else if (mode == 2) {
            int hit = _Z23TestBitWithBias0206eb98Phi((unsigned char*)ctx, (unsigned short)packed);
            if ((second != 0 && hit == 0) || (second == 0 && hit != 0)) {
                return 1;
            }
        } else {
            return 1;
        }
    }

    int kind = _ZNK6Script9Parameter5ToIntEv(arg);
    struct GameState* gs = _ZN9GameState11GetInstanceEv();
    if (kind == 1) {
        if (_ZNK9GameState21IsMorningDayOrEveningEv(gs)) {
            return 1;
        }
    } else if (kind == 0) {
        if (!_ZNK9GameState21IsMorningDayOrEveningEv(gs)) {
            return 1;
        }
    }

    int a = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)arg + 8));
    int b = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)arg + 0x10));
    if (a != data_02108cec.field0xc) {
        _Z26UnlinkNodeByByteId0206dd68Pvi(data_02108cec.field0x10, b);
        return 1;
    }

    struct Rec0206bf2c* rec = (struct Rec0206bf2c*)((SafeAllocator*)data_02108cec.field0x14)->Allocate(0x78);
    if (rec == 0) {
        return 0;
    }
    _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(rec);
    rec->field0x2 = (unsigned short)a;
    int rem = param1 - half * 2 - even;
    rec->field0x0 = (unsigned char)b;
    if (rem < 4) {
        _Z26UnlinkNodeByByteId0206dd68Pvi(data_02108cec.field0x10, rec->field0x0);
        return 1;
    }

    struct TaggedValue02030b44* v = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct TaggedValue02030b44*)((char*)arg + 0x18), rec->vec0x10);
    rec->field0x1c = (short)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(v));
    if (even) {
        rec->field0x1e = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)v + 8));
    }
    rec->id0x44 = data_02108cec.field0xa;
    rec->flags0xa |= 4;
    func_0206db48(data_02108cec.field0x10, rec);
    return 1;
}
