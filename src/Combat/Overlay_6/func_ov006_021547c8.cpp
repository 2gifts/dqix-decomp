#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154614 func_ov006_02155d94
#define func_ov006_02156e54 func_ov006_0215845c
#else
#define R(j,u) (u)
#endif
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
    char unk_0[R(0x6f0,0x774)];
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
#if !defined(jpn)
    char names_[3][0x80];
#endif
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

extern "C" void func_ov023_021dc354(ItemInfoWindow* window);
extern "C" void func_ov006_02156e54(AlchemyPot* self);
void SetField0x3b0Value(GameState* gameState, int camera);
extern "C" void _Z17ResetTask020dbebcPv(void* effect);
extern "C" void func_ov006_02154614(AlchemyPot* self);

// USA: func_ov006_021547c8
extern "C" ARM void func_ov006_021547c8(AlchemyPot* self) {
    func_ov023_021dc354(&self->window_);
    func_ov006_02156e54(self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0) {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->backgroundTask_ >= 0) {
        loader->RemoveTask(self->backgroundTask_);
        self->backgroundTask_ = -1;
    }
    if (self->effectAllocator_.GetSignedAllocator() != 0)
        self->effectAllocator_.Destroy();
    SafeAllocator* allocators[7] = {0};
    allocators[0] = self->itemAllocator_;
    allocators[1] = self->nextItemAllocator_;
    allocators[2] = self->itemAllocator_;
    allocators[3] = self->nextItemAllocator_;
    allocators[4] = self->windowAllocator_;
    allocators[5] = self->windowSpriteAllocator_;
    for (unsigned char i = 0; allocators[i] != 0; i++) {
        if (allocators[i]->GetSignedAllocator() != 0)
            allocators[i]->Destroy();
    }
    for (unsigned char j = 0; j < 6; j++) {
        if (self->allocators_[j].GetSignedAllocator() != 0)
            self->allocators_[j].Destroy();
    }
    for (unsigned char k = 0; k < 4; k++) {
        if (self->ingredientAllocators_[k].GetSignedAllocator() != 0)
            self->ingredientAllocators_[k].Destroy();
    }
    if (self->previousCamera_ != 0) {
        GameState* gameState = GameState::GetInstance();
        SetField0x3b0Value(gameState, (int)self->previousCamera_);
        self->previousCamera_ = 0;
    }
    if (!(self->flags_ & 8)) {
        self->protagonist_.Destroy();
        self->pot_.Destroy();
        self->lid_.Destroy();
        self->effect_.Destroy();
        self->steam_.Destroy();
    }
    _Z17ResetTask020dbebcPv(&self->subEffect_);
    func_ov006_02154614(self);
}
