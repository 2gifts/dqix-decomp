#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern int data_02109a28;

// USA: func_02099c90
ARM int StoreDecodedShortAt0x28_02099c90(struct Variant02030b0c* arg) {
    *(short*)((char*)&data_02109a28 + 0x28) = ((Script::Parameter*)arg)->ToInt();
    return 1;
}
