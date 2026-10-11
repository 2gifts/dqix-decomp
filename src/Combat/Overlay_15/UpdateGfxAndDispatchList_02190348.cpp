#if defined(jpn)
#define R(j,u) (j)
#define func_0208b610 func_0208bf04
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3b0Value(GameState* battleStruct);
extern "C" void _Z24DispatchByMode5_0218f22cPv(void* obj);

struct Vec3_02190348 { int x, y, z; };
extern "C" void func_0208b610(struct Vec3_02190348 v, unsigned short p, int a, int b, int c, short d);

struct ListNode02190348 { void* payload; struct ListNode02190348* next; };

struct Obj02190348 {
    char pad0[0x2c];
    struct ListNode02190348* list;
    char pad1[0x19c - 0x2c - 4];
    unsigned char flag19c;
    unsigned char flag19d;
};

// USA: func_ov015_02190348  (semantic: UpdateGfxAndDispatchList_02190348)
extern "C" ARM void func_ov015_02190348(struct Obj02190348* obj) {
    if (obj->flag19d) {
        *(volatile unsigned int*)0x040004a4 = 0x1f00c0;
        *(volatile unsigned int*)0x04000444 = 0;
        *(volatile unsigned int*)0x04000500 = 1;
        *(volatile unsigned int*)0x04000480 = 0x5294;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0xd000;
        *(volatile unsigned int*)0x0400048c = 0x3000;
        *(volatile unsigned int*)0x04000504 = 0;
        *(volatile unsigned int*)0x04000448 = 1;
    }
    if (obj->flag19c) {
        GameState* bs = GameState::GetInstance();
        int f3b0 = GetField0x3b0Value(bs);
        func_0208b610(*(struct Vec3_02190348*)(f3b0 + 0x10), 0x3dff, 0x800, 0x800, 0x800, 0);
    }
    struct ListNode02190348* node = obj->list;
    while (node != 0) {
        _Z24DispatchByMode5_0218f22cPv(node->payload);
        node = node->next;
    }
}
