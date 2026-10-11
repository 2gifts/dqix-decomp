#include <globaldefs.h>
void ClearFirstWord0206da74(int*);
void ClearFirstWord02064e20(int*);
#include "std_library_functions.h"

struct Struct_020401e4;
void ClearStruct020401e4(struct Struct_020401e4* obj);

struct Struct_0203cf58 {
    unsigned char pad[0x8c];
    int field8c;
    unsigned char pad2[0x8];
    int field98;
    unsigned char field9c;
    unsigned char pad3[0x141];
    short field1de;
    unsigned char pad4[4];
    int field1e4;
};

// USA: func_0203cf58
ARM void InitWithExtendedRegion0203cf58(struct Struct_0203cf58* obj) {
    ClearStruct020401e4((struct Struct_020401e4*)obj);
    ClearFirstWord02064e20((int*)((char*)obj + 0x90));
    ClearFirstWord0206da74((int*)((char*)obj + 0x94));
    memset((char*)obj + 0xc, 0, 0x80);
    obj->field98 = 0;
    obj->field8c = 0;
    obj->field9c = 0;
    memset((char*)obj + 0x9e, 0, 0x140);
    obj->field1de = 0;
    obj->field1e4 = 0;
}
