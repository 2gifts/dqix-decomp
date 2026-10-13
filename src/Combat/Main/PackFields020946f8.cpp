#include <globaldefs.h>

struct PackFields020946f8Struct {
    unsigned int attributes01;
    unsigned short attributes2;
    short affineParameter;
};

enum {
    SpriteBitmapMode = 3,
    SpriteAffineEffect = 0x100,
    SpriteDoubleSizeAffineEffect = 0x300
};

// USA: func_020946f8
// KEEP-NAME
// JPN: func_02094fe0
ARM void PackFields020946f8(PackFields020946f8Struct* sprite, int x, int y, int priority,
                            int mode, int mosaic, int effect, int shape, int colorMode,
                            int characterIndex, int paletteOrAlpha, int affineIndex) {
    if (effect == SpriteAffineEffect || effect == SpriteDoubleSizeAffineEffect) {
        if (mode == SpriteBitmapMode) {
            sprite->attributes01 = (y & 0xff) | (affineIndex << 25) | (mode << 10) | (mosaic << 12) | shape | ((x & 0x1ff) << 16) | effect;
        } else {
            sprite->attributes01 = (y & 0xff) | ((affineIndex << 25) | (colorMode << 13)) | (mode << 10) | (mosaic << 12) | shape | ((x & 0x1ff) << 16) | effect;
        }
    } else {
        if (mode == SpriteBitmapMode) {
            sprite->attributes01 = (y & 0xff) | (mode << 10) | (mosaic << 12) | shape | ((x & 0x1ff) << 16) | effect;
        } else {
            sprite->attributes01 = (y & 0xff) | (colorMode << 13) | (mode << 10) | (mosaic << 12) | shape | ((x & 0x1ff) << 16) | effect;
        }
    }
    sprite->attributes2 = characterIndex | (priority << 10) | (paletteOrAlpha << 12);
}
