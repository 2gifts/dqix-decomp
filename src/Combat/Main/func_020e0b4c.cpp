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

extern "C" void _Z27InitWeightedEntries02023064P14Struct02020520jPsS1_S1_S1_(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte(struct S_b20c* obj);
extern "C" void _Z18SetField0_0205b220Pvi(void* obj, int value);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void* obj, int value, unsigned char flag);
int StringLength(const char* s);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

extern short data_020ee864[];
extern short data_020ee87e[];
extern short data_020ee898[];
extern short data_020ee8b2[];

// USA: func_020e0b4c
extern "C" ARM void func_020e0b4c(void* obj, int b, int c) {
    struct Struct02020520 arr[13];
    _Z27InitWeightedEntries02023064P14Struct02020520jPsS1_S1_S1_(arr, 13, data_020ee864, data_020ee87e, data_020ee898, data_020ee8b2);
    struct S_b20c localObj;
    ClearTwoWordsAndByte(&localObj);
    _Z18SetField0_0205b220Pvi(&localObj, b + c);
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&localObj, (int)arr, 13);
    for (int i = 0; i < 3; i++) {
        func_0205b234(&localObj, (short)0xa, (short)(i * 13 + 0x10), (int)((char*)obj + 0x1fc + 0x400 + i * 0x48), (unsigned char)0xf, (unsigned char)0);
        char* s = (char*)obj + 0x2d4 + 0x400 + i * 8;
        if (StringLength(s) == 3) {
            func_0205b234(&localObj, (short)0x74, (short)(i * 13 + 0x10), (int)s, (unsigned char)0xf, (unsigned char)0);
        } else if (StringLength(s) == 2) {
            func_0205b234(&localObj, (short)0x78, (short)(i * 13 + 0x10), (int)s, (unsigned char)0xf, (unsigned char)0);
        } else if (StringLength(s) == 1) {
            func_0205b234(&localObj, (short)0x7d, (short)(i * 13 + 0xf), (int)s, (unsigned char)0xf, (unsigned char)0);
        } else {
            func_0205b234(&localObj, (short)0x74, (short)(i * 13 + 0x10), (int)s, (unsigned char)0xf, (unsigned char)0);
        }
    }
}