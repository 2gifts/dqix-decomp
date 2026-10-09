#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
struct Packed020e4ce8 {
    unsigned int field_0x0_0:6, field_0x0_6:6, field_0x0_12:6, field_0x0_18:6, field_0x0_24:2, field_0x0_26:1, field_0x0_27:1, field_0x0_28:1, reserved:2, flag:1;
};
struct Description020e4ce8 { int field_0x0; int field_0x4; union { unsigned int raw; Packed020e4ce8 bits; } field_0x8; };
struct Detail020e4ce8 { char pad[0x14]; void* stats; Packed020e4ce8 bits; };
struct Source020e4ce8 { char pad[0x144]; Detail020e4ce8* detail; char pad148[4]; char name[1]; };
struct Struct0200fb08;
extern "C" unsigned char _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
int StringLength(const char*);
extern "C" void func_020e4b34(void*, const char*, void*, unsigned int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
// USA: func_020e4ce8
extern "C" ARM void func_020e4ce8(Description020e4ce8* dest, Source020e4ce8* src, int flag) {
    memset(dest, 0, 12);
    if (src) {
        Detail020e4ce8* detail = src->detail;
        const char* name = src->name;
        func_020e4b34(dest, name, detail->stats, (unsigned char)detail->bits.field_0x0_0,
            detail->bits.field_0x0_6, detail->bits.field_0x0_12, detail->bits.field_0x0_18,
            detail->bits.field_0x0_24, detail->bits.field_0x0_26, detail->bits.field_0x0_27,
            detail->bits.field_0x0_28, 0);
        int count = StringLength(name);
        int suffix;
        if (count && name[count - 1] >= 'A' && name[count - 1] <= 'Z') suffix = name[count - 1];
        else suffix = 0;
        if (suffix && flag) {
            if (_Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance()) == 1) {
                dest->field_0x8.bits.field_0x0_12 = 0;
                dest->field_0x8.bits.field_0x0_0 = 0;
            }
            dest->field_0x8.bits.flag = 1;
        }
    }
}
