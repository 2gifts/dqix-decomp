#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct ViewObject
{
    char unk_0[0x24];
    Object3D* objects_;
    char unk_28[0x34 - 0x28];
    unsigned short triangles_;
    unsigned short quads_;
};

// USA: func_ov015_0218edcc
extern "C" ARM void func_ov015_0218edcc(ViewObject* self)
{
    GXFIFO_MATRIX_PUSH = 0;
    self->objects_->Draw(false);
    RenderConfig::SubmitToFifo();
    GXFIFO_MATRIX_POP = 1;
    self->triangles_ = self->quads_ = 0;
    self->triangles_ = self->objects_->pModel_->rawInternalModel_->numTriangles_;
    self->quads_ = self->objects_->pModel_->rawInternalModel_->numQuads_;
}
