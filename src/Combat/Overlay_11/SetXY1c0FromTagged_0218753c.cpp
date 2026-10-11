#if defined(jpn)
#define R(j,u) (j)
#define _Z17SetXY1c0_02184be0Pvss func_ov011_02185ce0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void _Z17SetXY1c0_02184be0Pvss(void* obj, int x, int y);

// USA: func_ov011_0218753c  (semantic: SetXY1c0FromTagged_0218753c)
extern "C" ARM int func_ov011_0218753c(struct TaggedNumber02184c30* a) {
    int x = GetTaggedValueAsInt_02184c30(a);
    int y = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    _Z17SetXY1c0_02184be0Pvss(func_ov017_021b2164(), x, y);
    return 1;
}
