#include <globaldefs.h>

extern int func_ov031_02205d10;
void* SetLookupFields_02205134(void*, void*, int);
struct Obj0220527c;
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);

// USA: func_ov031_02205cc4  (semantic: Trans_02205cc4)
extern "C" ARM unsigned int func_ov031_02205cc4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3, unsigned int a10) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    unsigned int r7 = 0;
    r7 = r0;
    r6 = r1;
    r5 = r2;
    r0 = (unsigned int)&func_ov031_02205d10;
    r1 = r7;
    r2 = 0x1;
    r4 = r3;
    r0 = (unsigned int)SetLookupFields_02205134((void*)r0, (void*)r1, (int)r2);
    r1 = r0;
    *(unsigned int*)((char*)r1 + 0x10) = (unsigned int)r6;
    *(unsigned int*)((char*)r1 + 0x14) = (unsigned int)r5;
    r2 = a10;
    *(unsigned int*)((char*)r1 + 0x18) = (unsigned int)r4;
    r0 = r7;
    *(unsigned int*)((char*)r1 + 0x1c) = (unsigned int)r2;
    r0 = (unsigned int)TailCall0220520cField64_0220527c((Obj0220527c*)r0, (void*)r1);
    return r0;
}
