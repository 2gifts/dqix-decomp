#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;
struct Struct020277c4;
void InitEntryList020277c4(Struct020277c4* obj, int count, SafeAllocator* alloc);
extern int data_020fdc4c;

// USA: func_0201f500
ARM int InitEntryListWithDecodedCount0201f500(Variant02030b0c* arg) {
    int count = ((Script::Parameter*)arg)->ToInt();
    InitEntryList020277c4(
        (Struct020277c4*)*(char**)((char*)&data_020fdc4c + 0x10),
        count,
        (SafeAllocator*)*(char**)((char*)&data_020fdc4c + 0x8));
    return 1;
}
