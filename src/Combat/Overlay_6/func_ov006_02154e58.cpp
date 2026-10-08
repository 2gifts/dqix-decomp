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

#include "System/Graphics.h"

struct Data0210a010 {
    char unk_0[0xa0];
    int viewportArg;
};
extern Data0210a010 data_0210a010;

extern "C" void _Z28InitCombatController020a2010Pv(void* camera);
void SetFields0x10To0x18(unsigned char* camera, int x, int y, int z);
extern "C" void func_0202e5d8(void* camera, int x, int y, int z);
extern "C" void func_0202e0a4(void* camera);
void SetField0x238False(void* camera);
extern "C" void _Z23InitCombatEntry021542f4Pv(void* camera);

// USA: func_ov006_02154e58
extern "C" ARM void func_ov006_02154e58(AlchemyPot* self) {
    if (!(self->flags_ & 0x1000))
        return;
    if ((self->flags_ & (0x40 | 8)) &&
        ((self->flags_ & 8) || (self->window_.flags_ & 4))) {
        if (self->window_.windowSprites_ != 2)
            return;
        if (!self->window_.inMenu_)
            return;
    }
    if (self->window_.windowSprites_ == 2 && self->window_.inMenu_ && (self->window_.flags_ & 4)) {
        data_0210a010.viewportArg = 0x46501313;
        void* camera = self->camera_;
        BG0CNT = BG0CNT & ~3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        if (camera != 0) {
            _Z28InitCombatController020a2010Pv(camera);
            SetFields0x10To0x18((unsigned char*)self->camera_, 0, -0x1e8f, 0);
            func_0202e5d8(self->camera_, 0, 0x2bae, 0x9199);
            func_0202e0a4(self->camera_);
            SetField0x238False(self->camera_);
        }
        self->resetBlend_ = 0;
    } else {
        _Z23InitCombatEntry021542f4Pv(self->camera_);
    }
    self->protagonist_.Draw(true);
    self->pot_.Draw(true);
    self->lid_.Draw(true);
    self->effect_.Draw(true);
}
