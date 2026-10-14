#include <globaldefs.h>

// USA: func_020d2f88
ARM char* FindSubstring_020d2f88(char* haystack, char* needle) {
    int matchLen;
    char* cursor;
    char needleChar;
    int start;
    start = 0;
    if (haystack[start] != 0) {
        do {
            cursor = haystack + start;
            matchLen = 0;
            while ((needleChar = needle[matchLen]) != 0 && *cursor == needleChar) {
                cursor++;
                matchLen++;
            }
            if (needleChar == 0) {
                return haystack + start;
            }
            start++;
        } while (haystack[start] != 0);
    }
    return 0;
}
