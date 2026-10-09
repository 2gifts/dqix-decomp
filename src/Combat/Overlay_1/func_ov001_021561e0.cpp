#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct CleanupState021561e0 {
    char field_0[8];
    unsigned short id;
    unsigned short state;
    char field_c[0x44];
    unsigned short flags;
    char field_52[0x2a];
    SafeAllocator allocator;
    char field_90[0x6c];
    unsigned char active;
    char field_fd[6];
    unsigned char pending;
    char field_104[2];
    unsigned char complete;
    char field_107[0x13];
    unsigned short keepResources;
    char field_11c[8];
    SafeAllocator childAllocator;
    SafeAllocator* externalAllocator;
    char field_13c[0x20];
    int resetGameFlag;
    void* allocation;
};
struct GameFlag021561e0 { char field_0[0x5cac]; unsigned char active; };
struct MapNode021561e0 {
    char field_0[0x2e];
    unsigned short category : 4;
    unsigned short flags : 12;
    char field_30[0x40];
    MapNode021561e0* next;
};
struct AreaState021561e0 { unsigned short id; char field_2[0x6a]; unsigned char entries[0x50]; };
struct CombatantFlags021561e0 { Object3D object; char field_ac[0xe0]; unsigned int flags; };
struct EventFlags021561e0 { char field_0[0x8c]; unsigned char flags[1]; };
struct Entry_02028bd0;
struct Obj02028c64;
extern "C" int _Z28InitAndCheckField3c_02153994v();
void* GetGlobal02109400();
extern "C" int _Z18AlwaysTrue02094b4cv();
extern "C" int* func_0202ae18();
extern "C" void func_ov001_0215aac8();
extern "C" void _Z36SetEntryCallbackAndDispatch_021d8c20iii(void*);
extern "C" void _Z17SetArrVal0215aaa8ii(int, int);
extern "C" void func_ov001_02154974(void*);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion*, void*);
unsigned int GetBitsInField0(unsigned int*, unsigned int);
extern "C" void _Z32DestroyActiveAllocators_0215aa5cv();
extern "C" AreaState021561e0* func_02012fe4();
void* GetPointerFromArray0x3c(unsigned char*, unsigned int);
extern "C" int _Z32FindMatchingElementIndex02018bc4PhPv(unsigned char*, void*);
Entry_02028bd0* GetEntryTableBase();
Obj02028c64* FindInlineEntryById(Entry_02028bd0*, int);
extern "C" void _Z18SetFlagBit02028c64P11Obj02028c64i(Obj02028c64*, int);
extern "C" EventFlags021561e0* func_0205ec34();
void SetOrClearBitInArray(void*, unsigned char*, int, int);
int CheckField0NonZero(int*);
extern "C" int func_0202c508(void*);
extern "C" void func_ov017_021d0490(int);
extern AllocatorUnion data_02114e20;

// USA: func_ov001_021561e0
extern "C" ARM int func_ov001_021561e0(CleanupState021561e0* state) {
    if (_Z28InitAndCheckField3c_02153994v() != 1) return state->state;
    state->complete = 1;
    GetGlobal02109400();
    if (!_Z18AlwaysTrue02094b4cv()) return 11;
    GameResources* resources = func_ov017_0218b5b0();
    GameState* game = GameState::GetInstance();
    int* manager = func_0202ae18();
    if (state->resetGameFlag) ((GameFlag021561e0*)game)->active = 0;
    func_ov001_0215aac8();
    if (state->allocation) {
        _Z36SetEntryCallbackAndDispatch_021d8c20iii(state->allocation);
        state->allocation = 0;
    }
    if (state->flags & 4) _Z17SetArrVal0215aaa8ii(1, 0);
    func_ov001_02154974(state);
    if ((state->flags & 2) || (state->flags & 8)) {
        SignedAllocatorHeader* buffer = state->childAllocator.GetSignedAllocator();
        if (buffer) {
            state->childAllocator.Destroy();
            state->allocator.Free(buffer);
        }
        if (state->externalAllocator) {
            SignedAllocatorHeader* external = state->externalAllocator->GetSignedAllocator();
            if (external) {
                state->externalAllocator->Destroy();
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, external);
                state->externalAllocator = 0;
            }
        }
    }
    if (!GetBitsInField0((unsigned int*)resources, 0x1000) || !state->keepResources) {
        SignedAllocatorHeader* buffer = state->allocator.GetSignedAllocator();
        if (buffer) {
            state->allocator.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, buffer);
        }
        _Z32DestroyActiveAllocators_0215aa5cv();
    }
    AreaState021561e0* area = func_02012fe4();
    MapNode021561e0* node = (MapNode021561e0*)GetPointerFromArray0x3c(area->entries, 2);
    while (node) {
        if (node->flags & 0x200) {
            int index = _Z32FindMatchingElementIndex02018bc4PhPv((unsigned char*)area, node);
            Obj02028c64* entry = FindInlineEntryById(GetEntryTableBase(), area->id);
            if (entry) _Z18SetFlagBit02028c64P11Obj02028c64i(entry, index);
            node->flags &= ~0x200;
        }
        node = node->next;
    }
    if (state->id == 0x730a) {
        EventFlags021561e0* events = func_0205ec34();
        SetOrClearBitInArray(events, events->flags, 0x1142, 0);
    }
    for (int i = 0; i < 4; ++i) {
        CombatantFlags021561e0* member = (CombatantFlags021561e0*)GetCombatantWithFlag0x100(game, i);
        if (member) {
            member->object.DisableFlag(0x800000);
            member->flags &= ~2;
        }
    }
    if (!CheckField0NonZero(manager) || func_0202c508(manager)) return 10;
    func_ov017_021d0490(0);
    state->active = 0;
    state->pending = 0;
    return 16;
}
