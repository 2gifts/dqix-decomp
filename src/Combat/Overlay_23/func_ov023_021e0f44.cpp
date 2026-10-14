#include <globaldefs.h>

struct Canvas_021e0f44 {
    char data[0xe0];
};

struct LayoutElement_021e0f44 {
    char pad0[0x16];
    unsigned char flags_;
    unsigned char unk_17;
};

struct Layout_021e0f44 {
    int unk_0;
    Canvas_021e0f44* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
    char pad14[0x4c - 0x14];
};

struct ItemInfoWindow_021e0f44 {
    char pad0[0xbc];
    short monsters_[3];
    short numMonsters_;
    char padc4[0xcc - 0xc4];
    Layout_021e0f44 layout_;
#if defined(jpn)
    char pad118[0x6d8 - 0x118];
#else
    char pad118[0x75c - 0x118];
#endif

    unsigned int vramOffset_;
    char pad760[0x774 - 0x760];
    unsigned short flags_;
};

struct Container020e0310;
struct StructAcAe021db45c;

struct Statics_021e0f44 {
#if defined(jpn)
    struct Container020e0310* sTexts;
    char pad4[8];
    int sPalette;
    int pad10;
    void* sBuffer;
    int pad18;
    ItemInfoWindow_021e0f44* sWindow;
    char pad20[8];
    struct Container020e0310* sMonsterNames;

#else
    void* sDrops;
    void* sBuffer;
    void* sFieldNames;
    int sPalette;
    int sPalette2;
    struct Container020e0310* sTexts;
    int sPalette3;
    int sStatesGuard;
    ItemInfoWindow_021e0f44* sWindow;
    void* sPlaces;
    struct Container020e0310* sMonsterNames;

#endif
};
extern "C" Statics_021e0f44 data_ov023_021ff9e0;
extern "C" const short data_ov023_021fd5a8[2] __attribute__((aligned(4)));

extern "C" void func_0204c684(Canvas_021e0f44* canvas);
int InitBufferFromDataField4_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
const char* GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" LayoutElement_021e0f44* func_ov023_021db4e4(Layout_021e0f44* layout, int id);
void SetEntryFields_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char shadow);
void CopyTextAndUppercaseIfFlagged0206819c(const char* input, char* output, int flag);
void UpdateEntryAndReset_021db45c(void* layout, struct StructAcAe021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Layout_021e0f44* layout);
void CreateAndSetFields8A_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021e0f44* canvas, unsigned int offset, unsigned short palette, int bg1);

#define SHOW_ELEMENT(layout, id)                                         \
    {                                                                    \
        LayoutElement_021e0f44* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->flags_ |= 1;                                        \
    }

#define HIDE_ELEMENT(layout, id)                                         \
    {                                                                    \
        LayoutElement_021e0f44* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                             \
            element->flags_ &= ~1;                                       \
    }

// USA: func_ov023_021e0f44
extern "C" ARM void func_ov023_021e0f44(ItemInfoWindow_021e0f44* self)
{
    Canvas_021e0f44 canvas;
    func_0204c684(&canvas);
    if (!InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 0x1c, 3))
        return;
    if (!(self->flags_ & 0x400))
    {
#if defined(jpn)

#else
        char names[2][0x80] = {0};
#endif

        const char* found = GetFieldByKey020e0434(data_ov023_021ff9e0.sTexts, 0x1f);
        const char* none = GetFieldByKey020e0434(data_ov023_021ff9e0.sTexts, 0x1e);
        SHOW_ELEMENT(&self->layout_, 0xe);
        SHOW_ELEMENT(&self->layout_, 0xd);
        SetEntryFields_021e23d0(&self->layout_, 0xb, (int)found, 10, 15);
        SetEntryFields_021e23d0(&self->layout_, 0xc, (int)found, 10, 15);
        SetEntryFields_021e23d0(&self->layout_, 0xd, (int)none, 10, 15);
        int i = 0;
        short count = data_ov023_021ff9e0.sWindow->numMonsters_;
        for (; i < count; i++)
        {
            if (i >= 2)
                break;
            const char* name = GetFieldByKey020e0434(data_ov023_021ff9e0.sMonsterNames, data_ov023_021ff9e0.sWindow->monsters_[i]);
            if (name != NULL)
            {
#if defined(jpn)
                SetEntryFields_021e23d0(&self->layout_, data_ov023_021fd5a8[i], (int)name, 10, 15);
#else
                CopyTextAndUppercaseIfFlagged0206819c(name, names[i], 0);
                SetEntryFields_021e23d0(&self->layout_, data_ov023_021fd5a8[i], (int)names[i], 10, 15);
#endif

            }
        }
        if (count != 3)
            HIDE_ELEMENT(&self->layout_, 0xd);
        short y;
        short x;
        UpdateEntryAndReset_021db45c(&self->layout_, (StructAcAe021db45c*)&canvas, 0xe, &x, &y);
        if (data_ov023_021ff9e0.sBuffer != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        CreateAndSetFields8A_021db544(&self->layout_, (void*)0xe, x, y);
        HIDE_ELEMENT(&self->layout_, 0xe);
    }
    self->vramOffset_ += func_ov023_021ddc98(&canvas, self->vramOffset_, data_ov023_021ff9e0.sPalette, 0);
}
