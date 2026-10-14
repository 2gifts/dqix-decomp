#include <globaldefs.h>

struct Struct_0205d81c;
unsigned int FindElementByC40205d81c(Struct_0205d81c*, int);

// USA: func_ov002_02157030  (semantic: Trans_02157030)
extern "C" ARM void func_ov002_02157030(unsigned int self, unsigned int id, short* x, short* y, short* w, short* h) {
    char* e = (char*)FindElementByC40205d81c((Struct_0205d81c*)(self + 0xec8), id);
    if (e == 0) {
        return;
    }
    *x = *(short*)(e + 0xac);
    *y = *(short*)(e + 0xae);
    *w = *(short*)(e + 0xa8);
    *h = *(short*)(e + 0xaa);
}
