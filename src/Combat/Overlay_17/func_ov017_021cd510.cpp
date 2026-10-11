#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
bool GetTreasureMapTypeFromItemID(unsigned short itemID, unsigned char* out);
void SetFields0216341c(void* work, unsigned char b1, unsigned char b2, short h);
void SetByteField0x5901AndFlag0x8000(void* work, unsigned char val);
void SetCombatWorkFlags0x55f4(void* work, int mask);
typedef void (*SetByteField0x5901Fn)(void*, int);
typedef void (*SetFields0216341cFn)(void*, unsigned char, unsigned char, unsigned short);

struct Ret021cd510 { unsigned char pad0[8]; unsigned short field8; };
struct Src021cd510 { unsigned char pad0[4]; unsigned short field4; unsigned short field6; signed char field8; };

// JPN: func_ov017_021cd9b8
// USA: func_ov017_021cd510
extern "C" ARM void func_ov017_021cd510(int unused0, Src021cd510* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    Ret021cd510* r = (Ret021cd510*)func_ov017_021b8478(h);
    if (r->field8 != src->field4) return;

    unsigned char buf[4];
    if (!GetTreasureMapTypeFromItemID(src->field6, buf)) return;

    unsigned char* work = (unsigned char*)func_ov017_021b8468(h);
    if (!work) return;

    ((SetFields0216341cFn)SetFields0216341c)(work, buf[0], buf[1], *(unsigned short*)(buf + 2));

    if (src->field8 >= 0) {
        ((SetByteField0x5901Fn)SetByteField0x5901AndFlag0x8000)(work, src->field8);
    }
    SetCombatWorkFlags0x55f4(work, 0x8000);
}
