#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
struct Node0205bacc;
struct Struct_0205bcdc;

extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* list, int mode);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* chan);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(void* chan);
extern "C" void _Z30SetupDualPointerTables0205cf28Phiii(unsigned char* p, int a, int b, int c);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* node, int val);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc* obj, int index);
extern "C" void func_0205bb04(void* obj, int v);

struct GlobalField0x1c {
    char unk0[0x5c];
    void* tileBuffer;
};
extern "C" struct GlobalField0x1c* _Z26GetGlobalField0x1c020421a0v();

extern "C" void func_0205d304(void* window, void* buf, int a, int b, int c, int d, int e, int f);

struct WindowNode {
    int unk0;
    int unk4;
};

struct Window {
    char unk0[4];
    struct WindowNode nodeA;
    char unkC[0x54 - 0xc];
    struct WindowNode nodeB;
    char unk5c[0xa0 - 0x5c];
    short unkA0;
    short unkA2;
    short tileX;
    short tileY;
    short unkA8;
    short unkAA;
    short unkAC;
    short unkAE;
    char unkB0;
    unsigned char unkB1;
};

struct Combatant {
    char unk0[0x38];
    struct Window* window;
    char unk3c[0x44 - 0x3c];
    int posX;
    int posY;
};

extern "C" void func_ov000_02176500(struct Combatant* obj, void* buf, int arg);

// USA: func_ov000_0217636c
extern "C" ARM void func_ov000_0217636c(struct Combatant* obj, int arg) {
    struct Window* window = obj->window;
    if (window != 0) {
        int x = obj->posX;
        int y = obj->posY;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)window, 1);
        _Z23SetChannelAFlag0205cef8Pv(window);
        _Z23SetChannelBFlag0205cf04Pv(window);
        _Z30SetupDualPointerTables0205cf28Phiii((unsigned char*)window, 2, 3, 0);
        _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)&window->nodeA, 6);
        _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)&window->nodeB, 6);
        _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc*)&window->nodeA, 0);
        func_0205bb04(&window->nodeB, 0);
        window->nodeA.unk4 = 1;
        window->nodeB.unk4 = 1;
        window->unkA0 = 2;
        window->unkA2 = 1;
        window->tileX = (x >> 3) + 9;
        window->tileY = (y >> 3) + 1;
        window->unkA8 = 0xc;
        window->unkAA = 0xe;
        window->unkAC = 0xa;
        window->unkAE = 0xe;
        window->unkB1 = 0xd;
        void* buf = _Z26GetGlobalField0x1c020421a0v()->tileBuffer;
        memset(buf, 0, 0x960);
        func_ov000_02176500(obj, buf, arg);
        func_0205d304(obj->window, buf, 0, 1, 0, 1, 0, 0);
    }
}
