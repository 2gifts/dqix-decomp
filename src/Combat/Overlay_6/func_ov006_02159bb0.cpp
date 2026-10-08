#include <globaldefs.h>

struct AlchemyMenu {
    char unk_0[0x100];
    char layout_[0x4c];
};

extern "C" short func_ov023_021e29d0(void* layout);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);

extern "C" unsigned short data_02114e30[];

// USA: func_ov006_02159bb0
extern "C" ARM unsigned char func_ov006_02159bb0(AlchemyMenu* self) {
    int filter1 = 0;
    int filter2 = 0;
    int sort = 0;
    int names = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x41)
            filter1 = 1;
        filter2 = element == 0x42 ? 1 : 0;
        sort = element == 0x13 ? 1 : 0;
        names = element == 0x26 ? 1 : 0;
    } else {
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 4))
            sort = 1;
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x300))
            names = 1;
    }
    if (sort)
        return 1;
    if (filter1)
        return 2;
    if (filter2)
        return 3;
    if (names)
        return 4;
    return 0;
}
