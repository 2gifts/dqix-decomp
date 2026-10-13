#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

extern "C" void func_02020720(char* obj);
void InitSubScreenDisplay(void* ctx);
extern "C" void _Z19TailForward0203b66cPc(char* obj);
extern "C" void _Z21InitSubObject0203bd78Pc(char* obj);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* obj);
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
void DelayThenSyncBit0(void);
void FinalizeRecordListDisplay02020cb8(void* self, int* handle);
void RefreshRecordListDisplay02020e58(void* self, int* handle);
extern "C" void func_02020c18(char* obj, int* handle, SafeAllocator* alloc);
void CopyStringOrDefault02026428(void* obj, const char* name);
void SetEventStringAndAccumulateLength02026470(void* obj, int flag);
struct Struct0205a198;
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
struct Rec020467f0;
extern "C" int _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(void* a, struct Rec020467f0* b, int flag, void* d);
extern "C" void _Z29SetBitfieldStoreBytes0205af38iPcii(int a, char* obj, int c, int d);
void* GetGlobalPtr02105244();
int InitAndCopyBuffer020233b8(void* arg0, int flag1);
extern "C" void* func_0203be4c(void);
extern "C" void _Z26InitFourEntrySlots02020aa0Pv(void* obj);
extern "C" void func_02026f34(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_0202343c(void* obj);
extern "C" void _Z32MarkActiveCombatantSlots02026b7cPh(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);
extern "C" int _Z26FormatAndCopyNames02020b98Pv(void* obj);

extern char data_020ef5c0;
extern char data_020ef5d8;
extern int data_020ef460;
extern char data_020ef5df;

struct AxisAllocs02021b84 {
    char pad[0x114];
    SafeAllocator allocs[2];
};

static inline SafeAllocator* GetAlloc02021b84(void* axis, int i) {
    return &((AxisAllocs02021b84*)axis)->allocs[i];
}

// USA: func_02021b84
extern "C" ARM void func_02021b84(char* self) {
    char path[0x18];
    void* fileData;
    unsigned int fileLength;

    GameState* game;
    BackgroundLoader* loader;
    char* axis;
    char* battleCtx;
    char* table;
    SafeAllocator* alloc;
    GrottoStruct* grotto;
    int state;

    game = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    func_02012fe4();
    axis = (char*)func_ov017_0218b5b0();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254();
    alloc = GetAlloc02021b84(axis, 1);
    grotto = game->GetGrottoStruct();
    state = *(signed char*)(self + 0x9c2);

    if (state == 0) {
        func_02021428(self, 0x19);
        loader->AddFence();
        *(int*)(self + 0x9fc) = loader->QueueLoadFile(&data_020ef5c0, (SafeAllocator*)0);
        sprintf(path, &data_020ef5d8, grotto->activeMapImageName);
        *(int*)(self + 0xa00) = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 0xc), path, (SafeAllocator*)0);
        strcpy(self + 0xa45, grotto->activeMapImageName);
        *(int*)(self + 0x9d0) = _Z26FormatAndCopyNames02020b98Pv(self);
        *(int*)(self + 0xa04) = loader->QueueLoadFile(&data_020ef5df, (SafeAllocator*)0);
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 1) {
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        if (loader->GetTaskStatus(*(int*)(self + 0x9fc)) == 0) return;
        if (loader->GetTaskStatus(*(int*)(self + 0xa00)) == 0) return;
        func_02020720(self);
        InitSubScreenDisplay(self);
        alloc->Reset();
        _Z19TailForward0203b66cPc(table);
        _Z21InitSubObject0203bd78Pc(battleCtx);
        _Z25InitBattleContext0203bd24Pc(battleCtx);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 0, 0);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 1, 0);
        func_0203ba74(table);
        DelayThenSyncBit0();
        FinalizeRecordListDisplay02020cb8(self, (int*)(self + 0x9fc));
        RefreshRecordListDisplay02020e58(self, (int*)(self + 0xa00));
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 2) {
        int status = loader->GetTaskStatus(*(int*)(self + 0x9d0));
        if (status == 0) return;
        if (status > 0) {
            func_02020c18(self, (int*)(self + 0x9d0), alloc);
        } else {
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0x9d0));
            *(int*)(self + 0x9d0) = -1;
        }
        *(int*)(self + 0x14) = 1;
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
    } else if (state == 3) {
        if (loader->GetTaskStatus(*(int*)(self + 0xa04)) == 0) return;
        *(int*)(self + 0xbe4) = 0;
        *(int*)(self + 0xbe8) = 0;
        *(short*)(self + 0xbec) = 0;
        *(short*)(self + 0xbee) = 0;
        CopyStringOrDefault02026428(self, grotto->activeMapNameNoLevel);
        SetEventStringAndAccumulateLength02026470(self, grotto->activeMapLevel);
        strcpy(self + 0xa55, grotto->activeMapNameNoLevel);
        *(unsigned char*)(self + 0xa95) = grotto->activeMapLevel;
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(*(int*)(self + 0xa04), &fileData, &fileLength);
        for (int i = 0; i < 0x1c; i++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)(self + 0xe8 + i * 0x28));
        }
        _Z18InitStruct0205a444Pc(self + 0x94);
        *(unsigned char*)(self + 0xe4) = 1;
        *(char**)(self + 0xd4) = self + 0xe8;
        *(unsigned short*)(self + 0xe0) = 0x18;
        _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(self + 0x94, (struct Rec020467f0*)fileData, fileLength, alloc);
        _Z29SetBitfieldStoreBytes0205af38iPcii((int)(self + 0x94), self + 0x250, 1, 1);
        _Z29SetBitfieldStoreBytes0205af38iPcii((int)(self + 0x94), self + 0x2a0, 1, 1);
        *(int*)((char*)GetGlobalPtr02105244() + 0x508) = 0x2000;
        char* vram = (char*)0x06600000;
        memcpy(self + 0xbf0, vram + 0x2c00, 0x40);
        InitAndCopyBuffer020233b8(self, 1);
        func_0203bd08();
        char* p = (char*)func_0203be4c() + 0x2e8;
        *(char**)GetGlobalPtr02105244() = p;
        BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa04));
        *(int*)(self + 0xa04) = -1;
        _Z26InitFourEntrySlots02020aa0Pv(self);
        func_02026f34(self);
        func_ov017_02191234(axis);
        *(unsigned char*)(self + 0x9c4) = 1;
        *(unsigned char*)(self + 0x9c8) = 0;
        *(unsigned char*)(self + 0x9c3) = 0;
        *(signed char*)(self + 0x9c2) = *(signed char*)(self + 0x9c2) + 1;
        DelayThenSyncBit0();
        func_0202343c(self);
        _Z32MarkActiveCombatantSlots02026b7cPh((unsigned char*)self);
        func_02026bdc(self, 0);
    }
}
