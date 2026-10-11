#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_02153710(void*, int);
int IsAnyByteSetInArray0x910(unsigned char* obj);
struct FlagObj_021dd010;
int IsFlagBit8Set_021dd010(struct FlagObj_021dd010* obj);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

struct RngHolder_021ed9dc { void* field0; };

// USA: func_ov024_021ed9dc
ARM int CanTargetCombatant_021ed9dc(struct RngHolder_021ed9dc* holder, int id) {
    void* p = func_ov000_02153710(holder->field0, id);
    if (!p) return 0;
    if (!IsAnyByteSetInArray0x910((unsigned char*)p)) return 0;
    GameObject* combatant = GetCombatantByID((int)holder->field0, id);
    if (!combatant) return 0;
    void* inner = *(void**)((char*)combatant + 0x138);
    if (*(unsigned short*)((char*)inner + 2) == 0) return 0;
    if (IsFlagBit8Set_021dd010((struct FlagObj_021dd010*)combatant)) return 0;
    return !IsCombatantFlagMask512_021eda60(combatant);
}
