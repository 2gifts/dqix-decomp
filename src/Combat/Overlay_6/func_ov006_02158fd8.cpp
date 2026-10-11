#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

struct AlchemyMenu {
    char unk_0[R(0x40, 0x48)];
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
};

extern "C" const unsigned short data_ov006_0215fffe[9];

// USA: func_ov006_02158fd8
extern "C" ARM void func_ov006_02158fd8(AlchemyMenu* self, unsigned int category, short item, unsigned char count) {
    if (item <= 0 || count == 0)
        return;
    short* items = self->items_[category];
    unsigned char* counts = self->counts_[category];
    unsigned short* size = &self->sizes_[category];
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, sizeof(sizes));
    unsigned short capacity = sizes[category];
    for (unsigned short i = 0; i < capacity; i++) {
        short entry = items[i];
        if (entry <= 0) {
            items[i] = item;
            counts[i] = count;
            (*size)++;
            return;
        }
        if (entry == item) {
            counts[i] += count;
            return;
        }
    }
}
