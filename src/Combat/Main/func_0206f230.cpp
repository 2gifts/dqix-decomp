#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

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
    char* field20;
    int field24;
};

struct BinarySearchByComparatorStruct {
    unsigned int count : 12;
    struct SortedEntry0206f230* arr;
};

typedef int (*BinarySearchByComparatorFn)(void* elem);

int GetShortAt0x8(unsigned char*);
int RelocateThreeFields(void* ctx, struct Fixup0206ef48* obj);
int InitEntryListFromSource0206f170(struct List0206f170* arg0, struct Src0206f170* arg1, unsigned char* outFlag,
                                    void (*callback)(struct EntryList0206f110*, struct Entry0206f110*));
void* BinarySearchByComparator(struct BinarySearchByComparatorStruct* base, int key, BinarySearchByComparatorFn comp);
char* AllocateStringCopy020da150(SafeAllocator* allocator, const char* src);

extern int data_02108d14;

// USA: func_0206f230
extern "C" ARM void func_0206f230(struct BinarySearchByComparatorStruct* out, SafeAllocator* alloc,
                                          struct Src0206f170* src, int reserved, short* keys, int keyCount,
                                          SafeAllocator* sb, unsigned char* flags) {
    int i;
    int isNew;
    int m;
    unsigned char initFlag;
    struct List0206f170 list;
    short sorted[0x200];
    short n;
    int j;
    struct SortedEntry0206f230* dst;
    int k;
    short* keyPtr;
    short key;
    short* slot;
    short* sortedPtr;
    struct SortedEntry0206f230* found;

    data_02108d14 = (int)out;
    if (keyCount == 0) {
        return;
    }
    initFlag = 0;
    InitEntryListFromSource0206f170(&list, src, &initFlag,
                                    (void (*)(struct EntryList0206f110*, struct Entry0206f110*))RelocateThreeFields);
    n = 0;
    keyPtr = keys;
    for (i = 0; i < keyCount; i++) {
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
        keyPtr++;
    }

    out->arr = (struct SortedEntry0206f230*)alloc->Allocate(n * sizeof(struct SortedEntry0206f230));
    if (out->arr == NULL) {
        return;
    }
    if (sb != NULL && flags != NULL) {
        alloc->Allocate(0x80 - n * 8);
    }

    m = 0;
    sortedPtr = sorted;
    dst = out->arr;
    for (k = 0; k < n; k++, sortedPtr++) {
        found = (struct SortedEntry0206f230*)BinarySearchByComparator(
            (struct BinarySearchByComparatorStruct*)&list, *sortedPtr, (BinarySearchByComparatorFn)GetShortAt0x8);
        if (found == NULL) {
            continue;
        }
        memcpy(dst, found, sizeof(struct SortedEntry0206f230));
        if (sb != NULL && flags != NULL) {
            dst->field0 = AllocateStringCopy020da150(sb, found->field0);
            dst->field20 = AllocateStringCopy020da150(sb, found->field20);
            alloc->Allocate(flags[k]);
        } else {
            dst->field0 = AllocateStringCopy020da150(alloc, found->field0);
            dst->field20 = AllocateStringCopy020da150(alloc, found->field20);
        }
        dst->field4 = AllocateStringCopy020da150(alloc, found->field4);
        dst++;
        m = (short)(m + 1);
    }
    out->count = m;
}
