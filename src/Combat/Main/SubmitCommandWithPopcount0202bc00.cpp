#include <globaldefs.h>

int PopCount32_020d1ae4(unsigned int);
unsigned short GetField0xa_0202d698(void);
void EmptyStub0202aebc(void);
int IssueBattleCommandSlot24_020d69cc(int, int, int, int, unsigned short, unsigned char);

#pragma optimize_for_size off
// USA: func_0202bc00  (semantic: SubmitCommandWithPopcount0202bc00)
extern "C" ARM int func_0202bc00(void* obj, int flag) {
    unsigned short* p = (unsigned short*)((char*)obj + 0x102a);
    *p = *p + 1;
    unsigned char* q = (unsigned char*)((char*)obj + 0x1029);
    int idx = (PopCount32_020d1ae4(GetField0xa_0202d698()) - 1) & 0xff;
    int f = flag != 0;
    *q = (*q & ~7) | (idx & 7);
    unsigned short field4 = *(unsigned short*)((char*)obj + 4);
    return IssueBattleCommandSlot24_020d69cc((int)(void*)EmptyStub0202aebc, (int)((char*)obj + 0x1014), 0x24, 0x785, field4, (unsigned char)(f & 0xff));
}
