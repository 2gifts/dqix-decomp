#include <globaldefs.h>

struct Entry02157368 {
    short id;
    char pad[0x18 - 2];
};

struct List02157368 {
    char pad0[8];
    struct Entry02157368* arr;
    char pad1[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov006_02157368  (semantic: FindEntryByIdStride24_02157368)
extern "C" ARM struct Entry02157368* func_ov006_02157368(struct List02157368* list, int id) {
    struct Entry02157368* arr = list->arr;
    if (arr == 0) {
        return 0;
    }
    unsigned short count = list->count;
    if (count == 0) {
        return 0;
    }
    for (unsigned short i = 0; i < count; i++) {
        struct Entry02157368* e = &arr[i];
        if (e->id == id) {
            return e;
        }
    }
    return 0;
}
