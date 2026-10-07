#include "std_library_functions.h"

// Partial view shared by this preparation routine and the following renderer.
struct Overlay8Preparation {
    unsigned char unknown000[0xb8];
    void* buffer;
    unsigned char unknown0bc[0x130 - 0xbc];
    unsigned char renderer[0xa0];
    short dimensions[8];
    unsigned char unknown1e0;
    unsigned char pass;
    unsigned char unknown1e2[3];
    unsigned char enabled;
    unsigned char visible;
    unsigned char count;
};

extern "C" {
    // Inferred from original call sites; no existing src/include declaration.
    void func_ov008_02187278(Overlay8Preparation*, void*, int, void*);
    void func_0205d304(void*, void*, int, int, bool, bool, void*, bool);

    void func_ov008_0218712c(Overlay8Preparation* menu, void* preferredEntries) {
        menu->dimensions[0] = 5;
        menu->dimensions[1] = 2;
        menu->dimensions[2] = 7;
        menu->dimensions[3] = 7;
        menu->dimensions[4] = 2;
        menu->dimensions[5] = 4;
        menu->dimensions[6] = 10;
        menu->dimensions[7] = 16;
        menu->count = 10;
        menu->pass = 1;
        menu->enabled = 1;
        menu->visible = 1;
        memset(menu->buffer, 0, 0x960);
        func_ov008_02187278(menu, menu->buffer, 0, preferredEntries);
        func_0205d304(menu->renderer, menu->buffer, 0, 0, false, false, 0, false);

        menu->dimensions[0] = 5;
        menu->dimensions[1] = 2;
        menu->dimensions[2] = 7;
        menu->dimensions[3] = 12;
        menu->dimensions[4] = 2;
        menu->dimensions[5] = 4;
        menu->dimensions[6] = 10;
        menu->dimensions[7] = 16;
        menu->count = 10;
        menu->pass = 2;
        menu->enabled = 1;
        menu->visible = 1;
        memset(menu->buffer, 0, 0x960);
        func_ov008_02187278(menu, menu->buffer, 1, preferredEntries);
        func_0205d304(menu->renderer, menu->buffer, 0, 0, false, false, 0, false);
    }
}
