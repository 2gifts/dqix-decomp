#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Combat/MapDisplay.h"

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

extern "C" void* func_02012fe4(void);
int StringLength_020d2ff0(const char* text);
extern "C" void* __clear(void* dst, int count);
void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" int func_0205b234(void* selector, short weight, int mode, char* buf, int a, int b);

// USA: func_020230fc  (semantic: FormatAndDispatchWeightedEntries_020230fc)
extern "C" ARM void func_020230fc(MapDisplay* obj, char* buffer, int offset) {
    short a[18];
    short b[18];
    short c[18];
    short d[18];
    struct Struct02020520 arr[18];
    struct S_b20c sel;
    int i;
    int weight;
    int v;
    int roundedV;

#if defined(jpn)
    Zone3D* zone = (Zone3D*)func_02012fe4();
#else
    func_02012fe4();
    __clear(b, 0x24);
#endif
    for (i = 0; i < 0x12; i++) {
        a[i] = i * 8;
#if defined(jpn)
        b[i] = 0;
#endif
        c[i] = 8;
        d[i] = 0x10;
    }

    obj->field5a8 = 0;
#if defined(jpn)
    if (zone->substruct_c_.jpbuffer[0] != 0) {
#else
    if (obj->scriptName[0] != 0) {
#endif
        obj->field5a8 = 1;
        InitWeightedEntries02023064(arr, 0x12, a, b, c, d);

#if defined(jpn)
        int tileCount = (StringLength_020d2ff0(zone->substruct_c_.jpbuffer) / 2 * 10) / 8 + 1;
        weight = tileCount * 8 - StringLength_020d2ff0(zone->substruct_c_.jpbuffer) / 2 * 10;
        weight /= 2;
#else
        v = obj->scriptNameWidth;
        roundedV = (v + 7) & ~7;
        if (v > 0x90) {
            weight = -obj->fieldb3c;
        } else {
            weight = (roundedV - v) >> 1;
        }
#endif

        ClearTwoWordsAndByte_0205b20c(&sel);
        SetField0_0205b220(&sel, (int)(buffer + offset));
        SetFieldsAt0x4And0x8_0205b228(&sel, (int)arr, 0x12);

#if defined(jpn)
        func_0205b234(&sel, (short)weight, 3, zone->substruct_c_.jpbuffer, 10, 15);
#else
        func_0205b234(&sel, (short)weight, 3, obj->scriptName, 0xf, 0);
#endif
    }
}
