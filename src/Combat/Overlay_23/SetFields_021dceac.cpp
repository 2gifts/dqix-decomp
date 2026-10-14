#include <globaldefs.h>

struct StatusTextRows021dceac {
#if defined(jpn)
    char padding[0x700];
#else
    char padding[0x784];
#endif
    const char* names[3];
    unsigned char quantities[3];
    unsigned char limits[3];
    unsigned char costs[3];
};

// USA: func_ov023_021dceac
ARM void SetFields_021dceac(char* obj, int idx, int val, unsigned char b1, unsigned char b2, unsigned char b3) {
    StatusTextRows021dceac* rows = (StatusTextRows021dceac*)obj;
    rows->names[idx] = (const char*)val;
    rows->quantities[idx] = b1;
    rows->limits[idx] = b2;
    rows->costs[idx] = b3;
}
