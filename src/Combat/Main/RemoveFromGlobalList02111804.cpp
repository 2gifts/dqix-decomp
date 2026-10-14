#include <globaldefs.h>

struct ListNode020ceeb4;
void UnlinkNodeWithInterruptsDisabled(struct ListNode020ceeb4**, struct ListNode020ceeb4*);

extern int data_02111804;

// USA: func_020cef64
ARM void RemoveFromGlobalList02111804_020cef64(void* node) {
    UnlinkNodeWithInterruptsDisabled((struct ListNode020ceeb4**)&data_02111804, (struct ListNode020ceeb4*)node);
}
