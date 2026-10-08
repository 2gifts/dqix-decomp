#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
char* FindUnescapedAngleBracket(char* str);
extern "C" int _Z26StringStartsWithCI020d85dcPKcS0_(const char* str, const char* prefix);
extern "C" char* _Z26JoinDelimitedParts02068e1cPcS_S_S_(char* dst, char* first, char* second, char* third);
extern "C" ARM void _Z29BuildStatusListString02068ea0PaPc(signed char* ids, char* dest);

extern char data_020e833c[];
extern char data_020f08ff[];

struct Entry02068f40 {
    signed char ids0[4];
    signed char ids1[4];
    signed char ids2[4];
    signed char ids3[4];
    int (*fn)(void*, void*, int);
};

// USA: func_02068f40
extern "C" ARM int func_02068f40(void* obj, char* p, char* out, int flag) {
    char b0[0x30];
    char b1[0x30];
    char b2[0x30];
    char b3[0x30];
    void* gs = _ZN9GameState11GetInstanceEv();
    for (;;) {
        char c = *p;
        if (c == 0) {
            break;
        }
        if (c == '<' && _Z26StringStartsWithCI020d85dcPKcS0_(p, data_020f08ff) != 0
            && FindUnescapedAngleBracket(p) != 0) {
            char* start = p;
            Entry02068f40* e = (Entry02068f40*)data_020e833c;
            while (e->fn != 0) {
                __clear(b0, 0x30);
                _Z29BuildStatusListString02068ea0PaPc(e->ids0, b0);
                if (_Z26StringStartsWithCI020d85dcPKcS0_(p, b0) != 0) {
                    int k = e->fn(gs, obj, flag);
                    __clear(b1, 0x30);
                    __clear(b2, 0x30);
                    __clear(b3, 0x30);
                    _Z29BuildStatusListString02068ea0PaPc(e->ids1, b1);
                    _Z29BuildStatusListString02068ea0PaPc(e->ids2, b2);
                    _Z29BuildStatusListString02068ea0PaPc(e->ids3, b3);
                    switch (k) {
                    case 0:
                        p = _Z26JoinDelimitedParts02068e1cPcS_S_S_(p, b0, b1, b3);
                        break;
                    case 1:
                        if (b2[0] != 0) {
                            p = _Z26JoinDelimitedParts02068e1cPcS_S_S_(p, b1, b2, b3);
                        } else {
                            p = _Z26JoinDelimitedParts02068e1cPcS_S_S_(p, b1, b3, b3);
                        }
                        break;
                    case 2:
                        p = _Z26JoinDelimitedParts02068e1cPcS_S_S_(p, b2, b3, b3);
                        break;
                    default:
                        p = _Z26JoinDelimitedParts02068e1cPcS_S_S_(p, b0, b1, b3);
                        break;
                    }
                    break;
                }
                ++e;
            }
            if (p != start) {
                continue;
            }
        }
        *out++ = c;
        ++p;
    }
    *out = 0;
    return 0;
}