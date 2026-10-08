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

struct ActiveEntry02046900;
struct List0204af64;
struct Obj0204b5e8;
struct Rec020467f0;
struct SelfTag0204b3a0;

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

extern "C" void func_ov023_021dcd90(ItemInfoWindow* window, unsigned char inMenu);
int CountActiveEntries(ActiveEntry02046900* pac);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* background);
void SetWord0x18ClearByte0x1f(unsigned char* background, int a);
extern "C" void func_0204b5b4(void* background, int a);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* background, int a, int b);
void* FindRecordByIndex(Rec020467f0* pac, int index, void** name, int* size);
extern "C" void _Z21DispatchByTag0204b2e0PvPc(void* background, char* file);
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(SelfTag0204b3a0* background, char* file);

extern char data_ov006_021601b6[];
extern char data_ov006_021601cc[];

// USA: func_ov006_02156bd8
extern "C" ARM void func_ov006_02156bd8(AlchemyPot* self) {
    if (!(self->flags_ & 1))
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->backgroundStep_ == 0) {
        if (self->flags_ & 8)
            self->backgroundTask_ = loader->QueueLoadFile(data_ov006_021601b6, 0);
        else
            self->backgroundTask_ = loader->QueueLoadFile(data_ov006_021601cc, 0);
        func_ov023_021dcd90(&self->window_, 0);
        self->backgroundStep_++;
    } else if (self->backgroundStep_ == 1) {
        if (loader->GetTaskStatus(self->backgroundTask_)) {
            void* name;
            void* pac;
            unsigned int pacSize;
            loader->GetLoadedFileByID(self->backgroundTask_, &pac, &pacSize);
            int count = CountActiveEntries((ActiveEntry02046900*)pac);
            BackgroundGraphics background;
            _Z17ResetList0204af64P12List0204af64((List0204af64*)&background);
            SetWord0x18ClearByte0x1f((unsigned char*)&background, 0);
            background.unk_1c_0_ = 0;
            background.unk_1c_4_ = 3;
            func_0204b5b4(&background, 3);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)&background, 0, 0);
            for (int i = 0; i < count; i++) {
                int size;
                void* file = FindRecordByIndex((Rec020467f0*)pac, i, &name, &size);
                if (file != 0) {
                    _Z21DispatchByTag0204b2e0PvPc(&background, (char*)file);
                    _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc((SelfTag0204b3a0*)&background, (char*)file);
                }
            }
            loader->RemoveTask(self->backgroundTask_);
            self->backgroundTask_ = -1;
            self->backgroundStep_ = 0;
            self->flags_ &= ~1;
            self->flags_ &= ~4;
        }
    }
}
