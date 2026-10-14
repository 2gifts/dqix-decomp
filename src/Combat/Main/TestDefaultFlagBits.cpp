#include <globaldefs.h>

extern int data_02102be0;
extern int data_02101980;
int TestFlagBitsAndDispatch020d6884_020d6830(int, unsigned short*, int);

// USA: func_0202dcb4
ARM int TestDefaultFlagBits_0202dcb4(int arg) {
    return TestFlagBitsAndDispatch020d6884_020d6830((int)&data_02102be0, (unsigned short*)&data_02101980, arg);
}
