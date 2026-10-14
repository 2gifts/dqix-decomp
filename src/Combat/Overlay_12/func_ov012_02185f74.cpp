#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "System/ColorEffects.h"

#if defined(jpn)
#define data_ov012_0218af75 data_ov012_0218bcec
#define data_ov012_0218af78 data_ov012_0218bcef
enum { kPixels = 0x134c, kTask = 0x1358 };
#else
enum { kPixels = 0x137c, kTask = 0x138c };
#endif

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

struct WindowTransform02185f74
{
    int field0, field4, field8, fieldC;
    unsigned char field10;
    int field14, field18, field1C, field20, field24, field28, field2C;
};

struct WindowFrame02185f74
{
    WindowTransform02185f74 transform;
    int field30, field34;
    short field38, field3A;
    int field3C, field40, field44, field48;
    unsigned char field4C, field4D, field4E;
};

struct WindowCursor02185f74
{
    WindowTransform02185f74 transform;
    int field30;
    short field34;
    unsigned char field36, field37, field38, field39, field3A;
    unsigned char unknown3B, field3C, field3D;
};

struct ProfileWindow02185f74
{
    unsigned int unknown0;
    WindowFrame02185f74 frame;
    WindowCursor02185f74 cursor;
    unsigned char field94, field95;
    Background02185f74* backgrounds;
    Canvas02185f74* canvases;
    unsigned short fieldA0, fieldA2, fieldA4, fieldA6;
    unsigned short fieldA8, fieldAA, fieldAC, fieldAE;
    unsigned char fieldB0, fieldB1, backgroundCount, canvasCount;
    unsigned char fieldB4, fieldB5, fieldB6, fieldB7, fieldB8;
};

struct ProfileEditor02185f74
{
#if !defined(jpn)
    void* unknown0;
    void* unknown4;
#endif
    struct BgControl {
        unsigned short value;
        unsigned short unknown;
    } savedBgControls[4];
    unsigned char bgControlsSaved;
    unsigned char unknownFlag;
    unsigned short unknownAlignment;
    unsigned int savedPlanes;
#if defined(jpn)
    SafeAllocator allocators[6];
#else
    SafeAllocator allocators[7];
#endif
    ProfileWindow02185f74 window;
    Background02185f74 backgrounds[3];
    Canvas02185f74 canvases[13];
};

struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;

void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* background, int a);
extern "C" void func_0204b5b4(Background02185f74* background, int a);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(Background02185f74* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0204bc74(Background02185f74* background, int a, int b, int c, int d, int e, int f);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
void AllocateBuffer0204c7a8(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);

extern "C" const unsigned char data_ov012_0218af75[3];
extern "C" const unsigned char data_ov012_0218af78[3];

// USA: func_ov012_02185f74
extern "C" ARM void func_ov012_02185f74(ProfileEditor02185f74* self)
{
    Background02185f74* background;
    int count;
    BackgroundLoader* loader;
    Canvas02185f74* canvas;
    void* name;
    void* file;
    unsigned int size;
    int fileSize;
    loader = BackgroundLoader::GetInstance();
    self->allocators[0].Reset();
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds[i];
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)background, 0);
        background->unk_1c_0_ = 0;
        background->unk_1c_4_ = data_ov012_0218af75[i];
        func_0204b5b4(background, data_ov012_0218af78[i]);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &self->allocators[0]);
        DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
    }
    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e00;
    BG3CNT = (BG3CNT & 0x43) | 0x1f08;
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);

    loader->GetLoadedFileByID(*(int*)((char*)self + kTask), &file, &size);
    count = CountActiveEntries((ActiveEntry02046900*)file);
    for (int i = 0; i < count; i++)
    {
        void* data = FindRecordByIndex((Rec020467f0*)file, i, &name, &fileSize);
        if (data != 0)
        {
            func_0204b174(&self->backgrounds[1], data, &self->allocators[0], fileSize);
            func_0204b174(&self->backgrounds[2], data, &self->allocators[0], fileSize);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        background = &self->backgrounds[i];
        func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8*)background, 0);
    }
    char* storage = (char*)self;
    *(void**)(storage + kPixels) = self->allocators[0].Allocate(0x7800);
    for (int i = 0; i < 13; i++)
    {
        canvas = &self->canvases[i];
        AllocateBuffer0204c7a8((Obj0204c7a8*)canvas, &self->allocators[0], (int)*(void**)(storage + kPixels), 0x800);
        canvas->background_ = &self->backgrounds[1];
    }
    self->window.backgrounds = self->backgrounds;
    self->window.backgroundCount = 3;
    LinkArrayPrevPointers0205cf78((Struct_0205cf78*)&self->window, (Elem_0205cf78*)self->canvases, 13);
    loader->RemoveTask(*(int*)((char*)self + kTask));
    *(int*)((char*)self + kTask) = -1;
}
