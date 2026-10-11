#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void SetCombatFields02163344(void* obj, int a1, short a2, unsigned char a3, unsigned short a4, unsigned short a5);
typedef void (*SetCombatFields02163344Fn)(void*, int, unsigned short, unsigned int, unsigned short, unsigned short);

struct Src021cd2dc {
    unsigned char pad[4];
    unsigned short field4 : 16;
    unsigned short field6;
    unsigned short field8;
    unsigned short fieldA_lo : 4;
    unsigned short fieldA_hi : 12;
    unsigned short fieldC_lo : 4;
    unsigned short fieldC_hi : 12;
};
struct Ret021cd2dc { unsigned char pad[8]; unsigned short field8; };

// JPN: func_ov017_021cd784
// USA: func_ov017_021cd2dc  (semantic: CallSetCombatFieldsIfMatch_021cd2dc)
extern "C" ARM void func_ov017_021cd2dc(int unused0, Src021cd2dc* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    obj += 0x3000;
    void* work = *(void**)(obj + regionalOffset0);
    Ret021cd2dc* r = (Ret021cd2dc*)func_ov017_021b8478(work);
    if (*(unsigned short*)((char*)r + 8) != src->field4) return;

    void* p = func_ov017_021b8468(work);
    if (!p) return;

    unsigned short nibbleC = src->fieldC_lo;
    unsigned short hiA = src->fieldA_hi;
    unsigned short field6 = src->field6;
    unsigned short field8 = src->field8;

    ((SetCombatFields02163344Fn)SetCombatFields02163344)(p, field6, field8, src->fieldA_lo, nibbleC, hiA);
}
