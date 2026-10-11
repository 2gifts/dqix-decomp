#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x5a68 };
#else
enum { kRegionalFieldOffset = 0x5cc8 };
#endif

#include "GameState/GameState.h"

void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int PollUntilFieldMatchesOrLimit0202b284(int unused, int threshold);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021c37a4(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0(struct StateBits5ccc_11544* state);

// USA: func_0202b1f4  (semantic: PollFlagAndFinalizeState_0202b1f4)
extern "C" ARM int func_0202b1f4(int* outPtr) {
    GameState* battleStruct = GameState::GetInstance();
    int ctx = ((int)func_ov017_0218b5b0());
    struct FlagWord02046708* flagWord = (struct FlagWord02046708*)GetDataPtr02114e04_020d6c00();
    if (TestFlags02046708(flagWord, 0x1000000)) {
        return 3;
    }
    int result = PollUntilFieldMatchesOrLimit0202b284((int)outPtr, 1);
    if ((unsigned int)((result + 0xfe) & 0xff) > 1) {
        return result;
    }
    OrBitsIntoField0((unsigned int*)flagWord, 0x1000000);
    func_ov017_021c37a4();
    _Z13SetBrightnessP13GameResourcesii((void*)ctx, -16, 10);
    *(unsigned char*)((char*)battleStruct + kRegionalFieldOffset) = 4;
    SetFlag0x5cccBit0((struct StateBits5ccc_11544*)battleStruct);
    *outPtr = 3;
    return 3;
}
