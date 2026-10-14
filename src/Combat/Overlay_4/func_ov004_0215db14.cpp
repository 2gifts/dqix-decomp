#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Menu0215db14 {
    char pad00[0xe];
    short key;
    char pad10;
    unsigned char quantity;
    signed char combatant;
    char pad13[0x1f];
    short entries[4];
    short count;
    char pad3c[0x61];
    unsigned char active;
};
struct Holder0215db14 { char pad[8]; Menu0215db14* menu; };
extern Holder0215db14 data_ov004_021707d8;
struct IndexList0215db14 { int entries[4]; };
extern IndexList0215db14 data_ov004_0216fb40;
struct ItemTransferContext0215db14 { SafeAllocator allocator; char state[0x18]; int container; char pad[8]; };
struct Combatant0215db14 { char pad[0x130]; unsigned int* flags; };
struct Slots02083960;
int DispatchNodeIfType7_02156e2c(void*, int);
extern "C" int func_ov004_0215da0c(void*);
Slots02083960* GetFieldAt0x150(unsigned char*);
int CountPositiveSlots02083960(Slots02083960*);
short SumKeyedLookups02086bf4(char*, int);
extern "C" int func_ov004_02156fd4(void*, int);
void* ZeroInitReturn020de824(void*);
void InitStruct0207cbe8(char*);
void InitStruct0207cc0c(char*);
extern "C" void func_0207ccf0(void*, int, int, int, int, int, int);
extern "C" void func_ov011_021848a0(void*, int);
extern "C" void func_ov023_021f65d4(void*, int, int);

// USA: func_ov004_0215db14
extern "C" ARM int func_ov004_0215db14(void* obj) {
    GameState* state = GameState::GetInstance();
    if (!data_ov004_021707d8.menu->active) return 0;
    int index = DispatchNodeIfType7_02156e2c(obj, 0x5f);
    if (index < 0) return 0;
    GameObject* combatant;
    int freeSlots;
    int selected;
    IndexList0215db14 list;
    COPY_ARRAY(list.entries, data_ov004_0216fb40.entries);
    Holder0215db14* holder = &data_ov004_021707d8;
    holder++;
    int count;
    int i;
    Menu0215db14* menu;
    menu = (holder - 1)->menu;
    count = menu->count;
    for (i = 0; i < count; i++) list.entries[i] = menu->entries[i];
    if (count == index) {
        func_ov004_0215da0c(obj);
        return 0;
    }
    selected = list.entries[index];
    menu->combatant = selected;
    combatant = GetCombatantWithFlag0x100(state, data_ov004_021707d8.menu->combatant);
    freeSlots = 0;
    if (combatant) {
        Slots02083960* slots = GetFieldAt0x150((unsigned char*)combatant);
        if (slots) freeSlots = 8 - CountPositiveSlots02083960(slots);
    }
    int total = SumKeyedLookups02086bf4((char*)GetPtrField0x2a04(state), data_ov004_021707d8.menu->key);
    int container = func_ov004_02156fd4(obj, 5);
    if (container) {
        ItemTransferContext0215db14 work;
        work.allocator.ResetAllocatorPointer();
        ZeroInitReturn020de824(work.state);
        InitStruct0207cbe8((char*)&work);
        InitStruct0207cbe8((char*)&work);
        work.container = container;
        func_0207ccf0(&work, data_ov004_021707d8.menu->key, data_ov004_021707d8.menu->quantity, selected, 1, 1, 0);
        InitStruct0207cc0c((char*)&work);
        data_ov004_021707d8.menu->active = 0;
    }
    if (data_ov004_021707d8.menu->quantity > freeSlots && total < 99) {
        func_ov011_021848a0(obj, 0x2383);
    } else if (data_ov004_021707d8.menu->quantity > freeSlots && total >= 99) {
        func_ov011_021848a0(obj, 0x2386);
    } else if (combatant && (*((Combatant0215db14*)combatant)->flags & 1)) {
        func_ov011_021848a0(obj, 0x2387);
    } else {
        func_ov011_021848a0(obj, 0x2382);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
