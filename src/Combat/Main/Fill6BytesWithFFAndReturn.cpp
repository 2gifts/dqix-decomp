#include <globaldefs.h>

void Fill6BytesWithFF_020a18d4(char* p);

// USA: func_020a1ffc
ARM char* Fill6BytesWithFFAndReturn_020a1ffc(char* p) {
    Fill6BytesWithFF_020a18d4(p);
    return p;
}
