#include <globaldefs.h>

struct Obj2081;
struct Elem2081;

struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);

// USA: func_020811d0
ARM int HasElementByByte0xc4_020811d0(struct Obj2081* obj, int key) {
    return FindElementByByte0xc4_02081da8(obj, key) != NULL;
}
