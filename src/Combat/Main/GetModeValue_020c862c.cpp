#include <globaldefs.h>

unsigned int SetData020f2284();

extern int data_0211155c;

// USA: func_020c862c  (semantic: GetModeValue_020c862c)
extern "C" ARM unsigned int func_020c862c(unsigned int mode) {
    switch (mode) {
    case 0:
#if defined(jpn)
        return 0x022a39a0;
#else
        return 0x022a3200;
#endif
    case 2: {
        int v = *(int*)((char*)&data_0211155c + 4);
        if (v == 0) goto ret0;
        v = SetData020f2284();
        if ((v & 3) != 1) goto ret23e;
    ret0:
        return 0;
    ret23e:
        return 0x023e0000;
    }
    case 3:
#if defined(jpn)
        return 0x01fff2c0;
#else
        return 0x01fff280;
#endif
    case 4:
        return 0x027e0080;
    case 5:
        return 0x027ff000;
    case 6:
        return 0x037f8000;
    case 1:
    default:
        return 0;
    }
}
