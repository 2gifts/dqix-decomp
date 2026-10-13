#include <globaldefs.h>

#if defined(jpn)
enum { MEMBER_OFFSET = 0x144 };
#else
enum { MEMBER_OFFSET = 0x150 };
#endif

extern "C" void func_02083c48(void*);

struct T0205420c {
    char pad[MEMBER_OFFSET];
    void* field150;
};

// USA: func_0205420c
ARM void MaybeCall0205420c(struct T0205420c* obj) {
    void* p = obj->field150;
    if (p != NULL) func_02083c48(p);
}
