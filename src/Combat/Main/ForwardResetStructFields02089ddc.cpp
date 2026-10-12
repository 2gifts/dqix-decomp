#include <globaldefs.h>

struct ResetFieldsStruct;
void ResetStructFields(struct ResetFieldsStruct* s);

#if defined(jpn)
#define ForwardResetStructFields02089ddc func_0208a6d8
extern "C" ARM void func_0208a6d8(struct ResetFieldsStruct* s);
#endif

// USA: func_02089ddc
ARM void ForwardResetStructFields02089ddc(struct ResetFieldsStruct* s) {
    ResetStructFields(s);
}
