#include <globaldefs.h>
#include <System/Matrix.h>

struct ItemNode02158fec {
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
    virtual void setStyle(int);
    virtual void slot_55();
    virtual void setValue(unsigned int);
    char unknown_4[8];
    unsigned char flags;
    char unknown_d[0x20 - 0xd];
    void* value;
};
struct Grid021f9b30 {
    char unknown_0[0x2c];
    Vector3i position;
    char unknown_38[0x5c - 0x38];
    short page, pages;
};
struct Entry02158fec {
    short id;
    short unknown_2;
    unsigned int count : 7;
    unsigned int cost : 25;
};
struct Element020de650 {
    unsigned int field_0;
    void* value;
    unsigned int kind : 4;
    unsigned int variant : 5;
    unsigned int unknown_9 : 23;
};
struct BattleMenuState02158fec {
    char unknown_0[0x31];
    unsigned char resetPosition;
};
struct Data021707d8 { void* field_0; void* field_4; BattleMenuState02158fec* state; void* field_c; };
struct RoleTable02158fec { unsigned char indices[9]; };
struct Container020dedd0;
extern const RoleTable02158fec data_ov004_0216fb28 __attribute__((aligned(4)));
extern Data021707d8 data_ov004_021707d8;
extern const Vector3i data_ov004_0216fb34;
extern "C" Grid021f9b30* func_ov004_02156ed0(void*, int);
extern "C" Container020dedd0* func_ov004_02156fd4(void*, int);
Entry02158fec* GetEntryFor_021570a4(void*, int);
extern "C" ItemNode02158fec* func_ov004_02156f04(void*, int);
Element020de650* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" ItemNode02158fec* func_ov004_02156fa0(void*, int);
extern "C" void func_ov023_021fb27c(void*, int);
extern "C" ItemNode02158fec* func_ov004_02156f38(void*, int);
void SetCellIfInBounds_021f9b30(Grid021f9b30*, short, unsigned int, unsigned int);
extern "C" int func_ov004_02158bd4(void*);

// USA: func_ov004_02158fec
extern "C" ARM int func_ov004_02158fec(void* object) {
    int textId = 0x12c;
    int secondaryId = textId + 6;
    int nameId = 0x138;
    int countId = nameId + 6;
    int costId = 0x144;
    Grid021f9b30* grid = func_ov004_02156ed0(object, 0x5b);
    if (grid->pages <= 1) {
        grid->page = 0;
        grid->pages = 1;
    }
    Container020dedd0* container = func_ov004_02156fd4(object, 5);
    if (!container) return 0;
    RoleTable02158fec roles = data_ov004_0216fb28;
    for (unsigned char i = 0; i < 6; i++) {
        Entry02158fec* entry = GetEntryFor_021570a4(object, i);
        if (entry) {
            int style = 15;
            if (entry->count == 0) style = 3;
            if (entry->id > 0) {
                ItemNode02158fec* text = func_ov004_02156f04(object, textId);
                if (text) {
                    Element020de650* element = FindElementByKey020dedd0(container, entry->id);
                    if (element) {
                        text->value = element->value;
                        ItemNode02158fec* icon = func_ov004_02156fa0(object, i + 0x14a);
                        if (element->kind == 0) {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(element->variant + 0x26));
                        } else {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(roles.indices[element->kind] + 9));
                        }
                    }
                    text->setStyle(style);
                }
                ItemNode02158fec* secondary = func_ov004_02156f04(object, secondaryId);
                if (secondary) secondary->setStyle(style);
                ItemNode02158fec* name = func_ov004_02156f04(object, nameId);
                if (name) name->setStyle(style);
                ItemNode02158fec* amount = func_ov004_02156f38(object, countId);
                if (amount) {
                    amount->setValue(entry->count);
                    amount->setStyle(style);
                }
                ItemNode02158fec* cost = func_ov004_02156f38(object, costId);
                if (cost) {
                    cost->setValue(entry->cost);
                    cost->setStyle(style);
                }
            } else {
                ItemNode02158fec* text = func_ov004_02156f04(object, textId);
                if (text) text->flags |= 8;
                ItemNode02158fec* secondary = func_ov004_02156f04(object, secondaryId);
                if (secondary) secondary->flags |= 8;
                ItemNode02158fec* name = func_ov004_02156f04(object, nameId);
                if (name) name->flags |= 8;
                ItemNode02158fec* amount = func_ov004_02156f38(object, countId);
                if (amount) amount->flags |= 8;
                ItemNode02158fec* cost = func_ov004_02156f38(object, costId);
                if (cost) cost->flags |= 8;
                SetCellIfInBounds_021f9b30(grid, 0, i, 0);
                ItemNode02158fec* icon = func_ov004_02156fa0(object, i + 0x14a);
                if (icon) icon->flags |= 8;
            }
        }
        textId++;
        secondaryId++;
        nameId++;
        countId++;
        costId++;
    }
    func_ov004_02158bd4(object);
    if (data_ov004_021707d8.state->resetPosition == 0) {
        Vector3i position = data_ov004_0216fb34;
        grid->position = position;
        data_ov004_021707d8.state->resetPosition = 0;
    }
    return 0;
}
