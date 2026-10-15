#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Filesystem/BackgroundLoader.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct TextTable {
    char pad_0[0x18];
};

struct BackgroundGraphics {
    char pad_0[0x20];
};

struct TextWindow {
    char pad_0[0xbc];
};

struct Canvas {
    char pad_0[0xe0];
};

struct WindowCursor {
    int pad_0[0x10];
};

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    TextTable texts_;
    char* text_;
    char titleTable_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char itemCount_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    void* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    PlayTime times_[2];
};

struct MessageSystem {
    char pad_0[R(0x228, 0x2d8)];
    void* unk_2d8;
    void* unk_2dc;
    void* unk_2e0;
};

struct CombatSlots02045cac;
struct Obj0204b010;
struct List0204afb4;
struct FlagWord020466f4;

void EmptyDestructor0205a494(void* renderer);
MessageSystem* GetGlobalField0x1c020421a0();
void InitCombatSlots02045cac(CombatSlots02045cac* messages);
void ReinitController02043204(char* messages);
void ClearBuffer0204b010(Obj0204b010* background, void* value);
void ResetRecordList0204afb4(List0204afb4* background);
void SetFlagBytes02017d68(void* unused);
void* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);

extern "C" {
void func_ov023_021eb26c(void* guide);
void func_02043124(MessageSystem* messages);
void func_0204b04c(BackgroundGraphics* background, int value);
void func_0204b088(BackgroundGraphics* background, int value);
unsigned int GetMainBGAssignedVRAMSize();
void func_020ca458(int value, void* destination, unsigned int size);
void func_0205d048(TextWindow* window);
void* func_02012fe4();
}

// USA: func_ov008_021845ac
extern "C" ARM void func_ov008_021845ac(BattleRecords* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0)
    {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->renderer_ != NULL)
        EmptyDestructor0205a494(self->renderer_);
    if (self->iconRenderer_ != NULL)
        EmptyDestructor0205a494(self->iconRenderer_);
    if (self->guide_ != NULL)
        func_ov023_021eb26c(self->guide_);
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    InitCombatSlots02045cac((CombatSlots02045cac*)messages);
    ReinitController02043204((char*)messages);
    func_02043124(messages);
    messages->unk_2d8 = NULL;
    messages->unk_2dc = NULL;
    messages->unk_2e0 = NULL;
    BackgroundGraphics* backgrounds[3] = {&self->backgrounds_[0], &self->backgrounds_[1], &self->backgrounds_[2]};
    for (int i = 0; i < 3; i++)
    {
        BackgroundGraphics* background = backgrounds[i];
        ClearBuffer0204b010((Obj0204b010*)background, 0);
        func_0204b04c(background, 0);
        func_0204b088(background, 0);
        ResetRecordList0204afb4((List0204afb4*)background);
    }
    func_020ca458(0, (void*)0x06000000, GetMainBGAssignedVRAMSize());
    func_0205d048(&self->window_);
    self->model_.Destroy();
    self->text_ = NULL;
    self->pixels_ = NULL;
    SafeAllocator* allocators[8] = {&self->allocator_,      &self->backgroundAllocator_, &self->textAllocator_,
                                    &self->spriteAllocator_, &self->iconAllocator_,       &self->modelAllocator_,
                                    &self->titleAllocator_,  &self->guideAllocator_};
    for (int i = 0; i < 7; i++)
        allocators[i]->Destroy();
    if (self->exit_ == 0)
    {
        if (self->mode_ == 0)
        {
            SetFlagBytes02017d68(func_02012fe4());
        }
        ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);
    }
}
