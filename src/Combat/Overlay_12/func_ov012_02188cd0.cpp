#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct TableA68;
struct Entry_0205d6a0;
struct ResetLayout_0215e6d8;
struct Struct0215efb8;
struct Struct0205de24;
struct Struct_0205def8;
struct Obj0205eaa0;

struct Keyboard02188cd0
{
    void* key_;
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
};

struct Profile02188cd0
{
    char unk_0[8];
    char unk_8[0x74];
};

struct Messages02188cd0
{
    char unk_0[0x998];
    int busy_;
};

struct ProfileEditor02188cd0
{
    void* unk_0;
    void* unk_4;
    char unk_8[0x20 - 0x8];
    char allocators_[7][0x14];
    char window_[0xd28 - 0xac];
    char card_[0x600];
    char* cardMessage_;
    char unk_132c[0x133c - 0x132c];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x1380 - 0x1372];
    int tasks_[6];
    int unk_1398;
    int result_;
    unsigned char unk_13a0;
    char unk_13a1[3];
    int unk_13a4;
    char unk_13a8[4];
    void* unk_13ac;
    char unk_13b0[0x13d0 - 0x13b0];
    char* message_;
    char unk_13d4[0x1480 - 0x13d4];
    unsigned char checker_[0x14bc - 0x1480];
};

extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int a);
extern "C" void func_02042764(const void* codes, char* text, int a);
extern "C" void _Z20ResetStruct_0215e6d8P20ResetLayout_0215e6d8(ResetLayout_0215e6d8* layout);
extern "C" void func_ov003_0215e6f8(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void _Z18InitStruct0215efb8P14Struct0215efb8(Struct0215efb8* keyboard);
extern "C" int func_ov012_0218ae74(ProfileEditor02188cd0* self, Profile02188cd0* profile);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(ProfileEditor02188cd0* self);
extern "C" void _Z22SetupBattleTag0218aabcPc(char* self);
extern "C" void func_ov003_0215f41c(void* keyboard, const char* text);
extern "C" void func_ov012_0218ab34(ProfileEditor02188cd0* self, char* text, int hidden);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" int func_0205d97c(void* window);
extern "C" int func_ov003_0215f000(void* keyboard, int input);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int a);
extern "C" void func_ov023_021e8270(void* card);
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8* window, int a, int b);
extern "C" void func_020426bc(const char* text, char* codes, int a);
extern "C" void func_ov012_0218943c(ProfileEditor02188cd0* self);
extern "C" Messages02188cd0* _Z26GetGlobalField0x1c020421a0v();
const char* FindEntryByKey(TableA68* texts, int id);
extern "C" void func_0204500c(Messages02188cd0* messages, const char* text, int a, int b);

extern "C" const char data_ov012_0218b2ea[];
extern "C" const char data_ov012_0218b303[];
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline Profile02188cd0* GetProfile02188cd0(GameState* gameState)
{
    return (Profile02188cd0*)((char*)gameState + 0x569c);
}

// USA: func_ov012_02188cd0
extern "C" ARM void func_ov012_02188cd0(ProfileEditor02188cd0* self)
{
    if (self->step_ == 0)
    {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
        Profile02188cd0* profile = GetProfile02188cd0(GameState::GetInstance());
        memset(self->message_, 0, 0x400);
        self->cardMessage_ = self->message_;
        func_02042764(profile->unk_8, self->message_, 1);
        self->tasks_[0] = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov012_0218b2ea, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 1)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->tasks_[0]))
        {
            if (loader->GetDetailedTaskStatus(self->tasks_[0]) != 2)
            {
                loader->RemoveTask(self->tasks_[0]);
                self->tasks_[0] = -1;
            }
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->tasks_[0], &file, &size);
            if (file != 0 && size != 0)
            {
                ((SafeAllocator*)self->allocators_[4])->Reset();
                _Z20ResetStruct_0215e6d8P20ResetLayout_0215e6d8((ResetLayout_0215e6d8*)self->unk_4);
                func_ov003_0215e6f8(self->unk_4, (SafeAllocator*)self->allocators_[4], file, size);
                _Z18InitStruct0215efb8P14Struct0215efb8((Struct0215efb8*)self->unk_0);
                ((Keyboard02188cd0*)self->unk_0)->layout_ = self->unk_4;
                ((Keyboard02188cd0*)self->unk_0)->key_ = 0;
            }
            loader->RemoveTask(self->tasks_[0]);
            self->tasks_[0] = -1;
            self->step_++;
            return;
        }
        return;
    }
    else if (self->step_ == 2)
    {
        func_ov012_0218ae74(self, GetProfile02188cd0(GameState::GetInstance()));
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        self->unk_13a0 = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        _Z22SetupBattleTag0218aabcPc((char*)self);
        memcpy(self->unk_13ac, GetProfile02188cd0(GameState::GetInstance())->unk_8, 0x72);
        Keyboard02188cd0* keyboard = (Keyboard02188cd0*)self->unk_0;
        keyboard->text_ = self->message_;
        keyboard->size_ = 0x400;
        ((Keyboard02188cd0*)self->unk_0)->unk_14 = 0x39;
        ((Keyboard02188cd0*)self->unk_0)->unk_1f = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_21 = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_24 = 1;
        func_ov003_0215f41c(self->unk_0, data_ov012_0218b303);
        ((Keyboard02188cd0*)self->unk_0)->unk_22 = 1;
        ((Keyboard02188cd0*)self->unk_0)->unk_23 = 0;
        func_ov012_0218ab34(self, 0, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 4)
    {
        if ((TestFlag0SetAndFlag1Clear(data_02114e30, 2) || func_0205d97c(self->window_) == 2) && *self->message_ == 0)
        {
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
            self->step_++;
        }
        Keyboard02188cd0* keyboard = (Keyboard02188cd0*)self->unk_0;
        unsigned char page = keyboard->unk_20;
        switch (func_ov003_0215f000(keyboard, self->unk_13a4))
        {
            case 1:
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 2, 0);
                return;

            case 2:
            case 3:
            case 8:
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
                if (page != ((Keyboard02188cd0*)self->unk_0)->unk_20)
                    func_ov012_0218ab34(self, 0, 0);
                func_ov023_021e8270(self->card_);
                return;

            case 4:
            case 5:
            case 6:
            case 7:
            case 11:
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
                func_ov012_0218ab34(self, 0, 0);
                return;

            case 9:
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
                return;

            case 10:
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
                if (*self->message_ != 0)
                {
                    GameState::GetInstance();
                    BackgroundLoader::AddLockGlobal();
                    BackgroundLoader::FreeAllocationsGlobal();
                    func_ov012_021845f8(self->checker_);
                    int forbidden = func_ov012_02184d80(self->checker_, self->message_);
                    BackgroundLoader::RemoveLockGlobal();
                    if (forbidden)
                    {
                        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)self->window_, 0, 14);
                        self->step_ = 10;
                        return;
                    }
                }
                _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
                self->step_++;
                return;
        }
    }
    else if (self->step_ == 5)
    {
        func_020426bc(self->message_, GetProfile02188cd0(GameState::GetInstance())->unk_8, 1);
        self->cardMessage_ = 0;
        memset(self->message_, 0, 0x400);
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 7)
    {
        self->state_ = 1;
        func_ov023_021e6e60(self);
        func_ov012_0218943c(self);
        self->unk_13a0 = 1;
        self->step_ = 1;
        return;
    }
    else if (self->step_ == 10)
    {
        Messages02188cd0* messages = _Z26GetGlobalField0x1c020421a0v();
        func_0204500c(messages, FindEntryByKey((TableA68*)self->strings_, 501), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 11)
    {
        if (_Z26GetGlobalField0x1c020421a0v()->busy_ == 0)
        {
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)self->window_, 1, 14);
            self->step_ = 4;
            ((Keyboard02188cd0*)self->unk_0)->unk_18 = 0;
            ((Keyboard02188cd0*)self->unk_0)->unk_1c = 0;
        }
    }
}
