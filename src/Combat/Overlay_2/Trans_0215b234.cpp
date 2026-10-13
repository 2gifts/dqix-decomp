#include <globaldefs.h>

extern unsigned char data_02108760;
extern char data_02109bf4;
unsigned char GetByteFieldAt0xcc(unsigned char*);
unsigned char GetField0xcc0209ca98(char*);

// USA: func_ov002_0215b234  (semantic: Trans_0215b234)
extern "C" ARM void func_ov002_0215b234(unsigned char* self) {
    self[0x1c2c] = GetField0xcc0209ca98(&data_02109bf4);
    self[0x1c2d] = GetByteFieldAt0xcc(&data_02108760);
}
