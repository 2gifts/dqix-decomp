#include <globaldefs.h>

extern "C" void func_020d4770(int, int, int);

// USA: func_020d5f88
ARM int ClearBattleSubEffectAt0x800_020d5f88(void* p) {
    if (p == NULL) return 6;
    if (*(unsigned short*)((char*)p + 0x80e) == 0) return 3;
    func_020d4770(*(unsigned short*)((char*)p + 0x816), 0, 0);
    *(unsigned short*)((char*)p + 0x80e) = 0;
    *(unsigned short*)((char*)p + 0x81c) = 0;
    return 0;
}
