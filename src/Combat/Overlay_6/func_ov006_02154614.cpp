#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

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
    void* recipe_;
    void* nextRecipe_;
    int unk_1bc;
    void* record_;
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

extern "C" void func_ov023_021dc134(ItemInfoWindow* window, short item, signed char mode);
extern "C" void _Z18InitStruct0205a444Pc(char* renderer);
extern "C" void func_ov006_0215479c(IngredientSprite* sprite);
extern "C" void _Z18InitStruct020dbd9cP14Struct020dbd9c(Struct020dbd9c* effect);

// USA: func_ov006_02154614
extern "C" ARM void func_ov006_02154614(AlchemyPot* self) {
#if !defined(jpn)
    memset(self->names_, 0, sizeof(self->names_));
#endif
    self->allocators_ = 0;
    self->itemAllocator_ = 0;
    self->nextItemAllocator_ = 0;
    self->previousCamera_ = 0;
    self->amounts_ = 0;
    self->itemNames_ = 0;
    self->texts_ = 0;
    self->recipe_ = 0;
    self->nextRecipe_ = 0;
    self->unk_1bc = 0;
    self->record_ = 0;
    self->unk_1c4 = 0;
    self->layout_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->menu_ = 0;
    self->item_ = 0;
    self->nextItem_ = 0;
    self->sprites_ = 0;
    self->windowSpriteAllocator_ = 0;
    self->windowAllocator_ = 0;
    func_ov023_021dc134(&self->window_, -1, 1);
    self->window_.flags_ |= 0x10 | 0x200;
    _Z18InitStruct0205a444Pc(self->renderer_);
    self->protagonist_.Initialize();
    self->pot_.Initialize();
    self->lid_.Initialize();
    self->effect_.Initialize();
    self->steam_.Initialize();
    memset(self->unk_594, 0, sizeof(self->unk_594));
    self->effectAllocator_.ResetAllocatorPointer();
    for (unsigned char i = 0; i < 4; i++) {
        func_ov006_0215479c(&self->ingredients_[i]);
        self->ingredientAllocators_[i].ResetAllocatorPointer();
    }
    self->task_ = -1;
    self->backgroundTask_ = -1;
    self->state_ = 0;
    self->loadStep_ = 0;
    self->itemStep_ = 0;
    self->backgroundStep_ = 0;
    self->unk_ae0 = 0;
    self->flags_ = 0;
    self->numIngredients_ = 0;
    self->itemId_ = 0;
    self->itemSprites_ = 0;
    self->effectMode_ = 0;
    _Z18InitStruct020dbd9cP14Struct020dbd9c(&self->subEffect_);
    self->resetBlend_ = 0;
}
