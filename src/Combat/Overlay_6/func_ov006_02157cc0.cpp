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
#include "Memory/SafeAllocator.h"

struct StructInit36e0;
struct AlchemyPot;

extern "C" void func_ov006_021547c8(AlchemyPot*);
extern "C" void _Z27TailCallInitStruct_02153730P14StructInit36e0(StructInit36e0*);
extern "C" char* _Z26GetGlobalField0x1c020421a0v();

class BackgroundLoader {
public:
    static BackgroundLoader* GetInstance();
    void RemoveTask(int taskID);
};

struct AlchemyMenu {
#if !defined(jpn)
    int textPosition_;
    char** texts_;
#endif
    void* canvasBuffer_;
    SafeAllocator* allocators_;
    AlchemyPot* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* recipes_;
    void* pageStart_;
    void* recipe_;
    void* records_;
    char save_[8];
    short* cursor_;
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int repeat_[0xc / 4];
    unsigned short buttons_;
    unsigned char unk_aa;
    int renderer_[0x54 / 4];
    int layout_[0x4c / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
    int results_[4][0x74 / 4];
#if defined(jpn)
    char regionalPad[8];
#endif
    int ticks_;
    int menuResult_;
    int task_;
    int unk_358;
};

// USA: func_ov006_02157cc0
extern "C" ARM void func_ov006_02157cc0(AlchemyMenu* self)
{
    if (self->pot_ != 0)
    {
        func_ov006_021547c8(self->pot_);
        self->pot_ = 0;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0)
    {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    if (self->unk_358 >= 0)
    {
        loader->RemoveTask(self->unk_358);
        self->unk_358 = -1;
    }
    _Z27TailCallInitStruct_02153730P14StructInit36e0((StructInit36e0*)self->ingredients_);
    *(int*)(_Z26GetGlobalField0x1c020421a0v() + R(0x228, 0x2d8)) = 0;
    if (self->allocators_ == 0)
        return;
    for (unsigned char i = 0; i < 10; i++)
    {
        if (self->allocators_[i].GetSignedAllocator() != 0)
            self->allocators_[i].Destroy();
    }
}
