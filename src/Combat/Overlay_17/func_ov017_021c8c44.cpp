#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry0207d9bc;
struct Obj02053f7c;

struct Evt021c8c44 {
    unsigned char tag;
    unsigned char pad1[3];
    int target;
    unsigned short key;
    unsigned char flag;
};

struct Combatant021c8c44 {
    Object3D obj3D;
    unsigned char padAc[0x15c - sizeof(Object3D)];
    int field_15c;
    unsigned char pad160[0x1b2 - 0x160];
    unsigned short field_1b2;
};

struct IndexList021c8c44 {
    int idx[4];
};

extern const IndexList021c8c44 data_ov017_021d6d18;

GameObject* GetCombatantWithFlag0x1000(GameState* gameState, int combatantId);
int GetSignedByte0x2d0(void* obj);
extern "C" void func_0202738c(void* a, int b, int c, int d);
extern "C" void func_02027304(void* obj, int id);
extern "C" void func_ov017_021b86f8(void* obj, int key, int a, int flag);
extern "C" int func_0202c508(void* search);
Entry0207d9bc* GetData02108ea8(void);
extern "C" void _Z23ResetEntryByKey0207da7cP13Entry0207d9bct(Entry0207d9bc* arr, unsigned short key);
extern "C" void _Z41EnqueueEventForFlaggedCombatants_021a33e0Pvi(void* ctx, int key);
extern "C" void _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(Obj02053f7c* obj, unsigned short a, int b);
#define _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(int a, int b, int c, int d, int e);
extern "C" void _Z30ClearMatchingHalfword_02197324Pht(unsigned char* obj, unsigned short key);

// USA: func_ov017_021c8c44
extern "C" ARM void func_ov017_021c8c44(int id, Evt021c8c44* evt, GameState* gs, unsigned char* ctx, void* search) {
    int match;
    int key = evt->key;
    int flag = evt->flag != 0;
    int target = evt->target;
    GameState* inst = GameState::GetInstance();
    void* timers = func_ov017_0218b5b0()->unknown_ptr_36d0;
    int i;

    for (i = 0; i < 4; i++) {
        match = 0;
        if (i == id) {
            match = 1;
        } else {
            GameObject* c = GetCombatantWithFlag0x1000(inst, i);
            if (c != NULL && id == GetSignedByte0x2d0(c)) {
                match = 1;
            }
        }
        if (match) {
            func_0202738c(timers, 0, 1, i);
            func_02027304(timers, i);
        }
    }

    func_ov017_021b86f8(*(void**)(ctx + 0x3718), key, 1, flag);

    if (func_0202c508(search)) {
        _Z23ResetEntryByKey0207da7cP13Entry0207d9bct(GetData02108ea8(), key);
        if (target != -1) {
            IndexList021c8c44 list = data_ov017_021d6d18;
            int n = 0;
            for (i = 0; i < 4; i++) {
                Combatant021c8c44* m = (Combatant021c8c44*)gs->GetPartyMemberByIndex(i);
                if (m != NULL) {
                    if (target == m->obj3D.GetField06() || target == m->field_15c) {
                        list.idx[n] = i;
                        n++;
                    }
                }
            }
            if (n == 1 && list.idx[0] != 0) {
                _Z41EnqueueEventForFlaggedCombatants_021a33e0Pvi(ctx, target);
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        Combatant021c8c44* c = (Combatant021c8c44*)GetCombatantWithFlag0x100(gs, j);
        if (c != NULL) {
            if (id == c->obj3D.unknown_4_) {
                _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi((Obj02053f7c*)c, 0, 1);
            } else if (c->obj3D.unknown_0_ & 0x1000) {
                Combatant021c8c44* leader = (Combatant021c8c44*)GetCombatantWithFlag0x100(gs, 0);
                if (leader != NULL) {
                    _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi((Obj02053f7c*)c, leader->field_1b2, 1);
                }
            }
        }
    }

    _Z26CallHelperWithBuf_021907dciiiii((int)ctx, id, 1, 1, 1);
    _Z30ClearMatchingHalfword_02197324Pht(ctx, key);
}
