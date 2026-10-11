#include <globaldefs.h>

struct Canvas_021df558 {
    char data[0xe0];
};

struct LayoutElement_021df558 {
    char pad0[0x16];
    unsigned char flags_;
    unsigned char unk_17;
};

struct Layout_021df558 {
    int unk_0;
    Canvas_021df558* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
    char pad14[0x48 - 0x14];
    short textHeight_;
    short textHeight12_;
};

struct PartEntry_021df558 {
    void* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int type_ : 5;
    unsigned int rank_ : 3;
    unsigned int unk_8_12 : 6;
    unsigned int cursed_ : 1;
    unsigned int unk_8_19 : 13;
    unsigned int unk_c;
    unsigned int unk_10;
    int unk_14;
    short unk_18;
    unsigned short price_;
    char unk_1c[0x20 - 0x1c];
};

struct ItemInfoWindow_021df558 {
    char pad0[0x4c];
    PartEntry_021df558* item_;
    char pad50[0xcc - 0x50];
    Layout_021df558 layout_;
#if defined(jpn)
    char pad118[0x62c - 0x118];
    char description_[0x6d8 - 0x62c];
#else
    char pad118[0x630 - 0x118];
    char description_[0x75c - 0x630];
#endif

    unsigned int vramOffset_;
};

struct StructAcAe021db45c;

struct Statics_021df558 {
#if defined(jpn)
    void* sTexts;
    int sPalette2;
    int sPalette3;
    int sPalette;
    void* sFieldNames;
    void* sBuffer;
    void* sDrops;
#else
    void* sDrops;
    void* sBuffer;
    void* sFieldNames;
    int sPalette;
    int sPalette2;
    void* sTexts;
    int sPalette3;
#endif

};
extern "C" Statics_021df558 data_ov023_021ff9e0;

extern "C" void func_0204c684(Canvas_021df558* canvas);
int InitBufferFromDataField4_021ddc34(void* canvas, short x, short y, short width, short height);
extern "C" void __clear(void* buffer, unsigned long size);
void* GetGlobalField0x1c020421a0();
extern "C" void func_02046608(void* messages, int, const char* input, char* output, int, int, int);
extern "C" LayoutElement_021df558* func_ov023_021db4e4(Layout_021df558* layout, int id);
void SetEntryFields_021e23d0(void* layout, int id, int text, unsigned char color, unsigned char shadow);
void UpdateEntryAndReset_021db45c(void* layout, struct StructAcAe021db45c* canvas, int id, short* x, short* y);
extern "C" void func_ov023_021e257c(Layout_021df558* layout);
void CreateAndSetFields8A_021db544(void* layout, void* id, int x, int y);
extern "C" unsigned int func_ov023_021ddc98(Canvas_021df558* canvas, unsigned int offset, unsigned short palette, int bg1);
unsigned short EvalOrDispatch020de194(void* item);
void SetPackedFields_021e24b0(void* layout, int id, int value, unsigned char color, unsigned char shadow,
                              unsigned char unk4, unsigned char digits, unsigned char unk5, unsigned char unk6);

#define SHOW_ELEMENT(layout, id)                                           \
    {                                                                      \
        LayoutElement_021df558* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ |= 1;                                          \
    }

#define HIDE_ELEMENT(layout, id)                                           \
    {                                                                      \
        LayoutElement_021df558* element = func_ov023_021db4e4(layout, id); \
        if (element != NULL)                                               \
            element->flags_ &= ~1;                                         \
    }

static inline int IsEquipment(const PartEntry_021df558* item)
{
    return item->category_ <= 7 ? 1 : 0;
}

// JPN: func_ov023_021dfbac
// USA: func_ov023_021df558
extern "C" ARM void func_ov023_021df558(ItemInfoWindow_021df558* self)
{
    Canvas_021df558 canvas;
    func_0204c684(&canvas);
    if (InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 0xe, 8))
    {
        PartEntry_021df558* item = self->item_;
        if (item != NULL)
        {
            short group = 0x14;
            short text = 4;
            if (IsEquipment(item))
            {
                group = 0x1c;
                text = 7;
            }
#if defined(jpn)
            SetEntryFields_021e23d0(&self->layout_, text, (int)self->description_, 12, 15);
#else
            char formatted[0x100] = {0};
            func_02046608(GetGlobalField0x1c020421a0(), 10, self->description_, formatted, 0x68, 0, 0);
            SetEntryFields_021e23d0(&self->layout_, text, (int)formatted, 10, 15);
#endif

            SHOW_ELEMENT(&self->layout_, group);
            short y;
            short x;
            UpdateEntryAndReset_021db45c(&self->layout_, (StructAcAe021db45c*)&canvas, group, &x, &y);
            if (data_ov023_021ff9e0.sBuffer != NULL)
            {
                self->layout_.canvas_ = &canvas;
                self->layout_.unk_12 = 1;
#if defined(jpn)

#else
                self->layout_.textHeight_ = 0xe;
#endif

                func_ov023_021e257c(&self->layout_);
            }
            CreateAndSetFields8A_021db544(&self->layout_, (void*)group, x, y);
            HIDE_ELEMENT(&self->layout_, group);
        }
        self->vramOffset_ += func_ov023_021ddc98(&canvas, self->vramOffset_, data_ov023_021ff9e0.sPalette3, 0);
    }
    if (IsEquipment(self->item_))
        return;
    if (InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 8, 2))
    {
        PartEntry_021df558* item = self->item_;
        SHOW_ELEMENT(&self->layout_, 0x10);
        if (item->category_ == 9 || EvalOrDispatch020de194(item) == 0)
        {
            HIDE_ELEMENT(&self->layout_, 5);
            HIDE_ELEMENT(&self->layout_, 0x17);
            SHOW_ELEMENT(&self->layout_, 0x19);
        }
        else
        {
            SetPackedFields_021e24b0(&self->layout_, 5, EvalOrDispatch020de194(item), 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&self->layout_, 5);
            SHOW_ELEMENT(&self->layout_, 0x17);
            HIDE_ELEMENT(&self->layout_, 0x19);
        }
        short y;
        short x;
        UpdateEntryAndReset_021db45c(&self->layout_, (StructAcAe021db45c*)&canvas, 0x10, &x, &y);
        if (data_ov023_021ff9e0.sBuffer != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        CreateAndSetFields8A_021db544(&self->layout_, (void*)0x10, x, y);
        HIDE_ELEMENT(&self->layout_, 0x10);
        self->vramOffset_ += func_ov023_021ddc98(&canvas, self->vramOffset_, data_ov023_021ff9e0.sPalette3, 0);
    }
    if (InitBufferFromDataField4_021ddc34(&canvas, 0, 0, 8, 2))
    {
        PartEntry_021df558* item = self->item_;
        SHOW_ELEMENT(&self->layout_, 0x12);
        unsigned short price;
        if (item->category_ == 9 || (price = item->price_) == 0)
        {
            HIDE_ELEMENT(&self->layout_, 6);
            HIDE_ELEMENT(&self->layout_, 0x18);
            SHOW_ELEMENT(&self->layout_, 0x1a);
        }
        else
        {
            SetPackedFields_021e24b0(&self->layout_, 6, price, 8, 15, 1, 6, 0, 0);
            SHOW_ELEMENT(&self->layout_, 6);
            SHOW_ELEMENT(&self->layout_, 0x18);
            HIDE_ELEMENT(&self->layout_, 0x1a);
        }
        short y;
        short x;
        UpdateEntryAndReset_021db45c(&self->layout_, (StructAcAe021db45c*)&canvas, 0x12, &x, &y);
        if (data_ov023_021ff9e0.sBuffer != NULL)
        {
            self->layout_.canvas_ = &canvas;
            self->layout_.unk_12 = 1;
            func_ov023_021e257c(&self->layout_);
        }
        CreateAndSetFields8A_021db544(&self->layout_, (void*)0x12, x, y);
        HIDE_ELEMENT(&self->layout_, 0x12);
        self->vramOffset_ += func_ov023_021ddc98(&canvas, self->vramOffset_, data_ov023_021ff9e0.sPalette3, 0);
    }
}
