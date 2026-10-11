#include <globaldefs.h>

short GetScaledFieldValue_02166684(int a);

struct ListNode021666bc {
    short id;
    unsigned short bit0 : 2;
    unsigned short bit2 : 1;
    unsigned short pad : 13;
    char pad4[4];
    struct ListNode021666bc* next;
};
extern struct ListNode021666bc* data_ov004_0217101c;

#if defined(jpn)
enum { globalPointerIndex = 1 };
#else
enum { globalPointerIndex = 0 };
#endif

// USA: func_ov004_021666bc  (semantic: FindNodeAndFlagBit2_021666bc)
#pragma optimize_for_size off
extern "C" ARM short func_ov004_021666bc(int a, char* outFlag) {
    short count = GetScaledFieldValue_02166684(a);
    struct ListNode021666bc* node = (&data_ov004_0217101c)[globalPointerIndex]->next;
    *outFlag = 0;
    while (node != 0 && count != 0) {
        count--;
        node = node->next;
    }
    if (node != 0) {
        *outFlag = node->bit2 != 0;
        return node->id;
    } else {
        return -1;
    }
}
