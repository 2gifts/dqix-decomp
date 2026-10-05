#include <globaldefs.h>

// Provisional recipe and ingredient-table views used by the alchemy menu.
struct AlchemyRecipeQuantityView {
    short unknown00[2];
    short firstIngredient;
    short secondIngredient;
    short thirdIngredient;
    unsigned short firstQuantity : 4;
    unsigned short secondQuantity : 4;
    unsigned short thirdQuantity : 4;
    unsigned short unknownQuantity : 4;
};
struct AlchemyIngredientQuantityView {
    char unknown00[8];
    unsigned char** quantityTables;
    void* unknown0c;
    AlchemyRecipeQuantityView* recipe;
    short firstIndex;
    short secondIndex;
    short thirdIndex;
    signed char firstCategory;
    signed char secondCategory;
    signed char thirdCategory;
};

extern "C" ARM bool func_ov006_02153a78(AlchemyIngredientQuantityView* state, int count)
{
    AlchemyRecipeQuantityView* recipe = state->recipe;
    if (!recipe) return false;
    if (recipe->firstIngredient > 0 && recipe->firstQuantity != 0) {
        if (state->firstIndex < 0) return false;
        if (state->firstCategory < 0) return false;
        if (recipe->firstQuantity * count > state->quantityTables[state->firstCategory][state->firstIndex]) return false;
    }
    if (recipe->secondIngredient > 0 && recipe->secondQuantity != 0) {
        if (state->secondIndex < 0) return false;
        if (state->secondCategory < 0) return false;
        if (recipe->secondQuantity * count > state->quantityTables[state->secondCategory][state->secondIndex]) return false;
    }
    if (recipe->thirdIngredient > 0 && recipe->thirdQuantity != 0) {
        if (state->thirdIndex < 0) return false;
        if (state->thirdCategory < 0) return false;
        if (recipe->thirdQuantity * count > state->quantityTables[state->thirdCategory][state->thirdIndex]) return false;
    }
    return true;
}
