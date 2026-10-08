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

void* GetWord0x0(int* gameState);
void SetBitsInField4(unsigned int* resources, unsigned int bits);
void ClearBitsInField4(unsigned int* resources, unsigned int bits);
extern "C" void _Z26SetForwardAndStore0205ebc0Pvii(void* sound, int a, int b);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(void* sound, int a, int b);
extern "C" void _Z25ForwardField0xc0_0205ebecPv(void* sound);

extern char data_02108760[];
extern char data_ov006_02160080[];
extern char data_ov006_02160087[];
extern char data_ov006_02160089[];
extern char data_ov006_0216008b[];
extern char data_ov006_02160092[];
extern char data_ov006_02160094[];
extern char data_ov006_02160096[];
extern char data_ov006_0216009e[];
extern char data_ov006_021600a0[];
extern char data_ov006_021600a9[];

// USA: func_ov006_02155068
extern "C" ARM void func_ov006_02155068(AlchemyPot* self) {
    unsigned int* resources = (unsigned int*)GetWord0x0((int*)GameState::GetInstance());
    unsigned short flags = self->flags_;
    if (flags & 0x2000) {
        SetBitsInField4(resources, 0x2000);
        self->steam_.MaybeSetRegularAnimation(data_ov006_02160080, 9);
        self->steam_.EnableFlag(0x1000);
        return;
    }
    if (flags & 0x80) {
        if (self->animationStep_ == 0) {
            _Z26SetForwardAndStore0205ebc0Pvii(data_02108760, 0x7a, 0x7a);
            _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(data_02108760, 0, 0);
            self->pot_.MaybeSetRegularAnimation(data_ov006_02160080, 1);
            self->effect_.MaybeSetRegularAnimation(data_ov006_02160087, 1);
            self->steam_.MaybeSetRegularAnimation(data_ov006_02160080, 9);
            self->steam_.DisableFlag(0x1000);
        } else if (self->animationStep_ >= 1 && self->pot_.HasAnimationStopped()) {
            self->animationStep_ = 0;
            self->flags_ &= ~0x80;
            self->effect_.MaybeSetRegularAnimation(data_ov006_02160089, 1);
            self->pot_.MaybeSetRegularAnimation(data_ov006_0216008b, 0);
            self->steam_.StopCurrentAnimation();
            return;
        }
        self->animationStep_++;
        return;
    }
    if (flags & 0x100) {
        if (!self->pot_.HasAnimationReachedEnd())
            return;
        if (self->animationStep_ == 0) {
            self->effect_.MaybeSetRegularAnimation(data_ov006_02160092, 0);
        } else if (self->animationStep_ == 1) {
            self->effect_.MaybeSetRegularAnimation(data_ov006_02160094, 1);
        } else if (self->animationStep_ == 2) {
            self->animationStep_ = 0;
            self->pot_.StopCurrentAnimation();
            self->pot_.MaybeSetRegularAnimation(data_ov006_02160096, 1);
            self->effect_.MaybeSetRegularAnimation(data_ov006_0216009e, 0);
            self->steam_.MaybeSetRegularAnimation(data_ov006_02160096, 1);
            self->flags_ &= ~0x100;
            return;
        }
        self->animationStep_++;
        return;
    }
    if (flags & 0x200) {
        self->flags_ = flags | 0x800;
        if (!self->pot_.HasAnimationStopped()) {
            self->animationStep_++;
            return;
        }
        ClearBitsInField4(resources, 0x2000);
        _Z25ForwardField0xc0_0205ebecPv(data_02108760);
        self->animationStep_ = 0;
        self->pot_.MaybeSetRegularAnimation(data_ov006_021600a0, 1);
        self->effect_.StopCurrentAnimation();
        self->flags_ &= ~0x200;
        return;
    }
    if (flags & 0x400) {
        if (self->pot_.HasAnimationStopped()) {
            self->animationStep_ = 0;
            self->pot_.MaybeSetRegularAnimation(data_ov006_021600a9, 0);
            self->effect_.StopCurrentAnimation();
            self->flags_ &= ~0x400;
            return;
        }
        self->pot_.MaybeSetRegularAnimation(data_ov006_021600a0, 1);
        return;
    }
    self->animationStep_ = 0;
    self->pot_.MaybeSetRegularAnimation(data_ov006_021600a9, 0);
    self->effect_.StopCurrentAnimation();
}
