#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj_021588bc {
    int f0;
    int f4;
};

extern "C" void func_ov001_02158880(struct Obj_021588bc* obj);
extern "C" int func_ov001_021588e4(struct Obj_021588bc* obj);

// USA: func_ov001_021588bc
ARM int InitObjFields_021588bc(struct Obj_021588bc* obj, int a, int b) {
    func_ov001_02158880(obj);
    obj->f0 = a;
    obj->f4 = b;
    return func_ov001_021588e4(obj);
}
