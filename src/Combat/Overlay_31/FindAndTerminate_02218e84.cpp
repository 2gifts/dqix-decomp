#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" char* func_ov031_02218e2c(void*, const char*);
extern "C" int func_ov031_0221ac6c(const char*, unsigned int, char*, int);

// USA: func_ov031_02218e84
ARM int FindAndTerminate_02218e84(void* self, int key, char* buffer, int size) {
    char* found = func_ov031_02218e2c(self, (const char*)key);
    if (found == NULL) return 0;
    int result = func_ov031_0221ac6c(found, strlen(found), buffer, size);
    if (result == -1 || (unsigned int)result >= (unsigned int)size) return result;
    buffer[result] = 0;
    return result;
}
