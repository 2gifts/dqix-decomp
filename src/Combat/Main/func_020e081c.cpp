#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "System/Memory.h"

#if defined(jpn)
enum { kBackupAllocator = 0x6c0, kBackupBuffer = 0x6c4, kBackupSize = 0x6c8,
       kStage = 0x916, kActive = 0x917, kBaseTask = 0x950, kObjectTask = 0x95c,
       kBackupBytes = 0x2500, kDisplay = 0x200, kDisplayWidth = 0x608 };
#define data_020f2b78 data_020f2cd0
extern const char data_020f2ce8[];
#else
enum { kBackupAllocator = 0x76c, kBackupBuffer = 0x770, kBackupSize = 0x774,
       kStage = 0x9c2, kActive = 0x9c3, kBaseTask = 0x9fc, kObjectTask = 0xa08,
       kBackupBytes = 0x3400, kDisplay = 0x258, kDisplayWidth = 0x508 };
extern const char data_020f2b90[];
extern const char data_020f2ba2[];
#endif

struct Struct0205a198 { char bytes[0x28]; };
struct Rec020467f0;
struct SetFlagStruct;
struct ToggleState;
struct AxisFloats0203b5a0;
struct Script020e081c {
    char unknown0[0x40];
    Struct0205a198* records;
    char unknown44[8];
    unsigned short count;
    char unknown4e[2];
    unsigned char active;
    char unknown51[3];
};

extern "C" void* func_02012fe4();
extern "C" char* func_0203bd08();
char* GetData02105254();
void SetFlag0x9c6(SetFlagStruct*, int);
extern "C" void func_02021428(void*, int);
void InitSubScreenDisplay(void* context);
void TailForward0203b66c(char*);
void InitBattleContext0203bd24(char*);
void Init0205a198(Struct0205a198*);
void InitStruct0205a444(char*);
int IsAxisIntWithin16(AxisFloats0203b5a0*, int);
int ProcessRecords0205a498(void*, Rec020467f0*, int, void*);
void* GetGlobalPtr02105244();
extern "C" void* func_0203be4c(char*);
extern "C" void func_020c9be0();
void DelayThenSyncBit0();
#if defined(jpn)
void FinalizeRecordListDisplay02020cb8(void*, int);
#else
void FinalizeRecordListDisplay02020cb8(void*, int*);
#endif
void ReleaseHandle02022b90(void*, int*);
void SetToggleState(ToggleState*, int, int);
extern const char data_020f2b78[];

static inline SafeAllocator* GetResourceAllocator(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// KEEP-NAME: func_020e081c is the shared regional export.
// USA: func_020e081c
extern "C" ARM void func_020e081c(char* self) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_02012fe4();
    GameResources* resources = func_ov017_0218b5b0();
    char* battle = func_0203bd08();
    char* table = GetData02105254();
    SafeAllocator* allocator = GetResourceAllocator(resources, 12);
    if (*(signed char*)(self + kStage) == 0) {
        SetFlag0x9c6((SetFlagStruct*)self, 0);
        func_02021428(self, 0x19);
        InitSubScreenDisplay(self);
        allocator->Reset();
        TailForward0203b66c(table);
        InitBattleContext0203bd24(battle);
        for (int i = 0; i < 28; ++i)
            Init0205a198(&((Struct0205a198*)(self + 0xe8))[i]);
        InitStruct0205a444(self + 0x94);
        Script020e081c* script = (Script020e081c*)(self + 0x94);
        script->active = 1;
        script->records = (Struct0205a198*)(self + 0xe8);
        script->count = 5;
        loader->AddFence();
        *(int*)(self + kBaseTask) = loader->QueueLoadFile(data_020f2b78, 0);
#if defined(jpn)
        *(int*)(self + kObjectTask) = loader->QueueLoadFile(data_020f2ce8, 0);
#else
        *(int*)(self + kObjectTask) = loader->QueueLoadFileInGP2(data_020f2b90, data_020f2ba2, 0);
#endif
        ++*(signed char*)(self + kStage);
    } else if (*(signed char*)(self + kStage) == 1) {
        if (!loader->GetTaskStatus(*(int*)(self + kBaseTask))) return;
        if (!loader->GetTaskStatus(*(int*)(self + kObjectTask))) return;
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((AxisFloats0203b5a0*)resources, 1)) return;
        void* file = 0;
        unsigned int length = 0;
        loader->GetLoadedFileByID(*(int*)(self + kObjectTask), &file, &length);
        ProcessRecords0205a498(self + 0x94, (Rec020467f0*)file, length, allocator);
        *(int*)((char*)GetGlobalPtr02105244() + kDisplayWidth) = 0x2800;
        void* display = (char*)func_0203be4c(func_0203bd08()) + kDisplay;
        *(void**)GetGlobalPtr02105244() = display;
        if (!*(SafeAllocator**)(self + kBackupAllocator)) func_020c9be0();
        if (*(SafeAllocator**)(self + kBackupAllocator) && *(void**)(self + kBackupBuffer))
            (*(SafeAllocator**)(self + kBackupAllocator))->Free(*(void**)(self + kBackupBuffer));
        *(unsigned int*)(self + kBackupSize) = kBackupBytes;
        *(void**)(self + kBackupBuffer) = (*(SafeAllocator**)(self + kBackupAllocator))->Allocate(*(unsigned int*)(self + kBackupSize));
        VectorizedInvertedMemcpy((const void*)0x06600000, *(void**)(self + kBackupBuffer), *(unsigned int*)(self + kBackupSize));
        DelayThenSyncBit0();
#if defined(jpn)
        FinalizeRecordListDisplay02020cb8(self, *(int*)(self + kBaseTask));
#else
        FinalizeRecordListDisplay02020cb8(self, (int*)(self + kBaseTask));
#endif
        ReleaseHandle02022b90(self, (int*)(self + kObjectTask));
        SetToggleState((ToggleState*)self, 1, 3);
        *(unsigned char*)(self + kActive) = 0;
        ++*(signed char*)(self + kStage);
    }
}
