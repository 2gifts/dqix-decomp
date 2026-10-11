#include <globaldefs.h>
#include "GameState/GameState.h"

int CalculateAge(int birthYear, int birthMonth, int birthDay);

struct DaysTable021e61f4 { int v[12]; };
extern struct DaysTable021e61f4 data_ov023_021fd72c;

// JPN: func_ov023_021e63d8
// USA: func_ov023_021e61f4  (semantic: CheckBirthdayFlags_021e61f4)
extern "C" ARM void func_ov023_021e61f4(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x1373, regionalOffset1=0x1454, regionalOffset2=0x1456, regionalOffset3=0x1457};
#else
 enum {regionalOffset0=0x13ab, regionalOffset1=0x13fc, regionalOffset2=0x13fe, regionalOffset3=0x13ff};
#endif
    struct DaysTable021e61f4 daysInMonth = data_ov023_021fd72c;
    char* base = (char*)obj;
    *(unsigned char*)(base + regionalOffset0) = 0;

    GameState::GetInstance();

    int age = CalculateAge(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2), *(unsigned char*)(base + regionalOffset3));
    if (age < 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x2;
    if (age > 0) *(unsigned char*)(base + regionalOffset0) |= 0x1;

    if (*(unsigned char*)(base + regionalOffset2) < 12) {
        int age2 = CalculateAge(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2) + 1, *(unsigned char*)(base + regionalOffset3));
        if (age2 >= 0) *(unsigned char*)(base + regionalOffset0) |= 0x4;
    }
    if (*(unsigned char*)(base + regionalOffset2) > 1) {
        int age3 = CalculateAge(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2) - 1, *(unsigned char*)(base + regionalOffset3));
        if (age3 <= 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x8;
    }

    if (*(unsigned short*)(base + regionalOffset1) % 4 == 0) daysInMonth.v[1] = 29;
    unsigned char month = *(unsigned char*)(base + regionalOffset2);
    unsigned char day = *(unsigned char*)(base + regionalOffset3);
    if (day < daysInMonth.v[month - 1]) {
        int age4 = CalculateAge(*(unsigned short*)(base + regionalOffset1), month, day + 1);
        if (age4 >= 0) *(unsigned char*)(base + regionalOffset0) |= 0x10;
    }

    if (*(unsigned char*)(base + regionalOffset3) > 1) {
        int age5 = CalculateAge(*(unsigned short*)(base + regionalOffset1), *(unsigned char*)(base + regionalOffset2), *(unsigned char*)(base + regionalOffset3) - 1);
        if (age5 <= 0x82) *(unsigned char*)(base + regionalOffset0) |= 0x20;
    }
}
