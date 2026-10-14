#include <globaldefs.h>
#include <GameState/GameState.h>

struct ItemNode0215b360 {
    virtual void slot_0();
    virtual void slot_1();
    virtual void slot_2();
    virtual void slot_3();
    virtual void slot_4();
    virtual void slot_5();
    virtual void slot_6();
    virtual void slot_7();
    virtual void slot_8();
    virtual void slot_9();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual void slot_29();
    virtual void slot_30();
    virtual void slot_31();
    virtual void slot_32();
    virtual void slot_33();
    virtual void slot_34();
    virtual void slot_35();
    virtual void slot_36();
    virtual void slot_37();
    virtual void slot_38();
    virtual void slot_39();
    virtual void slot_40();
    virtual void slot_41();
    virtual void slot_42();
    virtual void slot_43();
    virtual void slot_44();
    virtual void slot_45();
    virtual void slot_46();
    virtual void slot_47();
    virtual void slot_48();
    virtual void slot_49();
    virtual void slot_50();
    virtual void slot_51();
    virtual void slot_52();
    virtual void slot_53();
    virtual void slot_54();
    virtual void slot_55();
    virtual void notify(int);
    char unknown_4[8];
    unsigned char flags;
    char unknown_d[0x20 - 0xd];
    void* value;
};
struct Grid021f9b30 {
    char unknown_0[0x5c];
    short page, pages;
};
struct ItemLists0215b360 {
    char unknown_0[0x7c];
    unsigned char listIds[8];
};
struct Data021707d8 {
    void* field_0;
    void* field_4;
    ItemLists0215b360* state;
    void* field_c;
};
struct PartyState0215b360 {
    char unknown_0[0x1d4];
    unsigned char inventory[1];
};
struct TableA68;
struct Container020dedd0;
struct Element020de650 {
    unsigned int field_0;
    void* value;
};
extern Data021707d8 data_ov004_021707d8;
extern "C" Container020dedd0* func_ov004_02156fd4(void*, int);
TableA68* DispatchAdjustmentIfType4_02157018(void*, int);
int DispatchNodeIfType7_02156e2c(void*, int);
extern "C" ItemNode0215b360* func_ov004_02156f04(void*, int);
void* FindEntryByKey(TableA68*, int);
void ClearNodeMaskById_021f6600(void*, int, int);
short* GetPointerFromArray0xbd0(unsigned char*, unsigned int);
signed char* GetPointerAt0xbf0(void*, unsigned int);
int CountPositiveEntries0207c638(void*, unsigned int);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" Grid021f9b30* func_ov004_02156ed0(void*, int);
extern "C" ItemNode0215b360* func_ov004_02156f38(void*, int);
Element020de650* FindElementByKey020dedd0(Container020dedd0*, int);
void SetCellIfInBounds_021f9b30(Grid021f9b30*, short, unsigned int, unsigned int);
typedef void (*UnsignedGridCellSetter)(Grid021f9b30*, unsigned short, unsigned int, unsigned int);
typedef void* (*ContextNodeQuery)(void*, int);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
void* CheckThenNotify_02157088(void* object, int key);
extern "C" void func_ov023_021dcae0(void*, int);

// USA: func_ov004_0215b360
extern "C" ARM int func_ov004_0215b360(void* object) {
    short* items = NULL;
    signed char* amounts = NULL;
    int count = 0;
    Container020dedd0* container = func_ov004_02156fd4(object, 5);
    TableA68* table = DispatchAdjustmentIfType4_02157018(object, 3);
    int selected = DispatchNodeIfType7_02156e2c(object, 0x65);
    if (selected < 0) return 0;
    PartyState0215b360* party = (PartyState0215b360*)GetPtrField0x2a04(GameState::GetInstance());
    if (!party) return 0;
    for (int i = 0; i < 8; i++) {
        if (i == selected) {
            ItemNode0215b360* node = func_ov004_02156f04(object, 0x454);
            if (node) node->value = FindEntryByKey(table, (short)(i + 0x1b));
            ClearNodeMaskById_021f6600(object, i + 0x38c, 8);
            items = GetPointerFromArray0xbd0(party->inventory, data_ov004_021707d8.state->listIds[selected]);
            amounts = GetPointerAt0xbf0(party->inventory, data_ov004_021707d8.state->listIds[selected]);
            count = CountPositiveEntries0207c638(party->inventory, data_ov004_021707d8.state->listIds[selected]);
        } else {
            func_ov023_021f65d4(object, i + 0x38c, 8);
        }
    }
    Grid021f9b30* grid = func_ov004_02156ed0(object, 0x63);
    if (!grid) return 0;
    short pages = (count - 1) / 8 + 1;
    if (pages < 1) pages = 1;
    grid->page = 0;
    grid->pages = pages;
    func_ov004_02156f38(object, 0x456)->notify(1);
    func_ov004_02156f38(object, 0x457)->notify(pages);
    for (int i = 0; i < 8; i++)
        func_ov004_02156f38(object, i + 0x461)->notify(amounts[i]);
    for (int i = 0; i < 8; i++) {
        Element020de650* entry = FindElementByKey020dedd0(container, items[i]);
        ItemNode0215b360* node = func_ov004_02156f04(object, i + 0x44c);
        if (!entry) {
            node->flags |= 8;
            func_ov023_021f65d4(object, i + 0x459, 8);
            func_ov023_021f65d4(object, i + 0x461, 8);
            SetCellIfInBounds_021f9b30(grid, 0, (unsigned short)i, 0);
        } else {
            void* value = entry->value ? entry->value : NULL;
            if (node) {
                node->flags &= ~8;
                node->value = value;
                ClearNodeMaskById_021f6600(object, i + 0x459, 8);
                ClearNodeMaskById_021f6600(object, i + 0x461, 8);
                ((UnsignedGridCellSetter)SetCellIfInBounds_021f9b30)(grid, (unsigned short)(i + 0x44c), (unsigned short)i, 0);
            }
        }
    }
    void* node = func_ov004_02156f6c(object, 0x17);
    if (node) func_ov023_021f809c(node, object);
    void* notifier = ((ContextNodeQuery)CheckThenNotify_02157088)(object, 7);
    if (notifier) func_ov023_021dcae0(notifier, -1);
    return 0;
}
