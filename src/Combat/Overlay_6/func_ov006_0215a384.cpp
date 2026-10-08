#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/BackgroundLoader.h>

struct Record020836e4 {
    void* model_;
    char unk_4[0x1c];
};

struct Obj02157c78;
struct List02071d60;

struct PotIngredient {
    Record020836e4 entry_;
    char unk_20[0x50];
    short item_;
};

struct Recipe {
    short id_;
    short item_;
    short ingredients_[3];
    char unk_a[0xa];
    short greatRecipe_;
};

struct ResultItems {
    short items_[4];
};

struct AlchemyPot;

struct AlchemyMenu {
    char unk_0[0xc];
    SafeAllocator* allocators_;
    AlchemyPot* pot_;
    char unk_14[0x20];
    Recipe* recipe_;
    char unk_38[0x114];
    char table_[0x30];
    PotIngredient results_[4];
    char unk_34c[0x8];
    int task_;
    char unk_358[0x20];
    short chosenItems_[3];
};

extern "C" void _Z16InitObj_02157c78P11Obj02157c78(Obj02157c78* ingredient);
extern "C" void _Z18CopyStruct020836e4P14Record020836e4S0_(Record020836e4* destination, Record020836e4* source);
extern "C" Recipe* _Z22FindEntryByKey02071d60P12List02071d60i(List02071d60* table, int id);
extern "C" void _Z23InitAndDispatch020deef4iiiPss(int items, int file, int size, short* ids, short count);
extern "C" void func_ov006_02156f04(AlchemyPot* pot, PotIngredient* ingredients);

extern "C" const ResultItems data_ov006_0215ffda;

// USA: func_ov006_0215a384
extern "C" ARM unsigned char func_ov006_0215a384(AlchemyMenu* self, int great) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->task_)) {
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        if (data != 0) {
            self->allocators_[8].Reset();
            ResultItems ids = data_ov006_0215ffda;
            Record020836e4 copies[4];
            unsigned char i;
            for (i = 0; i < 4; i++) {
                _Z16InitObj_02157c78P11Obj02157c78((Obj02157c78*)&self->results_[i]);
                _Z18CopyStruct020836e4P14Record020836e4S0_(&copies[i], &self->results_[i].entry_);
            }
            Recipe* recipe = self->recipe_;
            if (recipe != 0) {
                if (great)
                    recipe = _Z22FindEntryByKey02071d60P12List02071d60i((List02071d60*)self->table_, recipe->greatRecipe_);
                short item = recipe->item_;
                self->results_[0].item_ = item;
                ids.items_[0] = item;
            }
            short item1 = self->chosenItems_[0];
            self->results_[1].item_ = item1;
            ids.items_[1] = item1;
            short item2 = self->chosenItems_[1];
            self->results_[2].item_ = item2;
            ids.items_[2] = item2;
            short item3 = self->chosenItems_[2];
            self->results_[3].item_ = item3;
            ids.items_[3] = item3;
            if (self->recipe_ != 0) {
                if (ids.items_[1] < 0) {
                    short ingredient = self->recipe_->ingredients_[0];
                    self->results_[1].item_ = ingredient;
                    ids.items_[1] = ingredient;
                }
                if (ids.items_[2] < 0) {
                    short ingredient = self->recipe_->ingredients_[1];
                    self->results_[2].item_ = ingredient;
                    ids.items_[2] = ingredient;
                }
                if (ids.items_[3] < 0) {
                    short ingredient = self->recipe_->ingredients_[2];
                    self->results_[3].item_ = ingredient;
                    ids.items_[3] = ingredient;
                }
            }
            _Z23InitAndDispatch020deef4iiiPss((int)copies, (int)data, size, ids.items_, 4);
            if (ids.items_[1] == ids.items_[2] && ids.items_[2] > 0)
                _Z18CopyStruct020836e4P14Record020836e4S0_(&copies[2], &copies[1]);
            if (ids.items_[1] == ids.items_[3] && ids.items_[3] > 0)
                _Z18CopyStruct020836e4P14Record020836e4S0_(&copies[3], &copies[1]);
            if (ids.items_[2] == ids.items_[3] && ids.items_[3] > 0)
                _Z18CopyStruct020836e4P14Record020836e4S0_(&copies[3], &copies[2]);
            for (i = 0; i < 4; i++)
                _Z18CopyStruct020836e4P14Record020836e4S0_(&self->results_[i].entry_, &copies[i]);
            func_ov006_02156f04(self->pot_, self->results_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->task_ == -1)
        return 1;
    return 0;
}
