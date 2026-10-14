#include <globaldefs.h>

void* SetGlobalContext02110370_020bd42c(void*);
int ScaleField0x160By1000_020bec98(void* obj);
void NotifyObjectIfPresent020bec58(void* volatile* slot, int arg);

// USA: func_0203ad88
ARM int ScaleAndNotify0203ad88(void* obj, void* target, int arg2) {
    char* p = (char*)obj;
    int result;
    if (*(void**)p == NULL) return 0;
    SetGlobalContext02110370_020bd42c(p + 0x4);
    if (target != NULL) {
        result = ScaleField0x160By1000_020bec98(target);
        NotifyObjectIfPresent020bec58((void* volatile*)target, arg2);
    } else {
        result = ScaleField0x160By1000_020bec98(p + 0x9c);
        NotifyObjectIfPresent020bec58((void* volatile*)(p + 0x9c), arg2);
    }
    *(short*)(p + 0xa4) = -1;
    return result;
}
