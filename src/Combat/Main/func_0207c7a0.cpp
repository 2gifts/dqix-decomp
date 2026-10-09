#include <globaldefs.h>

struct KeyedList0207c7a0 {
    char pad0[0xbd0];
    short *valueArrays[8];
    signed char *countArrays[8];
    short counts[8];
    unsigned char keys[8];
};
extern const short data_020e8a14[8];

// USA: func_0207c7a0
extern "C" ARM int func_0207c7a0(void *map, int value, int key) {
    KeyedList0207c7a0 *list = static_cast<KeyedList0207c7a0 *>(map);
    if (value < 0) {
        return 0;
    }
    int keyIndex = -1;
    for (int i = 0; i < 8; i++) {
        if (key == list->keys[i]) {
            keyIndex = i;
            break;
        }
    }
    if (keyIndex < 0) {
        for (int i = 0; i < 8; i++) {
            int capacity = data_020e8a14[i];
            short *values = list->valueArrays[i];
            for (int j = 0; j < capacity; j++) {
                if (value == values[j]) {
                    signed char *counts = list->countArrays[i];
                    return counts[j];
                }
            }
        }
    } else {
        int capacity = data_020e8a14[keyIndex];
        short *values = list->valueArrays[keyIndex];
        for (int j = 0; j < capacity; j++) {
            if (value == values[j]) {
                signed char *counts = list->countArrays[keyIndex];
                return counts[j];
            }
        }
    }
    return 0;
}