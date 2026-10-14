#include <globaldefs.h>

void SetFields5cAnd5e_021f65b4(void*, void*, short, short);
extern char* data_ov004_0217101c;

#if defined(jpn)
enum { globalPointerIndex = 1 };
#else
enum { globalPointerIndex = 0 };
#endif

// USA: func_ov004_02165ef4  (semantic: SetFieldFromDividedStat_02165ef4)
extern "C" ARM void func_ov004_02165ef4(void* a) {
    short field = *(short*)((&data_ov004_0217101c)[globalPointerIndex] + 0x4c);
    short v = (field + 7) / 8;
    SetFields5cAnd5e_021f65b4(a, (void*)0x5b, 0, v);
}
