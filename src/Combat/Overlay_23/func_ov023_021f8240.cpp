#include <globaldefs.h>

struct Vec3_021f8240
{
    int x;
    int y;
    int z;
};

class MenuObject_021f8240
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    MenuObject_021f8240* prev_;
    MenuObject_021f8240* next_;
    int state_;

    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0c();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1c();
    virtual Vec3_021f8240 GetPosition();
    virtual void V24();
    virtual void V28();
    virtual void V2c();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3c();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4c();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5c();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6c();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7c();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8c();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9c();
    virtual void Va0();
    virtual void Va4();
    virtual void Va8();
    virtual void Vac();
    virtual void Vb0();
    virtual void Vb4();
    virtual void Vb8();
    virtual void Vbc();
    virtual void Vc0();
    virtual void Vc4();
    virtual void Vc8();
    virtual void Vcc();
    virtual void Vd0();
    virtual void Vd4();
    virtual void Vd8();
    virtual unsigned char GetColor();
    virtual void SetValue(int);
    virtual int GetValue();
};

class MenuText_021f8240 : public MenuObject_021f8240
{
public:
    const char* text_;
    Vec3_021f8240 unk_24;
    short unk_30;
    short unk_32;
    unsigned short canvas_;
    unsigned short texts_;
    short textId_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    short unk_42;
    unsigned char font_ : 4;
    unsigned char color_ : 4;
    unsigned char selected_ : 1;
    unsigned char alignment_ : 6;
    unsigned char formatted_ : 1;
};

class MenuNumber_021f8240 : public MenuObject_021f8240
{
public:
    Vec3_021f8240 unk_20;
    int value_;
    unsigned short canvas_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    unsigned char font_ : 4;
    unsigned char color_ : 4;
    unsigned char unk_3b;
    unsigned char unk_3c;
    unsigned char unk_3d;
};

class MenuBox_021f8240 : public MenuObject_021f8240
{
public:
    char unk_20[4];
    unsigned short canvas_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    unsigned char color_;
};

struct Canvas_021f8240
{
    char unk_0[0xb4];
    short unk_b4;
    short unk_b6;
    char unk_b8[0xe0 - 0xb8];
};

class MenuCanvas_021f8240 : public MenuObject_021f8240
{
public:
    Canvas_021f8240 canvas_;
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

struct Node021f68b8;
struct TableA68;
struct S021fc504;

extern "C" Node021f68b8* func_ov011_021849c8(void* script);
extern "C" MenuObject_021f8240* _Z19GetNthNode_021f68b8P12Node021f68b8i(Node021f68b8* list, int index);
extern "C" unsigned short func_ov023_021f6f10(MenuObject_021f8240* object);
extern "C" MenuObject_021f8240* func_ov023_021f6880(Node021f68b8* list, int id);
extern "C" TableA68* func_ov023_021fa598(MenuObject_021f8240* texts);
const char* FindEntryByKey(TableA68* texts, int id);
int IsValueEqual12(int font);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* text, char* output, int font);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046608(void* messages, int, const char* input, char* output, int, int, int);
extern "C" int func_020420e8(const char* text, int font);
extern "C" void func_0204f41c(Canvas_021f8240* canvas, short x, short y, const char* text, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int);
extern "C" void _Z28SetShortAt_021f8c48_021f8c48Phs(MenuText_021f8240* text, unsigned short width);
extern "C" void _Z28SetShortAt_021f8c58_021f8c58Phs(MenuText_021f8240* text, unsigned short height);
extern "C" void func_0204f7e8(Canvas_021f8240* canvas, short x, short y, int value, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int, int, int, int);
extern "C" void func_ov023_021fbcb0(MenuNumber_021f8240* number, unsigned short width);
extern "C" void _Z26SetField_021fbcb8_021fbcb8Pvt(void* number, unsigned short height);
extern "C" unsigned short func_ov023_021fc4fc(MenuBox_021f8240* box);
extern "C" unsigned short _Z19GetField2c_021fc504P9S021fc504(S021fc504* box);
extern "C" void func_0204f914(Canvas_021f8240* canvas, unsigned char color, short x, short y, short right,
                              short bottom);
extern "C" MenuObject_021f8240* _Z19GetField18_021f6f18Pv(void* object);

// USA: func_ov023_021f8240
extern "C" ARM void func_ov023_021f8240(MenuCanvas_021f8240* self, void* script)
{
    Node021f68b8* objects = func_ov011_021849c8(script);
    for (MenuObject_021f8240* object = _Z19GetNthNode_021f68b8P12Node021f68b8i(objects, 0); object != NULL;
         object = _Z19GetField18_021f6f18Pv(object))
    {
        int kind = 0;
        if (!(object->flags_ & 8))
        {
            switch (func_ov023_021f6f10(object))
            {
            case 8:
                kind = 1;
                break;
            case 15:
                kind = 2;
                break;
            case 19:
                kind = 3;
                break;
            }
        }
        if (kind == 1)
        {
            MenuText_021f8240* text = (MenuText_021f8240*)object;
            int size;
            const char* string;
            int formatted;
            unsigned char font;
            if (text->canvas_ != self->id_)
                continue;
            string = text->text_;
            if (string == NULL)
            {
                MenuObject_021f8240* texts = func_ov023_021f6880(objects, text->texts_);
                if (texts != NULL && func_ov023_021f6f10(texts) == 4)
                    string = FindEntryByKey(func_ov023_021fa598(texts), text->textId_);
            }
            if (string == NULL)
                continue;
            Vec3_021f8240 position = text->GetPosition();
            font = text->font_;
            unsigned char color = text->GetColor();
            short left = self->unk_10c + font;
            short right = self->unk_10e + font;
            self->canvas_.unk_b4 = left;
            self->canvas_.unk_b6 = right;
            formatted = text->formatted_;
            size = IsValueEqual12(text->font_);
            char codes[0x100] = {0};
            char formattedText[0x100] = {0};
            if (formatted)
            {
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(string, codes, size);
                func_02046608(_Z26GetGlobalField0x1c020421a0v(), 10, codes, formattedText, 0x400, 0, 0);
                string = formattedText;
            }
            int width = func_020420e8(string, size);
            int x = position.x / 4096.0f;
            int y = position.y / 4096.0f;
            switch (text->alignment_)
            {
            case 1:
                break;
            case 3:
                x -= width >> 1;
                break;
            case 2:
                x -= width;
                break;
            }
            unsigned short textWidth;
            unsigned short textHeight;
            func_0204f41c(&self->canvas_, x, y, string, font, color, &textWidth, &textHeight, 0);
            _Z28SetShortAt_021f8c48_021f8c48Phs(text, textWidth);
            _Z28SetShortAt_021f8c58_021f8c58Phs(text, textHeight);
        }
        else if (kind == 2)
        {
            MenuNumber_021f8240* number = (MenuNumber_021f8240*)object;
            if (number->canvas_ != self->id_)
                continue;
            unsigned char font = number->font_;
            int value = number->GetValue();
            unsigned char unk3b = number->unk_3b;
            unsigned char unk3c = number->unk_3c;
            unsigned char color = number->GetColor();
            Vec3_021f8240 position = number->GetPosition();
            unsigned char unk3d = number->unk_3d;
            self->canvas_.unk_b4 = font;
            self->canvas_.unk_b6 = font + 1;
            int x = position.x / 4096.0f;
            int y = position.y / 4096.0f;
            unsigned short textWidth;
            unsigned short textHeight;
            func_0204f7e8(&self->canvas_, x, y, value, font, color, &textWidth, &textHeight, unk3b, unk3c, 0, unk3d);
            func_ov023_021fbcb0(number, textWidth);
            _Z26SetField_021fbcb8_021fbcb8Pvt(number, textHeight);
        }
        else if (kind == 3)
        {
            MenuBox_021f8240* box = (MenuBox_021f8240*)object;
            if (box->canvas_ != self->id_)
                continue;
            unsigned char color = box->GetColor();
            Vec3_021f8240 position = box->GetPosition();
            unsigned short x = position.x / 4096.0f;
            unsigned short y = position.y / 4096.0f;
            unsigned short right = func_ov023_021fc4fc(box) + x;
            unsigned short bottom = _Z19GetField2c_021fc504P9S021fc504((S021fc504*)box) + y;
            func_0204f914(&self->canvas_, color, x, y, right, bottom);
        }
    }
}
