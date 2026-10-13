#include <globaldefs.h>

// USA: func_ov031_02242f84
extern "C" ARM int func_ov031_02242f84(const signed char* text, int textLength, const signed char* pattern, int patternLength) {
    if (textLength < patternLength) return -1;
    int i = 0;
    int matched;
    const signed char* candidate;
    signed char first;
    int end = textLength - patternLength + 1;
    if (end > 0) {
        first = pattern[0];
        do {
            if (first == text[i]) {
                matched = 1;
                candidate = text;
                candidate += i;
                if (patternLength > 1) do {
                    if (candidate[matched] != pattern[matched]) break;
                    ++matched;
                } while (matched < patternLength);
                if (matched == patternLength) return 0;
            }
            ++i;
        } while (i < end);
    }
    return -1;
}
