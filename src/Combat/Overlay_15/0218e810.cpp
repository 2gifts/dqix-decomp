#include <globaldefs.h>
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "System/Graphics.h"

ModelRenderContext* GetModel3DContext(Model3D* model);
extern "C" void func_02031234(int angle);

struct ViewerDrawState0218e810
{
    char* viewer_;
    ViewerSlot* slot_;
    SafeAllocator* allocators_;
    const char* name_;
    void* monster_;
    void* buffer_;
    unsigned int bufferSize_;
    unsigned char kind_;
    char unknown1d_[3];
    int* parts_;
    Object3D* objects_;
    Struct205563c* effect_;
    char unknown2c_[8];
    unsigned short triangles_;
    unsigned short quads_;
    short motion_;
    unsigned char unknown3a_;
    unsigned char flag3b_;
    char unknown3c_[0xc];
    int field48_;
    char unknown4c_[8];
    int mirrorPart_;
    char unknown58_[4];
};

struct ModelPartBone0218e810
{
    int object_;
    int bone_;
};

struct ModelPartBindings0218e810
{
    ModelPartBone0218e810 entries_[6];
};

extern const ModelPartBindings0218e810 data_ov015_02193dc0;
extern const char data_ov015_0219416b[];
extern const char data_ov015_021940e7[];
extern const char data_ov015_021940e1[];
extern const char data_ov015_02194170[];
extern const char data_ov015_02194176[];

// USA: func_ov015_0218e810
extern "C" ARM void func_ov015_0218e810(void* object)
{
    int head;
    ModelRenderContext* context;
    int armLeft;
    int armRight;
    Model3D* model;
    Object3D* root;
    ViewerDrawState0218e810* self;
    self = (ViewerDrawState0218e810*)object;
    self->triangles_ = self->quads_ = 0;
    root = self->objects_;
    model = self->objects_->pModel_;
    if (model == NULL)
        return;
    context = GetModel3DContext(model);
    if (context == NULL)
        return;
    GXFIFO_MATRIX_PUSH = 0;
    root->Draw(true);
    if (root->pModel_ != NULL && root->pModel_->rawInternalModel_ != NULL)
    {
        self->triangles_ += root->pModel_->rawInternalModel_->numTriangles_;
        self->quads_ += root->pModel_->rawInternalModel_->numQuads_;
    }
    GXFIFO_MATRIX_POP = 1;
    head = model->GetBoneIndex(data_ov015_0219416b);
    armLeft = model->GetBoneIndex(data_ov015_021940e7);
    armRight = model->GetBoneIndex(data_ov015_021940e1);
    model->GetBoneIndex(data_ov015_02194170);
    model->GetBoneIndex(data_ov015_02194176);
    ModelPartBindings0218e810 bindings = data_ov015_02193dc0;
    bindings.entries_[0].bone_ = head;
    bindings.entries_[1].bone_ = head;
    bindings.entries_[2].bone_ = head;
    bindings.entries_[3].bone_ = armLeft;
    bindings.entries_[4].bone_ = armRight;
    for (ModelPartBone0218e810* binding = bindings.entries_; binding->object_ >= 0; binding++)
    {
        Object3D* part = &self->objects_[binding->object_];
        int bone = binding->bone_;
        if (part->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, bone);
            GXFIFO_MATRIX_PUSH = 0;
            part->DrawSimple3(false);
            if (part->pModel_ != NULL && part->pModel_->rawInternalModel_ != NULL)
            {
                self->triangles_ += part->pModel_->rawInternalModel_->numTriangles_;
                self->quads_ += part->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    if (self->mirrorPart_ != 0)
    {
        Object3D* part = &self->objects_[8];
        if (part->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, armLeft);
            GXFIFO_MATRIX_PUSH = 0;
            func_02031234(0x3244);
            part->DrawSimple2(false);
            if (part->pModel_ != NULL && part->pModel_->rawInternalModel_ != NULL)
            {
                self->triangles_ += part->pModel_->rawInternalModel_->numTriangles_;
                self->quads_ += part->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    GXFIFO_MATRIX_PUSH = 0;
    if (root[1].unknown_2_ >= 0)
    {
        root->ApplyAnimations(&root[1]);
        root[1].Draw(false);
        if (root[1].pModel_ != NULL && root[1].pModel_->rawInternalModel_ != NULL)
        {
            self->triangles_ += root->pModel_->rawInternalModel_->numTriangles_;
            self->quads_ += root->pModel_->rawInternalModel_->numQuads_;
        }
    }
    GXFIFO_MATRIX_POP = 1;
}
