#include <globaldefs.h>

struct MatchState_0200e984 {
    unsigned int discriminator;
    unsigned char* pattern;
};

// USA: func_0200eff0
extern "C" ARM int func_0200eff0(const unsigned char* text, const unsigned char* pattern, MatchState_0200e984* state) {
    const unsigned char* cursor = pattern;
    state->discriminator = 0;
    if (!pattern) return 1;
    if (*cursor == 'P') {
        ++cursor;
        if (*cursor == 'V') ++cursor;
        if (*cursor == 'K') ++cursor;
        if (*cursor == 'v' && (*text == 'P' || *text == '*')) return 1;
        cursor = pattern;
    }
    if (*text == '!' || *text == '*') {
        if (*text++ != *cursor++) return 0;
        for (;;) {
            for (;;) {
                unsigned int current = *text;
                if (current != *cursor++) break;
                ++text;
                if (current == '!') {
                    unsigned int discriminator = 0;
                    if (*text != '!') {
                        do {
                            discriminator = discriminator * 10 + *text++ - '0';
                        } while (*text != '!');
                    }
                    state->discriminator = discriminator;
                    return 1;
                }
            }
            while (*text++ != '!') {}
            while (*text++ != '!') {}
            if (!*text) return 0;
            cursor = pattern + 1;
        }
    }
    while ((*text == 'P' || *text == 'R') && *text == *cursor) {
        ++cursor;
        ++text;
        if (*cursor == 'K') {
            if (*text == 'K') ++text;
            ++cursor;
        }
        if (*text == 'K') return 0;
        const unsigned char* next = text;
        if (*cursor == 'V') {
            if (*next == 'V') ++next;
            ++cursor;
        }
        if (*next == 'V') return 0;
        text = next;
    }
    if (*text == *cursor) do {
        if (!*text) return 1;
    } while (*++text == *++cursor);
    return 0;
}
