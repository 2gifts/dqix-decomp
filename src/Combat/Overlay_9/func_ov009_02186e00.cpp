#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct KeyboardKey {
    short x_;
    short y_;
    const char* text_;
    const char* shiftedText_;
    unsigned char flags_;
    unsigned char unk_d;
    unsigned char size_;
    unsigned char unk_f;
    char unk_10[4];
};

struct Keyboard {
    KeyboardKey* key_;
    void* layout_;
    char* text_;
    int unk_c;
    int size_;
    int unk_14;
    int unk_18;
    short unk_1c;
    unsigned char unk_1e;
    unsigned char unk_1f;
    unsigned char unk_20;
    unsigned char unk_21;
    unsigned char unk_22;
    unsigned char unk_23;
    unsigned char unk_24;
    char unk_25[3];

    void SetText(char* text, int size)
    {
        text_ = text;
        size_ = size;
    }
};

struct CharacterInfo {
    const char* text_;
    signed char unk_4;
};

struct WindowCursor {
    char unk_0[4];
    int unk_4;
    char unk_8[0x38];
};

struct TouchState {
    char unk_0[0x55];
    unsigned char touching_;
};

struct PartyMemberData {
    char unk_0[0x3c];
    char name_[1];
};

struct Obj0205eaa0;
struct Struct_0205bef8;
struct Struct_0205ba68;
struct Node0205bacc;

extern "C" void func_ov003_0215f41c(Keyboard* keyboard, const char* text);
extern "C" CharacterInfo* _Z22FindEntryByKey0204254cii(int character, int mode);
extern "C" int func_ov003_0215f000(Keyboard* keyboard, int ticks);
extern "C" int func_ov009_02188ee8(void* self);
extern "C" void func_ov009_02189a4c(void* self);
extern "C" void _Z20SetStatValue021855dcPhi(unsigned char* self, int state);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int a);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void _Z22BuildFieldTag_021d9e60Pc(char* self);
extern "C" KeyboardKey* func_ov003_0215f4a4(Keyboard* keyboard, int a);
extern "C" void _Z23ResetEntrySkill0218a8b8Pv(void* self);
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(Struct_0205bef8* cursor);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* cursor, int columns, int rows, int a);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* cursor, int count);
extern "C" void func_0205bb04(WindowCursor* cursor, int a);
extern "C" void _Z29StoreResultIfNonZero_0215f4e4Pi(int* keyboard);
extern "C" void func_ov003_0215ec68(int size, short* width, short* height);

extern char data_ov009_0218ad26[];
extern char data_ov009_0218ad2a[];
extern char data_02108760[];
extern char data_02114e30[];
extern TouchState data_02114e54;
extern const char data_020ef078[];

struct CharacterCreation {
    char unk_0[0xbc];
    KeyboardKey* savedKey_;
    Keyboard* keyboard_;
    char unk_c4[0xbec - 0xc4];
    WindowCursor cursor_;
    char unk_c2c[0xc4c - 0xc2c];
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastX_;
    short lastY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd88 - 0xc5a];
    PartyMemberData* member_;
    char unk_d8c[0xd9c - 0xd8c];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
    char unk_da4[0xdb0 - 0xda4];
    char** names_;
    unsigned char unk_db4;
    unsigned char keyboardResult_;
};

// USA: func_ov009_02186e00
extern "C" ARM void func_ov009_02186e00(CharacterCreation* self)
{
    if (self->step_ == 0)
    {
        self->keyboard_->SetText(self->names_[self->sex_], 0x48);
        self->keyboard_->unk_14 = 8;
        self->keyboard_->unk_1f = 0;
        self->keyboard_->unk_21 = 0;
        self->keyboard_->unk_24 = 1;
        func_ov003_0215f41c(self->keyboard_, data_ov009_0218ad26);
        self->savedKey_ = self->keyboard_->key_;
        if (self->savedKey_ != NULL)
            self->keyboard_->key_ = self->savedKey_;
        self->savedKey_ = NULL;
        CharacterInfo* info = _Z22FindEntryByKey0204254cii((int)data_ov009_0218ad2a, 0);
        if (info != NULL)
            self->keyboard_->unk_c = info->unk_4 * 8 + 7;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        self->keyboard_->unk_18 = 0;
        self->keyboard_->unk_1c = 0;
        self->flags_ |= 1;
        self->flags_ &= ~0x800;
        self->flags_ |= 0x8100;
        self->step_++;
    }
    else if (self->step_ == 2)
    {
        if (self->flags_ & 0x80)
            return;
        self->keyboardResult_ = func_ov003_0215f000(self->keyboard_, GameState::GetInstance()->GetTickCount());
        int result = func_ov009_02188ee8(self);
        if (self->keyboardResult_ != 0)
            result = -1;
        int checked = 0;
        if (result == -2)
        {
            checked = 1;
            func_ov009_02189a4c(self);
        }
        else if (result == -3)
        {
            _Z20SetStatValue021855dcPhi((unsigned char*)self, 7);
            return;
        }
        else if (result >= 101 && result <= 108)
        {
            result -= 100;
            if (result <= self->lastStates_[self->sex_] && result != self->state_)
            {
                _Z20SetStatValue021855dcPhi((unsigned char*)self, (unsigned char)result);
                return;
            }
        }

        self->flags_ |= 0x2000;
        switch (self->keyboardResult_)
        {
        case 1:
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 2, 0);
            break;
        case 9:
            if (!TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 1) && data_02114e54.touching_ == 0)
                _Z20SetStatValue021855dcPhi((unsigned char*)self, 7);
            else
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            self->flags_ |= 0x8100;
            break;
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 11:
            if (!TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 2))
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            self->flags_ |= 0x8100;
            break;
        case 3:
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            self->flags_ |= 0x8100;
            _Z22BuildFieldTag_021d9e60Pc((char*)self);
            if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 1))
            {
                KeyboardKey* key = func_ov003_0215f4a4(self->keyboard_, 6);
                if (key != NULL)
                    self->keyboard_->key_ = key;
            }
            break;
        case 10:
            if (*self->names_[self->sex_] == 0)
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            if (checked == 0)
            {
                checked = 1;
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
                func_ov009_02189a4c(self);
            }
            break;
        case 13:
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            break;
        case 12:
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            _Z23ResetEntrySkill0218a8b8Pv(self);
            self->flags_ |= 0x8100;
            return;
        default:
            self->flags_ &= ~0x2000;
            if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 4) && result != -2)
            {
                if (self->keyboard_->key_ != NULL)
                {
                    _Z23ResetEntrySkill0218a8b8Pv(self);
                    self->flags_ |= 0x8100;
                    return;
                }
            }
            else if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 0xc0))
            {
                self->flags_ |= 0x2000;
            }
            break;
        }

        if (self->keyboardResult_ != 0 && self->keyboardResult_ != 8)
        {
            WindowCursor* cursor = &self->cursor_;
            _Z12Init0205bef8P15Struct_0205bef8((Struct_0205bef8*)cursor);
            _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)cursor, 11, 6, 1);
            _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)cursor, 0x42);
            cursor->unk_4 = 1;
            func_0205bb04(cursor, 0);
        }
        if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 8) && !(self->flags_ & 0x8100) &&
            self->keyboard_->key_ != NULL && checked == 0)
            func_ov009_02189a4c(self);
        if (self->flags_ & 0x400000)
        {
            self->flags_ |= 0x2000 | 0x1000000;
            self->step_++;
        }
        if (self->flags_ & 0x800)
        {
            WindowCursor* cursor = &self->cursor_;
            _Z12Init0205bef8P15Struct_0205bef8((Struct_0205bef8*)cursor);
            _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)cursor, 11, 6, 1);
            _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)cursor, 0x42);
            cursor->unk_4 = 1;
            func_0205bb04(cursor, 0);
            ((void (*)(Keyboard*, int))_Z29StoreResultIfNonZero_0215f4e4Pi)(self->keyboard_, 6);
            self->flags_ |= 0x1000000;
            sprintf(self->member_->name_, data_020ef078, self->names_[self->sex_]);
            _Z20SetStatValue021855dcPhi((unsigned char*)self, 9);
        }
    }
    else if (self->step_ == 3)
    {
        if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 0x401) || data_02114e54.touching_ != 0)
        {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            self->flags_ = (self->flags_ & ~0x1400000) | 0x2000;
            self->step_ = 2;
        }
        else if (TestFlag0SetAndFlag1Clear((unsigned short*)data_02114e30, 2))
        {
            self->flags_ = (self->flags_ & ~0x1400000) | 0x2000;
            self->step_ = 2;
        }
    }

    KeyboardKey* key = self->keyboard_->key_;
    if (key != NULL)
    {
        short width;
        short height;
        func_ov003_0215ec68(key->size_, &width, &height);
        self->cursorX_ = key->x_;
        self->cursorY_ = key->y_;
        self->cursorWidth_ = width;
        self->cursorHeight_ = height;
    }
}
