#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Container020e0310;
struct MessageSystem;

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
extern "C" const char* func_020e046c(char* output, void* file, unsigned int size, short id);
extern "C" int func_020420e8(const char* text, int large);
extern "C" char* func_0205ec34();

struct TextWindow;
extern "C" void func_0205d304(TextWindow* window, char* text, int, int, int, int, int, int);

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
void AppendXYTag(char* text, int x, int y);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
int TestBitInByteArray(int, unsigned char*, int);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct TextWindow
{
    char unk_0[0xa0];
    short width_;
    short height_;
    short unk_a4;
    short unk_a6;
    short unk_a8;
    short unk_aa;
    short unk_ac;
    short unk_ae;
    unsigned char unk_b0;
    unsigned char unk_b1;
    unsigned char unk_b2;
    unsigned char unk_b3;
    unsigned char unk_b4;
    unsigned char unk_b5;
    unsigned char unk_b6;
    unsigned char unk_b7;
    unsigned char unk_b8;
    unsigned char unk_b9;
    unsigned char unk_ba;
    unsigned char unk_bb;
};

struct ClearRecords
{
    char unk_0[0x10];
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int title_ : 9;
};

struct Appearance
{
    unsigned char female_ : 1;
};

struct PartyData
{
    char unk_0[0x49c];
    Appearance appearance_;
};

struct Hero
{
    char unk_0[0x150];
    PartyData* partyData_;
};

struct BattleRecords
{
    char unk_0[0xa0];
    char texts_[0x18];
    char* text_;
    char unk_bc[0x130 - 0xbc];
    TextWindow window_;
};

extern "C" void func_ov008_02188408(BattleRecords* self, char* text, int kind, ClearRecords* records);

// USA: func_ov008_02187f6c
extern "C" ARM void func_ov008_02187f6c(BattleRecords* self, ClearRecords* records)
{
    if (records != NULL)
    {
        self->window_.width_ = 0x14;
        self->window_.height_ = 3;
        self->window_.unk_a4 = 6;
        self->window_.unk_a6 = 0x11;
        self->window_.unk_a8 = 0;
        self->window_.unk_aa = 6;
        self->window_.unk_ac = 0xc;
        self->window_.unk_ae = 0xe;
        self->window_.unk_b7 = 0xc;
        self->window_.unk_b1 = 4;
        self->window_.unk_b5 = 1;
        self->window_.unk_b6 = 1;
        memset(self->text_, 0, 0x960);
        char* text = self->text_;
        if (text != NULL)
        {
            _Z26GetGlobalField0x1c020421a0v();
            if (records != NULL)
            {
                Hero* hero = (Hero*)GameState::GetInstance()->GetProtagonist();
                char* name = self->text_ + 0x8e0;
                BackgroundLoader::AddLockGlobal();
                unsigned int size = 0;
                char inner[0x20];
                char gp2[0x40];
                __clear(gp2, sizeof(gp2));
                __clear(inner, sizeof(inner));
                sprintf(gp2, data_ov008_0218b465, hero->partyData_->appearance_.female_);
                sprintf(inner, data_ov008_0218b47c, hero->partyData_->appearance_.female_);
                void* file = ExtractFileFromGP2(gp2, inner, &size);
                if (file != NULL)
                    func_020e046c(name, file, size, (short)records->title_);
                BackgroundLoader::RemoveLockGlobal();
                int x = (0xa0 - func_020420e8(name, 1)) / 2;
                if (x < 0)
                    x = 0;
                AppendXYTag(text, x, 6);
                if (name != NULL)
                    _Z20AppendString02042058PcPKc(text, name);
            }
            else
            {
                int i;
                int count = 3;
                char* store = func_0205ec34();
                if (TestBitInByteArray((int)store, (unsigned char*)store + 0x8c, 0x1198))
                    count = 4;
                for (i = 0; i < count; i++)
                {
                    AppendXYTag(text, 4, i * 15 + 4);
                    _Z20AppendString02042058PcPKc(text, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, (short)(i + 0x82)));
                }
            }
        }
        func_0205d304(&self->window_, self->text_, 0, 0, 0, 0, 0, 1);
        return;
    }
    self->window_.width_ = 0x16;
    self->window_.height_ = 8;
    self->window_.unk_a4 = 1;
    self->window_.unk_a6 = 0xf;
    self->window_.unk_a8 = 4;
    self->window_.unk_aa = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unk_ae = 0xe;
    self->window_.unk_b7 = 0xa;
    self->window_.unk_b1 = 4;
    self->window_.unk_b5 = 1;
    self->window_.unk_b6 = 1;
    memset(self->text_, 0, 0x960);
    char* labels = self->text_;
    if (labels != NULL)
    {
        _Z26GetGlobalField0x1c020421a0v();
        if (records != NULL)
        {
            Hero* hero = (Hero*)GameState::GetInstance()->GetProtagonist();
            char* name = self->text_ + 0x8e0;
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char inner[0x20];
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            __clear(inner, sizeof(inner));
            sprintf(gp2, data_ov008_0218b465, hero->partyData_->appearance_.female_);
            sprintf(inner, data_ov008_0218b47c, hero->partyData_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e046c(name, file, size, (short)records->title_);
            BackgroundLoader::RemoveLockGlobal();
            int x = (0xa0 - func_020420e8(name, 1)) / 2;
            if (x < 0)
                x = 0;
            AppendXYTag(labels, x, 6);
            if (name != NULL)
                _Z20AppendString02042058PcPKc(labels, name);
        }
        else
        {
            int i;
            int count = 3;
            char* store = func_0205ec34();
            if (TestBitInByteArray((int)store, (unsigned char*)store + 0x8c, 0x1198))
                count = 4;
            for (i = 0; i < count; i++)
            {
                AppendXYTag(labels, 4, i * 15 + 4);
                _Z20AppendString02042058PcPKc(labels, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, (short)(i + 0x82)));
            }
        }
    }
    func_0205d304(&self->window_, self->text_, 0, 0, 0, 0, 0, 0);
    self->window_.width_ = 3;
    self->window_.height_ = 8;
    self->window_.unk_a4 = 0x1b;
    self->window_.unk_a6 = 0xf;
    self->window_.unk_a8 = 4;
    self->window_.unk_aa = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unk_ae = 0xe;
    self->window_.unk_b7 = 0xa;
    self->window_.unk_b1 = 5;
    self->window_.unk_b5 = 1;
    self->window_.unk_b6 = 1;
    memset(self->text_, 0, 0x960);
    func_ov008_02188408(self, self->text_, 1, records);
    func_0205d304(&self->window_, self->text_, 0, 0, 0, 0, 0, 0);
}
