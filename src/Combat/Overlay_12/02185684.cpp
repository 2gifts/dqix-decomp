#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void* __clear(void*, int);
int FindByteInString_021859f4(void*, unsigned char*, int, int);

// USA: func_ov012_02185684
extern "C" ARM int func_ov012_02185684(void* owner, unsigned char* pattern,
    unsigned char* text, int unused, int limit) {
    unsigned char* markers = static_cast<unsigned char*>(owner);
    unsigned int any;
    unsigned int open;
    unsigned int close;
    unsigned int repeatOpen;
    unsigned int repeatClose;
    unsigned int special;
    int offset;
    any = markers[0x2a];
    open = markers[0x2b];
    close = markers[0x2c];
    repeatOpen = markers[0x2d];
    repeatClose = markers[0x2e];
    special = markers[0x31];
    offset = 0;
    while (offset < limit) {
        unsigned char* p = pattern;
        unsigned char* q = text;
        for (;;) {
            int token = *p;
            if (token == 0) return 1;
            unsigned int current;
            int length;
            int minimum = 1;
            current = *q;
            int maximum = minimum;
            unsigned char* next = p;
            if (token == open) {
                for (;;) {
                    if (*next == close) { ++next; break; }
                    ++next;
                }
            } else next = p + 1;
            if (*next == repeatOpen) {
                minimum = next[1] - 8;
                maximum = next[3] - 8;
                if (next[4] - 8 == 0) maximum *= 10;
            }
            int matched = 1;
            if (token == special) {
                if (minimum == 0 && maximum == 60) {
                    unsigned int terminator = p[7];
                    for (;;) {
                        unsigned int c = *q;
                        if (c == 0 || c == 0xff) return 0;
                        if (terminator == c) break;
                        ++q;
                    }
                    p += 8;
                    ++q;
                    continue;
                }
            } else if (token == any) {
                if (current < 0x12 || current > 0x2b) matched = 0;
            } else if (token == open) {
                unsigned char group[8];
                __clear(group, sizeof(group));
                int negate = 0;
                unsigned char* src;
                unsigned char* dst;
                dst = group;
                src = p + 1;
                length = negate;
                unsigned int rangeMarker;
                unsigned int negateMarker;
                unsigned int end;
                end = markers[0x2c];
                negateMarker = markers[0x2f];
                rangeMarker = markers[0x30];
                while (*src != end) {
                    unsigned int c = *src;
                    *dst = c;
                    if (c == negateMarker) length = 2;
                    if (c == rangeMarker) negate = 1;
                    ++src;
                    ++dst;
                }
                negate += length;
                length = strlen(reinterpret_cast<char*>(group));
                if (negate == 0)
                    matched = FindByteInString_021859f4(owner, group, length, current);
                else if (negate == 1) {
                    unsigned int low = group[0];
                    unsigned int high = group[length - 1];
                    matched = low <= current && current <= high;
                }
                else if (negate == 2)
                    matched = !FindByteInString_021859f4(owner, group + 1, length - 1, current);
                else if (negate == 3) {
                    unsigned char* ranged = group + 1;
                    unsigned int high = ranged[length - 2];
                    unsigned int low = group[1];
                    matched = !(low <= current && current <= high);
                }
                p += length + 1;
            } else if (token != current) matched = 0;
            if (matched) {
                int n = 0;
                while (n < minimum) {
                    if (current != *q) { matched = 0; break; }
                    ++n;
                    ++q;
                }
                if (!matched) break;
                while (minimum < maximum) {
                    if (current != *q) break;
                    ++minimum;
                    ++q;
                }
            } else if (matched == 0 && minimum != 0) break;
            ++p;
            if (*p == repeatOpen) {
                for (;;) {
                    if (*p != repeatClose) ++p;
                    else break;
                }
                ++p;
            }
        }
        ++offset;
        ++text;
    }
    return 0;
}
