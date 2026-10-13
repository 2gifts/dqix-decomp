#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int _Z19GetFieldPtrAt0x5ca4Pv(unsigned int);
extern "C" unsigned int _Z22ResetBigStruct02013750Pvi(unsigned int, unsigned int);
extern "C" unsigned int _Z26CopyInternalFields0207df50P11Foo0207df50(unsigned int);
extern "C" unsigned int _ZN13SafeAllocator5ResetEv(unsigned int);
extern "C" unsigned int _ZN13SafeAllocator7DestroyEv(unsigned int);
extern "C" unsigned int func_02012fe4();

// USA: func_ov001_02163c60  (semantic: Trans_02163c60)
extern "C" ARM int func_ov001_02163c60(void) {
#if defined(jpn)
    enum { allocatorOffset = 0x6c, copyFieldsOffset = 0x70 };
#else
    enum { allocatorOffset = 0x4c, copyFieldsOffset = 0x50 };
#endif
    unsigned int allocator;
    unsigned int state = (unsigned int)GameState::GetInstance();
    unsigned int grotto = func_02012fe4();
    unsigned int* slot = (unsigned int*)_Z19GetFieldPtrAt0x5ca4Pv(state);
    unsigned int entry = *slot;
    if (entry != 0) {
        _Z22ResetBigStruct02013750Pvi(entry, 1);
        allocator = *(unsigned int*)((char*)entry + allocatorOffset);
        if (allocator != 0) {
            _ZN13SafeAllocator7DestroyEv(allocator);
        }
    }
    *slot = 0;
    allocator = *(unsigned int*)((char*)grotto + allocatorOffset);
    unsigned int fields = *(unsigned int*)((char*)grotto + copyFieldsOffset);
    _ZN13SafeAllocator5ResetEv(allocator);
    _Z26CopyInternalFields0207df50P11Foo0207df50(fields);
    return 1;
}
