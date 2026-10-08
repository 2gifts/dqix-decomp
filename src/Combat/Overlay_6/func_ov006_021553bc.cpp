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

struct CallIfFlag0x800_021571ccStruct;

const char** CallFunc020e52a0(void* names, int item);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
void SetFields_021dceac(char* window, int index, int name, unsigned char count, unsigned char maximum, unsigned char unk);
extern "C" void func_ov023_021dced4(ItemInfoWindow* window, unsigned char multiplier);
void CallIfFlag_021571cc_021571cc(CallIfFlag0x800_021571ccStruct* self);

// USA: func_ov006_021553bc
extern "C" ARM void func_ov006_021553bc(AlchemyPot* self, short* items, unsigned char* amounts) {
    const char* names[3] = {0};
    for (unsigned char i = 0; i < 3; i++) {
        if (self->itemNames_ != 0) {
            const char** name = CallFunc020e52a0(self->itemNames_, items[i]);
            if (name != 0) {
                func_020e4864(*name, self->names_[i], 1, 0, 0, 0);
                names[i] = self->names_[i];
            }
            SetFields_021dceac((char*)&self->window_, i, (int)names[i], amounts[i], amounts[i], 0);
        }
    }
    func_ov023_021dced4(&self->window_, 1);
    CallIfFlag_021571cc_021571cc((CallIfFlag0x800_021571ccStruct*)self);
}
