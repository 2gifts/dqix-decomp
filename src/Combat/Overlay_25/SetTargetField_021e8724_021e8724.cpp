#include <globaldefs.h>

struct Ctx021ef988 {
#if defined(jpn)
    char pad[4];
#else
    char pad[0xc];
#endif
    void* target;
};
extern struct Ctx021ef988 data_ov025_021ef988;

struct Param021e8724 { char pad[8]; unsigned char value; };

// USA: func_ov025_021e8724
ARM int SetTargetField_021e8724_021e8724(struct Param021e8724* p) {
    *(unsigned char*)((char*)data_ov025_021ef988.target + 0x5d0) = p->value;
    return 1;
}
