#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0204a4ac(void*);

// USA: func_0204a464
ARM void SetStringField0234_0204a464(char* obj, const char* src) {
    strcpy(obj + 0x234, src);
    *(int*)(obj + 0x258) = -1;
    func_0204a4ac(obj);
}
