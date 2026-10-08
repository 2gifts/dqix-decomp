#include <globaldefs.h>

class GameState {
public:
    static GameState* GetInstance();
    unsigned int GetTickCount() const;
};

struct AlchemyMenu {
    char unk_0[0x74];
    char ingredients_[0x28];
    char repeat_[0x64];
    char layout_[0x28b];
    unsigned char count_;
    char unk_38c[0x7];
    unsigned char repeatDelay_;
    char unk_394[0x9c];
    unsigned char arrowUp_;
    unsigned char arrowDown_;
};

extern "C" short func_ov023_021e2868(void* layout);
extern "C" short func_ov023_021e29d0(void* layout);
extern "C" unsigned short func_02081f20(void* repeat, int ticks);
extern "C" unsigned short _Z26GetDeref_021599ac_021599acPPv(void** repeat);
extern "C" int func_ov006_02153a78(void* ingredients, int times);
extern "C" void func_ov006_0215f9e8(AlchemyMenu* self);
extern "C" void func_ov006_0215a5dc(AlchemyMenu* self);

// USA: func_ov006_021599c0
extern "C" ARM unsigned char func_ov006_021599c0(AlchemyMenu* self) {
    int confirm = 0;
    int cancel = 0;
    int change = 0;
    if (self->repeatDelay_ < 5) {
        self->repeatDelay_++;
    } else {
        short button = func_ov023_021e2868(self->layout_);
        if (button == 0x49)
            change = 1;
        if (button == 0x4a)
            change = -1;
        if (change != 0)
            self->repeatDelay_ = 0;
    }
    unsigned char count = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x49)
            change = 1;
        if (element == 0x4a)
            change = -1;
        confirm = element == 0x4e ? 1 : 0;
        cancel = element == 0x14 ? 1 : 0;
    }
    if ((unsigned short)(func_02081f20(self->repeat_, GameState::GetInstance()->GetTickCount()) + 0xffff) <= 1) {
        unsigned short buttons = _Z26GetDeref_021599ac_021599acPPv((void**)self->repeat_);
        if (buttons == 0x40)
            change = 1;
        if (buttons == 0x80)
            change = -1;
        if (buttons == 0x20)
            count = 9;
        if (buttons == 0x10)
            count = 1;
    }
    if (count != 0) {
        int previous = self->count_;
        self->count_ = count;
        while (!func_ov006_02153a78(self->ingredients_, self->count_))
            self->count_--;
        if (previous < self->count_)
            self->arrowUp_ = 1;
        if (self->count_ < previous)
            self->arrowDown_ = 1;
        func_ov006_0215f9e8(self);
        func_ov006_0215a5dc(self);
        return 1;
    }
    if (change != 0) {
        int previous = self->count_;
        self->count_ = previous + change;
        if (!func_ov006_02153a78(self->ingredients_, self->count_))
            self->count_--;
        if (self->count_ == 0)
            self->count_ = 1;
        if (self->count_ > 9)
            self->count_ = 9;
        if (previous < self->count_)
            self->arrowUp_ = 1;
        if (self->count_ < previous)
            self->arrowDown_ = 1;
        func_ov006_0215f9e8(self);
        func_ov006_0215a5dc(self);
        return 1;
    }
    if (confirm)
        return 2;
    if (cancel)
        return 3;
    return 0;
}
