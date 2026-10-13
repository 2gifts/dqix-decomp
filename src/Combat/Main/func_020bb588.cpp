#include <globaldefs.h>

struct PairSlot020bb588 {
    unsigned int start;
    unsigned int end;
    int active;
    int flag;
    unsigned short pair;
    unsigned short field12;
    unsigned int base;
};
extern PairSlot020bb588 data_020f1f44;
extern PairSlot020bb588 data_020f1f2c;
extern PairSlot020bb588* data_020f1ef8[2];
extern PairSlot020bb588* data_020f1f00[5];
static inline unsigned int AvailablePairBytes020bb588(const PairSlot020bb588* slot) {
    return slot->end - slot->start;
}

// USA: func_020bb588
extern "C" ARM unsigned int func_020bb588(unsigned int size, unsigned int fromFront) {
    unsigned int address;
    unsigned int aligned;
    int allocated;
    if (size == 0) aligned = 16;
    else aligned = (size + 15) & ~15;
    if (aligned >= 0x7fff0) return 0;
    if (fromFront != 0) {
        PairSlot020bb588* pair;
        PairSlot020bb588* slot;
        int i;
        i = 0;
        do {
            slot = data_020f1ef8[i];
            if (!slot->active || AvailablePairBytes020bb588(slot) < aligned) goto nextFront;
            switch (slot->pair) {
            case 0: pair = &data_020f1f2c; break;
            case 3: pair = &data_020f1f44; break;
            default: pair = 0; break;
            }
            if (!pair->active || AvailablePairBytes020bb588(pair) < (aligned >> 1)) goto nextFront;
            unsigned int start = slot->start;
            slot->start += aligned;
            pair->start += aligned >> 1;
            address = start + slot->base;
            allocated = 1;
            goto complete;
nextFront:
            i++;
        } while (i < 2);
        allocated = 0;
    } else {
        int i = 0;
        do {
            PairSlot020bb588* slot = data_020f1f00[i];
            if (!slot->active || AvailablePairBytes020bb588(slot) < aligned) goto nextBack;
            slot->end -= aligned;
            address = slot->end + slot->base;
            allocated = 1;
            goto complete;
nextBack:
            i++;
        } while (i < 5);
        allocated = 0;
    }
complete:
    if (!allocated) return 0;
    unsigned short offset = address >> 3;
    return ((aligned >> 4) << 16) | offset | (fromFront << 31);
}
