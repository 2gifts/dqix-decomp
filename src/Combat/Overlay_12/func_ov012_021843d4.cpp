#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include "std_library_functions.h"

struct List020727d8;
struct Struct020dfc40;
struct InitTarget0205cfd4;
struct List0204af64;

extern "C" void func_02074af4(void* p);
extern "C" void func_ov023_021e7220(void* card, int mode);
void ResetListHeader020727d8(List020727d8* list);
void ResetStruct020dfc40(Struct020dfc40* texts);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
void ResetList0204af64(List0204af64* background);
extern "C" void func_0204c684(void* canvas);
#if defined(jpn)
#define func_ov012_021845f8 func_ov012_02185690
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(void* cursor);
void ClearFields_021e20c0(void* profile);
#endif
extern "C" void func_ov012_021845f8(void* checker);

struct PEBackground { char raw[0x20]; };
struct PECanvas { char raw[0xe0]; };

struct ProfileEditor021843d4
{
#if !defined(jpn)
    void* unk_0;
    void* unk_4;
#endif
    char unk_8[0x10];
    unsigned char unk_18;
    unsigned char unk_19;
    char unk_1a[2];
    int planes_;
#if defined(jpn)
    SafeAllocator allocators_[6];
#else
    SafeAllocator allocators_[7];
#endif
    char window_[0xbc];
    PEBackground backgrounds_[3];
    PECanvas canvases_[13];
#if defined(jpn)
    char card_[0x608];
#else
    char card_[0x614];
#endif
    char strings_[8];
    char texts_[0x18];
    void* renderer_;
    void* unk_1360;
    void* sprites_;
#if !defined(jpn)
    void* renderer2_;
    void* sprites2_;
#endif
    unsigned char step_;
    unsigned char state_;
    char unk_1372[2];
    char* text_;
    const char* unk_1378;
    void* pixels_;
#if defined(jpn)
    int tasks_[4];
#else
    int tasks_[6];
#endif
    int unk_1398;
    int result_;
    unsigned char unk_13a0;
    char unk_13a1[3];
    int unk_13a4;
    signed char unk_13a8;
    signed char unk_13a9;
    unsigned char unk_13aa;
    unsigned char unk_13ab;
#if defined(jpn)
    unsigned char nameFlag_;
    unsigned char nameStep_;
    char align_1376[2];
    char nameCursor_[0x40];
    int profileIndex_;
    char profile_[0x48];
#endif
    void* unk_13ac;
    char* name_;
    void* unk_13b4;
    unsigned int unk_13b8;
    char* unk_13bc;
    signed char* unk_13c0;
    unsigned short unk_13c4_0 : 5;
    unsigned short unk_13c4_5 : 11;
    char unk_13c6[2];
    unsigned short* unk_13c8;
    unsigned int* unk_13cc;
    char* message_;
    unsigned int selection_;
    int selections_[6];
    int unk_13f0;
    unsigned int design_;
    unsigned int unk_13f8;
    unsigned short year_;
    unsigned char month_;
    unsigned char day_;
    char accoladeText_[0x40];
    char titleText_[0x40];
#if defined(jpn)
    unsigned char checker_[0x20];
#else
    unsigned char checker_[0x3c];
#endif
    unsigned char finished_;
    unsigned char unk_14bd;
    char unk_14be[2];
};

// USA: func_ov012_021843d4
extern "C" ARM void func_ov012_021843d4(ProfileEditor021843d4* self)
{
#if !defined(jpn)
    self->unk_0 = 0;
    self->unk_4 = 0;
#endif
    self->unk_18 = 0;
    self->unk_19 = 0;
    func_02074af4(self->unk_8);
    self->planes_ = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    self->finished_ = 0;
    self->allocators_[0].ResetAllocatorPointer();
    self->allocators_[1].ResetAllocatorPointer();
    self->allocators_[2].ResetAllocatorPointer();
    self->allocators_[3].ResetAllocatorPointer();
#if defined(jpn)
    self->allocators_[4].ResetAllocatorPointer();
    self->allocators_[5].ResetAllocatorPointer();
#else
    self->allocators_[5].ResetAllocatorPointer();
    self->allocators_[6].ResetAllocatorPointer();
#endif
    func_ov023_021e7220(self->card_, 2);
    ResetListHeader020727d8((List020727d8*)self->strings_);
    ResetStruct020dfc40((Struct020dfc40*)self->texts_);
    self->renderer_ = 0;
    self->sprites_ = 0;
    self->unk_1360 = 0;
#if !defined(jpn)
    self->renderer2_ = 0;
    self->sprites2_ = 0;
#endif
    InitStruct0205cfd4((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 3; i++)
        ResetList0204af64((List0204af64*)&self->backgrounds_[i]);
    for (int i = 0; i < 13; i++)
        func_0204c684(&self->canvases_[i]);
    self->step_ = 0;
    self->state_ = 0;
    self->text_ = 0;
    self->pixels_ = 0;
    self->unk_1378 = 0;
    self->result_ = 0;
    self->unk_13a0 = 0;
    self->unk_1398 = 0;
    for (int i = 0; i < (int)(sizeof(self->tasks_) / sizeof(self->tasks_[0])); i++)
        self->tasks_[i] = -1;
    self->unk_13a8 = -1;
    self->unk_13a9 = 0;
    self->unk_13aa = 0;
    self->unk_13ab = 0;
#if defined(jpn)
    self->nameFlag_ = 0;
    self->nameStep_ = 0;
    _Z12Init0205bef8P15Struct_0205bef8(self->nameCursor_);
    self->profileIndex_ = 0;
    ClearFields_021e20c0(self->profile_);
#endif
    self->unk_13ac = 0;
    self->name_ = 0;
    self->unk_13b4 = 0;
    self->unk_13b8 = 0;
    self->unk_13bc = 0;
    self->unk_13c0 = 0;
    self->unk_13c4_0 = 0;
    self->unk_13c4_5 = 0;
    self->unk_13c8 = 0;
    self->unk_13cc = 0;
    self->message_ = 0;
    self->selection_ = 0;
    self->design_ = 0;
    self->unk_13f8 = 0;
    self->year_ = 0;
    self->month_ = 0;
    self->day_ = 0;
    self->selections_[0] = -1;
    self->selections_[1] = -1;
    self->selections_[2] = -1;
    self->selections_[3] = -1;
    self->selections_[4] = -1;
    self->selections_[5] = -1;
    memset(self->accoladeText_, 0, sizeof(self->accoladeText_));
    memset(self->titleText_, 0, sizeof(self->titleText_));
    func_ov012_021845f8(self->checker_);
#if !defined(jpn)
    self->unk_14bd = 0;
#endif
}
