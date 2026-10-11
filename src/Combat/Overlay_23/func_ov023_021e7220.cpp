#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" unsigned short GetSubObjVRAMBanks(void);

struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct InitTarget0205cfd4;
void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

struct Struct020dfc40;
extern void ResetStruct020dfc40(Struct020dfc40* p);

struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204c684(void*);

int GetField0x3acValue(GameState* battleStruct);

struct ShortBytePair021e71a0;
void ClearShortAndTwoBytes_021e71a0(struct ShortBytePair021e71a0* p);

// JPN: func_ov023_021e747c
// USA: func_ov023_021e7220  (semantic: InitBigCombatStruct_021e7220)
extern "C" ARM void func_ov023_021e7220(void* obj, int val) {
#if defined(jpn)
 enum {regionalOffset0=0x604};
#else
 enum {regionalOffset0=0x60e};
#endif
    ((SafeAllocator*)((char*)obj + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)((char*)obj + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)((char*)obj + 0x28))->ResetAllocatorPointer();
    GameState* battleStruct = GameState::GetInstance();
    *(int*)((char*)obj + 0x3c) = val;
    *(int*)((char*)obj + 0x40) = GetSubBGVRAMBanks();
    *(int*)((char*)obj + 0x44) = GetSubObjVRAMBanks();
    *(int*)((char*)obj + 0x48) = (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
    *(unsigned char*)((char*)obj + 0x74) = 0;
    *(unsigned char*)((char*)obj + 0x75) = 0;
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 0x64));
    InitStruct0205cfd4((struct InitTarget0205cfd4*)((char*)obj + 0x78));
    ResetStruct020dfc40((Struct020dfc40*)((char*)obj + 0x4c));
    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)((char*)obj + 0x134 + i * 0x20));
    }
    for (int i = 0; i < 5; i++) {
        func_0204c684((char*)obj + 0x174 + i * 0xe0);
    }
    *(int*)((char*)obj + 0x5d4) = 0;
    *(int*)((char*)obj + 0x5d8) = 0;
    *(int*)((char*)obj + 0x5dc) = 0;
    *(int*)((char*)obj + 0x5e0) = 0;
    *(int*)((char*)obj + 0x5e4) = -1;
    *(int*)((char*)obj + 0x5ec) = 0;
    *(int*)((char*)obj + 0x5e8) = 0;
    *(int*)((char*)obj + 0x5f0) = GetField0x3acValue(battleStruct);
    *(int*)((char*)obj + 0x5f4) = 0;
    *(int*)((char*)obj + 0x5f8) = 0;
    *(int*)((char*)obj + 0x5fc) = 0;
    *(int*)((char*)obj + 0x600) = 0;
#if !defined(jpn)
    *(int*)((char*)obj + 0x604) = 0;
    *(int*)((char*)obj + 0x608) = 0;
    *(unsigned char*)((char*)obj + 0x60c) = 0;
    *(unsigned char*)((char*)obj + 0x60d) = 0;
#endif
    ClearShortAndTwoBytes_021e71a0((struct ShortBytePair021e71a0*)((char*)obj + regionalOffset0));
}
