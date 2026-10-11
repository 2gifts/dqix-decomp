#include <globaldefs.h>

#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"

struct FlagWord02046708;
void *GetDataPtr02114e04_020d6c00();
int TestFlags02046708(FlagWord02046708 *word, unsigned int mask);
void SetElementFields0202756c(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char opacity, int scaleX, int scaleY);

struct PartyIdentifierList {
    int values[4];
};

extern const PartyIdentifierList data_020e7064;

struct PartyDisplayReceiverPrefix {
    unsigned char unknown0[0x38];
    fix32_t scale;
#if defined(jpn)
    unsigned char unknown3c[0x914 - 0x3c];
#else
    unsigned char unknown3c[0x9c0 - 0x3c];
#endif
    unsigned char actionState;
};

struct PartyMemberIdentifierPrefix {
#if defined(jpn)
    unsigned char unknown0[0x1a6];
#else
    unsigned char unknown0[0x1b2];
#endif
    unsigned short identifier;
};

// USA: func_02023d84
extern "C" ARM void func_02023d84(void *receiver, CombatActionPosition *entries, int count, int tileX, int tileY, int xOffset,
                                  int yOffset, int flags) {
    PartyDisplayReceiverPrefix *state = static_cast<PartyDisplayReceiverPrefix *>(receiver);
    if (!state->actionState) return;
    PartyIdentifierList identifiers = data_020e7064;
    unsigned char identifierCount   = 0;
    GameState *game                 = GameState::GetInstance();
    GameObject *protagonist         = game->GetProtagonist();
    if (!protagonist) return;
    FlagWord02046708 *word = static_cast<FlagWord02046708 *>(GetDataPtr02114e04_020d6c00());
    for (int partyIndex = 0; partyIndex < 4; partyIndex++) {
        GameObject *member = game->GetPartyMemberByIndex(partyIndex);
        if (!member) continue;
        unsigned short identifier = reinterpret_cast<PartyMemberIdentifierPrefix *>(member)->identifier;
        if (!identifier) continue;
        if (TestFlags02046708(word, 0x80000)) continue;
        if (protagonist->obj3D_.GetField06() != member->obj3D_.GetField06()) continue;
        bool unique = true;
        for (int index = 0; index < identifierCount; index++) {
            if (identifier == identifiers.values[index]) unique = false;
        }
        if (!unique) continue;
        identifiers.values[identifierCount] = identifier;
        identifierCount++;
        CombatActionPosition *entry = entries;
        for (int index = 0; index < count; index++, entry++) {
            if (partyIndex != entry->combatantId) continue;
            fix32_t scale = state->scale;
            int x         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.x, scale)) / 4096.0f) - tileX;
            int y         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.z, scale)) / 4096.0f) - tileY;
            if (flags) {
                y = -(static_cast<int>(static_cast<float>(FIX32_MULTIPLY(entry->position.y, scale)) / 4096.0f) - tileY);
            }
            SetElementFields0202756c(receiver, (x + xOffset - 1) << 12, (y + yOffset - 1) << 12, 8,
                                     static_cast<unsigned char>(partyIndex + 0x54), 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }
}
