#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0205c570;
struct Struct_0205def8;
struct Obj0205eaa0;

struct BattleWindow {
    unsigned char unk0000[0x188];
#if defined(jpn)
    unsigned char elements[0x1faa - 0x188];
#else
    unsigned char elements[0x1bea];
#endif
    unsigned short flags;
};

struct BattleWindowContext {
#if defined(jpn)
    BattleWindow* window;
    int arg0;
    int arg1;
    BattleWindow* const& GetWindow() const {
        return window;
    }
#else
    int arg0;
    int arg1;
    BattleWindow* window;
#endif
};

struct MenuElementList {
    unsigned char unk00[0xb8];
    unsigned char state;
};

struct BattleSubMenu {
    unsigned char unk00[0x10];
    signed char history[8];
    signed char depth;
    unsigned char unk19[7];
    signed char selection;
    unsigned char unk21[5];
    unsigned short itemId;
    unsigned char unk28[0x10];
    MenuElementList* list;
    unsigned char unk3c[0x10];
    int partyIndex;
#if defined(jpn)
    unsigned char unk50[0x434];
#else
    unsigned char unk50[0x3f4];
#endif
    unsigned char forceClose;
#if defined(jpn)
    const signed char& GetSelection() const {
        return selection;
    }
#endif
};

extern BattleWindowContext data_ov000_02184294;
extern unsigned short data_02114e30;
extern Obj0205eaa0 data_02108760;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int set, int key);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* flags, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* member);
int CheckFlagsOrField_0217ab48_0217ab48(void* menu);
extern "C" void func_ov000_02171458(BattleSubMenu* menu);
extern "C" void func_ov000_0217629c(BattleSubMenu* menu);
extern "C" void func_ov000_0217ab8c(BattleSubMenu* menu, int a, int b);
extern "C" void func_ov000_02176e3c(BattleWindow* window, BattleSubMenu* menu, int c, int d, int e, int f);

#if defined(jpn)
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(BattleSubMenu* menu, int arg1, int arg2)
{
    BattleWindow* window;
    enum Selection { kSelectionMin = -128, kSelectionMax = 127 };
    Selection current;
    data_ov000_02184294.window->flags |= 0x100;
    const signed char previous = menu->GetSelection();
    current = (Selection)(signed char)GetActiveScaledSum0205d794((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    {
    window = data_ov000_02184294.GetWindow();
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x601);
    bool cancel = (pressed | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->forceClose) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x8c8) = menu->itemId;
            }
        }
        if (menu->history[menu->depth] != 100) {
            menu->list->state = 15;
        }
        return menu->history[menu->depth];
    }
    if (CheckFlagsOrField_0217ab48_0217ab48(menu)) {
        func_ov000_0217629c(menu);
        menu->history[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        menu->selection = -1;
        menu->itemId = 0;
        func_ov000_0217ab8c(menu, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.window, menu, menu->history[menu->depth],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(BattleSubMenu* menu, int arg1, int arg2)
{
    signed char current;
    BattleWindow* window;
    signed char previous;
    data_ov000_02184294.window->flags |= 0x100;
    previous = menu->selection;
    current = GetActiveScaledSum0205d794((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    window = data_ov000_02184294.window;
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x601);
    int cancel = (pressed | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->forceClose) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)window->elements, 0, 0x22);
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = GetFieldAt0x150_02053c6c((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x960) = menu->itemId;
            }
        }
        if (menu->history[menu->depth] != 100) {
            menu->list->state = 15;
        }
        return menu->history[menu->depth];
    }
    if (CheckFlagsOrField_0217ab48_0217ab48(menu)) {
        func_ov000_0217629c(menu);
        menu->history[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        menu->selection = -1;
        menu->itemId = 0;
        func_ov000_0217ab8c(menu, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.window, menu, menu->history[menu->depth],
                            data_ov000_02184294.arg1, data_ov000_02184294.arg0, 0);
    }
    return -1;
}
#endif
