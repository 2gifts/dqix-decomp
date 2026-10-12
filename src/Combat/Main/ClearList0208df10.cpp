#include <globaldefs.h>

struct List0208df10 {
    void* base;
    short count;
};

#if defined(jpn)
#define ClearList0208df10 func_0208e818
extern "C" ARM void func_0208e818(struct List0208df10 *l);
#endif

// USA: func_0208df10
ARM void ClearList0208df10(struct List0208df10 *l) {
    l->base = NULL;
    l->count = 0;
}
