#include <globaldefs.h>

struct HandleFieldC_02097240;

extern "C" short _Z15GetHandleFieldCP21HandleFieldC_02097240(struct HandleFieldC_02097240* obj);

struct Node_02097430 { char pad[0x20]; };

struct Container_02097430 {
    unsigned int pad0;
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Node_02097430* base;
};

extern "C" {
// USA: func_02097430
extern "C" ARM struct Node_02097430* func_02097430(struct Container_02097430* c, int key) {
    int count;
    struct Node_02097430* res;
    int mid;
    int r;
    int hi;
    int lo;
    struct Node_02097430* base;
    if (c->base == NULL || (int)_Z15GetHandleFieldCP21HandleFieldC_02097240 == 0) {
        res = NULL;
        goto out;
    }
    count = c->count;
    if (count == 0) {
        res = NULL;
        goto out;
    }
    hi = count - 1;
    lo = 0;
    base = c->base;
    while (lo <= hi) {
        mid = lo + ((hi - lo + 1) >> 1);
        res = base + mid;
        r = _Z15GetHandleFieldCP21HandleFieldC_02097240((struct HandleFieldC_02097240*)res);
        if (r == key) goto out;
        if (r > key) hi = mid - 1;
        else lo = mid + 1;
    }
    res = NULL;
out:
    return res;
}
}