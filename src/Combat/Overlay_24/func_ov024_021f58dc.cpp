#include <globaldefs.h>

struct Out0215fb54 { int keys[2]; };
extern "C" int _Z23FindRecordByKey0215fb54isP11Out0215fb54(int unused, short key, Out0215fb54* out);
void* GetActiveCombatWork();
extern "C" void* _Z26FindNodeByShortKey02162d88Pvs(void* obj, int key);

struct Gate_021f58dc { char pad0; unsigned char flags : 4; unsigned char pad1 : 4; };
struct Obj_021f58dc { int field0; };
struct SkillRecord_021f58dc {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest4 : 20;
    char pad8[0x18 - 0x8];
    unsigned int gap18 : 5;
    unsigned int kind : 7;
    unsigned int rest18 : 20;
};
extern Out0215fb54 data_ov024_021fea1c[];

// JPN: func_ov024_021f60a8
// USA: func_ov024_021f58dc
extern "C" ARM int func_ov024_021f58dc(Obj_021f58dc* obj, int id, SkillRecord_021f58dc* skill, int* outCount, short* outArray) {
    void* work;
    Gate_021f58dc* gate = (Gate_021f58dc*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    work = GetActiveCombatWork();
    if (!work) return 0;
    if (skill->kind == 0xc) {
        Out0215fb54 keys;
        keys.keys[1] = data_ov024_021fea1c[30].keys[1];
        keys.keys[0] = data_ov024_021fea1c[30].keys[0];
        int count = _Z23FindRecordByKey0215fb54isP11Out0215fb54(obj->field0, skill->id, &keys);
        for (int i = 0; i < count; i++) {
            if (!_Z26FindNodeByShortKey02162d88Pvs(work, keys.keys[i])) return 0;
        }
    }
    if (gate->flags >= 2) return 0;
    *outCount = 1;
    *outArray = id;
    return 1;
}
