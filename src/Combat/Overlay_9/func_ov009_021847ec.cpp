#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_021847ec func_ov009_02185850
#endif
#include "std_library_functions.h"

struct Entry0218aafc { char str[5]; };
extern struct Entry0218aafc data_ov009_0218aafc[];
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);

struct Obj021847ec {
    char pad[0x18];
    char unk18[0xc];
    int field24;
    short field28;
    unsigned char field2a[15];
};

// USA: func_ov009_021847ec
extern "C" ARM void func_ov009_021847ec(struct Obj021847ec* obj) {
    memset(obj->unk18, 0, 0xc);
    obj->field24 = 0;
    obj->field28 = 0;
    unsigned char* out = obj->field2a;
    int i;
    for (i = 0; i < 15; i++) {
        *out++ = (unsigned char)_Z27FindEntryIndexByKey020424e4ii((int)&data_ov009_0218aafc[i], 1);
    }
}
