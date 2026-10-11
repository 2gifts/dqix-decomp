#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue70_40 = 0x40 };
#else
enum { kRegionValue70_40 = 0x70 };
#endif


struct Cont0207fe44;
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);

struct Pair02167a5c { unsigned int a; unsigned int b; };
extern struct Pair02167a5c data_020e6d5c;
struct Inner02167a5c { unsigned int v[2]; };

struct DispatchEntry02167a5c { unsigned int fn; unsigned int locator; };
struct Table02167a5c { struct DispatchEntry02167a5c entries[7]; };
extern struct Table02167a5c data_ov003_0217f4f0;

struct Obj02167a5c {
    char pad0[0x10];
    struct Cont0207fe44* f10;
    char pad14[kRegionValue70_40 - 0x14];
    int f70;
    unsigned char f74;
    char pad75;
    signed char f76;
};

// USA: func_ov003_02167a5c
// JPN: func_ov003_02167934
extern "C" ARM void func_ov003_02167a5c(struct Obj02167a5c* obj, int p1, int p2) {
    if (obj->f74 == 0 || obj->f10 == 0) return;
    if (obj->f70 == p1 && obj->f76 == p2) return;

    if (obj->f70 != p1 || p2 < 0) {
        CallFunc0204c804OverAllElems(obj->f10);
    }
    obj->f70 = p1;
    obj->f76 = (signed char)p2;

    struct Table02167a5c buf;
    buf = data_ov003_0217f4f0;
    *(struct Inner02167a5c*)&buf.entries[0] = *(struct Inner02167a5c*)&data_020e6d5c;

    if (buf.entries[p1].fn == 0) return;
    struct DispatchEntry02167a5c* d = &buf.entries[p1];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    ((void(*)(void*))callback)(base);
}
