#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_0215a5dc func_ov006_0215bbd4
#define _Z25SetByte_021571b8_021571b8Pvh func_ov006_021587c0
#define _Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct func_ov006_021587d4
enum { kChildPointerOffset = 8 };
#else
enum { kChildPointerOffset = 0x10 };
#endif

struct CallIfFlag0x800_021571ccStruct;
struct ChildByteUpdate {
    unsigned char unknown[kChildPointerOffset];
    CallIfFlag0x800_021571ccStruct* child;
    unsigned char unknownAfterChild[0x38b - kChildPointerOffset - 4];
    unsigned char value;
};

extern "C" void _Z25SetByte_021571b8_021571b8Pvh(void*, unsigned char);
extern "C" void _Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct(CallIfFlag0x800_021571ccStruct*);

// USA: func_ov006_0215a5dc
extern "C" ARM void func_ov006_0215a5dc(ChildByteUpdate* self) {
    _Z25SetByte_021571b8_021571b8Pvh(self->child, self->value);
    _Z28CallIfFlag_021571cc_021571ccP30CallIfFlag0x800_021571ccStruct(self->child);
}
