#include <globaldefs.h>

void SetBattlerByte0x1c_02012528(unsigned char* obj, unsigned char value);
void SetByte0x6102012ba8(unsigned char* obj, unsigned char val);

struct Struct02153628_020e1114 { unsigned int field0; unsigned int field4; unsigned int field8; };
extern struct Struct02153628_020e1114 data_02153628;
extern unsigned char data_02114e30;
extern unsigned char data_02114e54;

// USA: func_020e1114
ARM void ResetElapsedState020e1114(void) {
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    SetBattlerByte0x1c_02012528(&data_02114e30, 1);
    SetByte0x6102012ba8(&data_02114e54, 1);
}
