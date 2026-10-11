#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Obj020941b0 {
    #if defined(jpn)
    char pad0[0x100];
#else
    char pad0[0x340];
#endif
    int handle;
    #if defined(jpn)
    char pad1[0x138 - 0x104];
#else
    char pad1[0x3c8 - 0x344];
#endif
    unsigned char flags3c8;
    char pad2[0x3cd - 0x3c9];
    unsigned char nibbleLo : 4;
    unsigned char nibbleHi : 4;
};

// JPN: func_02094ac4
// USA: func_020941b0
ARM void ReleaseHandleAndClearFlags(struct Obj020941b0* p) {
    int x = (int)BackgroundLoader::GetInstance();
    if (p->handle >= 0) {
        ((BackgroundLoader*)(x))->RemoveTask((int)(p->handle));
        p->handle = -1;
    }
    p->flags3c8 &= ~0x7f;
    p->nibbleLo = 0;
    #if defined(jpn)
    ((unsigned char*)p)[0x13d] |= 8;
#else
    ((unsigned char*)p)[0x3cd] |= 8;
#endif
}
