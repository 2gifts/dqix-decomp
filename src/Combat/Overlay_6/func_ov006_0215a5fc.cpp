#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"

extern int data_02109bf4;
extern char data_ov006_0216026c[];
extern char data_ov006_02160286[];
extern char data_ov006_02160297[];
extern char data_ov006_021602ab[];
extern char data_ov006_021602bb[];
extern char data_ov006_021602d2[];
extern char data_ov006_021602e7[];
extern char data_ov006_021602f8[];
extern char data_ov006_0216030a[];
extern char data_ov006_02160318[];
extern char data_ov006_0216032e[];
extern char data_ov006_02160340[];
extern char data_ov006_02160359[];

int GetWord0x0(int* obj);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(void*, int);
extern "C" void _Z11SetFogStateijjt(int, unsigned int, unsigned int, short);
void Set3DClearColor(int, int, int, int, int);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*, const char*, const char*, void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned int*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(void*);
extern "C" void func_020dfec0(void*, void*, void*, unsigned int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void _Z15ClearListHeaderP14Struct02071be8(void*);
extern "C" void _Z25RunBufferedStream02071c00iiP12StreamHeaderi(void*, unsigned int, void*, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void*, int, void*);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, unsigned int);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);
extern "C" void func_0204c684(void*);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void*, void*, void*, unsigned int);
void ClearFields_021e20c0(void*);
extern "C" void func_ov023_021e20f0(void*, void*, void*, unsigned int);
extern "C" void* func_ov006_02157368(void*, int);
extern "C" void func_0205a528(void*, void*, void*, void*);
extern "C" void _Z18InitStruct0205a444Pc(const char*);
void Zero4Bytes(void*);
extern "C" void func_020e5604(void*, void*, void*, unsigned int);
extern "C" void func_0207f84c(void*);
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*, int, int, int);
extern "C" int func_0207f9f4(void*);
void DispatchEntryOp0x10(void*, int);
extern "C" void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(void*, void*, int);
void DispatchEntryOp0x8(void*, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int*, int, int, int, int);
extern "C" void func_ov006_02158de0(void*);
extern "C" void func_ov006_02153744(void*, void*, void*, int);
extern "C" void _Z28FilterAndSortEntries02071ffcP17Container02071ffciiisPs(void*, int, int, int, short, short*);
void ComputeField_02158cac_02158cac(void*);
extern "C" void func_ov006_02153c60(void*, int, unsigned short);
extern "C" void func_ov006_0215373c(void*, void*);
extern "C" void _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(void*, int, int);
extern "C" void func_020813ec(void*, int);
extern "C" void* _Z21FindElementByByte0xc4P7Obj2081i(void*, int);
extern "C" void __clear(void*, int);
void* GetGlobalField0x1c020421a0();
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" void func_02046608(void*, int, void*, void*, int, int, int);
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(void*, int, void*);

struct Node14 {
    unsigned char pad[0x2c];
    void* f2c;
    unsigned char pad2[0x38 - 0x30];
    unsigned char f38;
    unsigned char pad3;
    unsigned char f3a;
};

struct Canvas {
    unsigned char pad[0xb8];
    unsigned short fb8;
    unsigned short fba;
};

struct Nib {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Scene {
    unsigned char pad00[0x08];
    void* f08;
    void* alloc;
    unsigned char pad10[0x04];
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    unsigned char pad28[0x04];
    int f2c;
    int f30;
    unsigned char pad34[0x04];
    int f38;
    unsigned char pad3c[0x54 - 0x3c];
    unsigned char f54[0x1c];
    unsigned char f70;
    unsigned char pad71[0x74 - 0x71];
    unsigned char f74[0xac - 0x74];
    unsigned char fac[0xe8 - 0xac];
    int fe8;
    int fec;
    unsigned char padf0[0xf8 - 0xf0];
    unsigned short ff8;
    unsigned char padfa[0xfc - 0xfa];
    unsigned char ffc;
    unsigned char padfd[0x100 - 0xfd];
    unsigned char f100[0x14c - 0x100];
    int f14c;
    unsigned char pad150[0x158 - 0x150];
    unsigned char f158[0x170 - 0x158];
    unsigned char f170[0x300 - 0x170];
    unsigned char f300[0x54];
    int f354;
    unsigned char pad358[0x35c - 0x358];
    short* f35c;
    unsigned char pad360[0x384 - 0x360];
    signed char f384;
    signed char f385;
    unsigned char f386;
    unsigned char pad387[0x38f - 0x387];
    unsigned char f38f;
    unsigned char f390;
    unsigned char pad391[0x394 - 0x391];
    unsigned short f394;
};

struct Frame {
    short sel;
    unsigned char pad0[2];
    unsigned int cs;
    void* cd;
    int rbs;
    unsigned int cbs;
    void* cbd;
    void* rbd;
    unsigned int c9s;
    void* c9d;
    int r7s;
    unsigned int c7s;
    void* c7d;
    void* r7d;
    unsigned int c5s;
    void* c5d;
    unsigned int c3s;
    void* c3d;
    unsigned char buf[0x400];
};

// USA: func_ov006_0215a5fc
extern "C" ARM void func_ov006_0215a5fc(Scene* obj) {
    Frame f;
    GetWord0x0((int*)GameState::GetInstance());
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    unsigned char st = obj->f390;

    if (st == 0) {
        if ((obj->f394 & 2) == 0) {
            _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(&data_02109bf4, 8);
        }
        _Z11SetFogStateijjt(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        FontBankLoader* g = GetGlobal02109400();
        BlankFunction02094b40(g);
        BlankFunction02094b34(g, 0x6c, 0x1fd, 0, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 1) {
        if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 2) {
        obj->f354 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, data_ov006_0216026c, data_ov006_02160286, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 3) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.c3d, &f.c3s);
            if (f.c3d != 0) {
                void* alloc = obj->alloc;
                _ZN13SafeAllocator5ResetEv((char*)alloc + 0x14);
                _Z19ResetStruct020dfc40P14Struct020dfc40((char*)obj + 0x158);
                func_020dfec0((char*)obj + 0x158, (char*)alloc + 0x14, f.c3d, f.c3s);
            }
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 4) {
        obj->f354 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, data_ov006_02160297, data_ov006_021602ab, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 5) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.c5d, &f.c5s);
            if (f.c5d != 0) {
                void* alloc = obj->alloc;
                _ZN13SafeAllocator5ResetEv(alloc);
                _Z15ClearListHeaderP14Struct02071be8((char*)obj + 0x14c);
                _Z25RunBufferedStream02071c00iiP12StreamHeaderi((char*)obj + 0x14c, (unsigned int)alloc, f.c5d, (int)f.c5s);
            }
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 6) {
        volatile unsigned short* bg = (volatile unsigned short*)0x04001008;
        bg[0] = (bg[0] & 0x43) | 0x10 | 0x1000;
        bg[1] = (bg[1] & 0x43) | 0x1010 + 0x100;
        bg[2] = (bg[2] & 0x43) | 0x1010 + 0x200;
        *(volatile unsigned short*)0x0400100e = (*(volatile unsigned short*)0x0400100e & 0x43) | 0x1300;
        memset(GetSubBG0ScreenBase(), 0, 0x800);
        *(volatile unsigned int*)0x04001010 = 0;
        _ZN13SafeAllocator5ResetEv((char*)obj->alloc + 0x3c);
        _Z17ResetList0204af64P12List0204af64((char*)obj + 0x54);
        _Z24SetWord0x18ClearByte0x1fPhi((char*)obj + 0x54, 0);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf) | 1);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf0) | 0x30);
        func_0204b5b4((char*)obj + 0x54, 3);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((char*)obj + 0x54, 0, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((char*)obj + 0x54, (char*)obj->alloc + 0x3c);
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((char*)obj + 0x54, 7, (char*)obj->alloc + 0x3c);
        obj->f354 = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(
            loader, data_ov006_021602bb, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 7) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.c7d, &f.c7s);
            void* rec;
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(f.c7d);
            int i;
            for (i = 0; i < n; i++) {
                rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(f.c7d, i, &f.r7d, &f.r7s);
                if (rec != 0) {
                if (i == 0) {
                    int j;
                    for (j = 0; j < 2; j++) {
                        unsigned char* o = (unsigned char*)obj->f1c + (j << 5);
                        _Z17ResetList0204af64P12List0204af64(o);
                        _Z24SetWord0x18ClearByte0x1fPhi(o, 0);
                        Nib* nib = (Nib*)(o + 0x1c);
                        nib->lo = 1;
                        nib->hi = (unsigned char)(j + 1);
                        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(o, 0, 0);
                        func_0204b5b4(o, j + 1);
                        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(o, (char*)obj->alloc + 0x3c);
                        func_0204b174(o, rec, (char*)obj->alloc + 0x3c, f.r7s);
                    }
                }
                else {
                    func_0204b174((char*)obj + 0x54, rec, (char*)obj->alloc + 0x3c, f.r7s);
                }
                }
            }
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((char*)obj + 0x54, 0);
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 8) {
        void* alloc = obj->alloc;
        _ZN13SafeAllocator5ResetEv((char*)alloc + 0x50);
        unsigned int i;
        for (i = 0; i < 7; i = (i + 1) & 0xff) {
            void* o = (char*)obj->f20 + i * 0xe0;
            func_0204c684(o);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(o, (char*)alloc + 0x50, obj->f08, 0x600);
            *(unsigned int*)((char*)o + 4) = (unsigned int)obj->f1c;
        }
        obj->f354 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, data_ov006_021602d2, data_ov006_021602e7, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 9) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.c9d, &f.c9s);
            if (f.c9d != 0) {
                void* alloc = obj->alloc;
                _ZN13SafeAllocator5ResetEv((char*)alloc + 0x78);
                ClearFields_021e20c0((char*)obj + 0x100);
                func_ov023_021e20f0((char*)obj + 0x100, (char*)alloc + 0x78, f.c9d, f.c9s);
                unsigned char* e = (unsigned char*)func_ov006_02157368((char*)obj + 0x100, 1);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
                e = (unsigned char*)func_ov006_02157368((char*)obj + 0x100, 0x23);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
                e = (unsigned char*)func_ov006_02157368((char*)obj + 0x100, 0x24);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
            }
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 0xa) {
        _Z18InitStruct0205a444Pc((char*)obj + 0xac);
        obj->ffc = 1;
        obj->fec = (int)obj->f24;
        obj->ff8 = 0x1d;
        obj->fe8 = *(int*)((char*)obj->f18 + 0x20);
        obj->f354 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, data_ov006_021602f8, data_ov006_0216030a, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xb) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.cbd, &f.cbs);
            void* alloc;
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(f.cbd);
            alloc = obj->alloc;
            _ZN13SafeAllocator5ResetEv((char*)alloc + 0x8c);
            int i;
            for (i = 0; i < n; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(f.cbd, i, &f.rbd, &f.rbs);
                if (rec != 0) {
                func_0205a528((char*)obj + 0xac, rec, (void*)f.rbs, (char*)alloc + 0x8c);
                }
            }
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
            int j;
            for (j = 0; j < 8; j++) {
                *((unsigned char*)obj->f24 + (j + 0x12) * 0x28 + 0x22) = 0x18;
            }
        }
    }
    else if (st == 0xc) {
        obj->f354 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(
            loader, data_ov006_02160318, data_ov006_0216032e, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xd) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, obj->f354) != 0) {
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, obj->f354, &f.cd, &f.cs);
            if (f.cd != 0) {
                void* alloc = obj->alloc;
                _ZN13SafeAllocator5ResetEv((char*)alloc + 0x28);
                Zero4Bytes((char*)obj + 0x170);
                func_020e5604((char*)obj + 0x170, (char*)alloc + 0x28, f.cd, f.cs);
            }
            _ZN16BackgroundLoader10RemoveTaskEi(loader, obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 0xe) {
        void* alloc = obj->alloc;
        _ZN13SafeAllocator5ResetEv((char*)alloc + 0x64);
        func_0207f84c(obj->f14);
        _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(
            obj->f14, (unsigned int)alloc + 0x64, (int)data_ov006_02160340, (int)data_ov006_02160359);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xf) {
        int res = func_0207f9f4(obj->f14);
        if (res == 0) {
            obj->f390 = obj->f390 + 1;
        }
        if (res < 0) {
            obj->f38f = 0xc;
        }
    }
    else if (st == 0x10) {
        DispatchEntryOp0x10(obj->f14, 1);
        {
            Node14* n2 = (Node14*)obj->f14;
            n2->f2c = obj->f1c;
            n2->f38 = 2;
        }
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(obj->f14, obj->f20, 7);
        ((Node14*)obj->f14)->f3a = 1;
        DispatchEntryOp0x8(obj->f14, 0x20);
        DispatchEntryOp0x8(obj->f14, 0x3e);
        volatile unsigned short* bg = (volatile unsigned short*)0x04001008;
        bg[0] = bg[0] & ~3;
        bg[1] = (bg[1] & ~3) | 1;
        bg[2] = (bg[2] & ~3) | 2;
        bg[3] = (bg[3] & ~3) | 3;
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)((char*)bg + 0x48), 4, 0x18, 0xa, 6);
        func_ov006_02158de0(obj);
        obj->f38f = 1;
        obj->f390 = 0;
        func_ov006_02153744((char*)obj + 0x74, (char*)obj + 0x14c, (void*)obj->f38, 0x1d8 - 1);
        _Z28FilterAndSortEntries02071ffcP17Container02071ffciiisPs(
            (char*)obj + 0x14c, -1, -1, 0, 0, (short*)((char*)obj + 0x35c));
        f.sel = 0;
        _Z28FilterAndSortEntries02071ffcP17Container02071ffciiisPs(
            (char*)obj + 0x14c, obj->f384, obj->f385, obj->f386, 0x10, &f.sel);
        int v = obj->f14c;
        obj->f2c = v;
        obj->f30 = v;
        ComputeField_02158cac_02158cac(obj);
        func_ov006_02153c60((char*)obj + 0x74, obj->f38, 0x1d7);
        func_ov006_0215373c((char*)obj + 0x74, (char*)obj + 0x14c);
        if ((obj->f394 & 2) == 0) {
            _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(obj->f14, 0, 1);
            _Z24SetEntryFlag0x2ByShortIdP19StatusOwner02081164ii(obj->f14, 1, 1);
            func_020813ec(obj->f14, 0);
            func_020813ec(obj->f14, 1);
            Canvas* cv = (Canvas*)_Z21FindElementByByte0xc4P7Obj2081i(obj->f14, 1);
            if (cv != 0) {
                cv->fb8 = 0xc;
                cv->fba = 0x10;
            }
            __clear(f.buf, 0x400);
            void* g = GetGlobalField0x1c020421a0();
            void* r = _Z21GetFieldByKey020e0434P17Container020e0310i((char*)obj + 0x158, 0);
            func_02046608(g, 0xc, r, f.buf, 0xe3, 0, 1);
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii(obj->f14, 1, f.buf);
            func_020813ec(obj->f14, 1);
        }
    }
}
