#include <globaldefs.h>
#include "System/ProcessorContext.h"

#if defined(jpn)
#define data_020f280c data_020f29c8
#define data_020f2800 data_020f29bc
#endif

int ClampInt020d9808(int* value, int* lo, int* hi);

extern int data_020f280c;
extern int data_020f2800;



// USA: func_020d97a8
ARM int ClampAndSubmit020d97a8(ProcessorContext* context, void* stackSpace, unsigned int stackSize,
                             int relativePriority, const void* entry, int userdata) {
    int priority = ClampInt020d9808(&relativePriority, &data_020f280c, &data_020f2800) + 16;
    PopulateContext(context, (unsigned int)entry, userdata,
                    (unsigned int)((char*)stackSpace + stackSize), stackSize, priority);
    return 1;
}
