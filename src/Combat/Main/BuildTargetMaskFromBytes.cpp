#include <globaldefs.h>

int AcquireFlagBits020bbe1c(int);

struct BattleTarget948 {
    char pad[0x44];
    int mask;
    int count;
    unsigned char slots[1];
};

// USA: func_020bc948
ARM int BuildTargetMaskFromBytes_020bc948(struct BattleTarget948* obj, int count, unsigned char* arr) {
    int mask = 0;
    int i = 0;
    if (i < count) {
        do {
            obj->slots[i] = arr[i];
            mask |= 1 << arr[i];
            i++;
        } while (i < count);
    }
    if (AcquireFlagBits020bbe1c(mask) == 0) {
        return 0;
    }
    obj->count = count;
    obj->mask = mask;
    return 1;
}
