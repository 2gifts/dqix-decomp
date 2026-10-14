#include <globaldefs.h>

extern "C" unsigned int func_ov027_021dd024(void);
extern "C" unsigned short func_ov027_021dd038(void);
void ClearFlagsTo_021dae1c_021dae1c(void);
int IssueBattleCommandSlot24_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5);

struct ListNode021daecc {
    unsigned char pad0[0x4b4];
    unsigned char field4b4;
    unsigned char pad1[0x4bc - 0x4b5];
    ListNode021daecc* next;
};

struct DispatchCtx021daecc {
    unsigned char pad0[0x18];
    ListNode021daecc* head;
    ListNode021daecc* cur;
    unsigned char pad1[0x24 - 0x20];
    unsigned char state;
    unsigned char pad2;
    unsigned char fieldB;
};

extern DispatchCtx021daecc data_ov027_021dd940;
extern int data_ov027_021dd980;

// USA: func_ov027_021daecc  (semantic: AdvanceDispatchNode_021daecc)
#pragma optimize_for_size off
extern "C" ARM int func_ov027_021daecc(void) {
    ListNode021daecc* head = data_ov027_021dd940.head;
    if (head == 0) {
        unsigned int a = func_ov027_021dd024();
        IssueBattleCommandSlot24_020d69cc(0, (int)&data_ov027_021dd980, 0x70, a, func_ov027_021dd038(), 8);
        return 0;
    }
    ListNode021daecc* cur = data_ov027_021dd940.cur;
    if (cur == 0 || cur->next == 0) {
        cur = *(ListNode021daecc* *)&data_ov027_021dd940.head;
    } else {
        cur = cur->next;
    }
    data_ov027_021dd940.cur = cur;
    ClearFlagsTo_021dae1c_021dae1c();
    data_ov027_021dd940.fieldB = data_ov027_021dd940.cur->field4b4;
    data_ov027_021dd940.state = 2;
    return 1;
}
