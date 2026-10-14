#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Container020dfa68;
struct Element020dfa68;

struct Element020df850 {
    short a;
    short b;
    int c;
};

struct MergedContainer020dfabc {
    unsigned short count;
    unsigned short pad2;
    unsigned int pad4a : 15;
    unsigned int doneFlag : 1;
    unsigned int pad4b : 16;
    void *elements;
    void *end;
};

struct ScaledPair020dfbc0;

typedef int (*ElementCallback020dfa68)(struct Container020dfa68 *, struct Element020dfa68 *);

extern int GetScaledFieldSum(struct ScaledPair020dfbc0 *);
extern "C" int func_020df77c(struct Container020dfa68 *, struct Element020dfa68 *);
extern int ForEachElement020dfa68(struct Container020dfa68 *, ElementCallback020dfa68);
extern int MergeContainer020dfabc(struct MergedContainer020dfabc *, struct MergedContainer020dfabc *, char *, ElementCallback020dfa68);

struct Container020dfb48;
typedef int (*Comparator020dfb48)(void *);
extern void *BinarySearchByComparator020dfb48(struct Container020dfb48 *, int, Comparator020dfb48);

char *AllocateStringCopy020da150(SafeAllocator *, const char *);
short GetShortAt0x0_020df774(short *);

// USA: func_020df850
extern "C" ARM int func_020df850(struct MergedContainer020dfabc *self, SafeAllocator *alloc,
                                 struct MergedContainer020dfabc *src, void *unused, short mode) {
    struct MergedContainer020dfabc local;
    char flag;
    struct Element020df850 *elem;
    struct Element020df850 *dst;
    struct Element020df850 *srcArr;
    struct Element020df850 *dstArr;
    int size;
    int mask;
    int n;
    int i;

    if (alloc == NULL || src == NULL || unused == NULL) return 0;
    if (mode < 0) {
        if (alloc != NULL && src != NULL) {
            memcpy(self, src, 8);
            size = GetScaledFieldSum((struct ScaledPair020dfbc0 *)self);
            mask = self->pad4a;
            if (size)
                self->elements = alloc->Allocate(size);
            else
                self->elements = NULL;
            self->end = mask ? alloc->Allocate(mask) : NULL;
            if (self->elements != NULL) memcpy(self->elements, (char *)src + 8, size);
            if (self->end != NULL)
                memcpy(self->end, (char *)src + (GetScaledFieldSum((struct ScaledPair020dfbc0 *)self) + 8), mask);
            if ((ElementCallback020dfa68)func_020df77c) ForEachElement020dfa68((struct Container020dfa68 *)self, (ElementCallback020dfa68)func_020df77c);
            self->doneFlag = 1;
        }
    } else {
        memset(&local, 0, 0x10);
        MergeContainer020dfabc(&local, src, &flag, func_020df77c);
        elem = (struct Element020df850 *)BinarySearchByComparator020dfb48(
            (struct Container020dfb48 *)&local, mode, (Comparator020dfb48)GetShortAt0x0_020df774);
        if (elem != NULL) {
            memset(self, 0, 0x10);
            self->count = 1;
            self->pad2 = elem->b;
            self->elements = alloc->Allocate(GetScaledFieldSum((struct ScaledPair020dfbc0 *)self));
            if (self->elements != NULL) {
                memcpy(self->elements, elem, 8);
                dst = (struct Element020df850 *)self->elements;
                n = dst->b;
                if (dst->b == 0 || dst->c == -1 || elem->c == 0) {
                    dst->b = 0;
                    ((struct Element020df850 *)self->elements)->c = 0;
                } else {
                    dst->c = (int)(dst + 1);
                    srcArr = (struct Element020df850 *)elem->c;
                    dstArr = (struct Element020df850 *)((struct Element020df850 *)self->elements)->c;
                    memcpy(dstArr, srcArr, n * 8);
                    for (i = 0; i < n; i++, dstArr++, srcArr++) {
                        dstArr->c = (int)AllocateStringCopy020da150(alloc, (const char *)srcArr->c);
                    }
                }
            }
        }
    }
    return 1;
}
