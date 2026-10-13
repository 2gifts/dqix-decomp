#include <globaldefs.h>

extern unsigned char data_02109da4;
extern unsigned char data_02109da6;

// USA: func_020a1fd4
ARM void StoreByteAtCountTail020a1fd4(unsigned char value) {
    const unsigned char* counts = &data_02109da4;
    if (counts[1] != 0) {
        (&data_02109da6)[(&data_02109da4)[1] - 1] = value;
    }
}
