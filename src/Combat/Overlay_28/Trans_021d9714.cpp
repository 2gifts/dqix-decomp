#include <globaldefs.h>

extern int data_ov028_021d9aec;
extern int data_ov028_021d9b14;
struct AlarmCtx020c949c;
void DisarmVCountAlarm(AlarmCtx020c949c*);
void ResetFields_021d94e4(void* p);

// USA: func_ov028_021d9714  (semantic: Trans_021d9714)
extern "C" ARM void func_ov028_021d9714(void) {
    DisarmVCountAlarm((AlarmCtx020c949c*)&data_ov028_021d9aec);
    ResetFields_021d94e4(&data_ov028_021d9b14);
}
