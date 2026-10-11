#include <globaldefs.h>
#if defined(jpn)
enum { kRegionOffset = 0x27a4 };
#else
enum { kRegionOffset = 0x2a04 };
#endif


struct Region02010834 {
    unsigned char pad[0xf78];
    unsigned char arr[4];
    unsigned char count;
};

struct Base02010834 {
    unsigned char pad[kRegionOffset];
    struct Region02010834 region;
};

// USA: func_02010834
ARM void CopyCountedBytesToIntArray02010834(struct Base02010834* base, int index, int* out, int* outCount) {
    int valid;
    unsigned char i;
    struct Region02010834* r;
    if (index >= 0 && index <= 3) {
        valid = 1;
    } else {
        valid = 0;
    }
    if (valid == 0) {
        return;
    }
    r = &base->region;
    for (i = 0; i < r->count; i++) {
        out[i] = r->arr[i];
    }
    *outCount = r->count;
}
