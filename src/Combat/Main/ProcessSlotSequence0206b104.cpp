#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069444(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
#endif

struct CombatSlots0206b198;
void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx);
ARM bool IsHighByteFF02044494(void* obj, void* src);
int Dispatch02044420(void* obj, void* src);

#if defined(jpn)
struct Combat0206b104 {
 char pad0[0x18]; unsigned short* arr; int unused1c; int f54; int f58;
 char pad28[0x10]; int count; int f70; union { int f74; int idx; }; int f78;
};
#else
struct Combat0206b104 {
    char pad0[0x4c];
    unsigned short* arr;
    char pad50[0x54 - 0x50];
    int f54;
    int f58;
    char pad5c[0x6c - 0x5c];
    int count;
    int f70;
    int f74;
    int f78;
    char pad7c[0x88 - 0x7c];
    int idx;
};

#endif
// USA: func_0206b104  (semantic: ProcessSlotSequence0206b104)
extern "C" ARM void func_0206b104(struct Combat0206b104* obj) {
#if defined(jpn)
    if ((obj->f54 == 0) | (obj->f58 == 0)) return;
#else
    if (obj->f54 == 0 || obj->f58 == 0) return;
#endif
    if (obj->count == 0) return;
    unsigned short* p;
    unsigned int i = obj->idx;
    for (; i < obj->count; i++) {
        p = obj->arr + i;
        #if defined(jpn)
        if (func_02069430(obj, *p)) {
#else
        if (IsHighByteFF02044494(obj, p)) {
#endif
            #if defined(jpn)
            i += func_02069444(obj, *p);
#else
            i += Dispatch02044420(obj, p);
#endif
        } else {
#if defined(jpn)
            func_0206cb14(obj, 12, *p);
            func_0206cb14(obj, 6, *p);
#else
            DecrementSlotRef0206b198((struct CombatSlots0206b198*)obj, *p);
#endif
        }
    }
    obj->count = 0;
    obj->f70 = 0;
    obj->f74 = 0;
    obj->f78 = 0;
}
