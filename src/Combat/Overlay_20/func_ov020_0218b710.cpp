#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct FieldGroup4e8_0218d7ac;
struct FieldGroup4f4_0218d800;
struct InitTarget0205cfd4;
struct List0204af64;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Cont0205d228;
struct Cont0205d274;
struct Obj0205d2bc;
struct Foo0207df50;
struct CombatSlots02045cac;
struct Struct_0205bcdc;
struct Obj_0205e8ec;
struct Actor0209c3b4;
struct Obj0203bdb0;
struct AllocGroup0218d8d8;

void DelayThenSyncBit0();
void EncodeSignFlaggedHalfword(short* out, int value);
int GetWord0x7f6c(void* obj);
void SetWord0x7f6c(void* obj, int value);
unsigned char GetByte0x4(char* obj);
void SetByte0x4(char* obj, unsigned char value);
void SetByte0x7f70(void* obj, unsigned char value);
void RestoreDisplayMode();
void UpdateFieldGroup4e8_0218d7ac(FieldGroup4e8_0218d7ac* obj, int target, int frames);
void UpdateFieldGroup4f4_0218d800(FieldGroup4f4_0218d800* obj, int target, int frames);
void WriteControlAndToggle020d86d0(int a, int b);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void InitStruct0205cfd4(InitTarget0205cfd4* obj);
void ResetList0204af64(List0204af64* list);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* obj, SafeAllocator* alloc);
void DispatchViaTable0204b5e8(Obj0204b5e8* obj, int a, int b);
int CountActiveEntries(ActiveEntry02046900* entries);
void* FindRecordByIndex(Rec020467f0* recs, int index, void** outField, int* outSize);
void FlushAndDispatchList0204b0e8(List0204b0e8* list, void* arg);
void AllocateBuffer0204c7a8(Obj0204c7a8* obj, SafeAllocator* alloc, int buf, unsigned int size);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* obj, Elem_0205cf78* elems, unsigned char flag);
char* GetGlobalField0x1c020421a0();
int AppendXYTag(char* text, int x, int y);
int AppendString02042058(char* text, const char* str);
int AppendDotLeaderLabel02042084(char* text, char* label, int width, int flags);
void CallFunc0204c8f0OverList0x9c(Cont0205d228* obj);
void CallFunc0204b04cOverList0x98(Cont0205d274* obj);
void InitEntries0205d2bc(Obj0205d2bc* obj);
void ProcessRingJobs020bbcb4();
void InitCombatSubsystems02012efc();
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
void LockStagedTextureVRAMCopying();
void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
void InitGlobalStateAndInstallHandlers020bb780(void* arg, int flag);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void TailForward020440a4(void* obj);
void CopyInternalFields0207df50(Foo0207df50* obj);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
void InitCombatSlots02045cac(CombatSlots02045cac* slots);
void InitBigStruct0205c790(char* obj);
int CheckSaveBufferStatus(int flag);
void ProcessCombatEntry0205cb74(char* obj, int entry);
void Forward0204359c(void* obj, int value);
void SetIndexIfValid0205bcdc(Struct_0205bcdc* obj, int index);
void InitBattleContext0203bd24(char* ctx);
void RefreshDisplayState0205e8ec(Obj_0205e8ec* obj);
void SetStateAndDispatch0209c3b4(Actor0209c3b4* actor, int state);
void ResetGxEngineState020c52e8();
extern "C" void _Z33CleanInvalidateOamBuffers0203bd88v(char* ctx);
void SyncMainSubOam0203bdb0(Obj0203bdb0* obj);
void ResetAllocatorAndDispatchState_0218d8d8(AllocGroup0218d8d8* obj);

extern "C" int func_ov020_0218d898(void* obj);
extern "C" void func_ov020_0218d644(void* obj);
extern "C" void func_ov020_0218d854(void* obj);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void func_ov020_0218cd98(void* obj);
extern "C" void func_ov020_0218cf8c(void* obj);
extern "C" void func_ov020_0218d32c(void* obj, int mode);
extern "C" void func_ov020_0218c98c(void* obj);
extern "C" void func_ov020_0218c7f0(char* obj, int a, int count);
extern "C" void func_ov020_0218c840(void* obj);
extern "C" void func_0204c684(void* obj);
extern "C" void func_0204b5b4(void* obj, int a);
extern "C" void func_0204b174(void* list, void* rec, SafeAllocator* alloc, int size);
extern "C" void func_0204bc74(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void func_0205d304(void* obj, char* text, int, int, int, int, int, int);
extern "C" void func_0205d0e0(void* obj, int a);
extern "C" void func_0207de48(void* obj, int a, int b);
extern "C" void func_02042c68(char* g);
extern "C" void func_02043124(char* g);
extern "C" void func_020432c4(char* g);
extern "C" void func_0205cc50(void* obj, int a, int b);
extern "C" void func_0205bb04(void* obj, int a);
extern "C" void func_02043368(char* g);
extern "C" void func_020439b0(char* g, int a);
extern "C" char* func_0203bd08(void);
extern "C" void func_020c5414(void);
extern "C" void func_020bbd9c(void);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void MapVRAMBanksToMainObj(int);
extern "C" void MapVRAMBanksToTextureImage(int);
extern "C" void MapVRAMBanksToTexturePalette(int);

extern AllocatorUnion data_02114e20;
extern unsigned short data_02114e30;
extern unsigned char data_02114e54[];
extern char data_02108760[];
extern char data_02109bf4[];
extern char data_ov020_0218dbdc[];
extern char data_ov020_0218dbef[];
extern char data_ov020_0218dbf5[];
extern char data_ov020_0218dbfc[];
extern char data_ov020_0218dc08[];
extern char data_ov020_0218dc1b[];
extern char data_ov020_0218dc2b[];
extern char data_ov020_0218dc3f[];
extern char data_ov020_0218dc55[];
extern char data_ov020_0218dc65[];
extern char data_ov020_0218dc72[];
extern char data_ov020_0218dc82[];
extern char data_ov020_0218dc91[];
extern char data_ov020_0218da90[];
extern char data_ov020_0218d9b0[];

struct ListFlags0218b710 {
    unsigned char low : 4;
    unsigned char high : 4;
};

struct Sequence0218b710 {
    int state;
    int frame;
    char pad08[0xc - 0x8];
    char big[0x2c - 0xc];
    char sub2c[0x7c - 0x2c];
    char sub7c[0xbc - 0x7c];
    unsigned char flagBc;
    unsigned char flagBd;
    char padBe[0xc0 - 0xbe];
    short posX;
    short posY;
    short width;
    short height;
    char padC8[0x244 - 0xc8];
    char pairTables[0x2b4 - 0x244];
    char textCont[0x34c - 0x2b4];
    void* list34c;
    char pad350[0x354 - 0x350];
    short textW;
    short textH;
    short textX0;
    short textY0;
    short textX1;
    short textY1;
    short textCols;
    short textRows;
    char pad364[0x365 - 0x364];
    unsigned char b365;
    unsigned char b366;
    char pad367[0x369 - 0x367];
    unsigned char b369;
    unsigned char b36a;
    char pad36b[0x370 - 0x36b];
    char list[0x1c];
    ListFlags0218b710 listFlags;
    char pad38d[0x390 - 0x38d];
    char tiles[0x4];
    void* list394;
    char pad398[0x470 - 0x398];
    SafeAllocator alloc;
    char pad484[0x498 - 0x470 - sizeof(SafeAllocator)];
    void* buf498;
    char pad49c[0x4e4 - 0x49c];
    int timer;
    char pad4e8[0x4fc - 0x4e8];
    int fadeTimer;
};

static inline int IsTimerActive(Sequence0218b710* self) {
    int active = self->timer > 0;
    return active;
}

static inline int IsFadeActive(Sequence0218b710* self) {
    int active = self->fadeTimer > 0;
    return active;
}

#define START_FADE(self, target, frames)                                               \
    UpdateFieldGroup4e8_0218d7ac((FieldGroup4e8_0218d7ac*)(self), (target), (frames)); \
    UpdateFieldGroup4f4_0218d800((FieldGroup4f4_0218d800*)(self), (target), (frames))

#define WAIT_FADE(self)                          \
    for (;;) {                                   \
        if (!IsFadeActive(self)) break;          \
        func_ov020_0218d644(self);               \
        DelayThenSyncBit0();                     \
        InitCombatSubsystems02012efc();          \
        WriteControlAndToggle020d86d0(0, 1);     \
    }

#define WAIT_TIMER(self)                         \
    for (;;) {                                   \
        if (!IsTimerActive(self)) break;         \
        func_ov020_0218d854(self);               \
        DelayThenSyncBit0();                     \
        InitCombatSubsystems02012efc();          \
        WriteControlAndToggle020d86d0(0, 1);     \
    }

// USA: func_ov020_0218b710
extern "C" ARM void func_ov020_0218b710(Sequence0218b710* self) {
    GameState* gs = GameState::GetInstance();
    DelayThenSyncBit0();
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    if (GetWord0x7f6c(gs) == 1) {
        EncodeSignFlaggedHalfword((short*)0x400006c, 16);
        EncodeSignFlaggedHalfword((short*)0x400106c, 16);
    }
    RestoreDisplayMode();
    *(volatile unsigned int*)0x4001000 |= 0x10000;

    if (GetWord0x7f6c(gs) == 1) {
        START_FADE(self, -16, 2000);
        for (;;) {
            if (!func_ov020_0218d898(self)) break;
            func_ov020_0218d644(self);
            DelayThenSyncBit0();
            WriteControlAndToggle020d86d0(0, 1);
        }
    }

    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
    bgcnt[0] = bgcnt[0] & ~0x3;
    bgcnt[1] = (bgcnt[1] & ~0x3) | 0x1;
    DelayThenSyncBit0();
    RestoreDisplayMode();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);

    if (GetByte0x4((char*)gs) != 6) {
        self->alloc.CreateTypeA(AllocateAligned4(&data_02114e20, 0x10000), 0x10000);
        self->alloc.Reset();
        InitStruct0205cfd4((InitTarget0205cfd4*)self->textCont);
        ResetList0204af64((List0204af64*)self->list);
        func_0204c684(self->tiles);
        MapVRAMBanksToMainBG(4);
        func_ov020_0218c7bc(0, 0, 1, 1, 0);
        SetWord0x18ClearByte0x1f((unsigned char*)self->list, 0);
        self->listFlags.low = 0;
        self->listFlags.high = 1;
        func_0204b5b4(self->list, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)self->list, &self->alloc);
        DispatchViaTable0204b5e8((Obj0204b5e8*)self->list, 0, 0);

        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->MaybeReset();
        task = loader->QueueLoadFile(data_ov020_0218dbdc, 0);
        for (;;) {
            if (loader->GetTaskStatus(task) != 0) {
                void* recField;
                void* file;
                unsigned int fileLen;
                loader->GetLoadedFileByID(task, &file, &fileLen);
                int count = CountActiveEntries((ActiveEntry02046900*)file);
                for (int i = 0; i < count; i++) {
                    int recSize;
                    void* rec = FindRecordByIndex((Rec020467f0*)file, i, &recField, &recSize);
                    if (rec != 0) {
                        func_0204b174(self->list, rec, &self->alloc, recSize);
                    }
                }
                loader->RemoveTask(task);
                func_0204bc74(self->list, 0, 0, 0, 0x20, 0x19, 0);
                FlushAndDispatchList0204b0e8((List0204b0e8*)self->list, 0);
                self->buf498 = self->alloc.Allocate(0x8000);
                AllocateBuffer0204c7a8((Obj0204c7a8*)self->tiles, &self->alloc, (int)self->buf498, 0x800);
                self->list394 = self->list;
                self->list34c = self->list;
                self->b366 = 1;
                LinkArrayPrevPointers0205cf78((Struct_0205cf78*)self->textCont, (Elem_0205cf78*)self->tiles, 1);
                break;
            }
            loader->RemoveAllLocks();
        }

        self->b365 = 1;
        self->textX0 = 0;
        self->textY0 = 0;
        self->textX1 = 0;
        self->textY1 = 0;
        self->textW = 0x20;
        self->textH = 0x18;
        self->textCols = 0xa;
        self->textRows = 0xd;
        self->b369 = 0;
        self->b36a = 1;

        char* text = *(char**)(GetGlobalField0x1c020421a0() + 0x5c);
        memset(text, 0, 0x960);
        char buf[0x80] = {0};
        AppendXYTag(text, 4, 0x68);
        sprintf(buf, data_ov020_0218dbef, data_ov020_0218dbf5, data_ov020_0218dbfc);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0x74);
        sprintf(buf, data_ov020_0218dc08, 4, 2, 0x7539);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0x80);
        sprintf(buf, data_ov020_0218dc1b, 0x13242d6);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0x8c);
        sprintf(buf, data_ov020_0218dc2b, 2, 1, 0x7533);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0x98);
        sprintf(buf, data_ov020_0218dc3f, 2, 1, 0x7533);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0xa4);
        sprintf(buf, data_ov020_0218dc55, 3, 1, 0x7536);
        AppendString02042058(text, buf);
        AppendXYTag(text, 4, 0xb0);
        sprintf(buf, data_ov020_0218dc65, 3, 0, 0x7531);
        AppendString02042058(text, buf);
        AppendXYTag(text, 0, 0x28);
        AppendDotLeaderLabel02042084(text, data_ov020_0218dc72, 0x100, 0);
        AppendXYTag(text, 0, 0x36);
        AppendDotLeaderLabel02042084(text, data_ov020_0218dc82, 0x100, 0);
        AppendXYTag(text, 0, 0x50);
        AppendDotLeaderLabel02042084(text, data_ov020_0218dc91, 0x100, 0);

        func_0205d304(self->textCont, text, 0, 0, 0, 1, 0, 0);
        func_0205d0e0(self->textCont, 1);
        func_0205d0e0(self->textCont, 1);
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)self->textCont);
        CallFunc0204b04cOverList0x98((Cont0205d274*)self->textCont);
        InitEntries0205d2bc((Obj0205d2bc*)self->textCont);
        WriteControlAndToggle020d86d0(0, 1);
        DelayThenSyncBit0();
        RestoreDisplayMode();
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x200;
        ProcessRingJobs020bbcb4();
        WriteControlAndToggle020d86d0(0, 1);

        while (self->state != -1) {
            InitCombatSubsystems02012efc();
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1) || TestFlag0SetAndFlag1Clear(&data_02114e30, 2) ||
                TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400) || TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800) ||
                data_02114e54[0x55] != 0) {
                break;
            }
            DelayThenSyncBit0();
            EncodeSignFlaggedHalfword((short*)0x400006c, 0);
            WriteControlAndToggle020d86d0(0, 1);
        }

        void* signedAlloc = self->alloc.GetSignedAllocator();
        self->alloc.Destroy();
        TailForward02012da4(&data_02114e20, signedAlloc);
    }

    DelayThenSyncBit0();
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    volatile unsigned short* mainBg = (volatile unsigned short*)0x4000008;
    volatile unsigned short* subBg = (volatile unsigned short*)0x400100a;
    mainBg[0] = (mainBg[0] & ~0x3) | 0x1;
    mainBg[1] = mainBg[1] & ~0x3;
    mainBg[2] = (mainBg[2] & ~0x3) | 0x2;
    mainBg[3] = (mainBg[3] & ~0x3) | 0x3;
    *(volatile unsigned short*)0x4001008 = *(volatile unsigned short*)0x4001008 & ~0x3;
    subBg[0] = (subBg[0] & ~0x3) | 0x1;
    subBg[1] = (subBg[1] & ~0x3) | 0x2;
    subBg[2] = (subBg[2] & ~0x3) | 0x3;

    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(1);
    ConfigurePairMode020bb48c(1, 1);
    MapVRAMBanksToTexturePalette(0x60);
    InitGlobalStateAndInstallHandlers020bb780((void*)0x8000, 1);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();

    self->alloc.CreateTypeA(AllocateAligned4(&data_02114e20, 0x10000), 0x10000);
    func_0207de48(self->pairTables, 0x4000, 0x400);
    char* g = GetGlobalField0x1c020421a0();
    func_02042c68(g);
    func_02043124(g);
    TailForward020440a4(g);
    *(char**)(g + 0x1e28) = self->pairTables;
    CopyInternalFields0207df50((Foo0207df50*)self->pairTables);
    RestorePairTables0207df90(self->pairTables);
    func_020432c4(g);
    BackupPairTables0207dfac(self->pairTables);
    self->state = 100;
    self->frame = -1;

    if (GetByte0x4((char*)gs) == 6) {
        if (GetWord0x7f6c(gs) == 0) {
            Set3DClearColor(0x7fff, 0x1f, 0x7fff, 0, 0);
            func_ov020_0218cd98(self);
            RestoreDisplayMode();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            self->timer = 2000;
            WAIT_TIMER(self)

            START_FADE(self, 0, 500);
            self->timer = 3000;
            for (;;) {
                if (!IsFadeActive(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    InitCombatSubsystems02012efc();
                }
                func_ov020_0218d644(self);
                DelayThenSyncBit0();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(self, -16, 500);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)

            func_ov020_0218cf8c(self);
            RestoreDisplayMode();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(self, 0, 1500);
            self->timer = 7000;
            for (;;) {
                if (!func_ov020_0218d898(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    InitCombatSubsystems02012efc();
                    if (self->timer <= 2500) {
                        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0xf0b) || data_02114e54[0x55] != 0) break;
                    }
                }
                func_ov020_0218d644(self);
                DelayThenSyncBit0();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)

            func_ov020_0218d32c(self, 0);
            RestoreDisplayMode();
            *(volatile unsigned int*)0x4001000 |= 0x10000;
            START_FADE(self, 0, 1500);
            self->timer = 6000;
            for (;;) {
                if (!IsFadeActive(self)) {
                    if (!IsTimerActive(self)) break;
                    func_ov020_0218d854(self);
                    InitCombatSubsystems02012efc();
                    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0xf0b) || data_02114e54[0x55] != 0) break;
                }
                func_ov020_0218d644(self);
                DelayThenSyncBit0();
                WriteControlAndToggle020d86d0(0, 1);
            }
            START_FADE(self, -16, 1000);
            WAIT_FADE(self)
            self->timer = 1000;
            WAIT_TIMER(self)
            Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
        }
        SetWord0x7f6c(gs, 5);
        SetByte0x4((char*)gs, 0);
        SetByte0x7f70(gs, 1);
    } else {
        SetWord0x7f6c(gs, 0);
        func_ov020_0218c98c(self);
        RestoreDisplayMode();
        *(volatile unsigned int*)0x4001000 |= 0x10000;
        InitCombatSlots02045cac((CombatSlots02045cac*)g);
        InitBigStruct0205c790(self->big);
        self->flagBd = 1;
        self->flagBc = 1;
        if (CheckSaveBufferStatus(1) == 4) {
            for (int i = 0; i < 8; i++) {
                ProcessCombatEntry0205cb74(self->big, (int)(data_ov020_0218da90 + i * 0x20));
                Forward0204359c(g, 0x10);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 8);
        } else {
            for (int i = 0; i < 7; i++) {
                ProcessCombatEntry0205cb74(self->big, (int)(data_ov020_0218d9b0 + i * 0x20));
                Forward0204359c(g, 0x10);
                func_020439b0(g, 0);
            }
            func_ov020_0218c7f0(self->big, 1, 7);
        }
        func_0205cc50(self->big, 0, -4);
        int x = (0x100 - self->width) >> 1;
        int y = (0xc0 - self->height) >> 2;
        self->posX = x;
        self->posY = y;
        func_0205cc50(self->big, 0, -4);
        SetIndexIfValid0205bcdc((Struct_0205bcdc*)self->sub2c, 0);
        func_0205bb04(self->sub7c, 0);
        MapVRAMBanksToMainObj(2);

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        char* global = GetGlobalField0x1c020421a0();
        for (;;) {
            func_02043368(global);
            if (((unsigned char*)global)[0x2e7] == 2) break;
            loader->RemoveAllLocks();
        }

        char* ctx = func_0203bd08();
        InitBattleContext0203bd24(ctx);
        RefreshDisplayState0205e8ec((Obj_0205e8ec*)data_02108760);
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)data_02109bf4, 2);
        while (self->state != -1) {
            InitCombatSubsystems02012efc();
            if (++self->frame >= 0xffffff) {
                self->frame = 1;
            }
            ResetGxEngineState020c52e8();
            func_020c5414();
            *(volatile unsigned short*)0x4000060 &= 0xcfdf;
            switch (self->state) {
            case 100:
                func_ov020_0218c840(self);
                break;
            default:
                self->state = -1;
                break;
            }
            WriteControlAndToggle020d86d0(0, 1);
            _Z33CleanInvalidateOamBuffers0203bd88v(ctx);
            DelayThenSyncBit0();
            SyncMainSubOam0203bdb0((Obj0203bdb0*)ctx);
            ProcessRingJobs020bbcb4();
            func_020bbd9c();
            EncodeSignFlaggedHalfword((short*)0x400006c, 0);
            EncodeSignFlaggedHalfword((short*)0x400106c, 0);
        }

        if (GetByte0x4((char*)gs) == 0) {
            SetWord0x7f6c(gs, 6);
        } else if (GetByte0x4((char*)gs) == 5) {
            SetWord0x7f6c(gs, 6);
        }
    }

    ResetAllocatorAndDispatchState_0218d8d8((AllocGroup0218d8d8*)self);
    CopyInternalFields0207df50((Foo0207df50*)self->pairTables);
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
}
