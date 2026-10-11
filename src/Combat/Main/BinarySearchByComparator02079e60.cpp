#include <globaldefs.h>
#if defined(jpn)
enum { kElementStride = 52 };
#else
enum { kElementStride = 60 };
#endif


typedef int (*CmpFn02079e60)(void*);

struct Obj02079e60 {
    unsigned int count : 12;
    char* arr;
};

// USA: func_02079e60
ARM void* BinarySearchByComparator02079e60(struct Obj02079e60* obj, int key, CmpFn02079e60 cmp) {
    char* arr = obj->arr;
    int count;
    int lo, hi, mid, r;
    if (arr == 0 || cmp == 0) {
        return 0;
    }
    count = obj->count;
    if (count == 0) {
        return 0;
    }
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        mid = lo + ((hi - lo + 1) >> 1);
        r = cmp(arr + mid * kElementStride);
        if (r == key) {
            return arr + mid * kElementStride;
        }
        if (r > key) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return 0;
}
