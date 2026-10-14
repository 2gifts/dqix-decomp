#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;

struct ListEntry020bc0a4 {
    unsigned char pad[0x34];
    unsigned short type;
    unsigned short pad36;
    unsigned short id;
};

// USA: func_020bc0a4
ARM int CountEntriesType1WithId_020bc0a4(int id) {
    int count = 0;
    SignedAllocatorHeader* e = data_0210f3d8.ElementAfter(NULL);
    if (e != NULL) {
        do {
            ListEntry020bc0a4* entry = (ListEntry020bc0a4*)e;
            if (entry->type == 1 && entry->id == id) count++;
            e = data_0210f3d8.ElementAfter(e);
        } while (e != NULL);
    }
    return count;
}
