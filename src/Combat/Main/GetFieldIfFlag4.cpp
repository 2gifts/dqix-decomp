#include <globaldefs.h>
int GetFlags_0202e09c(int);

// USA: func_020100f8
ARM int GetFieldIfFlag4_020100f8(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (GetFlags_0202e09c((int)(p)) & 4) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
