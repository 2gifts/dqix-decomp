#include <globaldefs.h>
#include "World/Object3D.h"

#if defined(jpn)
enum { kListOffset = 0x4ec };
#else
enum { kListOffset = 0x6fc };
#endif

extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0208e0a8(void);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** obj);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
int IsMatchingName0208e824(void* unused, char* str);
struct S1a0;
struct Vector3i;

struct ListNode0208f410 {
    char pad0[4];
    int vec[3];
    unsigned int f10;
    ListNode0208f410* next;
};

struct Obj0208f410 {
    char pad0[8];
    void* target;
    ListNode0208f410* head;
};

// USA: func_0208f410  (semantic: ProcessTargetNodeList_0208f410)
extern "C" ARM void func_0208f410(Obj0208f410* obj) {
    if (obj->target == 0) return;

    int ov = func_ov017_0218b5b0();
    HeadNode02046b24** headList = *(HeadNode02046b24***)(ov + 0x3000 + kListOffset);
    if (GetHeadNodeIdOrMinusOne(headList) == 0xa) return;
    if (GetBitsInField4((unsigned int*)ov, 2) != 0) return;

    void* g = func_02012fe4();
    char* s = *(char**)((char*)g + 8);
    void* dataPtr = func_0208e0a8();
    if (s == 0) return;
    if (IsMatchingName0208e824(dataPtr, s + 5) == 0) return;

    ListNode0208f410* node = obj->head;
    int flag = 1;
    while (node) {
        ((Object3D*)((S1a0*)obj->target))->SetCurrentAnimationTime(node->f10);
        *(Vector3i*)((int*)((char*)obj->target + 0x44)) = *(Vector3i const*)((int*)&node->vec);
        ((Object3D*)obj->target)->Draw(flag);
        node = node->next;
    }
}
