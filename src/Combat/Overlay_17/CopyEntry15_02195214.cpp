#include <globaldefs.h>

#include "Combat/NameEntryQueue.h"

// USA: func_ov017_02195214  (semantic: CopyEntry15_02195214)
extern "C" ARM void func_ov017_02195214(Entry15_02195214* dst, Entry15_02195214* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->mid = src->mid;
    dst->e = src->e;
}
