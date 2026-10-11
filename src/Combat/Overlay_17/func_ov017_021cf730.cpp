#include <globaldefs.h>
#include "GameState/GameState.h"
struct GrottoPacket {
    unsigned short zone_; unsigned char mapState_;
    union {
        unsigned char flags_;
        struct { unsigned char active_ : 1; unsigned char unknown_ : 1; unsigned char refresh_ : 1; signed char player_ : 5; } bits_;
    } control_;
    unsigned char quality_; unsigned char level_; unsigned short seed_;
    unsigned short x_; unsigned short y_; unsigned short z_; signed char field12_;
    union { unsigned char raw_; struct { unsigned char rank_ : 4; unsigned char environment_ : 4; } bits_; } ranks_;
};

struct ZoneWord { char pad[0xc]; int zone; };
extern "C" int* func_0202ae18();
int CheckField0NonZero(int*);
extern "C" int func_0202c540(int*);
void* GetData02100044();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021cf730
// JPN: func_ov017_021cfbe0
extern "C" ARM void func_ov017_021cf730(signed char player, unsigned char refresh) {
    int* control = func_0202ae18();
    if (!CheckField0NonZero(control) || func_0202c540(control)) return;
    GameState* state = GameState::GetInstance();
    void* destination = GetData02100044();
    unsigned char buffer[0x14];
    GrottoPacket* packet = (GrottoPacket*)(buffer + 4);
    GrottoStruct* grotto = state->GetGrottoStruct();
    buffer[0] = 0xa0;
    packet->zone_ = ((ZoneWord*)grotto)->zone;
    packet->mapState_ = grotto->activeMapData.DiscoveryStateAndMapTypeAndUnknown;
    packet->control_.bits_.active_ = grotto->unknown_0[0] != 0;
    packet->control_.bits_.refresh_ = refresh;
    packet->x_ = grotto->entranceX >> 7;
    packet->y_ = grotto->entranceY >> 7;
    packet->z_ = grotto->entranceZ >> 7;
    packet->quality_ = grotto->activeMapData.QualityOrLegacyBossID;
    packet->level_ = grotto->activeMapData.LegacyBossLevel;
    packet->seed_ = grotto->activeMapData.SeedOrMinTurns;
    packet->ranks_.bits_.rank_ = grotto->activeStartingMonsterRank;
    packet->ranks_.bits_.environment_ = grotto->activeEnviron;
    packet->field12_ = *((signed char*)grotto + 8);
    packet->control_.bits_.player_ = player;
    func_0205e330(destination, buffer, 0);
}
