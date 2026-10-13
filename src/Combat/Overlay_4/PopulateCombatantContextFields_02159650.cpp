#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020e207c(void*, char*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
#endif

#include "GameState/GameState.h"

struct Struct021707d8_02159650 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02159650 data_ov004_021707d8;
struct CombatantSelection {
    unsigned char unknown00[0x12];
    signed char partyIndex;

    signed char GetPartyIndex() const { return partyIndex; }
};

int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* g);

struct Container020dedd0;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);

int DispatchNodeIfType7_02156e2c(void* a, int key);

struct Entry_021570a4 { short field0; unsigned int field4; };
void* GetEntryFor_021570a4(void* obj, int index);

struct Element020de650 { int field0; char pad2[4]; int field8; char pad3[0xc]; short field18; };
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);

int CallFunc020e0434With02153694(int value);
extern "C" void func_020e4b34(void* obj, int stats1, int stats2, int a, int b, int c, int d, int e, int f, int g, int h, int i);

int CallFunc020e52a0(void* p, int key);

struct Field150Holder02052df8;
int GetHalfwordEntryFromField150(struct Field150Holder02052df8* obj, int index);

struct Table9x_02159650 { unsigned int v[9]; };
extern struct Table9x_02159650 data_ov004_0216fbb0;

struct Ctx_02159650 { char pad[8]; unsigned int idx4 : 4; unsigned int rest : 28; };
struct Field8Bits_02159650 { unsigned int low18 : 18; unsigned int bit18 : 1; unsigned int high13 : 13; };

struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

// USA: func_ov004_02159650  (semantic: PopulateCombatantContextFields_02159650)
extern "C" ARM int func_ov004_02159650(void* obj) {
    int g = GetGlobalField0x1c020421a0();
    func_02046380((void*)g);

    struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);

    struct Element020de650* elem = 0;
    struct Entry_021570a4* entry = 0;

    int idx = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (idx >= 0) {
        entry = (struct Entry_021570a4*)GetEntryFor_021570a4(obj, idx & 0xff);
        if (entry != 0 && node != 0) {
            elem = FindElementByKey020dedd0(node, entry->field0);
        }
    }

    signed char combatantId = ((CombatantSelection*)data_ov004_021707d8.ptr)->GetPartyIndex();
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);

    if (combatant != 0) {
#if defined(jpn)
        SetIndexedName02046574((Obj02046574*)g, 0, (char*)combatant->baseStats_);
#else
        InitObjFromCombatantId020e4bf4(data_ov004_021707d8.ptr + 0xa0, combatantId);
        *(void**)((char*)g + 0x10) = data_ov004_021707d8.ptr + 0xa0;

        void* p150 = *(void**)((char*)combatant + 0x150);
        int statVal = (short)(*(int*)((char*)p150 + 0x950));
        int fmt = CallFunc020e0434With02153694(statVal);
        func_020e4b34(data_ov004_021707d8.ptr + 0xac, fmt, fmt, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(void**)((char*)g + 0x28) = data_ov004_021707d8.ptr + 0xac;
#endif
    }

    if (elem != 0) {
#if defined(jpn)
        char name[80];
        func_020e207c(data_ov004_021707d8.ptr + 0x8c, name, elem->field18);
        SetIndexedName02046574((Obj02046574*)g, 1, name);
#else
        int val = CallFunc020e52a0(data_ov004_021707d8.ptr + 0x8c, elem->field18);
        *(int*)((char*)g + 0x18) = val;
#endif
    }

    if (combatant != 0 && elem != 0 && elem->field0 != 0) {
        struct Ctx_02159650* ctxElem = (struct Ctx_02159650*)elem;
        unsigned int nibble = ctxElem->idx4;
        int inRange = nibble <= 7;
        if (inRange) {
            struct Table9x_02159650 table = data_ov004_0216fbb0;
            int half = GetHalfwordEntryFromField150((struct Field150Holder02052df8*)combatant, table.v[nibble]);
            if (half > 0) {
                struct Element020de650* elem2 = FindElementByKey020dedd0(node, half);
                if (elem2 != 0 && ((struct Field8Bits_02159650*)&elem2->field8)->bit18 != 0) {
#if defined(jpn)
                    SetIndexedName02046574((Obj02046574*)g, 2, *(char**)((char*)elem2 + 4));
#else
                    int val2 = CallFunc020e52a0(data_ov004_021707d8.ptr + 0x8c, half);
                    *(int*)((char*)g + 0x18) = val2;
#endif
                }
            }
        }
    }

    if (entry != 0) {
        StoreInArray0x8b0((struct StoreStruct*)g, 0, data_ov004_021707d8.ptr[0x11] * (entry->field4 >> 7));
    }

    StoreInArray0x8b0((struct StoreStruct*)g, 1, data_ov004_021707d8.ptr[0x11]);
    return 0;
}
