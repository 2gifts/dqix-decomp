#include <globaldefs.h>

#if defined(jpn)
enum { kIngredientEntries = 0x714 };
#else
enum { kIngredientEntries = 0x894 };
#endif

struct IngredientSprite {
    char graphics[0x70];
    int task;
    short item;
    short x;
    short y;
    unsigned char loading;
};

struct AlchemyPot {
    char unknown0[kIngredientEntries];
    IngredientSprite ingredients[4];
};

// USA: func_ov006_021570b4
ARM int CheckAnyFlag_021570b4(char* storage) {
    AlchemyPot* pot = (AlchemyPot*)storage;
    IngredientSprite* ingredient = pot->ingredients;
    int loading = 0;
    for (unsigned char i = 0; i < 4; i++, ingredient++) {
        loading = (loading | ingredient->loading) != 0;
    }
    return loading;
}
