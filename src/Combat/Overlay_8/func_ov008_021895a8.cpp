#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
#define REG_BG0CNT (*(volatile unsigned short*)0x04000008)
#define REG_BG1CNT (*(volatile unsigned short*)0x0400000a)
#define REG_BG2CNT (*(volatile unsigned short*)0x0400000c)
#define REG_BG3CNT (*(volatile unsigned short*)0x0400000e)
#define REG_BLDCNT 0x04000050

struct MessageSystem
{
    char unk_0[0x5c];
    void* unk_5c;
};

struct Struct0205a198;
struct ActiveEntry02046900;
struct Rec020467f0;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct ClearTarget0205a234;

struct BackgroundGraphics
{
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas
{
    void* unk_0;
    BackgroundGraphics* background_;
    char unk_8[0xe0 - 8];
};

struct TextWindow
{
    char unk_0[0x98];
    BackgroundGraphics* background_;
    int unk_9c;
    char unk_a0[0xb2 - 0xa0];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct Sprite
{
    char unk_0[0x22];
    unsigned char unk_22;
    char unk_23[0x28 - 0x23];
};

struct SpriteRenderer
{
    char unk_0[0x3c];
    void* animations_;
    Sprite* sprites_;
    char unk_44[4];
    unsigned int unk_48;
    short numSprites_;
    unsigned short capacity_;
    unsigned char unk_50;
    char unk_51[3];

    void SetSprites(Sprite* sprites, short numSprites)
    {
        sprites_ = sprites;
        numSprites_ = numSprites;
    }
};

struct PartyMemberData
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

struct GuestRecords
{
    char unk_0[0x16];
    unsigned char female_ : 1;
    unsigned char unk_16_1 : 4;
    unsigned char unk_16_5 : 3;
    unsigned char unk_17;
};

struct GuestData
{
    char unk_0[0x38];
    GuestRecords records_;
};

struct Bytes2
{
    unsigned char b[2];
};

extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
extern "C" void func_020dfec0(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0204bc74(BackgroundGraphics* background, int, int, int, int, int, int);
extern "C" void func_0205a528(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void ColorEffect_ConfigureAlphaBlend(void* reg, int a, int b, int c, int d);
extern "C" void func_ov008_0218b240(void* self);
extern "C" void func_ov008_0218aa24(void* self);

char* GetWord0x0(int* gameState);
void* GetGlobal02109400();
int IsField0Null(void** field);
void SetBitsInWord(unsigned int* word, unsigned int bits);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* field, unsigned int bits);
extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
PartyMemberData* GetFieldAt0x150(unsigned char* member);
void SetWord0x18ClearByte0x1f(unsigned char* background, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c* background, SafeAllocator* allocator);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* background, int, int);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* background, void*);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198* sprite);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(ClearTarget0205a234* list);
extern "C" void _Z18InitStruct0205a444Pc(char* renderer);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void _Z21BlankFunction02094b34v();
extern "C" int _Z18AlwaysTrue02094b4cv();

extern char data_ov008_0218b4c8[];
extern char data_ov008_0218b4df[];
extern char data_ov008_0218b4f2[];
extern char data_ov008_0218b508[];
extern char data_ov008_0218b51a[];
extern char data_ov008_0218b52d[];
extern char data_ov008_0218b544[];
extern char data_ov008_0218b559[];
extern char data_ov008_0218b56a[];
extern char data_ov008_0218b57f[];
extern const unsigned char data_ov008_0218b3b8[4];

struct VisitorTalk
{
    char unk_0[0x10];
    unsigned char unk_10;
    unsigned char unk_11;
    unsigned int layers_;
    TextWindow window_;
    BackgroundGraphics backgrounds_[2];
    Canvas canvas_;
    SpriteRenderer* renderer_;
    Sprite* sprites_;
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
    char entry_[0x2c];
    char profile_[0x7c];
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

// USA: func_ov008_021895a8
extern "C" ARM void func_ov008_021895a8(VisitorTalk* self)
{
    GameState* gameState = GameState::GetInstance();
    char* resources = GetWord0x0((int*)gameState);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400();
    signed char step = self->step_;
    if (step == 0)
    {
        if (!IsField0Null(*(void***)(resources + 0x3700)))
            return;
        SetBitsInWord((unsigned int*)func_ov017_0218b5b0(), 0x10);
        OrBitsIntoField0(_Z27GetDataPtr02114e04_020d6c00v(), 0xd);
        unsigned int female;
        self->text_ = (char*)_Z26GetGlobalField0x1c020421a0v()->unk_5c;
        female = 0;
        GuestData* guest = self->guest_;
        if (guest == NULL)
        {
            GameObject* member = gameState->GetPartyMemberByIndex(self->member_);
            if (member == NULL)
            {
                func_ov008_0218b240(self);
                return;
            }
            PartyMemberData* data = GetFieldAt0x150((unsigned char*)member);
            if (data != NULL)
                female = data->female_;
        }
        else
        {
            female = guest->records_.female_;
        }
        char gp2[0x40];
        char inner[0x20];
        sprintf(gp2, data_ov008_0218b4c8, female);
        sprintf(inner, data_ov008_0218b4df, female);
        self->textTask_ = loader->QueueLoadFileInGP2(data_ov008_0218b4f2, data_ov008_0218b508, NULL);
        self->titleTask_ = loader->QueueLoadFileInGP2(gp2, inner, NULL);
        self->backgroundTask_ = loader->QueueLoadFile(data_ov008_0218b51a, NULL);
        self->spriteTask_ = loader->QueueLoadFile(data_ov008_0218b52d, NULL);
        self->step_++;
    }
    else if (step == 1)
    {
        if (loader->GetTaskStatus(self->textTask_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->textTask_, &file, &size);
            self->textAllocator_.Reset();
            func_020728ac(&self->texts_, &self->textAllocator_, file, size, 0, 0, 0);
            loader->RemoveTask(self->textTask_);
            self->textTask_ = -1;
            self->step_++;
        }
    }
    else if (step == 2)
    {
        if (loader->GetTaskStatus(self->titleTask_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->titleTask_, &file, &size);
            self->titleAllocator_.Reset();
            func_020dfec0(&self->titles_, &self->titleAllocator_, file, size);
            self->titlesLoaded_ = 1;
            loader->RemoveTask(self->titleTask_);
            self->titleTask_ = -1;
            self->allocator_.Reset();
            unsigned char layers[2];
            unsigned char priorities[2];
            *(Bytes2*)layers = *(Bytes2*)&data_ov008_0218b3b8[2];
            *(Bytes2*)priorities = *(Bytes2*)&data_ov008_0218b3b8[0];
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++)
            {
                background = &self->backgrounds_[i];
                SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
                background->unk_1c_0_ = 0;
                background->unk_1c_4_ = layers[i];
                func_0204b5b4(background, priorities[i]);
                _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)background, &self->allocator_);
                _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)background, 0, 0);
            }
            REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x1d00;
            REG_BG2CNT = (REG_BG2CNT & 0x43) | 0x1e00;
            ColorEffect_ConfigureAlphaBlend((void*)REG_BLDCNT, 2, 1, 10, 6);
            self->step_++;
        }
    }
    else if (step == 3)
    {
        if (loader->GetTaskStatus(self->backgroundTask_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->backgroundTask_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&size);
                if (file != NULL)
                    func_0204b174(&self->backgrounds_[1], file, &self->allocator_, size);
            }
            loader->RemoveTask(self->backgroundTask_);
            self->backgroundTask_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++)
            {
                background = &self->backgrounds_[i];
                func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)background, 0);
            }
            self->pixels_ = self->allocator_.Allocate(0x800);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8*)&self->canvas_, &self->allocator_, (int)self->pixels_, 0x100);
            self->canvas_.background_ = &self->backgrounds_[1];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unk_b2 = 2;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78*)&self->window_, (Elem_0205cf78*)&self->canvas_, 1);
            for (unsigned char i = 0; i < 8; i++)
            {
                int offset = i * sizeof(Sprite);
                _Z12Init0205a198P14Struct0205a198((Struct0205a198*)((char*)self->sprites_ + offset));
                ((Sprite*)((char*)self->sprites_ + offset))->unk_22 = i + 4;
            }
            _Z23ClearField0And40205a234P19ClearTarget0205a234((ClearTarget0205a234*)self->animations_);
            _Z18InitStruct0205a444Pc((char*)self->renderer_);
            self->renderer_->unk_50 = 0;
            SpriteRenderer* renderer = self->renderer_;
            renderer->SetSprites(self->sprites_, 8);
            self->renderer_->animations_ = self->animations_;
            self->step_++;
        }
    }
    else if (step == 4)
    {
        if (loader->GetTaskStatus(self->spriteTask_))
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            loader->GetLoadedFileByID(self->spriteTask_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            self->spriteAllocator_.Reset();
            for (int i = 0; i < count; i++)
            {
                unsigned int size;
                func_0205a528(self->renderer_, FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&size), size, &self->spriteAllocator_);
            }
            loader->RemoveTask(self->spriteTask_);
            self->spriteTask_ = -1;
            REG_BG0CNT = (REG_BG0CNT & ~3) | 2;
            REG_BG1CNT = (REG_BG1CNT & ~3) | 1;
            REG_BG2CNT = REG_BG2CNT & ~3;
            REG_BG3CNT = (REG_BG3CNT & ~3) | 3;
            REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1700;
            ((void (*)(void*, int, int, int, int))_Z21BlankFunction02094b34v)(GetGlobal02109400(), 0x6b, 0x206, 0, 0);
            self->step_++;
        }
    }
    else if (step == 5)
    {
        GetGlobal02109400();
        if (_Z18AlwaysTrue02094b4cv())
        {
            func_ov008_0218aa24(self);
            self->profileTask_ = loader->QueueLoadFileInGP2(data_ov008_0218b544, data_ov008_0218b559, NULL);
            self->sentencesTask_ = loader->QueueLoadFileInGP2(data_ov008_0218b56a, data_ov008_0218b57f, NULL);
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
