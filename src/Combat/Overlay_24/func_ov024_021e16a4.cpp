#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Container02070e60;
struct Element_021e16a4 { char pad0[2]; unsigned char kind; };
extern "C" struct Element_021e16a4* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(struct Container02070e60* container, int key);
GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021e16a4 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Range_021e16a4 { char pad[0x24]; struct PackedPair_021e16a4 f24; };

struct Record_021e16a4 {
    unsigned short id;
    char pad2[0x14];
    unsigned char used;
    char pad17;
};
struct Sub_021e16a4 { char pad0[0x24]; unsigned char f24; unsigned char f25; };
struct Ctx_021e16a4 {
    char pad0[0x81b4];
    struct Record_021e16a4 records[3];
    char pad81fc[0x8e18 - 0x81fc];
    struct Sub_021e16a4* sub;
};
struct Out_021e16a4 { char pad0[0x1c]; unsigned short code; };
struct Flag_021e16a4 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e16a4 {
    char pad0[4];
    struct Out_021e16a4* out;
    char pad8[4];
    void* field0xc;
    struct Ctx_021e16a4* ctx;
    char pad14[0x6e - 0x14];
    unsigned char done;
};

// USA: func_ov024_021e16a4
extern "C" ARM void* func_ov024_021e16a4(struct Obj_021e16a4* obj, int unused, int id, struct Range_021e16a4* range) {
    GameObject* c = GetCombatantWithFlag0x400ByID((int)obj->ctx, id);
    if (!c) return 0;
    if (obj->done == 0) {
        int slot = *((unsigned char*)c + 0x17c);
        if (slot >= 3) return 0;
        struct Record_021e16a4* rec = &obj->ctx->records[slot];
        struct Element_021e16a4* e = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(
            (struct Container02070e60*)((char*)obj->ctx->sub + 0x684), rec->id);
        if (rec->used != 0 || (e != 0 && e->kind == 7)) {
            obj->out->code = range->f24.c;
            obj->done = 1;
        } else {
            int chance = 100;
            struct Sub_021e16a4* sub = obj->ctx->sub;
            if (sub != 0 && (sub->f24 != 0 || sub->f25 != 0)) chance = 50;
            if (NextRandomMax((struct Random*)obj->ctx, 100) < chance) {
                obj->out->code = range->f24.a;
                obj->done = 1;
                rec->used = 1;
            } else {
                obj->out->code = range->f24.c;
                obj->done = 1;
            }
        }
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    struct Flag_021e16a4* fl = (struct Flag_021e16a4*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0, fl->flag != 0);
    return entry;
}
