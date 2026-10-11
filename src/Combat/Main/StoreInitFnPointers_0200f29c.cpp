#include <globaldefs.h>

#if defined(jpn)
#define __sinit_020e5920 __sinit_020e61fc
#define func_020e5920_dup func_020e61fc_dup
#endif

extern "C" void __sinit_020e5920();
// Second symbol at the SAME address, aliased in symbols.txt. mwcc dedupes two references to
// one symbol into a single literal-pool word; the target has this address in its pool TWICE,
// and only two DISTINCT symbols reproduce that.
extern "C" void func_020e5920_dup();

struct Obj0200f29c { char pad[0xc]; void (*fnC)(void); unsigned int fn10; };

// USA: func_0200f29c
extern "C" ARM int func_0200f29c(struct Obj0200f29c* obj) {
    obj->fnC = __sinit_020e5920;
    obj->fn10 = (unsigned int)func_020e5920_dup;
    return 1;
}
