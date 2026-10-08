#include <globaldefs.h>

#include "Combat/ResourceScriptEntry.h"

// USA: func_02082490
extern "C" ARM int func_02082490(void *output, void *resource, unsigned int size, int selection, int extra) {
    ResourceScriptEntry *entry = (ResourceScriptEntry *) output;
    Script script;
    memset(entry, 0, sizeof(*entry));
    data_02108ee8.field10 = 0;
    data_02108ee8.fieldC  = entry;
    data_02108ee8.field4  = extra;
    data_02108ee8.field8  = selection;
    data_02108ee8.field0  = 0;
    script.Initialize();
    script.SetOpcodeLookup(data_020f0ff8);
    script.Load(resource, size);
    script.Execute();
    if (data_02108ee8.field0 != 0) {
        entry->difference.value4Low      = (unsigned short) (entry->final.value4Low - entry->initial.value4Low);
        entry->difference.value0         = entry->final.value0 - entry->initial.value0;
        entry->difference.value8.low     = entry->final.value8.low - entry->initial.value8.low;
        entry->difference.value8.high    = entry->final.value8.high - entry->initial.value8.high;
        entry->difference.value8.middle  = entry->final.value8.middle - entry->initial.value8.middle;
        entry->difference.valueC.low     = entry->final.valueC.low - entry->initial.valueC.low;
        entry->difference.valueC.middle  = entry->final.valueC.middle - entry->initial.valueC.middle;
        entry->difference.value10.low    = entry->final.value10.low - entry->initial.value10.low;
        entry->difference.valueC.high    = entry->final.valueC.high - entry->initial.valueC.high;
        entry->difference.value10.middle = entry->final.value10.middle - entry->initial.value10.middle;
        entry->difference.value10.high   = entry->final.value10.high - entry->initial.value10.high;
        entry->difference.value4High     = (unsigned short) (entry->final.value4High - entry->initial.value4High);
        return entry->final.value4Low;
    }
    return 0;
}
