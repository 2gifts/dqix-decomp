#include <globaldefs.h>

// USA: func_02088c54
ARM int CheckFlag0x1ClearAndFlag0x20000Clear_02088c54(unsigned char* obj) {
    int x = *(int*)(obj + 0x14);
    if (x & 1) {
        return 0;
    }
    return (x & 0x20000) == 0;
}
