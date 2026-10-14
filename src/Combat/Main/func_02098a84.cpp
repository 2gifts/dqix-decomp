#include <globaldefs.h>

struct ValueList02098e3c;
extern int Field0x1b68ContainsValue(struct ValueList02098e3c* s, int val);

struct S02098834 {
    unsigned char pad0[0xc];
    unsigned int flagsLow : 4;
    unsigned int category : 4;
    unsigned int flagsHigh : 24;
    unsigned int used : 2;
    unsigned int valueId : 30;
    unsigned char pad1[0xe8 - 0x14];
};

extern struct S02098834* CopyStruct02098834(struct S02098834* dst, struct S02098834* src);
extern "C" void func_02098364(void* entry);

struct ValueList02098e3c {
    S02098834 entries[30];
    unsigned char unknown1b30[8];
    int field1b38;
    unsigned char unknown1b3c[0x1b68 - 0x1b3c];
    unsigned int values[3];
    int fallbackIndex;
};

// USA: func_02098a84
extern "C" ARM int func_02098a84(ValueList02098e3c* list) {
    S02098834* arr = list->entries;
    if (list->field1b38 == 0) {
        return 0;
    }

    int recycle = 0;
    int last = recycle;
    int freeIdx = recycle - 1;
    int allValid = 1;
    for (int idx = recycle; idx < 0x1e; idx++) {
        struct S02098834* e = &arr[idx];
        if (e->used == 0) {
            freeIdx = idx;
            break;
        }
        if (e->category == 9 || e->category == 10) {
            continue;
        }
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            allValid = 0;
        }
    }

    if (freeIdx == 0) {
        return 0;
    }

    if (freeIdx != -1) {
        if (allValid) {
            if (freeIdx < 6) {
                return freeIdx;
            }
            CopyStruct02098834(&arr[freeIdx], &arr[list->fallbackIndex]);
            func_02098364(&arr[list->fallbackIndex]);
            return list->fallbackIndex;
        }
        recycle = freeIdx;
    } else {
        for (int idx = 0x1d; idx >= 0; idx--) {
            struct S02098834* e = &arr[idx];
            if (e->category == 9 || e->category == 10) {
                continue;
            }
            if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
                recycle = idx;
                break;
            }
        }
    }

    for (int idx = recycle - 1; idx >= 0; idx--) {
        struct S02098834* e = &arr[idx];
        if (e->category == 9 || e->category == 10) {
            continue;
        }
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            last = idx;
            CopyStruct02098834(&arr[recycle], e);
            recycle = idx;
        }
    }
    struct S02098834* resetSlot = &arr[last];
    func_02098364(resetSlot);

    struct S02098834* e;
    for (recycle = 0; recycle < 6; recycle++) {
        if (arr[recycle].category == 9 || arr[recycle].category == 10) {
            continue;
        }
        e = &arr[recycle];
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            e->category = 2;
        }
    }
    for (recycle = 6; recycle < 12; recycle++) {
        if (arr[recycle].category == 9 || arr[recycle].category == 10) {
            continue;
        }
        e = &arr[recycle];
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            e->category = 3;
        }
    }
    for (recycle = 12; recycle < 18; recycle++) {
        if (arr[recycle].category == 9 || arr[recycle].category == 10) {
            continue;
        }
        e = &arr[recycle];
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            e->category = 4;
        }
    }
    for (recycle = 18; recycle < 24; recycle++) {
        if (arr[recycle].category == 9 || arr[recycle].category == 10) {
            continue;
        }
        e = &arr[recycle];
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            e->category = 5;
        }
    }
    for (recycle = 24; recycle < 0x1e; recycle++) {
        if (arr[recycle].category == 9 || arr[recycle].category == 10) {
            continue;
        }
        e = &arr[recycle];
        if (Field0x1b68ContainsValue(list, e->valueId) == 0) {
            e->category = 6;
        }
    }

    if (last < 6) {
        return last;
    }
    CopyStruct02098834(resetSlot, &arr[list->fallbackIndex]);
    func_02098364(&arr[list->fallbackIndex]);
    return list->fallbackIndex;
}
