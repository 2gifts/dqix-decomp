#include <globaldefs.h>
#include "System/ProcessorContext.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7b38  (semantic: Synth_020c7b38)
ARM unsigned int GetContextPriority(ProcessorContext* p) {
    return p->priority;
}
