#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"

void PushInputLogA(int value);
int GetField0x3acValue(GameState* battleStruct);
extern "C" Zone3D* func_02012fe4(void);
extern "C" void func_ov004_0216fa08(void* node);
extern "C" void func_ov004_0216fa74(void* node, unsigned char value);
extern "C" int func_ov004_0216f990(int mode, int key, int flag);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void _Z19InitStruct_02196c08Ph(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* msg, int id);
extern "C" void func_ov017_021b7104(void* node, void* msg);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct NodeMsg {
    unsigned char kind;
    unsigned char actor;
    unsigned short id;
    unsigned short value;
    unsigned short f6;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char f13;
    int f14;
};

struct Work02196e58 {
    unsigned char pad0[0x36b6];
    unsigned short monsterIndex;
    unsigned char pad36b8[0x36fc - 0x36b8];
    struct TailList020469b4* list;
    unsigned char pad3700[0x3718 - 0x3700];
    struct TailNode020469b4* node;
    unsigned char pad371c[0x3b74 - 0x371c];
    struct TailNode020469b4* inputNode;
};

// USA: func_ov017_02196e58
extern "C" ARM void func_ov017_02196e58(struct Work02196e58* work) {
    GameState* bs = GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    GameObject* monster = bs->GetMaybeFieldMonsterByIndex(work->monsterIndex);
    if (monster == NULL) {
        return;
    }
    PushInputLogA(4);
    func_ov004_0216fa08(work->inputNode);
    *(unsigned short*)((unsigned char*)work->inputNode + 8) = work->monsterIndex;
    func_ov004_0216fa74(work->inputNode, 1);
    AppendNodeToTail(work->list, work->inputNode);
    func_ov017_021b6f18(work->node);

    struct NodeMsg msg;
    _Z19InitStruct_02196c08Ph((unsigned char*)&msg);
    msg.kind = 1;
    msg.actor = GetField0x3acValue(bs);
    msg.value = *(unsigned short*)((unsigned char*)monster + 0x16a);
    msg.id = work->monsterIndex;
    msg.f12 = lighting->timeOfDayIndex_;

    Zone3D* zone = func_02012fe4();
    ActiveGrottoClass* grotto = NULL;
    if (zone != NULL) {
        grotto = &zone->grotto_;
    }
    DetailedTreasureMapData* detail = NULL;
    if (grotto != NULL) {
        detail = grotto->GetDetailedData();
    }
    func_ov017_021b6e70(&msg, msg.id);
    if (msg.fc) {
        if (detail != NULL) {
            msg.f8 = func_ov004_0216f990(1, detail->regular_.bossMonsterID_, 0);
        }
    } else if (msg.fd && detail != NULL) {
        msg.f8 = func_ov004_0216f990(2, detail->legacy_.bossID_, detail->legacy_.stats_.alternateVersion);
    }
    func_ov017_021b7104(work->node, &msg);
    AppendNodeToTail(work->list, work->node);
}
