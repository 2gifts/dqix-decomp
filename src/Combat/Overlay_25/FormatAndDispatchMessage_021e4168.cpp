#include <globaldefs.h>

#if defined(jpn)
#define func_ov025_021e4168 func_ov025_021e4658
#define data_ov025_021ef7ef data_ov025_021efacf
#endif
#include "std_library_functions.h"

extern char data_ov025_021ef7ef;
extern "C" void func_ov025_021e27c8(char* buf, signed char kind);

struct Param_021e4168 {
    unsigned char pad[8];
    signed char field8;
    unsigned char pad2[3];
    int fieldC;
};

// USA: func_ov025_021e4168  (semantic: FormatAndDispatchMessage_021e4168)
extern "C" ARM int func_ov025_021e4168(struct Param_021e4168* p) {
    char buf[0x50];
    sprintf(buf, &data_ov025_021ef7ef, p->fieldC);
    func_ov025_021e27c8(buf, p->field8);
    return 1;
}
