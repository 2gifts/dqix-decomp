#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct020dbd9c {
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct ItemInfoWindow {
    char unk_0[0x774];
    unsigned short flags_;
    char unk_776[0x7];
    signed char windowSprites_;
    char unk_77e[0x1d];
    unsigned char externalBuffer_ : 1;
    unsigned char inMenu_ : 1;
};

struct IngredientSprite {
    char unk_0[0x7c];
};

struct Recipe {
    short id_;
};

struct RecipeRecord {
    short id_;
    unsigned short known_ : 1;
    unsigned short made_ : 1;
    unsigned short unk_2_2 : 14;
};

struct AlchemyPot {
    char names_[3][0x80];
    SafeAllocator* allocators_;
    SafeAllocator* itemAllocator_;
    SafeAllocator* nextItemAllocator_;
    SafeAllocator effectAllocator_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* amounts_;
    void* itemNames_;
    void* texts_;
    Recipe* recipe_;
    Recipe* nextRecipe_;
    int unk_1bc;
    RecipeRecord* record_;
    unsigned char* unk_1c4;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D protagonist_;
    Object3D pot_;
    Object3D lid_;
    Object3D effect_;
    Object3D steam_;
    char unk_594[0x38];
    char camera_[0x2c8];
    IngredientSprite ingredients_[4];
    SafeAllocator ingredientAllocators_[4];
    int task_;
    int backgroundTask_;
    unsigned char state_;
    unsigned char loadStep_;
    unsigned char itemStep_;
    unsigned char backgroundStep_;
    unsigned char unk_ae0;
    unsigned char animationStep_;
    unsigned short flags_;
    ItemInfoWindow window_;
    SafeAllocator* windowAllocator_;
    SafeAllocator* windowSpriteAllocator_;
    char partNames_[0x18];
    Struct020dbd9c subEffect_;
    short itemId_;
    signed char itemSprites_;
    unsigned char numIngredients_;
    unsigned char effectMode_;
    unsigned char resetBlend_;
};

extern "C" void func_ov006_02155508(AlchemyPot* self);
extern "C" void func_ov023_021dd4cc(ItemInfoWindow* window, signed char sprites);

// USA: func_ov006_02155630
extern "C" ARM void func_ov006_02155630(AlchemyPot* self, Recipe* recipe, RecipeRecord* record, unsigned char* amounts) {
    if (recipe == 0 || record == 0) {
        func_ov006_02155508(self);
        return;
    }
    if (record != 0 && !record->made_) {
        func_ov006_02155508(self);
        return;
    }
    func_ov023_021dd4cc(&self->window_, 1);
    self->itemId_ = 0;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0) {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    self->task_ = -1;
    self->itemStep_ = 0;
    self->nextRecipe_ = recipe;
    self->record_ = record;
    self->amounts_ = amounts;
    self->flags_ = (self->flags_ | 2) & ~1;
    if (self->backgroundTask_ >= 0) {
        loader->RemoveTask(self->backgroundTask_);
        self->backgroundTask_ = -1;
    }
    self->backgroundTask_ = -1;
    self->backgroundStep_ = 0;
}
