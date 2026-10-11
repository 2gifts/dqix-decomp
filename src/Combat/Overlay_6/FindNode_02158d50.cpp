#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_02154e58 func_ov006_021565b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Node02158d50 {
    char pad[0x1c];
    struct Node02158d50* next;
};

struct Obj02158d50 {
    char pad[R(0x24, 0x2c)];
    struct Node02158d50* list;
};

// USA: func_ov006_02158d50
ARM struct Node02158d50* FindNode_02158d50(struct Obj02158d50* obj, short id) {
    struct Node02158d50* n = obj->list;
    struct Node02158d50* result = n;
    short target = id << 4;
    short i = 0;
    while (n) {
        if (i == target) {
            result = n;
            break;
        }
        i++;
        n = n->next;
    }
    return result;
}
