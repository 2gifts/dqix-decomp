#include "globaldefs.h"

struct Overlay2LayoutPreset {
    unsigned char id, width, height;
    signed char x, y;
    unsigned char extra0, extra1;
};
struct Overlay2LayoutParameters {
    unsigned char unknown00[0xa0];
    short x, y, inputX, inputY;
    short width, height, extra0, extra1;
    unsigned char unknownB0, preset, unknownB2[3], active, unknownB6, frames;
    inline void setSize(short a, short b) { width = a; height = b; }
    inline void setPosition(short a, short b) { x = a; y = b; }
    inline void setExtra(short a, short b) { extra0 = a; extra1 = b; }
};
struct Overlay2LayoutState {
    unsigned char unknown00[0xec8];
    Overlay2LayoutParameters parameters;
    unsigned char unknownF80[0x1bb8 - 0xf80];
    int mode;
};
extern "C" const Overlay2LayoutPreset data_ov002_0216cb48[];
extern "C" void func_ov002_02156080(Overlay2LayoutState*, short*, short*);

// Install the selected table preset, including two special-case adjustments.
extern "C" ARM void func_ov002_0215be00(Overlay2LayoutState* state, int id, short inputX, short inputY) {
    for (int i = 0; data_ov002_0216cb48[i].id != 255; ++i) {
        const Overlay2LayoutPreset* preset = &data_ov002_0216cb48[i];
        if (preset->id != id) continue;
        Overlay2LayoutParameters* parameters = &state->parameters;
        parameters->preset = preset->id;
        parameters->inputX = inputX;
        parameters->inputY = inputY;
        parameters->setSize(preset->width, preset->height);
        parameters->setPosition(preset->x, preset->y);
        parameters->setExtra(preset->extra0, preset->extra1);
        parameters->active = 1;
        if (preset->id == 21) {
            short entries[9], height;
            short displacement = 0;
            func_ov002_02156080(state, entries, &height);
            if (height < 8) {
                displacement = (8 - height) * 2;
            } else {
                parameters->setSize(preset->width, preset->height + 1);
            }
            if (displacement < 0) displacement = 0;
            parameters->setPosition(preset->x, preset->y - displacement);
        }
        if (preset->id == 13 && state->mode == 11) {
            parameters->x = 17;
            parameters->y = 16;
        }
        int frames = 10;
        if (id == 38) frames = 12;
        parameters->frames = frames;
        break;
    }
}
