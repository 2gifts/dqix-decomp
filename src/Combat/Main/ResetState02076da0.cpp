#include <globaldefs.h>
#include "World/Object3D.h"

struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);

struct State02076da0 {
    unsigned char pad_b0[0xb0];
    unsigned short f0xb0;
    unsigned short f0xb2;
    unsigned short f0xb4;
    unsigned char pad_130[0x130 - 0xb6];
    int f130;
    unsigned char pad_17a[0x17a - 0x134];
    unsigned char f0x17a;
};

// USA: func_02076da0
ARM int ResetState02076da0(struct State02076da0* p) {
    if (p->f130 == 0) SetByteSavingPrevious((struct Foo02033b58*)p, 0);
    else SetByte0xbeShiftPrev((struct Bytes02033b88*)p, 0);
    p->f0xb0 = 0x328;
    p->f0xb2 = 0;
    p->f0xb4 = 0;
    ((Object3D*)((unsigned char*)p))->DisableFlag(0x80);
    p->f0x17a = 0;
    return 1;
}
