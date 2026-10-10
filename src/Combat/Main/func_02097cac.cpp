#include <globaldefs.h>
#include "GameState/GameState.h"

struct ZoneState { unsigned short zoneId; unsigned short previousZoneId; };
struct ZoneState02097cac {
    unsigned short zoneId;
    char pad0[0x63];
    unsigned char flag65;
};
struct Base020989cc {
    char pad0[0x1b3c];
    unsigned int progress;
};

extern "C" void* func_0202ae18();
extern "C" ZoneState* func_02012fe4();
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
extern "C" void* _Z28CallFunc0200fbb4AtField0x3f8Pv(void* obj, const void* src);
void* GetField0x3f8Address(GameState* battleStruct);
int IsIdInRange020981e4(int a, int id);
int IsIdInRange02098240(int a, int id);
int IsIdInSet02098210(int a, int id);
void UpdateRankLevel020989cc(Base020989cc* base);
void EnqueueEventTag186_021d3e3c(unsigned char tag);

#define FLAG130(obj) (*(int*)(*(void**)((char*)(obj) + 0x130)))

// USA: func_02097cac
extern "C" ARM void func_02097cac(Base020989cc* state) {
    void* search = func_0202ae18();
    GameState* gameState = GameState::GetInstance();
    ZoneState02097cac* zoneState = (ZoneState02097cac*)GetField0x3f8Address(gameState);
    ZoneState* currentZone = func_02012fe4();
    int zoneId = zoneState->zoneId;
    GameObject* protagonist;
    int previousZoneId = currentZone->zoneId;

    if (!IsIdInRange020981e4((int)state, zoneId) &&
        !IsIdInRange020981e4((int)state, previousZoneId)) return;

    protagonist = gameState->GetProtagonist();

    if (IsIdInSet02098210((int)state, zoneId) &&
        (!IsIdInSet02098210((int)state, previousZoneId) || zoneState->flag65 != 0)) {
        if (func_0202c508(search) != 0 && (FLAG130(protagonist) & 1) == 0) {
            UpdateRankLevel020989cc(state);
        }
        int progress = state->progress;
        EnqueueEventTag186_021d3e3c(progress);
        switch (progress) {
            case 1:
            case 2: zoneState->zoneId = 0xc3b5; break;
            case 3:
            case 4: zoneState->zoneId = 0xc419; break;
            case 5: zoneState->zoneId = 0xc47d; break;
            case 6: zoneState->zoneId = 0xc4e1; break;
        }
        _Z28CallFunc0200fbb4AtField0x3f8Pv(gameState, zoneState);
    } else {
        if (func_0202c540(search) == 0 || zoneState->flag65 == 0) return;
        int progress = state->progress;
        if (!IsIdInRange020981e4((int)state, zoneId)) return;
        if (IsIdInRange02098240((int)state, zoneId)) return;
        if (zoneId == 0xc3bb) return;
        if (zoneId == 0xc3bc) return;
        if (zoneId == 0xc3bd) return;
        if (zoneId == 0xc3be) return;
        int rem = zoneState->zoneId % 100;
        int base = rem + 0xc350;
        switch (progress) {
            case 1:
            case 2: zoneState->zoneId = (unsigned short)(base + 0x64); break;
            case 3:
            case 4: zoneState->zoneId = (unsigned short)(base + 0xc8); break;
            case 5: zoneState->zoneId = (unsigned short)(base + 0x12c); break;
            case 6: zoneState->zoneId = (unsigned short)(base + 0x190); break;
        }
    }
}
