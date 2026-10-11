#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
int GetWord0x0(int* obj);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

void* GetActiveCombatWork(void);
void* GetSlot021677d8(void* obj, int id);

extern "C" void* func_02012fe4(void);

int CheckBitsInField0x63dc(void* obj, int mask);

struct Vec3_02092d60 {
    int x, y, z;
};

extern "C" void func_ov017_021cf3c0(struct Vec3_02092d60 v, int shortVal, int p2, int bits, int byteVal);

struct GlobalStructShort02012fe4 {
    unsigned short f0;
};

struct Param1_02092d60 {
    char pad[0x38];
    signed char f38;
};

// JPN: 0x02093680
// USA: func_02092d60  (semantic: QueueVec3Event_02092d60)
extern "C" ARM void func_02092d60(struct Param1_02092d60* p1, int p2) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetUnknownGameObject();
    if (c != 0) {
        struct Vec3_02092d60 vecBuf;
        _ZN8Vector3iaSERKS_(&vecBuf.x, (int*)((char*)c + 0x44));
        int word0 = GetWord0x0((int*)bs);
        struct HeadNode02046b24** listHead = *(struct HeadNode02046b24***)((char*)(int)word0 + (IS_JPN ? 0x34ec : 0x36fc));
        int head = GetHeadNodeIdOrMinusOne(listHead);
        if (head == 0xa) {
            void* work = GetActiveCombatWork();
            if (work != 0) {
                void* slot = GetSlot021677d8(work, *(short*)((char*)c + 4));
                if (slot != 0) {
                    _ZN8Vector3iaSERKS_(&vecBuf.x, (int*)slot);
                }
            }
        }
        struct GlobalStructShort02012fe4* g = (struct GlobalStructShort02012fe4*)func_02012fe4();
        unsigned short shortVal = g->f0;
        int bits = CheckBitsInField0x63dc(bs, 1);
        func_ov017_021cf3c0(vecBuf, shortVal, p2, bits, p1->f38);
    }
}
