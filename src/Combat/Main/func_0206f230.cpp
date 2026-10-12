#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define data_02108d14 data_02108c58
#define BinarySearchByComparator func_02070530
#endif

struct Src0206f170;
struct EntryList0206f110;
struct Entry0206f110;
struct Fixup0206ef48;

struct List0206f170 {
    int field0;
    void* field4;
    void* field8;
};

struct SortedEntry0206f230 {
    char* field0;
    char* field4;
    short field8;
    int field12;
    int field16;
#if !defined(jpn)
    char* field20;
    int field24;
#endif
};

struct BinarySearchByComparatorStruct {
    unsigned int count : 12;
    struct SortedEntry0206f230* arr;
};

typedef int (*BinarySearchByComparatorFn)(void* elem);

int GetShortAt0x8(unsigned char*);
int RelocateThreeFields(void* ctx, struct Fixup0206ef48* obj);
#if defined(jpn)
extern "C" int func_020700ac(void*, struct Fixup0206ef48*);
extern "C" int func_020702c0(struct List0206f170*, struct Src0206f170*, unsigned char*, int (*)(void*, struct Fixup0206ef48*));
extern "C" void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
#else
int InitEntryListFromSource0206f170(struct List0206f170* arg0, struct Src0206f170* arg1, unsigned char* outFlag,
                                    void (*callback)(struct EntryList0206f110*, struct Entry0206f110*));
void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
#endif
char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* src);

extern int data_02108d14;

// USA: func_0206f230
extern "C" ARM void func_0206f230(struct BinarySearchByComparatorStruct* out, SafeAllocator* alloc,
#if defined(jpn)
                                          struct Src0206f170* src, int reserved, short* keys, int keyCount) {
#else
                                          struct Src0206f170* src, int reserved, short* keys, int keyCount,
                                          SafeAllocator* sb, unsigned char* flags) {
#endif
#if defined(jpn)
    short* keyPtr;
#else
    int i;
#endif
    int isNew;
    int m;
    unsigned char initFlag;
    struct List0206f170 list;
    short sorted[0x200];
    short n;
    int j;
    struct SortedEntry0206f230* dst;
#if defined(jpn)
    short* sortedPtr;
    int i;
#else
    int k;
    short* keyPtr;
#endif
    short key;
    short* slot;
#if defined(jpn)
    int k;
#else
    short* sortedPtr;
#endif
    struct SortedEntry0206f230* found;

    data_02108d14 = (int)out;
    if (keyCount == 0) {
        return;
    }
    initFlag = 0;
#if defined(jpn)
    func_020702c0(&list, src, &initFlag, func_020700ac);
#else
    InitEntryListFromSource0206f170(&list, src, &initFlag,
                                    (void (*)(struct EntryList0206f110*, struct Entry0206f110*))RelocateThreeFields);
#endif
    n = 0;
#if defined(jpn)
    i = 0;
#endif
    keyPtr = keys;
#if defined(jpn)
    for (; i < keyCount; i++, keyPtr++) {
#else
    for (i = 0; i < keyCount; i++) {
#endif
        key = *keyPtr;
        if (BinarySearchByComparator((struct BinarySearchByComparatorStruct*)&list, key,
                                     (BinarySearchByComparatorFn)GetShortAt0x8) != NULL) {
            slot = sorted;
            isNew = 1;
            for (j = 0; j < n; j++, slot++) {
                if (*slot == key) {
                    isNew = 0;
                    break;
                }
                if (*slot > key) {
                    memmove(slot + 1, slot, (n - j) * sizeof(short));
                    break;
                }
            }
            if (isNew) {
                *slot = key;
                n = n + 1;
                if (n >= 0x200) {
                    break;
                }
            }
        }
#if !defined(jpn)
        keyPtr++;
#endif
    }

    out->arr = (struct SortedEntry0206f230*)alloc->Allocate(n * sizeof(struct SortedEntry0206f230));
    if (out->arr == NULL) {
        return;
    }
#if !defined(jpn)
    if (sb != NULL && flags != NULL) {
        alloc->Allocate(0x80 - n * 8);
    }
#endif

    m = 0;
#if defined(jpn)
    k = 0;
#endif
    sortedPtr = sorted;
    dst = out->arr;
#if defined(jpn)
    for (; k < n; k++, sortedPtr++) {
#else
    for (k = 0; k < n; k++, sortedPtr++) {
#endif
        found = (struct SortedEntry0206f230*)BinarySearchByComparator(
            (struct BinarySearchByComparatorStruct*)&list, *sortedPtr, (BinarySearchByComparatorFn)GetShortAt0x8);
        if (found == NULL) {
            continue;
        }
        memcpy(dst, found, sizeof(struct SortedEntry0206f230));
#if defined(jpn)
        dst->field0 = AllocateStringCopy020da150(alloc, found->field0);
#else
        if (sb != NULL && flags != NULL) {
            dst->field0 = AllocateStringCopy020da150(sb, found->field0);
            dst->field20 = AllocateStringCopy020da150(sb, found->field20);
            alloc->Allocate(flags[k]);
        } else {
            dst->field0 = AllocateStringCopy020da150(alloc, found->field0);
            dst->field20 = AllocateStringCopy020da150(alloc, found->field20);
        }
#endif
        dst->field4 = AllocateStringCopy020da150(alloc, found->field4);
        dst++;
        m = (short)(m + 1);
    }
    out->count = m;
}
