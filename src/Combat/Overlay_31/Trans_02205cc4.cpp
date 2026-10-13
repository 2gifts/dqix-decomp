#include <globaldefs.h>

extern int func_ov031_02205d10;
void* SetLookupFields_02205134(void*, void*, int);
struct Obj0220527c;
int TailCall0220520cField64_0220527c(Obj0220527c*, void*);

struct LookupRecord {
    char pad[0x10];
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
};

// USA: func_ov031_02205cc4  (semantic: Trans_02205cc4)
extern "C" ARM int func_ov031_02205cc4(Obj0220527c* obj, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    LookupRecord* rec = (LookupRecord*)SetLookupFields_02205134(&func_ov031_02205d10, obj, 1);
    rec->f10 = a;
    rec->f14 = b;
    rec->f18 = c;
    rec->f1c = d;
    return TailCall0220520cField64_0220527c(obj, rec);
}
