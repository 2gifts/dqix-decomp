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
#if defined(jpn)
    unsigned char pad_00[0x28];
#else
    unsigned char pad_00[0x5c];
#endif
    char* scratch;
};
struct StoreStruct;
struct Struct_0205d81c;
struct StructA0205d5d0;
TextResources* GetGlobalField0x1c020421a0();
MenuSkill* GetBoundedField420_0217199c(void*, int);
#if defined(jpn)
extern "C" void func_020dea34(int, char*);
#define NotifyLocalizedResourceLoad020dd040 func_020dea34
#else
void NotifyLocalizedResourceLoad020dd040(int, char*);
#endif
extern "C" void func_02046608(TextResources*, int, char*, char*, int, int, int);
extern "C" void func_02046380(TextResources*);
int IsFlag0x18Bit0x200Set(GameObject*);
unsigned int AdjustValueByFieldFlag(void*, unsigned int);
void StoreInArray0x8b0(StoreStruct*, int, int);
const char* CallFunc020e0434With02153694(int);
int AppendString02042058(char*, const char*);
void* FindElementByC40205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0*, int, int, int);
#define TryApplyElemFields0205d5d0 _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih
#else
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
#endif
#if defined(jpn)
extern "C" void func_0205d304(SkillTextWindow*, char*, int, int, int, int, int);
extern "C" void _Z14SetByteInRangePhih(unsigned char*, int, unsigned char);
extern "C" void _Z14SetByteAtIndexPhih(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void func_0205d304(SkillTextWindow*, char*, int, int, int, int, int, int);
#endif

// USA: func_ov000_02179194
extern "C" ARM void func_ov000_02179194(SkillDisplay* display, SkillMenu* menu) {
    char* destination;
    TextResources* resources;
#if !defined(jpn)
    char text[0x800];
#endif
    if (!menu) return;
    int cursor = menu->cursor;
    char* scratch = GetGlobalField0x1c020421a0()->scratch;
#if defined(jpn)
    memset(scratch, 0, 0x800);
#else
    memset(scratch, 0, 0x960);
#endif
    GameState* game = GameState::GetInstance();
    MenuSkill* skill = GetBoundedField420_0217199c(menu, cursor);
    if (!skill) return;
    GameObject* combatant = game->GetCombatantByIndex(menu->combatant);
    if (!combatant) return;
    GameObject* partyMember = GetCombatantWithFlag0x100(game, menu->combatant);
    if (!partyMember) return;
    NotifyLocalizedResourceLoad020dd040(skill->skill, scratch);
#if defined(jpn)
    destination = scratch;
#else
    func_02046608(GetGlobalField0x1c020421a0(), 10, scratch, text, 0x72, 0, 0);
    destination = text;
#endif
    resources = GetGlobalField0x1c020421a0();
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
#if defined(jpn)
    _Z14SetByteInRangePhih((unsigned char*)resources, 0, 3);
    _Z14SetByteInRangePhih((unsigned char*)resources, 1, 3);
    _Z14SetByteAtIndexPhih((unsigned char*)resources, 0, 1);
    _Z14SetByteAtIndexPhih((unsigned char*)resources, 1, 1);
    AppendString02042058(destination, data_ov000_02185169);
#else
    AppendString02042058(destination, CallFunc020e0434With02153694(0x3ec));
#endif
    SkillTextWindow* window = &display->window;
    if (FindElementByC40205d81c((Struct_0205d81c*)window, 0x23)) {
#if defined(jpn)
        TryApplyElemFields0205d5d0((StructA0205d5d0*)window, 0x23, (int)destination, 1);
#else
        TryApplyElemFields0205d5d0((StructA0205d5d0*)window, 0x23, (int)destination, 1, 0);
#endif
    } else {
        int width = menu->width;
        int height = menu->height;
#if defined(jpn)
        window->x = 12;
#else
        window->x = 16;
#endif
#if defined(jpn)
        window->y = 6;
#else
        window->y = 10;
#endif
#if defined(jpn)
        window->width = (width >> 3) + 22;
#else
        window->width = (width >> 3) + 16;
#endif
        window->height = height >> 3;
        window->left = 7;
#if defined(jpn)
        window->top = 8;
#else
        window->top = 6;
#endif
        window->right = 10;
        window->bottom = 14;
        window->id = 0x23;
#if defined(jpn)
        func_0205d304(window, destination, 1, 0, 0, 1, 0);
#else
        func_0205d304(window, destination, 1, 0, 0, 1, 0, 0);
#endif
    }
}
