#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct020A8218;
extern void AllocateArray020a8218(Struct020A8218*, int, int);

struct Data02109fe0 {
    void* allocator;
    Struct020A8218* out;
};
extern Data02109fe0 data_02109fe0;

// USA: func_020a7f5c
ARM int RegisterAndAllocateArray020a7f5c(Variant02030b0c* variant) {
    AllocateArray020a8218(data_02109fe0.out, (int)data_02109fe0.allocator, (unsigned short)((Script::Parameter*)variant)->ToInt());
    return 1;
}
