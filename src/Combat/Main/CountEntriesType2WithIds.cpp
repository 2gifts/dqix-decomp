#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;

struct ListEntry020bc0f8 {
    unsigned char pad[0x34];
    unsigned short type;
    unsigned short pad36;
    unsigned short id0;
    unsigned short id1;
};

// USA: func_020bc0f8
ARM int CountEntriesType2WithIds_020bc0f8(int a, int b) {
    int count = 0;
    SignedAllocatorHeader* e = data_0210f3d8.ElementAfter(NULL);
    if (e != NULL) {
        do {
            ListEntry020bc0f8* entry = (ListEntry020bc0f8*)e;
            if (entry->type == 2 && entry->id0 == a && entry->id1 == b) count++;
            e = data_0210f3d8.ElementAfter(e);
        } while (e != NULL);
    }
    return count;
}
