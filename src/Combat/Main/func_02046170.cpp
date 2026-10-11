#include <globaldefs.h>

extern "C" bool _Z20IsHighByteFF02044494PvS_(void* obj, void* src);
extern "C" int _Z22LookupKeyValue020425e4iii(int a, int b, int tableIdx);

extern int data_020e7a94[];

struct Glyph02046170 {
    int pad0;
    signed char width;
};

struct Slot02046170 {
    char pad0[0x17];
    unsigned char unk17;
    struct Glyph02046170* glyph;
};

struct Container02046170 {
    char pad0[0x9b8];
    struct Slot02046170 slots[0x80];
};

// USA: func_02046170
extern "C" ARM int func_02046170(struct Container02046170* obj, unsigned short* cmds, int count,
                                 int tableIdx) {
    if (cmds == 0) return 0;
    if (count < 0) return 0;

    int mask = data_020e7a94[tableIdx] & 0xff;
    int width = 0;
    int maxWidth = 0;
    int state = 0xff;

    for (int i = 0; i < count; i++) {
        unsigned short cmd = cmds[i];
        if (cmd == 0xff01) break;
        if (cmd == 0xff18) {
            if (maxWidth < width) maxWidth = width;
            width = 0;
            state = 0xff;
        } else if (cmd == 0xff19) {
            state = 0xff;
            width += mask + 1;
        } else if (_Z20IsHighByteFF02044494PvS_(obj, &cmd)) {
            state = 0xff;
        } else {
            struct Slot02046170* slot = &obj->slots[cmd];
            int v = slot->unk17;
            width += _Z22LookupKeyValue020425e4iii(state, v, tableIdx);
            state = v;
            int w = mask;
            if (slot->glyph != 0) w = slot->glyph->width;
            width += w + 1;
        }
    }

    if (width < maxWidth) width = maxWidth;
    return width;
}
