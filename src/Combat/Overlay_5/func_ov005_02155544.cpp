#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Main/BattleList.h>
#include <Resource/GameResources.h>

struct Field150Holder02052e14;

struct MemberScreen {
    char unk_0[R(0x4f8, 0x4fc)];
    int member_;
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    char unk_0[R(0x2d08, 0x2d90)];
    EquipmentSlot slots_[24];
};

extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
short* GetField150Ptr0x488(Field150Holder02052e14* obj);

extern "C" unsigned char data_ov005_0215cbd4[8];

// USA: func_ov005_02155544
extern "C" ARM void func_ov005_02155544(EquipmentMenu* self) {
    GameState* gameState = GameState::GetInstance();
    MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    GameObject* member = GetCombatantWithFlag0x100(gameState, screen->member_);
    short* equipment = GetField150Ptr0x488((Field150Holder02052e14*)member);
    for (int i = 0; i < 8; i++) {
        EquipmentSlot* slot = &self->slots_[i];
        slot->item_ = equipment[data_ov005_0215cbd4[i]];
        slot->count_ = 1;
    }
}
