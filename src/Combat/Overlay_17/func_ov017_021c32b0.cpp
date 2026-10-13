#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Mapping021c32b0 { unsigned char source, destination; };
struct PartyPolygonIds { signed char ids[11]; };
struct PartyPolygonResources {
#if defined(jpn)
    unsigned char unknown0[0x41ac];
#else
    unsigned char unknown0[0x445c];
#endif
    PartyPolygonIds party[4];
};
struct Saved021c32b0 { GameObject* main; GameObject* attachments[9]; };
struct ModelResourceOwner { unsigned short partySlot; };
struct Combatant021c32b0 {
#if defined(jpn)
    unsigned char unknown0[0x148];
#else
    unsigned char unknown0[0x154];
#endif
    ModelResourceOwner* models;
};
struct Data021c32b0 { char pad[0x568]; unsigned short slot; };
void ClearCombatantSlot(GameState*, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
Data021c32b0* GetFieldAt0x150(unsigned char*);

// USA: func_ov017_021c32b0
extern "C" ARM void func_ov017_021c32b0(Mapping021c32b0* mapping, int count) {
    Saved021c32b0 saved[4];
    PartyPolygonIds polygonIds[4];
    PartyPolygonResources* resources;
    GameState* game;
    game = GameState::GetInstance();
    resources = (PartyPolygonResources*)func_ov017_0218b5b0();
    int i = 0;
    while (i < count) {
        unsigned char id = mapping[i].source;
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
        memcpy(&polygonIds[i], &resources->party[id], sizeof(PartyPolygonIds));
        i++;
    }
    int j = 0;
    while (j < count) {
        int id = mapping[j].destination;
        RegisterCombatantSlot(game, id, saved[j].main);
        RegisterCombatantSlot(game, id * 12 + 0x13, saved[j].attachments[0]);
        RegisterCombatantSlot(game, id * 12 + 0x14, saved[j].attachments[1]);
        RegisterCombatantSlot(game, id * 12 + 0x15, saved[j].attachments[2]);
        RegisterCombatantSlot(game, id * 12 + 0x16, saved[j].attachments[3]);
        RegisterCombatantSlot(game, id * 12 + 0x17, saved[j].attachments[4]);
        RegisterCombatantSlot(game, id * 12 + 0x19, saved[j].attachments[5]);
        RegisterCombatantSlot(game, id * 12 + 0x1b, saved[j].attachments[6]);
        RegisterCombatantSlot(game, id * 12 + 0x1c, saved[j].attachments[7]);
        RegisterCombatantSlot(game, id * 12 + 0x1d, saved[j].attachments[8]);
        Combatant021c32b0* combatant = (Combatant021c32b0*)GetCombatantWithFlag0x100(game, id);
        if (combatant) {
            Data021c32b0* data = GetFieldAt0x150((unsigned char*)combatant);
            if (data) data->slot = id;
            if (combatant->models) combatant->models->partySlot = id;
        }
        memcpy(&resources->party[id], &polygonIds[j], sizeof(PartyPolygonIds));
        j++;
    }
}
