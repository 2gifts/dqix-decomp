#include <globaldefs.h>

struct Name0215f650 {
#if defined(jpn)
    char str[0x14];
#else
    char str[0x30];
#endif
};

struct Data0215f650 {
    char bytes[6];
};

struct Record0215f650 {
    unsigned char type;
    Name0215f650 name;
    Data0215f650 data;
};

// JPN: func_ov003_0215f854
// USA: func_ov003_0215f650
extern "C" ARM Record0215f650* func_ov003_0215f650(Record0215f650* dst, const Record0215f650* src) {
    dst->type = src->type;
    dst->name = src->name;
    dst->data = src->data;
    return dst;
}
