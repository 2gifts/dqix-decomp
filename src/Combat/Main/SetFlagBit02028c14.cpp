#include <globaldefs.h>

void InsertShortIntoTable021098f4_0209953c(unsigned short);

struct Obj02028c14 {
    unsigned short pad0;
    unsigned short lowNibble : 4;
    unsigned short flags : 12;
};

// USA: func_02028c14
ARM void SetFlagBit02028c14(struct Obj02028c14* obj, int index) {
    if (index >= 0xc) {
        InsertShortIntoTable021098f4_0209953c(4);
        return;
    }
    obj->flags |= 1 << index;
}
