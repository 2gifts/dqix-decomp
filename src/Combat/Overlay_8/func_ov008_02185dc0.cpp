#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct PlayRecords {
    int pad_0[0xb0 / 4];
};

struct TextTable {
    int pad_0[0x18 / 4];
};

struct TextList {
    int pad_0[2];
};

struct BackgroundGraphics {
    int pad_0[0x20 / 4];
};

struct TextWindow {
    int pad_0[0xbc / 4];
};

struct Canvas {
    int pad_0[0xe0 / 4];
};

struct WindowCursor {
    int pad_0[0x40 / 4];
};

struct Object3D {
    int pad_0[0xac / 4];
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

    int IsFlagSet(int flag)
    {
        return *(volatile int*)&flags_ & flag ? 1 : 0;
    }
};

struct MessageSystem {
    char pad_0[0x998];
    int busy_;
    int unk_99c;
    int unk_9a0;
    char pad_9a4[0x19ae - 0x9a4];
    unsigned char unk_19ae;
    char pad_19af[0x19b2 - 0x19af];
    unsigned char unk_19b2;
    char pad_19b3[0x19c5 - 0x19b3];
    unsigned char unk_19c5;
    char pad_19c6[0x19c8 - 0x19c6];
    unsigned char unk_19c8;
};

struct CombatantData {
    char pad_0[0x49c];
    unsigned char female_ : 1;
};

struct PartyMember {
    char pad_0[0x150];
    CombatantData* data_;
};

struct GameState {
    static GameState* GetInstance();
};

struct BackgroundLoader {
    static void AddLockGlobal();
    static void RemoveLockGlobal();
};

struct GameResources;
struct S_a05d8;
struct List020727d8;
struct StreamHeader;
struct Container020e0310;
struct Struct_0205bb84;
struct Obj0205eaa0;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char data_0211e33c[];
extern unsigned short data_02114e30[];
extern Obj0205eaa0 data_02108760;

GameResources* GetWord0x0(int* gameState);
extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
void SetBrightness(GameResources* resources, int screen, int brightness);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(void* records);
void AddClamped16BitHighAt0x20(S_a05d8* records, unsigned int value);
void CopyInBattleField0x7540(void* records);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* list);
extern "C" void _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(void* list, StreamHeader* file, int size, int id, void* output, int female);
int GetField0x3acValue(GameState* gameState);
PartyMember* GetCombatantWithFlag0x100(GameState* gameState, int index);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* cursor);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int value);

extern "C" {
void* memset(void* buffer, int value, unsigned long size);
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_0204500c(MessageSystem* messages, const char* text, int value, int value2);
void func_ov008_02186964(BattleRecords* self);
int func_ov008_02186a30(BattleRecords* self, int ticks);
void* func_0202ae18();
int func_0202c540(void* value);
}

// USA: func_ov008_02185dc0
extern "C" ARM void func_ov008_02185dc0(BattleRecords* self, unsigned int ticks)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetWord0x0((int*)gameState);
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    if (messages->busy_ != 0)
        messages->unk_19ae = 0;
    signed char step = self->step_;
    if (step == 0)
    {
        func_ov008_02186964(self);
        self->step_++;
    }
    if (step == 1)
    {
        if (self->IsFlagSet(0x20000) && self->IsFlagSet(0x200))
        {
            if (messages->unk_9a0 != 3)
                return;
            self->flags_ &= ~0x20000;
        }
        if (self->IsFlagSet(0x20000))
            step++;
        else
            SetBrightness(resources, 0, 0xf);
        self->step_++;
    }
    if (step == 2)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (!self->IsFlagSet(0x80))
        {
            int shown = 1;
            messages->busy_ = 1;
            if (self->title_ > 0)
            {
                if (!(self->flags_ & 0x200))
                    shown = 0;
                if (!shown)
                {
                    if (self->IsFlagSet(1) && !self->IsFlagSet(0x8000))
                    {
                        PlayRecords records;
                        _Z23LoadBattleBlock020ac4c0Pv(&records);
                        AddClamped16BitHighAt0x20((S_a05d8*)&records, 1);
                        CopyInBattleField0x7540(&records);
                    }
                    memset(self->text_, 0, 0x960);
                    char* path = self->text_;
                    char* inner = path + 0x80;
                    char* comment = path + 0x100;
                    BackgroundLoader::AddLockGlobal();
                    TextList list;
                    unsigned int size;
                    void* file = LoadFileIntoMemory(data_ov008_0218b400, data_0211e33c, &size);
                    if (file != NULL)
                    {
                        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&list);
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->comment_, path, 0);
                        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&list);
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->comment_, inner, 1);
                    }
                    file = ExtractFileFromGP2(path, inner, &size);
                    if (file != NULL)
                    {
                        PartyMember* member = GetCombatantWithFlag0x100(gameState, GetField0x3acValue(gameState));
                        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&list);
                        int female = member->data_->female_;
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->title_, comment, female);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    _Z20AppendString02042058PcPKc(comment, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, 1000));
                    func_0204500c(messages, comment, 0, 0xe3);
                    messages->unk_19b2 = 1;
                    messages->unk_19c8 = 1;
                    messages->unk_99c = 2;
                    if (self->page_ != NULL)
                    {
                        self->flags_ |= 0x200;
                        self->state_ = 2;
                        self->step_ = 0;
                        return;
                    }
                }
            }
            else
            {
                if (!(self->flags_ & 0x200))
                    shown = 0;
                if (!shown)
                {
                    func_0204500c(messages, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, 10000), 0, 0xe3);
                    messages->unk_19b2 = 1;
                    messages->unk_19c8 = 1;
                    messages->unk_99c = 2;
                }
            }
            if (self->IsFlagSet(0x20000))
            {
                messages->unk_19c5 = 1;
                messages->unk_19b2 = 0;
                self->flags_ |= 0x200;
                self->step_ = 1;
                return;
            }
            self->flags_ |= 0x20;
        }
        self->flags_ |= 8;
        self->step_++;
    }
    if (step == 3)
    {
        int result = func_ov008_02186a30(self, ticks);
        int selected = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)&self->cursor_);
        if (selected > self->top_ + 5)
            self->top_ = selected - 5;
        else if (selected < self->top_)
            self->top_ = selected;
        unsigned char kind = self->items_[selected];
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x401) || result == 1)
        {
            if (!func_0202c540(func_0202ae18()) || kind != 5)
            {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
                self->state_ = kind + 5;
                self->step_ = 0;
                self->flags_ &= ~8;
                self->flags_ &= ~0x20;
                return;
            }
        }
        else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x806) || result == -2)
        {
            self->state_ = 13;
            self->step_ = 0;
            self->flags_ &= ~8;
            self->flags_ &= ~0x20;
        }
    }
}
