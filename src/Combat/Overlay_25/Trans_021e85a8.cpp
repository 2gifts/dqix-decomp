#include <globaldefs.h>

struct Target021e85a8 { char pad[0x74a]; unsigned short value; };
struct Ctx021e85a8 { char pad[0xc]; struct Target021e85a8* target; };
extern struct Ctx021e85a8 data_ov025_021ef988;

struct Param021e85a8 { char pad[8]; unsigned short value; };

// USA: func_ov025_021e85a8  (semantic: Trans_021e85a8)
extern "C" ARM int func_ov025_021e85a8(struct Param021e85a8* p) {
    data_ov025_021ef988.target->value = p->value;
    return 1;
}
