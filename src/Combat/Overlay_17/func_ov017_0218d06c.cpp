#include <globaldefs.h>

unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" void func_ov017_0218e674(unsigned char* ov);
#if defined(jpn)
#define func_ov017_021a1ad0 func_ov017_021a2560
#define func_ov017_0218d06c func_ov017_0218dc4c
#define REGIONAL_FIELD(jp, us) (jp)
#else
#define REGIONAL_FIELD(jp, us) (us)
#endif
extern "C" void func_ov017_021a1ad0(unsigned char* ov);
void AdvanceCombatantsInRange_02197394(void);

// USA: func_ov017_0218d06c
extern "C" ARM void func_ov017_0218d06c(unsigned char* ov) {
    if (GetBitsInField0((unsigned int*)ov, 0x800) != 0) return;
    int shouldAdvance = 0;
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + REGIONAL_FIELD(0x4ec, 0x6fc))) != 0x26) {
        func_ov017_0218e674(ov);
        shouldAdvance = 1;
    }
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + REGIONAL_FIELD(0x4ec, 0x6fc))) != 0x26 ||
        *(unsigned char*)(*(unsigned char**)(ov + 0x3000 + REGIONAL_FIELD(0x910, 0xb30)) + 0xb) == 0) {
        func_ov017_021a1ad0(ov);
    }
    if (shouldAdvance != 0) {
        ((void (*)(unsigned char*))AdvanceCombatantsInRange_02197394)(ov);
    }
}
