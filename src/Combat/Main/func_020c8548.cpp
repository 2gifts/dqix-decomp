#include <globaldefs.h>
#include <System/DTCM.h>

unsigned int SetData020f2284();

extern int data_0211155c;

extern "C" void SDK_SYS_STACKSIZE(void);
extern "C" void SDK_IRQ_STACKSIZE(void);

// USA: func_020c8548
extern "C" ARM unsigned int func_020c8548(unsigned int mode) {
    switch (mode) {
    case 0:
        return 0x023e0000;
    case 2: {
        int v = *(int*)((char*)&data_0211155c + 4);
        if (v == 0) goto ret0;
        v = SetData020f2284();
        if ((v & 3) != 1) goto ret270;
    ret0:
        return 0;
    ret270:
        return 0x02700000;
    }
    case 3:
        return 0x02000000;
    case 4: {
        unsigned long irqLo = (unsigned long)&data_027e0000 + 0x3f80 - (long)SDK_IRQ_STACKSIZE;
        unsigned long sysLo;
        if ((long)SDK_SYS_STACKSIZE == 0) {
            sysLo = (unsigned long)&data_027e0000;
            if (sysLo < 0x027e0080) {
                sysLo = 0x027e0080;
            }
        } else if ((long)SDK_SYS_STACKSIZE < 0) {
            sysLo = 0x027e0080 - (long)SDK_SYS_STACKSIZE;
        } else {
            sysLo = irqLo - (long)SDK_SYS_STACKSIZE;
        }
        return sysLo;
    }
    case 5:
        return 0x027ff680;
    case 6:
        return 0x037f8000;
    case 1:
    default:
        return 0;
    }
}
