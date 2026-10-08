#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <Graphics/Vector.h>

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
    int pad_0[0x50 / 4];
    Vector3fix rotation_;
    int pad_5c[(0xac - 0x5c) / 4];
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

extern unsigned short data_02114e30[];

int TestFlagMask(unsigned short* pad, int buttons);

// USA: func_ov008_02186e4c
extern "C" ARM void func_ov008_02186e4c(BattleRecords* self, unsigned int ticks)
{
    int flags = self->flags_;
    if (flags & 0x40)
    {
        Vector3fix rotation = self->model_.rotation_;
        int done = 0;
        int y;
        int angle = fix32ReduceAngle0To2Pi(0x5ccc - rotation.y);
        if (angle >= 0 && angle < 0x3244)
        {
            y = rotation.y + angle / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                y += fix32ReduceAngle0To2Pi(0x5ccc - y) / 12;
        }
        else if (angle >= 0x3244 && angle < 0x6488)
        {
            y = rotation.y - (0x6488 - angle) / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                y -= (0x6488 - fix32ReduceAngle0To2Pi(0x5ccc - y)) / 12;
        }
        rotation.y = fix32ReduceAngle0To2Pi(y);
        self->model_.rotation_ = rotation;
        int difference = fix32ReduceAngle0To2Pi(0x5ccc - rotation.y);
        int distance = difference < 0 ? -difference : difference;
        if (distance < 0x28)
        {
            done = 1;
        }
        else
        {
            distance = 0x6488 - difference;
            if (distance < 0)
                distance = -distance;
            if (distance < 0x28)
                done = 1;
        }
        if (done)
        {
            rotation.y = fix32ReduceAngle0To2Pi(0x5ccc);
            self->model_.rotation_ = rotation;
            self->flags_ &= ~0x40;
        }
    }
    else if (flags & 0x20)
    {
        int left = 0;
        int right = 0;
        if (TestFlagMask(data_02114e30, 0x200))
            left = 1;
        if (TestFlagMask(data_02114e30, 0x100))
            right = 1;
        if (left && right)
        {
            self->flags_ |= 0x40;
            return;
        }
        if (!left && !right)
            return;
        Vector3fix rotation = self->model_.rotation_;
        if (left)
            rotation.y += (int)(4096.0f * (0.08f * ticks));
        if (right)
            rotation.y -= (int)(4096.0f * (0.08f * ticks));
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        self->model_.rotation_ = rotation;
    }
}
