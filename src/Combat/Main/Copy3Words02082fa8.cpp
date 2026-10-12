#include <globaldefs.h>
struct Words02082fa8 { unsigned int a, b, c; };
#if defined(jpn)
#define Copy3Words02082fa8 func_02083914
extern "C" ARM void Copy3Words02082fa8(struct Words02082fa8* dst, struct Words02082fa8* src);
#endif

// USA: func_02082fa8
ARM void Copy3Words02082fa8(struct Words02082fa8* dst, struct Words02082fa8* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}
