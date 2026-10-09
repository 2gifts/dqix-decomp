#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// USA: func_02048080
ARM void ClearNameTable(NameTable02048080* table)
{
    table->count = 0;
    table->entries = NULL;
}
