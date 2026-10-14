#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#if defined(jpn)
#include "Resource/MessageSystem.h"
#include "System/Memory.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02023218(MapDisplay* self, void* buffer, int offset, unsigned int capacity);
extern char data_020ef4b1[], data_020ef4c9[], data_020ef4d0[];
#endif
#include "Resource/GameResources.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254_0203b628(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

void InitSubScreenDisplay_020209d0(void* context);
void TailForward0203b66c(char* obj);
void InitSubObject0203bd78(char* obj);
void InitBattleContext0203bd24(char* obj);
void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
void DelayThenSyncBit0_020c9820(void);
#if defined(jpn)
void FinalizeRecordListDisplay02020cb8(void* self, int handle);
void RefreshRecordListDisplay02020e58(void* self, int handle);
#else
void FinalizeRecordListDisplay02020cb8(void* self, int* handle);
void RefreshRecordListDisplay02020e58(void* self, int* handle);
#endif
void CopyStringOrDefault02026428(void* obj, const char* name);
void SetEventStringAndAccumulateLength02026470(void* obj, int flag);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);
void InitStruct0205a444(char* obj);
struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);
void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
void* GetGlobalPtr02105244_0203bd14();
int InitAndCopyBuffer020233b8(void* arg0, int flag1);
extern "C" void* func_0203be4c(void);
void InitFourEntrySlots02020aa0(void* obj);
#if defined(jpn)
extern "C" void func_02026898(void* obj);
#else
extern "C" void func_02026f34(void* obj);
#endif
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_0202343c(void* obj);
void MarkActiveCombatantSlots02026b7c(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);
int FormatAndCopyNames02020b98(void* obj);

extern char data_020ef5c0[];
extern char data_020ef5d8[];
extern int data_020ef460;
extern char data_020ef5df[];

static inline SafeAllocator* GetAlloc02021b84(GameResources* axis, int i) {
    return &axis->allocator_array_38[i];
}

// USA: func_02021b84
extern "C" ARM void func_02021b84(MapDisplay* self) {
    char path[0x18];
    void* fileData;
    unsigned int fileLength;

    GameState* game;
    BackgroundLoader* loader;
    GameResources* axis;
    char* battleCtx;
    char* table;
    SafeAllocator* alloc;
    GrottoStruct* grotto;
    int state;

    game = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    func_02012fe4();
    axis = func_ov017_0218b5b0();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254_0203b628();
    alloc = GetAlloc02021b84(axis, 12);
    grotto = game->GetGrottoStruct();
    state = self->loadStage;

    if (state == 0) {
        func_02021428(self, 0x19);
        loader->AddFence();
        self->task9fc = loader->QueueLoadFile(
#if defined(jpn)
            data_020ef4b1,
#else
            data_020ef5c0,
#endif
            (SafeAllocator*)0);
        sprintf(path,
#if defined(jpn)
            data_020ef4c9,
#else
            data_020ef5d8,
#endif
            grotto->activeMapImageName);
        self->taska00 = loader->QueueLoadFileInGP2(

#if defined(jpn)
            *(const char**)&data_020ef460,
#else
            *(const char**)((char*)&data_020ef460 + 0xc),
#endif
            path, (SafeAllocator*)0);
        strcpy((char*)self->bytesa45, grotto->activeMapImageName);
        self->namesTask = FormatAndCopyNames02020b98(self);
        self->taska04 = loader->QueueLoadFile(
#if defined(jpn)
            data_020ef4d0,
#else
            data_020ef5df,
#endif
            (SafeAllocator*)0);
        self->loadStage = self->loadStage + 1;
    } else if (state == 1) {
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        if (loader->GetTaskStatus(self->task9fc) == 0) return;
        if (loader->GetTaskStatus(self->taska00) == 0) return;
        func_02020720(self);
        InitSubScreenDisplay_020209d0(self);
        alloc->Reset();
        TailForward0203b66c(table);
        InitSubObject0203bd78(battleCtx);
        InitBattleContext0203bd24(battleCtx);
        SetArraySlotFlag0203b718(table, 1, 0, 0);
        SetArraySlotFlag0203b718(table, 1, 1, 0);
        func_0203ba74(table);
        DelayThenSyncBit0_020c9820();
#if defined(jpn)
        FinalizeRecordListDisplay02020cb8(self, self->task9fc);
#else
        FinalizeRecordListDisplay02020cb8(self, &self->task9fc);
#endif
#if defined(jpn)
        RefreshRecordListDisplay02020e58(self, self->taska00);
#else
        RefreshRecordListDisplay02020e58(self, &self->taska00);
#endif
        self->loadStage = self->loadStage + 1;
    } else if (state == 2) {
        int status = loader->GetTaskStatus(self->namesTask);
        if (status == 0) return;
        if (status > 0) {
            func_02020c18(self,
#if defined(jpn)
                self->namesTask,
#else
                &self->namesTask,
#endif
                alloc);
        } else {
            BackgroundLoader::GetInstance()->RemoveTask(self->namesTask);
            self->namesTask = -1;
        }
        self->displayMode = 1;
        self->loadStage = self->loadStage + 1;
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->taska04) == 0) return;
 #if !defined(jpn)
        self->scriptNameWidth = 0;
        self->fieldb3c = 0;
        self->fieldb40 = 0;
        self->fieldb42 = 0;
#endif
        CopyStringOrDefault02026428(self, grotto->activeMapNameNoLevel);
        SetEventStringAndAccumulateLength02026470(self, grotto->activeMapLevel);
        strcpy((char*)self->bytesa55, grotto->activeMapNameNoLevel);
        self->fielda95 = grotto->activeMapLevel;
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(self->taska04, &fileData, &fileLength);
        for (int i = 0; i < 0x1c; i++) {
            Init0205a198(&self->records[i]);
        }
        InitStruct0205a444((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x18;
        ProcessRecords0205a498((char*)&self->entryList, (struct Rec020467f0*)fileData, fileLength, alloc);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        *(int*)((char*)GetGlobalPtr02105244_0203bd14() +
#if defined(jpn)
                0x608
#else
                0x508
#endif
        ) = 0x2000;
#if defined(jpn)
        MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
        char* buffer = messages->formatBuffer;
        char* vram = (char*)0x06600000;
        VectorizedInvertedMemcpy(vram + 0x2bc0, buffer, 0x540);
        func_02023218(self, buffer, 0, 0x540);
        DelayThenSyncBit0_020c9820();
        CleanInvalidateCacheRange(buffer, 0x540);
        LoadToSubObjVRAM(buffer, 0x2bc0, 0x540);
#else
        char* vram = (char*)0x06600000;
        memcpy(self->savedTiles, vram + 0x2c00, 0x40);
        InitAndCopyBuffer020233b8(self, 1);
#endif
        func_0203bd08();
        char* p = (char*)func_0203be4c() + 0x2e8;
        *(char**)GetGlobalPtr02105244_0203bd14() = p;
        BackgroundLoader::GetInstance()->RemoveTask(self->taska04);
        self->taska04 = -1;
        InitFourEntrySlots02020aa0(self);
#if defined(jpn)
        func_02026898(self);
#else
        func_02026f34(self);
#endif
        func_ov017_02191234(axis);
        self->field9c4 = 1;
        self->field9c8 = 0;
        self->field9c3 = 0;
        self->loadStage = self->loadStage + 1;
        DelayThenSyncBit0_020c9820();
        func_0202343c(self);
        MarkActiveCombatantSlots02026b7c((unsigned char*)self);
        func_02026bdc(self, 0);
    }
}
