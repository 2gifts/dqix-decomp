#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void*);
extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void func_ov023_021dc134(void*, int, int);
extern "C" void func_ov023_021dbfd0(void*, void*);

struct Obj021fbd00 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    char pad_a[0x16];
    char sub20[0x48];
    int f68;
#if defined(jpn)
    char pad6c[0x6a4];
#else
    char pad6c[0x728];
#endif
    unsigned short f794;
    char pad796[2];
    unsigned char f798;
};

// JPN: func_ov023_021fb07c
// USA: func_ov023_021fbd00  (semantic: InitObjWithSlots_021fbd00)
extern "C" ARM int func_ov023_021fbd00(Obj021fbd00* obj, void* ctx, unsigned short arg2, unsigned short arg3, int arg5, int arg6, unsigned char arg7) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 0x10;
    obj->f6 = arg2;
    obj->f8 = arg3;
    void* result = func_ov011_021845f8(ctx, obj->f8);
    if (result == NULL) return 0;
    func_ov023_021dc134(obj->sub20, -1, 0);
    obj->f794 = obj->f794 | (unsigned short)(arg5 | 0x4000);
    func_ov023_021dbfd0(obj->sub20, (char*)result + 4);
    obj->f68 = arg6;
    obj->f798 = arg7;
    return 1;
}
