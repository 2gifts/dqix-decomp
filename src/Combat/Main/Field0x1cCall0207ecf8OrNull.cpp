#include <globaldefs.h>
#include "Graphics/Model3D.h"

// USA: func_0205560c
ARM void Field0x1cCall0207ecf8OrNull_0205560c(void* obj) {
    Model3D* x = *(Model3D**)((char*)obj + 0x1c);
    if (x != NULL)
        x->RestageTextureImage();
}
