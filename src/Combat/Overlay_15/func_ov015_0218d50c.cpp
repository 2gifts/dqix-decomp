#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Elem0218d50c {
    int head[2];
    unsigned int lo : 4;
    unsigned int kind : 5;
};

struct Obj0218d50c {
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
    char pad44[0x58 - 0x44];
    int f58;
    Object3D* GetEnt(int i) { return &ents[i]; }
};

struct Vector3i;
void DelayThenSyncBit0_020c9820();
void ResetObjectState02079a3c(void*);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
struct Container020dedd0;
void* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" int func_ov015_0218c03c(void* self, char* buf, int i, int one);
extern "C" void func_ov015_0218c3a4(void* self, int v);
extern "C" void func_ov015_0218c920(void* self, int zero);
void* GetVariantShortTable02109928_02099cac();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
extern "C" void MemoryMapTexturePalette();
extern "C" void LoadToTexturePalette(void* dst, const void* src, int size);
extern "C" void MemoryUnmapTexturePalette();
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int fix32_Divide(int, int);

struct Pal0218d50c {
    char pad0[0x148];
    int count;
};

extern int data_0211e33c __attribute__((aligned(4)));
extern char data_ov015_02194094;
extern int data_ov015_02193d64[];
extern char data_ov015_021940f0;

// USA: func_ov015_0218d50c
extern "C" ARM int func_ov015_0218d50c(Obj0218d50c* self) {
    int off70;
    char* pairs;
    int off14;
    SafeAllocator* alloc;
    bool changed;
    short id;

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    DelayThenSyncBit0_020c9820();
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
        self->ids[1] != (id = self->GetEnt(1)->unknown_2_)) {
        changed = true;
    }

    unsigned int size = 0;
    char* buf = (char*)&data_0211e33c;
    unsigned int room = 0x30000;
    GPCReadPair pair;
    char name[0x80];
    ResetObjectState02079a3c(&pair);
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_ov015_02194094,
                                                   buf, size, room, false, 0)) {
        buf += size;
        room -= size;
        for (int i = 0; i < 10; i++) {
            if (self->state != 2 && self->ids[i] == (id = self->ents[i].unknown_2_)) {
                continue;
            }
            pairs = (char*)*self->pairsRoot;
            off70 = i * 0x70;
            alloc = self->allocs;
            off14 = i * 0x14;
            ((SafeAllocator*)((char*)alloc + off14))->Reset();
            CopyInternalFields0207df50((Foo0207df50*)(pairs + off70));
            Vector3fix savedPos = self->GetEnt(i)->position_;
            self->ents[i].Initialize();
            self->ents[i].position_ = savedPos;
            self->ents[i].unknown_2_ = self->ids[i];
            if (self->ids[i] < 0) {
                continue;
            }
            Elem0218d50c* elem = (Elem0218d50c*)FindElementByKey020dedd0((Container020dedd0*)((char*)self->container + 0x4c), (short)self->ids[i]);
            if (elem == 0) {
                continue;
            }
            if (func_ov015_0218c03c(self, name, i, 0) == 0) {
                self->ents[i].Initialize();
                self->ents[i].unknown_2_ = -1;
                continue;
            }
            self->ents[i].Destroy();
            if (i == 0) {
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
            } else if (!(i != 6 && i != 5 && i != 1)) {
                int a = FxMul(self->s40, self->s42);
                short sx = (int)(0.065f * (float)a);
                short sy = (int)(0.065f * (float)self->s40);
                self->ents[i].SetScale(sx, sy, sx);
            }
            if (i == 8 || i == 1) {
                changed = true;
                if (elem->kind == 6) {
                    self->f58 = 1;
                } else {
                    self->f58 = 0;
                }
            }
            RestorePairTables0207df90(pairs + off70);
            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, room, name);
            self->ents[i].SetModelFromFileCopy((SafeAllocator*)((char*)alloc + off14), buf, size, Model3D::TextureStagingMode_Normal);
            buf += size;
            room -= size;
            BackupPairTables0207dfac(pairs + off70);
            if (i == 4 && self->GetEnt(3)->pModel_ != 0) {
                self->GetEnt(3)->pModel_->ApplyTexturesFromModel(self->ents[i].pModel_);
            }
        }
        pair.Reset();
    }
    char* tbl = (char*)GetVariantShortTable02109928_02099cac();
    unsigned int n = ((Pal0218d50c*)*self->pairsRoot)->count;
    unsigned int cnt = (n << 16) >> 13;
    if (cnt != 0) {
        CleanInvalidateCacheRange(tbl + self->c3c * 4, 4);
        CleanInvalidateCacheRange(tbl + 0x108 + self->c3d * 4, 4);
        CleanInvalidateCacheRange(tbl + 0x88 + self->c3e * 16, 0x10);
        DelayThenSyncBit0_020c9820();
        LockStagedTextureVRAMCopying();
        MemoryMapTexturePalette();
        LoadToTexturePalette(tbl + self->c3c * 4, (char*)cnt + 0x24, 4);
        LoadToTexturePalette(tbl + 0x108 + self->c3d * 4, (char*)cnt + 0x28, 4);
        LoadToTexturePalette(tbl + 0x88 + self->c3e * 16, (char*)cnt + 0x30, 0x10);
        MemoryUnmapTexturePalette();
        UnlockStagedTextureVRAMCopying();
    }
    for (int k = 0; data_ov015_02193d64[k] >= 0; k++) {
        func_ov015_0218c3a4(self, data_ov015_02193d64[k]);
    }
    if (changed) {
        func_ov015_0218c920(self, 0);
    }
    self->state = 0;
    self->pathStr = &data_ov015_021940f0;
    BackgroundLoader::RemoveLockGlobal();
    int result = 1;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
    return result;
}
