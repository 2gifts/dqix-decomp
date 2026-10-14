#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct TableRow020a6090 { unsigned short v[16]; };
extern struct TableRow020a6090 data_02109dcc[];

// USA: func_020a6090
ARM int PopulateTableRow020a6090(void* param) {
    unsigned char index = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)param))->ToInt();
    struct TableRow020a6090* e = &data_02109dcc[index];
    e->v[0] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x8)))->ToInt();
    e->v[1] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x10)))->ToInt();
    e->v[2] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x18)))->ToInt();
    e->v[3] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x20)))->ToInt();
    e->v[4] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x28)))->ToInt();
    e->v[5] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x30)))->ToInt();
    e->v[6] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x38)))->ToInt();
    e->v[7] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x40)))->ToInt();
    e->v[8] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x48)))->ToInt();
    e->v[9] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x50)))->ToInt();
    e->v[10] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x58)))->ToInt();
    e->v[11] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x60)))->ToInt();
    e->v[12] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x68)))->ToInt();
    e->v[13] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x70)))->ToInt();
    e->v[14] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x78)))->ToInt();
    e->v[15] = ((Script::Parameter*)((struct Variant02030b0c*)((char*)param + 0x80)))->ToInt();
    return 1;
}
