#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_021847ec func_ov009_02185850
#endif
#include "std_library_functions.h"

struct Entry0218aafc { char str[5]; };
#if !defined(jpn)
extern struct Entry0218aafc data_ov009_0218aafc[];
#endif
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);

struct Obj021847ec {
#if !defined(jpn)
    char pad[0x18];
#endif
    char unk18[0xc];
    int field24;
    short field28;
#if defined(jpn)
    unsigned short field12;
    int tasks[2];
    int field1c;
#else
    unsigned char field2a[15];
#endif
};

#if defined(jpn)
extern "C" int func_ov009_02185888(Obj021847ec*);
#endif

// USA: func_ov009_021847ec
extern "C" ARM void func_ov009_021847ec(struct Obj021847ec* obj) {
    memset(obj->unk18, 0, 0xc);
    obj->field24 = 0;
    obj->field28 = 0;
#if defined(jpn)
    obj->tasks[0] = -1;
    obj->tasks[1] = -1;
    func_ov009_02185888(obj);
#else
    unsigned char* out = obj->field2a;
    int i;
    for (i = 0; i < 15; i++) {
        *out++ = (unsigned char)_Z27FindEntryIndexByKey020424e4ii((int)&data_ov009_0218aafc[i], 1);
    }
#endif
}
