#if defined(jpn)
enum { RegionalOffset = 0x4214 };
#else
enum { RegionalOffset = 0x44c4 };
#endif

#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
extern "C" int* func_0202ae18(void);
extern "C" char* func_ov017_0218b5b0(void);
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021d0924(int kind, unsigned char index, int flags, unsigned short packedTime);

extern "C" void _Z14GetEntry3BytesP9EntryDEE8iPhS1_S1_(void* base, unsigned char index, unsigned char* outA, unsigned char* outB, unsigned char* outC);
#define GetEntry3Bytes _Z14GetEntry3BytesP9EntryDEE8iPhS1_S1_

extern "C" void _Z14SetEntry3BytesP9EntryDEC8ihhh(void* base, unsigned char index, unsigned char a, unsigned char b, unsigned char c);
#define SetEntry3Bytes _Z14SetEntry3BytesP9EntryDEC8ihhh

extern "C" void _Z20ClearRegions0206e080Pci(char* base, int index);
extern "C" void _Z31ClearIndexedEntryFields0206e0d0Pci(char* base, int index);
extern "C" void _Z23ClearTwoRegions0206ebf4Pc(char* obj);
int CheckField0NonZero(int* obj);
void ApplySlotBytesToBattleStruct(unsigned char* obj);

// USA: func_020703c8
// JPN: func_020703c8
extern "C" ARM void func_020703c8(int index, int hour, int minute, int second) {
    unsigned char curHour;
    unsigned char curMinute;
    unsigned char curSecond;
    void* entry = func_0205ec34();
    int* state = func_0202ae18();
    char* owner = *(char**)(func_ov017_0218b5b0() + RegionalOffset);

    GetEntry3Bytes(entry, index, &curHour, &curMinute, &curSecond);
    if (curSecond + (curHour * 10000 + curMinute * 100) >= second + (hour * 10000 + minute * 100)) {
        return;
    }
    if (curHour != hour) {
        _Z20ClearRegions0206e080Pci((char*)entry, index);
        _Z23ClearTwoRegions0206ebf4Pc(owner);
    } else if (curMinute != minute) {
        _Z31ClearIndexedEntryFields0206e0d0Pci((char*)entry, index);
        _Z23ClearTwoRegions0206ebf4Pc(owner);
    }
    SetEntry3Bytes(entry, index, hour, minute, second);
    if (CheckField0NonZero(state) != 0 && func_0202c508(state) != 0) {
        func_ov017_021d0924(2, index, 0, second | (hour << 10 | minute << 5));
    }
    ApplySlotBytesToBattleStruct((unsigned char*)entry);
}
