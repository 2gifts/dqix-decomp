#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Elem0218cc24 {
    int head[2];
    unsigned int lo : 4;
    unsigned int kind : 5;
};

struct Obj0218cc24 {
    void* container;
    int** pairsRoot;
    SafeAllocator* allocs;
    void* pathStr;
    char pad10[0x20 - 0x10];
    int* ids;
    Object3D* ents;
    char pad28[4];
    unsigned char state;
    char pad2d[0x3c - 0x2d];
    unsigned char c3c;
    unsigned char c3d;
    unsigned char c3e;
    char pad3f;
    short s40;
    short s42;
    char pad44[0x50 - 0x44];
    unsigned char boneIdx;
    char pad51[3];
    int f54;
    Object3D* GetEnt(int i) { return &ents[i]; }
};

extern "C" void _ZN8Vector3iaSERKS_(void* dst, const void* src);
extern "C" void _Z17DelayThenSyncBit0v();
extern "C" void _Z24ResetObjectState02079a3cPv(void*);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(char*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" void* _Z24FindElementByKey020dedd0P17Container020dedd0i(void*, int);
extern "C" int func_ov015_0218c03c(void* self, char* buf, int i, int one);
extern "C" void func_ov015_0218c538(void* self, int zero);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_02099e18(void* a, int b, int c, int d);
extern "C" void _Z13SetFields0x44P14Fields020407b4iii(Object3D*, int, int, int);
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(void*, const char*);
extern "C" void _ZN7Model3D14RemoveTexturesEv(void*);
extern "C" void _ZN7Model3D22ApplyTexturesFromModelEPS_(void*, void*);
extern "C" void _ZN7Model3D33CreateBoneMatrixAndMaterialArraysEP13SafeAllocatori(void*, SafeAllocator*, int);
extern "C" void _ZN7Model3D39StoreBoneMatrixAndMaterialArrayPointersEv(void*);
extern "C" int fix32_Divide(int, int);

extern int data_0211e33c __attribute__((aligned(4)));
extern char data_ov015_021940c0;
extern char data_ov015_021940db;
extern char data_ov015_021940e1;
extern char data_ov015_021940e7;
extern int data_ov015_02193d48[];
extern char data_ov015_021940ed;

// USA: func_ov015_0218cc24
extern "C" ARM int func_ov015_0218cc24(Obj0218cc24* self) {
    int off70;
    char* pairs;
    bool changed;
    int off14;
    SafeAllocator* alloc;
    short id;

    _Z17DelayThenSyncBit0v();
    id = self->GetEnt(7)->unknown_2_;
    if (self->ids[7] != id) {
        self->GetEnt(3)->unknown_2_ = -1;
        self->GetEnt(4)->unknown_2_ = -1;
    }
    id = self->GetEnt(1)->unknown_2_;
    if (self->ids[1] != id) {
        self->GetEnt(0)->unknown_2_ = -1;
    }
    changed = false;
    id = self->GetEnt(8)->unknown_2_;
    if (self->ids[8] != id ||
        self->ids[1] != (id = self->GetEnt(1)->unknown_2_) ||
        self->ids[6] != (id = self->GetEnt(6)->unknown_2_)) {
        changed = true;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    unsigned int size = 0;
    char* buf = (char*)&data_0211e33c;
    unsigned int room = 0x30000;
    GPCReadPair pair;
    char name[0x80];
    _Z24ResetObjectState02079a3cPv(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_021940c0,
                                                   buf, size, room, false, 0)) {
        buf += size;
        room -= size;
        for (int i = 0; i < 10; i++) {
            if (self->state != 2 && self->ids[i] == (id = self->ents[i].unknown_2_)) {
                continue;
            }
            Vector3fix savedPos = self->ents[i].position_;
            pairs = (char*)*self->pairsRoot;
            off70 = i * 0x70;
            alloc = self->allocs;
            off14 = i * 0x14;
            ((SafeAllocator*)((char*)alloc + off14))->Reset();
            _Z26CopyInternalFields0207df50P11Foo0207df50(pairs + off70);
            self->ents[i].Initialize();
            _ZN8Vector3iaSERKS_(&self->ents[i].position_, &savedPos);
            self->ents[i].unknown_2_ = self->ids[i];
            if (self->ids[i] < 0) {
                continue;
            }
            Elem0218cc24* elem = (Elem0218cc24*)_Z24FindElementByKey020dedd0P17Container020dedd0i(
                (char*)self->container + 0x4c, (short)self->ids[i]);
            if (elem == 0) {
                continue;
            }
            if (func_ov015_0218c03c(self, name, i, 1) == 0) {
                continue;
            }
            self->ents[i].Destroy();
            if (!(i != 0 && i != 1)) {
                int a = FxMul(self->s40, self->s42);
                short sx = (int)(0.065f * (float)a);
                short sy = (int)(0.065f * (float)self->s40);
                self->ents[i].SetScale(sx, sy, sx);
                changed = true;
            } else if (!(i != 2 && i != 3 && i != 7 && i != 8 && i != 9)) {
                int sx = fix32_Divide(0x1000, FxMul(self->s40, self->s42));
                int sy = fix32_Divide(0x1000, self->s40);
                int sz = sx;
                if (!(i != 2 && i != 3 && i != 7)) {
                    sx = (int)(((long long)sx * (int)((float)self->s40 - 0.5f * (float)(self->s40 - 0x1000)) + 0x800) >> 12);
                    sy = (int)(((long long)sy * (int)((float)self->s40 - 0.5f * (float)(self->s40 - 0x1000)) + 0x800) >> 12);
                    sz = (int)(((long long)sz * (int)((float)self->s40 - 0.5f * (float)(self->s40 - 0x1000)) + 0x800) >> 12);
                }
                self->ents[i].SetScale(sx, sy, sz);
                if (i == 8) {
                    void* m = self->GetEnt(0)->pModel_;
                    self->f54 = 0;
                    if (elem->kind == 4) {
                        _Z13SetFields0x44P14Fields020407b4iii(&self->ents[i], 0, 0, 0);
                        if (m) {
                            self->boneIdx = _ZN7Model3D12GetBoneIndexEPKc(m, &data_ov015_021940db);
                        }
                    } else if (elem->kind == 6) {
                        _Z13SetFields0x44P14Fields020407b4iii(&self->ents[i], 0, 0, 0);
                        if (m) {
                            self->boneIdx = _ZN7Model3D12GetBoneIndexEPKc(m, &data_ov015_021940e1);
                        }
                        self->f54 = 1;
                    } else {
                        if (elem->kind == 0xb) {
                            short v = self->s40;
                            int x = (int)(((long long)v * 9830LL + 0x800) >> 12);
                            int y = (int)(((long long)v * -1638LL + 0x800) >> 12);
                            _Z13SetFields0x44P14Fields020407b4iii(&self->ents[i], x, y, 0);
                            if (m) {
                                self->boneIdx = _ZN7Model3D12GetBoneIndexEPKc(m, &data_ov015_021940e7);
                            }
                        } else {
                            short v = self->s40;
                            int x = (int)(((long long)v * -9830LL + 0x800) >> 12);
                            int y = (int)(((long long)v * -1638LL + 0x800) >> 12);
                            _Z13SetFields0x44P14Fields020407b4iii(&self->ents[i], x, y, 0);
                            if (m) {
                                self->boneIdx = _ZN7Model3D12GetBoneIndexEPKc(m, &data_ov015_021940e1);
                            }
                        }
                    }
                }
                if (i == 9) {
                    short v = self->s40;
                    _Z13SetFields0x44P14Fields020407b4iii(&self->ents[i], (int)(((long long)v * 0x2000LL + 0x800) >> 12), 0, 0);
                }
            }
            _Z25RestorePairTables0207df90Pc(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, room, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + off14), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            room -= size;
            _Z24BackupPairTables0207dfacPc(pairs + off70);
            if (i == 4 && self->GetEnt(3)->pModel_ != 0) {
                _ZN7Model3D22ApplyTexturesFromModelEPS_(self->GetEnt(3)->pModel_, self->ents[i].pModel_);
            }
            void* model = self->ents[i].pModel_;
            if (model == 0) {
                continue;
            }
            if (i == 0) {
                _ZN7Model3D33CreateBoneMatrixAndMaterialArraysEP13SafeAllocatori(model, (SafeAllocator*)((char*)alloc + off14), 7);
                _ZN7Model3D39StoreBoneMatrixAndMaterialArrayPointersEv(model);
            } else if (!(i == 1 || i == 6 || i == 5 || i == 4)) {
                _ZN7Model3D33CreateBoneMatrixAndMaterialArraysEP13SafeAllocatori(model, (SafeAllocator*)((char*)alloc + off14), 5);
                _ZN7Model3D39StoreBoneMatrixAndMaterialArrayPointersEv(model);
            }
        }
        pair.Reset();
    }
    if (changed) {
        func_ov015_0218c538(self, 0);
    }
    void* m0 = self->GetEnt(0)->pModel_;
    if (m0) {
        _ZN7Model3D14RemoveTexturesEv(m0);
        if (self->GetEnt(5)->unknown_2_ >= 0 && self->GetEnt(5)->pModel_) {
            _ZN7Model3D22ApplyTexturesFromModelEPS_(m0, self->GetEnt(5)->pModel_);
        }
        _ZN7Model3D22ApplyTexturesFromModelEPS_(m0, m0);
    }
    void* m1 = self->GetEnt(1)->pModel_;
    if (m1) {
        _ZN7Model3D14RemoveTexturesEv(m1);
        if (self->GetEnt(6)->unknown_2_ >= 0 && self->GetEnt(6)->pModel_) {
            _ZN7Model3D22ApplyTexturesFromModelEPS_(m1, self->GetEnt(6)->pModel_);
        }
        _ZN7Model3D22ApplyTexturesFromModelEPS_(m1, m1);
    }
    func_02099e18(self->GetEnt(2)->pModel_, self->c3e, self->c3c, self->c3d);
    for (int k = 0; data_ov015_02193d48[k] >= 0; k++) {
        func_ov015_0218c3a4(self, data_ov015_02193d48[k]);
    }
    BackgroundLoader::RemoveLockGlobal();
    self->state = 0;
    self->pathStr = &data_ov015_021940ed;
    int result = 1;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
    return result;
}
