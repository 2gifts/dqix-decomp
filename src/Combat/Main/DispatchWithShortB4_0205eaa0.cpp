#include <globaldefs.h>

#if defined(jpn)
#endif
extern "C" void func_0203ac40(void*, int, int, int);

struct Obj0205eaa0 {
    char pad_00[0xb4];
    short field_b4;
};

// USA: func_0205eaa0
ARM void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b) {
    func_0203ac40(obj, obj->field_b4, a, b);
}
