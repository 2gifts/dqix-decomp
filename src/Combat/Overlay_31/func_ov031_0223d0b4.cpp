#include <globaldefs.h>

struct InputRepeatState0223d0b4 {
    unsigned char pad[0x30];
    unsigned short mask;
    unsigned short pressed;
    unsigned short pressedOrRepeat;
    unsigned short released;
};

extern unsigned char data_ov031_02290d40[];
extern unsigned char data_ov031_02290d48[];

#define STATE0223d0b4 (*(InputRepeatState0223d0b4**)(data_ov031_02290d40 + 4))

// USA: func_ov031_0223d0b4
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0223d0b4(void) {
    InputRepeatState0223d0b4* state = STATE0223d0b4;
    unsigned short a = *(volatile unsigned short*)0x4000130;
    unsigned short b = *(volatile unsigned short*)0x27fffa8;
    unsigned short keyMask = (unsigned short)(((a | b) ^ 0x2fff) & 0x2fff);
    state->pressed = (unsigned short)((state->mask ^ keyMask) & keyMask);
    STATE0223d0b4->released = (unsigned short)(state->mask & (state->mask ^ keyMask));
    STATE0223d0b4->mask = keyMask;
    STATE0223d0b4->pressedOrRepeat = STATE0223d0b4->pressed;

    int i = 0;
    unsigned char* counters = data_ov031_02290d48;
    do {
        unsigned short bit = (unsigned short)(1 << i);
        if (!(keyMask & bit)) {
            *counters = 0;
        } else {
            *counters = *counters + 1;
            if (*counters == 0x28) {
                STATE0223d0b4->pressedOrRepeat |= bit;
            } else if (*counters == 0x2f) {
                STATE0223d0b4->pressedOrRepeat |= bit;
                *counters = 0x28;
            }
        }
        i++;
        counters++;
    } while (i < 14);
}
