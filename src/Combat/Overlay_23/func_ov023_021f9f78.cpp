#include <globaldefs.h>

struct MenuMove_021f9f78
{
    unsigned short id_;
    unsigned char kind_;
    unsigned char phase_;
    int speed_;
    int acceleration_;
    int maxSpeed_;
    int position_[3];
    int target_[3];
};

class MenuMover_021f9f78
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;
    unsigned short count_;
    MenuMove_021f9f78* moves_;

    virtual void Update(void* script);
};

typedef void (MenuMover_021f9f78::*MoveStep_021f9f78)(void* script, MenuMove_021f9f78* move);

struct MoveSteps_021f9f78
{
    MoveStep_021f9f78 steps[3];
};

extern MoveSteps_021f9f78 data_ov023_021fd92c;
extern MoveStep_021f9f78 data_020e6d5c;

// USA: func_ov023_021f9f78
extern "C" ARM void func_ov023_021f9f78(MenuMover_021f9f78* self, void* script)
{
    MoveSteps_021f9f78 steps = data_ov023_021fd92c;
    MoveStep_021f9f78 none = data_020e6d5c;
    steps.steps[0] = none;
    steps.steps[2] = none;
    for (int i = 0; i < self->count_; i++)
    {
        if (self->moves_[i].kind_ != 0)
            (self->*steps.steps[self->moves_[i].kind_])(script, &self->moves_[i]);
    }
}
