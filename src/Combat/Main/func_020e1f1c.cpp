#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct ClipRec020e1f1c {
    int f0;
    int value;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
};

struct Panel020e1f1c {
    Struct02020520* layouts;
    void* obj;
    ClipRec020e1f1c* clips;
    char pad[0x30 - 0xc];
    int offset;
    int stride;
    char pad2[0x3c - 0x38];
    unsigned char count;
};

struct Owner020e1f1c {
    void* buffer;
    Panel020e1f1c* panel;
};

extern "C" void* _Z25AllocateVRAMStagingMemoryj(unsigned int value);
extern "C" int _Z20GetHalfProductField8P15HasDims020e1288(void* obj);
extern "C" void func_020e2018(void* owner);
extern "C" void _Z19ClearStruct02020520P14Struct02020520(Struct02020520* s);
extern "C" void _Z20ClearTwoWordsAndByteP6S_b20c(void* obj);
extern "C" void _Z18SetField0_0205b220Pvi(void* obj, int value);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void* obj, int value, unsigned char flag);

// USA: func_020e1f1c
extern "C" ARM void* func_020e1f1c(Owner020e1f1c* owner) {
    void* buffer = _Z25AllocateVRAMStagingMemoryj(0x4000);
    owner->buffer = buffer;
    if (buffer != 0) {
        Panel020e1f1c* panel = owner->panel;
        int half = _Z20GetHalfProductField8P15HasDims020e1288(panel);
        memset((char*)owner->buffer + panel->offset, 0, panel->stride + half);
        func_020e2018(owner);
        int count = owner->panel->count;
        for (int i = 0; i < count; i++) {
            Struct02020520* d = &owner->panel->layouts[i];
            ClipRec020e1f1c* s = &owner->panel->clips[i];
            _Z19ClearStruct02020520P14Struct02020520(d);
            d->a = s->value;
            d->b = s->x;
            d->c = s->y;
            d->d = s->w;
            d->e = s->h;
        }
        void* obj = owner->panel->obj;
        _Z20ClearTwoWordsAndByteP6S_b20c(obj);
        _Z18SetField0_0205b220Pvi(obj, (int)((unsigned int)owner->buffer + owner->panel->offset));
        _Z29SetFieldsAt0x4And0x8_0205b228Pvih(obj, (int)owner->panel->layouts, count);
    }
    return owner->buffer;
}
