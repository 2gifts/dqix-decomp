#include <globaldefs.h>
#include "std_library_functions.h"

struct PatternSyntax0218a518 {
    unsigned char field_0[0x2a];
    unsigned char digit;
    unsigned char groupStart;
    unsigned char groupEnd;
    unsigned char repeatStart;
    unsigned char repeatEnd;
    unsigned char negate;
    unsigned char range;
    unsigned char wildcard;
};
extern "C" int _Z24FindByteInBuffer0218a888iPhii(int, unsigned char*, int, int);

// USA: func_ov009_0218a518
extern "C" ARM int func_ov009_0218a518(PatternSyntax0218a518* syntax, const unsigned char* pattern, const unsigned char* input, int unused, int count) {
    int digit = syntax->digit;
    int groupStart = syntax->groupStart;
    int groupEnd = syntax->groupEnd;
    int repeatStart = syntax->repeatStart;
    int repeatEnd = syntax->repeatEnd;
    int wildcard = syntax->wildcard;
    for (int start = 0; start < count; ++start, ++input) {
        const unsigned char* token = pattern;
        const unsigned char* text = input;
        while (1) {
            unsigned char code = *token;
            if (!code) return 1;
            unsigned int current = *text;
            int length;
            int minimum = 1;
            int maximum = minimum;
            const unsigned char* quantifier = token;
            if (code == groupStart) {
                while (1) {
                    if (*quantifier == groupEnd) { ++quantifier; break; }
                    ++quantifier;
                }
            } else quantifier = token + 1;
            if (*quantifier == repeatStart) {
                minimum = quantifier[1] - 8;
                maximum = quantifier[3] - 8;
                if (quantifier[4] - 8 == 0) maximum *= 10;
            }
            int matches = 1;
            if (code == wildcard) {
                if (minimum == 0 && maximum == 60) {
                    int terminator = token[7];
                    while (1) {
                        if (!*text || *text == 0xff) return 0;
                        if (terminator == *text) break;
                        ++text;
                    }
                    token += 8;
                    ++text;
                    continue;
                }
            } else if (code == digit) {
                if (current < 0x12 || current > 0x2b) matches = 0;
            } else if (code == groupStart) {
                unsigned char members[8] = {};
                int hasRange = 0;
                const unsigned char* source;
                unsigned char* destination = members;
                source = token + 1;
                length = 0;
                int range;
                int negate;
                int end;
                end = syntax->groupEnd;
                negate = syntax->negate;
                range = syntax->range;
                int value;
                while ((value = *source, value != end)) {
                    *destination = value;
                    if (value == negate) length = 2;
                    if (value == range) hasRange = 1;
                    ++source;
                    ++destination;
                }
                hasRange += length;
                length = strlen((char*)members);
                if (hasRange == 0) matches = _Z24FindByteInBuffer0218a888iPhii((int)syntax, members, length, current);
                else if (hasRange == 1) {
                    unsigned int last = members[length - 1];
                    matches = members[0] <= current && current <= last;
                }
                else if (hasRange == 2) matches = !_Z24FindByteInBuffer0218a888iPhii((int)syntax, members + 1, length - 1, current);
                else if (hasRange == 3) {
                    unsigned int last = (members + 1)[length - 2];
                    matches = !((members + 1)[0] <= current && current <= last);
                }
                token += length + 1;
            } else if (code != current) matches = 0;
            if (matches) {
                for (int matched = 0; matched < minimum; ++matched, ++text) {
                    if (current != *text) { matches = 0; break; }
                }
                if (!matches) break;
                while (minimum < maximum) {
                    if (current != *text) break;
                    ++minimum;
                    ++text;
                }
            } else if (!matches && minimum != 0) break;
            ++token;
            if (*token == repeatStart) {
                while (1) {
                    if (*token == repeatEnd) break;
                    ++token;
                }
                ++token;
            }
        }
    }
    return 0;
}

