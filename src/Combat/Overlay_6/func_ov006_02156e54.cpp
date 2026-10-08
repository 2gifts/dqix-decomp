#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_0203bd08();
extern "C" unsigned int func_0203be40(void* vram);

struct Unknown_02075cdc {
    char unk_0[0x14];
    unsigned int unk_14;
    char unk_18[0x38 - 0x18];
    unsigned int unk_38;
    unsigned int unk_3c;
    int unk_40;
    int unk_44;
    char unk_48[4];
    int unk_4c;
    char unk_50[0x5e - 0x50];
    unsigned char unk_5e;
    char unk_5f[0x70 - 0x5f];
};

struct IngredientSprite {
    Unknown_02075cdc graphics_;
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

extern "C" void func_ov006_0215479c(IngredientSprite* self);

struct AlchemyPot {
    char unk_0[0x894];
    IngredientSprite ingredients_[4];
};

// USA: func_ov006_02156e54
extern "C" ARM void func_ov006_02156e54(AlchemyPot* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    IngredientSprite* ingredient = self->ingredients_;
    for (unsigned char i = 0; i < 4; i++) {
        if (ingredient->task_ > 0)
            loader->RemoveTask(ingredient->task_);
        ingredient->task_ = -1;
        func_ov006_0215479c(ingredient);
        ingredient->graphics_.unk_5e = 0;
        ingredient->graphics_.unk_14 = func_0203be40(func_0203bd08()) + (i << 6) + 0x100;
        ingredient->graphics_.unk_38 = i * 0x120 + 0x240;
        ingredient->graphics_.unk_3c = (i + 10) & 0xf;
        ingredient->graphics_.unk_40 = 0;
        ingredient->x_ = (i << 5) + 0x20;
        ingredient->y_ = 0x80;
        ingredient++;
    }
}
