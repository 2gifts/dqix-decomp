#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"


#if defined(jpn)
enum { kEntryManagerMode = 3, kResourceByte = 0xc9 };
enum { kScenePrefix = 0x110, kSceneExtraPadding = 8, kGlobalPrefix = 0x868, kManagerPrefix = 0x20, kFirstAllocation = 0x48, kManagerAllocation = 0x34, kResourceSlot = 0x524 };
extern "C" void func_02080654(void*, void*, const char*);
extern "C" int func_02081b80(void*, const char*);
extern const char data_ov003_0217e7e0[];
extern const char data_ov003_0217e7fa[];
extern const char data_ov003_0217e814[];
extern const char data_ov003_0217e82a[];
extern const char data_ov003_0217e862[];
extern const char data_ov003_0217e865[];
#else
enum { kEntryManagerMode = 4, kResourceByte = 0xcd };
enum { kScenePrefix = 0x228, kSceneExtraPadding = 0x464 - 0x39c, kGlobalPrefix = 0x998, kManagerPrefix = 0x2c, kFirstAllocation = 0x78, kManagerAllocation = 0x40, kResourceSlot = 0x734 };
#endif

extern "C" void func_ov003_021602bc(void* self);
extern "C" void func_ov003_021672e4(void* a, int b, int c);
extern "C" void _Z15ClearSevenWordsP13Struct205563c(void* a);
extern "C" void func_02032e58(void* a);
extern "C" void func_0207f84c(void* a);
extern "C" void func_0204c684(void* a);
extern "C" void func_020dfec0(void* a, void* b, void* c, unsigned int d);
extern "C" void func_0204b5b4(void* a, int b);
extern "C" void func_0204b174(void* a, void* b, void* c, int d);
extern "C" void func_0204bc74(void* a, int b, int c, int d, int e, int f, int g);
extern "C" void func_0205a528(void* a, void* b, int c, void* d);
extern "C" int func_0207f9f4(void* a);
extern "C" void func_02081224(void* a, int b);
extern "C" void* func_0205ec34();
extern "C" void _Z17ResetList0204af64P12List0204af64(void* a);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void* a, int b);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void* a, void* b);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void* a, int b, int c);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void* a, int b, void* c);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void* a, void* b, void* c, unsigned int d);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* a);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* a, int b, void** c, int* d);
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void* a, void* b, const char* c, const char* d);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z18DispatchEntryOp0x8Pvi(void* a, int b);
extern "C" void _Z28SetEntryValueAndFlag02081058Pvii(void* a, int b, int c);
extern "C" void _Z38SetSublistEntryField14LowBits_02080798Pvii(void* a, int b, int c);
extern "C" void _Z12Init0205a198P14Struct0205a198(void* a);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(void* a);
extern "C" void _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(void* a, int b, int c, void* d, SafeAllocator* e, int f, int g);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void* a, void* b);
extern "C" void _Z20WrapAddByteField0x22iPcji(void* a, void* b, unsigned int c, int d);
extern "C" void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(void* a, void* b, int c);
extern "C" unsigned char _Z34CheckField0AndBattleState_02160b50v(void* a);
extern "C" int _Z18TestBitInByteArrayiPhi(void* a, void* b, int c);
extern "C" void _Z20SetOrClearBitInArrayPvPhii(void* a, void* b, int c, int d);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char data_ov003_0217fff0[];
extern char data_ov003_0218000a[];
extern char data_ov003_0218001b[];
extern char data_ov003_02180035[];
extern int data_ov003_0217f454[];
extern int data_ov003_0217f460[];
extern char data_ov003_02180046[];
extern char data_ov003_0218005a[];
extern char data_ov003_0218006a[];
extern char data_ov003_02180083[];
extern short data_ov003_0217f46c[];
extern char data_ov003_0218008a[];

struct ListEnt {
    char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1[3];
};

struct ObjEnt {
    char pad0[4];
    void* field4;
    char pad1[0xe0 - 8];
};

struct Mgr {
    char pad0[kManagerPrefix];
    void* field2c;
    char pad1[0x38 - 0x30];
    unsigned char b38;
    char pad2;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
};

struct Entry28 {
    char pad[0x28];
};

struct Global998 {
    char pad[kGlobalPrefix];
    int f998;
    char pad2[4];
    int f9a0;
};

struct Scene021615bc {
    char pad0[kScenePrefix];
    SafeAllocator a228;
    char pad1[0x264 - 0x228 - sizeof(SafeAllocator)];
    SafeAllocator a264;
    SafeAllocator a278;
    SafeAllocator a28c;
    SafeAllocator a2a0;
    SafeAllocator a2b4;
    SafeAllocator a2c8;
    char x2dc[0x3c];
    void* p318;
    void* p31c;
    void* p320;
    Mgr* p324;
    ListEnt* p328;
    ObjEnt* p32c;
    char pad2[4];
    char x334[0x3c];
    void* p370;
    void* p374;
    char pad3[0x380 - 0x378];
    unsigned short h380;
    char pad3b[2];
    unsigned char b384;
    char pad4[3];
    Entry28* p388;
    void* p38c;
    void* p390;
    void** p394;
    void* p398;
    char pad5[kSceneExtraPadding];
    unsigned int flags464;
    char pad6[4];
    int taskId;
    char pad7[0xc];
    short jpHiraganaEntry;
    short jpKatakanaEntry;
    short h480;
    short h482;
    short h484;
    short h486;
    char pad8[0x49e - 0x488];
    unsigned char b49e;
    char pad9[2];
    unsigned char b4a1;
    char pad10;
    unsigned char b4a3;
    unsigned char step;
    unsigned char b4a5;
    char pad11;
    unsigned char b4a7;
};

// USA: func_ov003_021615bc
// JPN: func_ov003_021616a4
extern "C" ARM void func_ov003_021615bc(Scene021615bc* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ListEnt* l;
    int i;
    int x;
    int k;
    if (self->step == 0) {
        self->a228.Reset();
        self->p318 = self->a228.Allocate(kFirstAllocation);
        self->p31c = self->a228.Allocate(0x1c);
        self->p320 = self->a228.Allocate(0x130);
        self->p324 = (Mgr*)self->a228.Allocate(kManagerAllocation);
        self->p328 = (ListEnt*)self->a228.Allocate(0x60);
        self->p32c = (ObjEnt*)self->a228.Allocate(0x380);
        self->p394 = (void**)self->a228.Allocate(0x10);
        func_ov003_021602bc(self);
        func_ov003_021672e4(self->p318, 0, -1);
        _Z15ClearSevenWordsP13Struct205563c(self->p31c);
        func_02032e58(self->p320);
        func_0207f84c(self->p324);
        for (int i = 0; i < 3; i++) {
            _Z17ResetList0204af64P12List0204af64(self->p328 + i);
        }
        for (int i = 0; i < 4; i++) {
            func_0204c684(self->p32c + i);
        }
        if (self->flags464 & 0x10000) {
#if defined(jpn)
            self->taskId = loader->QueueLoadFile(data_ov003_0217e7e0, NULL);
#else
            self->taskId = loader->QueueLoadFileInGP2(data_ov003_0217fff0, data_ov003_0218000a, NULL);
#endif
        } else {
#if defined(jpn)
            self->taskId = loader->QueueLoadFile(data_ov003_0217e7fa, NULL);
#else
            self->taskId = loader->QueueLoadFileInGP2(data_ov003_0218001b, data_ov003_02180035, NULL);
#endif
        }
        self->step = self->step + 1;
    }
    if (self->step == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            self->a2b4.Reset();
            func_020dfec0(self->x2dc, &self->a2b4, data, len);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->step = self->step + 1;
        }
    }
    if (self->step == 2) {
        self->a264.Reset();
        for (i = 0; i < 3; i++) {
            l = self->p328 + i;
            _Z24SetWord0x18ClearByte0x1fPhi(l, 0);
            k = data_ov003_0217f454[i];
            l->lo = 0;
            l->hi = k;
            func_0204b5b4(l, data_ov003_0217f460[i]);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(l, &self->a264);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(l, 0, 0);
            if (k == 3) {
                _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(l, 5, &self->a264);
            }
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG2CNT = (BG2CNT & 0x43) | 0x1f00;
        BG3CNT = (BG3CNT & 0x43) | 0x1d08;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 2, 9, 0xa, 6);
#if defined(jpn)
            self->taskId = loader->QueueLoadFile(data_ov003_0217e814, NULL);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov003_02180046, data_ov003_0218005a, NULL);
#endif
        self->step = self->step + 1;
    }
    if (self->step == 3) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* recs[8];
            int idx[8];
            void* out;
            void* data;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(data);
            for (int i = 0; i < n; i++) {
                recs[i] = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(data, i, &out, &idx[i]);
            }
            for (int i = 0; i < n; i++) {
                if (recs[i] != NULL) {
                    if (i == 0) {
                        func_0204b174(self->p328 + 1, recs[i], &self->a264, idx[i]);
                    } else {
                        func_0204b174(self->p328 + 2, recs[i], &self->a264, idx[i]);
                    }
                }
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            ListEnt* l;
            for (int i = 0; i < 3; i++) {
                l = self->p328 + i;
                func_0204bc74(l, 0, 0, 0, 0x20, 0x19, 0);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(l, NULL);
            }
            self->a278.Reset();
            self->p398 = self->a278.Allocate(0x6000);
            ObjEnt* o;
            for (int i = 0; i < 4; i++) {
                o = self->p32c + i;
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(o, &self->a278, self->p398, 0x400);
                o->field4 = self->p328 + 1;
            }
            self->step = self->step + 1;
        }
    }
    if (self->step == 4) {
        self->a28c.Reset();
#if defined(jpn)
        func_02080654(self->p324, &self->a28c, data_ov003_0217e82a);
#else
        _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(self->p324, &self->a28c, data_ov003_0218006a, data_ov003_02180083);
#endif
        self->step = self->step + 1;
    }
    if (self->step == 5) {
        int r = func_0207f9f4(self->p324);
        if (r == 0) {
            self->step = self->step + 1;
        }
        if (r < 0) {
            self->b4a3 = 0x10;
        }
    }
    if (self->step == 6) {
#if defined(jpn)
        Mgr* m = self->p324;
        m->b3b = 0x12;
        m->b3c = 0x10;
#endif
        if (self->flags464 & 0x20000) {
            Global998* g = (Global998*)_Z26GetGlobalField0x1c020421a0v();
            if (g->f998 != 0 && g->f9a0 != 3) {
                return;
            }
            self->flags464 &= ~0x20000;
        }
#if !defined(jpn)
        Mgr* m = self->p324;
        m->b3b = 0x12;
        m->b3c = 0x10;
        _Z18DispatchEntryOp0x8Pvi(m, 0);
        _Z18DispatchEntryOp0x8Pvi(m, 1);
        short* p = data_ov003_0217f46c;
        for (;;) {
            if (*p < 0) {
                break;
            }
            _Z28SetEntryValueAndFlag02081058Pvii(m, *p, 0x90);
            p++;
        }
        _Z28SetEntryValueAndFlag02081058Pvii(m, 0xc1, 0x9c);
        _Z28SetEntryValueAndFlag02081058Pvii(m, 0xc2, 0x9c);
        _Z28SetEntryValueAndFlag02081058Pvii(m, 0xc3, 0x9c);
        short id = 0x64;
        for (int i = 0; i < 8; i++) {
            _Z38SetSublistEntryField14LowBits_02080798Pvii(m, id, 1);
            id++;
        }
#endif
        self->a2a0.Reset();
        self->p388 = (Entry28*)self->a2a0.Allocate(0x3e8);
        self->p38c = self->a2a0.Allocate(8);
        for (int i = 0; i < 0x19; i++) {
            _Z12Init0205a198P14Struct0205a198(self->p388 + i);
        }
        _Z23ClearField0And40205a234P19ClearTarget0205a234(self->p38c);
        self->b384 = 0;
        self->p374 = self->p388;
        self->h380 = 0x19;
        self->p370 = self->p38c;
        self->a2c8.Reset();
        self->p390 = self->a2c8.Allocate(0x24);
        _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(self->p390, 0, 1, self->p38c, &self->a2c8, kEntryManagerMode, 0x40);
        self->taskId = loader->QueueLoadFile(data_ov003_0218008a, NULL);
        self->step = self->step + 1;
    }
    if (self->step == 7) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* out;
            void* data;
            unsigned int len;
            int idx;
            loader->GetLoadedFileByID(self->taskId, &data, &len);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(data);
            for (int i = 0; i < n; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(data, i, &out, &idx);
                func_0205a528(self->x334, rec, idx, &self->a2a0);
            }
            _Z20WrapAddByteField0x22iPcji(self->x334, self->p388, 0x19, 0x40);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->step = self->step + 1;
        }
    }
    if (self->step == 8) {
        Mgr* m = self->p324;
#if defined(jpn)
        self->jpHiraganaEntry = func_02081b80(m, data_ov003_0217e862);
        self->jpKatakanaEntry = func_02081b80(m, data_ov003_0217e865);
#endif
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 2;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 2, 9, 0xa, 6);
        m->field2c = self->p328;
        m->b38 = 2;
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(m, self->p32c, 4);
        m->b3a = 2;
#if !defined(jpn)
        func_02081224(m, 0x19);
        func_02081224(m, 0x1a);
        func_02081224(m, 0x1b);
        self->b49e = _Z34CheckField0AndBattleState_02160b50v(self);
#endif
        char* save = (char*)func_0205ec34();
        if (self->flags464 & 0x10000) {
            self->b4a3 = 0xa;
            self->step = 0;
        } else if (self->b4a1 == 1) {
            self->b4a3 = 4;
            self->step = 2;
        } else if (self->b4a1 == 2) {
            self->b4a3 = 4;
            self->step = 0;
        } else if (self->b4a1 == 3) {
            self->h484 = 0x50;
            self->h486 = 2;
            self->step = 0;
            self->b4a5 = 0;
            self->b4a3 = 1;
            self->flags464 |= 0x10;
            char* g = (char*)func_ov017_0218b5b0();
            self->h482 = *(unsigned char*)(*(char**)(g + 0x3000 + kResourceSlot) + kResourceByte);
        } else if (self->b4a1 == 4) {
            self->h484 = 0xd;
            self->h486 = 2;
            self->step = 0;
            self->b4a5 = 0;
            self->b4a3 = 1;
            self->flags464 |= 8;
        } else {
#if defined(jpn)
            self->b49e = _Z34CheckField0AndBattleState_02160b50v(self);
#endif
            if (self->b49e != 0 && self->b49e != 1) {
                if (self->b49e == 2) {
                    x = 3;
                }
            } else {
                x = 0;
            }
            self->h484 = x;
            self->h486 = -1;
            int flag = 1;
            GameObject* prot = GameState::GetInstance()->GetProtagonist();
            if (prot != NULL && (**(unsigned int**)((char*)prot + 0x130) & 1)) {
                self->h484 = 3;
                self->h486 = -1;
                flag = 0;
            }
            if (flag != 0 && self->b49e != 2) {
                if (_Z18TestBitInByteArrayiPhi(save, save + 0x8c, 0x77e) == 0) {
                    _Z20SetOrClearBitInArrayPvPhii(save, save + 0x8c, 0x77e, 1);
                    self->h484 = 0x4b;
                    self->h486 = x;
                }
            }
            self->b4a3 = 1;
            self->step = 0;
            self->b4a5 = 0;
        }
        self->flags464 |= 0x1000;
        self->b4a7 = 0;
    }
}
