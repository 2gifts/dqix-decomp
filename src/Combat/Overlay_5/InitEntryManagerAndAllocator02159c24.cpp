#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kManagerOffset = 0xe60, kEntryCount = 3 };
#else
enum { kManagerOffset = 0xe64, kEntryCount = 4 };
#endif

struct EntryManager020e2490;
void InitEntryManager020e2490(EntryManager020e2490*, int, int, void*, SafeAllocator*, int, unsigned char);

struct Obj02159c24 {
    char unknown0[0x280];
    SafeAllocator promptAllocator;
    char unknownAfterAllocator[kManagerOffset - 0x294];
    EntryManager020e2490* yesNo;
    void* yesNoState;
};

// USA: func_ov005_02159c24
ARM void InitEntryManagerAndAllocator02159c24(Obj02159c24* menu, void* entriesAddress, void* stateAddress) {
    menu->promptAllocator.Reset();
    menu->yesNo = (EntryManager020e2490*)menu->promptAllocator.Allocate(0x24);
    InitEntryManager020e2490(menu->yesNo, 0, 1, (void*)entriesAddress, &menu->promptAllocator, kEntryCount, 0x40);
    menu->yesNoState = (void*)stateAddress;
}
