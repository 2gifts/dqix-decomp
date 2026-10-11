#include <globaldefs.h>

unsigned short (*GetVariantShortTable02109928(void))[2];
int CallWithAddr4000330(int a);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void* obj);
struct S1a0;
extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(struct S1a0* obj, unsigned int v);
extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);
struct Struct0207ea38;
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(struct Struct0207ea38* obj, char* str);
extern "C" int _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(void* a0, void* a1, void* a2, unsigned int a3);
struct S02035d44;
extern "C" int _ZN8Object3D11DrawSimple2Eb(struct S02035d44* obj, int arg);
extern "C" void _ZN8Object3D19SendTransformToFifoEv(void* obj);
extern "C" void func_02031234(int angle);
extern "C" void _ZN8Object3D15ApplyAnimationsEPS_(void* obj, void* child);

extern char data_ov023_021fdcef;
extern char data_ov023_021fdcf4;
extern char data_ov023_021fdcfa;
extern char data_ov023_021fdd00;
extern char data_ov023_021fdd08;
extern char data_ov023_021fdd10;

struct TagObj021e5628 {
    unsigned char pad0[0x2];
    short field2;
    unsigned char pad1[0x8 - 0x4];
    void* field8;
    unsigned char pad2[0x1c - 0xc];
    unsigned int field1c;
    unsigned char pad3[0xc10 - 0x20];
    unsigned char field_c10;
    unsigned char pad4[0xc12 - 0xc11];
    unsigned char field_c12;
    unsigned char pad5[0xc14 - 0xc13];
    unsigned char field_c14;
};

struct CtxObj021e5628 {
    void* field0;
    void* field4;
};

struct FlagObjA8_021e5628 {
    unsigned char pad[0xa8];
    int flagA8 : 1;
};

// USA: func_ov023_021e5628  (semantic: SyncTagFieldsAndNotify_021e5628)
extern "C" ARM void func_ov023_021e5628(TagObj021e5628* obj, CtxObj021e5628* ctx) {
    if (obj->field_c12 != 0) return;
    if (obj->field_c14 == 0) return;

    unsigned short (*table)[2] = GetVariantShortTable02109928();
    if (table == 0) return;

    unsigned short v = *(unsigned short*)((char*)table + 0x128);
    unsigned short buf[8] = {v, v, v, v, v, v, v, v};
    CallWithAddr4000330((int)buf);

    if (obj->field2 >= 0) {
        _ZN8Object3D14AdvanceEffectsEv(obj);
        unsigned int f1c = obj->field1c;
        _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)((char*)obj + 0x408), f1c);
        _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)((char*)obj + 0xac), f1c);
        _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)((char*)obj + 0x35c), f1c);
    }
    if (obj->field2 <= -1) return;

    _ZN8Object3D4DrawEb(obj, 1);

    struct Struct0207ea38* strObj;
    void* p = *(void**)((char*)obj + 8);
    if (p == 0) goto skipMessages;
    if (!((struct FlagObjA8_021e5628*)p)->flagA8) p = 0;
    if (p == 0) goto skipMessages;

    {
        strObj = (struct Struct0207ea38*)obj->field8;
        if (strObj == 0) return;

        int r = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdcef);
        if (r > -1) {
            _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r);
            if (ctx != 0 && ctx->field4 != 0) {
                _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)ctx->field4, 0);
            }
            _ZN8Object3D19SendTransformToFifoEv((char*)obj + 0x158);
            _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x158), 0);
            _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x204), 0);
            _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x4b4), 0);

            if (obj->field_c10 != 0) {
                int r2 = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdcf4);
                if (r2 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r2);
                    _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x560), 0);
                }
                int r3 = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdcfa);
                if (r3 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r3);
                    func_02031234(0x3244);
                    _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x560), 0);
                }
            } else {
                int r4 = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdd00);
                if (r4 > -1 && *(short*)((char*)obj + 0x562) > -1) {
                    _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r4);
                    _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x560), 0);
                }
            }

            int r5 = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdd08);
            if (r5 > -1 && *(short*)((char*)obj + 0x60e) > -1) {
                _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r5);
                _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)((char*)obj + 0x60c), 0);
            }

            if (ctx != 0 && ctx->field0 != 0) {
                int r6 = _ZN7Model3D12GetBoneIndexEPKc(strObj, &data_ov023_021fdd10);
                if (r6 > -1) {
                    _Z40GetModelBonePositionAndDirectionMatricesP18ModelRenderContextP9Matrix4x3P9Matrix3x3j(p, 0, 0, r6);
                    _ZN8Object3D11DrawSimple2Eb((struct S02035d44*)ctx->field0, 0);
                }
            }
        }
    }

skipMessages:
    _ZN8Object3D15ApplyAnimationsEPS_(obj, (char*)obj + 0x408);
    _ZN8Object3D4DrawEb((char*)obj + 0x408, 1);
    _ZN8Object3D15ApplyAnimationsEPS_(obj, (char*)obj + 0xac);
    _ZN8Object3D4DrawEb((char*)obj + 0xac, 1);
    _ZN8Object3D15ApplyAnimationsEPS_(obj, (char*)obj + 0x35c);
    _ZN8Object3D4DrawEb((char*)obj + 0x35c, 1);
}
