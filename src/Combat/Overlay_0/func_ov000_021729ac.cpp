#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_0203bd08(void);
extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int banks);
extern "C" char* _Z20GetGlobalPtr02105244v();
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(void* obj);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" void _Z16ZeroInit020de848Pv(void* obj);
extern "C" void func_020dea64(void* list, void* alloc, void* data, unsigned int size, const void* entries, int count);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" char* func_ov017_021b8478(void* obj);
extern "C" struct Elem021729ac* _Z20GetElementIfInBoundsP12List02070f98i(void* list, int index);
extern "C" int _Z23GetElementCount02070fe4P14Struct02070fe4(void* list);
extern "C" int func_020de9a4(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(void* container, int key);
extern "C" void _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(void* obj, char* fmt);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z20Clear12Bytes020e46c4Pv(void* buf);
extern "C" void func_02046380(void* g);
extern "C" void func_02046608(void* a, int b, char* c, void* d, int e, int f, int g);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* entry);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* rec, int index, void** out, int* outSize);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);
extern "C" void _Z20WrapAddByteField0x22iPcji(void* a, char* b, unsigned int c, int d);
extern "C" void _Z29SetBitfieldStoreBytes0205af38iPcii(void* a, char* obj, int c, int d);
extern "C" int* _Z15GetData02105254v();
extern "C" void _Z24SetupBankModeAndTransferPiii(int* obj, int a, int b);
extern "C" void _Z19TailForward0203b66cPc(int* obj);
extern "C" void _Z25ClearThreeRegions0203b634Pc(int* obj);
void ConfigureSubBg0Control_02172944(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void ConfigureSubBg1Control_02172978(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void* obj, int value);
extern "C" void func_0204b5b4(void* obj, int value);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void* obj, SafeAllocator* alloc);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void* obj, int count, SafeAllocator* alloc);
extern "C" void func_0204c684(void* obj);
extern "C" char* _Z28CallFunc020e0434With02153694i(int key);
extern "C" void func_0204f914(void* obj, int a, short x0, short y0, short x1, short y1);
extern "C" void func_0204f41c(void* obj, short x, short y, void* str, int d, int e, short* outA, short* outB, int zero);
extern "C" void func_0204b174(void* obj, void* data, SafeAllocator* alloc, int size);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void* obj, unsigned int a, int b, int c, short d, short e, short f, short g, unsigned short h);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void* obj, void* buf);
extern "C" void func_0204bc74(void* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(void* s, void* arr, unsigned char count);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void _Z30InitAndFillIndexBuffer0204c964P14Canvas0204e998(void* canvas);

struct Triple021729ac {
    short value;
    short pad[2];
};

extern char data_ov000_02183ff5[];
extern char data_ov000_0218400f[];
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern char data_ov000_02183302[];
extern const short data_ov000_02183418[];
extern char data_ov000_02184035[];
extern char data_ov000_02184020[];
extern char data_ov000_02184046[];
extern Triple021729ac data_ov000_021833ba[];
extern Triple021729ac data_ov000_021833bc[];
extern Triple021729ac data_ov000_021833be[];

struct Elem021729ac {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
};

struct Source021729ac {
    char pad0[0x684];
    char list[4];
};

struct TextParam021729ac {
    int f0;
    int f4;
    unsigned int lo : 24;
    unsigned int mode : 2;
    unsigned int hi : 6;
};

struct BgField021729ac {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short pad1 : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short bit13 : 1;
    unsigned short screenSize : 2;
};

struct List021729ac {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[3];
};

struct Canvas021729ac {
    char pad0[8];
    char* text;                            // 0x08
    char pad1[0xa8 - 0xc];
    short width;                           // 0xa8
    short height;                          // 0xaa
    char pad2[0xe0 - 0xac];
};

struct Elem0e0_021729ac {
    char pad0[4];
    List021729ac* list;                    // 0x04
    char pad1[0xe0 - 8];
};

struct Menu021729ac {
    char pad0[0xb8];
    char container[0x18];                  // 0x00b8
    char desc[2][0x18];                    // 0x00d0
    char pad1[0x11c - 0x100];
    char records[0x158 - 0x11c];           // 0x011c
    char* f158;                            // 0x0158
    char* f15c;                            // 0x015c
    char pad2[0x168 - 0x160];
    short f168;                            // 0x0168
    char pad3[2];
    unsigned char f16c;                    // 0x016c
    char pad4[3];
    char* f170;                            // 0x0170
    char* f174;                            // 0x0174
    void* buffer;                          // 0x0178
    char pad5[4];
    BgField021729ac bg0;                   // 0x0180
    BgField021729ac bg1;                   // 0x0182
    int banks;                             // 0x0184
    char linkHead[0x220 - 0x188];          // 0x0188
    List021729ac* linkList;                // 0x0220
    char pad6[0x23a - 0x224];
    unsigned char linkFlag;                // 0x023a
    char pad7[0x284 - 0x23b];
    Elem0e0_021729ac elems[7];             // 0x0284
    List021729ac lists[3];                 // 0x08a4
    int planes;                            // 0x0904
    int state;                             // 0x0908
    int handle;                            // 0x090c

#if defined(jpn)
    char pad8[0x1b78 - 0x910];
#else
    char pad8[0x1a78 - 0x910];
#endif

    SafeAllocator allocs[6];               // 0x1a78

#if defined(jpn)
    char pad9[0x1c0c - 0x1bf0];
#else
    char pad9[0x1b54 - 0x1af0];
#endif


#if defined(jpn)
    char entries[2][0x38];
#else
    char entries[2][0x18];
#endif
                 // 0x1b54

#if defined(jpn)
    char labels[5][0x38];
#else
    char labels[9][0x18];
#endif
                  // 0x1b84

#if defined(jpn)
    char pad10[0x1faa - 0x1d94];
#else
    char pad10[0x1d72 - 0x1c5c];
#endif

    unsigned short f1d72;                  // 0x1d72
};

// USA: func_ov000_021729ac
extern "C" ARM int func_ov000_021729ac(Menu021729ac* self) {
    unsigned short codes[0x28];
    char text[0x80];
    Canvas021729ac canvas;
    TextParam021729ac param;
    void* file1;
    unsigned int len1;
    void* file2;
    unsigned int len2;
    void* recData4;
    void* file4;
    unsigned int len4;
    int recSize4;
    void* recData6;
    void* file6;
    unsigned int len6;
    int recSize6;
    short outB;
    short outA;

    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_0203bd08();

    if (self->state == 0) {
        self->planes = (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
        self->banks = GetSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x180);
        *(int*)func_0203bd08() = 0;

#if defined(jpn)
        *(int*)(_Z20GetGlobalPtr02105244v() + 0x608) = 0x1d000;
#else
        *(int*)(_Z20GetGlobalPtr02105244v() + 0x508) = 0x18000;
#endif


#if defined(jpn)
        self->handle = loader->QueueLoadFile(data_ov000_02183ff5, 0);
#else
        self->handle = loader->QueueLoadFileInGP2(data_ov000_02183ff5, data_ov000_0218400f, 0);
#endif

        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file1, &len1);
            if (file1 != 0) {
                self->allocs[1].Reset();
                _Z19ResetStruct020dfc40P14Struct020dfc40(self->container);
                func_020dfec0(self->container, &self->allocs[1], file1, len1);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;

#if defined(jpn)
            self->handle = loader->QueueLoadGP1(data_020f2a38, 0);
#else
            self->handle = loader->QueueLoadFileInGP2(data_020f2a38, data_020f2a30, 0);
#endif

            self->state++;
        }
    } else if (self->state == 2) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file2, &len2);
            if (file2 != 0) {
                self->allocs[4].Reset();
                _Z16ZeroInit020de848Pv(self->desc[0]);
                func_020dea64(self->desc[0], &self->allocs[4], file2, len2, data_ov000_02183302, 3);
                self->allocs[5].Reset();
                _Z16ZeroInit020de848Pv(self->desc[1]);
                __clear(codes, sizeof(codes));
                unsigned short n = 0;

#if defined(jpn)
                Source021729ac* src = (Source021729ac*)func_ov017_021b8478(*(void**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x508));
#else
                Source021729ac* src = (Source021729ac*)func_ov017_021b8478(*(void**)((char*)func_ov017_0218b5b0() + 0x3000 + 0x718));
#endif

                if (src != 0) {
                    void* list = src->list;
                    for (int i = 0; i < _Z23GetElementCount02070fe4P14Struct02070fe4(list); i++) {
                        if (n > sizeof(codes) / sizeof(codes[0])) {
                            break;
                        }
                        Elem021729ac* elem = _Z20GetElementIfInBoundsP12List02070f98i(list, i);
                        if (elem != 0) {
                            codes[n++] = elem->f4;
                            codes[n++] = elem->f6;
                        }
                    }
                }
                func_020de9a4(self->desc[1], &self->allocs[5], file2, len2, codes, n);
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(self->entries[0], _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x754e));
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(self->entries[1], _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, 0x7550));

#if defined(jpn)
            for (int i = 0; i < 5; i++) {
                _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(self->labels[i], _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, data_ov000_02183418[i]));
            }
#else
            void* g = _Z26GetGlobalField0x1c020421a0v();
            for (int i = 0; i < 9; i++) {
                __clear(text, sizeof(text));
                _Z20Clear12Bytes020e46c4Pv(&param);
                if (i >= 5) {
                    param.mode = 1;
                }
                func_02046380(g);
                int key = data_ov000_02183418[i];
                *(void**)g = &param;
                func_02046608(g, 0xa, _Z21GetFieldByKey020e0434P17Container020e0310i(self->container, key), text, 0x100, 0, 0);
                _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(self->labels[i], text);
            }

#endif
            self->state++;
        }
    } else if (self->state == 3) {
        if (self->f174 == 0 || self->f170 == 0) {
            self->state = 3;
        }

#if defined(jpn)

#else
        self->f16c = 1;
#endif

        self->f15c = self->f170;

#if defined(jpn)
        self->f168 = 0x20;
#else
        self->f168 = 0x28;
#endif

        self->f158 = self->f174;

#if defined(jpn)
        self->handle = loader->QueueLoadFile(data_ov000_02184020, 0);
#else
        self->handle = loader->QueueLoadFileInGP2(data_ov000_02184020, data_ov000_02184035, 0);
#endif

        self->state++;
    } else if (self->state == 4) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file4, &len4);
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(file4);
            self->allocs[0].Reset();
            for (int i = 0; i < count; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file4, i, &recData4, &recSize4);
                if (rec != 0) {
                    func_0205a528(self->records, rec, recSize4, &self->allocs[0]);
                }
            }

#if defined(jpn)
            _Z20WrapAddByteField0x22iPcji(self->records, self->f170, (unsigned short)count, 0x40);
#else
            _Z20WrapAddByteField0x22iPcji(self->records, self->f170, (unsigned short)count, 0x44);
#endif

            _Z29SetBitfieldStoreBytes0205af38iPcii(self->records, self->f170 + 0x2a8, 1, 1);
            _Z29SetBitfieldStoreBytes0205af38iPcii(self->records, self->f170 + 0x2d0, 1, 1);
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->state++;
        }
    } else if (self->state == 5) {
        int* bank = _Z15GetData02105254v();
        _Z24SetupBankModeAndTransferPiii(bank, 1, 0);
        _Z24SetupBankModeAndTransferPiii(bank, 1, 1);
        _Z19TailForward0203b66cPc(bank);
        _Z25ClearThreeRegions0203b634Pc(bank);
        ConfigureSubBg0Control_02172944(0, self->bg0.colorMode, 5, self->bg0.charBase, self->bg1.bit13);
        ConfigureSubBg1Control_02172978(0, self->bg1.colorMode, 6, self->bg1.charBase, self->bg1.bit13);
        *(volatile unsigned short*)0x400100c = (*(volatile unsigned short*)0x400100c & 0x43) | 0x704;
        self->allocs[3].Reset();

        List021729ac* list = &self->lists[0];
        _Z24SetWord0x18ClearByte0x1fPhi(list, 0);
        list->lo = 1;
        list->hi = 0;
        func_0204b5b4(list, 2);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(list, &self->allocs[3]);

        list = &self->lists[1];
        _Z24SetWord0x18ClearByte0x1fPhi(list, 0);
        list->lo = 1;
        list->hi = 1;
        func_0204b5b4(list, 3);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(list, &self->allocs[3]);

#if defined(jpn)
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(list, 29, &self->allocs[3]);
#else
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(list, 10, &self->allocs[3]);
#endif


        list = &self->lists[2];
        _Z24SetWord0x18ClearByte0x1fPhi(list, 0);
        list->lo = 1;
        list->hi = 2;
        func_0204b5b4(list, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(list, &self->allocs[3]);

        self->handle = loader->QueueLoadFile(data_ov000_02184046, 0);
        self->state++;
    } else if (self->state == 6) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            loader->GetLoadedFileByID(self->handle, &file6, &len6);
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(file6);
            for (int i = 0; i < count; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file6, i, &recData6, &recSize6);
                if (rec != 0) {
#if !defined(jpn)
                    if (i == 0) {
                        func_0204c684(&canvas);
                        canvas.width = 0x20;
                        canvas.height = 0x20;
                        canvas.text = (char*)rec + 0x10;
                        char* label1;
                        char* label0 = _Z28CallFunc020e0434With02153694i(0xc9);
                        label1 = _Z28CallFunc020e0434With02153694i(0xca);
                        short x;
                        short y0;
                        short y1;
                        for (int k = 0; k < 2; k++) {
                            x = data_ov000_021833ba[k].value;
                            y0 = data_ov000_021833bc[k].value;
                            y1 = data_ov000_021833be[k].value;
                            func_0204f914(&canvas, 3, x, y0, x + 0x10, y0 + 8);
                            func_0204f41c(&canvas, x + 1, y0 - 2, label0, 8, 2, &outA, &outB, 0);
                            func_0204f41c(&canvas, x, y0 - 2, label0, 8, 0xa, &outA, &outB, 0);
                            func_0204f914(&canvas, 3, x, y1, x + 0x10, y1 + 8);
                            func_0204f41c(&canvas, x + 1, y1 - 2, label1, 8, 2, &outA, &outB, 0);
                            func_0204f41c(&canvas, x, y1 - 2, label1, 8, 0xa, &outA, &outB, 0);
                        }
                    }
#endif
                    List021729ac* target = &self->lists[1];
                    if (i == count - 1) {
                        target = &self->lists[2];
                    }
                    func_0204b174(target, rec, &self->allocs[3], recSize6);
                }
            }
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->lists[1], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[1], 0);
            func_0204bc74(&self->lists[0], 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[0], 0);
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(&self->lists[2], 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&self->lists[2], 0);

            self->allocs[2].Reset();
            self->buffer = self->allocs[2].Allocate(0x5c00);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[0], &self->allocs[2], (int)self->buffer, 0x30c);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[1], &self->allocs[2], (int)self->buffer, 0x240);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[2], &self->allocs[2], (int)self->buffer, 0x240);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[3], &self->allocs[2], (int)self->buffer, 0x200);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[4], &self->allocs[2], (int)self->buffer, 0x200);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[5], &self->allocs[2], (int)self->buffer, 0x200);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->elems[6], &self->allocs[2], (int)self->buffer, 0x200);
            for (int j = 0; j < 7; j++) {
                self->elems[j].list = &self->lists[2];
            }
            loader->RemoveTask(self->handle);
            self->handle = -1;
            self->linkList = &self->lists[2];
            self->linkFlag = 1;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(self->linkHead, self->elems, 7);
            self->state++;
            self->f1d72 |= 0x40;
        }
    } else if (self->state == 7) {
        func_020dc7e8(0, -1);
        *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1700;
        *(volatile unsigned short*)0x4001050 = 0;
        _Z30InitAndFillIndexBuffer0204c964P14Canvas0204e998(&self->elems[0]);
        return 1;
    }
    return 0;
}
