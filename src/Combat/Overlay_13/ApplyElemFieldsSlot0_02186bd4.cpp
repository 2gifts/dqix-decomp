#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02186bd4 func_ov013_02187f00
#endif
#include "std_library_functions.h"

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);
extern "C" void func_ov013_02185424(void*, void*);

// USA: func_ov013_02186bd4  (semantic: ApplyElemFieldsSlot0_02186bd4)
extern "C" ARM void func_ov013_02186bd4(void* obj) {
    memset(*(void**)((char*)obj + 0x658), 0, 0x960);
    func_ov013_02185424(obj, *(void**)((char*)obj + 0x658));
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x38), 0, *(int*)((char*)obj + 0x658), 1, 0);
}
