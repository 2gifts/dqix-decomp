#include <globaldefs.h>

#include "System/ProcessorContext.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7a74
ARM void MarkContextStackTopUnknownSubspace(ProcessorContext *context, unsigned int size) {
    context->stackUnknownTopSubspaceSize = size;
    if (size != 0) {
        *reinterpret_cast<unsigned int *>(context->stackTop + size) = STACK_UNKNOWN_SECTION_MAGIC;
    }
}
