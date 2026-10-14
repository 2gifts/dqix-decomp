#include <globaldefs.h>

// USA: func_02088ab8
ARM int CheckFlag0x1ClearAndFlag0x40Clear_02088ab8(unsigned char* obj) {
    if (((int*)obj)[5] & 1) {
        return 0;
    }
    return (((int*)obj)[6] & 0x40) == 0;
}
