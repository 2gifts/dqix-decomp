#include <globaldefs.h>
#include <std_library_functions.h>

struct Recipe {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short amount0_ : 4;
    unsigned short amount1_ : 4;
    unsigned short amount2_ : 4;
    unsigned short stat_ : 4;
};

struct List02071d60;

extern "C" Recipe* _Z22FindEntryByKey02071d60P12List02071d60i(List02071d60* list, int key);

struct AlchemyIngredients {
    List02071d60* table_;
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
};

// USA: func_ov006_02153b9c
extern "C" ARM void func_ov006_02153b9c(AlchemyIngredients* self, short id, unsigned char* amounts) {
    memset(amounts, 0, 3);
    Recipe* recipe = _Z22FindEntryByKey02071d60P12List02071d60i(self->table_, id);
    if (recipe == 0)
        return;
    for (int category = 0; category < 9; category++) {
        short* items = self->items_[category];
        unsigned char* counts = self->counts_[category];
        short size = self->sizes_[category];
        for (short i = 0; i < size; i++) {
            short item = items[i];
            if (item > 0) {
                if (item == recipe->ingredients_[0])
                    amounts[0] = counts[i];
                else if (item == recipe->ingredients_[1])
                    amounts[1] = counts[i];
                else if (item == recipe->ingredients_[2])
                    amounts[2] = counts[i];
            }
        }
    }
}
