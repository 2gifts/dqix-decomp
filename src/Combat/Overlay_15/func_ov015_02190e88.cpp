#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct AllocatorUnion;
struct Struct021931b4;
struct Owner_021931cc;
struct Obj021900dc;

struct ViewerEntry
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char link_;
};

struct ViewObject
{
    char unk_0[0x1c];
    unsigned char kind_;
    char unk_1d[0x38 - 0x1d];
    short motion_;
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
    char unk_198[0x1a1 - 0x198];
    unsigned char field_;
    char unk_1a2[2];
    int page_;
    char unk_1a8[0x268 - 0x1a8];
    short cursors_[0x29];
    char unk_2ba[0x2c4 - 0x2ba];
    DebugMenu menuList_;
    char unk_344[0x350 - 0x344];
    unsigned char redraw_;
};

extern "C" int func_ov015_021925a8(S02190c2c* self);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
int TestFlagMask(unsigned short* pad, int buttons);
extern "C" int func_0201248c(unsigned short* pad, int buttons);
extern "C" int func_ov015_02191284(DebugMenu* menu);
extern "C" void func_ov015_02191af0(S02190c2c* self, int index);
extern "C" void func_ov015_02191ba0(S02190c2c* self, int index);
extern "C" void func_ov015_02191c70(S02190c2c* self, int index);
extern "C" ViewerEntry* func_ov015_02193160(S02190c2c* self, int page, int* index);
extern "C" void _Z22PushArrayValue021931b4P14Struct021931b4i(Struct021931b4* self, int page);
extern "C" int _Z11Pop021931ccP14Owner_021931cc(Owner_021931cc* self);
extern "C" void func_ov015_02192700(S02190c2c* self, int unk);
extern "C" int _Z28IsFieldValueInRange_02190c2cP9S02190c2c(S02190c2c* self);
extern "C" void func_ov015_02192158(S02190c2c* self, int index);
extern "C" void func_ov015_0218f308(ViewObject* object, const char* event);
extern "C" void _Z21UpdateField4c021900dcP11Obj021900dc(Obj021900dc* object);
extern "C" void func_ov015_0218f0c4(ViewObject* object);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" ViewObject* func_ov015_021919e4(S02190c2c* self, ViewerEntry* entry);
extern "C" void func_ov015_02192544(S02190c2c* self);
extern "C" void func_ov015_02190090(ViewObject* object);

extern unsigned short data_02114e30;
extern AllocatorUnion data_02114e20;

// USA: func_ov015_02190e88
extern "C" ARM void func_ov015_02190e88(S02190c2c* self)
{
    if (func_ov015_021925a8(self))
        return;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1))
    {
        int index = func_ov015_02191284(&self->menuList_);
        self->cursors_[self->page_] = index;
        switch (self->page_)
        {
        case 2:
            func_ov015_02191af0(self, index);
            return;
        case 3:
            func_ov015_02191ba0(self, index);
            return;
        case 40:
            func_ov015_02191c70(self, index);
            return;
        default:
        {
            int start = 0;
            func_ov015_02193160(self, self->page_, &start);
            index += start;
            ViewerEntry* entry = func_ov015_02193160(self, self->page_, &index);
            if (entry == NULL)
                break;
            if (entry->link_ != 0)
            {
                _Z22PushArrayValue021931b4P14Struct021931b4i((Struct021931b4*)self, self->page_);
                self->page_ = entry->link_;
                func_ov015_02192700(self, 0);
                return;
            }
            if (_Z28IsFieldValueInRange_02190c2cP9S02190c2c(self))
            {
                func_ov015_02192158(self, index);
                return;
            }
            if (self->page_ == 0x21)
            {
                func_ov015_0218f308(self->current_, entry->file_);
                self->menu_ = 1;
                func_ov015_02192700(self, 0);
                self->current_->motion_ = 0;
                _Z21UpdateField4c021900dcP11Obj021900dc((Obj021900dc*)self->current_);
                return;
            }
            if (TestFlagMask(&data_02114e30, 0x100))
            {
                ViewObjectNode* node = self->objects_;
                while (node != NULL)
                {
                    func_ov015_0218f0c4(node->object_);
                    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->object_);
                    ViewObjectNode* next = node;
                    node = node->next_;
                    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, next);
                }
                self->objects_ = NULL;
            }
            ViewObject* object = func_ov015_021919e4(self, entry);
            if (object != NULL && !TestFlagMask(&data_02114e30, 0x200))
            {
                self->current_ = object;
                switch (object->kind_)
                {
                case 0:
                case 1:
                    _Z22PushArrayValue021931b4P14Struct021931b4i((Struct021931b4*)self, self->page_);
                    self->page_ = 0x22;
                    func_ov015_02192700(self, 0);
                    return;
                case 2:
                    _Z22PushArrayValue021931b4P14Struct021931b4i((Struct021931b4*)self, self->page_);
                    self->page_ = 0x21;
                    func_ov015_02192700(self, 0);
                    return;
                default:
                    self->menu_ = 1;
                    func_ov015_02192700(self, 0);
                    self->current_->motion_ = 0;
                    _Z21UpdateField4c021900dcP11Obj021900dc((Obj021900dc*)self->current_);
                    return;
                }
            }
            break;
        }
        }
    }
    else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2))
    {
        if (self->page_ > 0)
        {
            self->cursors_[self->page_] = func_ov015_02191284(&self->menuList_);
            if (self->page_ == 8)
                func_ov015_02192544(self);
            int page = _Z11Pop021931ccP14Owner_021931cc((Owner_021931cc*)self);
            if (page >= 0)
            {
                self->page_ = page;
                func_ov015_02192700(self, 0);
            }
        }
    }
    else
    {
        if (func_0201248c(&data_02114e30, 0x20))
        {
            short first = self->menuList_.first_;
            int cursor = self->menuList_.cursor_ - 8;
            if (cursor < first)
                cursor = first;
            self->menuList_.cursor_ = cursor;
            self->redraw_ = 1;
            return;
        }
        if (func_0201248c(&data_02114e30, 0x10))
        {
            short last = self->menuList_.last_;
            int cursor = self->menuList_.cursor_ + 8;
            if (cursor > last)
                cursor = last;
            self->menuList_.cursor_ = cursor;
            self->redraw_ = 1;
            return;
        }
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200))
        {
            if (self->page_ == 6)
            {
                self->field_ = self->field_ == 0;
                self->redraw_ = 1;
            }
        }
        else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x100) && (self->page_ == 0x22 || _Z28IsFieldValueInRange_02190c2cP9S02190c2c(self)))
        {
            func_ov015_02190090(self->current_);
            self->redraw_ = 1;
        }
    }
}
