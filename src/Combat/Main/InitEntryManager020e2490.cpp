#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void ResetBytes020e25cc(signed char* p);
struct Struct02020520;
void ClearStruct02020520(struct Struct02020520* s);
struct ZeroStruct;
void ClearZeroStruct_020e1568(struct ZeroStruct* s);
void InitStruct020e1588(unsigned char* p);
void InitObj020e15f8(char* obj, int arg1, int arg2);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct EntryManager020e2490 {
    void* field0;
    void* field4;
    void* field8;
    unsigned char* fieldC;
    unsigned char* field10;
    signed char byte14;
    signed char byte15;
    signed char byte16;
    signed char byte17;
    short short18;
    short short1a;
    short short1c;
    signed char byte1e;
    signed char pad1f;
    void* field20;
};

// USA: func_020e2490
ARM void InitEntryManager020e2490(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag) {
    obj->short1c = 0;
    obj->byte1e = 8;
    obj->short18 = 0;
    obj->short1a = 0;
    obj->byte16 = 0;
    ResetBytes020e25cc((signed char*)obj);

    obj->field0 = alloc->Allocate(count * 0xc);
    obj->field4 = alloc->Allocate(0xc);
    obj->field8 = alloc->Allocate(count * 0xc);
    obj->fieldC = (unsigned char*)alloc->Allocate(0x40);
    obj->field10 = (unsigned char*)alloc->Allocate(0x4c);
    obj->field20 = arg3;

    int i;
    for (i = 0; i < count; i++) {
        ClearStruct02020520((struct Struct02020520*)((char*)obj->field0 + i * 0xc));
        ClearZeroStruct_020e1568((struct ZeroStruct*)((char*)obj->field8 + i * 0xc));
    }

    InitStruct020e1588(obj->fieldC);
    *(void**)(obj->fieldC + 0x0) = obj->field0;
    *(void**)(obj->fieldC + 0x4) = obj->field4;
    *(void**)(obj->fieldC + 0x8) = obj->field8;
    obj->fieldC[0x3c] = (unsigned char)count;
    obj->fieldC[0x3d] = flag;

    InitObj020e15f8((char*)obj->field10, arg1, arg2);
    *(void**)(obj->field10 + 0x4) = obj->fieldC;

    if (obj->field20 != NULL) {
        ClearField0And40205a234((struct ClearTarget0205a234*)obj->field20);
    }
}
