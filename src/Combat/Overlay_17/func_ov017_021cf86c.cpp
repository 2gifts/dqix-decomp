#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct ListHead02046b60;
struct HeadNode02046b24;
struct S_020113e0;
struct GrottoPacket {
    char pad0[4]; unsigned short zone_; unsigned char mapState_;
    union {
        unsigned char flags_;
        struct { unsigned char active_ : 1; unsigned char unknown_ : 1; unsigned char refresh_ : 1; signed char player_ : 5; } bits_;
    } control_;
    unsigned char quality_; unsigned char level_; unsigned short seed_;
    unsigned short x_; unsigned short y_; unsigned short z_; unsigned char field12_;
    union { unsigned char raw_; struct { unsigned char rank_ : 4; unsigned char environment_ : 4; } bits_; } ranks_;
};
struct PendingGrotto {
    char pad0[0x39]; unsigned char pending_;
    unsigned short zone_; unsigned char mapState_; unsigned char flags_;
    unsigned char quality_; unsigned char level_; unsigned short seed_;
    short x_; short y_; short z_; unsigned char field48_; unsigned char ranks_;
};
struct GrottoOverlay {
    char pad0[0x36fc]; ListHead02046b60* list_;
    char pad3700[0x3ca4 - 0x3700]; PendingGrotto* pending_;
};
struct WorldSettings { char pad0[0x2664]; char grottoState_[4]; };
struct GrottoZoneStorage { char pad0[0xc]; int zone_; };
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" WorldSettings* func_02012fe4();
void* GetField0x3f8Address(GameState*);
int ListContainsId(ListHead02046b60*, int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void func_0208f748(void*, int);
void FillBits5cd0(S_020113e0*);
extern "C" int _Z17IsInRange0201b588i(int);

// USA: func_ov017_021cf86c
extern "C" ARM void func_ov017_021cf86c(void*, GrottoPacket* packet, GameState* state, GrottoOverlay* overlay, SearchStruct0202c1a4* search) {
    if (packet->control_.bits_.player_ >= 0 && GetSearchStructCurrentArrEntry(search) != packet->control_.bits_.player_) return;
    WorldSettings* settings = func_02012fe4();
    GrottoStruct* grotto;
    ListHead02046b60* list = overlay->list_;
    GetField0x3f8Address(state);
    grotto = state->GetGrottoStruct();
    if (ListContainsId(list, 0x4e)) {
        PendingGrotto* pending = overlay->pending_;
        pending->zone_ = packet->zone_;
        pending->mapState_ = packet->mapState_;
        pending->flags_ = packet->control_.flags_;
        pending->quality_ = packet->quality_;
        pending->level_ = packet->level_;
        pending->seed_ = packet->seed_;
        pending->x_ = packet->x_;
        pending->y_ = packet->y_;
        pending->z_ = packet->z_;
        pending->field48_ = packet->field12_;
        pending->ranks_ = packet->ranks_.raw_;
        pending->pending_ = 1;
    } else {
        ((GrottoZoneStorage*)grotto)->zone_ = packet->zone_;
        grotto->activeMapData.DiscoveryStateAndMapTypeAndUnknown = packet->mapState_;
        grotto->unknown_0[0] = packet->control_.bits_.active_ != 0;
        grotto->entranceX = (short)packet->x_ << 7;
        grotto->entranceY = (short)packet->y_ << 7;
        grotto->entranceZ = (short)packet->z_ << 7;
        grotto->activeMapData.QualityOrLegacyBossID = packet->quality_;
        grotto->activeMapData.LegacyBossLevel = packet->level_;
        grotto->activeMapData.SeedOrMinTurns = packet->seed_;
        grotto->activeStartingMonsterRank = packet->ranks_.bits_.rank_;
        grotto->activeEnviron = packet->ranks_.bits_.environment_;
        grotto->unknown_8 = packet->field12_;
        grotto->unknown_0[1] = 0;
    }
    if (grotto->unknown_0[0] && (grotto->activeMapData.GetDiscoveryState() == 2 || grotto->activeMapData.GetDiscoveryState() == 3)) {
        if (((GrottoZoneStorage*)grotto)->zone_ == state->GetProtagonist()->obj3D_.GetField06() && GetHeadNodeIdOrMinusOne((HeadNode02046b24**)list) != 10) {
            func_0208f748(settings->grottoState_, 0);
        }
    }
    if (grotto->unknown_0[0] && packet->control_.bits_.refresh_ && (grotto->activeMapData.GetDiscoveryState() == 2 || grotto->activeMapData.GetDiscoveryState() == 3)) FillBits5cd0((S_020113e0*)state);
    if (_Z17IsInRange0201b588i(state->GetPartyMemberByIndex(0)->obj3D_.GetField06()) && packet->control_.bits_.refresh_) FillBits5cd0((S_020113e0*)state);
}
