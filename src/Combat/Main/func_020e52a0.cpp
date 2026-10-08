#include <globaldefs.h>

struct Entry020e52a0 {
    char pad00[0xc];
    unsigned short key;
    char pad0e[2];
};

struct Header020e52a0 {
    unsigned int count : 12;
    unsigned int pad1 : 4;
    struct Entry020e52a0* entries;
};

extern "C" extern unsigned short _Z11GetU16At0xcPh(unsigned char* obj);

// USA: func_020e52a0
extern "C" ARM void* func_020e52a0(void* arr, int key) {
    struct Entry020e52a0* table;
    struct Entry020e52a0* res;
    int count, mid, hi, lo, k;
    if (arr == 0) {
        return 0;
    }
    table = ((struct Header020e52a0*)arr)->entries;
    if (table == 0 || (void*)_Z11GetU16At0xcPh == 0) {
        res = 0;
        goto found;
    }
    count = ((struct Header020e52a0*)arr)->count;
    if (count == 0) {
        res = 0;
        goto found;
    }
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        mid = lo + ((hi - lo + 1) >> 1);
        res = &table[mid];
        k = _Z11GetU16At0xcPh((unsigned char*)res);
        if (k == key) {
            goto found;
        }
        if (k > key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    res = 0;
found:
    return res ? res : 0;
}