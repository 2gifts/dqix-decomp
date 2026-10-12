#include <globaldefs.h>

extern "C" unsigned int _Z19InitEntries0205d2bcP11Obj0205d2bc(unsigned int);
extern "C" unsigned int _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(unsigned int);
extern "C" unsigned int func_ov023_021e6b8c(unsigned int);

// USA: func_ov012_02185ab8  (semantic: Trans_02185ab8)
extern "C" ARM unsigned int func_ov012_02185ab8(unsigned int self, unsigned int r1, unsigned int r2, unsigned int r3) {
    _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(self + 0xd28);
    if (*(unsigned char*)(self + 0x1371) != 0) {
        _Z19InitEntries0205d2bcP11Obj0205d2bc(self + 0xac);
    }
    return func_ov023_021e6b8c(self);
}
