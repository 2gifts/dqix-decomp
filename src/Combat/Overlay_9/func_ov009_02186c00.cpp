#include <globaldefs.h>

struct Vector3fix {
    int x;
    int y;
    int z;
};

extern "C" void func_ov009_02188c2c(void* self);
extern "C" void func_ov009_02188d9c(void* self);
extern "C" void func_ov009_02188e70(void* self, int choice);
extern "C" void func_ov009_02188944(void* self, int choice);
extern "C" int func_ov009_02188ee8(void* self);
void SetStatValue021855dc(unsigned char* self, int state);
void CallFunc020a0db8AtField0x16c(char* camera, int position, int duration);
void CallFunc020a0db8AtField0x194AndClearFlag2(char* camera, int target, int duration);

extern const Vector3fix data_ov009_0218a9f8;
extern const Vector3fix data_ov009_0218aa04;
extern const Vector3fix data_ov009_0218aa10;
extern const Vector3fix data_ov009_0218aa1c;

struct CharacterCreation {
    char unk_0[0x804];
    int targetAngle_;
    char unk_808[0x924 - 0x808];
    char camera_[0x2c8];
    char unk_bec[0xc58 - 0xbec];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd9c - 0xc5a];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char hairStyle_[2];
    unsigned char skinColor_[2];
};

// USA: func_ov009_02186c00
extern "C" ARM void func_ov009_02186c00(CharacterCreation* self)
{
    if (self->step_ == 0)
    {
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        func_ov009_02188e70(self, self->skinColor_[self->sex_]);
        Vector3fix position = data_ov009_0218a9f8;
        Vector3fix target = data_ov009_0218aa04;
        CallFunc020a0db8AtField0x16c(self->camera_, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2(self->camera_, (int)&target, 0x1e000);
        self->targetAngle_ = 0x1eb;
        self->flags_ = (self->flags_ | 8) & ~1;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        if (self->flags_ & 0x80)
            return;
        func_ov009_02188944(self, self->skinColor_[self->sex_]);
        self->step_++;
    }
    else if (self->step_ == 2)
    {
        if (!(self->flags_ & 1) && !(self->flags_ & 8))
            self->flags_ |= 1;
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
            if (state <= self->lastStates_[self->sex_] && state != self->state_)
            {
                SetStatValue021855dc((unsigned char*)self, (unsigned char)state);
                changed = 1;
            }
        }
        if (changed)
        {
            Vector3fix position = data_ov009_0218aa10;
            Vector3fix target = data_ov009_0218aa1c;
            CallFunc020a0db8AtField0x16c(self->camera_, (int)&position, 0x1e000);
            CallFunc020a0db8AtField0x194AndClearFlag2(self->camera_, (int)&target, 0x1e000);
        }
    }
}
