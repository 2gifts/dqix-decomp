#include <globaldefs.h>

extern "C" void _Z31SelectMatchFnByWildcard020de3f4iiiiPcS_S_PPv(int a, int b, int c, int d, char* outA, char* outB, char* outC, void** outFunc);

typedef int (*MatchFn020deb58)(void*, int, int, int);

struct List020deb58 {
    unsigned short count;
    unsigned short pad2;
    unsigned int pad4;
    unsigned int pad8;
    void* base;
};

struct Entry020deb58 {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int fieldC;
};

// USA: func_020deb58
extern "C" ARM int func_020deb58(void* obj, int arg1, int arg2, int arg3, signed char arg4) {
    char outA = -1;
    char outB = -1;
    char outC = -1;
    void* fn = 0;
    _Z31SelectMatchFnByWildcard020de3f4iiiiPcS_S_PPv(arg1, arg2, arg3, arg4, &outA, &outB, &outC, &fn);
    if (fn == 0) {
        return 0;
    }
    List020deb58* list = (List020deb58*)obj;
    int count = list->count;
    short total = 0;
    char* elem = (char*)list->base;
    int i = total;
    for (; i < count; i++, elem += 0x20) {
        Entry020deb58* e = (Entry020deb58*)elem;
        int bits = (int)((e->fieldC << 9) >> 21);
        bits = (unsigned short)bits;
        if (bits != 0) {
            if (((MatchFn020deb58)fn)(elem, outA, outB, outC) != 0) {
                total = total + 1;
            }
        }
    }
    return total;
}