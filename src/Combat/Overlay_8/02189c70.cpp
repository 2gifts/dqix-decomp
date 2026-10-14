#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02189c70 func_ov008_0218a930
#define LOW_REGION(j,u) (j)
#define func_02099304 func_0209b000
#else
#define LOW_REGION(j,u) (u)
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "std_library_functions.h"
#include "System/Memory.h"
#include "System/OverlayId.h"

struct Name10_02189c70 { char c[10]; };

struct MapMeta02189c70 {
    unsigned char state;
    char discoveredBy[10];
    char clearedBy[10];
    unsigned char location;
    unsigned char flags;
    unsigned char quality;
    unsigned char level;
    unsigned short seed;
};

#if defined(jpn)
struct RegularMapNames02189c70 {
    char pad[0x3b];
    char prefix[0x20];
    char suffix[0x20];
    char locale[0x20];
    char level[8];
};
struct LegacyMapNames02189c70 {
    char pad[0x90];
    char name[0x20];
    char suffix[0x20];
    char level[8];
};
struct Detail02189c70 {
    unsigned char f0;
    unsigned char type;
    char pad2[0x4c - 2];
    union {
        RegularMapNames02189c70 regular;
        LegacyMapNames02189c70 legacy;
        char all[0x1e4 - 0x4c];
    } names;
};
#else
struct Detail02189c70 {
    unsigned char f0;
    unsigned char type;
    char pad2[LOW_REGION(0x87 - 2,0xaf - 2)];
    char nameA[LOW_REGION(0xdc - 0x87,0x144 - 0xaf)];
    char nameB[LOW_REGION(0x1e4 - 0xdc,0x1c4 - 0x144)];
};
#endif

struct Region02189c70 {
    unsigned char count;
    unsigned char pad1;
    MapMeta02189c70 entries[99];
    char pad_ad6[2];
};

struct NameSrc02189c70 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    char pad3;
    unsigned short f4;
    unsigned char f6;
    char name1[0xc];
    char name2[0xd];
    int f20;
    unsigned char f24;
    char pad25;
    unsigned short f26;
};

struct Id02189c70 {
    unsigned char b[6];
};

struct Slot02189c70 {
    Id02189c70 id;
    char pad6[0x14 - 6];
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    short f28;
    unsigned char f2a;
    unsigned char f2b;
};

struct Quest02189c70 {
    char pad0[0xb];
    unsigned char b0b_lo : 7;
    unsigned char active : 1;
    unsigned int kind : 4;
    unsigned int f0c_hi : 28;
    unsigned int f10;
    char pad14[0x2e - 0x14];
    unsigned char flag2e : 1;
    unsigned char b2e_hi : 7;
    char pad2f[0x50 - 0x2f];
    MapMeta02189c70 meta;
};

struct EntFlags02189c70 {
    char pad0[0x414];
    unsigned char bit0 : 1;
    unsigned char hi : 7;
    int GetBit0() { return bit0; }
};

struct EntHead02189c70 {
    char pad0[0x88];
};

struct EntBlk02189c70 {
    char pad0[0x44];
};

struct Ent02189c70 {
    char pad0[0x44];
    EntBlk02189c70 blk[2];
};

struct Stat02189c70 {
    char pad0[LOW_REGION(0x8b8,0x950)];
    int f950;
#if defined(jpn)
    int GetKind() const { return f950; }
#endif
};

struct Member02189c70 {
    char pad0[LOW_REGION(0x144,0x150)];
    Stat02189c70* f150;
};

struct Window02189c70 {
    void* f0;
    char pad4[0x10 - 4];
    void* f10;
#if defined(jpn)
    char pad14[0x2c - 0x14];
    char* text;
    char pad30[0x218 - 0x30];
#else
    char pad14[0x2c8 - 0x14];
#endif
    int f2c8;
    char pad2cc[LOW_REGION(0x868 - 0x21c,0x998 - 0x2cc)];
    int busy;
    int f99c;
    char pad9a0[LOW_REGION(0x17e2 - 0x870,0x19b2 - 0x9a0)];
    unsigned char f19b2;
};

struct Sub3b84 {
    char pad0[9];
    unsigned char f9;
    char padA[0x28 - 0xa];
    char rec[0x2c];
};

struct Sub3b4c {
    char pad0[2];
    unsigned char f2;
};

struct Res02189c70 {
    char pad0[LOW_REGION(0x392c,0x3b4c)];
    Sub3b4c* f3b4c;
    char pad3b50[0x3b84 - 0x3b50];
    Sub3b84* f3b84;
};

struct Self02189c70 {
    char pad0[0x250];
    SafeAllocator alloc;
    char pad_after_alloc[LOW_REGION(0xddc,0xde0) - 0x250 - sizeof(SafeAllocator)];
    void* de0;
    char pad_de4[0xdf0 - 0xde4];
    Id02189c70 id;
    char pad_df6[0xe04 - 0xdf6];
    int e04;
    int e08;
    int e0c;
    int e10;
    int e14;
    short e18;
    unsigned char e1a;
    unsigned char e1b;
    unsigned int e1c_lo : 21;
    unsigned int e1c_f21 : 4;
    unsigned int e1c_b25 : 1;
    unsigned int e1c_b26 : 1;
    unsigned int e1c_hi : 5;
    unsigned int e20_lo : 9;
    int e20_f9 : 10;
    int e20_f19 : 11;
    unsigned int e20_hi : 2;
    unsigned char e24;
    char pad_e25[0xe98 - 0xe25];
    unsigned char e98;
    unsigned char e99;
    signed char state;
    unsigned char e9b;
    unsigned char e9c;
    char pad_e9d[0xeac - 0xe9d];
    int eac;
#if !defined(jpn)
    int eb0;
#endif
    char pad_eb4[0xeb9 - 0xeb4];
    signed char member;
    unsigned char eba;
    unsigned char ebb;
    Quest02189c70* ebc;
    unsigned char ec0_b0 : 1;
    unsigned char ec0_b1 : 1;
    unsigned char ec0_hi : 6;
    char pad_ec1[3];
    void* ec4;
    unsigned int ec8;
};

#if defined(jpn)
extern char data_ov008_0218c184[];
extern char data_ov008_0218c196[];
extern "C" void func_020474a8(Window02189c70*, int, char*, char*);
extern "C" void func_0204500c(Window02189c70*, char*, int);
#endif
void* GetGlobalField0x1c020421a0();
extern "C" int func_0202ae18();
extern "C" void func_020728ac(void* table, SafeAllocator* alloc, void* data, unsigned int size, int a, int b, int c);
void* GetDataPtr02114e04_020d6c00();
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_ov008_0218b240(Self02189c70* self);
Ent02189c70* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void func_02042764(void* src, void* dst, int flag);
struct TableA68;
char* FindEntryByKey_02072a68(TableA68*, int);
struct Container020e0310;
char* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_02099304(void* name, void* a1, void* a2, unsigned int a3, char* buf, int bufSize, int flag, char* p1, char* p2);
extern "C" void func_02046380(void* w);
extern "C" void* func_0205ec34();
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
void SetOrClearBitInArray_0206df6c(void*, unsigned char*, int, int);
void InitObjFromCombatantId020e4bf4(void* obj, int id);
extern "C" void func_02046608(Window02189c70* w, int a, char* str, char* buf, int b, int c, int d);
#if !defined(jpn)
extern "C" void func_0204500c(Window02189c70* w, char* str, int a, int b);
#endif
extern "C" int func_0202c508(int v);
extern "C" int func_020457e0(Window02189c70* w);
void AllocateFreeSlot0218b1e0(void* obj);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
extern "C" void func_020a3720();
struct DetailedTreasureMapData;
bool ExportDetailedTreasureMapData(TreasureMapMetadata const*, DetailedTreasureMapData*, bool, unsigned char const*);
extern "C" void func_020a395c();
void CopyStringToIndexedField0x2ec_020464e8(char*, int, char*);
extern "C" void func_020e4b34(void* obj, void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
int GetField0x397cValue_020100b0(GameState* gs);
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
void CopyOutBattleRegion0x64f4_020ac760(void* dst);
void CopyToBattleRegion0x64f4_020ac734(void* src);
struct Src02011818;
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e_02011ab8(char*);
void CopyStringToField0x649e_02011a74(char*, unsigned int, char const*);
extern "C" void func_ov017_021a9ff0(int v);
extern "C" void func_020a1940(unsigned int id);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);

static inline EntFlags02189c70* GetEntFlags02189c70(Ent02189c70* ent, int i) {
    return (EntFlags02189c70*)&ent->blk[i];
}

// USA: func_ov008_02189c70
extern "C" ARM void func_ov008_02189c70(Self02189c70* self) {
    char buf400[0x400];
    char buf100[0x100];
    char buf80[0x80];
    Detail02189c70 detail3;
    Region02189c70 region;
    Detail02189c70 detail5;
    Detail02189c70 detail7;
#if !defined(jpn)
    char obj150[0xc];
    char obj144[0xc];
#endif

    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Window02189c70* win = (Window02189c70*)GetGlobalField0x1c020421a0();
    Res02189c70* res = (Res02189c70*)func_ov017_0218b5b0();
    Sub3b84* sub = res->f3b84;
    int token = func_0202ae18();

    if (self->state == 0) {
#if defined(jpn)
        if ((self->e98 & 2) && loader->GetTaskStatus(self->eac)) {
            void* archive;
            void* data;
            unsigned int archiveSize;
            unsigned int size;
            int failed = 0;
            loader->GetLoadedFileByID(self->eac, &archive, &archiveSize);
            if (!GetFileInNarc(archive, data_ov008_0218c184, (const void**)&data, &size, 0))
                failed = 1;
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->de0 = (char*)self + 0x280;
            self->ec0_b1 = 1;
            if (!GetFileInNarc(archive, data_ov008_0218c196, (const void**)&data, &size, 0))
                failed = 1;
            if (failed) {
                loader->RemoveTask(self->eac);
                ResetEntryList0205d6a0((Entry_0205d6a0*)((char*)self + 0x18), 1);
                self->e99 = 2;
                self->state = 0;
                self->e9b = 2;
                self->e9c = 0;
                return;
            }
            self->ec4 = data;
            self->ec8 = size;
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2f);
            ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);
            self->state = self->state + 1;
        }
#else
        if ((self->e98 & 2) && loader->GetTaskStatus(self->eac) && loader->GetTaskStatus(self->eb0)) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->eac, &data, &size);
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->de0 = (char*)self + 0x280;
            self->ec0_b1 = 1;
            loader->GetLoadedFileByID(self->eb0, &data, &size);
            self->ec4 = data;
            self->ec8 = size;
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2f);
            ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);
            self->state = self->state + 1;
        }
#endif
    } else if (self->state == 1) {
        Member02189c70* m = (Member02189c70*)gs->GetPartyMemberByIndex(self->member);
        Ent02189c70* ent = 0;
        int base;
        char* name;
#if !defined(jpn)
        char clr1[0x30];
        __clear(clr1, 0x30);
#endif
        if (self->ebc == 0) {
            if (m == 0) {
                func_ov008_0218b240(self);
                return;
            }
            ent = GetFieldAt0x150_02053c6c((unsigned char*)m);
            base = (signed char)m->f150->f950;
#if defined(jpn)
            name = (char*)self + 0xdf2;
#else
            func_02042764((char*)self + 0xdf6, clr1, 1);
            name = clr1;
#endif
        } else {
#if defined(jpn)
            name = (char*)self->ebc;
#else
            func_02042764(self->ebc, clr1, 1);
            name = clr1;
#endif
            base = (signed char)self->ebc->kind;
        }
        if (ent != 0 && !self->e1c_b26) {
            EntFlags02189c70* fl = GetEntFlags02189c70(ent, 1);
            self->e1c_b25 = fl->bit0;
            self->e1c_f21 = fl->bit0;
            self->e20_f9 = 300;
            int key = 20700;
#if !defined(jpn)
            if (fl->bit0 == 1) key += 50;
#endif
#if defined(jpn)
            self->e20_f19 = m->f150->GetKind() + 700;
#else
            self->e20_f19 = key - 20000 + m->f150->f950;
#endif
            self->e24 = 0;
        }
        int mode = self->ebc != 0 ? 3 : 1;
        char* title = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x280), (short)(self->e20_f9 + 10000));
        char* body;
        int v = self->e20_f19;
        if (v < 700) {
            body = GetFieldByKey020e0434((Container020e0310*)((char*)self + 0x288), (short)v);
        } else if (v < 800) {
            int key = 20700;
#if !defined(jpn)
            if (self->e1c_b25 == 1) key += 50;
#endif
            body = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x280), (short)(base + key));
        } else {
            body = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x280), (short)(v + 20000));
        }
        func_02099304((char*)self + LOW_REGION(0xe18,0xe1c), name, self->ec4, self->ec8, buf400, 0x400, mode, title, body);
        func_02046380(win);
        int found = 0;
        char* p = buf400;
        p += strlen(buf400);
        if (self->ebc == 0) {
            void* flags = func_0205ec34();
            if (!TestBitInByteArray_0206dfb0((int)flags, (unsigned char*)((char*)flags + 0x8c), 0x119b)) {
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x66);
                int len = strlen(str);
                memcpy(p, str, len);
                p += len;
                SetOrClearBitInArray_0206df6c(flags, (unsigned char*)((char*)flags + 0x8c), 0x119b, 1);
            }
#if defined(jpn)
            unsigned char* countp;
            Slot02189c70* slot;
            int i;
            countp = (unsigned char*)gs + 0x3bc + 0x6c00;
#else
            Slot02189c70* slot;
            int i;
            unsigned char* countp = (unsigned char*)gs + 0x1fc + 0x7000;
#endif
            slot = (Slot02189c70*)(countp + 4);
            Id02189c70 id = self->id;
            for (i = 0; i < *countp; i++, slot++) {
                Id02189c70 tmp = id;
                int same;
                int j;
                for (j = 0; j < 6; j++) {
                    if (tmp.b[j] != slot->id.b[j]) {
                        same = 0;
                        goto compared;
                    }
                }
                same = 1;
            compared:
                if (same) {
                    slot->f14 = self->e04;
                    slot->f18 = self->e08;
                    slot->f1c = self->e0c;
                    slot->f20 = self->e10;
                    slot->f24 = self->e14;
                    slot->f28 = self->e18;
                    slot->f2a = self->e1a;
                    slot->f2b = self->e1b;
                    found = 1;
                    break;
                }
            }
            memset(buf100, 0, 0x100);
            if (!found) {
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x64);
#if defined(jpn)
                SetIndexedName02046574((Obj02046574*)win, 0, name);
                func_020474a8(win, 0xc, str, buf100);
#else
                InitObjFromCombatantId020e4bf4(obj144, self->member);
                win->f10 = obj144;
                func_02046608(win, 0xc, str, buf100, 0xe3, 0, 1);
#endif
                memcpy(p, buf100, strlen(buf100));
            }
        }
        if (!self->e1c_b25) win->f99c = 0; else win->f99c = 2;
        win->f19b2 = 1;
#if defined(jpn)
        func_0204500c(win, buf400, 0);
#else
        func_0204500c(win, buf400, 0, 0xe3);
#endif
        win->busy = 1;
        loader->RemoveTask(self->eac);
#if !defined(jpn)
        loader->RemoveTask(self->eb0);
#endif
        self->eac = -1;
#if !defined(jpn)
        self->eb0 = -1;
#endif
        if (self->ebc != 0) {
            if (self->ebc->active && func_0202c508(token)) {
                self->state = 3;
            } else {
                self->state = 2;
            }
        } else if (found) {
            self->state = 2;
        } else {
            self->state = 100;
        }
    } else if (self->state == 100) {
        if (win->busy != 0) return;
        if (func_020457e0(win) == 0) {
            memset(buf80, 0, 0x80);
            if (*((unsigned char*)gs + LOW_REGION(0x6000 + 0xfbc,0x7000 + 0x1fc)) >= 0x10) {
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x69);
                memcpy(buf80, str, strlen(str));
                self->ebb = 1;
            } else {
#if defined(jpn)
                SetIndexedName02046574((Obj02046574*)win, 0, (char*)self + 0xdf2);
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                func_020474a8(win, 0xc, str, buf80);
#else
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                InitObjFromCombatantId020e4bf4(obj144, self->member);
                win->f10 = obj144;
                func_02046608(win, 0xc, str, buf80, 0xe3, 0, 1);
#endif
                AllocateFreeSlot0218b1e0(self);
            }
            if (!self->e1c_b25) win->f99c = 0; else win->f99c = 2;
            win->f19b2 = 1;
#if defined(jpn)
            func_0204500c(win, buf80, 0);
#else
            func_0204500c(win, buf80, 0, 0xe3);
#endif
            win->busy = 1;
        }
        self->state = 2;
    } else if (self->state == 2) {
        if (win->busy != 0) return;
        if (func_020457e0(win) == 0 && self->ebb != 0) {
            memcpy(sub->rec, &self->id, 0x2c);
            sub->f9 = 1;
            self->eba = 1;
        }
        ResetEntryList0205d6a0((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->e99 = 2;
        self->state = 0;
        self->e9b = 2;
        self->e9c = 0;
    } else if (self->state == 3) {
        if (win->busy != 0) return;
        MapMeta02189c70 meta3 = self->ebc->meta;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&meta3, (DetailedTreasureMapData*)&detail3, 0, (unsigned char const*)0);
        func_020a395c();
#if defined(jpn)
        if (detail3.type == 1) {
            RegularMapNames02189c70* names = &detail3.names.regular;
            SetIndexedName02046574((Obj02046574*)win, 2, names->prefix);
            SetIndexedName02046574((Obj02046574*)win, 3, names->suffix);
            SetIndexedName02046574((Obj02046574*)win, 4, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
            SetIndexedName02046574((Obj02046574*)win, 5, names->level);
        } else if (detail3.type == 2) {
            LegacyMapNames02189c70* names = &detail3.names.legacy;
            SetIndexedName02046574((Obj02046574*)win, 2, names->name);
            SetIndexedName02046574((Obj02046574*)win, 3, names->suffix);
            SetIndexedName02046574((Obj02046574*)win, 5, names->level);
        } else {
            self->state = 2;
            return;
        }
#else
        if (detail3.type == 1) {
            CopyStringToIndexedField0x2ec_020464e8((char*)win, 2, detail3.nameA);
        } else if (detail3.type == 2) {
            CopyStringToIndexedField0x2ec_020464e8((char*)win, 2, detail3.nameB);
        } else {
            self->state = 2;
            return;
        }
#endif
#if defined(jpn)
        SetIndexedName02046574((Obj02046574*)win, 0, (char*)self->ebc);
        SetIndexedName02046574((Obj02046574*)win, 1, *(char**)((char*)gs->GetUnknownGameObject() + 0x134));
#else
        char clr3[0x30];
        __clear(clr3, 0x30);
        func_02042764(self->ebc, clr3, 1);
        func_020e4b34(obj144, clr3, clr3, 0, 0, 0, 0, self->ebc->flag2e, 0, 1, 0, 1);
        InitObjFromCombatantId020e4bf4(obj150, GetField0x397cValue_020100b0(gs));
        win->f10 = obj144;
        win->f0 = obj150;
#endif
        if (ReadBattleField0x64f4Byte_02011804(gs) >= 0x63) {
#if defined(jpn)
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc9), 0);
#else
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc9), 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0);
#else
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0, 0xe3);
#endif
        }
        win->busy = 1;
        win->f19b2 = 0;
        self->state = 4;
    } else if (self->state == 4) {
        if (win->busy != 0) return;
        if (ReadBattleField0x64f4Byte_02011804(gs) >= 0x63) {
#if defined(jpn)
            char* text = win->text;
            char* name = *(char**)((char*)gs->GetUnknownGameObject() + 0x134);
            sprintf(text, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xcb), name);
            win->f2c8 = 1;
            func_0204500c(win, text, 0);
#else
            InitObjFromCombatantId020e4bf4(obj150, GetField0x397cValue_020100b0(gs));
            win->f0 = obj150;
            win->f2c8 = 1;
#if defined(jpn)
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xcb), 0);
#else
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xcb), 0, 0xe3);
#endif
#endif
            win->busy = 1;
            win->f19b2 = 1;
            self->state = 5;
        } else {
            CopyOutBattleRegion0x64f4_020ac760(&region);
            VectorizedMemset(&region.entries[region.count], 0, 0x1c);
            MapMeta02189c70* src = &self->ebc->meta;
            MapMeta02189c70* e = &region.entries[region.count];
            e->state = src->state;
            *(Name10_02189c70*)e->discoveredBy = *(Name10_02189c70*)src->discoveredBy;
            *(Name10_02189c70*)e->clearedBy = *(Name10_02189c70*)src->clearedBy;
            e->location = src->location;
            e->flags = src->flags;
            e->quality = src->quality;
            e->level = src->level;
            e->seed = src->seed;
            region.count++;
            CopyToBattleRegion0x64f4_020ac734(&region);
            self->ebc->active = 0;
            self->state = 2;
        }
    } else if (self->state == 5) {
        if (win->busy != 0) return;
        int r = func_020457e0(win);
        if (r == 0) {
            self->state = 2;
            return;
        }
        if (r != 1) return;
        MapMeta02189c70 meta5 = self->ebc->meta;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&meta5, (DetailedTreasureMapData*)&detail5, 0, (unsigned char const*)0);
        func_020a395c();
        NameSrc02189c70 names;
        VectorizedMemset(&names, 0, 0x28);
        names.name1[0] = 0;
        names.name2[0] = 0;
        names.f6 = 0;
        names.f20 = -1;
        names.f0 = ((TreasureMapMetadata*)&meta5)->GetMapType();
        names.f1 = meta5.quality;
        names.f2 = meta5.level;
        names.f4 = meta5.seed;
        names.f6 = 0;
        strcpy(names.name1, meta5.discoveredBy);
        strcpy(names.name2, meta5.clearedBy);
        names.f24 = meta5.flags;
        if (names.f0 == 2) names.f26 = meta5.seed;
        names.f20 = meta5.location;
        SetNameEntries02011818(gs, (Src02011818*)&names);
#if defined(jpn)
        if (((TreasureMapMetadata*)&meta5)->GetMapType() == 1) {
            RegularMapNames02189c70* names = &detail5.names.regular;
            ClearRegion0x649e_02011ab8((char*)gs);
            CopyStringToField0x649e_02011a74((char*)gs, 0, names->prefix);
            CopyStringToField0x649e_02011a74((char*)gs, 1, names->suffix);
            CopyStringToField0x649e_02011a74((char*)gs, 2, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
            CopyStringToField0x649e_02011a74((char*)gs, 3, names->level);
        } else if (((TreasureMapMetadata*)&meta5)->GetMapType() == 2) {
            LegacyMapNames02189c70* names = &detail5.names.legacy;
            ClearRegion0x649e_02011ab8((char*)gs);
            CopyStringToField0x649e_02011a74((char*)gs, 0, names->name);
            CopyStringToField0x649e_02011a74((char*)gs, 1, names->suffix);
            CopyStringToField0x649e_02011a74((char*)gs, 3, names->level);
        }
#else
        if (((TreasureMapMetadata*)&meta5)->GetMapType() == 1) {
            ClearRegion0x649e_02011ab8((char*)gs);
            CopyStringToField0x649e_02011a74((char*)gs, 0, detail5.nameA);
        } else if (((TreasureMapMetadata*)&meta5)->GetMapType() == 2) {
            CopyStringToField0x649e_02011a74((char*)gs, 0, detail5.nameB);
        }
#endif
        *(unsigned int*)((char*)gs + LOW_REGION(0x61f4,0x6474)) = self->ebc->f10 >> 2;
        func_ov017_021a9ff0(0);
        ResetEntryList0205d6a0((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->state = 2;
    } else if (self->state == 6) {
        if (res->f3b4c->f2 != 0) return;
        func_020a1940(OVERLAY_ID(8));
        self->ec0_b0 = 0;
        self->state = 7;
    } else if (self->state == 7) {
        void* obj = gs->GetUnknownGameObject();
        if (obj != 0) CancelPendingAction020397cc((Obj020397cc*)obj, 1);
        if (*((unsigned char*)gs + LOW_REGION(0x6000 + 0x1ee,0x6000 + 0x46e)) != 0) {
            MapMeta02189c70 meta7 = self->ebc->meta;
            func_020a3720();
            ExportDetailedTreasureMapData((TreasureMapMetadata const*)&meta7, (DetailedTreasureMapData*)&detail7, 0, (unsigned char const*)0);
            func_020a395c();
    #if defined(jpn)
            if (detail7.type == 1) {
            RegularMapNames02189c70* names = &detail7.names.regular;
                SetIndexedName02046574((Obj02046574*)win, 2, names->prefix);
                SetIndexedName02046574((Obj02046574*)win, 3, names->suffix);
                SetIndexedName02046574((Obj02046574*)win, 4, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
                SetIndexedName02046574((Obj02046574*)win, 5, names->level);
            } else if (detail7.type == 2) {
            LegacyMapNames02189c70* names = &detail7.names.legacy;
                SetIndexedName02046574((Obj02046574*)win, 2, names->name);
                SetIndexedName02046574((Obj02046574*)win, 3, names->suffix);
                SetIndexedName02046574((Obj02046574*)win, 5, names->level);
            }
#else
        if (detail7.type == 1) {
                CopyStringToIndexedField0x2ec_020464e8((char*)win, 2, detail7.nameA);
            } else if (detail7.type == 2) {
                CopyStringToIndexedField0x2ec_020464e8((char*)win, 2, detail7.nameB);
            }
#endif
#if defined(jpn)
            SetIndexedName02046574((Obj02046574*)win, 0, (char*)self->ebc);
#else
            char clr7[0x30];
            __clear(clr7, 0x30);
            func_02042764(self->ebc, clr7, 1);
            SetIndexedName02046574((Obj02046574*)win, 0, clr7);
#endif
            SetIndexedName02046574((Obj02046574*)win, 1, *(char**)((char*)gs->GetUnknownGameObject() + 0x134));
#if defined(jpn)
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0);
#else
            func_0204500c(win, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0, 0xe3);
#endif
            win->busy = 1;
            win->f19b2 = 0;
            self->ebc->active = 0;
        }
        self->state = 2;
    }
}
