#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
#define _Z20SetStatValue021855dcPhi func_ov009_021867bc
#endif

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int val);
extern "C" void func_ov009_02188944(CharacterCreationUI* self, int val);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
extern "C" ARM void _Z20SetStatValue021855dcPhi(unsigned char* self, int val);

int CallFunc020a0db8AtField0x16c_0202ee38(char* obj, int a, int b);
void CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(char* obj, int a, int b);

#if defined(jpn)
#define data_ov009_0218a9c8 data_ov009_0218b9a4
#endif
extern Vector3fix data_ov009_0218a9c8;
#if defined(jpn)
#define data_ov009_0218a9d4 data_ov009_0218b9b0
#endif
extern Vector3fix data_ov009_0218a9d4;
#if defined(jpn)
#define data_ov009_0218a9e0 data_ov009_0218b9bc
#endif
extern Vector3fix data_ov009_0218a9e0;
#if defined(jpn)
#define data_ov009_0218a9ec data_ov009_0218b9c8
#endif
extern Vector3fix data_ov009_0218a9ec;

// USA: func_ov009_021866f0  (semantic: AdvanceStatStep_021866f0)
extern "C" ARM void func_ov009_021866f0(CharacterCreationUI* self) {
    unsigned char step = self->step;
    if (step == 0) {
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        int idx = self->sex;
        unsigned char val = self->faceStyle[idx];
        func_ov009_02188e70(self, val);

        Vector3fix position = data_ov009_0218a9c8;
        Vector3fix target = data_ov009_0218a9d4;
        CallFunc020a0db8AtField0x16c_0202ee38((char*)self->camera, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58((char*)self->camera, (int)&target, 0x1e000);

        self->flags |= 1;
        self->step = self->step + 1;
        return;
    }
    if (step == 1) {
        if (self->flags & 0x80) {
            return;
        }
        int idx = self->sex;
        unsigned char val = self->faceStyle[idx];
        func_ov009_02188944(self, val);
        self->step = self->step + 1;
        return;
    }
    if (step != 2) {
        return;
    }

    int result = func_ov009_02188ee8(self);
    int flag = 0;
    if (result == -2) {
        _Z20SetStatValue021855dcPhi((unsigned char*)self, 6);
        flag = 1;
    } else if (result == -3) {
        _Z20SetStatValue021855dcPhi((unsigned char*)self, 4);
        flag = 1;
    } else if (result >= 0x65 && result <= 0x6c) {
        int idx = self->sex;
        int v = result - 0x64;
        signed char arrv = self->furthestState[idx];
        if (v <= arrv) {
            signed char cur = self->state;
            if (v != cur) {
                _Z20SetStatValue021855dcPhi((unsigned char*)self, v & 0xff);
                flag = 1;
            }
        }
    }

    if (flag != 0) {
        Vector3fix position = data_ov009_0218a9e0;
        Vector3fix target = data_ov009_0218a9ec;
        CallFunc020a0db8AtField0x16c_0202ee38((char*)self->camera, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58((char*)self->camera, (int)&target, 0x1e000);
    }
}
