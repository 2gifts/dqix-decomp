#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

// USA: func_0206f01c
extern "C" ARM void func_0206f01c(List0206f170* table, SafeAllocator* allocator,
                                 Src0206f170* source, unsigned int sourceLength) {
    int recordBytes;
    int stringBytes;
    if (allocator == NULL || source == NULL) return;

    memcpy(&table->table.header, &source->header, sizeof(Header0206f0f8));
    recordBytes = GetEntryArrayByteSize(&table->table.header);
    stringBytes = table->table.header.stringBytes;
    if (recordBytes) {
        table->table.arr = static_cast<MonsterDefinition*>(allocator->Allocate(recordBytes));
    } else {
        table->table.arr = NULL;
    }
    table->strings = stringBytes ? static_cast<char*>(allocator->Allocate(stringBytes)) : NULL;
    if (table->table.arr != NULL) {
        memcpy(table->table.arr, source + 1, recordBytes);
    }
    if (table->strings != NULL) {
        memcpy(table->strings, reinterpret_cast<char*>(source) +
               (GetEntryArrayByteSize(&table->table.header) + sizeof(Header0206f0f8)), stringBytes);
    }

    if (reinterpret_cast<void*>(RelocateThreeFields_0206ef48) != NULL) {
        InvokeCallbackForEachEntry_0206f110(table, RelocateThreeFields_0206ef48);
    }
    table->table.header.relocated = 1;
}
