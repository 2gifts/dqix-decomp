#include <globaldefs.h>
int GetFlags(int);

// USA: func_020100cc
ARM int GetFieldIfFlag2_020100cc(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (GetFlags((int)(p)) & 2) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
