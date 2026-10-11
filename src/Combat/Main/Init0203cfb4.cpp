#include <globaldefs.h>
void ClearFirstWord0206da74(int*);
void ClearFirstWord02064e20(int*);
#include "std_library_functions.h"

struct Struct_020401e4;
void ClearStruct020401e4(struct Struct_020401e4* obj);

struct Struct_0203cfb4 {
    unsigned char pad[0x8c];
    int field8c;
    unsigned char pad2[0x8];
    int field98;
    unsigned char field9c;
};

// USA: func_0203cfb4
ARM void Init0203cfb4(struct Struct_0203cfb4* obj) {
    ClearStruct020401e4((struct Struct_020401e4*)obj);
    ClearFirstWord02064e20((int*)((char*)obj + 0x90));
    ClearFirstWord0206da74((int*)((char*)obj + 0x94));
    memset((char*)obj + 0xc, 0, 0x80);
    obj->field98 = 0;
    obj->field8c = 0;
    obj->field9c = 0;
}
