#include <globaldefs.h>
int SetFlag0x8eIfBitTestFails_02023a9c(char*, int);

// USA: func_02026a78
ARM int CountMatchingEntries02026a78(char* obj) {
    unsigned char count = 0;
    int i;
    for (i = 0; i < *(unsigned char*)(obj + 0x780); i++) {
        if (SetFlag0x8eIfBitTestFails_02023a9c((char*)(obj), (int)(i))) {
            count++;
        }
    }
    return count;
}
