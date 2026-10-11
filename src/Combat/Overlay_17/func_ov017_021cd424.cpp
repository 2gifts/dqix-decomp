#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);

struct Entry021633b8 {
    unsigned short f0;
    unsigned short f2 : 15;
    unsigned short flag : 1;
    unsigned char f4;
    signed char f5;
};
void PushEntry021633b8(char* obj, Entry021633b8* src);
void SetByteField0x5901AndFlag0x8000(void* work, unsigned char val);
void SetCombatWorkFlags0x55f4(void* work, int mask);
typedef void (*SetByteField0x5901Fn)(void*, int);

struct Ret021cd424 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Src021cd424 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    signed char fielda;
    unsigned char fieldb;
    signed char fieldc;
};

// JPN: func_ov017_021cd8cc
// USA: func_ov017_021cd424
extern "C" ARM void func_ov017_021cd424(int unused0, Src021cd424* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    Ret021cd424* r = (Ret021cd424*)func_ov017_021b8478(h);
    if (r->field8 != src->field4) return;
    unsigned char* work = (unsigned char*)func_ov017_021b8468(h);
    if (!work) return;
    Entry021633b8 e;
    e.f0 = src->field6;
    e.f2 = src->field8;
    e.f4 = src->fieldb;
    e.f5 = src->fieldc;
    PushEntry021633b8((char*)work, &e);
    if (src->fielda >= 0) {
        ((SetByteField0x5901Fn)SetByteField0x5901AndFlag0x8000)(work, src->fielda);
    }
    SetCombatWorkFlags0x55f4(work, 0x8000);
}
