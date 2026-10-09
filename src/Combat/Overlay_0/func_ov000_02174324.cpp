#include <globaldefs.h>

struct Combatant02174324 {
    char pad[0x25];
    unsigned char field_0x25;
    char pad2[0x28 - 0x26];
    unsigned int statusFlags;
    char pad3[0x2f - 0x2c];
    unsigned char field_0x2f;
};

struct Slot02174324 {
    char pad[0x14];
    int x;
    int y;
    char pad2[0x22 - 0x1c];
    unsigned char palette;
    char pad3[0x26 - 0x23];
    unsigned char active;
    char pad4[0x28 - 0x27];
};

struct Battle02174324 {
    char pad[0x11c];
    char queue[0x170 - 0x11c];
    struct Slot02174324* slots;
};

extern "C" struct Combatant02174324* func_ov000_02161318(struct Battle02174324* obj, int id);
extern "C" int func_0205ac40(void* queue, struct Slot02174324* slot, int count);

extern unsigned int data_ov000_02183460[];
extern unsigned char data_ov000_021833b0[];

// USA: func_ov000_02174324
extern "C" ARM int func_ov000_02174324(struct Battle02174324* battle, int id, int x, int y) {
    struct Combatant02174324* c = func_ov000_02161318(battle, id);
    if (c == NULL) return 0;

    int i = 0;
    int found = 0;
    unsigned int flags = c->statusFlags;
    unsigned char slotIdx;
    unsigned char palette;

    while (data_ov000_02183460[i] != 0) {
        unsigned int bit = data_ov000_02183460[i];
        if (c->statusFlags & bit) {
            if (bit == 2 && c->field_0x2f != 2 && i == 4) {
                i++;
                continue;
            }
            slotIdx = data_ov000_021833b0[i] + 0x15;
            palette = id + 0x5c;
            found = 1;
            break;
        }
        i++;
    }

    if ((flags & 0x80000) && i >= 4) {
        if (c->field_0x25 != 9) {
            palette = id + 0x5c;
            found = 1;
            slotIdx = 0x1f;
        }
    }

    if (!found) return 0;

    struct Slot02174324* slot = &battle->slots[slotIdx];
    slot->x = x << 12;
    slot->y = y << 12;
    slot->palette = palette;
    slot->active = 1;
    func_0205ac40(battle->queue, slot, 1);
    return 1;
}
