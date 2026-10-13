#include <globaldefs.h>
#include "Resource/GameResources.h"

unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" void func_ov017_0218e674(unsigned char* ov);
extern "C" void func_ov017_021a1ad0(unsigned char* ov);
void AdvanceCombatantsInRange_02197394(GameResources*);

struct EventAdvanceGate {
    unsigned char unknown0[0xb];
    unsigned char flag;
};

// USA: func_ov017_0218d06c
extern "C" ARM void func_ov017_0218d06c(unsigned char* ov) {
    GameResources* resources = (GameResources*)ov;
    if (GetBitsInField0(&resources->brightnessFlags_0, 0x800) != 0) return;
    int shouldAdvance = 0;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) != 0x26) {
        func_ov017_0218e674(ov);
        shouldAdvance = 1;
    }
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) != 0x26 ||
        ((EventAdvanceGate*)resources->unknown_ptr_array_3afc[13])->flag == 0) {
        func_ov017_021a1ad0(ov);
    }
    if (shouldAdvance != 0) {
        AdvanceCombatantsInRange_02197394(resources);
    }
}
