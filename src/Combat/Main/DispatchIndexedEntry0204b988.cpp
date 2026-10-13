#include <globaldefs.h>

void CallFunc0204b620IfField0x14_0204b938(void* obj, void* p, int a3, int a4, unsigned short a5);

struct Obj0204b988 {
    char pad0[0x10];
    char* field10;
    char pad14[0x9];
    unsigned char field1d;
};

// USA: func_0204b988
ARM void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5) {
    char* base;
    if (obj->field1d <= index) return;
    base = obj->field10;
    if (base == NULL) return;
    CallFunc0204b620IfField0x14_0204b938(obj, base + index * 16, a3, a4, a5);
}
