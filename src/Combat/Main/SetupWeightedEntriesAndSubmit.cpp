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
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

extern short data_020ee82c[];
extern short data_020ee848[];
extern short data_020ee856[];
extern short data_020ee83a[];

// USA: func_020e0df8
ARM void SetupWeightedEntriesAndSubmit_020e0df8(void* obj, int b, int c, int) {
    struct Struct02020520 arr[7];
    InitWeightedEntries02023064(arr, 7, data_020ee82c, data_020ee848, data_020ee856, data_020ee83a);
    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, b + c);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, 7);
    int ret = func_0205b234((void*)&localObj, (short)6, (short)2, (int)((char*)obj + 0x1b4 + 0x400), (unsigned char)0xf, (unsigned char)0);
    short val = ret + 9;
    func_0205b234((void*)&localObj, val, (short)2, (int)((char*)obj + 0x1f4 + 0x400), (unsigned char)0xf, (unsigned char)0);
}
