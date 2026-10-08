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
    int textPosition_;
    char** texts_;
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
    *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x2d8) = 0;
    if (self->allocators_ == 0)
        return;
    for (unsigned char i = 0; i < 10; i++)
    {
        if (self->allocators_[i].GetSignedAllocator() != 0)
            self->allocators_[i].Destroy();
    }
}
