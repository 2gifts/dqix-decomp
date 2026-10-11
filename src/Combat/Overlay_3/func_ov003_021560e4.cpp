#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"


#if defined(jpn)
enum { kTaskOffset = 0x1cc, kPartyResourceOffset = 0x50c, kGlobalFieldOffset = 0x868, kManagerListOffset = 0x20, kManagerStateOffset = 0x2c, kManagerFlagOffset = 0x2e };
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*, int, char*);
extern "C" void func_02045d88(void*, void*, int);
extern "C" void func_02080654(void*, void*, const char*);
extern const char data_ov003_0217e554[];
extern const char data_ov003_0217e56e[];
extern const char data_ov003_0217e595[];
extern const char data_ov003_0217e5b3[];
extern const char data_ov003_0217e5c9[];
#else
enum { kTaskOffset = 0x1d0, kPartyResourceOffset = 0x71c, kGlobalFieldOffset = 0x998, kManagerListOffset = 0x2c, kManagerStateOffset = 0x38, kManagerFlagOffset = 0x3a };
#endif

extern "C" {
void ColorEffect_ConfigureAlphaBlend(int, int, int, int, int);
int _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
void* _Z17GetGlobal02109400v(void);
int _Z18AlwaysTrue02094b4cv(void*);
int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
int _Z18GetField0x3acValueP9GameState(void*);
void _Z18InitStruct0205a444Pc(void*);
int _Z18TestBitInByteArrayiPhi(void*, void*, int);
void _Z19ResetStruct020dfc40P14Struct020dfc40(void*);
void _Z20ClearFields_021e20c0Pv(void*);
void _Z21BlankFunction02094b34v(void*, int, int, int, int);
void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(void*, void*, int);
void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(void*, void*, int, int);
void _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(void*);
void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
void _Z24SetEntryScaledXY020807fcPviii(void*, int, int, int);
void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
void* _Z25GetGlobalResetObj020d7a50v(void);
void* _Z26GetGlobalField0x1c020421a0v(void);
void _Z27GetEntryFieldsAt0x602080828PviPsS0_(void*, short, short*, short*);
void _Z27GetEntryFieldsAt0xE02080878PviPsS0_(void*, int, short*, short*);
void _Z27SetEntryFieldsAt0x602080854Pviii(void*, short, int, int);
void _Z27SetEntryFieldsAt0xE020808a4Pviii(void*, int, int, int);
void _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(void*);
void _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(void*);
void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void*);
int _Z28CountNonZeroEntries_0215570cP11Obj0215570c(void*);
int _Z29LookupValueByEntryKey02081010Pvi(void*, int);
void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(void*);
void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void*, void*);
void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
void _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(void*, int, short*, short*);
void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(void*, void*, const char*, const char*);
int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void*, int);
void _ZN13SafeAllocator5ResetEv(void*);
int func_020420e8(int, int);
void func_0204500c(void*, void*, int, int);
void func_02046380(void*);
void func_0204b174(void*, void*, int, int);
void func_0204b5b4(void*, int);
void func_0205a528(void*, void*, int, void*);
void* func_0205ec34(void);
int func_0207f9f4(void*);
void func_02094ab0(void*);
void func_020dfec0(void*, void*, void*, unsigned int);
void func_ov003_02156054(void*);
void func_ov023_021e20f0(void*, void*, void*, unsigned int);
}

extern const char data_ov003_0217fce4[];
extern const char data_ov003_0217fcfe[];
extern const char data_ov003_0217fd0f[];
extern const char data_ov003_0217fd23[];
extern const char data_ov003_0217fd33[];
extern const char data_ov003_0217fd46[];
extern const char data_ov003_0217fd60[];
extern const char data_ov003_0217fd68[];
extern const char data_ov003_0217fd7e[];
extern const char data_ov003_0217fd90[];
extern const char data_ov003_0217fdaa[];
struct BytePair {
    unsigned char v[2];
};
extern const BytePair data_ov003_0217f29c[];
extern const short data_ov003_0217f2a0[];
extern const short data_ov003_0217f2ae[];

struct Prio {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Ent20 {
    char pad0[4];
    void* p4;
    char pad8[0x1c - 8];
    Prio b1c;
};

struct Ctrl {
    void* alloc;               // 0x00
    char pad04[0xc - 4];
    int f0c;
    Ent20* f10;
    char* f14;
    char* f18;
    void* f1c;
    char pad20[4];
    int f24;
    char pad28[4];
    char sub2c[0x68 - 0x2c];
    int f68;
    int f6c;
    char pad70[0x78 - 0x70];
    short f78;
    char pad7a[2];
    char f7c;
    char pad7d[0xe4 - 0x7d];
    char sube4[0xfc - 0xe4];
    char subfc[0x114 - 0xfc];
    char sub114[kTaskOffset - 0x114];
    int task;                  // 0x1d0
    char pad1d4[0x1ec - 0x1d4];
    short f1ec;
    short f1ee;
    char f1f0[2];
    unsigned char f1f2;
    char pad1f3[4];
    char f1f7;
    unsigned char mode;        // 0x1f8
    unsigned char state;       // 0x1f9
    char pad1fa;
    unsigned char f1fb;
    unsigned int flags;        // 0x1fc
};

// USA: func_ov003_021560e4
// JPN: func_ov003_02157740
extern "C" ARM void func_ov003_021560e4(Ctrl* self) {
    char* a;
    int state;
    BackgroundLoader* loader;
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (state == 0) {
        if (self->flags & 1) {
            _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        }
        func_ov003_02156054(self);
        void* g = _Z17GetGlobal02109400v();
        func_02094ab0(g);
        _Z21BlankFunction02094b34v(g, 0x66, 0x1f5, 0, 0);
        self->state = self->state + 1;
    } else if (state == 1) {
        if (_Z18AlwaysTrue02094b4cv(_Z17GetGlobal02109400v())) {
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e554, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fce4, data_ov003_0217fcfe, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 2) {
        if (loader->GetTaskStatus(self->task)) {
            int tmp[3];
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            void* a = self->alloc;
            _ZN13SafeAllocator5ResetEv(a);
            _Z19ResetStruct020dfc40P14Struct020dfc40(self->sube4);
            func_020dfec0(self->sube4, a, file, size);
            loader->RemoveTask(self->task);
            self->task = -1;
            char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
            int key = -1;
            if (self->flags & 1) {
                key = 0x1a;
                char* x = (char*)func_ov017_0218b5b0();
                int id = *(short*)(*(char**)(x + 0x3000 + kPartyResourceOffset) + 0x22);
                GameState* gs = GameState::GetInstance();
                GameObject* pm = gs->GetPartyMemberByIndex(id);
                if (pm == 0) {
                    pm = gs->GetPartyMemberByIndex(_Z18GetField0x3acValueP9GameState(gs));
                }
                func_02046380(g);
#if defined(jpn)
                if (pm != 0) {
                    _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, *(char**)((char*)pm + 0x134));
                }
#else
                _Z30InitObjFromCombatantId020e4bf4Pvi(tmp, *(short*)((char*)pm + 4));
                *(void**)g = tmp;
#endif
            } else {
                char* x = (char*)func_0205ec34();
                if (_Z18TestBitInByteArrayiPhi(x, x + 0x8c, 0x799)) {
                    key = 0;
                } else {
                    self->f1ec = 0;
                    self->f1ee = 1;
                    self->mode = 7;
                }
            }
            void* r = _Z21GetFieldByKey020e0434P17Container020e0310i(self->sube4, key);
            if (r) {
#if defined(jpn)
                func_02045d88(g, r, 0);
#else
                func_0204500c(g, r, 0, 0xe3);
#endif
                *(int*)(g + kGlobalFieldOffset) = 1;
                *(int*)(g + kGlobalFieldOffset + 4) = 1;
            }
            _Z18InitStruct0205a444Pc(self->sub2c);
            self->f7c = 0;
            self->f6c = self->f24;
            self->f78 = 10;
            if (self->f1c) {
                self->f68 = *(int*)((char*)self->f1c + 0x20);
            }
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e56e, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd0f, data_ov003_0217fd23, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x3c);
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &p, &len);
                func_0205a528(self->sub2c, rec, len, a + 0x3c);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x14);
            BytePair A = data_ov003_0217f29c[0];
            BytePair B = data_ov003_0217f29c[1];
            for (unsigned char i = 0; i < 2; i++) {
                Ent20* e = self->f10 + i;
                _Z24SetWord0x18ClearByte0x1fPhi(e, 0);
                e->b1c.lo = 0;
                e->b1c.hi = A.v[i];
                func_0204b5b4(e, B.v[i]);
                _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(e, a + 0x14);
                _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(e, 0, 0);
            }
            *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 0x1e00;
            *(volatile unsigned short*)0x400000c = (*(volatile unsigned short*)0x400000c & 0x43) | 0x1f00;
            ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 10, 6);
            self->task = loader->QueueLoadFile(data_ov003_0217fd33, 0);
            self->state = self->state + 1;
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(self->task)) {
            void* p;
            void* file;
            unsigned int size;
            int len;
            loader->GetLoadedFileByID(self->task, &file, &size);
            int n = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
            Ent20* e = self->f10;
            for (int i = 0; i < n; i++) {
                void* rec = (void*)_Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &p, &len);
                func_0204b174(e, rec, 0, len);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            char* a = (char*)self->alloc;
            for (unsigned char j = 0; j < 3; j++) {
                Ent20* ent = (Ent20*)(self->f14 + j * 0xe0);
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(ent, a + 0x14, self->f0c, 0x4cc);
                ent->p4 = self->f10;
            }
            a = (char*)self->alloc;
            _ZN13SafeAllocator5ResetEv(a + 0x28);
#if defined(jpn)
            func_02080654(self->f18, a + 0x28, data_ov003_0217e595);
#else
            _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(self->f18, a + 0x28, data_ov003_0217fd46, data_ov003_0217fd60);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 5) {
        int r = func_0207f9f4(self->f18);
        if (r == 0) {
            self->state = self->state + 1;
        }
        if (r < 0) {
            self->mode = 7;
        }
    } else if (state == 6) {
        void* p = self->f18;
#if !defined(jpn)
        short x, y, w, h;
        _Z32GetSublistEntryScaledXY_020807c4PviPsS0_(p, 2, &x, &y);
        _Z27GetEntryFieldsAt0xE02080878PviPsS0_(p, 2, &w, &h);
        int mx = 0;
        for (int k = 0; k < 2; k++) {
            int v = func_020420e8(_Z29LookupValueByEntryKey02081010Pvi(p, data_ov003_0217f2a0[k]), 0);
            if (mx < v) mx = v;
        }
        w = (mx + 0x1b) & ~7;
        w = w >> 3;
        if (w & 1) w = w + 1;
        x = (0x20 - w) >> 1;
        x = x << 3;
        _Z24SetEntryScaledXY020807fcPviii(p, 2, x, y);
        _Z27SetEntryFieldsAt0xE020808a4Pviii(p, 2, w, h);
#endif
        if (_Z28CountNonZeroEntries_0215570cP11Obj0215570c(self) >= 9) {
            for (unsigned char i = 0; i < 12; i++) {
                for (int j = 0; j < 3; j++) {
                    int idx = i + data_ov003_0217f2ae[j];
                    short a, b;
                    _Z27GetEntryFieldsAt0x602080828PviPsS0_(p, idx, &a, &b);
                    _Z27SetEntryFieldsAt0x602080854Pviii(p, idx, a, (short)(b - 1));
                }
            }
        }
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e5b3, 0);
#else
        self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd68, data_ov003_0217fd7e, 0);
#endif
        self->state = self->state + 1;
    } else if (state == 7) {
        if (loader->GetTaskStatus(self->task)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            if (file) {
                char* a = (char*)self->alloc;
                _ZN13SafeAllocator5ResetEv(a + 0x50);
                _Z20ClearFields_021e20c0Pv(self->sub114);
                func_ov023_021e20f0(self->sub114, a + 0x50, file, size);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
#if defined(jpn)
            self->task = loader->QueueLoadFile(data_ov003_0217e5c9, 0);
#else
            self->task = loader->QueueLoadFileInGP2(data_ov003_0217fd90, data_ov003_0217fdaa, 0);
#endif
            self->state = self->state + 1;
        }
    } else if (state == 8) {
        if (loader->GetTaskStatus(self->task)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &file, &size);
            if (file) {
                void* a = self->alloc;
                _Z19ResetStruct020dfc40P14Struct020dfc40(self->subfc);
                func_020dfec0(self->subfc, a, file, size);
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = self->state + 1;
        }
    } else if (state == 9) {
        char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
        if (*(int*)(g + kGlobalFieldOffset + 8) == 3) {
            char* p = self->f18;
            *(void**)(p + kManagerListOffset) = self->f10;
            *(char*)(p + kManagerStateOffset) = 2;
            _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(p, self->f14, 3);
            *(char*)(p + kManagerFlagOffset) = 1;
            _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(p);
            _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(p);
            _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(p);
            volatile unsigned short* bg = (volatile unsigned short*)0x4000008;
            bg[0] = (bg[0] & ~3) | 2;
            bg[1] = bg[1] & ~3;
            bg[2] = (bg[2] & ~3) | 1;
            bg[3] = (bg[3] & ~3) | 3;
            *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1700;
            self->mode = 7;
            self->state = 0;
            if (self->flags & 1) {
                GameState* gs = GameState::GetInstance();
                if (self->f1fb == 0) {
                    self->f1f7 = _Z18GetField0x3acValueP9GameState(gs);
                    self->state = 0;
                    if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, self->f1f7)) {
                        self->f1ec = 8;
                        self->mode = 7;
                        _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(p);
                    } else {
                        self->flags = self->flags | 2;
                        self->f1ec = 9;
                        self->mode = 3;
                        self->state = 0;
                    }
                } else {
                    self->f1f7 = self->f1f2;
                    self->f1ec = 6;
                    self->mode = 2;
                    self->state = 2;
                }
            } else {
                char* x = (char*)func_0205ec34();
                if (_Z18TestBitInByteArrayiPhi(x, x + 0x8c, 0x796)) {
                    self->f1ec = 4;
                    self->mode = 1;
                } else {
                    self->f1ec = 2;
                    self->mode = 2;
                }
            }
        }
    }
}
