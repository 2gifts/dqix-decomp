#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);

// USA: func_020d2f28
ARM int CopyStringBounded020d2f28(char* dst, const char* src, int n) {
    int i = 0;
    const char* p = src;
    if (n - 1 > 0) {
        do {
            dst[i] = *p;
            if (*p == 0) break;
            i++;
            p++;
        } while (i < n - 1);
    }
    if (i >= n - 1) {
        if (n != 0) dst[i] = 0;
    }
    return StringLength_020d2ff0(src);
}
