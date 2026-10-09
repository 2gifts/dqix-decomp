#include <globaldefs.h>
#include "std_library_functions.h"
struct Packed020e4f18 { unsigned int field_0x0_0:6, field_0x0_6:6, field_0x0_12:6, field_0x0_18:6, field_0x0_24:2, field_0x0_26:1, field_0x0_27:1, field_0x0_28:1, pad:2, flag:1; };
struct Description020e4f18 { char* name; char* text; Packed020e4f18 bits; };
// USA: func_020e4f18
extern "C" ARM void func_020e4f18(Description020e4f18* src, Description020e4f18* dest, int flags) {
    if (!src || !dest) return;
    if (flags & 1) {
        char* text = dest->text;
        sprintf(dest->name, src->name);
        sprintf(text, src->text);
    }
    if (flags & 2) {
        dest->bits.field_0x0_0 = src->bits.field_0x0_0;
        dest->bits.field_0x0_6 = src->bits.field_0x0_6;
        dest->bits.field_0x0_12 = src->bits.field_0x0_12;
        dest->bits.field_0x0_18 = src->bits.field_0x0_18;
    }
    dest->bits.field_0x0_24 = src->bits.field_0x0_24;
    dest->bits.field_0x0_26 = src->bits.field_0x0_26;
    dest->bits.field_0x0_27 = src->bits.field_0x0_27;
    dest->bits.field_0x0_28 = src->bits.field_0x0_28;
    dest->bits.flag = src->bits.flag;
}
