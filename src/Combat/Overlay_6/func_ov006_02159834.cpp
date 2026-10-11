#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#define func_ov006_021570fc func_ov006_02158704
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

class GameState {
public:
    static GameState* GetInstance();
    unsigned int GetTickCount() const;
};

struct AlchemyMenu {
    char unk_0[R(0x94, 0x9c)];
    char repeat_[0x64];
    char layout_[R(0x293, 0x28b)];
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
extern "C" void func_ov006_02159320(AlchemyMenu* self);
extern "C" void func_ov006_021593b0(AlchemyMenu* self);

// USA: func_ov006_02159834
extern "C" ARM int func_ov006_02159834(AlchemyMenu* self) {
    int confirm = 0;
    int cancel = 0;
    int change = 0;
    if (self->repeatDelay_ < 5) {
        self->repeatDelay_++;
    } else {
        short button = func_ov023_021e2868(self->layout_);
        if (button == 0x76)
            change = 1;
        if (button == 0x77)
            change = -1;
        if (change != 0)
            self->repeatDelay_ = 0;
    }
    unsigned char count = 0;
    short element = func_ov023_021e29d0(self->layout_);
    if (element >= 0) {
        if (element == 0x76)
            change = 1;
        if (element == 0x77)
            change = -1;
        confirm = element == 0x11 ? 1 : 0;
        cancel = element == 0x12 ? 1 : 0;
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
        if (count == 9)
            func_ov006_02159320(self);
        else
            func_ov006_021593b0(self);
        self->arrowUp_ = previous < self->count_ ? 1 : 0;
        self->arrowDown_ = self->count_ < previous ? 1 : 0;
        return 1;
    }
    if (change != 0) {
        if (change > 0)
            func_ov006_02159320(self);
        else
            func_ov006_021593b0(self);
        return 1;
    }
    if (confirm)
        return 2;
    if (cancel)
        return 3;
    return 0;
}
