#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

#if defined(jpn)
#define func_ov009_02188ee8 func_ov009_02189e04
#define _Z20SetStatValue021855dcPhi func_ov009_021867bc
#endif

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int choice);
extern "C" void func_ov009_02188944(CharacterCreationUI* self, int choice);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
#if defined(jpn)
extern "C" void func_ov009_021867bc(unsigned char*, int);
#define SetStatValue021855dc func_ov009_021867bc
#else
void SetStatValue021855dc(unsigned char* self, int state);
#endif
void CallFunc020a0db8AtField0x16c(char* camera, int position, int duration);
void CallFunc020a0db8AtField0x194AndClearFlag2(char* camera, int target, int duration);

#if defined(jpn)
#define data_ov009_0218a9f8 data_ov009_0218b9d4
#endif
extern const Vector3fix data_ov009_0218a9f8;
#if defined(jpn)
#define data_ov009_0218aa04 data_ov009_0218b9e0
#endif
extern const Vector3fix data_ov009_0218aa04;
#if defined(jpn)
#define data_ov009_0218aa10 data_ov009_0218b9ec
#endif
extern const Vector3fix data_ov009_0218aa10;
#if defined(jpn)
#define data_ov009_0218aa1c data_ov009_0218b9f8
#endif
extern const Vector3fix data_ov009_0218aa1c;

// USA: func_ov009_02186c00
extern "C" ARM void func_ov009_02186c00(CharacterCreationUI* self)
{
    if (self->step == 0)
    {
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        func_ov009_02188e70(self, self->skinColor[self->sex]);
        Vector3fix position = data_ov009_0218a9f8;
        Vector3fix target = data_ov009_0218aa04;
        CallFunc020a0db8AtField0x16c((char*)self->camera, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2((char*)self->camera, (int)&target, 0x1e000);
        self->targetAngle = 0x1eb;
        self->flags = (self->flags | 8) & ~1;
        self->step++;
    }
    else if (self->step == 1)
    {
        if (self->flags & 0x80)
            return;
        func_ov009_02188944(self, self->skinColor[self->sex]);
        self->step++;
    }
    else if (self->step == 2)
    {
        if (!(self->flags & 1) && !(self->flags & 8))
            self->flags |= 1;
        int result = func_ov009_02188ee8(self);
        int changed = 0;
        if (result == -2)
        {
            SetStatValue021855dc((unsigned char*)self, 8);
            changed = 1;
        }
        else if (result == -3)
        {
            SetStatValue021855dc((unsigned char*)self, 6);
            changed = 1;
        }
        else if (result >= 101 && result <= 108)
        {
            int state = result - 100;
            if (state <= self->furthestState[self->sex] && state != self->state)
            {
                SetStatValue021855dc((unsigned char*)self, (unsigned char)state);
                changed = 1;
            }
        }
        if (changed)
        {
            Vector3fix position = data_ov009_0218aa10;
            Vector3fix target = data_ov009_0218aa1c;
            CallFunc020a0db8AtField0x16c((char*)self->camera, (int)&position, 0x1e000);
            CallFunc020a0db8AtField0x194AndClearFlag2((char*)self->camera, (int)&target, 0x1e000);
        }
    }
}
