#include <globaldefs.h>

struct GetTableByteOrFFData { unsigned char pad[0xac]; unsigned char tbl[0xcc]; };

// USA: func_020965ac
ARM unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData* s, unsigned char idx) {
    if (idx < 0xcc) {
        return s->tbl[idx];
    }
    return 0xff;
}
