#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" int _Z10GetWord0x0Pi(void* obj);
extern "C" void func_ov005_02155424(void* self);
extern "C" void func_ov005_02155544(void* self);
extern "C" void func_ov005_021555c0(void* self);
extern "C" void func_ov005_021571d0(void* self);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z15Set3DClearColoriiiii(int color, int alpha, int depth, int polygonId, int fog);
extern "C" void _Z15SetBitsInField4Pjj(unsigned int* obj, unsigned int bits);
extern "C" int* _Z15GetData02105254v();
extern "C" void _Z24SetupBankModeAndTransferPiii(int* obj, int a, int b);
extern "C" void _Z19TailForward0203b66cPc(int* obj);
extern "C" void _Z25ClearThreeRegions0203b634Pc(int* obj);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void* obj, int value);
extern "C" void func_0204b5b4(void* obj, int value);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void* obj, int a, int b);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void* obj, SafeAllocator* alloc);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void* obj, int count, SafeAllocator* alloc);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(void* container, int key);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* entry);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* rec, int index, void** out, int* out44);
extern "C" void func_0204b174(void* obj, void* data, SafeAllocator* alloc, int field44);
extern "C" void func_0204bc74(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void* obj, void* buf);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void* obj, unsigned int a, int b, int c, short d, short e, short f, short g, unsigned short h);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(void* s, void* arr, unsigned char count);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(void* obj);
extern "C" int _Z27FindMatchingRecords0204684cP11Rec020467f0PKcPPviPiS4_(void* table, const char* name, void** outData, int maxCount, int* outField44, void** outRec);
extern "C" void _Z25RestorePairTables0207df90Pc(void* p);
extern "C" void _Z24BackupPairTables0207dfacPc(void* p);
extern "C" void _Z15Forward02047b30Pviii(void* a, int b, int c, int d);
extern "C" void _Z17ClearObj_021e1318P11Obj021e1318(void* obj);
extern "C" void _Z25InitScriptAndRun_021e133cPvS_iiis(void* a, void* b, int c, int d, int e, short f);
extern "C" void func_ov005_02154d18(void* obj, int a, int b);
extern "C" void func_ov005_02154d34(void* obj, int a, int b);
extern "C" void func_ov005_02154d50(void* obj, int a, int b);
extern "C" void func_ov005_02154d7c(void* obj, int a, int b);
extern "C" char* _Z19GetField1c_021a193cPi(int p);
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
    SafeAllocator alloc;                   // 0x0000
    char pad0[0x21c - sizeof(SafeAllocator)];
    SafeAllocator fileAlloc;               // 0x021c
    char pad1[0x244 - 0x21c - sizeof(SafeAllocator)];
    SafeAllocator effectAlloc;             // 0x0244
    char pad2[0x258 - 0x244 - sizeof(SafeAllocator)];
    SafeAllocator scriptAlloc;             // 0x0258
    char pad3[0x294 - 0x258 - sizeof(SafeAllocator)];
    char pairTables[0xdf4 - 0x294];        // 0x0294
    int fdf4;                              // 0x0df4
    char container[0xe10 - 0xdf8];         // 0x0df8
    int fe10;                              // 0x0e10
    char pad4[0xe84 - 0xe14];
    List0215436c lists[3];                 // 0x0e84
    char linkHead[0xf7c - 0xee4];          // 0x0ee4
    List0215436c* linkList;                // 0x0f7c
    char pad5[0xf96 - 0xf80];
    unsigned char linkFlag;                // 0x0f96
    char pad6[0xfa0 - 0xf97];
    char elems[3][0xe0];                   // 0x0fa0
    void* buffer;                          // 0x1240
    char effect[0x128c - 0x1244];          // 0x1244
    int f128c;                             // 0x128c
    char pad7[0x19b8 - 0x1290];
    unsigned short f19b8;                  // 0x19b8
    char pad8[0x19be - 0x19ba];
    unsigned char f19be;                   // 0x19be
    char pad9[0x19e0 - 0x19bf];
    char script[0x1a30 - 0x19e0];          // 0x19e0
    unsigned char f1a30;                   // 0x1a30
    char pad10[0x1a34 - 0x1a31];
    void* motionTarget;                    // 0x1a34
    int motion[0x1a6c - 0x1a38 >> 2];      // 0x1a38
    int f1a6c;                             // 0x1a6c
    char records[0x2d90 - 0x1a70];         // 0x1a70
    short f2d90;                           // 0x2d90
    char pad11[0x3da9 - 0x2d92];
    unsigned char f3da9;                   // 0x3da9
    unsigned char f3daa;                   // 0x3daa
    char pad12[0x3db8 - 0x3dab];
    unsigned char f3db8;                   // 0x3db8
    char pad13[0x3dc4 - 0x3db9];
    unsigned char state;                   // 0x3dc4
    char pad14[3];
    int handle;                            // 0x3dc8
    Flags0215436c flags;                   // 0x3dcc
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
    int word = _Z10GetWord0x0Pi(gs);
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
        self->fe10 = *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
        _Z15Set3DClearColoriiiii(0, 0, 0x7fff, 0, 0);
        _Z15SetBitsInField4Pjj((unsigned int*)word, 0x800);
        int* bank = _Z15GetData02105254v();
        _Z24SetupBankModeAndTransferPiii(bank, 0, 1);
        _Z19TailForward0203b66cPc(bank);
        _Z25ClearThreeRegions0203b634Pc(bank);

        _Z24SetWord0x18ClearByte0x1fPhi(&self->lists[0], 0);
        self->lists[0].lo = 0;
        self->lists[0].hi = 1;
        func_0204b5b4(&self->lists[0], 3);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&self->lists[0], 0, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(&self->lists[0], &self->alloc);
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(&self->lists[0], 6, &self->alloc);

        _Z24SetWord0x18ClearByte0x1fPhi(&self->lists[1], 0);
        self->lists[1].lo = 0;
        self->lists[1].hi = 2;
        func_0204b5b4(&self->lists[1], 2);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&self->lists[1], 0, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(&self->lists[1], &self->alloc);
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(&self->lists[1], 9, &self->alloc);

        _Z24SetWord0x18ClearByte0x1fPhi(&self->lists[2], 0);
        self->lists[2].lo = 0;
        self->lists[2].hi = 3;
        func_0204b5b4(&self->lists[2], 0);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&self->lists[2], 0, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(&self->lists[2], &self->alloc);

        volatile unsigned short* bgcnt = (volatile unsigned short*)0x400000a;
        bgcnt[0] = (bgcnt[0] & 0x43) | 0x1d00;
        bgcnt[1] = (bgcnt[1] & 0x43) | 0x1e00;
        bgcnt[2] = (bgcnt[2] & 0x43) | 0x1f04;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xa, 6);

        const char* inner = _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x3e9);
        const char* gp2 = _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x3e8);
        self->handle = loader->QueueLoadFileInGP2(gp2, inner, 0);
        self->state++;
    } else if (self->state == 3) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file3, &len3);
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(file3);
            for (int i = 0; i < count; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file3, i, &recData, &recSize);
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
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[1], 0);
            func_0204bc74(&self->lists[2], 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[2], 0);
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->lists[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[0], 0);
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->lists[0], 1, 0, 0, 0, 0x14, 0x10, 2, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[0], 0);

            self->buffer = self->alloc.Allocate(0x2400);
            char* elem;
            for (int j = 0; j < 3; j++) {
                elem = self->elems[j];
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(elem, &self->alloc, (int)self->buffer, data_ov005_0215cd68[j]);
                *(List0215436c**)(elem + 4) = &self->lists[2];
            }
            self->linkList = &self->lists[2];
            self->linkFlag = 1;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(self->linkHead, self->elems, 3);

            const char* name = _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x3ea);
            self->handle = loader->QueueLoadFile(name, 0);
            self->state++;
        }
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &len4);
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(file4);
            int mode = _Z24NormalizeField5_0200fb08P14Struct0200fb08(gs);
            int n = 0;
            const char* name = _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x7d0);
            if (_Z27FindMatchingRecords0204684cP11Rec020467f0PKcPPviPiS4_(file4, name, datas, count, sizes, 0) != 0) {
                _Z25RestorePairTables0207df90Pc(self->pairTables);
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
                    _Z15Forward02047b30Pviii(self->records + n * 0x88, (int)datas[i], sizes[i], (int)((char*)self + 0x14));
                    n++;
                }
                _Z24BackupPairTables0207dfacPc(self->pairTables);
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
            _Z17ClearObj_021e1318P11Obj021e1318(self->script);
            _Z25InitScriptAndRun_021e133cPvS_iiis(self->script, &self->scriptAlloc, (int)file5, len5, 0, 0);
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
        int v = *(int*)(_Z19GetField1c_021a193cPi(*(int*)(res + 0x3708)) + 0x4fc);
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
