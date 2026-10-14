#include <globaldefs.h>
void NotifyOverlayIfField0x9cSet02073240(int);

// USA: func_020732a8
ARM void CallFuncForEachOfFour_020732a8(void) {
    int i;
    for (i = 0; i < 4; i++) {
        NotifyOverlayIfField0x9cSet02073240((int)(i));
    }
}
