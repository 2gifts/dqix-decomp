#include <globaldefs.h>

extern "C" int _Z28LengthUntilDotOrEnd_0220868cPKc(const char*);

// USA: func_ov031_022086b0
extern "C" ARM int func_ov031_022086b0(const char* text, const char* pattern) {
    for (;;) {
        char textCharacter;
        char patternCharacter;
        while ((textCharacter = *text++) == (patternCharacter = *pattern++)) {
            if (textCharacter == 0) return 0;
        }
        if (patternCharacter != '*') return 1;
        text--;
        int textLength = _Z28LengthUntilDotOrEnd_0220868cPKc(text);
        int patternLength = _Z28LengthUntilDotOrEnd_0220868cPKc(pattern);
        if (patternLength > textLength) return 1;
        text += textLength - patternLength;
    }
}
