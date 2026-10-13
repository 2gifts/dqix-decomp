#include <globaldefs.h>
#include "Combat/SearchEntry.h"

ARM void PushInterruptDisableState(void);
extern "C" void func_020d8694(void);

struct Record0202ba08;
ARM struct Record0202ba08* CopyRecord0202ba08(struct Record0202ba08* dst, struct Record0202ba08* src);

// USA: func_0202c478
ARM void ShiftRecords0202c478(SearchStruct* obj) {
    PushInterruptDisableState();
    char* base = (char*)obj;
    int i;
    for (i = 0; i < *(int*)(base + 0xc); i++) {
        ((int*)(base + 0x790))[i] -= 0x10;
        if (((int*)(base + 0x790))[i] > 0) {
            continue;
        }
        int j;
        for (j = i; j < *(int*)(base + 0xc) - 1; j++) {
            CopyRecord0202ba08((struct Record0202ba08*)(base + 0x10 + j * 0xc0),
                                (struct Record0202ba08*)(base + 0x10 + (j + 1) * 0xc0));
        }
        (*(int*)(base + 0xc))--;
    }
    func_020d8694();
}
