#include <globaldefs.h>
#include "std_library_functions.h"

// KEEP-NAME: the ROM symbol is the mangled C++ name, not a func_ tag.
// USA: func_020757b4

extern char data_020f0dc2[];
extern char* data_020f0da0[];

char* FindSubstring_020d2f88(char* haystack, char* needle);
int StringLength_020d2ff0(const char* s);

char* StringReplaceLanguageTag(const char* src, char* dst, int language) {
    if (src == 0 || dst == 0) {
        return dst;
    }

    char* const tag = data_020f0dc2;
    strcpy(dst, src);
    char* at = FindSubstring_020d2f88(dst, tag);
    char* code = data_020f0da0[language];
    int codeLength = StringLength_020d2ff0(code);
    int shift = StringLength_020d2ff0(code) - StringLength_020d2ff0(tag);

    while (at != 0) {
        if (shift > 0) {
            memmove(at + shift, at, StringLength_020d2ff0(at) + 1);
        } else if (shift < 0) {
            memmove(at, at - shift, shift + StringLength_020d2ff0(at) + 1);
        }
        memmove(at, code, codeLength);
        at = FindSubstring_020d2f88(dst, tag);
    }
    return dst;
}
