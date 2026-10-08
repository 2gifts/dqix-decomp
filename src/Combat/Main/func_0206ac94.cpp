#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

extern "C" extern bool _Z20IsHighByteFF02044494PvS_(void* obj, void* src);
extern "C" extern bool _Z20IsHighByteFF0206ac6cPvS_(void* base, void* src);
extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int n);
extern "C" extern int _Z12Func0206abf8PvS_(void* obj, void* src);
extern "C" struct Entry0204254c* _Z22FindEntryByKey0204254cii(int key, int tableIdx);

// USA: func_0206ac94
extern "C" ARM int func_0206ac94(void* obj, unsigned short buf, unsigned char* p) {
    unsigned int total;
    unsigned char* q = p;
    if (!q) {
        return 0;
    }
    if (!_Z20IsHighByteFF02044494PvS_(obj, &buf)) {
        return 0;
    }
    total = 0;
    for (;;) {
        if (!*q) {
            break;
        }
        if (_Z20IsHighByteFF0206ac6cPvS_(obj, q)) {
            int step;
            if (!func_02001aec((unsigned char*)&buf, q, 2)) {
                return (int)q;
            }
            step = _Z12Func0206abf8PvS_(obj, q) * 2 + 2;
            q += step;
            total += step;
        } else {
            struct Entry0204254c* e;
            int val = 1;
            e = _Z22FindEntryByKey0204254cii((int)q, *(unsigned char*)((char*)obj + 0x19dc));
            if (e) {
                val = e->field5;
            }
            q += val;
            total += val;
            if (*(unsigned int*)((char*)obj + 0x68) >= total) {
                continue;
            }
            break;
        }
    }
    return 0;
}
