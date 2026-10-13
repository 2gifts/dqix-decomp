#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/MonsterDefinition.h"

char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* source);

extern BinarySearchByComparatorStruct* data_02108d14;

// USA: func_0206f230
extern "C" ARM void func_0206f230(struct BinarySearchByComparatorStruct* output, SafeAllocator* allocator,
#if defined(jpn)
                                          struct Src0206f170* source, int sourceSize, short* requestedIds, int requestedCount) {
#else
                                          struct Src0206f170* source, int sourceSize, short* requestedIds, int requestedCount,
                                          SafeAllocator* textAllocator, unsigned char* storagePadding) {
#endif
    short* requestedId;
    int request;
    bool isNew;
    int copiedCount;
    unsigned char wasRelocated;
    struct List0206f170 sourceTable;
    short selectedIds[0x200];
    short selectedCount;
    int position;
    struct MonsterDefinition* destination;
    short* selectedId;
    short id;
    short* insertion;
    int selected;
    struct MonsterDefinition* definition;

    data_02108d14 = output;
    if (requestedCount == 0) {
        return;
    }
    wasRelocated = 0;
    InitEntryListFromSource0206f170(&sourceTable, source, &wasRelocated, RelocateThreeFields);
    selectedCount = 0;
    for (requestedId = requestedIds, request = 0; request < requestedCount; request++, requestedId++) {
        id = *requestedId;
        if (BinarySearchByComparator(&sourceTable.table, id,
                                     GetShortAt0x8) != NULL) {
            insertion = selectedIds;
            isNew = true;
            for (position = 0; position < selectedCount; position++, insertion++) {
                if (*insertion == id) {
                    isNew = false;
                    break;
                }
                if (*insertion > id) {
                    memmove(insertion + 1, insertion, (selectedCount - position) * sizeof(short));
                    break;
                }
            }
            if (isNew) {
                *insertion = id;
                selectedCount = selectedCount + 1;
                if (selectedCount >= 0x200) {
                    break;
                }
            }
        }
    }

    output->arr = (struct MonsterDefinition*)allocator->Allocate(selectedCount * sizeof(struct MonsterDefinition));
    if (output->arr == NULL) {
        return;
    }
#if !defined(jpn)
    if (textAllocator != NULL && storagePadding != NULL) {
        allocator->Allocate(0x80 - selectedCount * 8);
    }
#endif

    copiedCount = 0;
    destination = output->arr;
    for (selectedId = selectedIds, selected = 0; selected < selectedCount; selected++, selectedId++) {
        definition = (struct MonsterDefinition*)BinarySearchByComparator(
            &sourceTable.table, *selectedId, GetShortAt0x8);
        if (definition == NULL) {
            continue;
        }
        memcpy(destination, definition, sizeof(struct MonsterDefinition));
#if defined(jpn)
        destination->name = AllocateStringCopy020da150(allocator, definition->name);
#else
        if (textAllocator != NULL && storagePadding != NULL) {
            destination->name = AllocateStringCopy020da150(textAllocator, definition->name);
            destination->localizedText = AllocateStringCopy020da150(textAllocator, definition->localizedText);
            allocator->Allocate(storagePadding[selected]);
        } else {
            destination->name = AllocateStringCopy020da150(allocator, definition->name);
            destination->localizedText = AllocateStringCopy020da150(allocator, definition->localizedText);
        }
#endif
        destination->modelName = AllocateStringCopy020da150(allocator, definition->modelName);
        destination++;
        copiedCount = (short)(copiedCount + 1);
    }
    output->header.count = copiedCount;
}
