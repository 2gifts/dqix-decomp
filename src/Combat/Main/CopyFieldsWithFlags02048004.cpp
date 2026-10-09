#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// USA: func_02048004
ARM void CopyFieldsWithFlags02048004(Foo02048004* src, Foo02048004* dst)
{
    dst->f6 = src->f6;
    dst->w8 = src->w8;
    dst->wc = src->wc;
    dst->w10 = src->w10;
    dst->nameTable.count = src->nameTable.count;
    dst->nameTable.entries = src->nameTable.entries;
    dst->f4 = src->f4;
    dst->bit1 = src->bit1;
    dst->bit0 = src->bit0;
}
