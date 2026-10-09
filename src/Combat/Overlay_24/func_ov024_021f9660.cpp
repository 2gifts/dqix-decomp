#include <globaldefs.h>
#include "GameState/GameState.h"

struct Skill021f9660 {
    char field_0[8];
    unsigned int field_8 : 28;
    unsigned int excluded : 1;
    unsigned int field_8_end : 3;
    char field_c[0xc];
    unsigned int field_18 : 5;
    unsigned int handler : 7;
    unsigned int field_18_end : 20;
    char field_1c[0x10];
    unsigned int field_2c : 14;
    unsigned int restriction : 6;
    unsigned int field_2c_end : 12;
};
struct SkillSlot021f9660 { short id; short flags; };
struct Planner021f9660 {
    char field_0[6];
    unsigned char mode;
    char field_7;
    GameObject* combatant;
    char field_c[0x20];
    unsigned char field_2c;
    char field_2d[7];
    unsigned char field_34;
    char field_35[3];
    int field_38;
    int field_3c;
    char field_40[0x134];
    int count;
    SkillSlot021f9660 skills[0x134];
    SkillSlot021f9660* selected;
    Skill021f9660* selectedSkill;
    int cost;
    unsigned char field_654;
    unsigned char active;
};
typedef void (Planner021f9660::*SkillHandler021f9660)();
struct HandlerTable021f9660 { SkillHandler021f9660 handlers[79]; };
extern HandlerTable021f9660 data_ov024_021ffeac;
extern unsigned int data_ov024_02200150;
extern SkillHandler021f9660 data_020e6d5c;
void* GetFieldAt0x150(unsigned char*);
char* GetData02108e10();
extern "C" Skill021f9660* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" int func_ov024_021f8874(Planner021f9660*, Skill021f9660*, GameObject*, int*);

// USA: func_ov024_021f9660
extern "C" ARM void func_ov024_021f9660(Planner021f9660* planner) {
    GameObject* combatant = planner->combatant;
    GetFieldAt0x150((unsigned char*)combatant);
    char* database = GetData02108e10();
    if (!(data_ov024_02200150 & 1)) {
        SkillHandler021f9660 empty = data_020e6d5c;
        data_ov024_021ffeac.handlers[0] = empty;
        data_ov024_021ffeac.handlers[11] = empty;
        data_ov024_021ffeac.handlers[12] = empty;
        data_ov024_021ffeac.handlers[29] = empty;
        data_ov024_021ffeac.handlers[30] = empty;
        data_ov024_021ffeac.handlers[31] = empty;
        data_ov024_021ffeac.handlers[34] = empty;
        data_ov024_021ffeac.handlers[35] = empty;
        data_ov024_021ffeac.handlers[44] = empty;
        data_ov024_021ffeac.handlers[45] = empty;
        data_ov024_021ffeac.handlers[52] = empty;
        data_ov024_021ffeac.handlers[57] = empty;
        data_ov024_021ffeac.handlers[58] = empty;
        data_ov024_021ffeac.handlers[59] = empty;
        data_ov024_021ffeac.handlers[60] = empty;
        data_ov024_021ffeac.handlers[65] = empty;
        data_ov024_021ffeac.handlers[66] = empty;
        data_ov024_02200150 |= 1;
    }
    for (int index = 0; index < planner->count; ++index) {
        Skill021f9660* skill = _Z24SearchBothTables02079e2cPci(database, planner->skills[index].id);
        if (skill->excluded) continue;
        if (skill->restriction) continue;
        int cost;
        if (!func_ov024_021f8874(planner, skill, combatant, &cost)) continue;
        if (planner->mode == 4 && cost != 0) continue;
        planner->selected = &planner->skills[index];
        planner->selectedSkill = skill;
        planner->cost = cost;
        planner->field_34 = 0;
        planner->field_2c = 0;
        planner->active = 1;
        planner->field_38 = 0;
        planner->field_3c = 0;
        SkillHandler021f9660 handler = data_020e6d5c;
        if (skill->handler <= 78) handler = data_ov024_021ffeac.handlers[skill->handler];
        if (handler != 0) (planner->*handler)();
    }
}
