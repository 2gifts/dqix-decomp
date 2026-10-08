#include <globaldefs.h>
#include <std_library_functions.h>

struct Container020dedd0;
struct StructDE234_020de234;

struct PartEntry
{
    void* model_;
    int unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unk_10_0 : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
    int unk_14;
    short unk_18;
    unsigned short price_;
};

struct Viewer0218c03c
{
    char unk_0[0x4c];
    char parts_[0x18];
};

struct ViewObject
{
    Viewer0218c03c* viewer_;
    char unk_4[0x1c];
    int* parts_;
    char unk_24[0x3b - 0x24];
    unsigned char female_;
    unsigned char hairColor_;
};

struct ModelExtension
{
    char text_[8];
};

struct FaceLetters
{
    char letters_[10];
};

extern "C" PartEntry* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" unsigned short _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(StructDE234_020de234* p, int preferMid);

extern const ModelExtension data_ov015_02193cd4;
extern const FaceLetters data_ov015_02193ce5;
extern const char data_ov015_02193fe4[];
extern const char data_ov015_02193fea[];
extern const char data_ov015_02193ffa[];

// USA: func_ov015_0218c03c
extern "C" ARM bool func_ov015_0218c03c(ViewObject* self, char* name, unsigned int part, int file)
{
    PartEntry* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i((Container020dedd0*)&self->viewer_->parts_, (short)self->parts_[part]);
    PartEntry* body = _Z24FindElementByKey020dedd0P17Container020dedd0i((Container020dedd0*)&self->viewer_->parts_, (short)self->parts_[7]);
    int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)entry, self->female_);
    ModelExtension extension = data_ov015_02193cd4;
    char suffix[2] = {0};
    char suffix2[2] = {0};
    switch (part)
    {
    case 0:
    case 1:
    case 2:
    default:
        break;
    case 4:
        strcpy(extension.text_, data_ov015_02193fe4);
        suffix[0] = 'a';
        suffix[1] = 0;
        number += self->hairColor_;
        break;
    case 3:
        suffix[0] = 'a';
        suffix[1] = 0;
        if (body != NULL && body->unk_18 > -1)
        {
            int index = (int)_Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)body, self->female_) / 100;
            if ((unsigned int)index >= 10)
                return false;
            FaceLetters letters = data_ov015_02193ce5;
            char letter = letters.letters_[index];
            if (letter == 0)
                return false;
            suffix[0] = letter;
            if (index == 3 && self->female_ == 0 && entry->unk_18 == 0x2329)
                suffix[0] = 'f';
        }
        break;
    case 5:
    case 6:
        if (file)
            strcpy(extension.text_, data_ov015_02193fe4);
        break;
    }
    if (file == 0)
        sprintf(name, data_ov015_02193fea, (char)entry->letter_, number, suffix, suffix2, extension.text_);
    else
        sprintf(name, data_ov015_02193ffa, (char)entry->letter_, number, suffix, suffix2, extension.text_);
    return true;
}
