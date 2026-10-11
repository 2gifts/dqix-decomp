#include <globaldefs.h>

extern "C" void* func_02057924(void);
void* GetInlineRecordByBattleId(void* obj, int id);
void* GetSlotPtr_021e8cf0_021e8cf0(char* base, int idx);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
extern int data_ov025_021ef988;

struct Param021e5014 { char pad[8]; unsigned char field8; unsigned char field9; };

// JPN: func_ov025_021e5504
// USA: func_ov025_021e5014
ARM int SetRecordFieldFromDispatch_021e5014(struct Param021e5014* p, int b, int unused2, int d) {
#if defined(jpn)
 enum {regionalOffset0=4};
#else
 enum {regionalOffset0=0xc};
#endif
    void* slot = GetSlotPtr_021e8cf0_021e8cf0(*(char**)((char*)&data_ov025_021ef988 + regionalOffset0), p->field9);
    if (!slot) {
        return 1;
    }
    int id = *(int*)slot;
    void* obj = func_02057924();
    void* record = GetInlineRecordByBattleId(obj, id);
    if (!record) {
        return 1;
    }
    int localbuf[8];
    int r = DispatchByIndex021820bc((void*)d, b, p->field8, (int)&localbuf[0]);
    if (r != 1) {
        *(short*)((char*)record + 0xb2) = -1;
        return 1;
    }
    *(short*)((char*)record + 0xb2) = (short)localbuf[0];
    return 1;
}
