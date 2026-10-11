#include <globaldefs.h>
int GetShortAt0x8(unsigned char*);

struct BinarySearchByComparatorStruct;
typedef int (*BinarySearchByComparatorFn)(void* elem);
#if defined(jpn)
extern "C" void* func_02070530(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
#define BinarySearchByComparator func_02070530
#else
extern void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
#endif


// USA: func_0206f4f0
ARM void* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* base, int key) {
    return BinarySearchByComparator(base, key, (BinarySearchByComparatorFn)GetShortAt0x8);
}
