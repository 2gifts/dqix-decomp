#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kTokenBase = 0xff22 };
#else
enum { kTokenBase = 0xff20 };
#endif

#if defined(jpn)
extern "C" ARM int func_02069444(void* obj, unsigned short buf) {
    int result = 0;
    if (!func_02069430(obj, buf)) return 0;
#else
// USA: func_02044420
ARM int Dispatch02044420(void* obj, void* src) {
    unsigned short buf;
    int result = 0;
    memcpy(&buf, src, 2);
    if (!IsHighByteFF02044494(obj, &buf)) {
        return 0;
    }
#endif
    switch (buf) {
    case kTokenBase + 0:
    case kTokenBase + 1:
    case kTokenBase + 3:
    case kTokenBase + 4:
        result = 1;
        break;
    case kTokenBase + 2:
    case kTokenBase + 5:
        result = 2;
        break;
    }
    return result;
}
