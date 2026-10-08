#include <globaldefs.h>

struct Vector3fix {
    int x;
    int y;
    int z;
};

struct TouchState {
    char unk_0[0x24];
    unsigned short unk_24;
    char unk_26[0x54 - 0x26];
    unsigned char unk_54;
    unsigned char touching_;
    char unk_56[0x5f - 0x56];
    unsigned char unk_5f;
};

struct Words021e60c4;

extern "C" Vector3fix func_ov023_021e613c(void* character);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void _Z22InitWordsQuad_021e60e0Pvj(void* character, unsigned int angle);
void SelectCoordsByFlag0x24(unsigned char* touch, int* x, int* y);
int TestFlagMask(unsigned short* pad, int buttons);
extern "C" void _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(void* character, Words021e60c4* rotation);

extern TouchState data_02114e54;
extern char data_02114e30[];

struct CharacterCreation {
    char unk_0[0x7f8];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char unk_808[0xd9c - 0x808];
    unsigned int flags_;
};

// USA: func_ov009_02188604
extern "C" ARM void func_ov009_02188604(CharacterCreation* self, unsigned int ticks)
{
    if (self->flags_ & 8)
    {
        int done = 0;
        Vector3fix rotation = func_ov023_021e613c(self->character_);
        int angle;
        int y = rotation.y;
        int difference = fix32ReduceAngle0To2Pi(self->targetAngle_ - y);
        if (difference >= 0 && difference < 0x3244)
        {
            angle = y + difference / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle += fix32ReduceAngle0To2Pi(self->targetAngle_ - angle) / 12;
        }
        else if (difference >= 0x3244 && difference < 0x6488)
        {
            angle = y - (0x6488 - difference) / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle -= (0x6488 - fix32ReduceAngle0To2Pi(self->targetAngle_ - angle)) / 12;
        }
        _Z22InitWordsQuad_021e60e0Pvj(self->character_, fix32ReduceAngle0To2Pi(angle));
        int remaining = fix32ReduceAngle0To2Pi(self->targetAngle_ - angle);
        if ((remaining < 0 ? -remaining : remaining) < 40)
            done = 1;
        else if (((0x6488 - remaining) < 0 ? -(0x6488 - remaining) : (0x6488 - remaining)) < 40)
            done = 1;
        if (done)
        {
            _Z22InitWordsQuad_021e60e0Pvj(self->character_, fix32ReduceAngle0To2Pi(self->targetAngle_));
            self->targetAngle_ = 0;
            self->flags_ &= ~8;
        }
    }
    else if (self->flags_ & 1)
    {
        int left = 0;
        int right = 0;
        int touched = 0;
        int x;
        int y;
        SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
        if (data_02114e54.touching_ != 0 || (data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0) ||
            data_02114e54.unk_54 != 0)
        {
            touched = 1;
            if (y >= 0xa9 && y <= 0xb1)
            {
                if (x >= 0xe && x <= 0x17)
                    left = 1;
                if (x >= 0x3b && x <= 0x44)
                    right = 1;
            }
        }
        if (touched == 0)
        {
            if (TestFlagMask((unsigned short*)data_02114e30, 0x200))
                left = 1;
            if (TestFlagMask((unsigned short*)data_02114e30, 0x100))
                right = 1;
        }
        if (left != 0 && right != 0)
        {
            self->targetAngle_ = 0x1eb;
            self->flags_ |= 8;
        }
        else if (left != 0 || right != 0)
        {
            Vector3fix rotation = func_ov023_021e613c(self->character_);
            if (left != 0)
                rotation.y += (int)(4096.0f * (0.08f * ticks));
            if (right != 0)
                rotation.y -= (int)(4096.0f * (0.08f * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
            _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(self->character_, (Words021e60c4*)&rotation);
        }
    }
}
