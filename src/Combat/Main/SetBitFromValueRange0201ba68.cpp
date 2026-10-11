#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
extern "C" void* func_0205ec34(void);
int ConvertIndex(int x);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
int IsInRange0201b588(int id);
int LookupKeyValue(int key);
extern "C" int _s32_div_f(int a, int b);


#if defined(jpn)
enum { ValueRangeStateOffset = 0x2860 };
#else
enum { ValueRangeStateOffset = 0x2820 };
#endif

// JPN: func_0201b7e0
// USA: func_0201ba68
ARM void SetBitFromValueRange0201ba68(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    if (func_0202c540(func_0202ae18()) != 0 || base[ValueRangeStateOffset] != 0) return;

    void* ctx = func_0205ec34();
    if (*(unsigned short*)base >= 20000 && *(unsigned short*)base <= 0x752f) {
        int idx = ConvertIndex(*(unsigned short*)base);
        if (idx < 0) return;
        SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, idx + 0x5a + 0xa00, 1);
        return;
    }
    if (*(unsigned short*)base >= 100 && *(unsigned short*)base <= 0x270f) {
        int q = _s32_div_f(*(unsigned short*)base, 100);
        if (q >= 100) return;
        SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, q + 0x96 + 0xa00, 1);
        return;
    }
    if (IsInRange0201b588(*(unsigned short*)base)) {
        SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, 0x79d, 1);
        return;
    }
    int t2 = LookupKeyValue(*(unsigned short*)base);
    if (t2 < 0) return;
    SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, t2 + 0x5a + 0xa00, 1);
}
