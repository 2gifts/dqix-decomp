#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
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

struct Detail02189c70 {
    unsigned char f0;
    unsigned char type;
    char pad2[0xaf - 2];
    char nameA[0x144 - 0xaf];
    char nameB[0x1c4 - 0x144];
};

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
    char pad0[0x950];
    int f950;
};

struct Member02189c70 {
    char pad0[0x150];
    Stat02189c70* f150;
};

struct Window02189c70 {
    void* f0;
    char pad4[0x10 - 4];
    void* f10;
    char pad14[0x2c8 - 0x14];
    int f2c8;
    char pad2cc[0x998 - 0x2cc];
    int busy;
    int f99c;
    char pad9a0[0x19b2 - 0x9a0];
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
    char pad0[0x3b4c];
    Sub3b4c* f3b4c;
    char pad3b50[0x3b84 - 0x3b50];
    Sub3b84* f3b84;
};

struct Self02189c70 {
    char pad0[0x250];
    SafeAllocator alloc;
    char pad_after_alloc[0xde0 - 0x250 - sizeof(SafeAllocator)];
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
    int eb0;
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

extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" int func_0202ae18();
extern "C" void func_020728ac(void* table, SafeAllocator* alloc, void* data, unsigned int size, int a, int b, int c);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(void* p, unsigned int mask);
extern "C" void _Z15ClearBitsInWordPjj(void* p, unsigned int mask);
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_ov008_0218b240(Self02189c70* self);
extern "C" Ent02189c70* _Z15GetFieldAt0x150Ph(Member02189c70* m);
extern "C" void func_02042764(void* src, void* dst, int flag);
extern "C" char* _Z14FindEntryByKeyP8TableA68i(void* table, int key);
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(void* c, int key);
extern "C" void func_02099304(void* name, void* a1, void* a2, unsigned int a3, char* buf, int bufSize, int flag, char* p1, char* p2);
extern "C" void func_02046380(void* w);
extern "C" void* func_0205ec34();
extern "C" int _Z18TestBitInByteArrayiPhi(void* obj, void* arr, int bit);
extern "C" void _Z20SetOrClearBitInArrayPvPhii(void* obj, void* arr, int bit, int set);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void* obj, int id);
extern "C" void func_02046608(Window02189c70* w, int a, char* str, char* buf, int b, int c, int d);
extern "C" void func_0204500c(Window02189c70* w, char* str, int a, int b);
extern "C" int func_0202c508(int v);
extern "C" int func_020457e0(Window02189c70* w);
extern "C" void _Z24AllocateFreeSlot0218b1e0Pv(void* obj);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void* p, int flag);
extern "C" void func_020a3720();
extern "C" bool _Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(const MapMeta02189c70* from, Detail02189c70* to, int a, int b);
extern "C" void func_020a395c();
extern "C" void _Z29CopyStringToIndexedField0x2ecPciS_(Window02189c70* w, int idx, char* str);
extern "C" void func_020e4b34(void* obj, void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern "C" int _Z19GetField0x397cValueP9GameState(GameState* gs);
extern "C" unsigned char _Z25ReadBattleField0x64f4Bytev(GameState* gs);
extern "C" void _Z25CopyOutBattleRegion0x64f4Pv(void* dst);
extern "C" void _Z24CopyToBattleRegion0x64f4Pv(void* src);
extern "C" void _Z22SetNameEntries02011818PvP11Src02011818(GameState* gs, NameSrc02189c70* src);
extern "C" void _Z17ClearRegion0x649ePc(GameState* gs);
extern "C" void _Z23CopyStringToField0x649ePcjPKc(GameState* gs, unsigned int idx, const char* str);
extern "C" void func_ov017_021a9ff0(int v);
extern "C" void func_020a1940(unsigned int id);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(void* obj, int v);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Window02189c70* w, int idx, char* str);

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
    char obj150[0xc];
    char obj144[0xc];

    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Window02189c70* win = (Window02189c70*)_Z26GetGlobalField0x1c020421a0v();
    Res02189c70* res = (Res02189c70*)func_ov017_0218b5b0();
    Sub3b84* sub = res->f3b84;
    int token = func_0202ae18();

    if (self->state == 0) {
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
            _Z18ClearFlags020466f4P16FlagWord020466f4j(_Z27GetDataPtr02114e04_020d6c00v(), 0x2f);
            _Z15ClearBitsInWordPjj(func_ov017_0218b5b0(), 0x10);
            self->state = self->state + 1;
        }
    } else if (self->state == 1) {
        Member02189c70* m = (Member02189c70*)gs->GetPartyMemberByIndex(self->member);
        Ent02189c70* ent = 0;
        int base;
        char* name;
        char clr1[0x30];
        __clear(clr1, 0x30);
        if (self->ebc == 0) {
            if (m == 0) {
                func_ov008_0218b240(self);
                return;
            }
            ent = _Z15GetFieldAt0x150Ph(m);
            base = (signed char)m->f150->f950;
            func_02042764((char*)self + 0xdf6, clr1, 1);
            name = clr1;
        } else {
            func_02042764(self->ebc, clr1, 1);
            name = clr1;
            base = (signed char)self->ebc->kind;
        }
        if (ent != 0 && !self->e1c_b26) {
            EntFlags02189c70* fl = GetEntFlags02189c70(ent, 1);
            self->e1c_b25 = fl->bit0;
            self->e1c_f21 = fl->bit0;
            self->e20_f9 = 300;
            int key = 20700;
            if (fl->bit0 == 1) key += 50;
            self->e20_f19 = key - 20000 + m->f150->f950;
            self->e24 = 0;
        }
        int mode = self->ebc != 0 ? 3 : 1;
        char* title = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x280, (short)(self->e20_f9 + 10000));
        char* body;
        int v = self->e20_f19;
        if (v < 700) {
            body = _Z21GetFieldByKey020e0434P17Container020e0310i((char*)self + 0x288, (short)v);
        } else if (v < 800) {
            int key = 20700;
            if (self->e1c_b25 == 1) key += 50;
            body = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x280, (short)(base + key));
        } else {
            body = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x280, (short)(v + 20000));
        }
        func_02099304((char*)self + 0xe1c, name, self->ec4, self->ec8, buf400, 0x400, mode, title, body);
        func_02046380(win);
        int found = 0;
        char* p = buf400;
        p += strlen(buf400);
        if (self->ebc == 0) {
            void* flags = func_0205ec34();
            if (!_Z18TestBitInByteArrayiPhi(flags, (char*)flags + 0x8c, 0x119b)) {
                char* str = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0x66);
                int len = strlen(str);
                memcpy(p, str, len);
                p += len;
                _Z20SetOrClearBitInArrayPvPhii(flags, (char*)flags + 0x8c, 0x119b, 1);
            }
            Slot02189c70* slot;
            int i;
            unsigned char* countp = (unsigned char*)gs + 0x1fc + 0x7000;
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
                char* str = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0x64);
                _Z30InitObjFromCombatantId020e4bf4Pvi(obj144, self->member);
                win->f10 = obj144;
                func_02046608(win, 0xc, str, buf100, 0xe3, 0, 1);
                memcpy(p, buf100, strlen(buf100));
            }
        }
        if (!self->e1c_b25) win->f99c = 0; else win->f99c = 2;
        win->f19b2 = 1;
        func_0204500c(win, buf400, 0, 0xe3);
        win->busy = 1;
        loader->RemoveTask(self->eac);
        loader->RemoveTask(self->eb0);
        self->eac = -1;
        self->eb0 = -1;
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
            if (*((unsigned char*)gs + 0x7000 + 0x1fc) >= 0x10) {
                char* str = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0x69);
                memcpy(buf80, str, strlen(str));
                self->ebb = 1;
            } else {
                char* str = _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0x68);
                _Z30InitObjFromCombatantId020e4bf4Pvi(obj144, self->member);
                win->f10 = obj144;
                func_02046608(win, 0xc, str, buf80, 0xe3, 0, 1);
                _Z24AllocateFreeSlot0218b1e0Pv(self);
            }
            if (!self->e1c_b25) win->f99c = 0; else win->f99c = 2;
            win->f19b2 = 1;
            func_0204500c(win, buf80, 0, 0xe3);
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
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((char*)self + 0x18, 1);
        self->e99 = 2;
        self->state = 0;
        self->e9b = 2;
        self->e9c = 0;
    } else if (self->state == 3) {
        if (win->busy != 0) return;
        MapMeta02189c70 meta3 = self->ebc->meta;
        func_020a3720();
        _Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(&meta3, &detail3, 0, 0);
        func_020a395c();
        if (detail3.type == 1) {
            _Z29CopyStringToIndexedField0x2ecPciS_(win, 2, detail3.nameA);
        } else if (detail3.type == 2) {
            _Z29CopyStringToIndexedField0x2ecPciS_(win, 2, detail3.nameB);
        } else {
            self->state = 2;
            return;
        }
        char clr3[0x30];
        __clear(clr3, 0x30);
        func_02042764(self->ebc, clr3, 1);
        func_020e4b34(obj144, clr3, clr3, 0, 0, 0, 0, self->ebc->flag2e, 0, 1, 0, 1);
        _Z30InitObjFromCombatantId020e4bf4Pvi(obj150, _Z19GetField0x397cValueP9GameState(gs));
        win->f10 = obj144;
        win->f0 = obj150;
        if (_Z25ReadBattleField0x64f4Bytev(gs) >= 0x63) {
            func_0204500c(win, _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0xc9), 0, 0xe3);
        } else {
            func_0204500c(win, _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0xca), 0, 0xe3);
        }
        win->busy = 1;
        win->f19b2 = 0;
        self->state = 4;
    } else if (self->state == 4) {
        if (win->busy != 0) return;
        if (_Z25ReadBattleField0x64f4Bytev(gs) >= 0x63) {
            _Z30InitObjFromCombatantId020e4bf4Pvi(obj150, _Z19GetField0x397cValueP9GameState(gs));
            win->f0 = obj150;
            win->f2c8 = 1;
            func_0204500c(win, _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0xcb), 0, 0xe3);
            win->busy = 1;
            win->f19b2 = 1;
            self->state = 5;
        } else {
            _Z25CopyOutBattleRegion0x64f4Pv(&region);
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
            _Z24CopyToBattleRegion0x64f4Pv(&region);
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
        _Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(&meta5, &detail5, 0, 0);
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
        _Z22SetNameEntries02011818PvP11Src02011818(gs, &names);
        if (((TreasureMapMetadata*)&meta5)->GetMapType() == 1) {
            _Z17ClearRegion0x649ePc(gs);
            _Z23CopyStringToField0x649ePcjPKc(gs, 0, detail5.nameA);
        } else if (((TreasureMapMetadata*)&meta5)->GetMapType() == 2) {
            _Z23CopyStringToField0x649ePcjPKc(gs, 0, detail5.nameB);
        }
        *(unsigned int*)((char*)gs + 0x6474) = self->ebc->f10 >> 2;
        func_ov017_021a9ff0(0);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((char*)self + 0x18, 1);
        self->state = 2;
    } else if (self->state == 6) {
        if (res->f3b4c->f2 != 0) return;
        func_020a1940(OVERLAY_ID(8));
        self->ec0_b0 = 0;
        self->state = 7;
    } else if (self->state == 7) {
        void* obj = gs->GetUnknownGameObject();
        if (obj != 0) _Z27CancelPendingAction020397ccP11Obj020397cci(obj, 1);
        if (*((unsigned char*)gs + 0x6000 + 0x46e) != 0) {
            MapMeta02189c70 meta7 = self->ebc->meta;
            func_020a3720();
            _Z29ExportDetailedTreasureMapDataPK19TreasureMapMetadataP23DetailedTreasureMapDatabPKh(&meta7, &detail7, 0, 0);
            func_020a395c();
            if (detail7.type == 1) {
                _Z29CopyStringToIndexedField0x2ecPciS_(win, 2, detail7.nameA);
            } else if (detail7.type == 2) {
                _Z29CopyStringToIndexedField0x2ecPciS_(win, 2, detail7.nameB);
            }
            char clr7[0x30];
            __clear(clr7, 0x30);
            func_02042764(self->ebc, clr7, 1);
            _Z22SetIndexedName02046574P11Obj02046574iPc(win, 0, clr7);
            _Z22SetIndexedName02046574P11Obj02046574iPc(win, 1, *(char**)((char*)gs->GetUnknownGameObject() + 0x134));
            func_0204500c(win, _Z14FindEntryByKeyP8TableA68i((char*)self + 0x278, 0xca), 0, 0xe3);
            win->busy = 1;
            win->f19b2 = 0;
            self->ebc->active = 0;
        }
        self->state = 2;
    }
}
