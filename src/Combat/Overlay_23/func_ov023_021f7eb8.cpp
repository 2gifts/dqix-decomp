#include <globaldefs.h>

struct Canvas_021f7eb8 {
    char unk_0[0xe0];
};

class MenuObject_021f7eb8 {
public:
    unsigned short type_;
    short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    MenuObject_021f7eb8* prev_;
    MenuObject_021f7eb8* next_;
    int state_;

    virtual void V00();
};

class MenuCanvas_021f7eb8 : public MenuObject_021f7eb8 {
public:
    Canvas_021f7eb8 canvas_;
    unsigned short x_;
    unsigned short y_;
    short page_;
    short pages_;
    unsigned char frame_;
    char unk_109;
    unsigned char color_;
    char unk_10b;
    unsigned short unk_10c;
    unsigned short unk_10e;
};

struct Glyph_021f7eb8 {
    int code;
    signed char width;
};

struct Obj0204fbf8;

extern "C" void _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih(Canvas_021f7eb8* canvas, int value, int id);
extern "C" void func_0204f174(Canvas_021f7eb8* canvas, short x, short y, short width, short height,
                              unsigned char frame, unsigned char a, unsigned char b, int);
extern "C" void func_0204fae8(Canvas_021f7eb8* canvas);
extern "C" Glyph_021f7eb8* _Z22FindEntryByKey0204254cii(const char* text, int table);
extern "C" void func_0204f7e8(Canvas_021f7eb8* canvas, short x, short y, int value, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int, int, int, int);
extern "C" void func_0204f41c(Canvas_021f7eb8* canvas, short x, short y, const char* text, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int);
extern "C" void func_ov023_021f8240(MenuCanvas_021f7eb8* self, void* script);
extern "C" void _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(Canvas_021f7eb8* canvas);

extern const char data_ov023_021fd91c[];

// USA: func_ov023_021f7eb8
extern "C" ARM void func_ov023_021f7eb8(MenuCanvas_021f7eb8* self, void* script, int value, short x, short y,
                                        short width, short height, unsigned char frame, unsigned char a,
                                        unsigned char b) {
    _Z37SetField0xa0AndByte0xc4IfFlag0x1ClearPhih(&self->canvas_, value, self->id_);
    func_0204f174(&self->canvas_, x, y, width, height, frame, a, b, 0);
    if (self->flags_ & 4) {
        if (self->pages_ > 1)
            func_0204fae8(&self->canvas_);
        height = (short)(height * 8) - 13;
        unsigned char color;
        int separatorWidth = 0;
        color = self->color_;
        Glyph_021f7eb8* glyph = _Z22FindEntryByKey0204254cii(data_ov023_021fd91c, 0);
        if (glyph != NULL)
            separatorWidth = glyph->width;
        unsigned short textWidth;
        unsigned short textHeight;
        short center = width * 4;
        func_0204f7e8(&self->canvas_, center - separatorWidth, height, self->page_ + 1, 8, color, &textWidth,
                      &textHeight, 1, 3, 0, 0);
        func_0204f7e8(&self->canvas_, center + separatorWidth + 1, height, self->pages_, 8, color, &textWidth,
                      &textHeight, 0, 3, 0, 0);
        func_0204f41c(&self->canvas_, center - (separatorWidth >> 1), height, data_ov023_021fd91c, 8, color,
                      &textWidth, &textHeight, 0);
    }
    func_ov023_021f8240(self, script);
    _Z36InvokeHandlerAfterCacheFlush0204fbf8P11Obj0204fbf8(&self->canvas_);
    self->x_ = x * 8;
    self->y_ = y * 8;
}
