#include <globaldefs.h>
#include "System/Matrix.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "Graphics/NSBXX/GeometryFifo.h"

struct Container02057a6c;

extern "C" void __clear(void* ptr, int size);
extern "C" void _Z29CopyVec3sAndDispatch_02196048PiS_S_(Vector3fix* eye, Vector3fix* up, Vector3fix* target);
extern "C" Container02057a6c* func_02057924(void);
extern "C" int func_020ca4b4(const void* src, void* dst, int size);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void _Z34UpdateEntriesWhereFlag2Set02057a6cP17Container02057a6c(Container02057a6c* c);
extern "C" void _Z28ForwardObjAndField0_021a3af0i(int obj);

extern const Vector3fix data_ov017_021d6420;
extern const Vector3fix data_ov017_021d642c;

struct Battle02195ecc {
    unsigned int flags[2];
    char pad8[0x36fc - 0x8];
    int nodeList;
};

// USA: func_ov017_02195ecc
extern "C" ARM void func_ov017_02195ecc(Battle02195ecc* self, unsigned int mode) {
    if (mode == 0) {
        return;
    }

    Vector3fix savedEye = data_0210a010.eyeVector;
    Vector3fix savedUp = data_0210a010.upVector;
    Vector3fix savedTarget = data_0210a010.targetVector;
    Matrix4x4 savedProjection = data_0210a010.projectionMatrix;
    Vector3fix eye = data_ov017_021d6420;
    Vector3fix target;
    __clear(&target, sizeof(target));
    Vector3fix up = data_ov017_021d642c;

    Mat4x4_WriteProjectionUnknown(0xe000, -0x22000, -0x20000, 0x20000, 0x1000, 0x190000, 0x1000,
                                  &data_0210a010.projectionMatrix);
    data_0210a010.flags &= ~((1 << RENDER_CONFIG_FLAG_4) | (1 << RENDER_CONFIG_FLAG_6));
    _Z29CopyVec3sAndDispatch_02196048PiS_S_(&eye, &up, &target);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();

    if (mode & 1) {
        Container02057a6c* entries = func_02057924();
        if (GetBitsInField4(self->flags, 0x20) == 0) {
            _Z34UpdateEntriesWhereFlag2Set02057a6cP17Container02057a6c(entries);
        }
    }
    if (mode & 2) {
        _Z28ForwardObjAndField0_021a3af0i(self->nodeList);
    }

    _Z29CopyVec3sAndDispatch_02196048PiS_S_(&savedEye, &savedUp, &savedTarget);
    func_020ca4b4(&savedProjection, &data_0210a010.projectionMatrix, sizeof(Matrix4x4));
    data_0210a010.flags &= ~((1 << RENDER_CONFIG_FLAG_4) | (1 << RENDER_CONFIG_FLAG_6));
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
}
