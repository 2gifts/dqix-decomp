#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj0219011c;
struct Obj021900dc;
struct S0219015c;
struct IndexList_0202a9ac;

struct ViewObject
{
    char unk_0[0x38];
    short motion_;
    unsigned char playing_;
    char unk_3b[0x44 - 0x3b];
    int loop_;
    int battle_;
    int step_;
};

struct ViewObjectNode
{
    ViewObject* object_;
    ViewObjectNode* next_;
};

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
    char unk_0[0x2c];
    ViewObjectNode* objects_;
    ViewObject* current_;
    char unk_34[0x194 - 0x34];
    int menu_;
    char unk_198[0x19f - 0x198];
    unsigned char syncMotion_;
    char unk_1a0[0x2bc - 0x1a0];
    int repeatDelay_;
    int repeatTimer_;
    DebugMenu menuList_;
    char unk_344[0x350 - 0x344];
    unsigned char redraw_;
};

extern "C" int func_ov015_021925a8(S02190c2c* self);
int TestFlagInSecondWord(unsigned short* pad, unsigned int buttons);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
int TestFlagMask(unsigned short* pad, int buttons);
extern "C" int func_0201248c(unsigned short* pad, int buttons);
extern "C" void _Z19SetField18_0219011cP11Obj0219011ci(Obj0219011c* object, int step);
extern "C" int func_ov015_02191284(DebugMenu* menu);
void* GetNodeAtIndex(IndexList_0202a9ac* menu, int index);
const char* GetSubstructAt0x4(void* item);
extern "C" void func_ov015_0218f364(ViewObject* object, const char* name);
extern "C" void _Z21UpdateField4c021900dcP11Obj021900dc(Obj021900dc* object);
extern "C" void func_ov015_02192700(S02190c2c* self, int unk);
extern "C" void _Z38AdjustSubstructField_0219015c_0219015cP9S0219015ci(S0219015c* object, int step);

extern unsigned short data_02114e30;

// USA: func_ov015_02191294
extern "C" ARM void func_ov015_02191294(S02190c2c* self)
{
    if (func_ov015_021925a8(self))
        return;
    if (TestFlagInSecondWord(&data_02114e30, 0x20) || TestFlagInSecondWord(&data_02114e30, 0x10) ||
        TestFlagInSecondWord(&data_02114e30, 0x100))
    {
        self->repeatDelay_ = 0x1e;
        self->repeatTimer_ = 0;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1))
    {
        if (TestFlagMask(&data_02114e30, 0x100))
        {
            ViewObject* current = self->current_;
            current->playing_ = current->playing_ == 0;
            self->redraw_ = 1;
            return;
        }
        if (TestFlagMask(&data_02114e30, 0x200))
        {
            ViewObject* current = self->current_;
            int loop = current->loop_;
            if (self->syncMotion_)
            {
                for (ViewObjectNode* node = self->objects_; node != NULL; node = node->next_)
                {
                    if (loop == 0)
                        node->object_->loop_ = 1;
                    else
                        node->object_->loop_ = 0;
                }
            }
            else if (loop == 0)
            {
                current->loop_ = 1;
            }
            else
            {
                current->loop_ = 0;
            }
        }
        _Z19SetField18_0219011cP11Obj0219011ci((Obj0219011c*)self->current_, self->current_->step_);
        self->current_->motion_ = func_ov015_02191284(&self->menuList_);
        void* item = GetNodeAtIndex((IndexList_0202a9ac*)&self->menuList_, func_ov015_02191284(&self->menuList_));
        if (item != NULL)
        {
            if (self->syncMotion_)
            {
                for (ViewObjectNode* node = self->objects_; node != NULL; node = node->next_)
                    func_ov015_0218f364(node->object_, GetSubstructAt0x4(item));
            }
            else
            {
                func_ov015_0218f364(self->current_, GetSubstructAt0x4(item));
            }
        }
        _Z21UpdateField4c021900dcP11Obj021900dc((Obj021900dc*)self->current_);
        self->redraw_ = 1;
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2))
    {
        _Z19SetField18_0219011cP11Obj0219011ci((Obj0219011c*)self->current_, self->current_->step_);
        self->current_->playing_ = 0;
        self->current_->motion_ = -1;
        self->current_->loop_ = 0;
        self->current_->step_ = 0;
        self->menu_ = 0;
        func_ov015_02192700(self, 0);
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x100))
    {
        if (self->current_->playing_)
            self->redraw_ = 1;
        return;
    }
    if (func_0201248c(&data_02114e30, 0x20))
    {
        if (TestFlagMask(&data_02114e30, 0x100))
        {
            _Z38AdjustSubstructField_0219015c_0219015cP9S0219015ci((S0219015c*)self->current_, -0x28);
        }
        else
        {
            short first = self->menuList_.first_;
            int cursor = self->menuList_.cursor_ - 8;
            if (cursor < first)
                cursor = first;
            self->menuList_.cursor_ = cursor;
        }
        self->redraw_ = 1;
        return;
    }
    if (func_0201248c(&data_02114e30, 0x10))
    {
        if (TestFlagMask(&data_02114e30, 0x100))
        {
            _Z38AdjustSubstructField_0219015c_0219015cP9S0219015ci((S0219015c*)self->current_, 0x28);
        }
        else
        {
            short last = self->menuList_.last_;
            int cursor = self->menuList_.cursor_ + 8;
            if (cursor > last)
                cursor = last;
            self->menuList_.cursor_ = cursor;
        }
        self->redraw_ = 1;
        return;
    }
    if (TestFlagMask(&data_02114e30, 0x20))
    {
        if (!TestFlagMask(&data_02114e30, 0x100))
            return;
        if (self->repeatTimer_ < self->repeatDelay_)
        {
            self->repeatTimer_++;
            return;
        }
        self->repeatTimer_ = 0;
        self->repeatDelay_ -= 10;
        _Z38AdjustSubstructField_0219015c_0219015cP9S0219015ci((S0219015c*)self->current_, -0x28);
        self->redraw_ = 1;
        return;
    }
    if (!TestFlagMask(&data_02114e30, 0x10))
        return;
    if (!TestFlagMask(&data_02114e30, 0x100))
        return;
    if (self->repeatTimer_ < self->repeatDelay_)
    {
        self->repeatTimer_++;
        return;
    }
    self->repeatTimer_ = 0;
    self->repeatDelay_ -= 10;
    _Z38AdjustSubstructField_0219015c_0219015cP9S0219015ci((S0219015c*)self->current_, 0x28);
    self->redraw_ = 1;
}
