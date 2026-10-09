#include <globaldefs.h>
#include "Combat/Main/MessageSlotTable.h"
#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);

GameObject* GetCombatantChecked(GameState* battleStruct, int combatantId);

extern "C" int func_020dd4c4(void* id, void* node);
extern "C" void func_020dd7ac(void* buf);
extern "C" void func_020dd8b4(int buf, int id, int node, int flag);

extern unsigned char data_ov003_0217fac8[];

struct NodeBits020dedd0 {
    char pad[0xc];
    unsigned int lo : 7;
    unsigned int kind : 4;
    unsigned int hi : 21;
};

// USA: func_ov003_021753a0  (semantic: ApplyEntryAndCheckKind_021753a0)
#pragma opt_common_subs off
extern "C" ARM int func_ov003_021753a0(char* obj, int id, int arg2, int arg3) {
    int result = 1;
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = GetCombatantChecked(battle, id);
    if (combatant == 0) return result;

    int key = *(short*)(obj + 0x1000 + 0x3a);
    struct Element020de650* node = FindElementByKey020dedd0((struct Container020dedd0*)(obj + 0x74 + 0x800), key);
    if (node == 0) return result;

    func_020dd4c4((void*)id, node);

    MessageSlotTable_020dd7ac buf;
    func_020dd7ac(&buf);
    func_020dd8b4((int)&buf, id, (int)node, 0);

    int kind = ((struct NodeBits020dedd0*)node)->kind;
    unsigned char kindByte = data_ov003_0217fac8[kind];
    func_020dd9b4(&buf, kindByte, (void*)arg2, (void*)arg3);

    switch (kindByte) {
    case 3:
    case 4:
        result = 0;
        break;
    }
    return result;
}
