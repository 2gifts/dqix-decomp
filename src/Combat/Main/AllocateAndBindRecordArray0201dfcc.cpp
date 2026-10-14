#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct SetFieldsStruct;
extern "C" void _ZN12ZoneFeatures21SetOpcode7bAllocationEPNS_13Opcode7bEntryEt(struct SetFieldsStruct* p, int value, short id);
typedef void (*SetFields0x84And0x82_U)(struct SetFieldsStruct*, int, unsigned short);

struct GlobalCtx0201dfcc {
    int field0;
    SafeAllocator* alloc;
    struct SetFieldsStruct* fields;
};
extern struct GlobalCtx0201dfcc data_020fdc20;

// USA: func_0201dfcc
ARM int WarpScript_Opcode_7b(Script::Parameter* arg0, int) {
    struct Variant02030b0c* variant = (struct Variant02030b0c*)arg0;
    unsigned int count = ((Script::Parameter*)variant)->ToInt();
    void* p = data_020fdc20.alloc->Allocate(count * 0x2c);
    if (p == NULL) return 0;
    ((SetFields0x84And0x82_U)_ZN12ZoneFeatures21SetOpcode7bAllocationEPNS_13Opcode7bEntryEt)(data_020fdc20.fields, (int)p, count);
    return 1;
}
