#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

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

int GetWord0x0_0200fb8c(int* obj);
struct Actor0209c3b4;
int SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor_020c5588(int, int, int, int, int);
struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40*);
extern "C" void func_020dfec0(void*, void*, void*, unsigned int);
struct Struct02071be8;
void ClearListHeader(Struct02071be8*);
struct StreamHeader;
void RunBufferedStream02071c00(int, int, StreamHeader*, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
struct List0204af64;
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
extern "C" void func_0204b5b4(void*, int);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
struct SafeAllocator;
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, unsigned int);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
extern "C" void func_0204c684(void*);
struct Obj0204c7a8;
void AllocateBuffer0204c7a8(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
void ClearFields_021e20c0(void*);
extern "C" void func_ov023_021e20f0(void*, void*, void*, unsigned int);
extern "C" void* func_ov006_02157368(void*, int);
extern "C" void func_0205a528(void*, void*, void*, void*);
void InitStruct0205a444(char*);
void Zero4Bytes_020e526c(void*);
extern "C" void func_020e5604(void*, void*, void*, unsigned int);
extern "C" void func_0207f84c(void*);
struct Obj0207f914;
void SetFieldsFromFormattedValue0207f914(Obj0207f914*, int, int, int);
extern "C" int func_0207f9f4(void*);
void DispatchEntryOp0x10_020810a0(void*, int);
struct Manager0207f7f0;
struct Node0207f7f0;
void InitNodeChain0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);
void DispatchEntryOp0x8_0208108c(void*, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int*, int, int, int, int);
extern "C" void func_ov006_02158de0(void*);
extern "C" void func_ov006_02153744(void*, void*, void*, int);
struct Container02071ffc;
void FilterAndSortEntries02071ffc(Container02071ffc*, int, int, int, short, short*);
void ComputeField_02158cac_02158cac(void*);
extern "C" void func_ov006_02153c60(void*, int, unsigned short);
extern "C" void func_ov006_0215373c(void*, void*);
struct StatusOwner02081164;
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020813ec(void*, int);
struct Obj2081;
void* FindElementByByte0xc4_02081da8(Obj2081*, int);
extern "C" void __clear(void*, int);
void* GetGlobalField0x1c020421a0();
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_02046608(void*, int, void*, void*, int, int, int);
struct Container02080f8c;
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);

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
    GetWord0x0_0200fb8c((int*)GameState::GetInstance());
    void* loader = BackgroundLoader::GetInstance();
    unsigned char st = obj->f390;

    if (st == 0) {
        if ((obj->f394 & 2) == 0) {
            SetStateAndDispatch0209c3b4((Actor0209c3b4*)&data_02109bf4, 8);
        }
        SetFogState_020c54a4(0, 0, 0, 0);
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        FontBankLoader* g = GetGlobal02109400_02094a00();
        BlankFunction02094b40(g);
        BlankFunction02094b34(g, 0x6c, 0x1fd, 0, 0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 1) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 2) {
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov006_0216026c, data_ov006_02160286, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 3) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c3d, &f.c3s);
            if (f.c3d != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x14))->Reset();
                ResetStruct020dfc40((Struct020dfc40*)((char*)obj + 0x158));
                func_020dfec0((char*)obj + 0x158, (char*)alloc + 0x14, f.c3d, f.c3s);
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 4) {
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov006_02160297, data_ov006_021602ab, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 5) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c5d, &f.c5s);
            if (f.c5d != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)alloc)->Reset();
                ClearListHeader((Struct02071be8*)((char*)obj + 0x14c));
                RunBufferedStream02071c00((int)((char*)obj + 0x14c), (unsigned int)alloc, (StreamHeader*)f.c5d, (int)f.c5s);
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
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
        ((SafeAllocator*)((char*)obj->alloc + 0x3c))->Reset();
        ResetList0204af64((List0204af64*)((char*)obj + 0x54));
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)((char*)obj + 0x54), 0);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf) | 1);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf0) | 0x30);
        func_0204b5b4((char*)obj + 0x54, 3);
        DispatchViaTable0204b5e8((Obj0204b5e8*)((char*)obj + 0x54), 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)((char*)obj + 0x54), (SafeAllocator*)((char*)obj->alloc + 0x3c));
        AllocateArray0204af38((Foo0204af38*)((char*)obj + 0x54), 7, (SafeAllocator*)((char*)obj->alloc + 0x3c));
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFile(data_ov006_021602bb, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 7) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c7d, &f.c7s);
            void* rec;
            int n = CountActiveEntries((ActiveEntry02046900*)f.c7d);
            int i;
            for (i = 0; i < n; i++) {
                rec = FindRecordByIndex((Rec020467f0*)f.c7d, i, &f.r7d, &f.r7s);
                if (rec != 0) {
                if (i == 0) {
                    int j;
                    for (j = 0; j < 2; j++) {
                        unsigned char* o = (unsigned char*)obj->f1c + (j << 5);
                        ResetList0204af64((List0204af64*)o);
                        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)o, 0);
                        Nib* nib = (Nib*)(o + 0x1c);
                        nib->lo = 1;
                        nib->hi = (unsigned char)(j + 1);
                        DispatchViaTable0204b5e8((Obj0204b5e8*)o, 0, 0);
                        func_0204b5b4(o, j + 1);
                        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)o, (SafeAllocator*)((char*)obj->alloc + 0x3c));
                        func_0204b174(o, rec, (char*)obj->alloc + 0x3c, f.r7s);
                    }
                }
                else {
                    func_0204b174((char*)obj + 0x54, rec, (char*)obj->alloc + 0x3c, f.r7s);
                }
                }
            }
            FlushAndDispatchList0204b0e8((List0204b0e8*)((char*)obj + 0x54), 0);
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 8) {
        void* alloc = obj->alloc;
        ((SafeAllocator*)((char*)alloc + 0x50))->Reset();
        unsigned int i;
        for (i = 0; i < 7; i = (i + 1) & 0xff) {
            void* o = (char*)obj->f20 + i * 0xe0;
            func_0204c684(o);
            AllocateBuffer0204c7a8((Obj0204c7a8*)o, (SafeAllocator*)((char*)alloc + 0x50), (int)obj->f08, 0x600);
            *(unsigned int*)((char*)o + 4) = (unsigned int)obj->f1c;
        }
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov006_021602d2, data_ov006_021602e7, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 9) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c9d, &f.c9s);
            if (f.c9d != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x78))->Reset();
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
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 0xa) {
        InitStruct0205a444((char*)((char*)obj + 0xac));
        obj->ffc = 1;
        obj->fec = (int)obj->f24;
        obj->ff8 = 0x1d;
        obj->fe8 = *(int*)((char*)obj->f18 + 0x20);
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov006_021602f8, data_ov006_0216030a, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xb) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.cbd, &f.cbs);
            void* alloc;
            int n = CountActiveEntries((ActiveEntry02046900*)f.cbd);
            alloc = obj->alloc;
            ((SafeAllocator*)((char*)alloc + 0x8c))->Reset();
            int i;
            for (i = 0; i < n; i++) {
                void* rec = FindRecordByIndex((Rec020467f0*)f.cbd, i, &f.rbd, &f.rbs);
                if (rec != 0) {
                func_0205a528((char*)obj + 0xac, rec, (void*)f.rbs, (char*)alloc + 0x8c);
                }
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
            int j;
            for (j = 0; j < 8; j++) {
                *((unsigned char*)obj->f24 + (j + 0x12) * 0x28 + 0x22) = 0x18;
            }
        }
    }
    else if (st == 0xc) {
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov006_02160318, data_ov006_0216032e, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xd) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.cd, &f.cs);
            if (f.cd != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x28))->Reset();
                Zero4Bytes_020e526c((char*)obj + 0x170);
                func_020e5604((char*)obj + 0x170, (char*)alloc + 0x28, f.cd, f.cs);
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 0xe) {
        void* alloc = obj->alloc;
        ((SafeAllocator*)((char*)alloc + 0x64))->Reset();
        func_0207f84c(obj->f14);
        SetFieldsFromFormattedValue0207f914((Obj0207f914*)obj->f14, (unsigned int)alloc + 0x64, (int)data_ov006_02160340, (int)data_ov006_02160359);
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
        DispatchEntryOp0x10_020810a0(obj->f14, 1);
        {
            Node14* n2 = (Node14*)obj->f14;
            n2->f2c = obj->f1c;
            n2->f38 = 2;
        }
        InitNodeChain0207f7f0((Manager0207f7f0*)obj->f14, (Node0207f7f0*)obj->f20, 7);
        ((Node14*)obj->f14)->f3a = 1;
        DispatchEntryOp0x8_0208108c(obj->f14, 0x20);
        DispatchEntryOp0x8_0208108c(obj->f14, 0x3e);
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
        FilterAndSortEntries02071ffc((Container02071ffc*)((char*)obj + 0x14c), -1, -1, 0, 0, (short*)((char*)obj + 0x35c));
        f.sel = 0;
        FilterAndSortEntries02071ffc((Container02071ffc*)((char*)obj + 0x14c), obj->f384, obj->f385, obj->f386, 0x10, &f.sel);
        int v = obj->f14c;
        obj->f2c = v;
        obj->f30 = v;
        ComputeField_02158cac_02158cac(obj);
        func_ov006_02153c60((char*)obj + 0x74, obj->f38, 0x1d7);
        func_ov006_0215373c((char*)obj + 0x74, (char*)obj + 0x14c);
        if ((obj->f394 & 2) == 0) {
            SetEntryFlag0x2ByShortId((StatusOwner02081164*)obj->f14, 0, 1);
            SetEntryFlag0x2ByShortId((StatusOwner02081164*)obj->f14, 1, 1);
            func_020813ec(obj->f14, 0);
            func_020813ec(obj->f14, 1);
            Canvas* cv = (Canvas*)FindElementByByte0xc4_02081da8((Obj2081*)obj->f14, 1);
            if (cv != 0) {
                cv->fb8 = 0xc;
                cv->fba = 0x10;
            }
            __clear(f.buf, 0x400);
            void* g = GetGlobalField0x1c020421a0();
            void* r = GetFieldByKey020e0434((Container020e0310*)((char*)obj + 0x158), 0);
            func_02046608(g, 0xc, r, f.buf, 0xe3, 0, 1);
            SetEntryFirstField02080f8c((Container02080f8c*)obj->f14, 1, (int)f.buf);
            func_020813ec(obj->f14, 1);
        }
    }
}
