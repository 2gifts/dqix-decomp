#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"

struct StructDE234_020de234 {
    void* model_;
    int unk_4;
    int unk_8;
    int unk_c;
    unsigned int unk_10_0 : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
    int unk_14;
    short unk_18;
    char unk_1a[0x20 - 0x1a];
};

extern "C" unsigned short _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(StructDE234_020de234* p, int preferMid);

extern const char data_ov006_021601e5[];

struct PotIngredient {
    StructDE234_020de234 entry_;
    char model_[0x20];
    char unk_40[0x30];
    short item_;
};

struct IngredientSprite {
    char graphics_[0x70];
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

struct AlchemyPot {
    char unk_0[0x894];
    IngredientSprite ingredients_[4];
    char unk_a84[0x12bb - 0xa84];
    unsigned char numIngredients_;
};

extern "C" void func_ov006_02156e54(AlchemyPot* self);

// USA: func_ov006_02156f04
extern "C" ARM void func_ov006_02156f04(AlchemyPot* self, PotIngredient* ingredients) {
    func_ov006_02156e54(self);
    IngredientSprite* ingredient = self->ingredients_;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    self->numIngredients_ = 0;
    for (unsigned char i = 0; i < 4; i++) {
        short item = ingredients->item_;
        ingredient->item_ = item;
        if (item > 0) {
            ingredient->loading_ = 1;
            int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(&ingredients->entry_, 0);
            char path[0x40] = {0};
            sprintf(path, data_ov006_021601e5, ingredients->entry_.letter_, number);
            ingredient->task_ = loader->QueueLoadFile(path, 0);
            if (i != 0)
                self->numIngredients_++;
        }
        ingredients++;
        ingredient++;
    }
}
