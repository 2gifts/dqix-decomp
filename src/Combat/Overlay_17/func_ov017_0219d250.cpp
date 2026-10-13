#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

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
    unsigned char unk3[0x175];
    unsigned char set : 1;
    unsigned char rest : 7;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    float f17c;
};

struct Combatant0219d250 {
    Object3D obj3D;
    char padAc[0x15c - 0xac];
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
    char pad0[0x3658];
    unsigned char b3658;
    char pad3659[0x36f0 - 0x3659];
    int f36f0;
    int f36f4;
    char pad36f8[0x370c - 0x36f8];
    unsigned char* header;
    char pad3710[0x3734 - 0x3710];
    Node0219d250* node;
    char pad3738[0x42e9 - 0x3738];
    unsigned char b42e9;
    unsigned char b42ea;
    char pad42eb;
    unsigned short h42ec;
    char pad42ee[0x44c4 - 0x42ee];
    void* regions;
};

extern "C" char* func_02012fe4(void);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* _Z17GetEntryTableBasev(void);
extern "C" void* func_02057924(void);
extern "C" void* _Z16GetPtrField0x468Pv(GameState* gs);
extern "C" Request0219d250* _Z20GetField0x3f8AddressP9GameState(GameState* gs);
extern "C" void* func_0202ae18(void);
extern "C" void* _Z20GetGlobalPtr021075f4v(void);
extern "C" GrottoIds0219d250* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
extern "C" void* func_0205ec34(void);
extern "C" void _Z32ClearMonsterFlagEntries_02191bdcPhi(Battle0219d250* self, int v);
extern "C" Entry0219d250* _Z22FindEntryByHalfwordKeyP11SearchTablei(void* table, int key);
extern "C" int func_0202c540(void* search);
extern "C" void _Z26SetField5cb0AndRecordByte0Pci(GameState* gs, int v);
extern "C" void _Z26SetField5cb4AndRecordByte1Pci(GameState* gs, int v);
extern "C" void _Z19SetSlotByte020107dcPci(GameState* gs, int v);
extern "C" int _Z24TestBitBySignedByteIndexP12SearchStructi(void* search, int i);
extern "C" int _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(void* search);
extern "C" Combatant0219d250* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int i);
extern "C" int func_0206e558(void* flags);
extern "C" int func_ov017_0219c774(Entry0219d250* entry, int a, int b);
extern "C" void* _Z17GetGlobal02109030v(void);
extern "C" void func_02094030(void* p, int a, int b, int c);
extern "C" void _Z18InitStruct0203e074Pc(void* p);
extern "C" int func_0209cd50(int id);
extern "C" int _Z14GetShortAt0xb8P23ShortField0xb8_0209cae8(void* obj);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(void* actor, int v);
extern "C" Entry0219d250* _Z20GetElementStride0x10Phj(void* table, unsigned int i);
extern "C" void func_ov017_0219cdc0(unsigned short value, int a1, signed char id);
extern "C" void _ZN8Object3D10SetField06Et(Object3D* obj, int value);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(Member0219d250* m);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" void func_020531f0(void* obj);
void ClearField0xc4KeepBit0x8000(unsigned char* obj);
extern "C" void _Z24ReinitController02043204Pc(char* c);
extern "C" void func_02043124(char* c);
extern "C" void _Z29SetBitIfValueInTable_0219e290Pvt(Battle0219d250* self, unsigned short v);
extern "C" void _Z22Clear0x80Bytes0206ebc8Pv(void* p);
extern "C" void _Z28Clear0x80BytesAt0x800206ebdcPh(void* p);
extern "C" void func_ov017_021a316c(Battle0219d250* self);
extern "C" void func_ov017_0219de70(Battle0219d250* self, Entry0219d250* other, Entry0219d250* entry);
extern "C" void _Z13SetByte0x63d5Pv(GameState* gs);
extern "C" unsigned char _Z18GetField0x3acValueP9GameState(GameState* gs);
extern "C" void func_ov017_0218f5a4(Battle0219d250* self, int id, int b, int c, int d);
extern "C" void func_0208fa8c(void* p);
extern "C" void* _Z19FindInlineEntryByIdP14Entry_02028bd0i(void* table, int id);
extern "C" void _Z39ProcessEntryFlagsAndCombatants_0219e014PhP17EntryArg_0219e014(Battle0219d250* self, void* entry);
extern "C" void func_020288e0(void* table);
void SetFlagsForFlaggedCombatants_0219e0ec(void* self);
extern "C" void _Z12Init0203cfb4P15Struct_0203cfb4(void* p);
extern "C" void _Z33ResetBattleEncounterState0205859cP17MainBlock0205859c(void* p);
extern "C" void _Z31UpdateFlagsFromField12_0219e234iiiPv(Battle0219d250* self, Request0219d250* request, Entry0219d250* other, Entry0219d250* entry);
extern "C" void _Z15SetBitsInField4Pjj(Battle0219d250* self, unsigned int mask);
extern "C" void func_ov017_0219fda0(Battle0219d250* self);
void InitEntriesAndAllocators_0219fec0(void* self);
extern "C" void _ZN6Zone3D10SwitchZoneEti(char* zone, int id, int flag);
extern "C" int _Z19IsIdInRange020981e4ii(void* obj, int id);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_02191108(Battle0219d250* self, int a, int b, int c, int d);
extern "C" int func_0202c508(void* search);
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(Battle0219d250* self, int a, int b, int c, int d);

extern char data_02109bf4;

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
    controller = _Z26GetGlobalField0x1c020421a0v();
    entryTable = _Z17GetEntryTableBasev();
    combatants = func_02057924();
    hero = gs->GetProtagonist();
    unknown = gs->GetUnknownGameObject();
    searchTable = _Z16GetPtrField0x468Pv(gs);
    request = _Z20GetField0x3f8AddressP9GameState(gs);
    search = func_0202ae18();
    extRegion = _Z20GetGlobalPtr021075f4v();
    party = _Z17GetPtrField0x2a04P9GameState(gs);
    char* status = field + 0x23ec;
    func_0205ec34();
    header = self->header;
    if (hero == NULL || unknown == NULL) {
        return;
    }

    _Z32ClearMonsterFlagEntries_02191bdcPhi(self, 1);
    id = request->id;
    heroZone = hero->obj3D_.GetField06();
    entry = _Z22FindEntryByHalfwordKeyP11SearchTablei(searchTable, id);
    other = _Z22FindEntryByHalfwordKeyP11SearchTablei(searchTable, heroZone);
    node = self->node;

    if (node->active != 0 && node->set && func_0202c540(search)) {
        _Z26SetField5cb0AndRecordByte0Pci(gs, node->a);
        _Z26SetField5cb4AndRecordByte1Pci(gs, node->b);
        _Z19SetSlotByte020107dcPci(gs, node->c);
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
                    if (_Z24TestBitBySignedByteIndexP12SearchStructi(search2, i) &&
                        i != _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(search2)) {
                        Combatant0219d250* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs2, i);
                        if (c != NULL && (key == c->obj3D.GetField06() || key == c->field15c)) {
                            present = 0;
                            break;
                        }
                    }
                }
                Combatant0219d250* c0 = _Z25GetCombatantWithFlag0x100P9GameStatei(gs2, 0);
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
                        func_02094030(_Z17GetGlobal02109030v(), 0x4e23, -1, 0);
                    }
                    request->flags6e &= ~2;
                    _Z18InitStruct0203e074Pc(extRegion);
                }
                if (func_0209cd50(id) != _Z14GetShortAt0xb8P23ShortField0xb8_0209cae8(&data_02109bf4) &&
                    request->f20 <= 0) {
                    _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 0);
                    header[0xa] = 1;
                }
            }
        }
        self->b42e9 = 0;
        TimeOfDay after = gs->GetTimeOfDay();
        if ((before == 0 && after != 0) || (before != 0 && after == 0)) {
            request->flags6e &= ~2;
            _Z18InitStruct0203e074Pc(extRegion);
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
        _Z18InitStruct0203e074Pc(extRegion);
    }
    if (entry == NULL) {
        entry = _Z20GetElementStride0x10Phj(searchTable, 0);
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
            _Z30ClearBytesAndZeroBlock02039d24Ph(member);
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
    if (*(int*)(controller + 0x998) != 0) {
        _Z24ReinitController02043204Pc(controller);
    }
    func_02043124(controller);

    int moved;
    if (other == NULL) {
        moved = 1;
    } else {
        moved = other->x != entry->x || other->y != entry->y || other->z != entry->z;
    }
    _Z29SetBitIfValueInTable_0219e290Pvt(self, request->id);
    if (request->active == 0) {
        if (moved) {
            _Z22Clear0x80Bytes0206ebc8Pv(self->regions);
        }
        if (id != heroZone) {
            _Z28Clear0x80BytesAt0x800206ebdcPh(self->regions);
        }
    }
    if (id != heroZone) {
        request->flags6e &= ~2;
    }
    if (!(request->flags6e & 2)) {
        func_ov017_021a316c(self);
        if (((SafeAllocator*)(field + 0x54))->GetSignedAllocator()) {
            ((SafeAllocator*)(field + 0x54))->Destroy();
            ((SafeAllocator*)(field + 0x54))->ResetAllocatorPointer();
        }
        func_ov017_0219de70(self, other, entry);
    }
    if (entry->kind == 2 && entry->id != 0x170c) {
        _Z13SetByte0x63d5Pv(gs);
    }
    if (request->pending != 0) {
        func_ov017_0218f5a4(self, _Z18GetField0x3acValueP9GameState(gs), 1, 0, 0);
        request->pending = 0;
    }
    func_0208fa8c(status);
    _Z39ProcessEntryFlagsAndCombatants_0219e014PhP17EntryArg_0219e014(self, _Z19FindInlineEntryByIdP14Entry_02028bd0i(entryTable, heroZone));
    func_020288e0(entryTable);
    SetFlagsForFlaggedCombatants_0219e0ec(self);
    _Z12Init0203cfb4P15Struct_0203cfb4(extRegion);
    _Z33ResetBattleEncounterState0205859cP17MainBlock0205859c(combatants);
    _Z31UpdateFlagsFromField12_0219e234iiiPv(self, request, other, entry);
    self->f36f0 = 0;
    self->f36f4 = 0;
    self->b42ea = gs->GetTimeOfDay();
    self->h42ec = 0;
    if (!(request->flags6e & 1)) {
        _Z15SetBitsInField4Pjj(self, 1);
    }
    if ((other == NULL || other->id != 3) && entry->id == 3) {
        func_ov017_0219fda0(self);
    } else if (other != NULL && other->id == 3 && entry->id != 3) {
        InitEntriesAndAllocators_0219fec0(self);
    }
    self->b3658 = 0;
    _ZN6Zone3D10SwitchZoneEti(field, request->id, request->mode);
    if (_Z19IsIdInRange020981e4ii(field + 0x840, id) || _Z19IsIdInRange020981e4ii(field + 0x840, heroZone)) {
        if (CheckField0NonZero((int*)search) == 0) {
            func_ov017_02191108(self, 1, 1, 1, 1);
        } else {
            for (int k = 0; k < 4; k++) {
                if (func_0202c508(search)) {
                    func_ov017_02191108(self, 1, 1, 1, 1);
                } else {
                    _Z26CallHelperWithBuf_021907dciiiii(self, 0, 1, 1, 1);
                }
            }
        }
    }
    *(unsigned short*)(field + 0x27d6) = 0;
    for (int j = 0; j < 4; j++) {
        if (member != NULL && j != ((Unknown0219d250*)unknown)->s4) {
            member->obj3D.DisableFlag(0x1010);
        }
    }
}
