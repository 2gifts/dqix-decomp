#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021ff4b0 data_ov023_021fe73c
#define func_ov023_021fc408 func_ov023_021fb700
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
struct Obj021fc408;
extern "C" int func_ov023_021fc408(struct Obj021fc408* obj, int unused, int b, int c, int p5, int p6, int p7, int p8, int p9, int p10);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021ff4b0;

struct Buf0216b120 { void* magic; char pad[0x30 - 4]; };

// USA: func_ov004_0216b120
extern "C" ARM void func_ov004_0216b120(void* p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
    void* base = func_ov011_021845f8(p0, p2);
    void* buf = ((SafeAllocator*)((char*)base + 4))->Allocate(0x30);
    if (!buf) {
        return;
    }

    struct Buf0216b120 local;
    local.magic = &data_ov023_021ff4b0;
    memcpy(buf, &local, sizeof(Buf0216b120));

    func_ov023_021fc408((struct Obj021fc408*)buf, (int)p0, p1, p2, p3, p4, p5, p6, p7, 0xf);

    void* list = func_ov011_021849c8(p0);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)buf);
}
