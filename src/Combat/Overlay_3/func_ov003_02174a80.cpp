#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kSelfBodyEnd = 0x7ac, kSelfField874 = 0x7f0, kSelfField7D8 = 0x754, kGlobalPrefix = 0x228, kGlobalGap = 0x870 - 0x237 };
extern const char* data_020f2a38;
extern const char data_ov003_0217ed74[];
extern const char data_ov003_0217eda8[];
extern const char data_ov003_0217edc6[];
extern "C" void func_02080654(void*, SafeAllocator*, const char*);
extern "C" void func_020dfc84(void*, SafeAllocator*, const char*, int, int, int);
#else
enum { kSelfBodyEnd = 0x830, kSelfField874 = 0x874, kSelfField7D8 = 0x7d8, kGlobalPrefix = 0x2d8, kGlobalGap = 0x9a0 - 0x2e7 };
#endif

struct StreamHeader02072488 {
    int a;
    int b;
};

struct Allocs02174a80 {
    SafeAllocator a[6];
};

struct Src02174a80 {
    char pad[0x20];
    int w20;
};

struct Glob02174a80 {
    char pad[kGlobalPrefix];
    void* p2d8;
    int w2dc;
    int w2e0;
    unsigned short h2e4;
    unsigned char b2e6;
    char pad2[kGlobalGap];
    int w9a0;
};

struct Ent02174a80 {
    char pad0[4];
    short h4;
    char pad6[0x16];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad1d[3];
};

struct Obj02174a80 {
    char pad0[4];
    void* f4;
    char pad8[0xe0 - 8];
};

struct Rec02174a80 {
    char pad0[2];
    short h2;
    short shorts[0x12];
    unsigned short h28;
    unsigned char b2a;
};

struct Self02174a80 {
    Src02174a80* p0;
    Allocs02174a80* alloc;
    char pad8[4];
    char body[kSelfBodyEnd - 0xc];
    int w830;
    unsigned char b834;
    unsigned char b835;
    unsigned char ids[0x12];
    short shorts[0x12];
    unsigned short h86c;
    short h86e;
    unsigned char b870;
    char pad871[0x89c - 0x871];
    void* p89c;
    Ent02174a80 ents[2];
    Obj02174a80 objs[8];
    char padfe0[0xc];
    int taskId;
    int padff0;
    void* buf;
    char padff8[0x1034 - 0xff8];
    short h1034;
    char pad1036[0x103e - 0x1036];
    unsigned char b103e;
    unsigned char state;
    char pad1040;
    unsigned char b1041;
    char pad1042[4];
    unsigned short h1046;
};


extern "C" void _ZN13SafeAllocator5ResetEv(SafeAllocator*);
extern "C" void _Z16ZeroInit020de848Pv(void*);
extern "C" void func_020dea64(void*, SafeAllocator*, void*, unsigned int, const char*, int);
extern "C" void _Z14ZeroListHeaderP14Struct02072488(StreamHeader02072488*);
extern "C" void _Z24InitCommandStreamSessioniiP12StreamHeaderi(StreamHeader02072488*, SafeAllocator*, int, int);
extern "C" void* _Z15GetData02108d18v(void);
extern "C" short _Z18GetHalfwordCheckedP12List0206f7f4i(void*, int);
extern "C" Rec02174a80* _Z21FindEntryById020725d8P12List020725d8i(StreamHeader02072488*, int);
extern "C" void _Z15InitObj02174408P18InitStruct02174408(void*);
#if !defined(jpn)
extern "C" void func_020dfc84(void*, SafeAllocator*, char*, char*, int, int);
#endif
extern "C" int func_020dfd40(void*, int, int);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, SafeAllocator*);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void MapVRAMBanksToMainObj(int);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, int*, int*);
extern "C" void func_0204b174(void*, void*, SafeAllocator*, int);
extern "C" void func_0204bc74(void*, int, int, int, int, int, int);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void*, SafeAllocator*, void*, unsigned int);
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*, SafeAllocator*, const char*, const char*);
extern "C" int func_0207f9f4(void*);
extern "C" void _Z18DispatchEntryOp0x8Pvi(void*, int);
extern "C" void func_0205a528(void*, void*, int, SafeAllocator*);
extern "C" Glob02174a80* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_ov003_02176798(void*);

extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern char data_ov003_0217fab4[];
extern char data_ov003_02180af4[];
extern char data_ov003_02180b10[];
extern char data_ov003_02180b2c[];
extern const unsigned char data_ov003_0217fa94[];
extern const unsigned char data_ov003_0217fa90[];
extern char data_ov003_02180b3f[];
extern char data_ov003_02180b55[];
extern char data_ov003_02180b6f[];
extern char data_ov003_02180b77[];
extern char data_ov003_02180b8d[];

// USA: func_ov003_02174a80
// JPN: func_ov003_02173b88
extern "C" ARM void func_ov003_02174a80(Self02174a80* self) {
    Allocs02174a80* allocs;
    BackgroundLoader* loader;
    Ent02174a80* e;
    int i;
    loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        loader->AddFence();
#if defined(jpn)
        self->taskId = loader->QueueLoadGP1(data_020f2a38, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_020f2a38, data_020f2a30, 0);
#endif
        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            SafeAllocator* alloc = &self->alloc->a[0];
            alloc->Reset();
            _Z16ZeroInit020de848Pv((char*)self + kSelfField874);
            func_020dea64((char*)self + kSelfField874, alloc, file, size, data_ov003_0217fab4, 9);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
        }
    }

    if (self->state == 2) {
        self->taskId = loader->QueueLoadFile(data_ov003_02180af4, 0);
        self->state++;
    } else if (self->state == 3) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file;
            unsigned int size;
            StreamHeader02072488 hdr;
            char buf1[0x40];
            char buf2[0x20];
            Allocs02174a80* al;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            al = self->alloc;
            al->a[1].Reset();
            _Z14ZeroListHeaderP14Struct02072488(&hdr);
            _Z24InitCommandStreamSessioniiP12StreamHeaderi(&hdr, &al->a[1], (int)file, size);
            self->h1034 = _Z18GetHalfwordCheckedP12List0206f7f4i(_Z15GetData02108d18v(), 0);
            Rec02174a80* rec = _Z21FindEntryById020725d8P12List020725d8i(&hdr, self->h1034);
            _Z15InitObj02174408P18InitStruct02174408(&self->b834);
            self->b834 = 0x63;
            self->b835 = 5;
            self->shorts[0] = 0x3386;
            self->shorts[1] = 0x2fa5;
            self->shorts[2] = 0x43f2;
            self->shorts[3] = 0x4e36;
            self->shorts[4] = 0x4e36 + 0x490;
            if (rec != 0) {
                short count = 0;
                short i = 0;
                for (; i < 0x12; i++) {
                    self->shorts[i] = rec->shorts[i];
                    self->ids[i] = 0;
                    if (self->shorts[i] <= 0) {
                        self->shorts[i] = -1;
                    } else {
                        count++;
                    }
                }
                self->b834 = 0x63;
                self->b835 = count;
                self->h86e = rec->h2;
                self->h86c = rec->h28;
                self->b870 = rec->b2a;
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
            al = self->alloc;
            al->a[1].Reset();
#if defined(jpn)
            func_020dfc84((char*)self + 0xc, &al->a[1], data_ov003_0217ed74, 0, (short)(self->h86e - 1), -1);
#else
            sprintf(buf1, data_ov003_02180b10, self->h86e - 1);
            sprintf(buf2, data_ov003_02180b2c, self->h86e - 1);
            func_020dfc84((char*)self + 0xc, &al->a[1], buf1, buf2, 0, -1);
#endif
        }
    } else if (self->state == 4) {
        if (func_020dfd40((char*)self + 0xc, 0, 0)) {
            self->state++;
        }
    }

    if (self->state == 5) {
        allocs = self->alloc;
        allocs->a[4].Reset();
        for (i = 0; i < 2; i++) {
            e = &self->ents[i];
            _Z24SetWord0x18ClearByte0x1fPhi(e, 0);
            e->lo = 0;
            e->hi = data_ov003_0217fa94[i];
            func_0204b5b4(e, data_ov003_0217fa90[i]);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(e, &allocs->a[4]);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(e, 0, 0);
        }
        MapVRAMBanksToMainBG(0x10);
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        BG3CNT = (BG3CNT & 0x43) | 0x308 | 0x1c00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        self->taskId = loader->QueueLoadFile(data_ov003_02180b3f, 0);
        self->state++;
    } else if (self->state == 6) {
        if (loader->GetTaskStatus(self->taskId)) {
            int tmp;
            void* file;
            unsigned int size;
            void* recs[12];
            int outs[12];
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
            for (i = 0; i < n; i++) {
                recs[i] = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &tmp, &outs[i]);
            }
            allocs = self->alloc;
            for (i = 0; i < n; i++) {
                if (recs[i] != 0) {
                    func_0204b174(&self->ents[1], recs[i], &allocs->a[4], outs[i]);
                }
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            e = &self->ents[1];
            e->h4 = 3;
            for (i = 0; i < 2; i++) {
                e = &self->ents[i];
                func_0204bc74(e, 0, 0, 0, 0x20, 0x19, 0);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(e, 0);
            }
            self->buf = allocs->a[4].Allocate(0x5000);
            for (i = 0; i < 8; i++) {
                Obj02174a80* o = &self->objs[i];
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(o, &allocs->a[4], self->buf, 0x4cc);
                o->f4 = &self->ents[1];
            }
            self->state++;
        }
    }

    if (self->state == 7) {
        Allocs02174a80* al = self->alloc;
        al->a[5].Reset();
#if defined(jpn)
        func_02080654(self->p89c, &al->a[5], data_ov003_0217eda8);
#else
        _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(self->p89c, &al->a[5], data_ov003_02180b55, data_ov003_02180b6f);
#endif
        self->state++;
    } else if (self->state == 8) {
        int r = func_0207f9f4(self->p89c);
        if (r == 0) {
            self->state++;
        }
        if (r < 0) {
            self->b103e = 9;
        }
    }

    if (self->state == 9) {
        void* p = self->p89c;
        _Z18DispatchEntryOp0x8Pvi(p, 0x21);
        _Z18DispatchEntryOp0x8Pvi(p, 0x2c);
        _Z18DispatchEntryOp0x8Pvi(p, 0x3c);
        _Z18DispatchEntryOp0x8Pvi(p, 0x51);
#if !defined(jpn)
        _Z18DispatchEntryOp0x8Pvi(p, 0x52);
        _Z18DispatchEntryOp0x8Pvi(p, 0x55);
#endif
        _Z18DispatchEntryOp0x8Pvi(p, 0x5c);
        _Z18DispatchEntryOp0x8Pvi(p, 0x5f);
        _Z18DispatchEntryOp0x8Pvi(p, 0x63);
        _Z18DispatchEntryOp0x8Pvi(p, 0x70);
        _Z18DispatchEntryOp0x8Pvi(p, 0x71);
        _Z18DispatchEntryOp0x8Pvi(p, 0x75);
        _Z18DispatchEntryOp0x8Pvi(p, 0xd2);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        MapVRAMBanksToMainObj(0x20);
        DISPCNT = (DISPCNT & 0xffcfffef) | 0x10;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov003_0217edc6, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov003_02180b77, data_ov003_02180b8d, 0);
#endif
        self->state++;
    } else if (self->state == 10) {
        if (loader->GetTaskStatus(self->taskId)) {
            int tmp;
            void* file;
            unsigned int size;
            int out;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
            allocs = self->alloc;
            allocs->a[3].Reset();
            for (i = 0; i < n; i++) {
                void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &tmp, &out);
                func_0205a528((char*)self + kSelfField7D8, rec, out, &allocs->a[3]);
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            Glob02174a80* g = _Z26GetGlobalField0x1c020421a0v();
            g->p2d8 = (char*)self + kSelfField7D8;
            g->w2dc = self->w830;
            if (self->p0 != 0) {
                g->w2e0 = self->p0->w20;
            }
            g->h2e4 = 0;
            g->b2e6 = 0;
            self->state++;
        }
    }

    if (self->state == 11) {
        if (_Z26GetGlobalField0x1c020421a0v()->w9a0 == 3) {
            self->h1046 |= 0x40;
            self->b1041 = 0;
            func_ov003_02176798(self);
            self->b103e = 1;
            self->state = 0;
        }
    }
}
