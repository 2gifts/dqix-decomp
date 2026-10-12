#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185424 func_ov013_02186468
#define TryApplyElemFields0205d5d0 _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov013_02186bd4 func_ov013_02187f00
#endif
#include "std_library_functions.h"

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0*, int, int, int, unsigned char);
#endif
extern "C" void func_ov013_02185424(void*, void*);

// USA: func_ov013_02186bd4  (semantic: ApplyElemFieldsSlot0_02186bd4)
extern "C" ARM void func_ov013_02186bd4(void* obj) {
    memset(*(void**)((char*)obj + LOW_REGION(0x5e0, 0x658)), 0, LOW_REGION(0x800, 0x960));
    func_ov013_02185424(obj, *(void**)((char*)obj + LOW_REGION(0x5e0, 0x658)));
#if defined(jpn)
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + LOW_REGION(0x34, 0x38)), 0, *(int*)((char*)obj + LOW_REGION(0x5e0, 0x658)), 1);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + LOW_REGION(0x34, 0x38)), 0, *(int*)((char*)obj + LOW_REGION(0x5e0, 0x658)), 1, 0);
#endif
}
