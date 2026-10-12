#include <globaldefs.h>

#if defined(jpn)
#define InitAndDispatch_021fd2b8 func_ov023_021fc5b0
#endif

int GetGlobal02109400(void);

extern "C" void func_02094ab0(int val);
extern "C" void _Z21BlankFunction02094b40v(int val);
extern "C" void _Z21BlankFunction02094b34v(int val, int f20, int f24, unsigned char f28, unsigned char f29);

struct S_021fd2b8 {
    char pad0[0x20];
    int f20;
    int f24;
    unsigned char f28;
    unsigned char f29;
};

// USA: func_ov023_021fd2b8
#if defined(jpn)
extern "C"
#endif
ARM int InitAndDispatch_021fd2b8(struct S_021fd2b8* s) {
    int val = GetGlobal02109400();
    func_02094ab0(val);
    _Z21BlankFunction02094b40v(val);
    _Z21BlankFunction02094b34v(val, s->f20, s->f24, s->f28, s->f29);
    return 1;
}
