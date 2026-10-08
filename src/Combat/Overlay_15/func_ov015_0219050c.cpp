#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void __clear(void* buffer, unsigned long size);

struct MessageSystem0219050c
{
    char unk_0[0x19b0];
    unsigned char unk_19b0;
};

struct AnimationRecord0219050c
{
    char name[0x18];
    int frameRate;
};

struct IndexList_0202a9ac;
struct Obj0218f3c4;
struct Obj0218f408;

struct ViewObject
{
    char unk_0[0x34];
    unsigned short triangles_;
    unsigned short quads_;
    short motion_;
};

struct CharacterViewer
{
    char unk_0[0x30];
    ViewObject* current_;
    char unk_34[0x194 - 0x34];
    int menu_;
    char unk_198[0x1a0 - 0x198];
    unsigned char viewMemory_;
    char unk_1a1[0x24c - 0x1a1];
    float fps_;
    char unk_250[0x2c4 - 0x250];
    char menuList_[0x80];
};

extern "C" MessageSystem0219050c* _Z26GetGlobalField0x1c020421a0v();
extern "C" double func_0200c578(float v);
extern "C" void func_02069fec(MessageSystem0219050c* system, const char* text, char* converted);
extern "C" void func_02045d14(MessageSystem0219050c* system, const char* converted, unsigned short* line, int unk);
extern "C" void func_02045f3c(MessageSystem0219050c* system, unsigned short* line, int x, int y, int color, int a, int b, int c, int d, int e);
void* GetNodeAtIndex(IndexList_0202a9ac* list, int index);
void* GetSubstructAt0x4(void* item);
extern "C" AnimationRecord0219050c* func_ov015_0218f39c(ViewObject* self, void* name);
extern "C" float _Z16GetRatio0218f3c4P11Obj0218f3c4(Obj0218f3c4* obj);
extern "C" float _Z16GetRatio0218f408P11Obj0218f408(Obj0218f408* obj);
extern "C" void func_ov015_0218f794(ViewObject* self);

extern const char data_ov015_02194256[];
extern const char data_ov015_02194261[];
extern const char data_ov015_0219426a[];
extern const char data_ov015_02194273[];
extern const char data_ov015_0219427b[];
extern const char data_ov015_02194288[];
extern const char data_ov015_02194295[];

#define PREPARE_TEXT()                                                    \
    {                                                                     \
        memset(line, 0, sizeof(line));                                    \
        MessageSystem0219050c* system = _Z26GetGlobalField0x1c020421a0v();     \
        char converted[0x40];                                             \
        __clear(converted, sizeof(converted));                            \
        func_02069fec(system, text, converted);                           \
        func_02045d14(system, converted, line, 0);                        \
    }

#define DRAW_LINE(x, y, color)                                                     \
    {                                                                              \
        messages->unk_19b0 = 1;                                                    \
        func_02045f3c(messages, &line[1], x, y, color, 8, 0x14, 0, 1, 0x11);       \
    }

// USA: func_ov015_0219050c
extern "C" ARM void func_ov015_0219050c(CharacterViewer* self)
{
    char text[0x20];
    unsigned short line[0x20];

    MessageSystem0219050c* messages = _Z26GetGlobalField0x1c020421a0v();
    sprintf(text, data_ov015_02194256, func_0200c578(self->fps_));
    PREPARE_TEXT();
    DRAW_LINE(0, 0xa0, 0x7fff);
    unsigned short triangles = 0;
    if (self->current_ != NULL)
        triangles = self->current_->triangles_;
    sprintf(text, data_ov015_02194261, triangles);
    PREPARE_TEXT();
    DRAW_LINE(0, 0xaa, 0x7fff);
    unsigned short quads = 0;
    if (self->current_ != NULL)
        quads = self->current_->quads_;
    sprintf(text, data_ov015_0219426a, quads);
    PREPARE_TEXT();
    messages->unk_19b0 = 1;
    if (quads != 0)
        func_02045f3c(messages, &line[1], 0, 0xb4, 0x1f, 8, 0x14, 0, 1, 0x11);
    else
        func_02045f3c(messages, &line[1], 0, 0xb4, 0x7fff, 8, 0x14, 0, 1, 0x11);
    if (self->menu_ == 1)
    {
        void* item = GetNodeAtIndex((IndexList_0202a9ac*)&self->menuList_, self->current_->motion_);
        if (item == NULL)
            return;
        AnimationRecord0219050c* record = func_ov015_0218f39c(self->current_, GetSubstructAt0x4(item));
        if (record == NULL)
            return;
        sprintf(text, data_ov015_02194273, record->name);
        PREPARE_TEXT();
        DRAW_LINE(0x96, 0x96, 0x7fff);
        sprintf(text, data_ov015_0219427b, func_0200c578(record->frameRate / 4096.0f));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xa0, 0x7fff);
        sprintf(text, data_ov015_02194288, func_0200c578(_Z16GetRatio0218f3c4P11Obj0218f3c4((Obj0218f3c4*)self->current_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xaa, 0x7fff);
        sprintf(text, data_ov015_02194295, func_0200c578(_Z16GetRatio0218f408P11Obj0218f408((Obj0218f408*)self->current_)));
        PREPARE_TEXT();
        DRAW_LINE(0xa0, 0xb4, 0x7fff);
    }
    if (self->viewMemory_ && self->current_ != NULL)
        func_ov015_0218f794(self->current_);
}
