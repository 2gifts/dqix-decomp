#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern "C" void func_02022da0(void*);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "World/Zone3D.h"
#include "Combat/MapDisplay.h"

extern "C" Zone3D* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254_0203b628(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

extern "C" int func_020420e8(void* p, int flag);

void TailForward0203b66c(char* obj);
void InitSubObject0203bd78(char* obj);
void InitBattleContext0203bd24(char* obj);
void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);
void InitStruct0205a444(char* obj);

int FormatAndCopyNames02020b98(void* obj);
void ClearRecords02026644(char* obj);
#if defined(jpn)
extern "C" void func_020211b0(char* obj, int handle);
#else
extern "C" void func_020211b0(char* obj, int* handle);
#endif
#if defined(jpn)
#else
#endif
int InitAndCopyBuffer02023330(void* obj, int flag);
void InitFourEntrySlots02020aa0(void* obj);
#if defined(jpn)
extern "C" void func_02020fc4(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void func_02020fc4(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void func_020210f8(char* obj, int* handle, SafeAllocator* alloc);
extern "C" void func_0202445c(void* obj);
extern "C" void func_ov017_02191234(void* obj);
void DelayThenSyncBit0_020c9820(void);
extern "C" void func_0202343c(void* obj);
void MarkActiveCombatantSlots02026b7c(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);

extern const char* data_020ef460[];
extern char data_020ef598;
extern char data_020ef5a5;
extern Script::OpcodeLookupEntry data_020ef4e8[];
extern char data_020ef5b9;

static inline SafeAllocator* GetResourceAllocator(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// USA: func_02021578
extern "C" ARM void func_02021578(MapDisplay* self) {
    void* fileData;
    unsigned int fileLength;
    char buf[0x40];
    Script script;

    BackgroundLoader* loader;
    GameResources* axis;
    int i0;
    int i1;
    int i2;
    Zone3D_StructPtr_8* modes;
    char* battleCtx;
    char* table;
    SafeAllocator* alloc;
    int state;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    modes = func_02012fe4()->pUnknownStruct_8_;
    axis = func_ov017_0218b5b0();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254_0203b628();
    state = self->loadStage;
    alloc = GetResourceAllocator(axis, 12);

    if (state == 0) {
        self->failed = 0;
        func_02021428(self, 0x19);
#if !defined(jpn)
        loader->AddFence();
        self->scriptTask = loader->QueueLoadFileInGP2(
            data_020ef460[1],
            data_020ef460[0], (SafeAllocator*)0);
#endif
        loader->AddFence();
        self->namesTask = FormatAndCopyNames02020b98(self);
        self->fileTask984 = loader->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)],
            &data_020ef598, (SafeAllocator*)0);
        self->fileTask920 = loader->QueueLoadFile(&data_020ef5a5, (SafeAllocator*)0);
        self->loadStage = self->loadStage + 1;
#if !defined(jpn)
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->scriptTask) == 0) return;
        VectorizedMemset(self->scriptName, 0, 0x40);
        data_020fdc4c.nameOverride = 0;
        self->scriptNameWidth = 0;
        self->fieldb3c = 0;
        self->fieldb40 = 0;
        self->fieldb42 = 0;
        loader->GetLoadedFileByID(self->scriptTask, &fileData, &fileLength);
        script.Initialize();
        script.SetOpcodeLookup(data_020ef4e8);
        script.Load(fileData, fileLength);
        script.Execute();
        const char* name = data_020fdc4c.nameOverride;
        if (name != 0) {
            memcpy(self->scriptName, name, strlen(name));
            self->scriptNameWidth = func_020420e8(self->scriptName, 0);
        }
        BackgroundLoader::GetInstance()->RemoveTask(self->scriptTask);
        self->scriptTask = -1;
        self->loadStage = self->loadStage + 1;
#endif
    } else if (state == REGION_VALUE(1, 2)) {
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        func_02020720(self);
        func_02020838(self);
        TailForward0203b66c(table);
        alloc->Reset();
        InitSubObject0203bd78(battleCtx);
        InitBattleContext0203bd24(battleCtx);
        SetArraySlotFlag0203b718(table, 1, 0, 0);
        SetArraySlotFlag0203b718(table, 1, 1, 0);
        func_0203ba74(table);
        for (i0 = 0; i0 < 0x1c; i0++) {
            Init0205a198(&self->records[i0]);
        }
        InitStruct0205a444((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x1c;
        int mode = modes->unknown_c_low_;
        if (mode == 0) {
            self->displayMode = 3;
        } else if (mode == 7) {
            self->displayMode = 1;
        } else {
            self->displayMode = 0;
        }
        self->loadStage = self->loadStage + 1;
#if defined(jpn)
    }
    if (self->loadStage == 2) {
#else
    } else if (state == 3) {
#endif
        int status = loader->GetTaskStatus(self->namesTask);
        if (status == 0) return;
        self->nameCount = 0;
        self->forwardingCount = 0;
        if (status == -1) {
            self->loadStage = 0x64;
            BackgroundLoader::GetInstance()->RemoveTask(self->namesTask);
            self->namesTask = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->fileTask984);
            self->fileTask984 = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->fileTask920);
            self->fileTask920 = -1;
            self->failed = 1;
            return;
        }
#if defined(jpn)
        func_02020c18(self, self->namesTask, alloc);
#else
        func_02020c18(self, &self->namesTask, alloc);
#endif
        if (self->refreshRecords != 0) {
            self->field9b8 = 1;
            self->field9b9 = 0;
            ClearRecords02026644((char*)self);
        }
        loader->AddFence();
        sprintf(buf, &data_020ef5b9, self->name);
        self->fileTask928 = loader->QueueLoadFileInGP2(
            data_020ef460[REGION_VALUE(1, 2)], buf, (SafeAllocator*)0);
        for (i1 = 0; i1 < self->nameCount; i1++) {
            sprintf(buf, &data_020ef5b9,
                    (self->names)[i1].name);
            self->nameTasks[i1] = loader->QueueLoadFileInGP2(
                data_020ef460[REGION_VALUE(1, 2)], buf, (SafeAllocator*)0);
        }
        self->loadStage = self->loadStage + 1;
    }

    if (self->loadStage == REGION_VALUE(3, 4)) {
        if (loader->GetTaskStatus(self->fileTask984) == 0) return;
#if defined(jpn)
        func_020211b0((char*)self, self->fileTask984);
#else
        func_020211b0((char*)self, &self->fileTask984);
#endif
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(4, 5)) {
        if (loader->GetTaskStatus(self->fileTask920) == 0) return;
#if defined(jpn)
        func_02020aec(self, self->fileTask920, alloc);
#else
        func_02020aec(self, &self->fileTask920, alloc);
#endif
#if defined(jpn)
        func_02022da0(self);
#else
        char* vram = (char*)0x6600000;
        memcpy(self->savedTiles, vram + 0x2c20, 0x40);
        InitAndCopyBuffer02023330(self, 1);
#endif
        InitFourEntrySlots02020aa0(self);
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(5, 6)) {
        if (loader->GetTaskStatus(self->fileTask928) == 0) return;
#if defined(jpn)
        func_02020fc4((char*)self, self->fileTask928, alloc);
#else
        func_02020fc4((char*)self, &self->fileTask928, alloc);
#endif
        self->loadStage = self->loadStage + 1;
    }
    if (self->loadStage == REGION_VALUE(6, 7)) {
        for (i2 = 0; i2 < self->nameCount; i2++) {
            if (loader->GetTaskStatus(self->nameTasks[i2]) == 0) return;
        }
        func_020210f8((char*)self, self->nameTasks, alloc);
        func_0202445c(self);
        func_ov017_02191234(axis);
        self->forwardingPending = 1;
        self->field9c4 = 1;
        self->field9c8 = 0;
        self->field9c3 = 0;
        self->loadStage = self->loadStage + 1;
        DelayThenSyncBit0_020c9820();
        func_0202343c(self);
        func_0202445c(self);
        MarkActiveCombatantSlots02026b7c((unsigned char*)self);
        func_02026bdc(self, 0);
    }
}
