#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern "C" void func_020729b4(int a, int b, int c);

struct Data02108db0 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    int f8;
    int fc;
    int f10;
};

extern struct Data02108db0 data_02108db0;

// USA: func_02072628
ARM int SubmitVariantU16Filtered(struct Variant02030b0c* p) {
    unsigned short v = (unsigned short)((Script::Parameter*)p)->ToInt();
    if (data_02108db0.f4 != 0) return 1;
    if (data_02108db0.f8 != 0 && data_02108db0.f2 != 0) v = data_02108db0.f2;
    func_020729b4(data_02108db0.f10, data_02108db0.fc, v);
    return 1;
}
