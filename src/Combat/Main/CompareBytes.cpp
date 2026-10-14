#include <globaldefs.h>

// USA: func_020d3044
ARM int CompareBytes_020d3044(const unsigned char* a, const unsigned char* b, int n) {
    int i;
    if (n != 0) {
        i = 0;
        if (i < n) {
            do {
                unsigned char ca = a[i];
                unsigned char cb = b[i];
                if (ca != cb) return ca - cb;
                i++;
            } while (i < n);
        }
    }
    return 0;
}
