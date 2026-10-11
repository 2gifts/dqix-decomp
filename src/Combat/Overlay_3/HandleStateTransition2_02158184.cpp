#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue1F9_1F5 = 0x1f5 };
enum { kRegionValue1F8_1F4 = 0x1f4 };
#else
enum { kRegionValue1F9_1F5 = 0x1f9 };
enum { kRegionValue1F8_1F4 = 0x1f8 };
#endif


extern "C" int _Z21IsFieldEq3At_021538e0Pv(void*);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void SetCombatModeFromCase020dc2d0(int);
void ResetHandlesAndFlags_02153874(void* obj);

// USA: func_ov003_02158184
// JPN: func_ov003_02159670
ARM void HandleStateTransition2_02158184(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char state = *(unsigned char*)(s + kRegionValue1F9_1F5);
    void* p4 = *(void**)(s + 4);

    if (state == 0) {
        signed char b = *(signed char*)((char*)p4 + 0x59);
        int ok = 0;
        if (b < 0) goto check;
        if (b <= 3) ok = 1;
    check:
        if (!ok) {
            *(unsigned char*)(s + kRegionValue1F8_1F4) = 7;
            return;
        }
        *(signed char*)((char*)p4 + 0x59) = -1;
        ResetHandlesAndFlags_02153874(p4);
        *(unsigned char*)(s + kRegionValue1F9_1F5) = *(unsigned char*)(s + kRegionValue1F9_1F5) + 1;
        return;
    }
    if (state != 1) return;
    if (_Z21IsFieldEq3At_021538e0Pv(p4) == 0) return;

    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
    SetCombatModeFromCase020dc2d0(0);
    *(unsigned char*)(s + kRegionValue1F8_1F4) = 7;
}
