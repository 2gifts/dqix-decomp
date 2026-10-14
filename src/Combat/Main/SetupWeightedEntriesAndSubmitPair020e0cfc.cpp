#include <globaldefs.h>

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" int func_020420e8(char*, int);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

extern short data_020ee818[];
extern short data_020ee800[];
extern short data_020ee810[];
extern short data_020ee808[];

// USA: func_020e0cfc
ARM void SetupWeightedEntriesAndSubmitPair020e0cfc(void* obj, int b, int c) {
    struct Struct02020520 arr[4];
    InitWeightedEntries02023064(arr, 4, data_020ee818, data_020ee800, data_020ee810, data_020ee808);

    int len1 = func_020420e8((char*)obj + 0x2f4 + 0x400, 0);
    int len2 = func_020420e8((char*)obj + 0x324 + 0x400, 0);

    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, b + c);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, 4);

    func_0205b234(&localObj, (short)(0x5f - len1), (short)0x14, (int)((char*)obj + 0x2f4 + 0x400), (unsigned char)0xf, (unsigned char)0);
    func_0205b234(&localObj, (short)(0x5f - len2), (short)0x2c, (int)((char*)obj + 0x324 + 0x400), (unsigned char)0xf, (unsigned char)0);
}
