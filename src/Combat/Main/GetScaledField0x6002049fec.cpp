#include <globaldefs.h>
#include "Graphics/AlphaTween.h"

struct Struct020349c8;

// USA: func_02049fec
ARM float GetScaledField0x6002049fec(char* obj) {
    char* x = *(char**)(obj + 0x13c);
    if (x == NULL) return 0.0f;
    return ((AlphaTween*)((struct Struct020349c8*)(x + 0x60)))->GetTarget();
}
