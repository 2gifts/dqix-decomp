#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>

struct State0204166c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
#if defined(jpn)
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char upperFlags : 5;
#else
    unsigned short f14;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char pad16 : 4;
    unsigned char f17;
    int f18;
#endif
};


struct Entry020e2cc4 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
struct BattleEntry0204500c {
    Entry020e2cc4 prefix;
    unsigned char reserved[0x21];
};
struct BattleFlags0204500c {
    unsigned char streamMode : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char remaining : 2;
};
struct Foo0207df50;
struct Struct0204394c;
struct MessageSystem0219050c;

struct Battle0204500c {
    unsigned char pad0[4];
    void* window38;
    unsigned char pad8[4];
    int stream40;
    int stream44;
    void* buffer48;
    void* buffer4c;
    void* buffer50;
    unsigned char pad20[0xc];
    char* layout60;
    char* layout64;
    unsigned char pad34[0x21c - 0x34];
    unsigned char flags2cc[4];
    unsigned char pad220[0x7e2 - 0x220];
    unsigned char b912;
    unsigned char pad7e3[0x81c - 0x7e3];
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    unsigned char pad85c[4];
    int w990;
    int w994;
    unsigned char pad868[4];
    int state99c;
    int mode9a0;
    int w9a4;
    unsigned char pad878[8];
    int w9b0;
    int w9b4;
    State0204166c states[0x80];
    unsigned char stateFlags[0x80];
    unsigned char pad1708[0x20];
    int w1858;
    int w185c;
    int w1860;
    int w1864;
    int w1868;
    unsigned char pad173c[0x10];
    short h187c;
    short h187e;
    unsigned char pad1750[2];
    unsigned short slots[0x10];
    unsigned short slotCount;
    unsigned short h1944;
    unsigned char pad1776[2];
    signed char levels[4];
    signed char b194e[4];
    unsigned char b1952[4];
    unsigned char b1956;
    unsigned char b1957;
    unsigned char b1958;
    unsigned char pad1787[1];
    unsigned char b195a;
    unsigned char b195b;
    unsigned char pad178a[1];
    unsigned char b195d;
    unsigned char pad178c[2];
    unsigned char b1960;
    unsigned char pad178f[5];
    BattleEntry0204500c entries[2];
    unsigned char b19ac;
    unsigned char b19ad;
    unsigned char b19ae;
    unsigned char b19af;
    unsigned char b19b0;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char pad17e3[1];
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pad17e6[2];
    unsigned char b19b8;
    unsigned char pad17e9[2];
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char pad17ee[1];
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char field17f2;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char pad17fc[1];
    unsigned char b19cc;
    unsigned char b19cd;
    BattleFlags0204500c flags17ff;
    unsigned char pad1800[0x1c4c - 0x1800];
    Foo0207df50* encoder;
};

typedef char VerifyStateSize0204500c[sizeof(State0204166c) == 0x1c ? 1 : -1];
typedef char VerifyRecordSize0204500c[sizeof(BattleEntry0204500c) == 0x24 ? 1 : -1];
typedef char VerifyStatesOffset0204500c[offsetof(Battle0204500c, states) == 0x888 ? 1 : -1];
typedef char VerifySlotOffset0204500c[offsetof(Battle0204500c, slots) == 0x1752 ? 1 : -1];
typedef char VerifyEntryOffset0204500c[offsetof(Battle0204500c, entries) == 0x1794 ? 1 : -1];
typedef char VerifyFlagsOffset0204500c[offsetof(Battle0204500c, flags17ff) == 0x17ff ? 1 : -1];
typedef char VerifyEncoderOffset0204500c[offsetof(Battle0204500c, encoder) == 0x1c4c ? 1 : -1];

extern "C" void func_02045ca4(void*, const char*, int);
extern "C" void func_0206cb14(void*, int, unsigned short);
extern "C" void func_0205e944(void*, int);
extern "C" void func_02041bbc(State0204166c*);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" void func_02044d0c(void);
extern "C" int func_02044104(Struct0204394c*);
extern "C" void func_020698d8(void*, int, const char*, char*);
extern "C" void func_02069ecc(MessageSystem0219050c*, const char*, char*);
extern "C" void func_0206c570(void*, const char*);
extern "C" unsigned char* _Z20GetField4Ptr020e1b24Pv(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
void InvokeSubHandlerIfPresent(int*);
extern "C" void _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(Entry020e2cc4*, int);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern int data_02108760;

// USA: func_0204500c
extern "C" ARM void func_0204500c(Battle0204500c* obj, const char* name, int mode) {
    if (name == 0) return;
    for (int i = 0; i < 4; i++) {
        obj->b194e[i] = -1;
        obj->b1952[i] = 0;
    }
    obj->b1956 = 0;
    obj->b1957 = 0;
    obj->flags17ff.flag4 = 1;
    obj->flags17ff.flag3 = 0;
    obj->b1958 = 0;
    obj->b195b = 0;
    obj->w9b0 = 0;
    obj->b195a = 12;
    if (obj->mode9a0 == 3) {
        func_02045ca4(obj, name, mode);
    } else {
        unsigned short slotCount = obj->slotCount;
        unsigned short* slots = obj->slots;
        for (unsigned short i = 0; i < slotCount; i++) {
            func_0206cb14(obj, 10, slots[i]);
        }
        memset(obj->slots, 0xff01, sizeof(obj->slots));
        obj->b19c4 = 0;
        obj->b19c3 = 0;
        obj->slotCount = 0;
        obj->h1944 = 0;
        obj->b19c2 = 1;
        obj->flags17ff.flag5 = 0;
        obj->b19b0 = 0;
        obj->b19bf = 1;
        obj->flags17ff.flag1 = 1;
        obj->levels[0] = obj->levels[1] = obj->levels[2] = obj->levels[3] = 0x7f;
        func_0205e944(&data_02108760, 0x7f);
        memset(obj->flags2cc, 0, sizeof(obj->flags2cc));
        memset(obj->buffer48, 0, 0x800);
        memset(obj->buffer4c, 0, 0x140);
        memset(obj->buffer50, 0, 0x140);
        obj->b19bd = 1;
        obj->w9b4 = 14;
        for (int i = 14; i < 0x80; i++) {
            func_02041bbc(&obj->states[i]);
            obj->stateFlags[i] = 0;
        }
        obj->b19bb = 1;
        obj->w1860 = 0xc;
        obj->w1864 = 0x10;
        obj->h187c = 0x7fff;
        obj->w9a4 = 3;
        func_02043270(obj, 2, 0x80, 0xfc, 0x3e);
        obj->b19b8 = 0;
        obj->b19b1 = 1;
        obj->w990 = 0x80;
        obj->w1868 = 0;
        obj->b912 = 0;
        obj->w994 = -1;
        obj->w94c[0] = 0;
        obj->w94c[1] = 0;
        obj->w94c[2] = 0;
        obj->w94c[3] = 0;
        obj->b19ac = 0;
        obj->b19ad = 0;
        obj->b1960 = 0;
        for (int i = 0; i < 4; i++) obj->w1868 = 0;
        obj->field17f2 = 0;
        obj->b19c0 = 0;
        obj->b195d = 0x1e;
        obj->b19c1 = 0;
        obj->b19c6 = 0;
        obj->b19c7 = 0;
        obj->b19c8 = 0;
        obj->b19c9 = 0;
        obj->h187e = 0;
        obj->b19cc = 0;
        obj->flags17ff.streamMode = 0;
        obj->b19cd = 0;
        if (mode == 1) {
            obj->b19cc = 1;
        } else if (mode == 1) {
            obj->flags17ff.streamMode = 1;
        }
        if (obj->b19cc != 0) {
            obj->b19cd = 1;
            obj->stream40 = 0;
            func_02044d0c();
        }
        if (obj->flags17ff.streamMode != 0) {
            obj->stream44 = 0;
            func_02044104((Struct0204394c*)obj->encoder);
        }
        func_020698d8(obj, obj->b195a, name, obj->layout60);
        func_02069ecc((MessageSystem0219050c*)obj, obj->layout60, obj->layout64);
        func_0206c570(obj, obj->layout64);
        func_02043270(obj, 2, 0x74, 0xfc, 0x4a);
        obj->w1858 = 2;
        obj->w185c = 0x7e;
        obj->w1860 = 0xc;
        obj->w1864 = 0x14;
        if (obj->window38 != 0) {
            unsigned char* frame = _Z20GetField4Ptr020e1b24Pv(obj->window38);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(obj->window38, -1);
                if (func_020e1f1c(obj->window38) != 0) {
                    func_020e2110(obj->window38);
                    func_020e23f4(obj->window38);
                    InvokeSubHandlerIfPresent((int*)obj->window38);
                }
            }
        }
        memset(obj->block95c, 0, sizeof(obj->block95c));
        memset(obj->block97c, 0, sizeof(obj->block97c));
        obj->w994 = -1;
        obj->b19bc = 0;
        obj->mode9a0 = 5;
        obj->b19b2 = 1;
        obj->state99c = 0;
        obj->b19ae = 0;
        obj->b19af = 0;
        obj->b19b5 = 0;
        obj->b19c5 = 0;
        obj->b19ca = 1;
        obj->b19b4 = 0;
        for (int i = 0; i < 2; i++) {
            _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(&obj->entries[i].prefix, 0);
        }
        if (obj->encoder != 0) _Z26CopyInternalFields0207df50P11Foo0207df50(obj->encoder);
    }
}
#else
#include <globaldefs.h>

class GameState {
public:
    unsigned char unk_0[0x7f58];
    short pendingNumber_7f58;

    static GameState* GetInstance();
};

struct NumberText0204500c {
    char* first;
    char* second;
    int flags;
};

struct State0204166c {
    unsigned char data[0x1c];
};

struct Foo02042fcc {
    unsigned char data[0x1c];
};

struct Entry020e2cc4 {
    unsigned char data[0x24];
};

struct Foo0207df50;
struct Struct0204394c;
struct Ctx0206a974;
struct CombatSlots0206b198;
struct RingBuffer02045824;

struct Battle0204500c {
    unsigned char pad0[0x18];
    NumberText0204500c* number18;
    unsigned char pad1c[0x14];
    signed char cursor30;
    signed char cursor31;
    unsigned char pad32[0x6];
    void* window38;
    unsigned char pad3c[0x4];
    int stream40;
    int stream44;
    void* buffer48;
    void* buffer4c;
    void* buffer50;
    unsigned char pad54[0xc];
    int layout60;
    int layout64;
    unsigned char pad68[0x264];
    unsigned char flags2cc[4];
    unsigned char pad2d0[0x642];
    unsigned char b912;
    unsigned char pad913[0x1d];
    Foo02042fcc foo930;
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    unsigned char pad98c[0x4];
    int w990;
    int w994;
    unsigned char pad998[0x4];
    int state99c;
    int mode9a0;
    int w9a4;
    unsigned char pad9a8[0x8];
    int w9b0;
    int w9b4;
    State0204166c states[0x80];
    unsigned char stateFlags[0x80];
    unsigned char pad1838[0x20];
    int w1858;
    int w185c;
    int w1860;
    int w1864;
    int w1868;
    unsigned char pad186c[0x10];
    short h187c;
    short h187e;
    unsigned char pad1880[0x2];
    unsigned short slots[0x40];
    unsigned char slotData[0x40];
    unsigned short slotCount;
    unsigned short h1944;
    unsigned short h1946;
    unsigned char pad1948[0x2];
    signed char levels[4];
    signed char b194e[4];
    unsigned char b1952[4];
    unsigned char b1956;
    unsigned char b1957;
    unsigned char b1958;
    unsigned char pad1959[0x1];
    unsigned char b195a;
    unsigned char b195b;
    unsigned char pad195c[0x1];
    unsigned char b195d;
    unsigned char pad195e[0x2];
    unsigned char b1960;
    unsigned char pad1961[0x3];
    Entry020e2cc4 entries[2];
    unsigned char b19ac;
    unsigned char b19ad;
    unsigned char b19ae;
    unsigned char b19af;
    unsigned char b19b0;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char pad19b3[0x1];
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pad19b6[0x2];
    unsigned char b19b8;
    unsigned char pad19b9[0x2];
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char pad19be[0x1];
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char pad19cb[0x1];
    unsigned char b19cc;
    unsigned char b19cd;
    unsigned char b19ce;
    unsigned char b19cf;
    unsigned char pad19d0[0x1];
    unsigned char b19d1;
    unsigned char b19d2;
    unsigned char b19d3;
    unsigned char pad19d4[0x8];
    unsigned char b19dc;
    unsigned char pad19dd[0x44b];
    Foo0207df50* encoder;
};

extern "C" void __clear(void* dst, int size);
extern "C" void* memcpy(void* dst, const void* src, unsigned int size);
extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" void* _Z20Clear12Bytes020e46c4Pv(void*);
extern "C" void _Z31DispatchIfCountPositive020dcf7ciPv(int, void*);
int StringLength(const char*);
extern "C" void func_02044f3c(struct Battle0204500c* obj, const char* name, int mode);
extern "C" void _Z24DecrementSlotRef0206b198P19CombatSlots0206b198t(struct CombatSlots0206b198*, unsigned short);
extern "C" void func_0205e944(void* target, int level);
extern "C" void _Z15Forward020416c0P13State0204166c(struct State0204166c*);
extern "C" void func_02042b98(struct Battle0204500c* obj, int a, int b, int c, int d);
extern "C" void _Z16ResetFoo02042fccP11Foo02042fcc(struct Foo02042fcc*);
extern "C" void _Z25SetRingBufferSlot02045824P18RingBuffer02045824ii(struct RingBuffer02045824*, int, int);
extern "C" void func_02044d0c(void);
extern "C" int _Z33PrepareEncodeStreamBuffer0204394cP14Struct0204394c(struct Struct0204394c*);
extern "C" void func_0206831c(struct Battle0204500c* obj, const char* name, int a);
extern "C" void func_02068418(struct Battle0204500c* obj, int a, int b, int flag);
extern "C" void func_02068f40(struct Battle0204500c* obj, int a, int b, int flag);
extern "C" void func_02069234(struct Battle0204500c* obj, int a, int b, int flag);
extern "C" void func_020695f4(struct Battle0204500c* obj, int a, int b, int flag);
extern "C" void func_02069fec(struct Battle0204500c* obj, int a, int b);
extern "C" void _Z25InitContextString0206a974P11Ctx0206a974PKcPv(struct Ctx0206a974*, const char*, void*);
extern "C" unsigned char* _Z20GetField4Ptr020e1b24Pv(void*);
extern "C" void func_020e1b2c(void*, int);
extern "C" int func_020e1f1c(void*);
extern "C" void func_020e2110(void*);
extern "C" void func_020e23f4(void*);
void InvokeSubHandlerIfPresent(int*);
extern "C" void _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(struct Entry020e2cc4*, int);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50*);

extern int data_02108760;

// USA: func_0204500c
extern "C" ARM void func_0204500c(struct Battle0204500c* obj, const char* name, int mode, void* context) {
    GameState* gs = GameState::GetInstance();
    short count = gs->pendingNumber_7f58;
    NumberText0204500c number;
    _Z20Clear12Bytes020e46c4Pv(&number);
    if (count > 0) {
        char first[0x80] = {};
        char second[0x80] = {};
        number.first = first;
        number.second = second;
        _Z31DispatchIfCountPositive020dcf7ciPv(count, &number);
        obj->number18 = &number;
    }
    obj->b19dc = 1;
    if (name == 0) {
        return;
    }

    int len = StringLength(name);
    for (int pos = 0; pos < len;) {
        int n = 0x40;
        char chunk[0x43] = {};
        if (len < pos + 0x40) {
            n = len - pos;
        }
        memcpy(chunk, name + pos, n);
        pos += n;
    }

    for (int i = 0; i < 4; i++) {
        obj->b194e[i] = -1;
        obj->b1952[i] = 0;
    }
    obj->b1956 = 0;
    obj->b1957 = 0;
    obj->b19d2 = 1;
    obj->b19d1 = 0;
    obj->b1958 = 0;
    obj->b195b = 0;
    obj->w9b0 = 0;
    obj->b195a = 8;

    if (obj->mode9a0 == 3) {
        func_02044f3c(obj, name, mode);
    } else {
        unsigned short slotCount = obj->slotCount;
        for (unsigned short i = 0; i < slotCount; i++) {
            _Z24DecrementSlotRef0206b198P19CombatSlots0206b198t((struct CombatSlots0206b198*)obj, obj->slots[i]);
        }
        memset(obj->slots, 0xff01, sizeof(obj->slots));
        memset(obj->slotData, 0, sizeof(obj->slotData));
        obj->b19c4 = 0;
        obj->b19c3 = 0;
        obj->slotCount = 0;
        obj->h1944 = 0;
        obj->h1946 = 0;
        obj->b19c2 = 1;
        obj->b19d3 = 0;
        obj->b19b0 = 0;
        obj->b19bf = 1;
        obj->b19cf = 1;
        obj->levels[0] = obj->levels[1] = obj->levels[2] = obj->levels[3] = 0x7f;
        func_0205e944(&data_02108760, 0x7f);
        memset(obj->flags2cc, 0, sizeof(obj->flags2cc));
        memset(obj->buffer48, 0, 0x960);
        memset(obj->buffer4c, 0, 0x280);
        memset(obj->buffer50, 0, 0x280);
        obj->b19bd = 1;
        obj->w9b4 = 0;
        for (int i = 0; i < 0x80; i++) {
            _Z15Forward020416c0P13State0204166c(&obj->states[i]);
            obj->stateFlags[i] = 0;
        }
        obj->b19bb = 1;
        obj->w1860 = 0xc;
        obj->w1864 = 0x10;
        obj->h187c = 0x7fff;
        obj->w9a4 = 3;
        func_02042b98(obj, 2, 0x80, 0xfc, 0x3e);
        _Z16ResetFoo02042fccP11Foo02042fcc(&obj->foo930);
        obj->b19b8 = 0;
        obj->b19b1 = 1;
        obj->w990 = 0x80;
        obj->w1868 = 0;
        obj->b912 = 0;
        obj->w994 = -1;
        obj->w94c[0] = 0;
        obj->w94c[1] = 0;
        obj->w94c[2] = 0;
        obj->w94c[3] = 0;
        obj->b19ac = 0;
        obj->b19ad = 0;
        obj->b1960 = 0;
        _Z25SetRingBufferSlot02045824P18RingBuffer02045824ii((struct RingBuffer02045824*)obj, 0, -1);
        obj->b19c0 = 0;
        obj->b195d = 0x1e;
        obj->b19c1 = 0;
        obj->b19c6 = 0;
        obj->b19c7 = 0;
        obj->b19c8 = 0;
        obj->b19c9 = 0;
        obj->h187e = 0;
        obj->b19cc = 0;
        obj->b19ce = 0;
        obj->b19cd = 0;
        if (mode == 1) {
            obj->b19cc = 1;
        } else if (mode == 1) {
            obj->b19ce = 1;
        }
        if (obj->b19cc != 0) {
            obj->b19cd = 1;
            obj->stream40 = 0;
            func_02044d0c();
        }
        if (obj->b19ce != 0) {
            obj->stream44 = 0;
            _Z33PrepareEncodeStreamBuffer0204394cP14Struct0204394c((struct Struct0204394c*)obj->encoder);
        }
        int a = obj->layout60;
        int b = obj->layout64;
        func_0206831c(obj, name, a);
        func_02068418(obj, a, b, obj->b19dc);
        func_02068f40(obj, b, a, obj->b19dc);
        func_02069234(obj, a, b, obj->b19dc);
        func_020695f4(obj, b, a, obj->b19dc);
        func_02069fec(obj, a, b);
        _Z25InitContextString0206a974P11Ctx0206a974PKcPv((struct Ctx0206a974*)obj, (const char*)b, context);
        func_02042b98(obj, 2, 0x74, 0xfc, 0x4a);
        obj->w1858 = 2;
        obj->w185c = 0x7e;
        obj->w1860 = 0xc;
        obj->w1864 = 0x14;
        if (obj->window38 != 0) {
            unsigned char* frame = _Z20GetField4Ptr020e1b24Pv(obj->window38);
            if (frame != 0) {
                frame[0x38] = 2;
                frame[0x39] = 0x74;
                frame[0x3a] = 0xfc;
                frame[0x3b] = 0x4a;
                func_020e1b2c(obj->window38, -1);
                if (func_020e1f1c(obj->window38) != 0) {
                    func_020e2110(obj->window38);
                    func_020e23f4(obj->window38);
                    InvokeSubHandlerIfPresent((int*)obj->window38);
                }
            }
        }
        memset(obj->block95c, 0, sizeof(obj->block95c));
        memset(obj->block97c, 0, sizeof(obj->block97c));
        obj->w994 = -1;
        obj->b19bc = 0;
        obj->mode9a0 = 5;
        obj->b19b2 = 1;
        obj->state99c = 0;
        obj->b19ae = 0;
        obj->b19af = 0;
        obj->b19b5 = 0;
        obj->b19c5 = 0;
        obj->b19ca = 1;
        obj->b19b4 = 0;
        for (int i = 0; i < 2; i++) {
            _Z23SetEntryEnabled020e2cc4P13Entry020e2cc4i(&obj->entries[i], 0);
        }
        if (obj->encoder != 0) {
            _Z26CopyInternalFields0207df50P11Foo0207df50(obj->encoder);
        }
    }
    obj->cursor30 = -1;
    obj->cursor31 = -1;
    if (count > 0) {
        gs->pendingNumber_7f58 = 0;
    }
}

#endif
