#include <globaldefs.h>
void RegisterSlotA020cf0fc(int);

struct Date02098f20 { int year; int month; int day; int pad; };

// USA: func_02098f20
ARM int CalculateAge_02098f20(int birthYear, int birthMonth, int birthDay) {
    struct Date02098f20 now;
    int age;
    RegisterSlotA020cf0fc((int)(&now));
    now.year += 0x7d0;
    age = now.year - birthYear;
    if (birthMonth * 100 + birthDay > now.month * 100 + now.day) age -= 1;
    return age;
}
