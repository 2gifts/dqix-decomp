#include <globaldefs.h>

struct TextObject0222df84;
struct TextRow0222df84 { TextObject0222df84* object; int field4; unsigned char text[12]; };
struct TextCoordinates0222df84 { unsigned char padding_0x0[0xe]; unsigned short x, y; };
extern TextRow0222df84* data_ov031_02290c98;
extern TextCoordinates0222df84 data_ov031_02248ee0;
extern const unsigned char data_ov031_02248f20[12];
extern "C" void CallVTableField14_0223ca40(void*, int);
extern "C" void func_ov031_0223c980(TextObject0222df84*, int, int, int, int, int, int, const char*);
extern "C" void _Z30SetFlagIfMatchesElem0_0223caecPv(void*);

// USA: func_ov031_0222df84
extern "C" ARM void func_ov031_0222df84() {
    unsigned short rectangle[4] __attribute__((aligned(4)));
    rectangle[0] = data_ov031_02248ee0.x;
    rectangle[1] = data_ov031_02248ee0.y;
    rectangle[2] = 11;
    rectangle[3] = 16;
    CallVTableField14_0223ca40(data_ov031_02290c98->object, 0);
    unsigned short text[2];
    text[1] = 0;
    const unsigned char* columns = data_ov031_02248f20;
    int i = 0;
    do {
        TextRow0222df84* row = data_ov031_02290c98;
        text[0] = row->text[i];
        unsigned short x = *columns++;
        rectangle[0] = x;
        func_ov031_0223c980(row->object, x, rectangle[1], rectangle[2], rectangle[3], 2, 0x480, reinterpret_cast<const char*>(text));
    } while (++i < 12);
    _Z30SetFlagIfMatchesElem0_0223caecPv(data_ov031_02290c98->object);
}
