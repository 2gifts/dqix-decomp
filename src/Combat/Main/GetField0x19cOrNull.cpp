#include <globaldefs.h>

struct S02053dc0 {
#if defined(jpn)
    char pad[0x190];
#else
    char pad[0x19c];
#endif
    void* field19c;
};

// USA: func_02053dc0
ARM void* GetField0x19cOrNull(struct S02053dc0* p) {
    void* x = p->field19c;
    return x != NULL ? x : NULL;
}
