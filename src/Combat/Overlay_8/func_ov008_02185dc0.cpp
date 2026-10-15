#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->flags_ & (flag))
#define REGION_MESSAGE(obj,shown) (!((obj)->flags_ & 0x200))
#define data_ov008_0218b400 data_ov008_0218c080
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->IsFlagSet(flag))
#define REGION_MESSAGE(obj,shown) (!(shown))
#endif

#include <Memory/SafeAllocator.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/MessageSystem.h"

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
#if defined(jpn)
        return flags_ & flag ? 1 : 0;
#else
        return *(int*)&flags_ & flag ? 1 : 0;
#endif
    }
};

struct CombatantData {
    char pad_0[0x49c];
    unsigned char female_ : 1;
};

struct PartyMember : GameObject {
    char pad_13c[REGION_LAYOUT(0x144, 0x150) - 0x13c];
    CombatantData* data_;
};

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

GameResources* GetWord0x0_0200fb8c(int* gameState);
MessageSystem* GetGlobalField0x1c020421a0();
void SetBrightness(GameResources* resources, int screen, int brightness);
int IsBrightnessTransitionActive(GameResources* resources);
void LoadBattleBlock020ac4c0(void* records);
void AddClamped16BitHighAt0x20_020a05d8(S_a05d8* records, unsigned int value);
void CopyInBattleField0x7540_020ac494(void* records);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
void ResetListHeader020727d8(List020727d8* list);
extern "C" void _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(void* list, StreamHeader* file, int size, int id, void* output, int female);
int GetField0x3acValue_020100a8(GameState* gameState);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);
int ComputeScaledSum0205bb84(Struct_0205bb84* cursor);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* pad, int buttons);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int value);

extern "C" {
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_ov008_02186964(BattleRecords* self);
int func_ov008_02186a30(BattleRecords* self, int ticks);
void* func_0202ae18();
int func_0202c540(void* value);
}

#if defined(jpn)
extern "C" void _Z28SubmitScriptFromFile020727f8PvPKciS_h(void*, const char*, int, void*, int);
#endif

// USA: func_ov008_02185dc0
extern "C" ARM void func_ov008_02185dc0(BattleRecords* self, unsigned int ticks)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetWord0x0_0200fb8c((int*)gameState);
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    if (messages->active != NULL)
        messages->b19ae = 0;
    signed char step = self->step_;
    if (step == 0)
    {
        func_ov008_02186964(self);
        self->step_++;
    }
    if (step == 1)
    {
        if (REGION_FLAG(self, 0x20000) && REGION_FLAG(self, 0x200))
        {
            if (messages->mode != 3)
                return;
            self->flags_ &= ~0x20000;
        }
        if (REGION_FLAG(self, 0x20000))
            step++;
        else
            SetBrightness(resources, 0, 0xf);
        self->step_++;
    }
    if (step == 2)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (!REGION_FLAG(self, 0x80))
        {
#if !defined(jpn)
            int shown = 1;
#endif
            messages->active = (void*)1;
            if (self->title_ > 0)
            {
#if !defined(jpn)
                if (!(self->flags_ & 0x200))
                    shown = 0;
#endif
                if (REGION_MESSAGE(self, shown))
                {
                    if (REGION_FLAG(self, 1) && !REGION_FLAG(self, 0x8000))
                    {
                        PlayRecords records;
                        LoadBattleBlock020ac4c0(&records);
                        AddClamped16BitHighAt0x20_020a05d8((S_a05d8*)&records, 1);
                        CopyInBattleField0x7540_020ac494(&records);
                    }
                    memset(self->text_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
                    char* path = self->text_;
                    char* comment = path + 0x80;
                    TextList list;
                    ResetListHeader020727d8((List020727d8*)&list);
                    _Z28SubmitScriptFromFile020727f8PvPKciS_h(&list, data_ov008_0218b400, self->comment_, path, 0);
                    PartyMember* member = (PartyMember*)GetCombatantWithFlag0x100_0200ff1c(gameState, GetField0x3acValue_020100a8(gameState));
                    ResetListHeader020727d8((List020727d8*)&list);
                    int female = member->data_->female_;
                    _Z28SubmitScriptFromFile020727f8PvPKciS_h(&list, path, self->title_, comment, female);
#else
                    char* path = self->text_;
                    char* inner = path + 0x80;
                    char* comment = path + 0x100;
                    BackgroundLoader::AddLockGlobal();
                    TextList list;
                    unsigned int size;
                    void* file = LoadFileIntoMemory(data_ov008_0218b400, data_0211e33c, &size);
                    if (file != NULL)
                    {
                        ResetListHeader020727d8((List020727d8*)&list);
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->comment_, path, 0);
                        ResetListHeader020727d8((List020727d8*)&list);
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->comment_, inner, 1);
                    }
                    file = ExtractFileFromGP2(path, inner, &size);
                    if (file != NULL)
                    {
                        PartyMember* member = (PartyMember*)GetCombatantWithFlag0x100_0200ff1c(gameState, GetField0x3acValue_020100a8(gameState));
                        ResetListHeader020727d8((List020727d8*)&list);
                        int female = member->data_->female_;
                        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, self->title_, comment, female);
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    AppendString02042058(comment, GetFieldByKey020e0434((Container020e0310*)&self->texts_, 1000));
#if defined(jpn)
                    func_0204500c(messages, comment, 0);
#else
                    func_0204500c(messages, comment, 0, 0xe3);
#endif
                    messages->b19b2 = 1;
                    messages->b19c8 = 1;
                    messages->state = 2;
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
#if !defined(jpn)
                if (!(self->flags_ & 0x200))
                    shown = 0;
#endif
                if (REGION_MESSAGE(self, shown))
                {
#if defined(jpn)
                    func_0204500c(messages, GetFieldByKey020e0434((Container020e0310*)&self->texts_, 10000), 0);
#else
                    func_0204500c(messages, GetFieldByKey020e0434((Container020e0310*)&self->texts_, 10000), 0, 0xe3);
#endif
                    messages->b19b2 = 1;
                    messages->b19c8 = 1;
                    messages->state = 2;
                }
            }
            if (REGION_FLAG(self, 0x20000))
            {
                messages->b19c5 = 1;
                messages->b19b2 = 0;
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
        int selected = ComputeScaledSum0205bb84((Struct_0205bb84*)&self->cursor_);
#if defined(jpn)
        int limit = 5;
        int first = self->top_;
        limit += first;
        if (selected > limit)
            self->top_ = selected - 5;
        else if (selected < first)
            self->top_ = selected;
#else
        if (selected > self->top_ + 5)
            self->top_ = selected - 5;
        else if (selected < self->top_)
            self->top_ = selected;
#endif
        unsigned char kind = self->items_[selected];
        if (TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x401) || result == 1)
        {
            if (!func_0202c540(func_0202ae18()) || kind != 5)
            {
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                self->state_ = kind + 5;
                self->step_ = 0;
                self->flags_ &= ~8;
                self->flags_ &= ~0x20;
                return;
            }
        }
        else if (TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x806) || result == -2)
        {
            self->state_ = 13;
            self->step_ = 0;
            self->flags_ &= ~8;
            self->flags_ &= ~0x20;
        }
    }
}
