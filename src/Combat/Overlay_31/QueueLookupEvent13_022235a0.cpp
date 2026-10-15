#include <globaldefs.h>
#include "Resource/UiArrayEntry.h"

extern ArrBasePair022276b4* data_ov031_02290c4c;

extern "C" void* func_ov031_0223c560(int a, int b);
int GetTableEntryByField0_022236d0(void);
extern "C" void func_ov031_0223c980(void* obj, int a, int b, int c, int d, int e, int f, int g);
void SetFlagIfMatchesElem0_0223caec(void* ptr);

// USA: func_ov031_022235a0  (semantic: QueueLookupEvent13_022235a0)
extern "C" ARM void func_ov031_022235a0(void* arg) {
    void* obj = func_ov031_0223c560(0, 0);
    int lookup = LookupArrayPlusBase_022276b4(data_ov031_02290c4c, (unsigned int)arg);
    int entry = GetTableEntryByField0_022236d0();
    func_ov031_0223c980(obj, 0xd, 0x28, 0xe6, 0x70, 2, entry, lookup);
    SetFlagIfMatchesElem0_0223caec(obj);
}
