#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"

void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

extern "C" void func_0205308c(void* obj, int val);
extern "C" void func_ov017_021cc1f8(int a, void* buf, int len, int extra);

unsigned char GetField0x397cValue(GameState* battleStruct);
int GetFieldIfFlag4(char* obj);

struct S020a2c70;
int MarkStateIfFlag020a2c70(struct S020a2c70* p);

struct BitsC102052f44 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Obj02052f44 {
    char pad0[0x4];
    short field4;
    char pad6[0xc1 - 0x6];
    struct BitsC102052f44 fc1;
    char padc2[(IS_JPN ? 0x16c : 0x178) - 0xc2];
    signed char f178[1];
    char pad179[0x17c - 0x179];
    signed char f17c;
    signed char f17d;
    signed char f17e;
    char pad17f[0x180 - 0x17f];
    int f180;
    signed char f184;
    signed char f185;
    signed char f186;
    char pad187[0x190 - 0x187];
    int f190;
    int f194;
};

// USA: func_02052f44
ARM int FilterBytesAndInit02052f44(struct Obj02052f44* obj, signed char* src, int len) {
    int count;
    int i;
    signed char idx;
    signed char val;
    GameState* battleStruct;

    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 2)) {
        return 0;
    }

    if (len > 4) {
        return 0;
    }

    {
        int flag17c = (((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x70 : 0x7c)] > 0);
        if (flag17c) {
            return 0;
        }
    }

    count = 0;
    for (i = 0; i < len; i++) {
        signed char c = src[i];
        if (c > 0 && c < 0x21) {
            obj->f178[count] = c;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    obj->f17c = count;
    obj->f17d = 0;
    obj->f180 = -1;
    obj->f17e = 0;
    obj->f184 = 0;
    obj->f190 = 0;
    obj->f194 = -1;
    obj->f185 = 0;
    obj->f186 = 0;

    idx = ((signed char*)((char*)obj + 0x100))[(IS_JPN ? 0x71 : 0x7d)];
    {
        char* base = (char*)obj + idx;
        base = base + 0x100;
        val = ((signed char*)base)[(IS_JPN ? 0x6c : 0x78)];
    }
    func_0205308c(obj, val);

    func_ov017_021cc1f8(obj->field4, src, len, 0);

    obj->fc1.mode |= 2;

    {
        short field4;
        battleStruct = GameState::GetInstance();
        field4 = obj->field4;
        obj = (struct Obj02052f44*)battleStruct;
        unsigned char cur = GetField0x397cValue((GameState*)obj);
        if (cur == field4) {
            int r = GetFieldIfFlag4((char*)obj);
            if (r != 0) {
                MarkStateIfFlag020a2c70((struct S020a2c70*)r);
            }
        }
    }

    return 1;
}
