#include <globaldefs.h>
struct Token020aea40 { unsigned short value; };
extern "C" Token020aea40* func_02012fe4();
void SetOrClearElemFlag0x4ByKeys(int, int, short);
extern unsigned char data_020e9148[], data_020e9149[], data_020e914a[];
// USA: func_020aea40
extern "C" ARM void func_020aea40(unsigned int index, int clear) {
    if (index <= 3) {
        if (func_02012fe4()->value != 0x164a) return;
    } else {
        if (index < 4 || index > 7) return;
        if (func_02012fe4()->value != 0x21ff) return;
    }
    if (!clear) {
        SetOrClearElemFlag0x4ByKeys(1, 0, data_020e9148[index * 3]);
        SetOrClearElemFlag0x4ByKeys(1, 0, data_020e9149[index * 3]);
        SetOrClearElemFlag0x4ByKeys(1, 0, data_020e914a[index * 3]);
    } else {
        SetOrClearElemFlag0x4ByKeys(0, 0, data_020e9148[index * 3]);
        SetOrClearElemFlag0x4ByKeys(0, 0, data_020e9149[index * 3]);
        SetOrClearElemFlag0x4ByKeys(0, 0, data_020e914a[index * 3]);
    }
}
