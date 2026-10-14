#include <globaldefs.h>

extern "C" int func_0206b37c(void* obj, void* p);
int IsHighByteFF0206ac6c(void* obj, void* p);
bool IsCommandInRange02067a9c(void* obj, void* p);
int IsHalfwordInRange02067ad8(int unused, void* p);
int Func0206abf8(void* a, void* p);

struct Entry0204254c {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct Entry0204254c* FindEntryByKey0204254c(int key, int tableIdx);

// USA: func_0206b528
extern "C" ARM int func_0206b528(unsigned char* obj, int* outA, int* outB) {
    unsigned char* buf = *(unsigned char**)(obj + 0x50);
    int start = *(int*)(obj + 0x84);
    int base = *(int*)(obj + 0x990);
    int i;
    unsigned char* p = buf + start;

    outA[0] = base - (func_0206b37c(obj, p) >> 1);
    outB[0] = 0;
    i = 1;

    for (;;) {
        signed char c = *(signed char*)p;
        if (c == 0) return c;
        if (IsHighByteFF0206ac6c(obj, p)) {
            bool stop = IsCommandInRange02067a9c(obj, p);
            if (stop) return stop;
            if (IsHalfwordInRange02067ad8((int)obj, p)) {
                p += 2;
                outA[i] = base - (func_0206b37c(obj, p) >> 1);
                outB[i] = 0;
                i++;
            } else {
                p = (p + 2) + Func0206abf8(obj, p) * 2;
                goto again;
            }
        } else {
            int adv = 1;
            struct Entry0204254c* e = FindEntryByKey0204254c((int)p, (obj + 0x1000)[0x9dc]);
            if (e) adv = e->field5;
            p += adv;
        }
    again: ;
    }
}
