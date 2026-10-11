#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// USA: func_0204719c
extern "C" ARM void func_0204719c(void* obj)
{
    Foo02048004* f = (Foo02048004*)obj;

    f->word0 = 0;
    f->f6 = 0;
    f->w8 = 0;
    f->wc = 0;
    f->nameTable.count = 0;
    f->f4 = 3;
    f->w10 = 0;
    f->bit0 = 0;
    f->words1c[23] = f->words1c[24] = 0;
    f->words1c[21] = f->words1c[22] = 0;
    f->words1c[0] = 0;
    f->words1c[1] = 0;
    f->words1c[2] = 0;
    f->words1c[3] = 0;
    f->words1c[4] = 0;
    f->words1c[5] = 0;
    f->words1c[6] = 0x1000;
    f->words1c[7] = 0x1000;
    f->words1c[8] = 0x1000;
    f->field82 = 0x1f;
    f->field80 = 0x7fff;
    f->bit1 = 0;
    f->bit2 = 0;
}
