#include <globaldefs.h>

struct PartyMemberAppearance {
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short unk_16;
    short width_;
    short height_;
};

struct PartyMemberData {
    char unk_0[0x488];
    PartyMemberAppearance appearance_;
};

extern "C" void func_ov023_021e6158(void* character, int part);
extern "C" void _Z20GetEntryPair02188bf8PhiPsS0_(unsigned char* self, int bodyType, short* width, short* height);
extern "C" void func_ov023_021e5e68(void* character, int width, int height);
extern "C" int func_ov009_02188b14(void* self, int state, int choice);
extern "C" void func_ov023_021e540c(void* character);

struct CharacterCreation {
    char unk_0[0x7f8];
    void* character_;
    void* nextCharacter_;
    char unk_800[0xc58 - 0x800];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd88 - 0xc5a];
    PartyMemberData* member_;
    char unk_d8c[0xd9c - 0xd8c];
    unsigned int flags_;
};

// USA: func_ov009_02188944
extern "C" ARM void func_ov009_02188944(CharacterCreation* self, int choice)
{
    PartyMemberAppearance* appearance = &self->member_->appearance_;
    int state = self->state_;
    void* next = self->nextCharacter_;
    void* current = self->character_;
    if (state == 1)
    {
        appearance->female_ = choice;
        func_ov023_021e6158(next, 0);
        func_ov023_021e6158(next, 2);
        func_ov023_021e6158(next, 3);
        func_ov023_021e6158(next, 4);
        self->flags_ |= 2;
    }
    else if (state == 2)
    {
        _Z20GetEntryPair02188bf8PhiPsS0_((unsigned char*)self, choice, &appearance->width_, &appearance->height_);
        func_ov023_021e5e68(current, appearance->width_, appearance->height_);
        func_ov023_021e5e68(next, appearance->width_, appearance->height_);
    }
    else if (state == 5)
    {
        appearance->models_[2] = func_ov009_02188b14(self, 5, choice) + 0x233c;
        func_ov023_021e6158(next, 2);
        self->flags_ |= 2;
    }
    else if (state == 3)
    {
        appearance->models_[3] = func_ov009_02188b14(self, 3, choice) + 0x2328;
        func_ov023_021e6158(next, 3);
        func_ov023_021e6158(next, 4);
        self->flags_ |= 2;
    }
    else if (state == 4)
    {
        appearance->hairColor_ = choice;
        func_ov023_021e6158(next, 4);
        self->flags_ |= 2;
    }
    else if (state == 6)
    {
        appearance->eyeColor_ = choice;
        func_ov023_021e540c(current);
    }
    else if (state == 7)
    {
        appearance->skinColor_ = choice;
        func_ov023_021e540c(current);
    }
}
