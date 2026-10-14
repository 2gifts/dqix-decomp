#include <globaldefs.h>

struct Container020e0310;
struct Struct0205de24;
struct Obj0204b5e8;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" int func_020420e8(char* str, int id);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
char* GetGlobalField0x1c020421a0(void);
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);
extern "C" void memset(void* dst, int val, int size);
void AppendEntryNames_0215e13c(char* base, char* dst, int flag);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct BattleMenu_0215df1c {
    char unk_0[0x64];
    char messages[0x7c - 0x64];
    char* text;
    char unk_80[0x98 - 0x80];
    char window[0x138 - 0x98];
    short width;
    short height;
    short x;
    short y;
    short field140;
    short field142;
    short field144;
    short field146;
    char unk_148;
    unsigned char field149;
    char unk_14a[3];
    unsigned char field14d;
    char unk_14e;
    unsigned char field14f;
    char unk_150[4];
    char scrollers[2][0x20];
    char unk_194[0x3bd - 0x194];
    unsigned char keys[3];
    unsigned char count;
    signed char cursor;
    char unk_3c2[0x3d0 - 0x3c2];
    int field3d0;
    char unk_3d4[0x3f2 - 0x3d4];
    unsigned char lowerScreen;
};

// USA: func_ov003_0215df1c
extern "C" ARM void func_ov003_0215df1c(struct BattleMenu_0215df1c* self) {
    void* ctx = func_0202ae18();
    self->count = 3;
    self->keys[0] = 0;
    self->keys[1] = 1;
    self->keys[2] = 2;
    if (func_0202c540(ctx)) {
        self->count = 2;
        self->keys[0] = 1;
        self->keys[1] = 2;
        self->keys[2] = 0xff;
    } else if (self->field3d0 == 0) {
        self->count = 2;
        self->keys[0] = 0;
        self->keys[1] = 2;
        self->keys[2] = 0xff;
    }

    short height = (self->count * 14 + 0x12) / 8;
    int maxWidth = 0;
    for (int i = 0; i < self->count; i++) {
        short w = func_020420e8((char*)GetFieldByKey020e0434((struct Container020e0310*)self->messages, self->keys[i]), 0);
        if (maxWidth < w) {
            maxWidth = w;
        }
    }
    short width = (maxWidth + 0x18) >> 3;

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)self->window, 0, 2);
    self->width = width;
    self->height = height;
    self->x = 0x1f - width;
    self->y = 2;
    self->field140 = 0xc;
    self->field142 = 8;
    self->field144 = 0xa;
    self->field146 = 0xe;
    self->field14f = 0xa;
    self->field149 = 1;
    self->field14d = 1;

    if (self->lowerScreen) {
        short pos = *(short*)(GetGlobalField0x1c020421a0() + 0x916);
        short row = pos / 8;
        short offset = pos % 8;
        self->x = 0x20 - width;
        self->y = row - height;
        for (int i = 0; i < 2; i++) {
            DispatchViaTable0204b5e8((struct Obj0204b5e8*)self->scrollers[i], 2, -offset);
        }
    }

    self->cursor = 0;
    memset(self->text, 0, 0x960);
    AppendEntryNames_0215e13c((char*)self, self->text, 0);
    func_0205d304(self->window, self->text, 0, 1, 0, 1, 0, 0);
}
