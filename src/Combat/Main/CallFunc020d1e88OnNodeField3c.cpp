#include <globaldefs.h>

int EnqueueEvent0x6Sub4_020d1e88(int, int);

struct Node020bc1ac { unsigned char pad[0x3c]; unsigned char field3c; };
struct Obj020bc1ac { struct Node020bc1ac* node; };

static inline bool HasNode(const struct Obj020bc1ac* o) { return o->node != NULL; }

// USA: func_020bc1ac
ARM void CallFunc020d1e88OnNodeField3c(struct Obj020bc1ac* obj, int arg) {
    if (!HasNode(obj)) return;
    EnqueueEvent0x6Sub4_020d1e88(obj->node->field3c, arg);
}
