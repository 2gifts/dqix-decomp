#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
void* GetData02105254(void);
extern "C" void func_02021428(void* obj, int amount);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

extern "C" void func_02020720(char* obj);
extern "C" void func_02020838(char* obj);
extern "C" void _Z19TailForward0203b66cPc(char* obj);
extern "C" void _Z21InitSubObject0203bd78Pc(char* obj);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* obj);
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);
struct Struct0205a198;
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);

void* GetGlobalPtr02105244();
extern "C" void* func_0203be4c(void);
struct Rec020467f0;
extern "C" int _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(void* a, struct Rec020467f0* b, int flag, void* d);
extern "C" void _Z29SetBitfieldStoreBytes0205af38iPcii(int a, char* obj, int c, int d);
extern "C" int _Z30ValidateResourceLookup0205a1f0PvS_i(void* a, void* b, int c);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
void DelayThenSyncBit0(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);
extern "C" void _Z26InitFourEntrySlots02020aa0Pv(void* obj);
extern "C" void func_02027974(void* obj, int a, void* b);
#if defined(jpn)
extern "C" void func_02020c18(char* obj, int handle, SafeAllocator* alloc);
extern "C" void func_02020fc4(void* obj, int handle, SafeAllocator* alloc);
#else
extern "C" void func_02020c18(char* obj, int* handle, SafeAllocator* alloc);
extern "C" void func_02020fc4(void* obj, int* handle, SafeAllocator* alloc);
#endif
extern "C" void func_020210f8(char* obj, int* handle, SafeAllocator* alloc);
struct List0204af64;
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void func_0204b174(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void func_0202445c(void* obj);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_0202343c(void* obj);
extern "C" void _Z32MarkActiveCombatantSlots02026b7cPh(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);
extern "C" int _Z26FormatAndCopyNames02020b98Pv(void* obj);
extern "C" int _Z22IsValueInRange0201b5d8i(int x);
extern "C" int _Z17IsInRange0201b5b0i(int id);
extern "C" void _Z25UpdateStringField02023b0cPcS_(char* a, char* b);

extern "C" void __clear(void* dst, unsigned int size);
extern int data_020ef460;
extern char data_020ef5fa;
extern char data_020ef613;
extern char data_020ef622;
extern char data_020ef632;
extern char data_020ef642;
extern char data_020ef649;
extern char data_020ef5b9;
extern char data_020ef654;
extern char data_020ef65d;
extern char data_020ef668;
extern char data_020ef671;

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

struct Entry02021f88 {
    int field0;
    char* name;
    char pad8[0x1c];
};

struct ListState02021f88 {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct AxisAllocs02021f88 {
    char pad[0x114];
    SafeAllocator allocs[2];
};

static inline SafeAllocator* GetAlloc02021f88(void* axis, int i) {
    return &((AxisAllocs02021f88*)axis)->allocs[i];
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
extern "C" ARM void func_02021f88(char* self) {
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
    void* axis;
    char* battleCtx;
    char* table;
    int state;
    SafeAllocator* alloc;

    GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    p6 = func_02012fe4();
    axis = func_ov017_0218b5b0();
    battleCtx = (char*)func_0203bd08();
    table = (char*)GetData02105254();
    state = *(signed char*)(self + 0x9c2 - ContextTailRegionOffset);
    alloc = GetAlloc02021f88(axis, 1);

    if (state == 0) {
        func_02021428(self, 0x19);
        loader->AddFence();
        *(int*)(self + 0xa10 - ContextTailRegionOffset) = loader->QueueLoadFile(&data_020ef5fa, (SafeAllocator*)0);
        int v = *(signed char*)((char*)p6 + ZoneValueOffset);
#if !defined(jpn)
        __clear(buf4, 0x20);
#endif
        if (_Z22IsValueInRange0201b5d8i(*p6)) {
            strcpy(buf4, &data_020ef613);
        } else {
            sprintf(buf4, &data_020ef622, v);
        }
#if defined(jpn)
        *(int*)(self + 0xa14 - ContextTailRegionOffset) = loader->QueueLoadFile(buf4, (SafeAllocator*)0);
#else
        *(int*)(self + 0xa14 - ContextTailRegionOffset) = loader->QueueLoadFileInGP2(&data_020ef632, buf4, (SafeAllocator*)0);
#endif
        if (_Z22IsValueInRange0201b5d8i(*p6)) {
            *(int*)(self + 0x9d0 - ContextTailRegionOffset) = _Z26FormatAndCopyNames02020b98Pv(self);
        } else if (_Z17IsInRange0201b5b0i(*p6)) {
#if !defined(jpn)
            __clear(buf3, 0x10);
#endif
            sprintf(buf3, &data_020ef642, *p6);
            _Z25UpdateStringField02023b0cPcS_(self, buf3);
        }
        *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) = *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) + 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(*(int*)(self + 0xa10 - ContextTailRegionOffset)) == 0) return;
        if (loader->GetTaskStatus(*(int*)(self + 0xa14 - ContextTailRegionOffset)) == 0) return;
        func_02021428(self, 0x19);
        if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axis, 1) != 0) return;
        func_02020720(self);
        *(int*)(self + 0x14) = 0;
        func_02020838(self);
        _Z19TailForward0203b66cPc(table);
        alloc->Reset();
        _Z21InitSubObject0203bd78Pc(battleCtx);
        _Z25InitBattleContext0203bd24Pc(battleCtx);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 0, 0);
        _Z24SetArraySlotFlag0203b718Pviii(table, 1, 1, 0);
        func_0203ba74(table);
        for (int i = 0; i < 0x1c; i++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)(self + 0xe8 + i * 0x28));
        }
        _Z18InitStruct0205a444Pc(self + 0x94);
        *(unsigned char*)(self + 0xe4) = 1;
        *(char**)(self + 0xd4) = self + 0xe8;
        *(unsigned short*)(self + 0xe0) = 0x1b;
        char* g = (char*)GetGlobalPtr02105244();
        *(int*)(g + GlobalBufferOffset) = 0x2000;
        func_0203bd08();
        char* p = (char*)func_0203be4c() + 0x2c0;
        g = (char*)GetGlobalPtr02105244();
        *(char**)g = p;
        if (_Z22IsValueInRange0201b5d8i(*p6)) {
            if (loader->GetTaskStatus(*(int*)(self + 0x9d0 - ContextTailRegionOffset)) == 0) return;
        }
        fileData = 0;
        fileLength = 0;
        loader->GetLoadedFileByID(*(int*)(self + 0xa10 - ContextTailRegionOffset), &fileData, &fileLength);
        _Z22ProcessRecords0205a498PvP11Rec020467f0iS_(self + 0x94, (struct Rec020467f0*)fileData, fileLength, alloc);
        _Z29SetBitfieldStoreBytes0205af38iPcii((int)(self + 0x94), self + 0x250, 1, 1);
        _Z29SetBitfieldStoreBytes0205af38iPcii((int)(self + 0x94), self + 0x2a0, 1, 1);
        BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa10 - ContextTailRegionOffset));
        *(int*)(self + 0xa10 - ContextTailRegionOffset) = -1;
        loader->GetLoadedFileByID(*(int*)(self + 0xa14 - ContextTailRegionOffset), &fileData, &fileLength);
        res = 0;
        if (_Z30ValidateResourceLookup0205a1f0PvS_i(&res, fileData, fileLength) != 0) return;
        char* vram = (char*)_Z26GetGlobalField0x1c020421a0v();
        char* dst = *(char**)(vram + VramDataOffset);
        VectorizedInvertedMemcpy(res->f14, dst, res->f10);
        DelayThenSyncBit0();
        CleanInvalidateCacheRange(dst, res->f10);
        LoadToSubObjVRAM((int)dst, 0x2c20, res->f10);
        BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa14 - ContextTailRegionOffset));
        *(int*)(self + 0xa14 - ContextTailRegionOffset) = -1;
        _Z26InitFourEntrySlots02020aa0Pv(self);
        *(int*)(self + 0x24) = 0;
        *(int*)(self + 0x30) = 0;
        if (_Z17IsInRange0201b5b0i(*p6)) {
            strcpy(self + 0x548, &data_020ef649);
            *(int*)(self + 0x38) = 0x2000;
            *(void**)(self + 0x6c) = alloc->Allocate(0x800);
            func_02027974(self, (int)((ActiveGrottoClass*)Off2000_02021f88(Zone02021f88(p6)))->floorMap_.pMapAdjacencyData, *(void**)(self + 0x6c));
            *(int*)(self + 0x18) = -1;
            *(int*)(self + 0x1c) = -1;
            Node02021f88* node = (Node02021f88*)alloc->Allocate(0x14);
            if (node == 0) return;
            node->type = 0;
            node->count = 1;
            node->data = (short*)alloc->Allocate(node->count * 2);
            if (node->data == 0) return;
            for (int i = 0; i < node->count; i++) {
                node->data[i] = *p6;
            }
            Node02021f88* head = *(Node02021f88**)(self + 0x754 - ContextTailRegionOffset);
            node->id = head ? head->id + 1 : 1;
            node->next = *(Node02021f88**)(self + 0x754 - ContextTailRegionOffset);
            *(Node02021f88**)(self + 0x754 - ContextTailRegionOffset) = node;
        } else {
#if defined(jpn)
            func_02020c18(self, *(int*)(self + 0x9d0 - ContextTailRegionOffset), alloc);
#else
            func_02020c18(self, (int*)(self + 0x9d0 - ContextTailRegionOffset), alloc);
#endif
        }
        loader->AddFence();
        sprintf(buf2, &data_020ef5b9, self + 0x548);
        *(int*)(self + 0x9d4 - ContextTailRegionOffset) = loader->QueueLoadFileInGP2(
            *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
        if (_Z22IsValueInRange0201b5d8i(*p6)) {
            for (int i = 0; i < *(int*)(self + 0x24); i++) {
                sprintf(buf2, &data_020ef5b9,
                        (*(Entry02021f88**)(self + 0x20))[i].name);
                *(int*)(self + 0x9d8 - ContextTailRegionOffset + i * 4) = loader->QueueLoadFileInGP2(
                    *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf2, (SafeAllocator*)0);
            }
        }
        *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) = *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) + 1;
    } else if (state == 2) {
        if (loader->GetTaskStatus(*(int*)(self + 0x9d4 - ContextTailRegionOffset)) == 0) return;
        if (_Z22IsValueInRange0201b5d8i(*p6)) {
            for (int i = 0; i < *(int*)(self + 0x24); i++) {
                if (loader->GetTaskStatus(*(int*)(self + 0x9d8 - ContextTailRegionOffset + i * 4)) == 0) return;
            }
        }
#if defined(jpn)
        func_02020fc4(self, *(int*)(self + 0x9d4 - ContextTailRegionOffset), alloc);
#else
        func_02020fc4(self, (int*)(self + 0x9d4 - ContextTailRegionOffset), alloc);
#endif
        if (_Z17IsInRange0201b5b0i(*p6)) {
            *(int*)(self + 0x70) = *(int*)(self + 0x74) + 1;
            char* zone = Zone02021f88(p6);
            _Z17ResetList0204af64P12List0204af64((struct List0204af64*)(self + 0x4c));
            ((ListState02021f88*)(self + 0x4c))->lo = 1;
            ((ListState02021f88*)(self + 0x4c))->hi = 0;
            *(int*)(self + 0x4c) = *(int*)(self + 0x70) << 5;
            loader->AddFence();
            ActiveGrottoClass* grotto = (ActiveGrottoClass*)(zone + ZoneLargeOffset);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, &data_020ef654);
            } else {
                sprintf(buf1, &data_020ef65d, grotto->GetActiveGrottoEnviron());
            }
            *(int*)(self + 0xa18 - ContextTailRegionOffset) = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf1, (SafeAllocator*)0);
            if (grotto->GetActiveGrottoEnviron() == 0) {
                sprintf(buf1, &data_020ef668);
            } else {
                sprintf(buf1, &data_020ef671, grotto->GetActiveGrottoEnviron());
            }
            *(int*)(self + 0xa1c - ContextTailRegionOffset) = loader->QueueLoadFileInGP2(
                *(const char**)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset), buf1, (SafeAllocator*)0);
        } else {
            func_020210f8(self, (int*)(self + 0x9d8 - ContextTailRegionOffset), alloc);
        }
        *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) = *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) + 1;
    } else if (state == 3) {
        if (_Z17IsInRange0201b5b0i(*p6)) {
            if (loader->GetTaskStatus(*(int*)(self + 0xa18 - ContextTailRegionOffset)) == 0) return;
            if (loader->GetTaskStatus(*(int*)(self + 0xa1c - ContextTailRegionOffset)) == 0) return;
            fileDataA = 0;
            fileDataB = 0;
            fileLengthA = 0;
            fileLengthB = 0;
            loader->GetLoadedFileByID(*(int*)(self + 0xa18 - ContextTailRegionOffset), &fileDataA, &fileLengthA);
            fileLengthA = (fileLengthA + 3) & ~3;
            loader->GetLoadedFileByID(*(int*)(self + 0xa1c - ContextTailRegionOffset), &fileDataB, &fileLengthB);
            fileLengthB = (fileLengthB + 3) & ~3;
            func_0204b174(self + 0x4c, fileDataA, alloc, fileLengthA);
            func_0204b174(self + 0x4c, fileDataB, alloc, fileLengthB);
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa18 - ContextTailRegionOffset));
            *(int*)(self + 0xa18 - ContextTailRegionOffset) = -1;
            BackgroundLoader::GetInstance()->RemoveTask(*(int*)(self + 0xa1c - ContextTailRegionOffset));
            *(int*)(self + 0xa1c - ContextTailRegionOffset) = -1;
        }
        func_0202445c(self);
        func_ov017_02191234(axis);
        *(unsigned char*)(self + 0x55c) = 1;
        *(unsigned char*)(self + 0x9c4 - ContextTailRegionOffset) = 1;
        *(unsigned char*)(self + 0x9c8 - ContextTailRegionOffset) = 0;
        *(unsigned char*)(self + 0x9c3 - ContextTailRegionOffset) = 0;
        *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) = *(signed char*)(self + 0x9c2 - ContextTailRegionOffset) + 1;
        DelayThenSyncBit0();
        func_0202343c(self);
        _Z32MarkActiveCombatantSlots02026b7cPh((unsigned char*)self);
        func_02026bdc(self, 0);
    }
}
