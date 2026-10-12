#include <globaldefs.h>

#if defined(jpn)
enum { MEMBER_OFFSET = 0x19c };
#else
enum { MEMBER_OFFSET = 0x1a8 };
#endif

struct S3f58 {
    char unk[MEMBER_OFFSET];
    int field1a8;
    int field1ac;
};

#if defined(jpn)
#define GetFields1a8And1ac func_020552d0
extern "C" ARM void func_020552d0(struct S3f58* obj, int* out1, int* out2);
#endif

// USA: func_02053f58
ARM void GetFields1a8And1ac(struct S3f58* obj, int* out1, int* out2) {
    *out1 = obj->field1a8;
    *out2 = obj->field1ac;
}
