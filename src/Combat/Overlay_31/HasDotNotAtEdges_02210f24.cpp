#include <globaldefs.h>

int StringLength_020d2ff0(const char* s);

// USA: func_ov031_02210f24  (semantic: HasDotNotAtEdges_02210f24)
extern "C" ARM int func_ov031_02210f24(const char* s) {
    if (s != NULL) {
        int len = StringLength_020d2ff0(s);
        if (len > 2) {
            if (len <= 0x40) {
                int end = len - 1;
                int i = 1;
                if (end > 1) {
                    do {
                        if (s[i] == '.') {
                            return 1;
                        }
                        i++;
                    } while (i < end);
                }
            }
        }
    }
    return 0;
}
