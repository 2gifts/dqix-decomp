#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

class GameState {
public:
    static GameState* GetInstance();
};

struct Stats_021f9030 {
    unsigned short currHP;
    char pad2[0x16];
    unsigned int flags18;
};

struct GameObject {
    char pad0[4];
    short id;
    char pad6[0x12a];
    unsigned int* status;
    char pad134[4];
    struct Stats_021f9030* stats;
    char pad13c[0x40];
    unsigned char side;
};

struct S02053dc0;

struct Command_021f9030 {
    unsigned short action;
    signed char target;
    unsigned char side;
};

struct Battle_021f9030 {
    char pad0[0x8e18];
    unsigned char* party;
};

struct Field_021f9030 {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int mode;
};

struct Skill_021f9030 {
    char field_0[4];
    unsigned int id : 12;
    unsigned int field_4_end : 20;
    unsigned int cost : 8;
    unsigned int field_8 : 20;
    unsigned int excluded : 1;
    unsigned int field_8_end : 3;
    char field_c[0xc];
    unsigned int field_18 : 5;
    unsigned int type : 7;
    unsigned int field_18_end : 20;
    char field_1c[0x10];
    unsigned int field_2c : 14;
    unsigned int restriction : 6;
    unsigned int field_2c_end : 12;
};

struct SkillSlot_021f9030 {
    short id;
    char flags;
    unsigned char inherent;
};

struct Planner_021f9030 {
    struct Battle_021f9030* owner;
    short id;
    unsigned char mode;
    unsigned char active;
    struct GameObject* combatant;
    int allies;
    char field_10[0x6c];
    struct GameObject* targets[8];
    int targetCount;
    char field_a0[0x64];
    int power[4];
    float ratio[4];
    float weight;
    int target;
    char field_12c[4];
    int field_130;
    char field_134[0x40];
    int count;
    struct SkillSlot_021f9030 skills[0x134];
    struct SkillSlot_021f9030* selected;
    struct Skill_021f9030* selectedSkill;
    int selectedCost;
};

struct SkillIds_021f9030 {
    unsigned short ids[10];
};

extern "C" void __clear(void* dst, int size);
void* GetFieldAt0x150_02053c6c(unsigned char* obj);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int IsCombatantFlag2Mask8192_021e6798(GameObject* combatant);
Command_021f9030* GetField0x19cOrNull(S02053dc0* p);
Skill_021f9030* SearchBothTables02079e2c(char* table, int id);
extern "C" int func_ov000_02155f9c(Battle_021f9030* battle, int combatantId, int checkSubFlag);
extern "C" void func_ov024_021f7478(Planner_021f9030* obj);
extern "C" int func_ov024_021f8874(Planner_021f9030* obj, Skill_021f9030* skill, GameObject* combatant, int* cost);
extern "C" void func_ov024_021fa7ec(Planner_021f9030* self, float* outHi, float* outLo, float* outAvg,
                                    int* outIndex, float baseHi, float baseLo, int useBase,
                                    GameObject* target, int index);
extern "C" float func_ov024_021db358(GameObject* obj);

extern SkillIds_021f9030 data_ov024_021fefc2;

// USA: func_ov024_021f9030
extern "C" ARM void func_ov024_021f9030(Planner_021f9030* obj, Battle_021f9030* owner, int id, unsigned short* state) {
    GameState* gameState = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gameState, id);
    Field_021f9030* field = (Field_021f9030*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    ActionDataTables* database = GetData02108e10_020797dc();
    unsigned char mode = (signed char)field->mode;
    if (mode >= 5) {
        return;
    }
    if (func_ov000_02155f9c(owner, id, 0) != 0 || *state != 1) {
        return;
    }
    obj->owner = owner;
    obj->id = id;
    obj->weight = 0.4f;
    if (obj->mode == 2) {
        obj->weight = 0.25f;
    }
    obj->mode = mode;
    obj->active = 1;
    SkillIds_021f9030 ids = data_ov024_021fefc2;
    unsigned char found[10];
    __clear(found, sizeof(found));
    short costs[10];
    __clear(costs, sizeof(costs));
    unsigned char disabled;
    unsigned char reviving;
    unsigned char buffing;
    int hasInherent = 0;
    int isMode0 = obj->mode == 0;
    int isMode14 = 1;
    if (obj->mode != 1 && obj->mode != 4) {
        isMode14 = 0;
    }
    int isMode2 = obj->mode == 2;
    int isMode3 = obj->mode == 3;
    func_ov024_021f7478(obj);
    int i;
    disabled = 0;
    reviving = 0;
    buffing = 0;
    for (i = 0; i < 4; i++) {
        GameObject* ally = GetCombatantWithFlag0x100_0200ff1c(gameState, i);
        if (ally == 0) continue;
        if (!TestBitAt0x34_020a35e0(obj->owner->party, i)) continue;
        if (IsCombatantFlag2Mask8192_021e6798(ally)) continue;
        if (*ally->status & 1) continue;
        if (ally->stats->flags18 & 0x800) {
            disabled = 1;
        }
        Command_021f9030* command = GetField0x19cOrNull((S02053dc0*)ally);
        if (command == 0) continue;
        unsigned short action = command->action;
        if (action == 0x201) {
            reviving = 1;
            continue;
        }
        if (action == 0xb9 || action == 0x92 || action == 0xb6) {
            buffing = 1;
        }
    }
    for (i = 0; i < obj->count; i++) {
        SkillSlot_021f9030* slot = &obj->skills[i];
        Skill_021f9030* skill = SearchBothTables02079e2c((char*)database, slot->id);
        int cost = 0;
        if (skill->type == 2) {
            if (func_ov024_021f8874(obj, skill, combatant, &cost)) {
                if (slot->inherent == 0) {
                    hasInherent = 1;
                }
            }
            continue;
        }
        if (!skill->excluded && skill->restriction == 0) continue;
        if (!func_ov024_021f8874(obj, skill, combatant, &cost)) continue;
        if (obj->mode == 4 && cost != 0) continue;
        for (int j = 0; j < 10; j++) {
            if (ids.ids[j] == skill->id) {
                found[j] = 1;
                costs[j] = cost;
                break;
            }
        }
    }
    if (found[0] && !disabled && !reviving && !isMode0 && (!isMode14 || obj->allies > 2)) {
        if (hasInherent) {
            float weight = obj->weight;
            if (obj->target != obj->id && obj->ratio[obj->target] < weight) goto skipRevive;
        }
        Command_021f9030* command = GetField0x19cOrNull((S02053dc0*)combatant);
        command->action = 0x201;
        *state = 0x201;
        command->side = 0;
        command->target = combatant->id;
        return;
    }
skipRevive:
    if (found[1] && obj->targetCount <= 1 && (isMode0 || isMode14 || isMode2)) {
        GameObject* target = obj->targets[0];
        obj->selectedSkill = SearchBothTables02079e2c((char*)database, 0x45);
        obj->selectedCost = obj->selectedSkill->cost;
        float hi;
        float lo;
        float avg;
        int index;
        hi = 0;
        lo = 0;
        avg = 0;
        index = -1;
        func_ov024_021fa7ec(obj, &hi, &lo, &avg, &index, 0, 0, 0, target, 0);
        if (lo > target->stats->currHP) {
            Command_021f9030* command = GetField0x19cOrNull((S02053dc0*)combatant);
            command->action = 0x45;
            *state = 0x45;
            command->side = target->side;
            command->target = target->id;
            return;
        }
    }
    if (!(func_ov024_021db358(obj->combatant) > 0.25f) && !disabled && !reviving && isMode3 && !hasInherent) {
        int action = 3;
        if (found[5]) {
            action = 0x87;
        }
        Command_021f9030* command = GetField0x19cOrNull((S02053dc0*)combatant);
        command->action = (unsigned short)action;
        *state = (unsigned short)action;
        command->side = 0;
        command->target = combatant->id;
        return;
    }
    if (!found[7] && !found[8] && !found[6]) return;
    if (!isMode3 || obj->field_130 == 0) return;
    if (disabled || reviving || buffing || hasInherent) return;
    if (func_ov024_021db358(combatant) < 0.5f) return;
    int self = obj->id;
    int target = obj->target;
    if (target == self) return;
    if (target < 0 || target > 4) return;
    if (self < 0 || self > 4) return;
    if (obj->power[self] < obj->power[target] * 2) return;
    int action = 0;
    if (obj->field_130 >= 2 && found[7]) {
        action = 0xb6;
    } else if (found[8]) {
        action = 0xb9;
    } else if (found[6]) {
        action = 0x92;
    } else if (found[7]) {
        action = 0xb6;
    }
    if (action == 0) return;
    Command_021f9030* command = GetField0x19cOrNull((S02053dc0*)combatant);
    command->action = (unsigned short)action;
    *state = (unsigned short)action;
    command->side = 0;
    command->target = action == 0xb6 ? combatant->id : obj->target;
}
