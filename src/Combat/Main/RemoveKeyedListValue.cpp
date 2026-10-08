#include <globaldefs.h>

struct KeyedList0207c484 {
    char pad0[0xbd0];
    short *valueArrays[8];
    signed char *countArrays[8];
    short counts[8];
    unsigned char keys[8];
};
int DecrementKeyedStackAmount0207c484(KeyedList0207c484 *, int, int, int);
extern const short data_020e8a04[8];

// USA: func_0207c894
extern "C" ARM int func_0207c894(void *map, int value, int key) {
    KeyedList0207c484 *list = static_cast<KeyedList0207c484 *>(map);
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
            int capacity  = data_020e8a04[i];
            short *values = list->valueArrays[i];
            for (int j = 0; j < capacity; j++) {
                if (value == values[j]) {
                    signed char *counts = list->countArrays[i];
                    if (counts[j] != 0) {
                        counts[j]--;
                    }
                    if (counts[j] == 0) {
                        values[j] = -1;
                    }
                    return 1;
                }
            }
        }
    } else {
        return DecrementKeyedStackAmount0207c484(list, value, 1, keyIndex) != 0;
    }
    return 0;
}
