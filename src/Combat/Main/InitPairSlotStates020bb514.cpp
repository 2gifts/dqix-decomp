#include <globaldefs.h>
#if defined(jpn)
#define data_020f1f14 data_020f2080
#define data_0210cf84 data_0210cc3c
#endif

struct PairSlot020bb514 { int a; int b; int active; int flag; char pad[8]; };
extern struct PairSlot020bb514 data_020f1f14[];
extern unsigned short data_0210cf84;

// USA: func_020bb514
ARM void InitPairSlotStates020bb514(void) {
    int i;
    struct PairSlot020bb514* slot = data_020f1f14;
    unsigned int rawCount = data_0210cf84;
    if (rawCount > 1) rawCount = rawCount + 1;
    int count = (int)rawCount;
    i = 0;
    do {
        if (i < count) {
            slot->active = 1;
        } else {
            slot->active = 0;
        }
        if (slot->flag != 0) {
            slot->a = 0;
            slot->b = 0x10000;
        } else {
            slot->a = 0;
            slot->b = 0x20000;
        }
        i = i + 1;
        slot = slot + 1;
    } while (i < 5);
}
