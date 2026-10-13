#include <globaldefs.h>

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern void* data_02108740[];
extern Script::OpcodeLookupEntry data_020f051c[];

// USA: func_0205e104
ARM void RunBufferedStream0205e104(char* zoneParameters, SafeAllocator* allocator, const void* buffer, unsigned int length) {
    Script script;
    if (zoneParameters && buffer && length) {
        data_02108740[1] = zoneParameters;
        data_02108740[0] = allocator;
        script.Initialize();
        script.SetOpcodeLookup(data_020f051c);
        script.Load(buffer, length);
        script.Execute();
    }
}
