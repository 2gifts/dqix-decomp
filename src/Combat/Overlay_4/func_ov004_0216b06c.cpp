#include <globaldefs.h>

#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021fbb64(void* block, void* obj, int p1, int p2, int p3, int p4, int p5, int p6, int one, int p7, int fifteen);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021ff078;

struct Buf0216b06c { void* magic; char pad[0x40 - 4]; };

// USA: func_ov004_0216b06c
extern "C" ARM void func_ov004_0216b06c(void* obj, int p1, int p2, int p3, int p4, int p5, int p6, int p7
#if !defined(jpn)
, unsigned char p8
#endif
) {
    void* buf = func_ov011_021845f8(obj, p2);
    void* block = ((SafeAllocator*)((char*)buf + 4))->Allocate(0x40);
    if (!block) return;

    struct Buf0216b06c local;
    local.magic = &data_ov023_021ff078;
    memcpy(block, &local, sizeof(Buf0216b06c));

    func_ov023_021fbb64(block, obj, p1, p2, p3, p4, p5, p6, 1, p7, 0xf);

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(obj), (struct ListNode_021f67ac*)block);
#if !defined(jpn)
    *((unsigned char*)block + 0x3d) = p8;
#endif
}
