#include <globaldefs.h>

struct Neg1SearchEntry {
    char unk[8];
    int field8;
};

// USA: func_020daa20
ARM struct Neg1SearchEntry* FindEntryWithField8Neg1_020daa20(unsigned char* obj) {
    struct Neg1SearchEntry* e = (struct Neg1SearchEntry*)(obj + 0x14);
    unsigned char i = 0;
    while (i < 4) {
        if (e->field8 == -1) {
            return e;
        }
        i++;
        e++;
    }
    return NULL;
}
