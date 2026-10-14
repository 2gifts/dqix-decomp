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

void* AllocateVRAMStagingMemory(unsigned int value);
struct HasDims020e1288;
int GetHalfProductField8(HasDims020e1288*);
extern "C" void func_020e2018(void* owner);
void ClearStruct02020520(Struct02020520* s);
struct S_b20c;
void ClearTwoWordsAndByte_0205b20c(S_b20c*);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);

// USA: func_020e1f1c
extern "C" ARM void* func_020e1f1c(Owner020e1f1c* owner) {
    void* buffer = AllocateVRAMStagingMemory(0x4000);
    owner->buffer = buffer;
    if (buffer != 0) {
        Panel020e1f1c* panel = owner->panel;
        int half = GetHalfProductField8((HasDims020e1288*)panel);
        memset((char*)owner->buffer + panel->offset, 0, panel->stride + half);
        func_020e2018(owner);
        int count = owner->panel->count;
        for (int i = 0; i < count; i++) {
            Struct02020520* d = &owner->panel->layouts[i];
            ClipRec020e1f1c* s = &owner->panel->clips[i];
            ClearStruct02020520(d);
            d->a = s->value;
            d->b = s->x;
            d->c = s->y;
            d->d = s->w;
            d->e = s->h;
        }
        void* obj = owner->panel->obj;
        ClearTwoWordsAndByte_0205b20c((S_b20c*)obj);
        SetField0_0205b220(obj, (int)((unsigned int)owner->buffer + owner->panel->offset));
        SetFieldsAt0x4And0x8_0205b228(obj, (int)owner->panel->layouts, count);
    }
    return owner->buffer;
}
