#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct SearchStruct;
void SetFlagBitAt0xe_0202c5bc(struct SearchStruct* obj, int value);

// USA: func_ov017_021cea64
ARM void CallHelperIfMismatch_021cea64(int unused0, int* p, int unused2, int unused3, struct SearchStruct0202c1a4* extra) {
    int field = p[1];
    int val = GetSearchStructCurrentArrEntry(extra);
    if (field == val) return;
    SetFlagBitAt0xe_0202c5bc((struct SearchStruct*)extra, field);
}
