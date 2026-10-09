#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" void func_0204bc08(void* a, int b, int size, void* src, int extra);
extern "C" double func_0200c578(float v);
extern "C" double func_02009424(double v);

struct Entry02174e50 {
    char pad0[0x24];
    unsigned char flags;
    char pad25[0x40 - 0x25];
    float phase;
    char pad44[0x80 - 0x44];
    unsigned short color;
};

// USA: func_ov000_02174e50
extern "C" ARM void func_ov000_02174e50(char* obj, int id) {
    GameState::GetInstance();
    struct Entry02174e50* entry = (struct Entry02174e50*)func_ov000_02161318(obj, id);
    if (entry != NULL) {
        float phase = entry->phase;
        if (3.14f <= phase) {
            unsigned short white = 0x7fff;
            memcpy(*(void**)(obj + 0x178), &white, 2);
            func_0204bc08(obj + 0x8c4, id + 2, 0xf, *(void**)(obj + 0x178), 2);
            entry->flags &= ~8;
            entry->phase = 0.0f;
            entry->color = 0x7fff;
        } else {
            float s = func_02009424(func_0200c578(phase * 2.0f));
            if (s < 0.0f) {
                s = 0.0f - s;
            }
            s = 1.0f - s;
            int g = (int)(16.0f * s) + 15;
            int b = (int)(31.0f * s);
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            unsigned short color = 0x1f | (g << 5) | (b << 10);
            memcpy(*(void**)(obj + 0x178), &color, 2);
            func_0204bc08(obj + 0x8c4, id + 2, 0xf, *(void**)(obj + 0x178), 2);
            entry->color = color;
        }
    }
}
