#include <globaldefs.h>

struct ShortField0x28_02099fe8 {
    char pad[0x28];
    short field;
    char pad2[2];
};

struct BitField0209a004 {
    unsigned int count : 12;
    unsigned int : 19;
    unsigned int flag : 1;
};

struct Table0209a004 {
    struct BitField0209a004 header;
    struct ShortField0x28_02099fe8* records;
};

int GetShortAt0x28(struct ShortField0x28_02099fe8*);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0209a004
extern "C" ARM struct ShortField0x28_02099fe8* _Z26BinarySearchRecord0209a004Pvi(struct Table0209a004* table, int key) {
    struct ShortField0x28_02099fe8* found;
    int hi, lo, mid, count;
    struct ShortField0x28_02099fe8* records = table->records;
    if (records == NULL || (void*)GetShortAt0x28 == NULL) {
        found = NULL;
    } else {
        count = table->header.count;
        if (count == 0) {
            found = NULL;
        } else {
            lo = 0;
            hi = count - 1;
            while (lo <= hi) {
                mid = lo + ((hi - lo + 1) >> 1);
                found = &records[mid];
                int v = GetShortAt0x28(found);
                if (v == key) goto done;
                if (v > key) hi = mid - 1;
                else lo = mid + 1;
            }
            found = NULL;
        }
    }
done:
    return found;
}
