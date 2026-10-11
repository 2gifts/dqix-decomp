#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;

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
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

extern short data_020ee8e8[];
extern short data_020ee8cc[];
extern short data_020ee920[];
extern short data_020ee904[];
extern const short data_020ee820[];

// USA: func_020e0ec4
extern "C" ARM void func_020e0ec4(void* obj, int b, int c) {
    struct Struct02020520 arr[14];
    _Z27InitWeightedEntries02023064P14Struct02020520jPsS1_S1_S1_(arr, 14, data_020ee920, data_020ee8cc, data_020ee8e8, data_020ee904);
    struct S_b20c localObj;
    ClearTwoWordsAndByte(&localObj);
    _Z18SetField0_0205b220Pvi(&localObj, b + c);
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&localObj, (int)arr, 14);

    int idx = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance());
    func_0205b234(&localObj, data_020ee820[idx], (short)6, (int)((char*)obj + 0x2ec + 0x400), (unsigned char)0xf, (unsigned char)0);
}
