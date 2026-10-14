#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205ba68;
struct Struct_0205d81c;
struct Node0205bacc;
struct Container020e0310;

struct ListWindow0217dd60 {
    char pad0[0x8];
    int field8;
    char pad0c[0x58 - 0xc];
    int field58;
    char pad5c[0x68 - 0x5c];
    int page;
    char pad6c[0x94 - 0x6c];
    unsigned char field94;
    unsigned char field95;
    char pad96[0xa0 - 0x96];
    short a0;
    short a2;
    short a4;
    short a6;
    short a8;
    short aa;
    short ac;
    short ae;
    char padb0;
    unsigned char fieldb1;
    char padb2[0xb5 - 0xb2];
    unsigned char fieldb5;
};

struct ListMenu0217dd60 {
    char pad0[0x10];
    int field10;
    char pad14[0x18 - 0x14];
    unsigned char items[0x30 - 0x18];
    unsigned char itemCount;
    char pad31;
    unsigned char field32;
    char pad33[0x90 - 0x33];
    struct ListWindow0217dd60* window;
    char pad94[0xcc - 0x94];
    char names[4];
};

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24*, unsigned char, unsigned char);
void SetChannelBFlag0205cf04(void*);
void SetChannelAFlag0205cef8(void*);
int GetGlobalField0x1c020421a0();
extern "C" void func_02012fe4();
extern "C" void __clear(void* buf, int n);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
void AppendNameTag_02041b70(char* dst, int n, const char* name);
void AppendString02042058(char* dst, const char* src);
unsigned char* GetElementByB4IfAbsent_0205e00c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* elem, int state);
void SetByte0xd9AndFlag0x2_0205042c(unsigned char* elem, unsigned char value);
void SetByte0xdaAndFlag0x2_02050440(unsigned char* elem, int value);
extern "C" void func_0205d304(void* window, char* buf, int a, int b, int c, int d, int e, int f);
void SetupPointerTable0205ba68(struct Struct_0205ba68* t, int a, int b, int c);
void SetField0AndPropagate0205bacc(struct Node0205bacc* n, int value);

extern const char data_ov003_02180c7f[];

// USA: func_ov003_0217dd60
extern "C" ARM void func_ov003_0217dd60(struct ListMenu0217dd60* menu) {
    char buf[0x400];
    func_02012fe4();
    GetGlobalField0x1c020421a0();
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)menu->window, 0, 1);
    int field10Value = menu->field10;
    menu->window->fieldb1 = 0;
    short scaled = (short)(field10Value >> 3);
    {
        struct ListWindow0217dd60* w = menu->window;
        w->a0 = scaled;
        w->a2 = 11;
    }
    {
        struct ListWindow0217dd60* w = menu->window;
        w->a4 = (32 - scaled) >> 1;
        w->a6 = 2;
    }
    {
        struct ListWindow0217dd60* w = menu->window;
        w->a8 = 12;
        w->aa = 6;
    }
    {
        struct ListWindow0217dd60* w = menu->window;
        w->ac = 10;
        w->ae = 13;
    }
    if (menu->field32 > 1) {
        struct ListWindow0217dd60* w = menu->window;
        w->a0 = scaled;
        w->a2 = 12;
    }
    menu->window->fieldb5 = 1;
    SetChannelBFlag0205cf04(menu->window);
    SetChannelAFlag0205cef8(menu->window);
    int end;
    int i;
    int page = menu->window->page;
    __clear(buf, 0x400);
    end = (page + 1) * 6;
    if (end > menu->itemCount) {
        end = menu->itemCount;
    }
    for (i = page * 6; i < end; i++) {
        const char* name = (const char*)GetFieldByKey020e0434((struct Container020e0310*)menu->names, (short)(menu->items[i] + 100));
        AppendNameTag_02041b70(buf, i % 6, name);
        if (i != end - 1) {
            AppendString02042058(buf, data_ov003_02180c7f);
        }
    }
    if (menu->field32 > 1) {
        unsigned char* elem = GetElementByB4IfAbsent_0205e00c((struct Struct_0205d81c*)menu->window, 0);
        if (elem != NULL) {
            SetField0xd8State_02050400(elem, 1);
            SetByte0xd9AndFlag0x2_0205042c(elem, page);
            SetByte0xdaAndFlag0x2_02050440(elem, menu->field32);
        }
    }
    if (menu->field32 > 1) {
        func_0205d304(menu->window, buf, 0, 0, 1, 1, 0, 0);
    } else {
        func_0205d304(menu->window, buf, 0, 0, 0, 1, 0, 0);
    }
    int field32 = menu->field32;
    struct ListWindow0217dd60* window = menu->window;
    window->field8 = field32;
    window->field58 = field32;
    SetupPointerTable0205ba68((struct Struct_0205ba68*)((char*)window + 4), 1, 6, 0);
    SetupPointerTable0205ba68((struct Struct_0205ba68*)((char*)window + 0x54), 1, 6, 0);
    unsigned char itemCount = menu->itemCount;
    SetField0AndPropagate0205bacc((struct Node0205bacc*)((char*)window + 4), itemCount);
    SetField0AndPropagate0205bacc((struct Node0205bacc*)((char*)window + 0x54), itemCount);
    window->field94 = 1;
    window->field95 = 1;
}
