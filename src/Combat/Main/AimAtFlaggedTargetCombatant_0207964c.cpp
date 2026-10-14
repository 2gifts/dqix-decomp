#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj);
struct Vector3i;
int fix32ReduceAngle0To2Pi(int arg);
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct CombatantFlagObj0207964c {
    char pad[0xc1];
    unsigned char flags2 : 2;
};

// USA: func_0207964c  (semantic: AimAtFlaggedTargetCombatant_0207964c)
extern "C" ARM void func_0207964c(unsigned char* self) {
    if (self[0x17d] & 8) {
        GameState* battleStruct = GameState::GetInstance();
        int field = GetField0x17dBits4To5IfFlag8_020795cc(self);
        unsigned char* combatant = (unsigned char*)battleStruct->GetPartyMemberByIndex(field);
        if (combatant != NULL) {
            if (!(((struct CombatantFlagObj0207964c*)combatant)->flags2 & 1)) {
                int scale = ((Object3D*)combatant)->GetRadius() / 4 + ((Object3D*)self)->GetRadius() / 2;
                Vector3fix vec = ((Object3D*)combatant)->GetPointInFront(scale);
                int angleArg = *(int*)(combatant + 0x54) + 0x3244;
                int aim = fix32ReduceAngle0To2Pi(angleArg);
                *(Vector3i*)((int*)(self + 0x44)) = *(Vector3i const*)((int*)&vec);
                SetVecYFromValue02033874((struct Obj02033874*)self, aim);
            }
        }
    }
}
