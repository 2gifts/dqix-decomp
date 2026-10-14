#include <globaldefs.h>

struct Obj2081;

extern unsigned char* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
extern int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* obj);

// USA: func_020811e8
ARM int IsElementFieldActive020811e8(struct Obj2081* obj, int key) {
    unsigned char* elem = FindElementByByte0xc4_02081da8(obj, key);
    if (elem != NULL) {
        return CheckField0x9cSetWhenField0xd4Present_0204c7e0(elem) != 0;
    }
    return 0;
}
