#include <globaldefs.h>

struct SlotPair02085400 {
    signed char sentinelIdx;
    signed char guardIdx;
};
extern struct SlotPair02085400 data_020e8b7e[];

// USA: func_02085400
ARM int AnySlotHasBit17At0x2f4_02085400(unsigned char* obj) {
    int i;
    signed char slotIdx;
    for (i = 0; (slotIdx = data_020e8b7e[i].sentinelIdx) != -1; i++) {
        signed char guardIdx = data_020e8b7e[i].guardIdx;
        if (*(short*)(obj + guardIdx * 0x20 + 0x100 + 0xac) > 0) {
            int field = *(int*)(obj + slotIdx * 0x2c + 0x2f4);
            if (((unsigned int)field << 14) >> 31) {
                return 1;
            }
        }
    }
    return 0;
}
