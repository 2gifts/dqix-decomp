#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct FieldSet02097bc4;
void SetFieldGroupFromFlags02097bc4(struct FieldSet02097bc4* obj, int flags);

extern "C" int func_02097c18(void* obj, int b, int c, int d, int e, int f, int g, int h);

struct Data021098e0 {
    unsigned char* status;
    void* target;
};
extern struct Data021098e0 data_021098e0;

// USA: func_020978fc
ARM int GateAndDispatchVariants020978fc(struct Variant02030b0c* arr) {
    char* base = (char*)arr;
    int a = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x0)))->ToInt();
    if (*data_021098e0.status != (a & 0xff)) {
        return 1;
    }
    {
        int b = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x8)))->ToInt() & 0xff;
        int c = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x10)))->ToInt();
        int d = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x18)))->ToInt();
        int e = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x20)))->ToInt();
        int f = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x28)))->ToInt();
        int g = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x30)))->ToInt();
        int h = ((Script::Parameter*)((struct Variant02030b0c*)(base + 0x38)))->ToInt();
        SetFieldGroupFromFlags02097bc4((struct FieldSet02097bc4*)data_021098e0.target, b);
        func_02097c18(data_021098e0.target, b, c, d, e, f, g, h);
    }
    return 1;
}
