#include <globaldefs.h>

void ReleaseFlagBits020bbe64(int);

struct BattleTarget9a8 {
    char pad[0x44];
    int mask;
    int count;
};

// USA: func_020bc9a8
ARM void ClearTargetMask_020bc9a8(struct BattleTarget9a8* obj) {
    if (obj->mask != 0) {
        ReleaseFlagBits020bbe64(obj->mask);
        obj->mask = 0;
        obj->count = 0;
    }
}
