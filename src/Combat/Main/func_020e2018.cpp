#include <globaldefs.h>
struct ZeroStruct { int pointer, value; unsigned char x, y, width, height; };
struct Struct02020520 { int pointer; short x, y, width, height; };
struct S_b20c { int pointer, layout; unsigned char mode; };
struct Image020e2018 { int pointer; char unknown4[6]; unsigned char width, height; };
struct Panel020e2018 {
    char unknown0[8];
    Image020e2018* image;
    char unknownC[0x24-0xc];
    ZeroStruct clipping;
    int offset, stride;
    char unknown38[2];
    unsigned char width, height;
};
struct Owner020e2018 { int buffer; Panel020e2018* panel; };
void ClearZeroStruct_020e1568(ZeroStruct*);
void ClearStruct02020520(Struct02020520*);
void ClearTwoWordsAndByte_0205b20c(S_b20c*);
void SetField0_0205b220(void*, int);
void SetFieldsAt0x4And0x8_0205b228(void*, int, unsigned char);
extern "C" void func_0205b734(S_b20c*, int, int, int, int, int);
// USA: func_020e2018
extern "C" ARM void func_020e2018(Owner020e2018* owner) {
    Panel020e2018* panel = owner->panel;
    Image020e2018* image = panel->image;
    ClearZeroStruct_020e1568(&panel->clipping);
    panel->clipping.pointer = image->pointer;
    panel->clipping.value = 0;
    panel->clipping.x = 0;
    panel->clipping.y = 0;
    panel->clipping.width = image->width - 4;
    panel->clipping.height = image->height - 4;
    int width = owner->panel->width - 4;
    if (width <= panel->clipping.width) panel->clipping.width = width;
    int height = owner->panel->height - 4;
    if (height <= panel->clipping.height) panel->clipping.height = height;
    Struct02020520 layout;
    ClearStruct02020520(&layout);
    layout.width = image->width;
    layout.height = image->height;
    S_b20c destination;
    ClearTwoWordsAndByte_0205b20c(&destination);
    SetField0_0205b220(&destination, owner->buffer + (owner->panel->offset + owner->panel->stride));
    SetFieldsAt0x4And0x8_0205b228(&destination, (int)&layout, 1);
    func_0205b734(&destination, 0, 0, panel->clipping.width, panel->clipping.height, 1);
}
