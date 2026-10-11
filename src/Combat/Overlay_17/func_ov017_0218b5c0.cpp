#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x4c0
#else
#define REGION_FIELD_0 0x6d0
#endif


void SetOrClearFlagBit0x55d(unsigned char* base, int set, int bit);

struct FlagPair_0218b5c0 { int a; int b; };
extern FlagPair_0218b5c0 data_ov017_021d82e0;

// USA: func_ov017_0218b5c0  (semantic: SetOrClearFlagBit55dIfActive_0218b5c0)
extern "C" ARM void func_ov017_0218b5c0(int set, int bit) {
    int b = data_ov017_021d82e0.b;
    if (b == 0) return;
    int val = *(int*)((char*)b + 0x3000 + REGION_FIELD_0);
    if (val == 0) return;
    SetOrClearFlagBit0x55d((unsigned char*)val, set, bit);
}
