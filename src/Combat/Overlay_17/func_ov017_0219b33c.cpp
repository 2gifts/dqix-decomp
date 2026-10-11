#include <globaldefs.h>
#include "GameState/GameState.h"

int IsFieldNotPositive_021a4e70(unsigned char* base);
unsigned char GetByte0x26c(char* obj);

struct SrcFields_0219b33c {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short field10;
    short field12;
};

extern const unsigned char data_ov017_021d64a0[15];

struct Pair0219b33c { unsigned int v[2]; };
struct Buf15_0219b33c { unsigned char v[15]; };

// JPN: func_ov017_0219bed0
// USA: func_ov017_0219b33c
extern "C" ARM void func_ov017_0219b33c(char* self, struct SrcFields_0219b33c* src) {
#if defined(jpn)
 enum {regionalOffset0=0x180, regionalOffset1=0x34b4, regionalOffset2=0x3e60, regionalOffset3=0x34a4, regionalOffset4=0x34a5, regionalOffset5=0x34a6, regionalOffset6=0x34a8, regionalOffset7=0x34ac, regionalOffset8=0x34b6};
#else
 enum {regionalOffset0=0x18c, regionalOffset1=0x36c4, regionalOffset2=0x4080, regionalOffset3=0x36b4, regionalOffset4=0x36b5, regionalOffset5=0x36b6, regionalOffset6=0x36b8, regionalOffset7=0x36bc, regionalOffset8=0x36c6};
#endif
    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();

    if (!IsFieldNotPositive_021a4e70((unsigned char*)self)) return;

    if (combatant) {
        if (*(int*)((char*)combatant + regionalOffset0) & 1) return;
        if (GetByte0x26c((char*)combatant) != 0) return;
    }

    if (*(short*)(self + regionalOffset1) < src->field10) return;
    if (*(int*)(self + regionalOffset2) != 0) return;

    *(unsigned char*)(self + regionalOffset3) = src->field0;
    *(unsigned char*)(self + regionalOffset4) = src->field1;
    *(unsigned short*)(self + regionalOffset5) = src->field2;
    *(unsigned char*)(self + regionalOffset6) = src->field4;
    *(struct Pair0219b33c*)(self + regionalOffset7) = *(struct Pair0219b33c*)&src->field8;
    *(short*)(self + regionalOffset1) = src->field10;
    *(short*)(self + regionalOffset8) = src->field12;

    if (src->field1 != 0x12) return;

    struct Buf15_0219b33c bufWrap;
    unsigned char* buf = bufWrap.v;
    bufWrap = *(struct Buf15_0219b33c*)data_ov017_021d64a0;

    *(unsigned char*)(self + regionalOffset4) = buf[src->field0];
}
