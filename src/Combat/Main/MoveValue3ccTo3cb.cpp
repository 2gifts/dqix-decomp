#include <globaldefs.h>

#if defined(jpn)
enum { kSecondBank = 0x80, kByteA = 0x13b, kByteB = 0x13c, kFlags = 0x13d };
#else
enum { kSecondBank = 0x1a0, kByteA = 0x3cb, kByteB = 0x3cc, kFlags = 0x3cd };
#endif
#if defined(jpn)
#define func_02093ad8 func_02094400
#endif


extern "C" void func_02093ad8(char* a, char* b, char* c, int d);

#if defined(jpn)
#define MoveValue3ccTo3cb func_020943c0
extern "C" ARM void func_020943c0(char* obj);
#endif

// USA: func_02093a98
ARM void MoveValue3ccTo3cb(char* obj) {
    func_02093ad8(obj, obj + kSecondBank, obj, obj[kByteB]);
    obj[kByteA] = obj[kByteB];
    obj[kByteB] = 0;
    ((unsigned char*)obj)[kFlags] &= ~4;
}
