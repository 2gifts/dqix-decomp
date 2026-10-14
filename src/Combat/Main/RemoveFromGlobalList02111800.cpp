#include <globaldefs.h>

struct ListNode020ceeb4;
void UnlinkNodeWithInterruptsDisabled(struct ListNode020ceeb4**, struct ListNode020ceeb4*);

extern int data_02111800;

// USA: func_020cef7c
ARM void RemoveFromGlobalList02111800_020cef7c(void* node) {
    UnlinkNodeWithInterruptsDisabled((struct ListNode020ceeb4**)&data_02111800, (struct ListNode020ceeb4*)node);
}
