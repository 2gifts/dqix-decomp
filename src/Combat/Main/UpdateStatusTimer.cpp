#include <globaldefs.h>
#if defined(jpn)
#define ACTIVE_FLAG 0x17f1
#define TIMER_FLAG 0x17f0
#define TIMER_COUNT 0x178b
#else
#define ACTIVE_FLAG 0x19c1
#define TIMER_FLAG 0x19c0
#define TIMER_COUNT 0x195d
#endif

// USA: func_020658ac
ARM void UpdateStatusTimer(unsigned char* base, unsigned int amount) {
    unsigned char c;
    if (base[ACTIVE_FLAG] != 0) {
        if (base[TIMER_FLAG] == 0) {
            base[TIMER_FLAG] = 1;
            base[TIMER_COUNT] = 0x1e;
        }
    }
    if (base[TIMER_FLAG] == 0) return;
    c = base[TIMER_COUNT];
    if (c <= amount) {
        if (base[ACTIVE_FLAG] != 0) {
            base[TIMER_COUNT] = c + (0x1e - amount);
        } else {
            base[TIMER_COUNT] = 0;
            base[TIMER_FLAG] = 0;
        }
    } else {
        base[TIMER_COUNT] = c - amount;
    }
}

// JPN: 0x02066cdc
