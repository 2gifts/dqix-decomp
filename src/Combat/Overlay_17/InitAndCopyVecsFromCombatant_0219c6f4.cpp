#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetField0x3f8Address(GameState* battleStruct);
void InitStruct02070378(char* obj);
struct Vector3i;

// USA: func_ov017_0219c6f4  (semantic: InitAndCopyVecsFromCombatant_0219c6f4)
extern "C" ARM void* func_ov017_0219c6f4(char* combatant) {
    GameState* battleStruct = GameState::GetInstance();
    char* obj = (char*)GetField0x3f8Address(battleStruct);
    InitStruct02070378(obj);

    *(short*)(obj + 0x0) = *(int*)(combatant + 0x1c);
    *(Vector3i*)((int*)(obj + 0x10)) = *(Vector3i const*)((int*)(combatant + 0x20));

    *(short*)(obj + 0x1c) = *(short*)(combatant + 0x50);
    *(unsigned char*)(obj + 0xb) = *(int*)(combatant + 0x6c);
    *(Vector3i*)((int*)(obj + 0x30)) = *(Vector3i const*)((int*)(combatant + 0x20));

    *(Vector3i*)((int*)(obj + 0x3c)) = *(Vector3i const*)((int*)(combatant + 0x2c));
    *(Vector3i*)((int*)(obj + 0x48)) = *(Vector3i const*)((int*)(combatant + 0x38));
    *(Vector3i*)((int*)(obj + 0x54)) = *(Vector3i const*)((int*)(combatant + 0x44));

    *(unsigned char*)(obj + 0xc) = 1;
    *(unsigned char*)(obj + 0x7) = 1;

    return obj;
}
