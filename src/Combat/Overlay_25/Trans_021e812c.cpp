#include <globaldefs.h>

struct Target021e812c { char pad[0x228]; unsigned int value; };
struct Ctx021e812c { char pad[0xc]; struct Target021e812c* target; };
extern struct Ctx021e812c data_ov025_021ef988;

struct Param021e812c { char pad[8]; unsigned char value; };

// USA: func_ov025_021e812c  (semantic: Trans_021e812c)
extern "C" ARM int func_ov025_021e812c(struct Param021e812c* p) {
    data_ov025_021ef988.target->value = p->value;
    return 1;
}
