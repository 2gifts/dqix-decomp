#include <globaldefs.h>

#if defined(jpn)
enum { entrySize = 0x488 };
#else
enum { entrySize = 0x448 };
#endif

// USA: func_ov000_02161318  (semantic: FindElementByIdField_02161318)
extern "C" ARM void* func_ov000_02161318(void* obj, int id) {
    int valid = (id >= 0 && id <= 3) ? 1 : 0;
    if (valid) {
        for (int i = 0; i < 4; i++) {
            int cur = *(int*)((char*)obj + i * entrySize + 0x9a4);
            if (id == cur) {
                return (char*)obj + 0x958 + i * entrySize;
            }
        }
    }
    return 0;
}
