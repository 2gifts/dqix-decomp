#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

extern "C" void* func_ov017_0218b5b0(void* p);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void* _ZN7Model3D23SetMaterialDiffuseColorEj(void* p, int v);

struct Vec3Block020b3850;
extern "C" void _ZN12RenderConfig17SetObjectPositionEP8Vector3i(struct Vec3Block020b3850* src);

struct Vec3Block020b3880;
extern "C" void _ZN12RenderConfig14SetObjectScaleEP8Vector3i(struct Vec3Block020b3880* src);

extern "C" void Mat3x3_WriteIdentity(void* p);
extern "C" void func_020ca528(void* a, void* b);
extern int data_0210a0cc;

struct S02037418;
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);

struct FlagRegs0208f87c { unsigned char pad[0xfc]; unsigned int flags; };
extern struct FlagRegs0208f87c data_0210a010;

extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);

struct Battler02035e1c;
extern "C" int _ZN8Object3D26DrawMeshWithMaterialSimpleEbiii(struct Battler02035e1c* a, int b, int c, int d, int e);

// JPN: 0x02090190
// USA: func_0208f87c
ARM void SyncBattleState0208f87c(void* self, int b, int c, int d) {
    void* ov = func_ov017_0218b5b0(self);
    void* r4 = *(void**)((char*)ov + (IS_JPN ? 0x34bc : 0x36cc));
    if (GetBitsInField4((unsigned int*)ov, 0x200400) != 0) {
        return;
    }
    if (*(void**)((char*)r4 + 0x8) == 0) {
        return;
    }
    _ZN7Model3D23SetMaterialDiffuseColorEj(*(void**)((char*)r4 + 0x8), b);
    _ZN12RenderConfig17SetObjectPositionEP8Vector3i((struct Vec3Block020b3850*)self);
    unsigned int vec[3] = { (unsigned int)c, (unsigned int)c, (unsigned int)c };
    _ZN12RenderConfig14SetObjectScaleEP8Vector3i((struct Vec3Block020b3880*)vec);
    char buf1[0x24];
    Mat3x3_WriteIdentity(buf1);
    func_020ca528(buf1, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    _ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)r4, d);
    _ZN12RenderConfig12SubmitToFifoEv();
    _ZN8Object3D26DrawMeshWithMaterialSimpleEbiii((struct Battler02035e1c*)r4, 0, 0, 0, 1);
}
