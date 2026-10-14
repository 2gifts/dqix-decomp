#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Obj2081;
int FindElementByByte0xc4(Obj2081*, int);
struct List0207f0ac;
int FindEntryByShortId0207f0ac(List0207f0ac*, int);
struct Obj02081e18;
unsigned int FindMatchingElemSumOrScaledPtr02081e18(Obj02081e18*, int);
struct Obj02081de0;
int FindElementWithByte0xc4Is0xff(Obj02081de0*);
int ClearSublistEntriesFlag4(void *obj, int id);
extern "C" int _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih(void *a, int c, int id);
struct Params02081498;
int DispatchMessageAndInvokeList02081498(void*, void*, Params02081498*);
int ProcessEntryList02081574(void *obj, void *a, void *b);
struct Obj0204fbf8;
int InvokeHandlerAfterCacheFlush0204fbf8(Obj0204fbf8*);

// USA: func_020813ec  (semantic: ProcessSublistEntryAndDispatch_020813ec)
extern "C" ARM int func_020813ec(void *obj, int id) {
    if (id < 0) {
        return 1;
    }

    int a = FindElementByByte0xc4((Obj2081*)obj, id);
    int b = FindEntryByShortId0207f0ac((List0207f0ac*)((char *)obj + 0xc), id);
    if (b == 0) {
        return 1;
    }

    unsigned char byteVal = *((unsigned char *)obj + (IS_JPN ? 0x2e : 0x3a));
    unsigned int c = FindMatchingElemSumOrScaledPtr02081e18((Obj02081e18*)obj, byteVal);

    if (a == 0) {
        a = FindElementWithByte0xc4Is0xff((Obj02081de0*)obj);
        ClearSublistEntriesFlag4(obj, id);
    }

    if (a != 0) {
        _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih((void *)a, c, id);
        DispatchMessageAndInvokeList02081498(obj, (void *)a, (Params02081498*)b);
        ProcessEntryList02081574(obj, (void *)a, (void *)b);
        InvokeHandlerAfterCacheFlush0204fbf8((Obj0204fbf8*)a);
    }

    return 0;
}
