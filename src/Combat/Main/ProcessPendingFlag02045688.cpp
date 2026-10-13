#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

void ForwardToTargetOrDefault0205eabc(void*, void*, int);
extern int data_02108760;
extern int data_02107820;

// USA: func_02045688
ARM void ProcessPendingFlag02045688(MessageSystem* window) {
    if (window->b19b3 && window->b19b2) {
        ForwardToTargetOrDefault0205eabc(&data_02108760, &data_02107820, 0);
        window->b19b3 = 0;
    }
}
