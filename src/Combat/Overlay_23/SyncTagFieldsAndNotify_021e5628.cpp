#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/NSBXX/GeometryFifo.h"

unsigned short (*GetVariantShortTable02109928_02099cac(void))[2];
int CallWithAddr4000330_020c555c(int a);
extern "C" void func_02031234(int angle);

extern char data_ov023_021fdcef;
extern char data_ov023_021fdcf4;
extern char data_ov023_021fdcfa;
extern char data_ov023_021fdd00;
extern char data_ov023_021fdd08;
extern char data_ov023_021fdd10;

struct TagObj021e5628 {
    Object3D field0;
    Object3D fieldAc;
    Object3D field158;
    Object3D field204;
    Object3D field2b0;
    Object3D field35c;
    Object3D field408;
    Object3D field4b4;
    Object3D field560;
    Object3D field60c;
    unsigned char pad3[0xc10 - 0x6b8];
    unsigned char field_c10;
    unsigned char pad4[0xc12 - 0xc11];
    unsigned char field_c12;
    unsigned char pad5[0xc14 - 0xc13];
    unsigned char field_c14;
};

struct CtxObj021e5628 {
    Object3D* field0;
    Object3D* field4;
};

// USA: func_ov023_021e5628  (semantic: SyncTagFieldsAndNotify_021e5628)
extern "C" ARM void func_ov023_021e5628(TagObj021e5628* obj, CtxObj021e5628* ctx) {
    if (obj->field_c12 != 0) return;
    if (obj->field_c14 == 0) return;

    unsigned short (*table)[2] = GetVariantShortTable02109928_02099cac();
    if (table == 0) return;

    unsigned short v = *(unsigned short*)((char*)table + 0x128);
    unsigned short buf[8] = {v, v, v, v, v, v, v, v};
    CallWithAddr4000330_020c555c((int)buf);

    if (obj->field0.unknown_2_ >= 0) {
        obj->field0.AdvanceEffects();
        fix32_t f1c = obj->field0.animationTime_;
        obj->field408.SetCurrentAnimationTime(f1c);
        obj->fieldAc.SetCurrentAnimationTime(f1c);
        obj->field35c.SetCurrentAnimationTime(f1c);
    }
    if (obj->field0.unknown_2_ <= -1) return;

    obj->field0.Draw(true);

    Model3D* strObj;
    Model3D* p = *(Model3D**)((char*)obj + 8);
    if (p == 0) goto skipMessages;
    if (!p->unknown_flags_a8_0_) p = 0;
    if (p == 0) goto skipMessages;

    {
        strObj = obj->field0.pModel_;
        if (strObj == 0) return;

        int boneIndex = strObj->GetBoneIndex(&data_ov023_021fdcef);
        if (boneIndex > -1) {
            GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
            if (ctx != 0 && ctx->field4 != 0) {
                ctx->field4->DrawSimple2(false);
            }
            obj->field158.SendTransformToFifo();
            obj->field158.DrawSimple2(false);
            obj->field204.DrawSimple2(false);
            obj->field4b4.DrawSimple2(false);

            if (obj->field_c10 != 0) {
                boneIndex = strObj->GetBoneIndex(&data_ov023_021fdcf4);
                if (boneIndex > -1 && obj->field560.unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
                    obj->field560.DrawSimple2(false);
                }
                boneIndex = strObj->GetBoneIndex(&data_ov023_021fdcfa);
                if (boneIndex > -1 && obj->field560.unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
                    func_02031234(0x3244);
                    obj->field560.DrawSimple2(false);
                }
            } else {
                boneIndex = strObj->GetBoneIndex(&data_ov023_021fdd00);
                if (boneIndex > -1 && obj->field560.unknown_2_ > -1) {
                    GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
                    obj->field560.DrawSimple2(false);
                }
            }

            boneIndex = strObj->GetBoneIndex(&data_ov023_021fdd08);
            if (boneIndex > -1 && obj->field60c.unknown_2_ > -1) {
                GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
                obj->field60c.DrawSimple2(false);
            }

            if (ctx != 0 && ctx->field0 != 0) {
                boneIndex = strObj->GetBoneIndex(&data_ov023_021fdd10);
                if (boneIndex > -1) {
                    GetModelBonePositionAndDirectionMatrices(&p->renderContext_, 0, 0, boneIndex);
                    ctx->field0->DrawSimple2(false);
                }
            }
        }
    }

skipMessages:
    obj->field0.ApplyAnimations(&obj->field408);
    obj->field408.Draw(true);
    obj->field0.ApplyAnimations(&obj->fieldAc);
    obj->fieldAc.Draw(true);
    obj->field0.ApplyAnimations(&obj->field35c);
    obj->field35c.Draw(true);
}
