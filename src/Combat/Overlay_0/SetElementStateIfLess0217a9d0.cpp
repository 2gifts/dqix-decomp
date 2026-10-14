#include <globaldefs.h>

struct Elem_0205d81c;
struct Struct_0205d81c;
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* obj, int value);

// USA: func_ov000_0217a9d0
ARM void SetElementStateIfLess0217a9d0(int key, int b, int c, struct Struct_0205d81c* s) {
    struct Elem_0205d81c* elem = FindElementByC40205d81c(s, key);
    int v;
    if (elem == 0) return;
    v = 0;
    if (c < b) v = 1;
    SetField0xd8State_02050400((unsigned char*)elem, v);
}
