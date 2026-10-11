// JPN: func_ov017_0219d088
#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);
extern "C" void func_020399b0(GameObject* combatant, unsigned short arg1, int* vec3, int value);

void* GetField0x3f8Address(GameState* battleStruct);
unsigned char GetByte0x26c(char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Owner_1e80c;
struct S_e820;
struct ThreeWords_1e80c { int field0; int field4; int field8; };
ThreeWords_1e80c GetThreeWordsAt0x70(Owner_1e80c* src);
int GetSignedFieldAt0x7c(S_e820* p);

// USA: func_ov017_0219c598  (semantic: DispatchVec3EventToFlaggedCombatants_0219c598)
extern "C" ARM void func_ov017_0219c598(int* srcVec3, short* srcAngle, int forceFlag) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field3f8 = (unsigned char*)GetField0x3f8Address(battleStruct);
    void* dataBase = func_02012fe4();
    ((int)func_ov017_0218b5b0());
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(battleStruct);
    GameObject* combatant = battleStruct->GetUnknownGameObject();

    if (field3f8[0xa] != 0 && forceFlag == 0) {
        return;
    }
    if (field3f8[0x67] != 0 && GetByte0x26c((char*)combatant) != 0) {
        return;
    }

    int vec3[3];
    int angle;
    int i;
    if (srcVec3 != 0) {
        _ZN8Vector3iaSERKS_(vec3, srcVec3);
        if (srcAngle != 0) {
            angle = *srcAngle;
        }
    } else if (field3f8[0x7] != 0) {
        _ZN8Vector3iaSERKS_(vec3, (int*)(field3f8 + 0x10));
        angle = *(short*)(field3f8 + 0x1c);
    } else {
        _ZN8Vector3iaSERKS_(vec3, (int*)&GetThreeWordsAt0x70((Owner_1e80c*)((char*)dataBase + RegionOffset6c)));
        angle = GetSignedFieldAt0x7c((S_e820*)((char*)dataBase + RegionOffset6c));
    }

    int value = _Z22fix32ReduceAngle0To2Pii(angle);

    for (i = 0; i < field2a04[0xf7c]; i++) {
        GameObject* c = battleStruct->GetPartyMemberByIndex((field2a04 + i)[0xf78]);
        if (c != 0) {
            func_020399b0(c, *(unsigned short*)dataBase, vec3, value);
        }
    }

    if (field2a04[0xf7d] != 0) {
        GameObject* c = battleStruct->GetPartyMemberByIndex(0xce);
        if (c != 0) {
            func_020399b0(c, *(unsigned short*)dataBase, vec3, value);
        }
    }
}
