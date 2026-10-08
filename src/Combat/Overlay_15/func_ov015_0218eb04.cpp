#include <globaldefs.h>
#include <std_library_functions.h>
#include "World/Object3D.h"
#include "Graphics/NSBXX/GeometryFifo.h"

extern "C" void __clear(void* buffer, unsigned long size);

struct CharacterColors
{
    unsigned short hair_[10][2];
    unsigned short colors2_[8][2];
    unsigned short colors4_[8][4];
    unsigned short colors8_[8][8];
    unsigned short skin_[8][2];
    unsigned short edge_;
};

struct ViewObject
{
    char unk_0[0x24];
    Object3D* objects_;
    char unk_28[0x34 - 0x28];
    unsigned short triangles_;
    unsigned short quads_;
};

struct DollAnimated
{
    int animated_[9];
};

struct DollBones
{
    char names_[9][0x14];
};

CharacterColors* GetVariantShortTable02109928();
int CallWithAddr4000330(int a);
ModelRenderContext* GetModel3DContext(Model3D* model);

extern const DollBones data_ov015_02193ee8;
extern const DollAnimated data_ov015_02193d9c;

// USA: func_ov015_0218eb04
extern "C" ARM void func_ov015_0218eb04(ViewObject* self)
{
    unsigned short edge = GetVariantShortTable02109928()->edge_;
    unsigned short edges[8] = {edge, edge, edge, edge, edge, edge, edge, edge};
    CallWithAddr4000330((int)edges);
    self->quads_ = 0;
    self->triangles_ = 0;
    Model3D* model = self->objects_->pModel_;
    if (model == NULL)
        return;
    ModelRenderContext* context = GetModel3DContext(model);
    if (context == NULL)
        return;
    Object3D* parts[10];
    __clear(parts, sizeof(parts));
    parts[0] = &self->objects_[0];
    parts[1] = &self->objects_[2];
    parts[2] = &self->objects_[3];
    parts[3] = &self->objects_[7];
    parts[4] = &self->objects_[8];
    parts[5] = &self->objects_[9];
    parts[6] = &self->objects_[6];
    parts[7] = &self->objects_[5];
    parts[8] = &self->objects_[1];
    DollBones bones = data_ov015_02193ee8;
    DollAnimated animated = data_ov015_02193d9c;
    for (int i = 0; parts[i] != NULL; i++)
    {
        Object3D* part = parts[i];
        if (part->unknown_2_ >= 0)
        {
            if (strlen(bones.names_[i]) != 0)
            {
                GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, model->GetBoneIndex(bones.names_[i]));
                part->EnableFlag(0x4000);
            }
            if (animated.animated_[i])
                self->objects_->ApplyAnimations(part);
            part->Draw(true);
        }
    }
}
