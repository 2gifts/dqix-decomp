#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int val; };
extern int data_02109404;

// USA: func_020954b0
ARM int StoreByteToTable02109404_020954b0(struct Variant02030b0c* args) {
    unsigned char val = ((Script::Parameter*)args)->ToInt();
    unsigned char idx = ((Script::Parameter*)(args + 1))->ToInt();
    if (idx < 0xcc) {
        unsigned char* base = *(unsigned char**)((char*)&data_02109404 + 0x10);
        base[idx] = val;
    }
    return 1;
}
