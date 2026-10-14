#include <globaldefs.h>
#include "Filesystem/NitroVM.h"

int NitroVM_FinishRead(NitroVM*);

// USA: func_020c00b8
ARM void *CallFunc020cca80AtField0x5c_020c00b8(void *obj) {
    return (void*)NitroVM_FinishRead((NitroVM *)((char *)obj + 0x5c));
}
