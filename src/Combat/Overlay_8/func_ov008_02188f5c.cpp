#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct InitTarget0205cfd4;
struct List0204af64;
struct List020727d8;
struct Struct020dfc40;

struct PartyMemberData
{
    char unk_0[0x3c];
    char name_[0xc];
};

struct ProfileData
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int unk_0_21 : 4;
    unsigned int female_ : 1;
    unsigned int initialized_ : 1;
    unsigned int designChosen_ : 1;
    unsigned int birthdayChosen_ : 1;
    unsigned int accoladeChosen_ : 1;
    unsigned int vocationAccolade_ : 1;
    unsigned int showBirthday_ : 1;
    unsigned int unk_4_0 : 9;
    int title_ : 10;
    int accolade_ : 11;
    int edited_ : 1;
    unsigned int unk_4_31 : 1;
    char unk_8[0x74];
};

struct GuestEntry
{
    unsigned char id_[6];
    char name_[0xb];
    unsigned char unk_11;
    unsigned short unk_12_0 : 14;
    unsigned short used_ : 1;
    unsigned short unk_12_15 : 1;
    char records_[0x18];
};

struct GuestData
{
    char unk_0[0x6c];
    ProfileData profile_;
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* func_0202ae18();
extern "C" void func_02074af4(void* state);
extern "C" void func_0204c684(void* canvas);
extern "C" void func_020426bc(const char* name, char* codes, int);
extern "C" void func_ov008_021843f8(void* records);
extern "C" void func_ov017_021d1014(signed char member, int, int);
extern "C" void func_ov017_021d1118(signed char member, int, int, int);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(InitTarget0205cfd4* window);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* background);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* texts);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* texts);
extern "C" void _Z22ResetSubStruct02189228Pv(void* entry);
PartyMemberData* GetFieldAt0x150(unsigned char* member);
int CheckField0NonZero(int*);

struct VisitorTalk
{
    char unk_0[0x10];
    unsigned char unk_10;
    unsigned char unk_11;
    unsigned int layers_;
    char window_[0xbc];
    char backgrounds_[2][0x20];
    char canvas_[0xe0];
    void* renderer_;
    void* sprites_;
    void* animations_;
    SafeAllocator allocator_;
    SafeAllocator textAllocator_;
    SafeAllocator recordsAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator profileAllocator_;
    SafeAllocator titleAllocator_;
    char texts_[8];
    char profileTexts_[8];
    char titles_[0x18];
    char* text_;
    void* pixels_;
    char records_[0xb48];
    GuestEntry entry_;
    ProfileData profile_;
    unsigned char unk_e98;
    signed char state_;
    signed char step_;
    signed char recordsState_;
    signed char recordsStep_;
    int textTask_;
    int backgroundTask_;
    int spriteTask_;
    int profileTask_;
    int sentencesTask_;
    int titleTask_;
    unsigned char done_;
    signed char member_;
    unsigned char saved_;
    unsigned char full_;
    GuestData* guest_;
    unsigned char active_ : 1;
    unsigned char profileLoaded_ : 1;
    unsigned char titlesLoaded_ : 1;
    unsigned char aborted_ : 1;
    unsigned char unk_ec0_4 : 4;
    void* sentences_;
    unsigned int sentencesSize_;
};

// USA: func_ov008_02188f5c
extern "C" ARM void func_ov008_02188f5c(VisitorTalk* self, signed char member, GuestData* guest)
{
    GameState* gameState = GameState::GetInstance();
    func_0202ae18();
    self->unk_10 = 0;
    self->unk_11 = 0;
    func_02074af4(self);
    self->layers_ = (REG_DISPCNT & 0x1f00) >> 8;
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x100;
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4((InitTarget0205cfd4*)&self->window_);
    _Z17ResetList0204af64P12List0204af64((List0204af64*)&self->backgrounds_[0]);
    _Z17ResetList0204af64P12List0204af64((List0204af64*)&self->backgrounds_[1]);
    func_0204c684(&self->canvas_);
    _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&self->texts_);
    _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&self->profileTexts_);
    _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)&self->titles_);
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->allocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->recordsAllocator_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->profileAllocator_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->text_ = NULL;
    self->pixels_ = NULL;
    func_ov008_021843f8(&self->records_);
    _Z22ResetSubStruct02189228Pv(&self->entry_);
    self->profile_.year_ = 2000;
    self->profile_.month_ = 1;
    self->profile_.day_ = 1;
    self->profile_.birthdayChosen_ = 0;
    self->profile_.unk_0_21 = 0;
    self->profile_.designChosen_ = 0;
    self->profile_.female_ = 0;
    self->profile_.initialized_ = 0;
    self->profile_.accoladeChosen_ = 0;
    self->profile_.vocationAccolade_ = 1;
    self->profile_.showBirthday_ = 0;
    self->profile_.unk_4_0 = 0x1ff;
    self->profile_.edited_ = 0;
    self->profile_.title_ = 300;
    self->profile_.accolade_ = 706;
    self->profile_.unk_8[0] = 0;
    self->unk_e98 = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->recordsState_ = 0;
    self->recordsStep_ = 0;
    self->textTask_ = -1;
    self->backgroundTask_ = -1;
    self->spriteTask_ = -1;
    self->profileTask_ = -1;
    self->sentencesTask_ = -1;
    self->titleTask_ = -1;
    self->sentences_ = NULL;
    self->sentencesSize_ = 0;
    self->done_ = 0;
    self->saved_ = 0;
    self->full_ = 0;
    self->guest_ = guest;
    self->active_ = 1;
    self->profileLoaded_ = 0;
    self->titlesLoaded_ = 0;
    self->aborted_ = 0;
    self->member_ = member;
    if (self->guest_ == NULL)
    {
        GameObject* object = gameState->GetPartyMemberByIndex(member);
        if (object != NULL)
        {
            PartyMemberData* data = GetFieldAt0x150((unsigned char*)object);
            if (data != NULL)
            {
                _Z22ResetSubStruct02189228Pv(&self->entry_);
                char name[0xc];
                __clear(name, sizeof(name));
                func_020426bc(data->name_, name, 1);
                memcpy(self->entry_.name_, name, sizeof(self->entry_.name_));
                self->entry_.used_ = 1;
                if (CheckField0NonZero((int*)func_0202ae18()))
                {
                    func_ov017_021d1014(member, 0, 0);
                    func_ov017_021d1118(member, 1, 1, 0);
                }
            }
        }
    }
    else
    {
        self->unk_e98 = 0xff;
        memcpy(&self->profile_, &self->guest_->profile_, sizeof(ProfileData));
    }
}
