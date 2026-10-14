#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);

// USA: func_ov000_0216fcfc
ARM int GetFieldByKeyFromWork0x88_ov000_0216fcfc(void* obj, int key) {
    return GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + 0x88), key);
}
