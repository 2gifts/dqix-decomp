#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Obj02088f68;

struct Msgs_021e05fc {
    unsigned int success : 10;
    unsigned int pad : 10;
    unsigned int fail : 10;
    unsigned int rest : 2;
};

struct Rec_021e05fc {
    char pad0[0x24];
    struct Msgs_021e05fc msgs;
};

struct Pending_021e05fc {
    char pad0[0xc];
    int fc;
};

struct Flag_021e05fc { unsigned char pad : 7; unsigned char flag : 1; };

struct Obj_021e05fc {
    char pad0[0xc];
    void* fc;
    void* f10;
};

signed char GetFieldOrFallback02159e60(void* obj, int mode);
extern "C" void func_ov000_021554f4(void* world, int id, int other, struct Rec_021e05fc* rec, int a4, int a5);
void InitObj02088f68(struct Obj02088f68* obj);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" void* func_ov000_0215e958(void* world);
void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int msg);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long bits, int flag);

// USA: func_ov024_021e05fc
extern "C" ARM void* func_ov024_021e05fc(struct Obj_021e05fc* obj, int other, int id, struct Rec_021e05fc* rec) {
    GameObject* c = GetCombatantByID((int)obj->f10, id);
    if (!c) return 0;
    GameState::GetInstance();
    int mine = GetFieldOrFallback02159e60(obj->f10, id);
    int theirs = GetFieldOrFallback02159e60(obj->f10, other);
    int ok = 0;
    if (theirs > mine) {
        if (theirs - mine >= 7) ok = 1;
    }
    struct Pending_021e05fc* pending = *(struct Pending_021e05fc**)((char*)obj->f10 + 0x8e18);
    if (pending) {
        if (pending->fc >= 0) ok = 0;
    }
    int count = *(unsigned char*)((char*)c->currentStats_ + 0x48);
    unsigned short msg = 0;
    unsigned long long bits = 0;
    if (count >= 1 && ok) {
        GameObject* t = GetCombatantByID((int)obj->f10, id);
        if (t) {
            msg = rec->msgs.success;
            func_ov000_021554f4(obj->f10, id, other, rec, 0, 4);
            t->currentStats_->primaryStats.currHP = 0;
            InitObj02088f68((struct Obj02088f68*)t->currentStats_);
            func_ov000_02159eac(obj->f10, &bits, 0x24);
            ((unsigned char*)obj->f10)[0x8e15]++;
        }
    } else {
        msg = rec->msgs.fail;
    }
    void* entry = func_ov000_0215e958(obj->f10);
    if (!entry) return 0;
    AddEntryAndIncrementCount0215a88c(obj->f10, entry, msg);
    struct Flag_021e05fc* fl = (struct Flag_021e05fc*)((char*)obj->fc + 0x1c);
    func_ov000_0215cd44(obj->f10, entry, c, 0, bits, fl->flag != 0);
    return entry;
}
