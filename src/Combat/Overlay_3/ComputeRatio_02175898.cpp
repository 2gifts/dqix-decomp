#include <globaldefs.h>

int EvalOrDispatch020de194(void* s);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

// USA: func_ov003_02175898
ARM unsigned int ComputeRatio_02175898(char* obj, void* s) {
    if (s == NULL) {
        return 0;
    }
    int v = EvalOrDispatch020de194(s);
#if defined(jpn)
    enum { fieldOffset = 0x7e8 };
#else
    enum { fieldOffset = 0x86c };
#endif
    unsigned short field = *(unsigned short*)(obj + fieldOffset);
    return _u32_div_f(field * v, 100);
}
