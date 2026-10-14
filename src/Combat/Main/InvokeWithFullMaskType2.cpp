#include <globaldefs.h>
#include "System/RequestSubmission.h"

// USA: func_020d68b4
ARM int InvokeWithFullMaskType2_020d68b4(void* request, int port) {
    return func_020d5d34(request, port, 0xffff, 2, 1);
}
