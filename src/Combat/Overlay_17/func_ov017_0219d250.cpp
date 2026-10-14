#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "Resource/MessageSystem.h"

struct Entry0219d250 {
    unsigned short id;
    unsigned char unk2[3];
    signed char x;
    signed char y;
    signed char z;
    unsigned char unk8[4];
    unsigned char kind : 4;
};

struct Request0219d250 {
    unsigned short id;
    unsigned char unk2;
    unsigned char pending;
    unsigned char mode;
    unsigned char unk5[5];
    unsigned char active;
    unsigned char unkb[0x15];
    int f20;
    unsigned char unk24[0x3c];
    unsigned char f60;
    unsigned char unk61;
    unsigned char f62;
    unsigned char unk63[4];
    unsigned char f67;
    unsigned char unk68[6];
    unsigned char flags6e;
};

struct Node0219d250 {
    unsigned char unk0[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unk3[0x174 - 3];
#else
    unsigned char unk3[0x178 - 3];
#endif
    unsigned char set : 1;
    unsigned char rest : 7;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    float f17c;
};

struct Combatant0219d250 {
    Object3D obj3D;
#if defined(jpn)
    char padAc[0x150 - 0xac];
#else
    char padAc[0x15c - 0xac];
#endif
    int field15c;
};

struct Member0219d250 {
    Object3D obj3D;
    char padAc[0xb8 - 0xac];
    unsigned short b8;
    char padBa[0x130 - 0xba];
    unsigned char* p130;
};

struct Unknown0219d250 {
    char pad0[4];
    short s4;
};

struct GrottoIds0219d250 {
    unsigned char unk0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Battle0219d250 {
#if defined(jpn)
    char pad0[0x3448];
#else
    char pad0[0x3658];
#endif
    unsigned char b3658;
    char pad3659[0x36f0 - 0x3659];
    int f36f0;
    int f36f4;
    char pad36f8[0x370c - 0x36f8];
    unsigned char* header;
    char pad3710[0x3734 - 0x3710];
    Node0219d250* node;
#if defined(jpn)
    char pad3738[0x40c9 - 0x3528];
#else
    char pad3738[0x42e9 - 0x3738];
#endif
    unsigned char b42e9;
    unsigned char b42ea;
    char pad42eb;
    unsigned short h42ec;
#if defined(jpn)
    char pad42ee[0x4214 - 0x40ce];
#else
    char pad42ee[0x44c4 - 0x42ee];
#endif
    void* regions;
};

extern "C" char* func_02012fe4(void);
char* GetGlobalField0x1c020421a0(void);
void* GetEntryTableBase(void);
extern "C" void* func_02057924(void);
void* GetPtrField0x468(void*);
Request0219d250* GetField0x3f8Address(GameState* gs);
extern "C" void* func_0202ae18(void);
void* GetGlobalPtr021075f4(void);
extern "C" void* func_0205ec34(void);
void ClearMonsterFlagEntries_02191bdc(unsigned char*, int);
struct SearchTable;
Entry0219d250* FindEntryByHalfwordKey(SearchTable*, int);
extern "C" int func_0202c540(void* search);
void SetField5cb0AndRecordByte0(char*, int);
void SetField5cb4AndRecordByte1(char*, int);
void SetSlotByte020107dc(char*, int);
struct SearchStruct;
int TestBitBySignedByteIndex(SearchStruct*, int);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" int func_0206e558(void* flags);
extern "C" int func_ov017_0219c774(Entry0219d250* entry, int a, int b);
void* GetGlobal02109030(void);
extern "C" void func_02094030(void* p, int a, int b, int c);
void InitStruct0203e074(char*);
extern "C" int func_0209cd50(int id);
struct ShortField0xb8_0209cae8;
int GetShortAt0xb8(ShortField0xb8_0209cae8*);
struct Actor0209c678;
void DispatchContextByState0209c678(Actor0209c678*, int);
Entry0219d250* GetElementStride0x10(unsigned char*, unsigned int);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
void ClearBytesAndZeroBlock02039d24(unsigned char*);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" void func_020531f0(void* obj);
void ClearField0xc4KeepBit0x8000(unsigned char* obj);
void ReinitController02043204(char* c);
extern "C" void func_02043124(char* c);
void SetBitIfValueInTable_0219e290(void*, unsigned short);
void Clear0x80Bytes0206ebc8(void* p);
void Clear0x80BytesAt0x800206ebdc(unsigned char*);
extern "C" void func_ov017_021a316c(Battle0219d250* self);
extern "C" void func_ov017_0219de70(Battle0219d250* self, Entry0219d250* other, Entry0219d250* entry);
void SetByte0x63d5(void*);
unsigned char GetField0x3acValue(GameState* gs);
extern "C" void func_ov017_0218f5a4(Battle0219d250* self, int id, int b, int c, int d);
extern "C" void func_0208fa8c(void* p);
struct Entry_02028bd0;
void* FindInlineEntryById(Entry_02028bd0*, int);
struct EntryArg_0219e014;
void ProcessEntryFlagsAndCombatants_0219e014(unsigned char*, EntryArg_0219e014*);
extern "C" void func_020288e0(void* table);
void SetFlagsForFlaggedCombatants_0219e0ec(void* self);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
struct MainBlock0205859c;
void ResetBattleEncounterState0205859c(MainBlock0205859c*);
void UpdateFlagsFromField12_0219e234(int, int, int, void*);
void SetBitsInField4(unsigned int*, unsigned int);
extern "C" void func_ov017_0219fda0(Battle0219d250* self);
void InitEntriesAndAllocators_0219fec0(void* self);
int IsIdInRange020981e4(int, int);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_02191108(Battle0219d250* self, int a, int b, int c, int d);
extern "C" int func_0202c508(void* search);
void CallHelperWithBuf_021907dc(int, int, int, int, int);

extern char data_02109bf4;

#if defined(jpn)
enum { ZoneKeyOffset = 0x2816 };
#else
enum { ZoneKeyOffset = 0x27d6 };
#endif

// USA: func_ov017_0219d250
extern "C" ARM void func_ov017_0219d250(Battle0219d250* self, unsigned char arg) {
    Node0219d250* node;
    Request0219d250* request;
    int id;
    Entry0219d250* entry;
    Entry0219d250* other;
    GameState* gs;
    char* controller;
    void* entryTable;
    void* combatants;
    GameObject* hero;
    GameObject* unknown;
    void* searchTable;
    void* search;
    void* extRegion;
    GrottoIds0219d250* party;
    int heroZone;
    TimeOfDay before;
    Member0219d250* member;
    int i;
    int present;
    void* flags;
    void* search2;
    GameState* gs2;
    unsigned char* header;
    int changed;
    int forced;
    unsigned short key;

    gs = GameState::GetInstance();
    char* field = func_02012fe4();
    controller = GetGlobalField0x1c020421a0();
    entryTable = GetEntryTableBase();
    combatants = func_02057924();
    hero = gs->GetProtagonist();
    unknown = gs->GetUnknownGameObject();
    searchTable = GetPtrField0x468(gs);
    request = GetField0x3f8Address(gs);
    search = func_0202ae18();
    extRegion = GetGlobalPtr021075f4();
    party = (GrottoIds0219d250*)GetPtrField0x2a04(gs);
    char* status = (char*)&((Zone3D*)field)->grotto_;
    func_0205ec34();
    header = self->header;
    if (hero == NULL || unknown == NULL) {
        return;
    }

    ClearMonsterFlagEntries_02191bdc((unsigned char*)self, 1);
    id = request->id;
    heroZone = hero->obj3D_.GetField06();
    entry = FindEntryByHalfwordKey((SearchTable*)searchTable, id);
    other = FindEntryByHalfwordKey((SearchTable*)searchTable, heroZone);
    node = self->node;

    if (node->active != 0 && node->set && func_0202c540(search)) {
        SetField5cb0AndRecordByte0((char*)gs, node->a);
        SetField5cb4AndRecordByte1((char*)gs, node->b);
        SetSlotByte020107dc((char*)gs, node->c);
    } else {
        before = gs->GetTimeOfDay();
        if (func_0202c540(search) && request->f60 == 0 && self->node->active == 0) {
            GameObject* lead = gs->GetPartyMemberByIndex(0);
            if ((lead != NULL && id == lead->obj3D_.GetField06()) || request->f62 != 0) {
                if (request->f62 != 0) {
                    forced = 1;
                } else {
                    forced = 0;
                }
                gs2 = GameState::GetInstance();
                search2 = func_0202ae18();
                flags = func_0205ec34();
                present = 1;
                key = entry->id;
                changed = 0;
                for (i = 1; i < 4; i++) {
                    if (TestBitBySignedByteIndex((SearchStruct*)search2, i) &&
                        i != GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search2)) {
                        Combatant0219d250* c = (Combatant0219d250*)GetCombatantWithFlag0x100(gs2, i);
                        if (c != NULL && (key == c->obj3D.GetField06() || key == c->field15c)) {
                            present = 0;
                            break;
                        }
                    }
                }
                Combatant0219d250* c0 = (Combatant0219d250*)GetCombatantWithFlag0x100(gs2, 0);
                if (c0 != NULL && (key == c0->obj3D.GetField06() || key == c0->field15c)) {
                    present = 1;
                }
                if (forced) {
                    present = 1;
                }
                if (present) {
                    int a = func_0206e558(flags) ? 1 : 0;
                    int b = func_ov017_0219c774(entry, 1, 0);
                    changed = (a | b) ? 1 : 0;
                }
                if (changed) {
                    if (self->b42e9 != 0) {
                        func_02094030(GetGlobal02109030(), 0x4e23, -1, 0);
                    }
                    request->flags6e &= ~2;
                    InitStruct0203e074((char*)extRegion);
                }
                if (func_0209cd50(id) != GetShortAt0xb8((ShortField0xb8_0209cae8*)&data_02109bf4) &&
                    request->f20 <= 0) {
                    DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
                    header[0xa] = 1;
                }
            }
        }
        self->b42e9 = 0;
        TimeOfDay after = gs->GetTimeOfDay();
        if ((before == 0 && after != 0) || (before != 0 && after == 0)) {
            request->flags6e &= ~2;
            InitStruct0203e074((char*)extRegion);
        }
    }

    node->set = 0;
    node->rest = 0;
    node->a = 0;
    node->b = 0;
    node->c = 0;
    node->f17c = -1.0f;
    if (request->f67 != 0) {
        request->flags6e &= ~2;
        InitStruct0203e074((char*)extRegion);
    }
    if (entry == NULL) {
        entry = GetElementStride0x10((unsigned char*)searchTable, 0);
        id = entry->id;
        request->id = id;
    }
    func_ov017_0219cdc0(id, 1, -1);

    for (int n = 0; n < party->count; n++) {
        member = (Member0219d250*)gs->GetPartyMemberByIndex(party->ids[n]);
        if (member != NULL) {
            _ZN8Object3D10SetField06Et(&member->obj3D, id);
            member->obj3D.SetInheritedAlpha(0x1f);
            member->b8 = 0;
            ClearBytesAndZeroBlock02039d24((unsigned char*)member);
            if (id != heroZone) {
                member->p130[8] = 0;
                func_ov017_021c9e00(party->ids[n], 1, 0, 1);
            }
        }
    }

    if (CheckSubstructByte0x7cPositive((signed char*)unknown)) {
        func_020531f0(unknown);
    }
    ClearField0xc4KeepBit0x8000((unsigned char*)hero);
    if (((MessageSystem*)controller)->active != NULL) {
        ReinitController02043204(controller);
    }
    func_02043124(controller);

    int moved;
    if (other == NULL) {
        moved = 1;
    } else {
        moved = other->x != entry->x || other->y != entry->y || other->z != entry->z;
    }
    SetBitIfValueInTable_0219e290(self, request->id);
    if (request->active == 0) {
        if (moved) {
            Clear0x80Bytes0206ebc8(self->regions);
        }
        if (id != heroZone) {
            Clear0x80BytesAt0x800206ebdc((unsigned char*)self->regions);
        }
    }
    if (id != heroZone) {
        request->flags6e &= ~2;
    }
    if (!(request->flags6e & 2)) {
        func_ov017_021a316c(self);
        if (((Zone3D*)field)->internalAllocator_.GetSignedAllocator()) {
            ((Zone3D*)field)->internalAllocator_.Destroy();
            ((Zone3D*)field)->internalAllocator_.ResetAllocatorPointer();
        }
        func_ov017_0219de70(self, other, entry);
    }
    if (entry->kind == 2 && entry->id != 0x170c) {
        SetByte0x63d5(gs);
    }
    if (request->pending != 0) {
        func_ov017_0218f5a4(self, GetField0x3acValue(gs), 1, 0, 0);
        request->pending = 0;
    }
    func_0208fa8c(status);
    ProcessEntryFlagsAndCombatants_0219e014((unsigned char*)self, (EntryArg_0219e014*)(FindInlineEntryById((Entry_02028bd0*)entryTable, heroZone)));
    func_020288e0(entryTable);
    SetFlagsForFlaggedCombatants_0219e0ec(self);
    Init0203cfb4((Struct_0203cfb4*)extRegion);
    ResetBattleEncounterState0205859c((MainBlock0205859c*)combatants);
    UpdateFlagsFromField12_0219e234((int)self, (int)request, (int)other, entry);
    self->f36f0 = 0;
    self->f36f4 = 0;
    self->b42ea = gs->GetTimeOfDay();
    self->h42ec = 0;
    if (!(request->flags6e & 1)) {
        SetBitsInField4((unsigned int*)self, 1);
    }
    if ((other == NULL || other->id != 3) && entry->id == 3) {
        func_ov017_0219fda0(self);
    } else if (other != NULL && other->id == 3 && entry->id != 3) {
        InitEntriesAndAllocators_0219fec0(self);
    }
    self->b3658 = 0;
    ((Zone3D*)field)->SwitchZone(request->id, request->mode);
    if (IsIdInRange020981e4((int)(((Zone3D*)field)->unk_840), id) || IsIdInRange020981e4((int)(((Zone3D*)field)->unk_840), heroZone)) {
        if (CheckField0NonZero((int*)search) == 0) {
            func_ov017_02191108(self, 1, 1, 1, 1);
        } else {
            for (int k = 0; k < 4; k++) {
                if (func_0202c508(search)) {
                    func_ov017_02191108(self, 1, 1, 1, 1);
                } else {
                    CallHelperWithBuf_021907dc((int)self, 0, 1, 1, 1);
                }
            }
        }
    }
    *(unsigned short*)(field + ZoneKeyOffset) = 0;
    for (int j = 0; j < 4; j++) {
        if (member != NULL && j != ((Unknown0219d250*)unknown)->s4) {
            member->obj3D.DisableFlag(0x1010);
        }
    }
}
