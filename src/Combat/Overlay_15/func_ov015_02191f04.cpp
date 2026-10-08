#include <globaldefs.h>

struct IndexList_0202a9ac;

struct DebugMenu
{
    char unk_0[0x5c];
    short first_;
    short last_;
    short cursor_;
    char unk_62[0x80 - 0x62];
};

struct S02190c2c
{
    char unk_0[0x19c];
    unsigned char aspect_;
    unsigned char floor_;
    unsigned char monsterBox_;
    unsigned char syncMotion_;
    unsigned char viewMemory_;
    char unk_1a1[0x2c4 - 0x1a1];
    DebugMenu menuList_;
    char unk_344[0x350 - 0x344];
    unsigned char redraw_;
};

extern "C" int func_ov015_02191284(DebugMenu* menu);
void* GetNodeAtIndex(IndexList_0202a9ac* menu, int index);
extern "C" void func_020294cc(void* item, const char* text);

extern char data_ov015_0219432e[];
extern char data_ov015_02194338[];
extern char data_ov015_02194342[];
extern char data_ov015_0219434b[];
extern char data_ov015_0219435a[];
extern char data_ov015_02194369[];
extern char data_ov015_02194378[];
extern char data_ov015_02194387[];
extern char data_ov015_02194396[];

// USA: func_ov015_02191f04
extern "C" ARM void func_ov015_02191f04(S02190c2c* self)
{
    int index = func_ov015_02191284(&self->menuList_);
    void* item = GetNodeAtIndex((IndexList_0202a9ac*)&self->menuList_, self->menuList_.cursor_);
    switch (index)
    {
    case 0:
    {
        self->aspect_ = !self->aspect_;
        if (self->aspect_)
            func_020294cc(item, data_ov015_0219432e);
        else
            func_020294cc(item, data_ov015_02194338);
        break;
    }
    case 1:
        self->floor_ = self->floor_ == 0;
        func_020294cc(item, data_ov015_02194342);
        break;
    case 2:
    {
        self->monsterBox_ = !self->monsterBox_;
        if (self->monsterBox_)
            func_020294cc(item, data_ov015_0219434b);
        else
            func_020294cc(item, data_ov015_0219435a);
        break;
    }
    case 3:
    {
        self->syncMotion_ = !self->syncMotion_;
        if (self->syncMotion_)
            func_020294cc(item, data_ov015_02194369);
        else
            func_020294cc(item, data_ov015_02194378);
        break;
    }
    case 4:
    {
        self->viewMemory_ = !self->viewMemory_;
        if (self->viewMemory_)
            func_020294cc(item, data_ov015_02194387);
        else
            func_020294cc(item, data_ov015_02194396);
        break;
    }
    }
    self->redraw_ = 1;
}
