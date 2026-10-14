#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { FIELD_OFFSET = 0x4a };
#else
enum { FIELD_OFFSET = 0x2a };
#endif

struct Variant02030b0c;

extern void* data_02108740[];

// USA: func_0205e03c
ARM int StoreVariantToField0x2a_0205e03c(struct Variant02030b0c* p) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(p);
    *(short*)((char*)data_02108740[1] + FIELD_OFFSET) = parameters[0].ToInt();
    return 1;
}
