#include <globaldefs.h>

struct Out0215fb54 { int x0; int x1; };
extern "C" int _Z23FindRecordByKey0215fb54isP11Out0215fb54(int unused, short key, Out0215fb54* out);
void* GetActiveCombatWork(void);
extern "C" void* _Z26FindNodeByShortKey02162d88Pvs(void* obj, int key);

struct Gate_021f5478 { char pad0; unsigned char flags : 4; unsigned char pad1 : 4; };
struct Obj_021f5478 { int field0; };
struct Action_021f5478 {
    int field0;
    unsigned int key : 12;
    unsigned int pad4 : 20;
    char pad8[0x10];
    unsigned int pad18 : 5;
    unsigned int kind : 7;
    unsigned int pad18b : 20;
};
extern const Out0215fb54 data_ov024_021fea1c[];

// JPN: func_ov024_021f5c44
// USA: func_ov024_021f5478
extern "C" ARM int func_ov024_021f5478(struct Obj_021f5478* obj, int id, struct Action_021f5478* action, int* outCount, short* outArray) {
    void* work;
    struct Gate_021f5478* gate = (struct Gate_021f5478*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    work = GetActiveCombatWork();
    if (!work) return 0;
    if (action->kind == 0xc) {
        Out0215fb54 out;
        out.x1 = data_ov024_021fea1c[37].x1;
        out.x0 = data_ov024_021fea1c[37].x0;
        int count = _Z23FindRecordByKey0215fb54isP11Out0215fb54(obj->field0, action->key, &out);
        for (int i = 0; i < count; i++) {
            if (!_Z26FindNodeByShortKey02162d88Pvs(work, (&out.x0)[i])) return 0;
        }
    }
    if (gate->flags >= 4) return 0;
    *outCount = 1;
    *outArray = id;
    return 1;
}
