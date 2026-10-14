#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/ScriptElementList.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct ElementList0208d8ec;
extern void InitElementList0208d8ec(struct ElementList0208d8ec* obj, SafeAllocator* alloc, int capacity);

// USA: func_0208d550
extern "C" ARM int func_0208d550(struct Variant02030b0c* v) {
    short val = (short)((Script::Parameter*)v)->ToInt();
    if (data_02108fc0.header->selectedCount != 0) {
        InitElementList0208d8ec((struct ElementList0208d8ec*)data_02108fc0.header, data_02108fc0.allocator, data_02108fc0.header->selectedCount);
    } else {
        InitElementList0208d8ec((struct ElementList0208d8ec*)data_02108fc0.header, data_02108fc0.allocator, val);
    }
    return 1;
}
