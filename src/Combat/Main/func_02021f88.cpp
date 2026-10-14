#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Resource/GameResources.h"
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254_0203b628(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

void TailForward0203b66c(char* obj);
void InitSubObject0203bd78(char* obj);
void InitBattleContext0203bd24(char* obj);
void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);
void InitStruct0205a444(char* obj);

void* GetGlobalPtr02105244_0203bd14();
extern "C" void* func_0203be4c(void);
struct Rec020467f0;
int ProcessRecords0205a498(void* a, struct Rec020467f0* b, int flag, void* d);
void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d);
int ValidateResourceLookup0205a1f0(void* a, void* b, int c);
int GetGlobalField0x1c020421a0(void);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
void DelayThenSyncBit0_020c9820(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);
void InitFourEntrySlots02020aa0(void* obj);
extern "C" void func_02027974(void* obj, int a, void* b);
#if defined(jpn)
extern "C" void func_02020fc4(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void func_02020fc4(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void func_020210f8(char* obj, int* handle, SafeAllocator* alloc);
struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);
extern "C" void func_0204b174(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void func_0202445c(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_0202343c(void* obj);
void MarkActiveCombatantSlots02026b7c(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);
int FormatAndCopyNames02020b98(void* obj);
int IsValueInRange0201b5d8(int x);
int IsInRange0201b5b0(int id);
void UpdateStringField02023b0c(char* a, char* b);

extern "C" void __clear(void* dst, unsigned int size);
extern int data_020ef460;
extern char data_020ef5fa[];
extern char data_020ef613[];
extern char data_020ef622[];
extern char data_020ef632[];
extern char data_020ef642[];
extern char data_020ef649[];
extern char data_020ef5b9[];
extern char data_020ef654[];
extern char data_020ef65d[];
extern char data_020ef668[];
extern char data_020ef671[];

struct Res02021f88 {
    char pad0[0x10];
    unsigned int f10;
    void* f14;
};

struct Node02021f88 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int x;
    int y;
    struct Node02021f88* next;
};

static inline SafeAllocator* GetAlloc02021f88(GameResources* axis, int i) {
    return &axis->allocator_array_38[i];
}

#if defined(jpn)
enum { ContextTailRegionOffset = 0xac, GlobalHeaderRegionOffset = 4, ZoneBaseOffset = 0xc,
       ZoneLargeOffset = 0x2400, ZoneValueOffset = 0x23da, GlobalBufferOffset = 0x608,
       VramDataOffset = 0x2c, InitialPathBufferSize = 0x40 };
#else
enum { ContextTailRegionOffset = 0, GlobalHeaderRegionOffset = 0, ZoneBaseOffset = 0x3ec,
       ZoneLargeOffset = 0x2000, ZoneValueOffset = 0x23ba, GlobalBufferOffset = 0x508,
       VramDataOffset = 0x60, InitialPathBufferSize = 0x20 };
#endif

static inline char* Zone02021f88(void* p) {
    return (char*)p + ZoneBaseOffset;
}

static inline char* Off2000_02021f88(char* p) {
    return p + ZoneLargeOffset;
}

// USA: func_02021f88
extern "C" ARM void func_02021f88(MapDisplay* self) {
    char buf4[InitialPathBufferSize];
    char buf3[0x10];
    char buf2[0x40];
    char buf1[0x40];
    void* fileData;
    unsigned int fileLength;
    Res02021f88* res;
    void* fileDataA;
    void* fileDataB;
    unsigned int fileLengthA;
    unsigned int fileLengthB;

    BackgroundLoader* loader;
    unsigned short* p6;
    GameResources* axis;
    char* battleCtx;
    char* table;
    int state;
    SafeAllocator* alloc;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    p6 = func_02012fe4();
    axis = func_ov017_0218b5b0();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254_0203b628();
    state = self->loadStage;
    alloc = GetAlloc02021f88(axis, 12);

    if (state == 0) {
        func_02021428(self, 0x19);
        loader->AddFence();
        self->taska10 = loader->QueueLoadFile(data_020ef5fa, (SafeAllocator*)0);
        int v = *(signed char*)((char*)p6 + ZoneValueOffset);
#if !defined(jpn)
        __clear(buf4, 0x20);
#endif
        if (IsValueInRange0201b5d8(*p6)) {
            strcpy(buf4, data_020ef613);
        } else {
            sprintf(buf4, data_020ef622, v);
        }
#if defined(jpn)
        self->taska14 = loader->QueueLoadFile(buf4, (SafeAllocator*)0);
#else
        self->taska14 = loader->QueueLoadFileInGP2(data_020ef632, buf4, (SafeAllocator*)0);
#endif
        if (IsValueInRange0201b5d8(*p6)) {
            self->namesTask = FormatAndCopyNames02020b98(self);
        } else if (IsInRange0201b5b0(*p6)) {
#if !defined(jpn)
            __clear(buf3, 0x10);
#endif
            sprintf(buf3, data_020ef642, *p6);
            UpdateStringField02023b0c((char*)self, buf3);
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->taska10) == 0) return;
        if (loader->GetTaskStatus(self->taska14) == 0) return;
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        func_02020720(self);
        self->displayMode = 0;
        func_02020838(self);
        TailForward0203b66c(table);
        alloc->Reset();
        InitSubObject0203bd78(battleCtx);
        InitBattleContext0203bd24(battleCtx);
        SetArraySlotFlag0203b718(table, 1, 0, 0);
        SetArraySlotFlag0203b718(table, 1, 1, 0);
        func_0203ba74(table);
        for (int i = 0; i < 0x1c; i++) {
            Init0205a198(&self->records[i]);
        }
        InitStruct0205a444((char*)&self->entryList);
        self->entryList.active = 1;
        self->entryList.records = self->records;
        self->entryList.count = 0x1b;
        char* g = (char*)GetGlobalPtr02105244_0203bd14();
        *(int*)(g + GlobalBufferOffset) = 0x2000;
        func_0203bd08();
        char* p = (char*)func_0203be4c() + 0x2c0;
        g = (char*)GetGlobalPtr02105244_0203bd14();
        *(char**)g = p;
        if (IsValueInRange0201b5d8(*p6)) {
            if (loader->GetTaskStatus(self->namesTask) == 0) return;
        }
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(self->taska10, &fileData, &fileLength);
        ProcessRecords0205a498((char*)&self->entryList, (struct Rec020467f0*)fileData, fileLength, alloc);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[9], 1, 1);
        SetBitfieldStoreBytes0205af38((int)((char*)&self->entryList), (char*)&self->records[11], 1, 1);
        BackgroundLoader::GetInstance()->RemoveTask(self->taska10);
        self->taska10 = -1;
        loader->GetLoadedFileByID(self->taska14, &fileData, &fileLength);
        res = 0;
        if (ValidateResourceLookup0205a1f0(&res, fileData, fileLength) != 0) return;
        char* vram = (char*)GetGlobalField0x1c020421a0();
        char* dst = *(char**)(vram + VramDataOffset);
        VectorizedInvertedMemcpy(res->f14, dst, res->f10);
        DelayThenSyncBit0_020c9820();
        CleanInvalidateCacheRange(dst, res->f10);
        LoadToSubObjVRAM((int)dst, 0x2c20, res->f10);
        BackgroundLoader::GetInstance()->RemoveTask(self->taska14);
        self->taska14 = -1;
        InitFourEntrySlots02020aa0(self);
        self->nameCount = 0;
        self->forwardingCount = 0;
        if (IsInRange0201b5b0(*p6)) {
            strcpy(self->name, data_020ef649);
            self->scale = 0x2000;
            self->mapState = alloc->Allocate(0x800);
            func_02027974(self, (int)((ActiveGrottoClass*)Off2000_02021f88(Zone02021f88(p6)))->floorMap_.pMapAdjacencyData, self->mapState);
            self->forwardingX = -1;
            self->forwardingY = -1;
            Node02021f88* node = (Node02021f88*)alloc->Allocate(0x14);
            if (node == 0) return;
            node->type = 0;
            node->count = 1;
            node->data = (short*)alloc->Allocate(node->count * 2);
            if (node->data == 0) return;
            for (int i = 0; i < node->count; i++) {
                node->data[i] = *p6;
            }
            Node02021f88* head = self->field754;
            node->id = head ? head->id + 1 : 1;
            node->next = self->field754;
            self->field754 = node;
        } else {
#if defined(jpn)
            func_02020c18(self, self->namesTask, alloc);
#else
            func_02020c18(self, &self->namesTask, alloc);
#endif
        }
        loader->AddFence();
        sprintf(buf2, data_020ef5b9, self->name);
        self->fileTask928 = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
        if (IsValueInRange0201b5d8(*p6)) {
            for (int i = 0; i < self->nameCount; i++) {
                sprintf(buf2, data_020ef5b9,
                        self->names[i].name);
                self->nameTasks[i] = loader->QueueLoadFileInGP2(
                    *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
            }
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 2) {
        if (loader->GetTaskStatus(self->fileTask928) == 0) return;
        if (IsValueInRange0201b5d8(*p6)) {
            for (int i = 0; i < self->nameCount; i++) {
                if (loader->GetTaskStatus(self->nameTasks[i]) == 0) return;
            }
        }
#if defined(jpn)
        func_02020fc4(self, self->fileTask928, alloc);
#else
        func_02020fc4(self, &self->fileTask928, alloc);
#endif
        if (IsInRange0201b5b0(*p6)) {
            self->mapPalette = self->forwardingFill + 1;
            char* zone = Zone02021f88(p6);
            ResetList0204af64(&self->list4c);
            self->list4c.b1c_lo = 1;
            self->list4c.b1c_hi = 0;
            self->list4c.byteCount = self->mapPalette << 5;
            loader->AddFence();
            ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zone + ZoneLargeOffset);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, data_020ef654);
            } else {
                sprintf(buf1, data_020ef65d, grotto->GetActiveGrottoEnviron());
            }
            self->taska18 = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf1, (SafeAllocator*)0);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, data_020ef668);
            } else {
                sprintf(buf1, data_020ef671, grotto->GetActiveGrottoEnviron());
            }
            self->taska1c = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf1, (SafeAllocator*)0);
        } else {
            func_020210f8((char*)self, self->nameTasks, alloc);
        }
        self->loadStage = self->loadStage + 1;
    } else if (state == 3) {
        if (IsInRange0201b5b0(*p6)) {
            if (loader->GetTaskStatus(self->taska18) == 0) return;
            if (loader->GetTaskStatus(self->taska1c) == 0) return;
            fileDataA = 0;
            fileDataB = 0;
            fileLengthA = 0;
            fileLengthB = 0;
            loader->GetLoadedFileByID(self->taska18, &fileDataA, &fileLengthA);
            fileLengthA = (fileLengthA + 3) & ~3;
            loader->GetLoadedFileByID(self->taska1c, &fileDataB, &fileLengthB);
            fileLengthB = (fileLengthB + 3) & ~3;
            func_0204b174(&self->list4c, fileDataA, alloc, fileLengthA);
            func_0204b174(&self->list4c, fileDataB, alloc, fileLengthB);
            BackgroundLoader::GetInstance()->RemoveTask(self->taska18);
            self->taska18 = -1;
            BackgroundLoader::GetInstance()->RemoveTask(self->taska1c);
            self->taska1c = -1;
        }
        func_0202445c(self);
        func_ov017_02191234(axis);
        self->forwardingPending = 1;
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
