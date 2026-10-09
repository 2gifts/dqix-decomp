#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"


void MaybeInvoke0204719c(struct Foo02048004* obj);
void ClearNameTable(struct NameTable02048080* table);

// USA: func_ov011_0218513c
ARM void* InitField20And34_0218513c(void* obj) {
    MaybeInvoke0204719c((struct Foo02048004*)((char*)obj + 0x20));
    ClearNameTable((struct NameTable02048080*)((char*)obj + 0x34));
    return obj;
}
