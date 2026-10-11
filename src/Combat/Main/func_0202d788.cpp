#include <globaldefs.h>

extern char data_021015a0;
unsigned short GetSharedHalfwordOrBattleDefault();
void SetField0x48UnlessState9Or10(int);
extern "C" int _Z24IssueBattleCommandSlot30issst(int, short, short, unsigned short, unsigned short);
extern "C" void func_0202d840();

// USA: func_0202d788
extern "C" ARM int func_0202d788(unsigned short slot) {
    int mask;
    unsigned short idx;

    mask = GetSharedHalfwordOrBattleDefault();
    if (mask == 0x8000) {
        SetField0x48UnlessState9Or10(3);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 3;
    }
    if (mask == 0) {
        SetField0x48UnlessState9Or10(0x16);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return 0x18;
    }
    idx = slot;
    while (!(mask & (1 << (idx - 1)))) {
        idx = idx + 1;
        if (idx > 0x10) {
            return 0x18;
        }
    }
    return (unsigned short)_Z24IssueBattleCommandSlot30issst((int)&func_0202d840, 3, 0x11, idx, 0x1e);
}
