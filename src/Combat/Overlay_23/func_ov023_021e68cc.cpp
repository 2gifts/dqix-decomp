#include <globaldefs.h>

struct Struct_0205d81c;

struct Element_021e68cc {
    char pad0[0xac];
    short x;
    short y;
};

struct Sprite_021e68cc {
    char pad0[0x14];
    int posX;
    int posY;
    char pad1c[0x22 - 0x1c];
    unsigned char tile;
    char pad23[0x25 - 0x23];
    unsigned char palette;
    char pad26[0x28 - 0x26];
};

#if defined(jpn)
struct ProfileEditor_021e68cc {
    char pad0[0x90];
#else
struct ProfileEditor_021e68cc {
    char pad0[0xac];
#endif

#if defined(jpn)
    char list_[0x1334 - 0x90];
#else
    char list_[0x135c - 0xac];
#endif

    void* renderer_;
    char pad1360[0x1364 - 0x1360];
    Sprite_021e68cc* sprites_;
#if defined(jpn)

#else
    char pad1368[0x1370 - 0x1368];
#endif

    unsigned char mode_;
    unsigned char page_;
#if defined(jpn)
    char pad1372[0x1370 - 0x1342];
#else
    char pad1372[0x13a8 - 0x1372];
#endif

    signed char selected_;
    char pad13a9[0x13ab - 0x13a9];
    unsigned char enabledMask_;
};

extern "C" Element_021e68cc* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(void* renderer, void* sprite);

// JPN: func_ov023_021e6e3c
// USA: func_ov023_021e68cc
extern "C" ARM void func_ov023_021e68cc(ProfileEditor_021e68cc* self) {
#if defined(jpn)
 enum {regionalOffset0=0x11};
#else
 enum {regionalOffset0=0x13};
#endif
    unsigned char page = self->page_;
    if (page != 7 && page != 8 && page != 9)
        return;
    if (self->mode_ != 4)
        return;

    int posX;
    signed char slot = 0;
    unsigned char tile = regionalOffset0;
    for (int row = 0; row < 3; row++) {
        Element_021e68cc* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((Struct_0205d81c*)self->list_, (unsigned char)(row + 7));
        posX = ((short)(e->x * 8) + 10) << 12;
        short top = e->y * 8;
        for (int col = 0; col < 2; col++) {
            int offset = 0x10;
            int index = 0xd;
            int dir = 1;
            if (col == 1) {
                offset = 0x1c;
                index = 0xe;
                dir = -1;
            }
            Sprite_021e68cc* sprite = &self->sprites_[index];
            int y = top + offset;
            sprite->posX = posX;
            sprite->posY = y << 12;
            sprite->tile = tile++;
            sprite->palette = 7;
            if (slot == self->selected_) {
                sprite->posX = posX;
                sprite->posY = (y - dir) << 12;
            }
            if (!(self->enabledMask_ & (1 << slot)))
                sprite->palette = 0xd;
            func_0205ac40(self->renderer_, sprite);
            slot++;
        }
    }
    self->selected_ = -1;
}
