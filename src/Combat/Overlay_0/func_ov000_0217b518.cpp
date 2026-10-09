#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_0205c570;
struct Struct_0205def8;
struct Obj0205eaa0;

struct BattleWindow {
    unsigned char unk0000[0x188];
    unsigned char elements[0x1bea];
    unsigned short flags;
};

struct BattleWindowContext {
    int arg0;
    int arg1;
    BattleWindow* window;
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
    unsigned char unk50[0x3f4];
    unsigned char forceClose;
};

extern BattleWindowContext data_ov000_02184294;
extern unsigned short data_02114e30;
extern Obj0205eaa0 data_02108760;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8* s, int set, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* flags, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* obj, int flag);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
unsigned char* GetFieldAt0x150(unsigned char* member);
extern "C" int _Z35CheckFlagsOrField_0217ab48_0217ab48Pv(void* menu);
extern "C" void func_ov000_02171458(BattleSubMenu* menu);
extern "C" void func_ov000_0217629c(BattleSubMenu* menu);
extern "C" void func_ov000_0217ab8c(BattleSubMenu* menu, int a, int b);
extern "C" void func_ov000_02176e3c(BattleWindow* window, BattleSubMenu* menu, int c, int d, int e, int f);

// USA: func_ov000_0217b518
extern "C" ARM int func_ov000_0217b518(BattleSubMenu* menu, int arg1, int arg2)
{
    signed char current;
    BattleWindow* window;
    signed char previous;
    data_ov000_02184294.window->flags |= 0x100;
    previous = menu->selection;
    current = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)menu->list);
    menu->selection = current;
    window = data_ov000_02184294.window;
    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)window->elements, 1, 0x22);
    if (previous != current) {
        return -1;
    }
    int pressed = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int cancel = (pressed | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(menu->list, 0x14)) ? 1 : 0;
    if (cancel || menu->forceClose) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8*)window->elements, 0, 0x22);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        func_ov000_02171458(menu);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(menu->partyIndex);
        if (member != NULL) {
            unsigned char* data = GetFieldAt0x150((unsigned char*)member);
            if (data != NULL) {
                *(unsigned short*)(data + 0x960) = menu->itemId;
            }
        }
        if (menu->history[menu->depth] != 100) {
            menu->list->state = 15;
        }
        return menu->history[menu->depth];
    }
    if (_Z35CheckFlagsOrField_0217ab48_0217ab48Pv(menu)) {
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
