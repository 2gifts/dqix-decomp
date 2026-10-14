#include <globaldefs.h>

// USA: func_02088a70
ARM int CheckActiveAndFlag0x40Clear_02088a70(unsigned char* obj) {
    if (((int*)obj)[5] & 1) {
        return 0;
    }
    return (((int*)obj)[6] & 0x40) == 0;
}
