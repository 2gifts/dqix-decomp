#include <globaldefs.h>

struct Recipe {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short amount0_ : 4;
    unsigned short amount1_ : 4;
    unsigned short amount2_ : 4;
    unsigned short stat_ : 4;
    unsigned int minRate_ : 10;
    unsigned int maxRate_ : 10;
    unsigned int kind_ : 8;
    unsigned int unk_c_28 : 4;
    unsigned int minStat_ : 10;
    unsigned int maxStat_ : 10;
    unsigned int unk_10_20 : 2;
    unsigned int known_ : 1;
    unsigned int unk_10_23 : 9;
    short greatRecipe_;
    short unk_16;
    short unk_18;
    short unk_1a;
    Recipe* next_;
};

struct List02071d60;

extern "C" Recipe* _Z22FindEntryByKey02071d60P12List02071d60i(List02071d60* list, int key);

struct AlchemyIngredients {
    List02071d60* table_;
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
    Recipe* recipe_;
    short index_[3];
    signed char category_[3];
    void* records_;
    unsigned short recordCount_;
};

// USA: func_ov006_021537d0
extern "C" ARM int func_ov006_021537d0(AlchemyIngredients* self, short id) {
    if (self->sizes_ == 0)
        return 0;
    self->recipe_ = _Z22FindEntryByKey02071d60P12List02071d60i(self->table_, id);
    if (self->recipe_ == 0)
        return 0;
    if (self->recipe_->ingredients_[0] > 0 && self->recipe_->amount0_ != 0) {
        self->index_[0] = -1;
        self->category_[0] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->recipe_->ingredients_[0] == items[i]) {
                    self->index_[0] = i;
                    self->category_[0] = category;
                    break;
                }
            }
        }
        if (self->index_[0] < 0)
            return 0;
        if (self->recipe_->amount0_ > self->counts_[self->category_[0]][self->index_[0]])
            return 0;
    }
    if (self->recipe_->ingredients_[1] > 0 && self->recipe_->amount1_ != 0) {
        self->index_[1] = -1;
        self->category_[1] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->recipe_->ingredients_[1] == items[i]) {
                    self->index_[1] = i;
                    self->category_[1] = category;
                    break;
                }
            }
        }
        if (self->index_[1] < 0)
            return 0;
        if (self->recipe_->amount1_ > self->counts_[self->category_[1]][self->index_[1]])
            return 0;
    }
    if (self->recipe_->ingredients_[2] > 0 && self->recipe_->amount2_ != 0) {
        self->index_[2] = -1;
        self->category_[2] = -1;
        for (signed char category = 0; category < 9; category++) {
            short* items = self->items_[category];
            unsigned short size = self->sizes_[category];
            for (unsigned short i = 0; i < size; i++) {
                if (self->recipe_->ingredients_[2] == items[i]) {
                    self->index_[2] = i;
                    self->category_[2] = category;
                    break;
                }
            }
        }
        if (self->index_[2] < 0)
            return 0;
        if (self->recipe_->amount2_ > self->counts_[self->category_[2]][self->index_[2]])
            return 0;
    }
    return 1;
}
