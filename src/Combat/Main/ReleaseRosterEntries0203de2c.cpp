#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0203f430(void* p);
struct Obj02037640;

struct Node0203de2c {
    char pad0[0x14];
    void* field_14;
    void* field_18;
};
struct Roster0203de2c {
    char pad0[0xc];
    struct Node0203de2c* nodes[0x20];
};

// USA: func_0203de2c
ARM void ReleaseRosterEntries0203de2c(struct Roster0203de2c* roster) {
    int i;
    GameState::GetInstance();
    for (i = 0; i < 0x20; i++) {
        struct Node0203de2c* n = roster->nodes[i];
        if (n == NULL) continue;
        if (n->field_14 != NULL) {
            func_0203f430(n->field_14);
        } else if (n->field_18 != NULL) {
            ((Object3D*)((struct Obj02037640*)n->field_18))->StageTextureData();
        }
    }
}
