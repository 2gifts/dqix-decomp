#include <globaldefs.h>

int CheckField0NonZero020a10a8(int*);

// USA: func_0202eeb4
ARM int AnySubObjectField0NonZero_0202eeb4(char* obj) {
    int result = 1;
    int inner = 1;
    if (CheckField0NonZero020a10a8((int*)(obj + 0x16c)) == 0) {
        if (CheckField0NonZero020a10a8((int*)(obj + 0x194)) == 0) inner = 0;
    }
    if (inner == 0) {
        if (CheckField0NonZero020a10a8((int*)(obj + 0x1bc)) == 0) result = 0;
    }
    return result;
}
