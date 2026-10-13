#include <globaldefs.h>

// USA: func_ov031_0221d270  (semantic: ValidatePrintable_0221d270)
extern "C" THUMB int func_ov031_0221d270(const unsigned char* text, int count) {
    int i = 0;
    if (i < count) {
        do {
            unsigned char c = *text;
            text++;
            if (c < 0x20 || c > 0x7f) return -1;
            i++;
        } while (i < count);
    }
    return 0;
}
