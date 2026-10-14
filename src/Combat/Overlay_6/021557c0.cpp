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
    char unk_0[0x48];
    void* partNames_;
#if defined(jpn)
    char unk_4c[0x6f0 - 0x4c];
#else
    char unk_4c[0x774 - 0x4c];
#endif
    unsigned short flags_;
    unsigned char visible_;
    char unk_777[0x6];
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
    short item_;
    short ingredients_[3];
    unsigned short amount0_ : 4;
    unsigned short amount1_ : 4;
    unsigned short amount2_ : 4;
    unsigned short unk_a_12 : 4;
    unsigned int unk_c_0 : 20;
    unsigned int letter_ : 8;
    unsigned int unk_c_28 : 4;
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

struct BattleEquipmentEntry {
    unsigned char unknown00[8];
    unsigned int category : 4;
    unsigned int unknownFlags : 28;
    unsigned char unknown0c[0xc];
    short item;
    unsigned char unknown1a[6];
};

struct BattleEquipmentView {
    unsigned char unknown00[0x194];
    BattleEquipmentEntry entries[8];
};

struct Party021557c0 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Container020e0310;
struct Container020dedd0;

extern "C" void __clear(void* dst, int size);
int GetFieldByKey020e0434(Container020e0310* texts, int id);
#if defined(jpn)
extern "C" int func_020e12ec(char* destination, const char* source);
#define data_ov006_0215ff5c data_ov006_021612c0
#endif
void ZeroInit020de848(void* obj);
int BuildDescriptorFlag1_020de980(void* obj, void* alloc, void* data, int size, int id);
void* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" void func_ov023_021dcd90(ItemInfoWindow* window, unsigned char inMenu);
extern "C" void func_ov023_021dcae0(ItemInfoWindow* window, int item);
extern "C" void func_ov023_021dced4(ItemInfoWindow* window, unsigned char multiplier);
const char** CallFunc020e52a0_020e5294(void* names, int item);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
void* GetPtrField0x2a04_02010828(GameState* gameState);
void SetFields_021dceac(char* window, int index, int name, unsigned char count, unsigned char maximum, unsigned char unk);

extern unsigned char data_ov006_0215ff5c[8];

// USA: func_ov006_021557c0
extern "C" ARM void func_ov006_021557c0(AlchemyPot* self) {
    if (!(self->flags_ & 2) || self->window_.visible_ == 0)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    short item = self->itemId_;
    if (item > 0) {
        if (self->itemStep_ == 0) {
            short innerKey = self->itemSprites_ + 0x26;
#if defined(jpn)
            const char* inner = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, innerKey);
            char path[0x40];
            func_020e12ec(path, inner);
            self->task_ = loader->QueueLoadGP1(path, 0);
#else
            short gp2Key = self->itemSprites_ + 0x64;
            const char* inner = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, innerKey);
            const char* gp2 = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, gp2Key);
            self->task_ = loader->QueueLoadFileInGP2(gp2, inner, 0);
#endif
            self->itemStep_++;
        }
        if (self->itemStep_ == 1) {
            if (loader->GetTaskStatus(self->task_) == 0)
                return;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &data, &size);
            self->nextItemAllocator_->Reset();
            short id = self->itemId_;
            ZeroInit020de848(self->partNames_);
            BuildDescriptorFlag1_020de980(self->partNames_, self->nextItemAllocator_, data, size, id);
            self->window_.flags_ &= ~0x1000;
            self->window_.partNames_ = self->partNames_;
            func_ov023_021dcd90(&self->window_, 1);
            loader->RemoveTask(self->task_);
            self->nextItem_ = FindElementByKey020dedd0((Container020dedd0*)self->partNames_, id);
            self->flags_ &= ~2;
            self->flags_ |= 0x40;
            func_ov023_021dcae0(&self->window_, self->itemId_);
            return;
        }
    } else if (item == -1) {
        self->flags_ &= ~2;
        self->flags_ |= 0x40;
        self->window_.flags_ &= ~0x1000;
        func_ov023_021dcd90(&self->window_, 1);
        func_ov023_021dcae0(&self->window_, self->itemId_);
        return;
    }

    if (self->itemStep_ == 0) {
#if defined(jpn)
        short innerKey = 0x26;
        innerKey += self->nextRecipe_->letter_;
        const char* inner = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, innerKey);
        char path[0x40];
        func_020e12ec(path, inner);
        self->task_ = loader->QueueLoadGP1(path, 0);
#else
        short gp2Key = 0x64;
        short innerKey = 0x26;
        gp2Key += self->nextRecipe_->letter_;
        innerKey += self->nextRecipe_->letter_;
        const char* inner = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, innerKey);
        const char* gp2 = (const char*)GetFieldByKey020e0434((Container020e0310*)self->texts_, gp2Key);
        self->task_ = loader->QueueLoadFileInGP2(gp2, inner, 0);
#endif
        self->itemStep_++;
    } else if (self->itemStep_ == 1) {
        if (loader->GetTaskStatus(self->task_) == 0)
            return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        if (data != 0) {
            self->nextItemAllocator_->Reset();
            ZeroInit020de848(self->partNames_);
            BuildDescriptorFlag1_020de980(self->partNames_, self->nextItemAllocator_, data, size, self->nextRecipe_->item_);
            self->nextItem_ = FindElementByKey020dedd0((Container020dedd0*)self->partNames_, self->nextRecipe_->item_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->itemStep_ = 3;
    } else if (self->itemStep_ == 3) {
        self->recipe_ = self->nextRecipe_;
        SafeAllocator* alloc = self->itemAllocator_;
        self->itemAllocator_ = self->nextItemAllocator_;
        self->nextItemAllocator_ = alloc;
        self->window_.partNames_ = self->partNames_;
        func_ov023_021dcd90(&self->window_, 1);
        const char* names[3] = {0};
        if (self->itemNames_ != 0) {
#if defined(jpn)
            names[0] = (const char*)GetFieldByKey020e0434((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[0]);
            names[1] = (const char*)GetFieldByKey020e0434((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[1]);
            names[2] = (const char*)GetFieldByKey020e0434((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[2]);
#else
            memset(self->names_, 0, sizeof(self->names_));
            const char** name = CallFunc020e52a0_020e5294(self->itemNames_, self->nextRecipe_->ingredients_[0]);
            if (name != 0) {
                func_020e4864(*name, self->names_[0], 1, 0, 0, 0);
                names[0] = self->names_[0];
            }
            name = CallFunc020e52a0_020e5294(self->itemNames_, self->nextRecipe_->ingredients_[1]);
            if (name != 0) {
                func_020e4864(*name, self->names_[1], 1, 0, 0, 0);
                names[1] = self->names_[1];
            }
            name = CallFunc020e52a0_020e5294(self->itemNames_, self->nextRecipe_->ingredients_[2]);
            if (name != 0) {
                func_020e4864(*name, self->names_[2], 1, 0, 0, 0);
                names[2] = self->names_[2];
            }
#endif
        }
        unsigned char counts[3] = {0};
        GameState* gs = GameState::GetInstance();
        Party021557c0* party = (Party021557c0*)GetPtrField0x2a04_02010828(gs);
        for (int i = 0; i < party->count; i++) {
            char* actor = (char*)GetCombatantWithFlag0x100_0200ff1c(gs, party->ids[i]);
            if (actor != 0) {
                for (int j = 0; j < 8; j++) {
                    BattleEquipmentView* equipment = *(BattleEquipmentView**)(actor
#if defined(jpn)
                        + 0x144
#else
                        + 0x150
#endif
                    );
                    BattleEquipmentEntry* entry = &equipment->entries[data_ov006_0215ff5c[j]];
                    if (entry != 0) {
                        int equipped = entry->category <= 7;
                        if (equipped) {
                            if (self->nextRecipe_->ingredients_[0] == entry->item)
                                counts[0]++;
                            if (self->nextRecipe_->ingredients_[1] == entry->item)
                                counts[1]++;
                            if (self->nextRecipe_->ingredients_[2] == entry->item)
                                counts[2]++;
                        }
                    }
                }
            }
        }
        SetFields_021dceac((char*)&self->window_, 0, (int)names[0], self->nextRecipe_->amount0_, self->amounts_[0], counts[0]);
        SetFields_021dceac((char*)&self->window_, 1, (int)names[1], self->nextRecipe_->amount1_, self->amounts_[1], counts[1]);
        SetFields_021dceac((char*)&self->window_, 2, (int)names[2], self->nextRecipe_->amount2_, self->amounts_[2], counts[2]);
        func_ov023_021dced4(&self->window_, 1);
        int known = 0;
        if (self->record_ != 0 && self->record_->known_)
            known = 1;
        if (known)
            self->window_.flags_ &= ~0x1000;
        else
            self->window_.flags_ |= 0x1000;
        func_ov023_021dcae0(&self->window_, self->nextRecipe_->item_);
        self->item_ = self->nextItem_;
        self->nextItem_ = 0;
        self->itemStep_ = 0;
        self->flags_ &= ~2;
        self->flags_ |= 0x44;
    }
}
