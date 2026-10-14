#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Array020278e4;
void AllocateArray020278e4(Array020278e4* obj, int capacity, SafeAllocator* alloc);
extern int data_020fdc4c;

// USA: func_0201f580
ARM int AllocateArrayWithDecodedCount0201f580(Variant02030b0c* arg) {
    int capacity = ((Script::Parameter*)arg)->ToInt();
    AllocateArray020278e4(
        (Array020278e4*)*(char**)((char*)&data_020fdc4c + 0x10),
        capacity,
        (SafeAllocator*)*(char**)((char*)&data_020fdc4c + 0x8));
    return 1;
}
