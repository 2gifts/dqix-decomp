#include <globaldefs.h>

#if defined(jpn)
enum { ENTRY_WORDS = 5 };
#else
enum { ENTRY_WORDS = 7 };
#endif

typedef int (*BinarySearchByComparatorFn)(void* elem);

struct BinarySearchByComparatorElem {
    unsigned int v[ENTRY_WORDS];
};

struct BinarySearchByComparatorStruct {
    unsigned int count : 12;
    struct BinarySearchByComparatorElem* arr;
};

#if defined(jpn)
#define BinarySearchByComparator func_02070530
extern "C" ARM void* func_02070530(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
#endif

// USA: func_0206f470
ARM void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp) {
    struct BinarySearchByComparatorElem* arr;
    int count;
    int low;
    int high;
    int mid;
    int r;

    arr = base->arr;
    if (arr == NULL || comp == NULL) {
        return NULL;
    }
    count = base->count;
    if (count == 0) {
        return NULL;
    }
    low = 0;
    high = count - 1;
    while (low <= high) {
        mid = low + ((high - low + 1) >> 1);
        r = comp(&arr[mid]);
        if (r == key) {
            return &arr[mid];
        }
        if (r > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return NULL;
}
