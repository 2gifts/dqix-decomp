#include <globaldefs.h>

#include <World/Object3D.h>
#include <Graphics/NSBXX/RenderConfig.h>

#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

extern "C" void* func_ov017_0218b5b0(void* p);
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);

extern "C" void func_020ca528(void* a, void* b);
extern int data_0210a0cc;

// USA: func_0208f87c
ARM void SyncBattleState0208f87c(void* self, int b, int c, int d) {
    void* ov = func_ov017_0218b5b0(self);
    Object3D* r4 = *(Object3D**)((char*)ov + (IS_JPN ? 0x34bc : 0x36cc));
    if (GetBitsInField4_0203b4fc((unsigned int*)ov, 0x200400) != 0) {
        return;
    }
    if (r4->pModel_ == 0) {
        return;
    }
    r4->pModel_->SetMaterialDiffuseColor(b);
    RenderConfig::SetObjectPosition((Vector3i*)self);
    Vector3i vec = { c, c, c };
    RenderConfig::SetObjectScale(&vec);
    Matrix3x3 buf1;
    Mat3x3_WriteIdentity(&buf1);
    func_020ca528(&buf1, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    r4->SetInheritedAlpha(d);
    RenderConfig::SubmitToFifo();
    r4->DrawMeshWithMaterialSimple(0, 0, 0, 1);
}
