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
#define MoveValue3cbTo3cc func_02094380
extern "C" ARM void func_02094380(char* obj);
#endif

// USA: func_02093a58
ARM void MoveValue3cbTo3cc(char* obj) {
    func_02093ad8(obj, obj, obj + kSecondBank, obj[kByteA]);
    obj[kByteB] = obj[kByteA];
    obj[kByteA] = 0;
    ((unsigned char*)obj)[kFlags] &= ~4;
}
