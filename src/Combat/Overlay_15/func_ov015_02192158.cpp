#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct S_0218ffa8;
struct S_0218ffd0;
struct S_0218fff8;
struct Obj02190020;
struct SetStruct_0218ff7c;
struct SetStruct_0219005c;
struct Container020dedd0;
struct Fields020deda4;
struct Obj021900dc;

struct ViewerEntry
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char link_;
};

struct PartEntry
{
    char unk_0[0x18];
    short unk_18;
};

struct ViewObject
{
    char unk_0[0x20];
    int* parts_;
    char unk_24[0x38 - 0x24];
    short motion_;
    unsigned char playing_;
    unsigned char female_;
};

struct ViewObjectNode
{
    ViewObject* object_;
    ViewObjectNode* next_;
};

struct S02190c2c
{
    char unk_0[0x2c];
    ViewObjectNode* objects_;
    ViewObject* current_;
    char unk_34[0x4c - 0x34];
    char parts_[0x194 - 0x4c];
    int menu_;
    char unk_198[0x1a4 - 0x198];
    int page_;
};

extern "C" ViewerEntry* func_ov015_02193160(S02190c2c* self, int page, int* index);
void SetByteFieldIfChanged_0218ffa8(S_0218ffa8* object, int female);
extern "C" void func_ov015_0218f308(ViewObject* object, const char* event);
extern "C" void func_ov015_02192700(S02190c2c* self, int unk);
void UpdateField4c021900dc(Obj021900dc* object);
void SetByteFieldIfChanged_0218ffd0(S_0218ffd0* object, int color);
void SetByteFieldIfChanged_0218fff8(S_0218fff8* object, int color);
void SetField3c02190020(Obj02190020* object, unsigned char color);
void SetIfChanged0218ff7c(SetStruct_0218ff7c* object, int part, int id);
PartEntry* FindElementByKey020dedd0(Container020dedd0* names, int id);
PartEntry* Forward10BitFields020deda4(int names, int category, Fields020deda4* entry);
void SetPairIfChanged0219005c(SetStruct_0219005c* object, short width, short height);

// USA: func_ov015_02192158
extern "C" ARM void func_ov015_02192158(S02190c2c* self, int index)
{
    if (self->current_ == NULL)
        return;
    int position = index;
    int setPart;
    int part;
    ViewerEntry* entry = func_ov015_02193160(self, self->page_, &position);
    setPart = 0;
    part = 0;
    switch (self->page_)
    {
    case 15:
        SetByteFieldIfChanged_0218ffa8((S_0218ffa8*)self->current_, (unsigned char)entry->id_);
        break;
    case 17:
        part = 2;
        setPart = 1;
        break;
    case 18:
        setPart = 1;
        break;
    case 19:
        setPart = 1;
        break;
    case 21:
        setPart = 1;
        break;
    case 25:
        part = 1;
        setPart = 1;
        break;
    case 27:
        part = 8;
        setPart = 1;
        break;
    case 28:
        part = 9;
        setPart = 1;
        break;
    case 22:
        part = 7;
        setPart = 1;
        break;
    case 20:
        part = 3;
        setPart = 1;
        break;
    case 24:
        part = 5;
        setPart = 1;
        break;
    case 26:
        part = 6;
        setPart = 1;
        break;
    case 23:
        setPart = 1;
        break;
    case 16:
        setPart = 1;
        break;
    case 30:
    case 31:
    case 32:
        func_ov015_0218f308(self->current_, entry->file_);
        self->menu_ = 1;
        func_ov015_02192700(self, 0);
        self->current_->motion_ = 0;
        UpdateField4c021900dc((Obj021900dc*)self->current_);
        break;
    }
    if (!setPart)
        return;
    for (ViewObjectNode* node = self->objects_; node != NULL; node = node->next_)
    {
        if (self->page_ == 18)
        {
            SetByteFieldIfChanged_0218ffd0((S_0218ffd0*)node->object_, (unsigned char)entry->id_);
        }
        else if (self->page_ == 19)
        {
            SetByteFieldIfChanged_0218fff8((S_0218fff8*)node->object_, (unsigned char)entry->id_);
        }
        else if (self->page_ == 21)
        {
            SetField3c02190020((Obj02190020*)node->object_, entry->id_);
        }
        else if (self->page_ == 20)
        {
            SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
            SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, 4, entry->id_);
        }
        else if (self->page_ == 23)
        {
            SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
            PartEntry* skin = Forward10BitFields020deda4((int)&self->parts_, 0x61,
                (Fields020deda4*)FindElementByKey020dedd0((Container020dedd0*)&self->parts_, (short)node->object_->parts_[0]));
            if (skin != NULL)
                SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, 5, skin->unk_18);
            else
                SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, 5, 0x36b0);
        }
        else if (self->page_ == 16)
        {
            if (self->current_->female_ == 0)
            {
                switch (entry->id_)
                {
                case 0:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xeb8, 0x109f);
                    break;
                case 1:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xe35, 0x1028);
                    break;
                case 2:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xf0a, 0xfae);
                    break;
                case 3:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0x1024, 0xf33);
                    break;
                case 4:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xf1e, 0xeb4);
                    break;
                }
            }
            else
            {
                switch (entry->id_)
                {
                case 0:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xeb8, 0x1051);
                    break;
                case 1:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xe39, 0xffb);
                    break;
                case 2:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xee1, 0xf85);
                    break;
                case 3:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0x1024, 0xf33);
                    break;
                case 4:
                    SetPairIfChanged0219005c((SetStruct_0219005c*)node->object_, 0xeb8, 0xeb4);
                    break;
                }
            }
        }
        else
        {
            SetIfChanged0218ff7c((SetStruct_0218ff7c*)node->object_, (unsigned char)part, entry->id_);
        }
    }
}
