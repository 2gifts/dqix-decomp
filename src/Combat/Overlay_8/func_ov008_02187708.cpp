#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct ClearRecords;

struct GuestRecords {
    unsigned int hours1_ : 14;
    unsigned int unk_0_14 : 17;
    unsigned int unk_0_31 : 1;
    unsigned int hours2_ : 14;
    unsigned int unk_4_14 : 17;
    unsigned int unk_4_31 : 1;
    unsigned int minutes1_ : 7;
    unsigned int minutes2_ : 7;
    unsigned int unk_8_14 : 7;
    unsigned int unk_8_21 : 7;
    unsigned int unk_8_28 : 4;
    unsigned int unk_c_0 : 10;
    unsigned int unk_c_10 : 14;
    unsigned int unk_c_24 : 7;
    unsigned int unk_c_31 : 1;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int unk_10_23 : 7;
    unsigned int unk_10_30 : 2;
    short title_;
    unsigned char female_ : 1;
    unsigned char unk_16_1 : 4;
    unsigned char unk_16_5 : 3;
    unsigned char unk_17;
};

struct TextTable {
    int pad_0[0x18 / 4];
};

struct TextList {
    int pad_0[2];
};

struct BackgroundGraphics {
    int pad_0[0x20 / 4];
};

struct TextWindow {
    int pad_0[0xbc / 4];
};

struct Canvas {
    int pad_0[0xe0 / 4];
};

struct WindowCursor {
    int pad_0[0x40 / 4];
};

struct Object3D {
    int pad_0[0xac / 4];
};

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    TextTable texts_;
    char* text_;
    char titleTable_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char itemCount_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    GuestRecords* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    PlayTime times_[2];
};

struct PartyMemberData {
    char pad_0[0x49c];
    unsigned char female_ : 1;
    char pad_49d[0x950 - 0x49d];
    int vocation_;
};

struct GameObject {
    char pad_0[0x150];
    PartyMemberData* partyData_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct HeroTitleWord {
    unsigned int unk_0 : 19;
    int title_ : 11;
    unsigned int unk_30 : 2;
};

static inline char* GetHeroTitle(GameState* gameState)
{
    return (char*)gameState + 0x569c;
}

struct BackgroundLoader {
    static BackgroundLoader* GetInstance();
    static void AddLockGlobal();
    static void RemoveLockGlobal();
};

struct MessageSystem {
    char pad_0[0x10];
    void* unk_10;
};

struct MessageName {
    int pad_0[3];
};

struct List020727d8;
struct Container020e0310;
struct TableA68;
struct StreamHeader;
struct Obj02046574;

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];
extern char data_ov008_0218b49b[];
extern char data_ov008_0218b4b0[];
extern char data_ov008_0218b4c1[];

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z20Clear12Bytes020e46c4Pv(void* name);
extern "C" void _Z28InitObjFromCombatant020e4c74PvP10GameObject(void* name, GameObject* object);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* list);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
const char* FindEntryByKey(TableA68* texts, int id);
extern "C" void _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(void* list, StreamHeader* file, int size, int id, void* output, unsigned char female);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574* messages, int index, char* text);
char* FindSubstring(char* text, char* search);
void AppendYTag(char* text, int y);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_02046380(MessageSystem* messages);
void func_02042764(const void* codes, char* text, int value);
void func_020e4b34(MessageName* name, char* text, char* text2, int a, int b, int c, int d, int female, int e,
                   int f, int g, int h);
const char* func_020e046c(char* output, void* file, unsigned int size, short id);
void func_02046608(MessageSystem* messages, int value, const char* format, char* output, int size, int a, int b);
int func_020420e8(const char* text, int large);
}

// USA: func_ov008_02187708
extern "C" ARM void func_ov008_02187708(BattleRecords* self, char* text, ClearRecords* records)
{
    if (text == NULL)
        return;
    GameState* gameState = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    char name[0x30];
    __clear(name, sizeof(name));
    short title = 0;
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    unsigned int female = 0;
    func_02046380(messages);
    MessageName heroName;
    MessageName guestName;
    const void* codes = self->guest_;
    if (codes == NULL)
    {
        char* heroTitle = GetHeroTitle(gameState);
        title = ((HeroTitleWord*)(heroTitle + 4))->title_;
        GameObject* hero = gameState->GetProtagonist();
        if (hero != NULL)
        {
            if (title <= 0)
            {
                PartyMemberData* data = hero->partyData_;
                int vocations = 0x50dc;
                if (data->female_ == 1)
                    vocations = 0x510e;
                title = vocations - 20000 + data->vocation_;
            }
            female = hero->partyData_->female_;
            _Z20Clear12Bytes020e46c4Pv(&heroName);
            _Z28InitObjFromCombatant020e4c74PvP10GameObject(&heroName, hero);
            messages->unk_10 = &heroName;
        }
    }
    else
    {
        GuestRecords* guest = self->guestRecords_;
        if (guest != NULL)
            title = guest->title_;
        female = guest->female_;
        func_02042764(codes, name, 1);
        _Z20Clear12Bytes020e46c4Pv(&guestName);
        func_020e4b34(&guestName, name, name, 0, 0, 0, 0, female, 0, 1, 0, 1);
        messages->unk_10 = &guestName;
    }
    if (title > 0)
    {
        TextList list;
        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)&list);
        const char* titleText = NULL;
        unsigned int size = 0;
        if (title < 700)
        {
            if (self->guestTitles_ != NULL)
            {
                titleText = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->guestTitles_, title);
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                unsigned int namesSize = 0;
                char gp2[0x40];
                char inner[0x20];
                __clear(gp2, sizeof(gp2));
                __clear(inner, sizeof(inner));
                sprintf(gp2, data_ov008_0218b465, female);
                sprintf(inner, data_ov008_0218b47c, female);
                void* file = ExtractFileFromGP2(gp2, inner, &namesSize);
                if (file != NULL)
                    titleText = func_020e046c(buffer, file, namesSize, title);
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        else
        {
            if (self->guestTexts_ != NULL)
            {
                titleText = FindEntryByKey((TableA68*)self->guestTexts_, (short)(title + 20000));
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                void* file = ExtractFileFromGP2(data_ov008_0218b49b, data_ov008_0218b4b0, &size);
                if (file != NULL)
                {
                    _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(&list, (StreamHeader*)file, size, (short)(title + 20000), buffer, 0);
                    titleText = buffer;
                }
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)messages, 0, (char*)titleText);
    }
    char* output = self->text_;
    int format = 100;
    int width = 0xee;
    if (records != NULL)
    {
        format = 101;
        width = 0xdf;
    }
    func_02046608(messages, 10, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, format), output + 0x760, width, 1, 0);
    int color = 7;
    if (FindSubstring(output + 0x760, data_ov008_0218b4c1) != NULL)
        color = 2;
    if (records != NULL)
    {
        self->titleX_ = (func_020420e8(output + 0x760, 0) + 0x10) << 12;
        if (color == 2)
            self->titleX_ = 0xe0000;
    }
    AppendYTag(text, color);
    _Z20AppendString02042058PcPKc(text, output + 0x760);
}
