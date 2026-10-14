#include <globaldefs.h>
#include "std_library_functions.h"

void ClearBitInArrayGuarded_020960cc(int unused, unsigned char* arr, int index);

struct Entry0209645c {
    unsigned int id : 9;
    unsigned char pad[12];
};

struct List0209645c {
    unsigned char count;
    unsigned char pad[3];
    Entry0209645c entries[9];
};

// USA: func_0209645c  (semantic: RemoveEntryById_0209645c)
extern "C" ARM int func_0209645c(List0209645c* list, int value) {
    if (value < 0 || list->count == 0) return 0;
    int i;
    for (i = 0; i < list->count; i++) {
        if (value == (int)list->entries[i].id) break;
    }
    if (i == list->count) return 0;
    ClearBitInArrayGuarded_020960cc((int)list, (unsigned char*)list + 0x4a8, value);
    Entry0209645c temp[9];
    memset(temp, 0, sizeof(temp));
    memcpy(temp, list->entries, 0x80);
    memcpy(&list->entries[i], &temp[i + 1], (list->count - i) * 16);
    list->count = list->count - 1;
    return 1;
}
