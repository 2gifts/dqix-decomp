#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x244
#define REGION_OFFSET_1 0x2ac
#define REGION_OFFSET_2 0x3400
#define REGION_OFFSET_3 0x21c
#define REGION_OFFSET_4 0x288
#else
#define REGION_OFFSET_0 0x2c8
#define REGION_OFFSET_1 0x6f0
#define REGION_OFFSET_2 0x3000
#define REGION_OFFSET_3 0x2a0
#define REGION_OFFSET_4 0x2ec
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "System/Timing.h"

extern "C" void func_0202ae18(void);
void InitStruct02013718(char* obj, int a, int b);
extern "C" void func_02012fe4(void);
int IsField0xcNonNegative(int* obj);
void* GetPtrField0x468(void* obj);
struct SearchEntry;
struct SearchTable;
struct SearchEntry* FindEntryByHalfwordKey(struct SearchTable* table, int key);
extern "C" void _ZN6Zone3D10SwitchZoneEt(void* g, int val, int flag);
extern "C" void func_02012de8(void);
struct Obj0202fa00;
extern "C" void func_02015438(void* p);
void BlankFunction020d84f4(void);
void SetCombatWorkFlags0x55f4(void* work, int mask);

// USA: func_ov000_02166880
ARM void InitAndProcessCombat02166880(unsigned char* obj) {
    ((int)func_ov017_0218b5b0());
    GameState* battle = GameState::GetInstance();
    struct Obj0202fa00* fieldObj = (struct Obj0202fa00*)(int)BackgroundLoader::GetInstance();
    battle->GetProtagonist();
    func_0202ae18();
    InitStruct02013718((char*)(obj + REGION_OFFSET_0 + 0xc00), (int)(obj + 8), (int)(obj + REGION_OFFSET_1 + REGION_OFFSET_2));
    func_02012fe4();

    if (IsField0xcNonNegative(*(int**)(obj + REGION_OFFSET_3))) {
        unsigned short v = *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 0x20);
        if (v != 0) *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) = v;
    }

    void* table = GetPtrField0x468(battle);
    struct SearchEntry* entry = FindEntryByHalfwordKey((struct SearchTable*)table,
        *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2));
    if (entry == NULL || *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) == 30000) {
        *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2) = 0x75a4;
    }
    _ZN6Zone3D10SwitchZoneEt(obj + REGION_OFFSET_0 + 0xc00, *(unsigned short*)((char*)*(int**)(obj + REGION_OFFSET_3) + 2), 0);

    GetCurrentTimestamp();
    for (;;) {
        func_02012de8();
        ((BackgroundLoader*)(fieldObj))->RemoveAllLocks();
        func_02015438(obj + REGION_OFFSET_0 + 0xc00);
        if (*(int*)(obj + 0x1000 + REGION_OFFSET_4) == 0) break;
        BlankFunction020d84f4();
    }
    SetCombatWorkFlags0x55f4(obj, 0x10);
}
