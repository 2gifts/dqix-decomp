#include <globaldefs.h>

#if defined(jpn)
enum { ENTRY_STRIDE = 0x14 };
#else
enum { ENTRY_STRIDE = 0x1c };
#endif

struct Header0206f0f8 {
    unsigned int count : 12;
    unsigned int rest : 20;
};

#if defined(jpn)
#define GetEntryArrayByteSize func_02070248
extern "C" ARM int func_02070248(struct Header0206f0f8 *obj);
#endif

// USA: func_0206f0f8
ARM int GetEntryArrayByteSize(struct Header0206f0f8 *obj) {
    return obj->count * ENTRY_STRIDE;
}
