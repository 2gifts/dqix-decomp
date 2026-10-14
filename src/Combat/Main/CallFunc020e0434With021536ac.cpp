#include <globaldefs.h>
int GetFieldByKey020e0434(struct Container020e0310 *, int);

extern int data_021536ac;

// USA: func_020e51e4
ARM int CallFunc020e0434With021536ac_020e51e4(int value) {
    return GetFieldByKey020e0434((struct Container020e0310 *)(&data_021536ac), (int)(value));
}
