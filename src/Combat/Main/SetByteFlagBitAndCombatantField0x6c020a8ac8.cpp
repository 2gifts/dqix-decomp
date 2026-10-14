#include <globaldefs.h>
#include "GameState/GameState.h"

void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);

// USA: func_020a8ac8
ARM void SetByteFlagBitAndCombatantField0x6c_020a8ac8(unsigned char* obj, int bit) {
    *(unsigned char*)(obj + 4) |= (1 << bit);
    OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x402);
    ((Object3D*)((unsigned char*)GameState::GetInstance()->GetPartyMemberByIndex(bit)))->EnableFlag(0x8000100);
}
