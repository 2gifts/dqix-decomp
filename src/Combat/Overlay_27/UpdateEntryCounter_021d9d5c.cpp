#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern unsigned int data_ov027_021dd920;
extern char* data_ov027_021e33ec;

// USA: func_ov027_021d9d5c  (semantic: UpdateEntryCounter_021d9d5c)
extern "C" ARM void func_ov027_021d9d5c(int index) {
    if ((data_ov027_021dd920 & (1 << index)) == 0) return;
    if (*(unsigned char*)(data_ov027_021e33ec + index * 0x5d4 + 0x1d52) == 0) return;
    char* entry = data_ov027_021e33ec + index * 0x5d4;
    unsigned short counter = *(unsigned short*)(entry + 0x1d4c);
    if (counter == 0) return;
    unsigned short a = *(unsigned short*)(entry + 0x1d48);
    unsigned short b = *(unsigned short*)(entry + 0x1d4a);
    if (b > a) goto storeB;
    if (a <= b + 2) {
        *(unsigned short*)(entry + 0x1d48) = a + 1;
        return;
    }
storeB:
    *(unsigned short*)(entry + 0x1d48) = b;
}
