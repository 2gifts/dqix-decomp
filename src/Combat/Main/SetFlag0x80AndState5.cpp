#include <globaldefs.h>

struct Obj02088818;
void SetStateAndByte0x6a(struct Obj02088818* obj, unsigned short mode);

// USA: func_020887fc
ARM void SetFlag0x80AndState5_020887fc(unsigned char* obj) {
    *(int*)(obj + 0x18) |= 0x80;
    SetStateAndByte0x6a((struct Obj02088818*)obj, 5);
}
