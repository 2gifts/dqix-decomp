#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_021537b8(char* self, short id, void* rec);

int IsFlag0x14Bit0x20Set_ov000_021543f4(GameObject* combatant);
void* SearchBothTables02079e2c(char* p, int key);

// USA: func_ov000_0215f110
ARM void ProcessCombatEntries_0215f110(char* self) {
    char* selfP = self;
    ActionDataTables* data = GetData02108e10_020797dc();
    int i = 0;
    while (i < *(int*)(selfP + 0x8000 + 0xe7c)) {
        char* rec = (char*)(*(int**)(selfP + 0x8000 + 0xe78)) + i * 0x28;
        short id = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
        GameState* bs = GameState::GetInstance();
        GameObject* c = bs->GetCombatantByIndex(id);
        if (c == NULL) {
            return;
        }
        if (!IsFlag0x14Bit0x20Set_ov000_021543f4(c)) {
            short key = *(short*)rec;
            void* res = SearchBothTables02079e2c((char*)data, key);
            if (res != NULL) {
                unsigned int v = *(unsigned int*)((char*)res + 8);
                if (((v << 3) >> 31) != 0) {
                    short sh = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
                    func_ov000_021537b8(selfP, sh, rec);
                }
            }
        }
        i++;
    }
}
