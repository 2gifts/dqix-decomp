#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>

struct Struct0205a198 { char bytes[0x28]; };
struct Rec020467f0;
struct SetFlagStruct;
struct ToggleState;
struct AxisFloats0203b5a0;
struct Script020e081c {
    char pad_0[0x40];
    Struct0205a198* records;
    char pad_44[8];
    unsigned short count;
    char pad_4e[2];
    unsigned char active;
    char pad_51[3];
};
struct DisplayLoad020e081c {
    char pad_0[0x94];
    Script020e081c script;
    Struct0205a198 records[28];
    char pad_548[0x224];
    SafeAllocator* allocator;
    void* buffer;
    unsigned int bufferSize;
    char pad_778[0x24a];
    signed char stage;
    unsigned char active;
    char pad_9c4[0x38];
    int fileHandle;
    char pad_a00[8];
    int archiveHandle;
};
struct DisplayGlobal020e081c { void* display; char pad_4[0x504]; int width; };
struct BattleDisplay020e081c { char pad_0[0x258]; char display[1]; };

extern "C" void* func_02012fe4();
extern "C" char* func_0203bd08();
char* GetData02105254();
void SetFlag0x9c6(SetFlagStruct*, int);
extern "C" void func_02021428(void*, int);
void InitSubScreenDisplay(void*);
extern "C" void _Z19TailForward0203b66cPc(char*);
extern "C" void _Z25InitBattleContext0203bd24Pc(char*);
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198*);
extern "C" void _Z18InitStruct0205a444Pc(char*);
int IsAxisIntWithin16(AxisFloats0203b5a0*, int);
extern "C" void _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(void*, Rec020467f0*, int, void*);
DisplayGlobal020e081c* GetGlobalPtr02105244();
extern "C" BattleDisplay020e081c* func_0203be4c(char*);
extern "C" void func_020c9be0();
extern "C" void VectorizedInvertedMemcpy(void*, void*, int);
void DelayThenSyncBit0();
extern "C" void _Z33FinalizeRecordListDisplay02020cb8PvPi(void*, int*);
extern "C" void _Z21ReleaseHandle02022b90PvPi(void*, int*);
void SetToggleState(ToggleState*, int, int);
extern const char data_020f2b78[];
extern const char data_020f2b90[];
extern const char data_020f2ba2[];

// USA: func_020e081c
extern "C" ARM void func_020e081c(DisplayLoad020e081c* self) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_02012fe4();
    GameResources* axis = func_ov017_0218b5b0();
    char* battle = func_0203bd08();
    char* table = GetData02105254();
    SafeAllocator (&allocators)[17] = axis->allocator_array_38;
    SafeAllocator* allocator = &allocators[12];
    if (self->stage == 0) {
        SetFlag0x9c6((SetFlagStruct*)self, 0);
        func_02021428(self, 0x19);
        InitSubScreenDisplay(self);
        allocator->Reset();
        _Z19TailForward0203b66cPc(table);
        _Z25InitBattleContext0203bd24Pc(battle);
        for (int i = 0; i < 28; ++i) _Z12Init0205a198P14Struct0205a198(&self->records[i]);
        _Z18InitStruct0205a444Pc((char*)&self->script);
        self->script.active = 1;
        self->script.records = self->records;
        self->script.count = 5;
        loader->AddFence();
        self->fileHandle = loader->QueueLoadFile(data_020f2b78, 0);
        self->archiveHandle = loader->QueueLoadFileInGP2(data_020f2b90, data_020f2ba2, 0);
        ++self->stage;
    } else if (self->stage == 1) {
        if (!loader->GetTaskStatus(self->fileHandle)) return;
        if (!loader->GetTaskStatus(self->archiveHandle)) return;
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((AxisFloats0203b5a0*)axis, 1)) return;
        void* file = 0;
        unsigned int length = 0;
        loader->GetLoadedFileByID(self->archiveHandle, &file, &length);
        _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(&self->script, (Rec020467f0*)file, length, allocator);
        GetGlobalPtr02105244()->width = 0x2800;
        void* display = func_0203be4c(func_0203bd08())->display;
        GetGlobalPtr02105244()->display = display;
        if (!self->allocator) func_020c9be0();
        if (self->allocator && self->buffer) self->allocator->Free(self->buffer);
        self->bufferSize = 0x3400;
        self->buffer = self->allocator->Allocate(self->bufferSize);
        VectorizedInvertedMemcpy((void*)0x06600000, self->buffer, self->bufferSize);
        DelayThenSyncBit0();
        _Z33FinalizeRecordListDisplay02020cb8PvPi(self, &self->fileHandle);
        _Z21ReleaseHandle02022b90PvPi(self, &self->archiveHandle);
        SetToggleState((ToggleState*)self, 1, 3);
        self->active = 0;
        ++self->stage;
    }
}
