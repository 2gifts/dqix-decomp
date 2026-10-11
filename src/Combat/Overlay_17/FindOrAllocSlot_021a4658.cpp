#include <globaldefs.h>

void Init021b2f64(unsigned char* self);

// USA: func_ov017_021a4658
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
