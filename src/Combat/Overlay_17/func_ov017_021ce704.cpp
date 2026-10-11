#include <globaldefs.h>
#include "GameState/GameState.h"

struct PackedStats {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int unused : 2;
};
struct StatBlock {
    char pad0[0x800];
    PackedStats values[3];
    unsigned int finalValue : 10;
};
#if defined(jpn)
struct PartyRegion { char pad0[4]; StatBlock stats; };
#else
struct PartyRegion { char pad0[0x1c]; StatBlock stats; };
#endif
#if defined(jpn)
struct PartyStats { char pad0[0x80]; PartyRegion region; };
#else
struct PartyStats { char pad0[0x100]; PartyRegion region; };
#endif
static inline PartyRegion* GetStatRegion(PartyStats* stats) { return &stats->region; }
static inline StatBlock* GetStatBlock(PartyRegion* region) { return &region->stats; }
struct StatsPayload {
    PackedStats values[3];
    unsigned int finalValue : 10;
    unsigned int partyIndex : 3;
};
struct StatsMessage { unsigned char type; unsigned char pad1[3]; unsigned int payload[4]; };
void* GetData02100044();
PartyStats* GetFieldAt0x150(unsigned char*);
extern "C" void func_0205e330(void*, void*, int);

// JPN: func_ov017_021cebac
// USA: func_ov017_021ce704
extern "C" ARM void func_ov017_021ce704(int index) {
    void* context = GetData02100044();
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), index);
    if (!combatant) return;
    PartyStats* stats = GetFieldAt0x150((unsigned char*)combatant);
    if (!stats) return;
    StatsMessage message;
    message.type = 0x12;
    StatsPayload* payload = (StatsPayload*)message.payload;
    payload->values[0].first = stats->region.stats.values[0].first;
    payload->values[0].second = stats->region.stats.values[0].second;
    payload->values[0].third = stats->region.stats.values[0].third;
    StatBlock* block = GetStatBlock(GetStatRegion(stats));
    payload->values[1].first = block->values[1].first;
    payload->values[1].second = block->values[1].second;
    payload->values[1].third = block->values[1].third;
    payload->values[2].first = block->values[2].first;
    payload->values[2].second = block->values[2].second;
    payload->values[2].third = block->values[2].third;
    payload->finalValue = block->finalValue;
    payload->partyIndex = index;
    func_0205e330(context, &message, 0);
}
