#include <globaldefs.h>

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Node0205bacc;

extern "C" void _Z12Init0205bef8P15Struct_0205bef8(Struct_0205bef8* cursor);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* s, int val);
extern "C" void func_0205bb04(void* cursor, int index);

struct Cursor02186964 {
    int field0;
    int field4;
};

struct Menu02186964 {
    char pad0[0x744];
    unsigned char items[8];
    unsigned char itemCount;
    char pad1[0x750 - 0x74d];
    Cursor02186964 cursor;
    char pad2[0xb10 - 0x758];
    signed char state;
    char pad3[0xb18 - 0xb11];
    unsigned int flags;
    char pad4[0xb28 - 0xb1c];
    unsigned char selected;
    unsigned char scrollTop;
};

// USA: func_ov008_02186964
extern "C" ARM void func_ov008_02186964(Menu02186964* self) {
    int visible;
    int columns;
    int index;
    int count;
    columns = 1;
    count = columns;
    visible = columns;
    index = 0;
    if (self->state == 3) {
        columns = 1;
        count = self->itemCount;
        visible = count;
        for (int i = 0; i < count; i++) {
            if (self->selected == self->items[i]) {
                index = i;
                break;
            }
        }
        if (count > 6) {
            self->flags |= 0x10;
            if (index > self->scrollTop + 5) {
                self->scrollTop = index - 5;
            } else if (index < self->scrollTop) {
                self->scrollTop = index;
            }
        }
    }
    _Z12Init0205bef8P15Struct_0205bef8((Struct_0205bef8*)&self->cursor);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&self->cursor, columns, count, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&self->cursor, visible);
    self->cursor.field4 = columns;
    func_0205bb04(&self->cursor, index);
}
