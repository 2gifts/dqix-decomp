#include <globaldefs.h>

struct AlchemyIngredients {
    char unk_0[0x4];
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
};

// USA: func_ov006_021537c8  (semantic: Trans_021537c8)
extern "C" ARM void func_ov006_021537c8(AlchemyIngredients* self, short** items, unsigned char** counts, unsigned short* sizes) {
    self->items_ = items;
    self->counts_ = counts;
    self->sizes_ = sizes;
}
