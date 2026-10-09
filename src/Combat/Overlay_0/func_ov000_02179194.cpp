#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct MenuSkill {
    unsigned int field_00;
    unsigned int skill : 12;
    unsigned int field_04 : 20;
    unsigned int cost : 8;
    unsigned int field_08 : 24;
};
struct SkillMenu {
    unsigned char pad_00[0xe];
    short maximumCost;
    unsigned char pad_10[0xe];
    short cursor;
    unsigned char pad_20[0x24];
    int width;
    int height;
    int combatant;
};
struct SkillTextWindow {
    unsigned char pad_00[0xa0];
    short x;
    short y;
    short width;
    short height;
    short left;
    short top;
    short right;
    short bottom;
    unsigned char field_b0;
    unsigned char id;
};
struct SkillDisplay {
    unsigned char pad_00[0x188];
    SkillTextWindow window;
};
struct TextResources {
    unsigned char pad_00[0x5c];
    char* scratch;
};
struct StoreStruct;
struct Struct_0205d81c;
struct StructA0205d5d0;
TextResources* GetGlobalField0x1c020421a0();
MenuSkill* GetBoundedField420_0217199c(void*, int);
void NotifyLocalizedResourceLoad020dd040(int, char*);
extern "C" void func_02046608(TextResources*, int, char*, char*, int, int, int);
extern "C" void func_02046380(TextResources*);
int IsFlag0x18Bit0x200Set(GameObject*);
unsigned int AdjustValueByFieldFlag(void*, unsigned int);
void StoreInArray0x8b0(StoreStruct*, int, int);
const char* CallFunc020e0434With02153694(int);
int AppendString02042058(char*, const char*);
void* FindElementByC40205d81c(Struct_0205d81c*, int);
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
extern "C" void func_0205d304(SkillTextWindow*, char*, int, int, int, int, int, int);

// USA: func_ov000_02179194
extern "C" ARM void func_ov000_02179194(SkillDisplay* display, SkillMenu* menu) {
    char text[0x800];
    if (!menu) return;
    int cursor = menu->cursor;
    char* scratch = GetGlobalField0x1c020421a0()->scratch;
    memset(scratch, 0, 0x960);
    GameState* game = GameState::GetInstance();
    MenuSkill* skill = GetBoundedField420_0217199c(menu, cursor);
    if (!skill) return;
    GameObject* combatant = game->GetCombatantByIndex(menu->combatant);
    if (!combatant) return;
    GameObject* partyMember = GetCombatantWithFlag0x100(game, menu->combatant);
    if (!partyMember) return;
    NotifyLocalizedResourceLoad020dd040(skill->skill, scratch);
    func_02046608(GetGlobalField0x1c020421a0(), 10, scratch, text, 0x72, 0, 0);
    char* destination = text;
    TextResources* resources = GetGlobalField0x1c020421a0();
    func_02046380(resources);
    int cost;
    if (IsFlag0x18Bit0x200Set(combatant)) cost = 0;
    else {
        unsigned int value = skill->cost;
        if (value >= 0xff) cost = menu->maximumCost;
        else cost = AdjustValueByFieldFlag(partyMember, value);
    }
    StoreInArray0x8b0((StoreStruct*)resources, 0, cost);
    StoreInArray0x8b0((StoreStruct*)resources, 1, menu->maximumCost);
    AppendString02042058(destination, CallFunc020e0434With02153694(0x3ec));
    SkillTextWindow* window = &display->window;
    if (FindElementByC40205d81c((Struct_0205d81c*)window, 0x23)) {
        TryApplyElemFields0205d5d0((StructA0205d5d0*)window, 0x23, (int)destination, 1, 0);
    } else {
        int width = menu->width;
        int height = menu->height;
        window->x = 16;
        window->y = 10;
        window->width = (width >> 3) + 16;
        window->height = height >> 3;
        window->left = 7;
        window->top = 6;
        window->right = 10;
        window->bottom = 14;
        window->id = 0x23;
        func_0205d304(window, destination, 1, 0, 0, 1, 0, 0);
    }
}
