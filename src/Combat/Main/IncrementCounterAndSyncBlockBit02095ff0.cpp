#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
struct S_a0364;
void AddClampedTopByteAt0x8_020a0364(struct S_a0364* p, unsigned int amount);
ARM int LoadBattleBlock020ac4c0(void* dst);
ARM int CopyInBattleField0x7540_020ac494(void* src);
ARM void SetBitInArrayGuarded_0209609c(int unused, unsigned char* arr, int index);
ARM int TestBitInByteArray02096100(int unused, unsigned char* arr, int idx);

// USA: func_02095ff0  (semantic: IncrementCounterAndSyncBlockBit02095ff0)
extern "C" ARM void func_02095ff0(void* obj, int idx) {
    unsigned char buf[0xb0];
    if (idx > 0xcc || idx < 0) return;

    void* f = func_0205ec34();
    if (TestBitInByteArray_0206dfb0((int)f, (unsigned char*)f + 0x8c, 0x1138)) {
        short* p = (short*)((char*)f + 0x2ca);
        *p = *p + 1;
    }

    if (!TestBitInByteArray02096100((int)obj, (unsigned char*)obj + 0x84, idx)) {
        LoadBattleBlock020ac4c0(buf);
        AddClampedTopByteAt0x8_020a0364((struct S_a0364*)buf, 1);
        CopyInBattleField0x7540_020ac494(buf);
    }

    SetBitInArrayGuarded_0209609c((int)obj, (unsigned char*)obj + 0x84, idx);
}
