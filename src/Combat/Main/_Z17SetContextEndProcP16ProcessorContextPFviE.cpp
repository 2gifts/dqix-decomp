#include <globaldefs.h>
#include "System/ProcessorContext.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c7ca8  (semantic: Synth_020c7ca8)
ARM void SetContextEndProc(ProcessorContext* context, ProcessorContext::ExitRoutine proc) {
    context->exitProc = proc;
}
