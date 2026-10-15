#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj021fce28 {
    char pad[0x20];
    Object3D model;
};

// USA: func_ov023_021fce28
ARM void TailCallOffset20_021fce28(void *obj, int a1, int a2, int a3) {
    ((Obj021fce28 *)obj)->model.Initialize();
}
