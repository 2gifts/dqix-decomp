#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"
#include "World/ZoneLootableRecord.h"

GameResources* GetWord0x0(int* gameState);
void ClearCombatWorkFlags0x55f4(void* work, int mask);
void SetCombatWorkFlags0x55f4(void* work, int mask);
int GetCombatWorkFlags0x55f4(void* work, int mask);
void ResetBigStruct02013750(void* obj, int flag);
extern "C" void func_ov000_02172720(void* obj);
char* GetData02108e10(void);
void ClearTwoRegions02079f9c(char* obj);
struct Obj020d6f0c;
struct Container020d6d18;
void DestroyAllocatorAt0xa28(struct Obj020d6f0c* self);
void ConstructEntryManager020d6d18(struct Container020d6d18* self);
extern "C" void* func_02057924(void);
extern "C" void func_02057f00(void* self, int code);
extern "C" void func_ov017_021a05a8(GameResources* res);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
extern "C" void* func_0205ec34(void);
extern "C" unsigned short* func_02012fe4(void);
struct SearchTable;
struct SearchEntry;
struct SearchTable* GetPtrField0x468(void* obj);
struct SearchEntry* FindEntryByHalfwordKey(struct SearchTable* table, int key);
extern "C" void func_0206461c(void* a, struct SearchEntry* b);
void SetFieldsAndSignalData02184220(void* p, int val);

extern int data_ov000_0218321c[];

struct BattleScene0216873c {
    int bgLayers;
    char pad_4[4];
    SafeAllocator heaps[5];
    char pad_6c[0xea4 - 0x6c];
    struct Container020d6d18* entryManager;
    int state;
    int step;
    char pad_eb0[0xec8 - 0xeb0];
    char bigStruct[0x3760 - 0xec8];
    char field_0x3760[0x5600 - 0x3760];
    Foo02048004 model0;
    Foo02048004 model1;
    char pad_5710[0x774c - 0x5710];
    SafeAllocator heap;
};

// USA: func_ov000_0216873c
extern "C" ARM void func_ov000_0216873c(struct BattleScene0216873c* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetWord0x0((int*)gs);
    if (scene->step == 0) {
        SetBrightness(res, -16, 15);
        scene->step++;
        return;
    }
    if (IsBrightnessTransitionActive(res)) {
        return;
    }
    ClearCombatWorkFlags0x55f4(scene, 0x200);
    ResetBigStruct02013750(scene->bigStruct, 1);
    func_ov000_02172720(scene->field_0x3760);
    SetCombatWorkFlags0x55f4(scene, 0x800);
    ClearTwoRegions02079f9c(GetData02108e10());
    MaybeInvoke0204719c(&scene->model0);
    MaybeInvoke0204719c(&scene->model1);
    if (scene->entryManager != 0) {
        DestroyAllocatorAt0xa28((struct Obj020d6f0c*)scene->entryManager);
        ConstructEntryManager020d6d18(scene->entryManager);
        scene->entryManager = 0;
    }
    void* combat = func_02057924();
    for (int* code = data_ov000_0218321c; *code >= 0; code++) {
        func_02057f00(combat, *code);
    }
    scene->heap.Destroy();
    for (int i = 0; i < 5; i++) {
        scene->heaps[i].Destroy();
    }
    if (GetCombatWorkFlags0x55f4(scene, 1)) {
        func_ov017_021a05a8(res);
    }
    func_ov017_0219b624(res);
    func_ov017_0219ba0c(res, 0);
    void* target = func_0205ec34();
    unsigned short* key = func_02012fe4();
    func_0206461c(target, FindEntryByHalfwordKey(GetPtrField0x468(gs), *key));
    if (scene->bgLayers != 0) {
        DISPCNT = (DISPCNT & ~0x1f00) | (scene->bgLayers << 8);
    }
    SetFieldsAndSignalData02184220(scene, 6);
}
