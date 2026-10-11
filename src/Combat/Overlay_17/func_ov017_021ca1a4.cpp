// JPN: func_ov017_021ca654
#if defined(jpn)
enum { RegionOffset3718 = 0x3508, RegionOffset54f4 = 0x56e8 };
#else
enum { RegionOffset3718 = 0x3718, RegionOffset54f4 = 0x54f4 };
#endif

#include <globaldefs.h>

int PeekInputLogA(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);

struct Combatant020A36A8;
int MatchesActiveIndex020a36a8(struct Combatant020A36A8* obj);

int TestBitAt0x34(unsigned char* obj, unsigned int index);

struct Src021c6814 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    unsigned char field3;
    signed char field4;
    unsigned char pad5;
    unsigned short field6;
    unsigned short field8;
};
extern "C" void func_ov017_021c6814(unsigned short a, unsigned short b, struct Src021c6814* src, unsigned char flags, signed char arg5, unsigned char arg6);

extern "C" void func_ov000_02162c14(void* b, int idx, struct Src021c6814* out);

void SetCombatWorkFlags0x55f4(void* work, int mask);

struct Arg1_021ca1a4 { char pad[4]; unsigned short field4; };
struct AType_021ca1a4 { char pad[8]; unsigned short field8; };

// USA: func_ov017_021ca1a4
extern "C" ARM void func_ov017_021ca1a4(int argIdx, struct Arg1_021ca1a4* arg1, void* unused, char* arg3) {
    if (PeekInputLogA() != 0) return;

    void* combatant = *(void**)(arg3 + RegionOffset3718);
    void* a = func_ov017_021b8478(combatant);
    void* b = func_ov017_021b8468(combatant);
    if (!a || !b) return;

    if (((struct AType_021ca1a4*)a)->field8 != arg1->field4) return;

    if (MatchesActiveIndex020a36a8((struct Combatant020A36A8*)a)) {
        int i;
        struct Src021c6814 buf;
        for (i = 0; i < 4; i++) {
            if (TestBitAt0x34((unsigned char*)a, i & 0xff) && argIdx != i) {
                func_ov000_02162c14(b, i, &buf);
                int val = *(int*)((char*)b + i * 4 + RegionOffset54f4);
                func_ov017_021c6814(((struct AType_021ca1a4*)a)->field8, (unsigned short)i, &buf, (unsigned char)(val & 0xff), (signed char)argIdx, 0);
            }
        }
    } else {
        SetCombatWorkFlags0x55f4(b, 0x40000000);
    }
}
