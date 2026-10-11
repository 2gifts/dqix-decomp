#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

void ProcessCombatState020534ac(char* combatant);
int GetIntField0x260(void* obj);
int GetField0x3acValue(GameState* gameState);
int GetIndexedEntryField0x178(signed char* obj);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
void FillEntriesEncoded_02199684(Entry_02199684* arr, int count, int value);
void ClearAndEncodeEntries_021996bc(Entry_02199684* arr, int count);

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc*);

struct Elem_0205d81c {
    char pad0[0xA8];
    short w;
    short h;
    short x;
    short y;
};
struct Struct_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);

struct TileMap0204bc74;
extern "C" void func_0204bc74(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);

// JPN: func_ov017_0219ad34
// USA: func_ov017_0219a18c
extern "C" ARM void func_ov017_0219a18c(unsigned char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x3e60, regionalOffset1=0x3e54, regionalOffset2=0x3e58, regionalOffset3=0x294, regionalOffset4=0x3800, regionalOffset5=0xa90};
#else
 enum {regionalOffset0=0x4080, regionalOffset1=0x4074, regionalOffset2=0x4078, regionalOffset3=0xb4, regionalOffset4=0x3c00, regionalOffset5=0xcb0};
#endif
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), i);
        if (combatant != 0) {
            ProcessCombatState020534ac((char*)combatant);
        }
    }

    if (*(int*)(self + (regionalOffset0)) == 0 || *(int*)(self + (regionalOffset1)) == 0) {
        return;
    }
    if (*(int*)(self + (regionalOffset2)) < 4) {
        return;
    }

    GameState* gs = GameState::GetInstance();
    if (GetIntField0x260(gs->GetUnknownGameObject()) != -1) {
        return;
    }

    FillEntriesEncoded_02199684((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
    ClearBuffers0204b010OverList0x98(*(Cont0205d1e0**)(self + 0x3000 + regionalOffset5));
    CallFunc0204c8f0OverList0x9c(*(Cont0205d228**)(self + 0x3000 + regionalOffset5));
    func_0205da88(*(void**)(self + 0x3000 + regionalOffset5), 1, 2, 1);

    GameObject* protagonist = gs->GetProtagonist();
    GameObject* combatant = GetCombatantWithFlag0x100(gs, GetField0x3acValue(gs));
    int found = 0;
    int key;
    int mode = GetIntField0x260(protagonist);
    int entry = GetIndexedEntryField0x178((signed char*)combatant);
    switch (mode) {
    case -1:
        break;
    case 0:
        found = 1;
        key = 0;
        break;
    case 1:
        found = 1;
        key = 1;
        break;
    case 2:
        found = 1;
        key = 2;
        break;
    case 3:
        found = 1;
        key = 3;
        break;
    }

    if (found && entry >= 0) {
        Elem_0205d81c* elem = FindElementByC40205d81c(*(Struct_0205d81c**)(self + 0x3000 + regionalOffset5), key);
        if (elem != 0) {
            func_0204bc74((TileMap0204bc74*)(self + regionalOffset3 + regionalOffset4), 1, elem->x, elem->y, elem->w, elem->h, 0xf);
        }
    }

    CallFunc0204b04cOverList0x98(*(Cont0205d274**)(self + 0x3000 + regionalOffset5));
    if (GetBitsInField4((unsigned int*)self, 0x10000) == 0) {
        InitEntries0205d2bc(*(Obj0205d2bc**)(self + 0x3000 + regionalOffset5));
    }
    ClearAndEncodeEntries_021996bc((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2);
}
