#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Mapping021c32b0 { unsigned char source, destination; };
struct FlagRecord021c32b0 { unsigned char flags[11]; };
struct ResourceFlags021c32b0 { char pad[0x445c]; FlagRecord021c32b0 slots[0xe9]; };
struct Saved021c32b0 { GameObject* main; GameObject* attachments[9]; };
struct Combatant021c32b0 { char pad[0x154]; unsigned short* field_154; };
struct Data021c32b0 { char pad[0x568]; unsigned short slot; };
void ClearCombatantSlot(GameState*, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
Data021c32b0* GetFieldAt0x150(unsigned char*);

// USA: func_ov017_021c32b0
extern "C" ARM void func_ov017_021c32b0(Mapping021c32b0* mapping, int count) {
    Saved021c32b0 saved[4];
    FlagRecord021c32b0 flags[4];
    ResourceFlags021c32b0* resources;
    GameState* game;
    game = GameState::GetInstance();
    resources = (ResourceFlags021c32b0*)func_ov017_0218b5b0();
    int i = 0;
    while (i < count) {
        short id = mapping[i].source;
        saved[i].main = game->GetGameObjectByIndex(id);
        ClearCombatantSlot(game, id);
        saved[i].attachments[0] = game->GetGameObjectByIndex(id * 12 + 0x13);
        ClearCombatantSlot(game, id * 12 + 0x13);
        saved[i].attachments[1] = game->GetGameObjectByIndex(id * 12 + 0x14);
        ClearCombatantSlot(game, id * 12 + 0x14);
        saved[i].attachments[2] = game->GetGameObjectByIndex(id * 12 + 0x15);
        ClearCombatantSlot(game, id * 12 + 0x15);
        saved[i].attachments[3] = game->GetGameObjectByIndex(id * 12 + 0x16);
        ClearCombatantSlot(game, id * 12 + 0x16);
        saved[i].attachments[4] = game->GetGameObjectByIndex(id * 12 + 0x17);
        ClearCombatantSlot(game, id * 12 + 0x17);
        saved[i].attachments[5] = game->GetGameObjectByIndex(id * 12 + 0x19);
        ClearCombatantSlot(game, id * 12 + 0x19);
        saved[i].attachments[6] = game->GetGameObjectByIndex(id * 12 + 0x1b);
        ClearCombatantSlot(game, id * 12 + 0x1b);
        saved[i].attachments[7] = game->GetGameObjectByIndex(id * 12 + 0x1c);
        ClearCombatantSlot(game, id * 12 + 0x1c);
        saved[i].attachments[8] = game->GetGameObjectByIndex(id * 12 + 0x1d);
        ClearCombatantSlot(game, id * 12 + 0x1d);
        memcpy(&flags[i], &resources->slots[(unsigned int)id], 11);
        i++;
    }
    int j = 0;
    while (j < count) {
        int id = mapping[j].destination;
        RegisterCombatantSlot(game, id, saved[j].main);
        RegisterCombatantSlot(game, (short)id * 12 + 0x13, saved[j].attachments[0]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x14, saved[j].attachments[1]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x15, saved[j].attachments[2]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x16, saved[j].attachments[3]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x17, saved[j].attachments[4]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x19, saved[j].attachments[5]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x1b, saved[j].attachments[6]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x1c, saved[j].attachments[7]);
        RegisterCombatantSlot(game, (short)id * 12 + 0x1d, saved[j].attachments[8]);
        Combatant021c32b0* combatant = (Combatant021c32b0*)GetCombatantWithFlag0x100(game, id);
        if (combatant) {
            Data021c32b0* data = GetFieldAt0x150((unsigned char*)combatant);
            if (data) data->slot = id;
            if (combatant->field_154) *combatant->field_154 = id;
        }
        memcpy(&resources->slots[(unsigned int)id], &flags[j], 11);
        j++;
    }
}
