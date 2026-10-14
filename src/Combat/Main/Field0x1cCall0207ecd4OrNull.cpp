#include <globaldefs.h>

struct Obj0207ecd4;
extern "C" void* _ZN7Model3D21RestageTexturePaletteEv(struct Obj0207ecd4*);

// USA: func_02055624
ARM void* Field0x1cCall0207ecd4OrNull_02055624(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return _ZN7Model3D21RestageTexturePaletteEv((struct Obj0207ecd4*)x);
}
