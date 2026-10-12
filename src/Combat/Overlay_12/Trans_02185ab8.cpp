#include <globaldefs.h>

#if defined(jpn)
enum { kContainerOffsetInBlock = 0x10c, kActiveOffsetInBlock = 0x341, kEntriesOffset = 0x90 };
#else
enum { kContainerOffsetInBlock = 0x128, kActiveOffsetInBlock = 0x371, kEntriesOffset = 0xac };
#endif


#if defined(jpn)
#define func_ov012_02185ab8 func_ov012_02186118
#endif

struct Obj0205d2bc;
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(Obj0205d2bc*);
struct Container021e76a8;
extern "C" void _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(Container021e76a8*);
extern "C" unsigned int func_ov023_021e6b8c(unsigned int);

// USA: func_ov012_02185ab8  (semantic: Trans_02185ab8)
extern "C" ARM void func_ov012_02185ab8(void* object) {
    int cc = 0;
    unsigned int r0 = (unsigned int)object;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = r4 + kContainerOffsetInBlock;
    r0 = r0 + 0xc00;
    _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8((Container021e76a8*)r0);
    r0 = r4 + 0x1000;
    r0 = *(unsigned char*)((char*)r0 + kActiveOffsetInBlock);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L2c; }
    r0 = r4 + kEntriesOffset;
    _Z19InitEntries0205d2bcP11Obj0205d2bc((Obj0205d2bc*)r0);
L2c:;
#if !defined(jpn)
    r0 = r4;
    (void)func_ov023_021e6b8c(r0);
#endif
}
