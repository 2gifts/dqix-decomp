#include <globaldefs.h>

#if defined(jpn)
struct GlyphKeyRemap {
    signed char character;
    const unsigned char* replacement;
};

extern unsigned char data_020f008a[];
extern unsigned char data_020f008d[];
extern unsigned char data_020f0090[];
extern GlyphKeyRemap data_020e848c[];

// JPN: func_02042ea4
extern "C" ARM void func_02042ea4(unsigned char* output, const unsigned char* input) {
    if (output == NULL) return;
    if (input == NULL) {
        output[0] = 0;
        output[1] = 0;
        return;
    }

    const GlyphKeyRemap* entry;
    int character = (signed char)input[0];
    if (character >= 'A' && character <= 'Z') {
        const unsigned char* const base = data_020f008a;
        int offset = character - 'A';
        output[0] = base[0];
        output[1] = base[1] + offset;
        return;
    }
    if (character >= 'a' && character <= 'z') {
        const unsigned char* const base = data_020f008d;
        int offset = character - 'a';
        output[0] = base[0];
        output[1] = base[1] + offset;
        return;
    }
    if (character >= '0' && character <= '9') {
        const unsigned char* const base = data_020f0090;
        int offset = character - '0';
        output[0] = base[0];
        output[1] = base[1] + offset;
        return;
    }

    entry = data_020e848c;
    for (;;) {
        if (entry->character == 0) break;
        if (character == entry->character) {
            input = entry->replacement;
            break;
        }
        ++entry;
    }
    output[0] = input[0];
    output[1] = input[1];
}
#endif
