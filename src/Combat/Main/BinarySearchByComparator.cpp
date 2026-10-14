#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f470
ARM void* BinarySearchByComparator_0206f470(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp) {
    MonsterDefinition* arr;
    int count;
    int low;
    int high;
    int mid;
    int r;

    arr = base->arr;
    if (arr == NULL || comp == NULL) {
        return NULL;
    }
    count = base->header.count;
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
