#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

extern bool IsHighByteFF02044494(void* obj, void* src);
extern bool IsHighByteFF0206ac6c(void* base, void* src);
extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int n);
extern int Func0206abf8(void* obj, void* src);
struct Entry0204254c* FindEntryByKey0204254c(int key, int tableIdx);

// USA: func_0206ac94
extern "C" ARM int func_0206ac94(void* obj, unsigned short buf, unsigned char* p) {
    unsigned int total;
    unsigned char* q = p;
    if (!q) {
        return 0;
    }
    if (!IsHighByteFF02044494(obj, &buf)) {
        return 0;
    }
    total = 0;
    for (;;) {
        if (!*q) {
            break;
        }
        if (IsHighByteFF0206ac6c(obj, q)) {
            int step;
            if (!func_02001aec((unsigned char*)&buf, q, 2)) {
                return (int)q;
            }
            step = Func0206abf8(obj, q) * 2 + 2;
            q += step;
            total += step;
        } else {
            struct Entry0204254c* e;
            int val = 1;
            e = FindEntryByKey0204254c((int)q, *(unsigned char*)((char*)obj + 0x19dc));
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
