#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"
#include "std_library_functions.h"

// USA: func_0206f170
ARM int InitEntryListFromSource0206f170(List0206f170* table, Src0206f170* source,
                                      unsigned char* wasRelocated, MonsterDefinitionVisitor relocate) {
    int recordBytes;
    *wasRelocated = 0;
    if (source == NULL) return 0;

    memcpy(&table->table.header, &source->header, sizeof(Header0206f0f8));
    table->table.arr = reinterpret_cast<MonsterDefinition*>(source + 1);
    recordBytes = GetEntryArrayByteSize(&table->table.header);
    table->strings = reinterpret_cast<char*>(source) + (recordBytes + sizeof(Header0206f0f8));
    if (table->table.header.relocated) {
        *wasRelocated = 1;
        return 1;
    }
    InvokeCallbackForEachEntry(table, relocate);
    table->table.header.relocated = 1;
    source->header.relocated = 1;
    return 1;
}
