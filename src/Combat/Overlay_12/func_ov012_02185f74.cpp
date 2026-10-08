#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "System/ColorEffects.h"

struct Background02185f74
{
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas02185f74
{
    void* unk_0;
    Background02185f74* background_;
    char unk_8[0xe0 - 8];
};

struct Window02185f74
{
    char unk_0[0x98];
    Background02185f74* background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct ProfileEditor02185f74
{
    char unk_0[0x20];
    SafeAllocator allocators_[7];
    Window02185f74 window_;
    Background02185f74 backgrounds_[3];
    Canvas02185f74 canvases_[13];
    char unk_d28[0x137c - 0xd28];
    void* pixels_;
    int tasks_[6];
};

struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;

void SetWord0x18ClearByte0x1f(unsigned char* background, int a);
extern "C" void func_0204b5b4(Background02185f74* background, int a);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c* background, SafeAllocator* allocator);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* background, int a, int b);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(Background02185f74* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0204bc74(Background02185f74* background, int a, int b, int c, int d, int e, int f);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* background, void* a);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);

extern "C" const unsigned char data_ov012_0218af75[3];
extern "C" const unsigned char data_ov012_0218af78[3];

// USA: func_ov012_02185f74
extern "C" ARM void func_ov012_02185f74(ProfileEditor02185f74* self)
{
    Background02185f74* background;
    int count;
    BackgroundLoader* loader;
    Canvas02185f74* canvas;
    char name[4];
    void* file;
    unsigned int size;
    unsigned int fileSize;
    loader = BackgroundLoader::GetInstance();
    self->allocators_[0].Reset();
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds_[i];
        SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
        background->unk_1c_0_ = 0;
        background->unk_1c_4_ = data_ov012_0218af75[i];
        func_0204b5b4(background, data_ov012_0218af78[i]);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)background, &self->allocators_[0]);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)background, 0, 0);
    }
    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e00;
    BG3CNT = (BG3CNT & 0x43) | 0x1f08;
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);

    loader->GetLoadedFileByID(self->tasks_[3], &file, &size);
    count = CountActiveEntries((ActiveEntry02046900*)file);
    for (int i = 0; i < count; i++)
    {
        void* data = FindRecordByIndex((Rec020467f0*)file, i, (void**)name, (int*)&fileSize);
        if (data != 0)
        {
            func_0204b174(&self->backgrounds_[1], data, &self->allocators_[0], fileSize);
            func_0204b174(&self->backgrounds_[2], data, &self->allocators_[0], fileSize);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds_[i];
        func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
        _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)background, 0);
    }
    self->pixels_ = self->allocators_[0].Allocate(0x7800);
    for (int i = 0; i < 13; i++)
    {
        canvas = &self->canvases_[i];
        _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8*)canvas, &self->allocators_[0], (int)self->pixels_, 0x800);
        canvas->background_ = &self->backgrounds_[1];
    }
    self->window_.background_ = self->backgrounds_;
    self->window_.unk_b2 = 3;
    _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78*)&self->window_, (Elem_0205cf78*)self->canvases_, 13);
    loader->RemoveTask(self->tasks_[3]);
    self->tasks_[3] = -1;
}
