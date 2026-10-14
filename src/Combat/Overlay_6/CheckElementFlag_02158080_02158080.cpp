#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
int IsElemFlag0x20Clear_02080c3c(struct Obj2081* obj, int key);

// USA: func_ov006_02158080
ARM int CheckElementFlag_02158080_02158080(struct Obj2081* obj, int key) {
    if (FindElementByByte0xc4_02081da8(obj, key) != NULL) {
        if (IsElemFlag0x20Clear_02080c3c(obj, key) != 0) {
            return 1;
        }
    }
    return 0;
}
