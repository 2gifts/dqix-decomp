#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct TextTable {
    int pad_0[0x18 / 4];
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
    void AdvanceEffects();
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

typedef void (BattleRecords::*StateFunction)(unsigned int ticks);

struct StateTable {
    StateFunction states[15];
};

extern StateTable data_ov008_0218b340;
extern StateFunction data_020e6d5c;

struct GameState {
    static GameState* GetInstance();
    unsigned int GetTickCount() const;
};

struct Obj021870e4;
struct TaskState0209ff6c;

extern "C" void _Z33ClearFlagIfDone_021870e4_021870e4P11Obj021870e4(Obj021870e4* self);
extern "C" void _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(TaskState0209ff6c* titles);

extern "C" {
void func_ov008_02188ef0(BattleRecords* self);
unsigned char func_0205d0e0(TextWindow* window, int ticks);
void func_ov008_02186e4c(BattleRecords* self, unsigned int ticks);
void func_ov008_0218747c(BattleRecords* self, int index);
void func_ov023_021eb43c(void* guide);
}

// USA: func_ov008_02184754
extern "C" ARM int func_ov008_02184754(BattleRecords* self)
{
    func_ov008_02188ef0(self);
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_0205d0e0(&self->window_, ticks);
    func_ov008_02186e4c(self, ticks);
    self->model_.AdvanceEffects();
    ((void (*)(BattleRecords*, unsigned int))_Z33ClearFlagIfDone_021870e4_021870e4P11Obj021870e4)(self, ticks);
    func_ov008_0218747c(self, 0);
    func_ov008_0218747c(self, 1);
    StateTable table = data_ov008_0218b340;
    table.states[14] = data_020e6d5c;
    if (table.states[self->state_] == NULL)
        return 0;
    (self->*table.states[self->state_])(ticks);
    if (self->titles_ != NULL)
        _Z21PollOv017Task0209ff6cP17TaskState0209ff6c((TaskState0209ff6c*)self->titles_);
    if (self->guide_ != NULL)
        func_ov023_021eb43c(self->guide_);
    if (self->state_ == 14)
        return 1;
    return 0;
}
