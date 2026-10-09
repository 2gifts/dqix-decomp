#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

struct Foo02048004;
void MaybeInvoke0204719c(struct Foo02048004* obj);

struct NameTable02048080;
void ClearNameTable(struct NameTable02048080* table);

// USA: func_ov004_0215c474  (semantic: InvokeAndClearNameTable_0215c474)
extern "C" ARM void* func_ov004_0215c474(void* self) {
    MaybeInvoke0204719c((struct Foo02048004*)((char*)self + 0x20));
    ClearNameTable((struct NameTable02048080*)((char*)self + 0x34));
    return self;
}
