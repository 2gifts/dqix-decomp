#include <globaldefs.h>
#include "GameState/GameState.h"

struct PackedField017 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int f16 : 5;
    unsigned int f21 : 5;
    unsigned int top : 6;
};

struct CalendarDate {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int weekday;
};

struct CalendarTime {
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

struct DownloadedEntry {
    short id;
    unsigned short unknown02;
    unsigned int value : 7;
    unsigned int unknown04 : 25;
    unsigned char unknown08[0x20];
};

struct DownloadedData {
    short unknown00;
    unsigned short unknown02;
    DownloadedEntry entries[6];
    PackedField017 start;
    short itemId;
    unsigned short unknownFA;
    unsigned short price;
    unsigned short unknownFE;
    PackedField017 end;
    PackedField017 timestamp;
    unsigned int unknown108;
    unsigned short flags : 13;
    unsigned short unknownFlags : 3;
    unsigned short unknown10E;
};

struct Struct_02245528;
extern "C" void func_ov031_022125c8();
extern "C" int func_ov031_0221268c();
extern "C" void func_ov031_022120f8();
void SetField34AndClear35_37_02245528(Struct_02245528*, int);
extern "C" int func_ov031_0221244c(void*, void*);
extern "C" int func_ov017_021b2090(PackedField017, PackedField017);
void CallStub022169a0_02212784();
extern "C" void func_ov031_02245478(Struct_02245528*);

#if defined(jpn)
void SetDataFromIndex_02211c50(int);
extern unsigned char data_ov031_0224a1b4[];
#endif

// USA: func_ov031_02243e34
extern "C" ARM void func_ov031_02243e34(void* object) {
    unsigned char* state = (unsigned char*)object;
    switch (state[0x35]) {
    case 0:
#if defined(jpn)
        SetDataFromIndex_02211c50(2);
#endif
        state[0x35] = 4;
        break;
    case 4:
        func_ov031_022125c8();
        state[0x35] = 5;
        break;
    case 5: {
        int result = func_ov031_0221268c();
        if (result == 3) state[0x35] = 6;
        else if (result == 4) state[0x35] = 8;
        else if (result == 5 || result == 0) {
            func_ov031_022120f8();
            SetField34AndClear35_37_02245528((Struct_02245528*)object, 0);
        }
        int& timer = *(int*)(state + 0x384);
        if (timer < 0x46000) timer += 0x333;
        break;
    }
    case 6: {
        CalendarDate date;
        CalendarTime time;
        if (func_ov031_0221244c(&date, &time)) {
            date.year += 2000;
#if defined(jpn)
            time.hours += 9;
            if (time.hours >= 24) {
                time.hours -= 24;
                ++date.day;
                unsigned int monthLength = *(const unsigned int*)(data_ov031_0224a1b4 + date.month * sizeof(unsigned int));
                if (monthLength < date.day) {
                    date.day = 1;
                    if (++date.month > 12) {
                        date.month = 1;
                        ++date.year;
                    }
                }
            }
#endif
            PackedField017& timestamp = *(PackedField017*)(state + 0x378);
            timestamp.low = date.year;
            timestamp.f12 = date.month;
            timestamp.f16 = date.day;
            timestamp.f21 = time.hours;
            timestamp.top = time.minutes;
            state[0x44] |= 4;
            if (state[0x374] & 0x10) {
#if defined(jpn)
                DownloadedData* downloaded = (DownloadedData*)((char*)GameState::GetInstance() + 0x5c0c);
#else
                DownloadedData* downloaded = (DownloadedData*)((char*)GameState::GetInstance() + 0x5e6c);
#endif
                bool earlier = func_ov017_021b2090(downloaded->timestamp, timestamp) != 0;
                if (!earlier) {
                    state[0x44] |= 0x80;
                    state[0x374] &= ~1;
                }
            }
        } else state[0x374] &= ~1;
        if (state[0x374] & 0x80) state[0x35] = 7;
        else if (state[0x374] & 2) {
            state[0x3d0] = 1;
            SetField34AndClear35_37_02245528((Struct_02245528*)object, 5);
        } else if (!(state[0x374] & 1)) state[0x35] = 7;
        else SetField34AndClear35_37_02245528((Struct_02245528*)object, 4);
        break;
    }
    case 7:
        CallStub022169a0_02212784();
        state[0x35] = 5;
        break;
    case 8:
        func_ov031_02245478((Struct_02245528*)object);
        func_ov031_022120f8();
        break;
    }
}
