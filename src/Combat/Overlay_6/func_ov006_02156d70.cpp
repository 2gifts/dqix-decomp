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

struct InitStruct02078484Struct;
struct Obj020dbfa4;

struct Vec3_02156d70 {
    int x;
    int y;
    int z;
};

struct EffectParams {
    char name_[0x11];
    unsigned char unk_11;
    short unk_12;
    char unk_14[0x2c - 0x14];
    Vec3_02156d70 position_;
    char unk_38[0x44 - 0x38];
    Vec3_02156d70 scale_;
};

extern "C" void func_020dbdc0(Struct020dbd9c* effect);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(InitStruct02078484Struct* params);
extern "C" void _Z26ProcessPendingNode020dbfa4P11Obj020dbfa4i(Obj020dbfa4* effect, int params);

extern char data_ov006_02160089[];
extern char data_ov006_02160092[];

// USA: func_ov006_02156d70
extern "C" ARM void func_ov006_02156d70(AlchemyPot* self) {
    func_020dbdc0(&self->subEffect_);
    if (self->subEffect_.unk_14 == 0 && self->effectMode_ != 0) {
        EffectParams params;
        _Z18InitStruct02078484P24InitStruct02078484Struct((InitStruct02078484Struct*)&params);
        params.unk_11 &= ~4;
        params.unk_12 = 0;
        if (self->effectMode_ == 1 || self->effectMode_ == 2) {
            strcpy(params.name_, data_ov006_02160089);
            self->effectMode_ = 2;
        } else {
            strcpy(params.name_, data_ov006_02160092);
            self->effectMode_ = 0;
        }
        params.scale_.x = 0x10a;
        params.scale_.y = 0x10a;
        params.scale_.z = 0x10a;
        params.position_.x = -0x41;
        params.position_.y = -0xaac;
        params.position_.z = 0x4526;
        _Z26ProcessPendingNode020dbfa4P11Obj020dbfa4i((Obj020dbfa4*)&self->subEffect_, (int)&params);
    }
}
