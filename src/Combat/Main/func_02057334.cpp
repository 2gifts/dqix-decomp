#include <globaldefs.h>
#include <GameState/GameState.h>

struct S02055080;
struct Struct02058c88
{
    unsigned char padding[0x148];
    Struct02058c88* next;
};
struct Obj02055c30;

struct ListNode02057854
{
    unsigned char padding_0x0[4];
    unsigned int frame;
    unsigned int endFrame;
    unsigned char repeat;
    unsigned char padding_0xd[0x23];
    S02055080* resource;
    Struct02058c88* head;
    unsigned char flags;
    unsigned char padding_0x39[0x13];
    float channelSlopes[4];
    unsigned char padding_0x5c[8];
    float translationSlopes[3];
    float rotationSlopes[3];
    float scaleSlopes[3];
    unsigned char padding_0x88[0x14];
    float durationSlope;
    unsigned char padding_0xa0[4];
    float extraSlopes[3];
    float vectorSlopes[3];
    unsigned char padding_0xbc[0x5c];
    float channels[4];
    float translation[3];
    float rotation[3];
    float scale[3];
    float duration;
    int delay;
    unsigned int finalFrame;
    float extra[3];
    float vector[3];
};

struct AnimationTiming02057334
{
    unsigned char padding[6];
    unsigned char interval;
};

extern "C" int _Z40CheckListStableAndField8LtField402057854P16ListNode02057854(ListNode02057854*);
extern "C" void _Z18InitStruct02058c88P14Struct02058c88(Struct02058c88*);
void* GetSubField0x8(S02055080*);
extern "C" void _Z41UpdateCounterAndMaybeComputeSlope02055c30P11Obj02055c30(Obj02055c30*);
extern "C" void func_02056d80(ListNode02057854*);
extern "C" void func_020557a4(ListNode02057854*);
extern "C" void func_020559cc(ListNode02057854*);
extern "C" void func_02055ccc(ListNode02057854*);
extern "C" void func_02059720(Struct02058c88*);
extern "C" void func_02055f5c(ListNode02057854*, int, int);

// USA: func_02057334
extern "C" ARM int func_02057334(ListNode02057854* self)
{
    int steps = 0;
    int skip = 0;
    int ticks = GameState::GetInstance()->GetTickCount();
    if (!_Z40CheckListStableAndField8LtField402057854P16ListNode02057854(self))
    {
        if (self->frame > self->endFrame && self->flags)
        {
            Struct02058c88* child = self->head;
            while (child)
            {
                _Z18InitStruct02058c88P14Struct02058c88(child);
                child = child->next;
            }
        }
        else if (self->frame > self->endFrame && !self->flags)
        {
            skip = 1;
        }
        if (self->frame > self->endFrame && self->repeat)
        {
            func_02056d80(self);
            skip = 1;
        }
        if (!skip)
        {
            if (self->frame > self->finalFrame)
            {
                self->delay -= ticks;
                if (self->delay < 0)
                {
                    int interval = ((AnimationTiming02057334*)GetSubField0x8(self->resource))->interval;
                    self->delay = interval;
                    if (ticks < interval + 1)
                    {
                        steps = 1;
                    }
                    else
                    {
                        steps = ticks / (interval + 1);
                    }
                }
            }
            self->channels[0] += self->channelSlopes[0] * (float)ticks;
            self->channels[1] += self->channelSlopes[1] * (float)ticks;
            self->channels[2] += self->channelSlopes[2] * (float)ticks;
            self->channels[3] += self->channelSlopes[3] * (float)ticks;
            for (int i = 0; i < 3; i++)
            {
                self->translation[i] += (float)ticks * self->translationSlopes[i];
                self->rotation[i] += (float)ticks * self->rotationSlopes[i];
                self->scale[i] += (float)ticks * self->scaleSlopes[i];
                self->extra[i] += (float)ticks * self->extraSlopes[i];
                self->vector[i] += (float)ticks * self->vectorSlopes[i];
            }
            self->duration += self->durationSlope * (float)ticks;
            func_020557a4(self);
            func_020559cc(self);
            _Z41UpdateCounterAndMaybeComputeSlope02055c30P11Obj02055c30((Obj02055c30*)self);
            func_02055ccc(self);
        }
    }
    if (!_Z40CheckListStableAndField8LtField402057854P16ListNode02057854(self) || !self->flags)
    {
        Struct02058c88* child = self->head;
        while (child)
        {
            func_02059720(child);
            child = child->next;
        }
    }
    if (steps)
    {
        func_02055f5c(self, ticks, steps);
    }
    if (!_Z40CheckListStableAndField8LtField402057854P16ListNode02057854(self))
    {
        self->frame += ticks;
    }
    return steps != 0;
}
