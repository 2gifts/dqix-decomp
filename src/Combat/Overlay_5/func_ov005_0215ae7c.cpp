#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_ov005_0215ae7c func_ov005_0215c33c
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct MessageSystem;
struct Field150Holder02052e14;
struct Container020dedd0;
struct Container020e0310;

struct MemberScreen
{
    char unk_0[LOW_REGION(0x4f8,0x4fc)];
    int member_;
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
    char texts_[LOW_REGION(0x3d7c,0x3e04) - 0xdf8];
    signed char unk_3e04;
    char unk_3e05[0x3e84 - 0x3e05];
    unsigned short names_[8][LOW_REGION(0xa,0x40)];
    unsigned char longNames_[8];
};

MessageSystem* GetGlobalField0x1c020421a0();
extern "C" GameResources* func_ov017_0218b5b0(void);
MemberScreen* GetField1c_021a193c(int* obj);
short* GetField150Ptr0x488(Field150Holder02052e14* member);
extern "C" void func_020462d0(MessageSystem* messages, unsigned short* codes, int count);
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" void __clear(void* buffer, unsigned long size);
void CopyTextAndUppercaseIfFlagged0206819c(const char* name, char* output, int flag);
extern "C" void func_02046608(MessageSystem* messages, int, const char* format, char* output, int size, int, int);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
int FindSubstring(char* text, char* search);
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int);
extern "C" void func_020439b0(MessageSystem* messages, int);
#if defined(jpn)
extern "C" void func_020471d0(MessageSystem* messages, int, unsigned short* codes, int);
extern "C" void func_020469b0(MessageSystem* messages, const char* text, unsigned short* codes, int);
#endif

extern "C" const unsigned char data_ov005_0215cc04[8];
extern "C" char data_ov005_0215ce08[];

// USA: func_ov005_0215ae7c
extern "C" ARM void func_ov005_0215ae7c(EquipmentMenu* self)
{
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052e14* member =
        (Field150Holder02052e14*)GetCombatantWithFlag0x100(gameState, GetField1c_021a193c((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3])->member_);
    if (member == NULL)
        return;
    short* equipment = GetField150Ptr0x488(member);
    for (int i = 0; i < 8; i++)
    {
#if defined(jpn)
        func_020471d0(messages, 0xa, self->names_[i], 0xa);
#else
        func_020462d0(messages, self->names_[i], 0x40);
#endif
        for (int j = 0; j < LOW_REGION(0xa,0x40); j++)
            self->names_[i][j] = 0xffff;
#if !defined(jpn)
        self->longNames_[i] = 0;
#endif
    }
    for (int i = 0; i < 8; i++)
    {
        short item = equipment[data_ov005_0215cc04[i]];
        Element020de650* entry = FindElementByKey020dedd0(self->items_, item);
#if defined(jpn)
        if (entry != NULL)
        {
            func_020469b0(messages, entry->unk_4, self->names_[i], 0xa);
        }
        else if (item <= 0)
        {
            func_020469b0(messages, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x2ee0), self->names_[i], 0xa);
        }
        else
        {
            func_020469b0(messages, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x32c7), self->names_[i], 0xa);
        }
#else
        char text[0x80];
        __clear(text, sizeof(text));
        if (entry != NULL)
        {
            char name[0x80];
            __clear(name, sizeof(name));
            CopyTextAndUppercaseIfFlagged0206819c(entry->unk_4, name, 0);
            func_02046608(messages, 0, name, text, 0x58, 0, 0);
        }
        else if (item <= 0)
        {
            func_02046608(messages, 0, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x2ee0), text, 0x58, 0, 0);
        }
        else
        {
            func_02046608(messages, 0, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x32c7), text, 0x58, 0, 0);
        }
        if (FindSubstring(text, data_ov005_0215ce08))
            self->longNames_[i] = 1;
        func_02045d14(messages, text, self->names_[i], 0);
#endif
        func_020439b0(messages, 0);
        self->unk_3e04 = 2;
    }
}
