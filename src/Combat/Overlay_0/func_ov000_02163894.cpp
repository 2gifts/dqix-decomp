#include <globaldefs.h>
#include "Util/Random.h"

// USA: func_ov000_02163894
extern "C" ARM void func_ov000_02163894(char* obj) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (*(signed char*)(obj + 0x773c + i) >= 0) {
            count++;
        }
    }
    if (count <= 1) {
        return;
    }
    int n = NextRandomBetween(GetBTRandom(), 2, 10);
    for (int k = 1; k < n; k++) {
        int j = k % count;
        signed char first = *(signed char*)(obj + 0x773c);
        *(signed char*)(obj + 0x773c) = *(signed char*)(obj + 0x773c + j);
        *(signed char*)(obj + 0x773c + j) = first;
    }
}
