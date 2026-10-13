#include <globaldefs.h>

extern int data_ov028_021d9aec;
extern int data_ov028_021d9b14;
extern "C" void _Z17DisarmVCountAlarmP16AlarmCtx020c949c(void* alarm);
extern "C" void _Z20ResetFields_021d94e4Pv(void* p);

// USA: func_ov028_021d9714  (semantic: Trans_021d9714)
extern "C" ARM void func_ov028_021d9714(void) {
    _Z17DisarmVCountAlarmP16AlarmCtx020c949c(&data_ov028_021d9aec);
    _Z20ResetFields_021d94e4Pv(&data_ov028_021d9b14);
}
