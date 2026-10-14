#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0204a4ac(void*);

// USA: func_0204a488
ARM void SetStringField0244_0204a488(char* obj, const char* src) {
    strcpy(obj + 0x244, src);
    *(int*)(obj + 0x25c) = -1;
    func_0204a4ac(obj);
}
