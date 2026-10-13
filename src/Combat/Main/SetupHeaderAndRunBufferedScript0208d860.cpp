// KEEP-NAME
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/ScriptElementList.h"

#if defined(jpn)
#define data_020f121c data_020f12ec
#endif

extern Script::OpcodeLookupEntry data_020f121c[];

// USA: func_0208d860
// JPN: func_0208e11c
ARM void SetupHeaderAndRunBufferedScript0208d860(StreamHeader0208d860* header, SafeAllocator* allocator,
                                                const void* bytecode, unsigned int length,
                                                const short* selectedIds, short selectedCount,
                                                unsigned short flags) {
    if (allocator != NULL && bytecode != NULL && length != 0) {
        data_02108fc0.header = header;
        data_02108fc0.header->selectedIds = selectedIds;
        data_02108fc0.header->selectedCount = selectedCount;
        data_02108fc0.header->flags = flags;
        data_02108fc0.allocator = allocator;
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(data_020f121c);
        script.Load(bytecode, length);
        script.Execute();
    }
}
