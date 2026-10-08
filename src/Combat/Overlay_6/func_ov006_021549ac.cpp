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

struct Obj0207fc6c;

typedef void (AlchemyPot::*PMF021549ac)();
struct RawTable021549ac { PMF021549ac e[3]; };
extern struct RawTable021549ac data_ov006_0215ff94;
extern PMF021549ac data_020e6d5c;

extern "C" void func_ov006_02156bd8(AlchemyPot* self);
void CallFunc0204c87cOverEntries0207fc6c(Obj0207fc6c* menu, int ticks);
extern "C" void func_ov006_02156fdc(AlchemyPot* self);
extern "C" void func_ov006_02156d70(AlchemyPot* self);
extern "C" void func_ov006_02155068(AlchemyPot* self);

// USA: func_ov006_021549ac
extern "C" ARM void func_ov006_021549ac(AlchemyPot* self, int ticks) {
    func_ov006_02156bd8(self);
    Obj0207fc6c* menu = (Obj0207fc6c*)self->menu_;
    if (menu != 0)
        CallFunc0204c87cOverEntries0207fc6c(menu, ticks);
    func_ov006_02156fdc(self);
    func_ov006_02156d70(self);
    struct RawTable021549ac updates;
    updates = data_ov006_0215ff94;
    updates.e[2] = data_020e6d5c;
    if (updates.e[self->state_] != 0) {
        (self->*updates.e[self->state_])();
        func_ov006_02155068(self);
    }
}
