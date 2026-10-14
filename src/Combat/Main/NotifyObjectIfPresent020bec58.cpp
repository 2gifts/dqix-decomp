#include <globaldefs.h>

void RetargetTweenIfFlag2Enabled_020bf148(void*, int);

// USA: func_020bec58
ARM void NotifyObjectIfPresent020bec58(void* volatile* slot, int arg) {
    if (*slot != NULL) {
        RetargetTweenIfFlag2Enabled_020bf148(*slot, arg);
    }
}
