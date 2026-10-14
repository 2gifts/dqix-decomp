#include <globaldefs.h>

struct Obj0207ecf8;
extern "C" void* _ZN7Model3D19RestageTextureImageEv(struct Obj0207ecf8*);

// USA: func_0205560c
ARM void* Field0x1cCall0207ecf8OrNull_0205560c(void* obj) {
    void* x = *(void**)((char*)obj + 0x1c);
    if (x == NULL) return x;
    return _ZN7Model3D19RestageTextureImageEv((struct Obj0207ecf8*)x);
}
