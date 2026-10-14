#include <globaldefs.h>
#include "GameState/GameState.h"

struct ActionFlags { unsigned int low : 27; unsigned int enabled0 : 1; unsigned int enabled1 : 1; unsigned int disabled : 1; unsigned int high : 2; };
struct ActionNode { int field0; ActionFlags flags; };
struct ActionEntry { ActionNode* node; void* field4; unsigned int type : 4; unsigned int rest : 14; unsigned int marked : 1; unsigned int high : 13; char pad[12]; short value; char tail[6]; };
struct ActionExtension { char pad[0x194]; ActionEntry entries[24]; char tail[8]; unsigned char selection : 1; unsigned char rest : 7; };
struct CombatantActions { char pad[0x150]; ActionExtension* extension; };
struct BattleActionState { char pad[0xe]; short key; char pad10[0x2c]; short combatant; char pad3e[0x4e]; char controller[16]; unsigned char active; };
struct BattleActionData { char pad[8]; BattleActionState* battle; };
struct ActionKeys { int keys[9]; };
struct ActionIndices { unsigned char indices[8]; };
struct GlobalController { char pad[0x18]; void* selected; };
struct Container020dedd0;
struct Field150Holder02052df8;
struct Obj021fbdf4;
extern BattleActionData data_ov004_021707d8;
extern ActionKeys data_ov004_0216fbf8;
extern ActionIndices data_ov004_0216fb18;
extern "C" signed char func_ov004_02157128(void*);
extern "C" void func_0202ae18();
extern "C" Container020dedd0* func_ov004_02156fd4(void*, int);
ActionEntry* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" int func_020dd4c4(int, ActionEntry*);
extern "C" void func_ov011_021848a0(void*, int);
int GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
extern "C" void func_ov004_02159650(void*);
GlobalController* GetGlobalField0x1c020421a0();
void* CallFunc020e52a0_020e5294(void*, int);
extern "C" Obj021fbdf4* func_ov004_02157054(void*, int);
void SetFieldThenTailCallOffset20_021fbdf4(Obj021fbdf4*, unsigned char);
typedef void (*ActionSetter)(Obj021fbdf4*, int);
extern "C" int func_ov004_02157a28(void*, int);

static inline ActionExtension* GetActions(CombatantActions* combatant) { return combatant->extension; }

// USA: func_ov004_02159fcc
extern "C" ARM int func_ov004_02159fcc(void* obj) {
    int flag = func_ov004_02157128(obj);
    data_ov004_021707d8.battle->combatant = flag;
    func_0202ae18();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), flag);
    if (!combatant) return 0;
    Container020dedd0* container = func_ov004_02156fd4(obj, 5);
    if (!container) return 0;
    ActionEntry* entry = FindElementByKey020dedd0(container, data_ov004_021707d8.battle->key);
    if (!entry) return 0;
    unsigned int type = entry->type;
    if (func_020dd4c4(flag, entry)) {
        func_ov011_021848a0(obj, 0x392);
        return 0;
    }
    ActionKeys keys = data_ov004_0216fbf8;
    int key = GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, keys.keys[entry->type]);
    if (key > 0) {
        ActionEntry* selected = FindElementByKey020dedd0(container, key);
        if (selected && selected->marked) {
            func_ov004_02159650(obj);
            GlobalController* controller = GetGlobalField0x1c020421a0();
            controller->selected = CallFunc020e52a0_020e5294(data_ov004_021707d8.battle->controller, selected->value);
            func_ov011_021848a0(obj, 0x23b6);
            return 0;
        }
    }
    if (type == 7 && GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, 9) == 0x4680) {
        int unavailable;
        if (!combatant) unavailable = 0;
        else {
            ActionIndices indices = data_ov004_0216fb18;
            unsigned char flags[2];
            for (unsigned char i = 0; i < 8; i++) {
                unsigned char index = indices.indices[i];
                if (index == 0xff) break;
                ActionEntry* action;
                ActionExtension* extension = GetActions((CombatantActions*)combatant);
                action = &extension->entries[index];
                if (action && action->value >= 0) {
                    ActionNode* node = action->node;
                    if (node && !node->flags.disabled) {
                        unsigned int enabled = node->flags.enabled0 ? 1 : 0;
                        flags[0] = enabled;
                        flags[1] = node->flags.enabled1 ? 1 : 0;
                        if (!flags[extension->selection]) {
                            unavailable = 1;
                            goto checked;
                        }
                    }
                }
            }
            unavailable = 0;
        }
    checked:
        if (unavailable) {
            func_ov011_021848a0(obj, 0x23b5);
            return 0;
        }
    }
    Obj021fbdf4* node = func_ov004_02157054(obj, 7);
    if (node) {
        ActionSetter setter = (ActionSetter)SetFieldThenTailCallOffset20_021fbdf4;
        setter(node, -1);
        data_ov004_021707d8.battle->active = 1;
    }
    return func_ov004_02157a28(obj, 0);
}
