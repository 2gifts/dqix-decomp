#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069444(void*, unsigned short);
extern "C" int func_020694a0(void*, unsigned short);
extern "C" void func_0206cb14(void*, int, unsigned short);
#endif

int IsHalfwordInRange02067ad8(int unused, void* src);
bool IsHighByteFF02044494(void* obj, void* src);
int Dispatch02044420(void* obj, void* src);

struct CombatSlots0206b198;
void DecrementSlotRef0206b198(struct CombatSlots0206b198* obj, unsigned short idx);

struct Ctx0206b61c {
    #if defined(jpn)
    unsigned char pad0[0x18];
#else
    unsigned char pad0[0x4c];
#endif
    unsigned short* buf;
    unsigned char pad1[0x74 - 0x50];
    int idx;
    int counter;
};

// USA: func_0206b61c
ARM void ProcessTextTokens0206b61c(struct Ctx0206b61c* obj) {
    int cont = 1;
    int consumed = 0;
    int stop = consumed;
    unsigned short* p = obj->buf + obj->idx;
    while (cont) {
        int extra;
        #if defined(jpn)
        if (func_020694a0(obj, *p)) {
#else
        if (IsHalfwordInRange02067ad8((int)obj, p)) {
#endif
            cont = stop;
        }
        #if defined(jpn)
        if (func_02069430(obj, *p)) {
#else
        if (IsHighByteFF02044494(obj, p)) {
#endif
            #if defined(jpn)
            extra = func_02069444(obj, *p);
#else
            extra = Dispatch02044420(obj, p);
#endif
            p += extra;
            consumed += extra;
        } else {
#if defined(jpn)
            func_0206cb14(obj, *((unsigned char*)obj + 0x1788), *p);
            func_0206cb14(obj, 12, *p);
            func_0206cb14(obj, 6, *p);
#else
            DecrementSlotRef0206b198((struct CombatSlots0206b198*)obj, *p);
#endif
        }
        p += 1;
        consumed += 1;
    }
    obj->idx += consumed;
    obj->counter += 1;
}
