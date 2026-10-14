#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

int GetWord0x0_0200fb8c(int*);
extern "C" void func_ov005_02155424(void* self);
extern "C" void func_ov005_02155544(void* self);
extern "C" void func_ov005_021555c0(void* self);
extern "C" void func_ov005_021571d0(void* self);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
char* GetGlobalField0x1c020421a0();
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fog);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int bits);
int* GetData02105254_0203b628();
void SetupBankModeAndTransfer_0203b678(int* obj, int a, int b);
void TailForward0203b66c(char*);
void ClearThreeRegions0203b634(char*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
extern "C" void func_0204b5b4(void* obj, int value);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);
struct Container020e0310;
const char* GetFieldByKey020e0434(Container020e0310*, int);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(void* obj, void* data, SafeAllocator* alloc, int field44);
extern "C" void func_0204bc74(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
struct Obj0204b8d0;
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct Obj0204c7a8;
void AllocateBuffer0204c7a8(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
struct Elem_0205cf78;
struct Struct_0205cf78;
void LinkArrayPrevPointers0205cf78(Struct_0205cf78*, Elem_0205cf78*, unsigned char);
struct Struct0200fb08;
int NormalizeField5_0200fb08(Struct0200fb08*);
int FindMatchingRecords0204684c(Rec020467f0*, char const*, void**, int, int*, void**);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void Forward02047b30(void* a, int b, int c, int d);
struct Obj021e1318;
void ClearObj_021e1318(Obj021e1318*);
void InitScriptAndRun_021e133c(void* a, void* b, int c, int d, int e, short f);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
char* GetField1c_021a193c(int*);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov023_021dc134(void* obj, int key, int flag);
extern "C" void func_ov023_021dbfd0(void* obj, void* alloc);

extern char data_ov005_0215cdb4[];
extern char data_ov005_0215cdcd[];
extern unsigned int data_ov005_0215cd68[3];
extern char data_ov005_0215cddd[];
extern char data_ov005_0215cdf3[];

struct List0215436c {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[3];
};

union Flags0215436c {
    unsigned int raw;
    struct {
        unsigned int b0 : 2;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int b4 : 1;
        unsigned int b5 : 1;
        unsigned int b6 : 1;
        unsigned int b7 : 3;
        unsigned int b10 : 1;
        unsigned int rest : 21;
    } bits;
};

struct Scene0215436c {
    SafeAllocator alloc;
    char pad0[0x21c - sizeof(SafeAllocator)];
    SafeAllocator fileAlloc;
    char pad1[0x244 - 0x21c - sizeof(SafeAllocator)];
    SafeAllocator effectAlloc;
    char pad2[0x258 - 0x244 - sizeof(SafeAllocator)];
    SafeAllocator scriptAlloc;
    char pad3[0x294 - 0x258 - sizeof(SafeAllocator)];
    char pairTables[0xdf4 - 0x294];
    int fdf4;
    char container[0xe10 - 0xdf8];
    int fe10;
    char pad4[0xe84 - 0xe14];
    List0215436c lists[3];
    char linkHead[0xf7c - 0xee4];
    List0215436c* linkList;
    char pad5[0xf96 - 0xf80];
    unsigned char linkFlag;
    char pad6[0xfa0 - 0xf97];
    char elems[3][0xe0];
    void* buffer;
    char effect[0x128c - 0x1244];
    int f128c;
    char pad7[0x19b8 - 0x1290];
    unsigned short f19b8;
    char pad8[0x19be - 0x19ba];
    unsigned char f19be;
    char pad9[0x19e0 - 0x19bf];
    char script[0x1a30 - 0x19e0];
    unsigned char f1a30;
    char pad10[0x1a34 - 0x1a31];
    void* motionTarget;
    int motion[0x1a6c - 0x1a38 >> 2];
    int f1a6c;
    char records[0x2d90 - 0x1a70];
    short f2d90;
    char pad11[0x3da9 - 0x2d92];
    unsigned char f3da9;
    unsigned char f3daa;
    char pad12[0x3db8 - 0x3dab];
    unsigned char f3db8;
    char pad13[0x3dc4 - 0x3db9];
    unsigned char state;
    char pad14[3];
    int handle;
    Flags0215436c flags;
};

// USA: func_ov005_0215436c
extern "C" ARM int func_ov005_0215436c(Scene0215436c* self) {
    unsigned int size;
    void* recData;
    void* file3;
    unsigned int len3;
    int recSize;
    void* file4;
    unsigned int len4;
    void* file5;
    unsigned int len5;
    void* datas[38];
    int sizes[38];

    if (self->state == 0xff) {
        return 1;
    }

    GameState* gs = GameState::GetInstance();
    int word = GetWord0x0_0200fb8c((int*)gs);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        func_ov005_02155424(self);
        func_ov005_02155544(self);
        func_ov005_021555c0(self);
        self->flags.bits.b5 = 1;
        self->f3da9 = 0;
        self->flags.bits.b6 = 1;
        self->f3daa = 0;
        self->state++;
    } else if (self->state == 1) {
        if (self->f3daa == 0) {
            self->state++;
        }
    } else if (self->state == 2) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* data = ExtractFileFromGP2(data_ov005_0215cdb4, data_ov005_0215cdcd, &size);
        self->fileAlloc.Reset();
        func_020dfec0(self->container, &self->fileAlloc, data, size);
        BackgroundLoader::RemoveLockGlobal();
        self->fe10 = *(int*)(GetGlobalField0x1c020421a0() + 0x5c);
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        SetBitsInField4_0203b4d8((unsigned int*)word, 0x800);
        int* bank = GetData02105254_0203b628();
        SetupBankModeAndTransfer_0203b678(bank, 0, 1);
        TailForward0203b66c((char*)bank);
        ClearThreeRegions0203b634((char*)bank);

        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->lists[0], 0);
        self->lists[0].lo = 0;
        self->lists[0].hi = 1;
        func_0204b5b4(&self->lists[0], 3);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&self->lists[0], 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->lists[0], &self->alloc);
        AllocateArray0204af38((Foo0204af38*)&self->lists[0], 6, &self->alloc);

        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->lists[1], 0);
        self->lists[1].lo = 0;
        self->lists[1].hi = 2;
        func_0204b5b4(&self->lists[1], 2);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&self->lists[1], 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->lists[1], &self->alloc);
        AllocateArray0204af38((Foo0204af38*)&self->lists[1], 9, &self->alloc);

        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->lists[2], 0);
        self->lists[2].lo = 0;
        self->lists[2].hi = 3;
        func_0204b5b4(&self->lists[2], 0);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&self->lists[2], 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->lists[2], &self->alloc);

        volatile unsigned short* bgcnt = (volatile unsigned short*)0x400000a;
        bgcnt[0] = (bgcnt[0] & 0x43) | 0x1d00;
        bgcnt[1] = (bgcnt[1] & 0x43) | 0x1e00;
        bgcnt[2] = (bgcnt[2] & 0x43) | 0x1f04;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xa, 6);

        const char* inner = GetFieldByKey020e0434((Container020e0310*)self->container, 0x3e9);
        const char* gp2 = GetFieldByKey020e0434((Container020e0310*)self->container, 0x3e8);
        self->handle = loader->QueueLoadFileInGP2(gp2, inner, 0);
        self->state++;
    } else if (self->state == 3) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file3, &len3);
            int count = CountActiveEntries((ActiveEntry02046900*)file3);
            for (int i = 0; i < count; i++) {
                void* rec = FindRecordByIndex((Rec020467f0*)file3, i, &recData, &recSize);
                if (rec != 0) {
                    if (i == 0) {
                        func_0204b174(&self->lists[2], rec, &self->alloc, recSize);
                    } else if (i <= 8) {
                        func_0204b174(&self->lists[0], rec, &self->alloc, recSize);
                    } else {
                        func_0204b174(&self->lists[1], rec, &self->alloc, recSize);
                    }
                }
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;

            func_0204bc74(&self->lists[1], 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->lists[1], 0);
            func_0204bc74(&self->lists[2], 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->lists[2], 0);
            DispatchEntry0204b8d0((Obj0204b8d0*)&self->lists[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->lists[0], 0);
            DispatchEntry0204b8d0((Obj0204b8d0*)&self->lists[0], 1, 0, 0, 0, 0x14, 0x10, 2, 0xffff);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->lists[0], 0);

            self->buffer = self->alloc.Allocate(0x2400);
            char* elem;
            for (int j = 0; j < 3; j++) {
                elem = self->elems[j];
                AllocateBuffer0204c7a8((Obj0204c7a8*)elem, &self->alloc, (int)self->buffer, data_ov005_0215cd68[j]);
                *(List0215436c**)(elem + 4) = &self->lists[2];
            }
            self->linkList = &self->lists[2];
            self->linkFlag = 1;
            LinkArrayPrevPointers0205cf78((Struct_0205cf78*)self->linkHead, (Elem_0205cf78*)self->elems, 3);

            const char* name = GetFieldByKey020e0434((Container020e0310*)self->container, 0x3ea);
            self->handle = loader->QueueLoadFile(name, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &len4);
            int count = CountActiveEntries((ActiveEntry02046900*)file4);
            int mode = NormalizeField5_0200fb08((Struct0200fb08*)gs);
            int n = 0;
            const char* name = GetFieldByKey020e0434((Container020e0310*)self->container, 0x7d0);
            if (FindMatchingRecords0204684c((Rec020467f0*)file4, name, datas, count, sizes, 0) != 0) {
                RestorePairTables0207df90((char*)self->pairTables);
                for (int i = 0; i < count; i++) {
                    if (i == 0x23) {
                        if (mode == 2 || mode == 3) {
                            continue;
                        }
                    } else if (i == 0x24) {
                        if (mode != 2) {
                            continue;
                        }
                    } else if (i == 0x25) {
                        if (mode != 3) {
                            continue;
                        }
                    }
                    Forward02047b30(self->records + n * 0x88, (int)datas[i], sizes[i], (int)((char*)self + 0x14));
                    n++;
                }
                BackupPairTables0207dfac((char*)self->pairTables);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->handle = loader->QueueLoadFileInGP2(data_ov005_0215cddd, data_ov005_0215cdf3, 0);
            self->state++;
        }
    } else if (self->state == 5) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file5, &len5);
            self->scriptAlloc.Reset();
            ClearObj_021e1318((Obj021e1318*)self->script);
            InitScriptAndRun_021e133c(self->script, &self->scriptAlloc, (int)file5, len5, 0, 0);
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->state++;
        }
    } else {
        char* recs = self->records;
        volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
        bgcnt[0] = (bgcnt[0] & ~3) | 1;
        bgcnt[1] = (bgcnt[1] & ~3) | 3;
        bgcnt[2] = (bgcnt[2] & ~3) | 2;
        bgcnt[3] = bgcnt[3] & ~3;
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;

        self->motionTarget = recs;
        self->motion[0] = 0x8000;
        self->motion[1] = -0x3000;
        self->motion[2] = 0x3000;
        self->motion[3] = -0x3000;
        self->motion[4] = 0x3000;
        func_ov005_02154d18(&self->motionTarget, 0x85000, 0x17000);
        func_ov005_02154d34(&self->motionTarget, 0x85000, 0x17000);
        func_ov005_02154d50(&self->motionTarget, 0x76000, 0x16000);
        func_ov005_02154d7c(&self->motionTarget, 0x76000, 0x16000);
        self->f1a6c = 0x5000;
        self->f3db8 = 0;
        self->flags.raw |= 0x400;
        func_ov005_021571d0(self);
        self->f1a30 = 0;
        self->flags.bits.b2 = 1;
        self->flags.bits.b3 = 1;

        GameState::GetInstance();
        char* res = (char*)func_ov017_0218b5b0();
        int v = *(int*)(GetField1c_021a193c((int*)(*(int*)(res + 0x3708))) + 0x4fc);
        func_020dc7e8(5, (signed char)v);
        self->effectAlloc.Reset();
        func_ov023_021dc134(self->effect, self->f2d90, 0);
        self->f19b8 |= 0xd0;
        func_ov023_021dbfd0(self->effect, &self->effectAlloc);
        self->f128c = self->fdf4;
        self->f19be = v;
        self->state = 0xff;
        return 1;
    }
    return 0;
}
