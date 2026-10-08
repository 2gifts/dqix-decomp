#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Unknown_02075cdc {
    char unk_0[0x70];
};

extern "C" void func_02076080(Unknown_02075cdc* graphics, SafeAllocator* allocator, void* file, unsigned int size);

struct IngredientSprite {
    Unknown_02075cdc graphics_;
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

struct AlchemyPot {
    char unk_0[0x894];
    IngredientSprite ingredients_[4];
    SafeAllocator ingredientAllocators_[4];
};

// USA: func_ov006_02156fdc
extern "C" ARM void func_ov006_02156fdc(AlchemyPot* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    IngredientSprite* ingredient = self->ingredients_;
    for (unsigned char i = 0; i < 4; i++) {
        if (ingredient->loading_) {
            if (loader->GetTaskStatus(ingredient->task_)) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(ingredient->task_, &data, &size);
                if (data != 0) {
                    self->ingredientAllocators_[i].Reset();
                    func_02076080(&ingredient->graphics_, &self->ingredientAllocators_[i], data, size);
                }
                loader->RemoveTask(ingredient->task_);
                ingredient->task_ = -1;
                ingredient->loading_ = 0;
            }
            ingredient->x_ = 0x6f;
            ingredient->y_ = -0x1a;
        }
        ingredient++;
    }
}
