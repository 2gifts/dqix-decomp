#include <globaldefs.h>
#include "System/ProcessorContext.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7884
bool IsContextInactive(ProcessorContext* context)
{
    return context->blockState == CONTEXT_STATE_INVALID;
}
