#include <globaldefs.h>

extern "C" ARM int func_ov015_021925a8(void* obj);
int TestFlagMask_02012430(unsigned short* obj, int mask);
int TestFlagInSecondWord_02012468(unsigned short* obj, unsigned int mask);

extern unsigned short data_02114e30;

struct Obj02190c98 {
    char pad[0x350];
    unsigned char flag350;
};

// USA: func_ov015_02190c98  (semantic: CheckCombatantFlag350AndMasks)
extern "C" ARM int func_ov015_02190c98(struct Obj02190c98* obj) {
    if (obj->flag350 != 0) return 1;
    if (!func_ov015_021925a8(obj)) {
        if (TestFlagMask_02012430(&data_02114e30, 0xc0)) return 1;
    }
    if (!func_ov015_021925a8(obj)) {
        if (TestFlagInSecondWord_02012468(&data_02114e30, 0xc0)) return 1;
    }
    return 0;
}
