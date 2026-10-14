#include <globaldefs.h>

extern char data_021015a0;
extern char data_021017a0;
extern char data_02101f80;

extern "C" void func_0202cb50();
void SetField0x48UnlessState9Or10_0202c848(int arg);
int IssueBattleCommandSlot13_020d559c(int a0, unsigned int a1);
int BuildAndDispatch020d5898(int a, int b, int c, int d, unsigned short e, unsigned short f);

// USA: func_0202c9ac
extern "C" ARM void func_0202c9ac(unsigned short* p) {
    unsigned short mask = 1 << p[8];
    unsigned short v = p[1];
    if (v != 0) {
        SetField0x48UnlessState9Or10_0202c848(v);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }
    switch (p[4]) {
    case 7: {
        int (*cb)(void*) = *(int (**)(void*))((char*)&data_021015a0 + 0x24);
        if (cb != 0 && cb(p) == 0) {
            int r = IssueBattleCommandSlot13_020d559c(0, p[8]);
            if (r == 2) return;
            SetField0x48UnlessState9Or10_0202c848(r);
            *(int*)(&data_021015a0 + 0x10) = 9;
            return;
        }
        *(unsigned short*)((char*)&data_021015a0 + 0xa) = *(unsigned short*)((char*)&data_021015a0 + 0xa) | mask;
        void (*cb2)(unsigned short*) =
            *(void (**)(unsigned short*))((char*)&data_021015a0 + 0x18);
        if (cb2 != 0) cb2(p);
        return;
        }
    case 9: {
        *(unsigned short*)((char*)&data_021015a0 + 0xa) = *(unsigned short*)((char*)&data_021015a0 + 0xa) & ~mask;
        void (*cb2)(unsigned short*) =
            *(void (**)(unsigned short*))((char*)&data_021015a0 + 0x18);
        if (cb2 != 0) cb2(p);
        return;
        }
    case 0: {
        int state = *(int*)(&data_021015a0 + 0x10);
        int f;
        int r;
        if (!(state != 4 && state != 6 && state != 5)) { f = 1; goto done0; }
        *(int*)(&data_021015a0 + 0x10) = 4;
        r = BuildAndDispatch020d5898((int)func_0202cb50, (int)&data_02101f80,
                                     (unsigned short)*(int*)((char*)&data_021015a0 + 0x2c),
                                     (int)&data_021017a0,
                                     (unsigned short)*(int*)((char*)&data_021015a0 + 0x38),
                                     1);
        if (r == 2) { f = 1; goto done0; }
        SetField0x48UnlessState9Or10_0202c848(r);
        f = 0;
    done0:
        if (f == 0) { *(int*)(&data_021015a0 + 0x10) = 9; }
        return;
        }
    case 2:
        break;
    case 26:
        break;
    }
}
