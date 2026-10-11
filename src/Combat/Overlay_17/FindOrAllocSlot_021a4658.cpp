#include <globaldefs.h>

void Init021b2f64(unsigned char* self);

// func_ov017_0218f5a4 passes a combatant ID and writes it to the returned slot.
// The two scans prefer an existing active match before initializing a free slot.
// Exhaustion deliberately retains the original non-returning loop.
// USA: func_ov017_021a4658
// JPN: func_ov017_021a50cc
extern "C" ARM unsigned char* func_ov017_021a4658(unsigned char* base, int combatantId) {
    int matchingSlotIndex;
    for (matchingSlotIndex = 0; matchingSlotIndex < 0xc; matchingSlotIndex++) {
        unsigned char* slotRelativeBase = base + matchingSlotIndex * 0x48;
#if defined(jpn)
        if (slotRelativeBase[0x352e] != 0) {
            if (slotRelativeBase[0x352f] == 0 && combatantId == *(short*)(slotRelativeBase + 0x3534)) {
                return base + 0x352c + matchingSlotIndex * 0x48;
#else
        if (slotRelativeBase[0x373e] != 0) {
            if (slotRelativeBase[0x373f] == 0 && combatantId == *(short*)(slotRelativeBase + 0x3744)) {
                return base + 0x373c + matchingSlotIndex * 0x48;
#endif
            }
        }
    }

    int freeSlotIndex;
    for (freeSlotIndex = 0; freeSlotIndex < 0xc; freeSlotIndex++) {
        unsigned char* slotRelativeBase = base + freeSlotIndex * 0x48;
#if defined(jpn)
        if (slotRelativeBase[0x352e] == 0) {
            unsigned char* freeSlot = base + 0x352c + freeSlotIndex * 0x48;
#else
        if (slotRelativeBase[0x373e] == 0) {
            unsigned char* freeSlot = base + 0x373c + freeSlotIndex * 0x48;
#endif
            Init021b2f64(freeSlot);
#if defined(jpn)
            return base + 0x352c + freeSlotIndex * 0x48;
#else
            return base + 0x373c + freeSlotIndex * 0x48;
#endif
        }
    }

    for (;;) {}
}
