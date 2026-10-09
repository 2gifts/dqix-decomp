#include <globaldefs.h>
#include "World/LootableContainer.h"
#include "World/Zone3D.h"
#include "System/Matrix.h"

extern "C" void _Z26ResetGxEngineState020c52e8v();
extern "C" void func_020c5414();
void SubmitGeometryJob(int, int, int, int, void*);
extern "C" void _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(int, int, int, int, int, int, int, int, void*);
extern "C" int func_02015ef4(Zone3D*, int);
extern const Vector3fix data_020e6e08;
extern const Vector3fix data_020e6e14;

// USA: func_020158cc
extern "C" ARM void func_020158cc(Zone3D* self) {
    if (LootableContainerManager::GetMainInstance() != NULL &&
        self->pUnknownStruct_8_ != NULL) {
        Vector3fix target = data_020e6e08;
        Vector3fix eye = {0};
        Vector3fix up = data_020e6e14;
        _Z26ResetGxEngineState020c52e8v();
        func_020c5414();
        *(volatile unsigned int*)0x04000440 = 0;
        SubmitGeometryJob((int)&eye, (int)&up, (int)&target, 1, NULL);
        _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(0, 0xc0000, 0, 0x100000,
            -0x400000, 0x400000, 0x400000, 1, NULL);
        *(volatile unsigned int*)0x04000440 = 2;
        for (int i = 0; i < self->numChests_; ++i)
            func_02015ef4(self, i);
    }
}
