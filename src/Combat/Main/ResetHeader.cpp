#include <globaldefs.h>

struct HeaderStruct {
    int w0;
    unsigned short h4;
    unsigned short h6;
    unsigned short h8;
};

// USA: func_0203e624
ARM void ResetHeader_0203e624(struct HeaderStruct* s) {
    s->w0 = 0;
    s->h4 = 0;
    s->h6 = 0;
    s->h8 = 0;
}
