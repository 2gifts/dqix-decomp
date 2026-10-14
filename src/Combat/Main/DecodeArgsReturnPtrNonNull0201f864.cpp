#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };
struct Struct02030b7c;

// USA: func_0201f864
ARM int DecodeArgsReturnPtrNonNull0201f864(Variant02030b0c* args) {
    void* p;
    ((Script::Parameter*)args)->ToInt();
    p = (void*)((Script::Parameter*)((Struct02030b7c*)(args + 1)))->ToString();
    ((Script::Parameter*)(args + 2))->ToInt();
    return p != NULL ? 1 : 0;
}
