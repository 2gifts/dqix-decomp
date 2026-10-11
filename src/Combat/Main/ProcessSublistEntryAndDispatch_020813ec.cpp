#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#if IS_JPN
#define _Z38FindMatchingElemSumOrScaledPtr02081e18P11Obj02081e18i func_02082754
#define _Z29FindElementWithByte0xc4Is0xffP11Obj02081de0 func_0208271c
#define _Z24ProcessEntryList02081574PvS_S_ func_02081e78
#endif

extern "C" int _Z21FindElementByByte0xc4P7Obj2081i(void *obj, int id);
extern "C" int _Z26FindEntryByShortId0207f0acP12List0207f0aci(void *list, int id);
extern "C" int _Z38FindMatchingElemSumOrScaledPtr02081e18P11Obj02081e18i(void *obj, int x);
extern "C" int _Z29FindElementWithByte0xc4Is0xffP11Obj02081de0(void *obj);
extern "C" int _Z24ClearSublistEntriesFlag4Pvi(void *obj, int id);
extern "C" int _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih(void *a, int c, int id);
extern "C" int _Z36DispatchMessageAndInvokeList02081498PvS_P14Params02081498(void *obj, void *a, void *b);
extern "C" int _Z24ProcessEntryList02081574PvS_S_(void *obj, void *a, void *b);
extern "C" int _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(void *a);

// JPN: 0x02081cf0
// USA: func_020813ec  (semantic: ProcessSublistEntryAndDispatch_020813ec)
extern "C" ARM int func_020813ec(void *obj, int id) {
    if (id < 0) {
        return 1;
    }

    int a = _Z21FindElementByByte0xc4P7Obj2081i(obj, id);
    int b = _Z26FindEntryByShortId0207f0acP12List0207f0aci((char *)obj + 0xc, id);
    if (b == 0) {
        return 1;
    }

    unsigned char byteVal = *((unsigned char *)obj + (IS_JPN ? 0x2e : 0x3a));
    int c = _Z38FindMatchingElemSumOrScaledPtr02081e18P11Obj02081e18i(obj, byteVal);

    if (a == 0) {
        a = _Z29FindElementWithByte0xc4Is0xffP11Obj02081de0(obj);
        _Z24ClearSublistEntriesFlag4Pvi(obj, id);
    }

    if (a != 0) {
        _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih((void *)a, c, id);
        _Z36DispatchMessageAndInvokeList02081498PvS_P14Params02081498(obj, (void *)a, (void *)b);
        _Z24ProcessEntryList02081574PvS_S_(obj, (void *)a, (void *)b);
        _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8((void *)a);
    }

    return 0;
}
