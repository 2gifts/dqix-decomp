#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Memory.h"

struct Obj020827c4 { char field_0x0[0x1c]; };
extern "C" void _Z26InitFlagsAndTimers020827c4P11Obj020827c4(Obj020827c4*);

struct Settings02098364 {
    char field_0x0[11];
    unsigned char mode : 7;
    unsigned char enabled : 1;
    unsigned int field_0xc_0 : 4;
    unsigned int field_0xc_4 : 4;
    unsigned int field_0xc_8 : 7;
    unsigned int field_0xc_15 : 4;
    unsigned int field_0xc_19 : 5;
    unsigned int field_0xc_24 : 6;
    unsigned int field_0xc_30 : 1;
    unsigned int field_0xc_31 : 1;
    unsigned int field_0x10_0 : 2;
    unsigned int field_0x10_2 : 30;
    char field_0x14[6];
    Obj020827c4 timers;
    char field_0x36[2];
    char field_0x38[0x18];
    char field_0x50[0x1c];
    unsigned int interval : 12;
    unsigned int rate : 4;
    unsigned int count : 5;
    unsigned int field_0x6c_21 : 4;
    unsigned int flag25 : 1;
    unsigned int flag26 : 1;
    unsigned int flag27 : 1;
    unsigned int flag28 : 1;
    unsigned int flag29 : 1;
    unsigned int flag30 : 1;
    unsigned int flag31 : 1;
    unsigned int limit : 9;
    unsigned int duration : 10;
    unsigned int scale : 11;
    unsigned int flag_0x70_30 : 1;
    unsigned int flag_0x70_31 : 1;
    unsigned char field_0x74;
};

// USA: func_02098364
extern "C" ARM void func_02098364(Settings02098364* settings) {
    memset(settings, 0, 11);
    settings->field_0xc_0 = 0;
    settings->field_0xc_4 = 0;
    settings->mode = 0;
    settings->field_0xc_15 = 0;
    settings->field_0xc_19 = 0;
    settings->field_0xc_24 = 0;
    settings->field_0xc_30 = 0;
    settings->field_0x10_0 = 0;
    settings->field_0xc_31 = 0;
    settings->enabled = 0;
    settings->field_0x10_2 = 0;
    VectorizedMemset(settings->field_0x14, 0, 6);
    settings->interval = 2000;
    settings->rate = 1;
    settings->count = 1;
    settings->flag28 = 0;
    settings->field_0x6c_21 = 0;
    settings->flag27 = 0;
    settings->flag25 = 0;
    settings->flag26 = 0;
    settings->flag29 = 0;
    settings->flag30 = 1;
    settings->flag31 = 0;
    settings->limit = 511;
    settings->flag_0x70_30 = 0;
    settings->duration = 300;
    settings->scale = 706;
    settings->field_0x74 = 0;
    _Z26InitFlagsAndTimers020827c4P11Obj020827c4(&settings->timers);
    VectorizedMemset(settings->field_0x38, 0, 0x18);
    VectorizedMemset(settings->field_0x50, 0, 0x1c);
}
