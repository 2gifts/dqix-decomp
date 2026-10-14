#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
void SetBattlerByte0x1c_02012528(unsigned char* obj, unsigned char value);
struct ShortPair02012518;
void ClearTwoHalfwords(ShortPair02012518* p);
void SetByte0x6102012ba8(unsigned char* obj, unsigned char val);
void TailForward02012bb0(unsigned char* obj);

struct Ctx02153628 { void* field0; unsigned int field4; unsigned int field8; };
extern Ctx02153628 data_02153628;
extern unsigned char data_02114e30;
extern unsigned char data_02114e54;

// USA: func_020e1154
ARM void InitContext020e1154(void* obj) {
    unsigned long long result = GetCurrentTimestamp();
    data_02153628.field4 = (unsigned int)result;
    data_02153628.field8 = (unsigned int)(result >> 32);
    data_02153628.field0 = obj;
    SetBattlerByte0x1c_02012528(&data_02114e30, 0);
    ClearTwoHalfwords((ShortPair02012518*)&data_02114e30);
    SetByte0x6102012ba8(&data_02114e54, 0);
    TailForward02012bb0(&data_02114e54);
}
