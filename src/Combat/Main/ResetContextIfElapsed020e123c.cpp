#include <globaldefs.h>

int IsElapsedTicksBelowThreshold_020e11e4(void);
void SetBattlerByte0x1c_02012528(unsigned char* obj, unsigned char value);
void SetByte0x6102012ba8(unsigned char* obj, unsigned char val);

struct Ctx02153628 { void* field0; unsigned int field4; unsigned int field8; };
extern Ctx02153628 data_02153628;
extern unsigned char data_02114e30;
extern unsigned char data_02114e54;

// USA: func_020e123c  (semantic: ResetContextIfElapsed020e123c)
extern "C" ARM void func_020e123c(void) {
    if (IsElapsedTicksBelowThreshold_020e11e4()) {
        return;
    }
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    SetBattlerByte0x1c_02012528(&data_02114e30, 1);
    SetByte0x6102012ba8(&data_02114e54, 1);
}
