#include <globaldefs.h>

struct Inner0218d618 { char pad[0x10]; int f10; };
struct Struct0218d618 { char pad[
#if defined(jpn)
0x41e8
#else
0x4498
#endif
]; Inner0218d618* f498; };

// USA: func_ov017_0218d618
ARM int IsField10Eq2_0218d618(Struct0218d618* p) {
    Inner0218d618* q = p->f498;
    if (q == NULL) goto ret0;
    if (q->f10 == 2) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
