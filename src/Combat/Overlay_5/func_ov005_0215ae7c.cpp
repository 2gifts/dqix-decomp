#include <globaldefs.h>

struct MessageSystem;
struct Field150Holder02052e14;
struct Container020dedd0;
struct Container020e0310;

struct GameState
{
    static GameState* GetInstance();
};

struct MemberScreen
{
    char unk_0[0x4fc];
    int member_;
};

struct GameResources
{
    char unk_0[0x3708];
    int* unknown_ptr_3708;
};

struct Element020de650
{
    int unk_0;
    const char* unk_4;
};

struct EquipmentMenu
{
    char unk_0[0xdf4];
    Container020dedd0* items_;
    char texts_[0x3e04 - 0xdf8];
    signed char unk_3e04;
    char unk_3e05[0x3e84 - 0x3e05];
    unsigned short names_[8][0x40];
    unsigned char longNames_[8];
};

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* obj);
Field150Holder02052e14* GetCombatantWithFlag0x100(GameState* gameState, int index);
short* GetField150Ptr0x488(Field150Holder02052e14* member);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
extern "C" Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char* name, char* output, int flag);
extern "C" void func_02046608(MessageSystem* messages, int, const char* format, char* output, int size, int, int);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
int FindSubstring(char* text, char* search);
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int);
extern "C" void func_020439b0(MessageSystem* messages, int);

extern "C" const unsigned char data_ov005_0215cc04[8];
extern "C" char data_ov005_0215ce08[];

// USA: func_ov005_0215ae7c
extern "C" ARM void func_ov005_0215ae7c(EquipmentMenu* self)
{
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052e14* member =
        GetCombatantWithFlag0x100(gameState, _Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708)->member_);
    if (member == NULL)
        return;
    short* equipment = GetField150Ptr0x488(member);
    for (int i = 0; i < 8; i++)
    {
        func_020462d0(messages, self->names_[i], 0x40);
        for (int j = 0; j < 0x40; j++)
            self->names_[i][j] = 0xffff;
        self->longNames_[i] = 0;
    }
    for (int i = 0; i < 8; i++)
    {
        short item = equipment[data_ov005_0215cc04[i]];
        Element020de650* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, item);
        char text[0x80];
        __clear(text, sizeof(text));
        if (entry != NULL)
        {
            char name[0x80];
            __clear(name, sizeof(name));
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(entry->unk_4, name, 0);
            func_02046608(messages, 0, name, text, 0x58, 0, 0);
        }
        else if (item <= 0)
        {
            func_02046608(messages, 0, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x2ee0), text, 0x58, 0, 0);
        }
        else
        {
            func_02046608(messages, 0, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x32c7), text, 0x58, 0, 0);
        }
        if (FindSubstring(text, data_ov005_0215ce08))
            self->longNames_[i] = 1;
        func_02045d14(messages, text, self->names_[i], 0);
        func_020439b0(messages, 0);
        self->unk_3e04 = 2;
    }
}
