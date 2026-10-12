#include <globaldefs.h>

#if defined(jpn)
enum { ACTIVE_OBJECT_FIELD = 0x4c0 };
#else
enum { ACTIVE_OBJECT_FIELD = 0x6d0 };
#endif


#if defined(jpn)
#define TestFlagBit55dIfActive_0218b628 func_ov017_0218c248
#endif

int TestFlagBit0x55d(unsigned char* base, int bit);

struct FlagPair_0218b628 { int a; int b; };
extern FlagPair_0218b628 data_ov017_021d82e0;

// USA: func_ov017_0218b628
#if defined(jpn)
extern "C"
#endif
ARM int TestFlagBit55dIfActive_0218b628(int bit) {
    int b = data_ov017_021d82e0.b;
    if (b == 0) return 0;
    int val = *(int*)((char*)b + 0x3000 + ACTIVE_OBJECT_FIELD);
    if (val == 0) return 0;
    return TestFlagBit0x55d((unsigned char*)val, bit);
}
