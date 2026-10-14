#include <globaldefs.h>

int GetSignedField020c39c8(volatile unsigned short* p);
extern "C" int abs(int x);
unsigned short GetMaskedKeyInput_02012354(void);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

struct InputStickState_0201229c {
    unsigned short f0;
    unsigned short f2;
    char pad4[24];
    unsigned char f1c;
};

// USA: func_0201229c  (semantic: UpdateInputStateAndBit_0201229c)
extern "C" ARM void func_0201229c(struct InputStickState_0201229c* obj) {
    int flag;
    void* data;
    int x, sum;

    flag = 0;
    if (obj->f1c == 0) {
        goto setFlag;
    }
    if ((*(unsigned short*)0x27fffa8 & 0x8000) >> 15) {
        goto setFlag;
    }
    x = GetSignedField020c39c8((volatile unsigned short*)0x400106c);
    sum = abs(GetSignedField020c39c8((volatile unsigned short*)0x400006c)) + abs(x);
    if (sum < 0x20) {
        goto skipFlag;
    }
setFlag:
    flag = 1;
skipFlag:
    if (flag != 0) {
        obj->f2 = 0;
        obj->f0 = 0;
        return;
    }
    obj->f2 = obj->f0;
    obj->f0 = GetMaskedKeyInput_02012354();
    if (obj->f0 == 0) {
        return;
    }
    data = func_0205ec34();
    SetOrClearBitInArray_0206df6c(data, (unsigned char*)data + 0x8c, 0x113e, 1);
}
