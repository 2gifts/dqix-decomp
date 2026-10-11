#include <globaldefs.h>

#if defined(jpn)
#define REGION_FIELD_0 0x4c0
#else
#define REGION_FIELD_0 0x6d0
#endif


void SetFlagBits0x55e(unsigned char* base, int bit);

struct FlagPair_0218b5f8 { int a; int b; };
extern FlagPair_0218b5f8 data_ov017_021d82e0;

// USA: func_ov017_0218b5f8  (semantic: SetFlagBits55eIfActive_0218b5f8)
extern "C" ARM void func_ov017_0218b5f8(int bit) {
    int b = data_ov017_021d82e0.b;
    if (b == 0) return;
    int val = *(int*)((char*)b + 0x3000 + REGION_FIELD_0);
    if (val == 0) return;
    SetFlagBits0x55e((unsigned char*)val, bit);
}
