// JPN: func_ov017_021c4bb8
#if defined(jpn)
enum { RegionOffset3734 = 0x3524, RegionOffset101 = 0xfd };
#else
enum { RegionOffset3734 = 0x3734, RegionOffset101 = 0x101 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Evt021c46ec {
    unsigned char pad0[4];
    unsigned short id;
    unsigned char pad6[0x10 - 0x6];
    int field10;
};

struct Mode021c46ec {
    unsigned char pad0[3];
    unsigned char active;
    unsigned char pad4[0x12 - 0x4];
    unsigned char field12;
    unsigned char pad13[RegionOffset101 - 0x13];
    unsigned char field101;
};

struct Ov021c46ec {
    unsigned char pad0[RegionOffset3734];
    struct Mode021c46ec* mode;
};

struct SearchStruct0202c1a4;
extern "C" int func_0202c540(struct SearchStruct0202c1a4* search);
extern "C" int func_0202c508(struct SearchStruct0202c1a4* search);
extern "C" void func_020103c8(GameState* battleStruct, int arg);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
signed char GetSignedByte0x2d0(void* obj);
extern "C" void func_ov017_0219dac4(struct Ov021c46ec* ov, int idx, int id);
extern "C" void func_ov017_021c4fa0(int idx, int id);

// USA: func_ov017_021c46ec
extern "C" ARM void func_ov017_021c46ec(int idx, struct Evt021c46ec* evt, GameState* battleStruct, struct Ov021c46ec* ov, struct SearchStruct0202c1a4* search) {
    unsigned short id = evt->id;
    if (func_0202c540(search) != 0 && idx == 0) {
        func_020103c8(battleStruct, evt->field10);
    }

    int active = 0;
    int i;
    struct Mode021c46ec* mode = ov->mode;
    if (mode->active != 0) {
        active = 1;
    }

    GameObject* objs[4];
    GameObject* leader = battleStruct->GetPartyMemberByIndex(idx);
    if (!active || mode->field101 == 0) {
        int count = 0;
        objs[count++] = leader;
        for (i = 0; i < 4; i++) {
            GameObject* c = GetCombatantWithFlag0x1000(battleStruct, i);
            if (c != NULL && idx == GetSignedByte0x2d0(c)) {
                objs[count++] = c;
            }
        }

        if (!active || mode->field101 != 0 || mode->field12 == 0 || idx != 0) {
            for (i = 0; i < count; i++) {
                GameObject* c = objs[i];
                if (c != NULL) {
                    if (id != c->obj3D_.GetField06() || id == 0x170c) {
                        c->obj3D_.MakeHidden();
                    }
                }
            }
        }
    }

    func_ov017_0219dac4(ov, idx, id);
    if (func_0202c508(search) != 0) {
        func_ov017_021c4fa0(idx, id);
    }
}
