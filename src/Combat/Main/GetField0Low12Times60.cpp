#include <globaldefs.h>

#if defined(jpn)
enum { ELEMENT_STRIDE = 52 };
#else
enum { ELEMENT_STRIDE = 60 };
#endif

struct Field0Low12_02079b94 {
    unsigned int value : 12;
};

// USA: func_02079b94
ARM int GetField0Low12Times60(struct Field0Low12_02079b94* obj) {
    return obj->value * ELEMENT_STRIDE;
}
