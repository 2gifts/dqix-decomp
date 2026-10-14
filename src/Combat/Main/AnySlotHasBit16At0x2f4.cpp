#include <globaldefs.h>

struct SlotPair0208538c {
    signed char sentinelIdx;
    signed char guardIdx;
};
extern struct SlotPair0208538c data_020e8b6c[];

// USA: func_0208538c
ARM int AnySlotHasBit16At0x2f4_0208538c(unsigned char* obj) {
    int i;
    signed char slotIdx;
    for (i = 0; (slotIdx = data_020e8b6c[i].sentinelIdx) != -1; i++) {
        signed char guardIdx = data_020e8b6c[i].guardIdx;
        if (*(short*)(obj + guardIdx * 0x20 + 0x100 + 0xac) > 0) {
            int field = *(int*)(obj + slotIdx * 0x2c + 0x2f4);
            if (((unsigned int)field << 15) >> 31) {
                return 1;
            }
        }
    }
    return 0;
}
