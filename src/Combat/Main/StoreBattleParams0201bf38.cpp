#include <globaldefs.h>

#if defined(jpn)
#define StoreBattleParams0201bf38 func_0201bcb0
enum { ParamAOffset = 0x2785, ParamBOffset = 0x2786, ParamCOffset = 0x2788 };
#else
enum { ParamAOffset = 0x2745, ParamBOffset = 0x2746, ParamCOffset = 0x2748 };
#endif

ARM void SetOrClearBit(unsigned char* obj, int bit, int set);

#if defined(jpn)
extern "C" void func_0201bcb0(unsigned char* obj, int set, int a, int b, unsigned short c);
#endif

// USA: func_0201bf38
ARM void StoreBattleParams0201bf38(unsigned char* obj, int set, int a, int b, unsigned short c) {
    SetOrClearBit(obj, 0, set);
    obj[ParamAOffset] = a;
    obj[ParamBOffset] = b;
    *(unsigned short*)(obj + ParamCOffset) = c;
}
