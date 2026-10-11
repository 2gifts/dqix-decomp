#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int _Z19GetFieldPtrAt0x5ca4Pv(unsigned int);
extern "C" unsigned int _Z22ResetBigStruct02013750Pvi(unsigned int, unsigned int);
extern "C" unsigned int _Z26CopyInternalFields0207df50P11Foo0207df50(unsigned int);
extern "C" unsigned int _ZN13SafeAllocator5ResetEv(unsigned int);
extern "C" unsigned int _ZN13SafeAllocator7DestroyEv(unsigned int);
extern "C" unsigned int func_02012fe4();

// USA: func_ov001_02163c60  (semantic: Trans_02163c60)
extern "C" ARM unsigned int func_ov001_02163c60(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
#if defined(jpn)
    enum { allocatorOffset = 0x6c, copyFieldsOffset = 0x70 };
#else
    enum { allocatorOffset = 0x4c, copyFieldsOffset = 0x50 };
#endif
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r0 = (unsigned int)GameState::GetInstance();
    r4 = r0;
    r0 = (unsigned int)func_02012fe4();
    r5 = r0;
    r0 = r4;
    r0 = (unsigned int)_Z19GetFieldPtrAt0x5ca4Pv(r0);
    r4 = r0;
    r6 = *(unsigned int*)((char*)r4 + 0x0);
    cc = (int)(r6) - (int)(0x0);
    if (cc == 0) { goto L48; }
    r0 = r6;
    r1 = 0x1;
    r0 = (unsigned int)_Z22ResetBigStruct02013750Pvi(r0, r1);
    r0 = *(unsigned int*)((char*)r6 + allocatorOffset);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L48; }
    r0 = (unsigned int)_ZN13SafeAllocator7DestroyEv(r0);
L48:;
    r0 = 0x0;
    *(unsigned int*)((char*)r4 + 0x0) = (unsigned int)r0;
    r0 = *(unsigned int*)((char*)r5 + allocatorOffset);
    r4 = *(unsigned int*)((char*)r5 + copyFieldsOffset);
    r0 = (unsigned int)_ZN13SafeAllocator5ResetEv(r0);
    r0 = r4;
    r0 = (unsigned int)_Z26CopyInternalFields0207df50P11Foo0207df50(r0);
    r0 = 0x1;
    return r0;
}
