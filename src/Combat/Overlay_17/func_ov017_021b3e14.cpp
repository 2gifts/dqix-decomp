#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"

struct OffsetTable02072e34 {
    int v[11];
};
void BuildOffsetTable02072e34(int n, struct OffsetTable02072e34* out);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
void ApplyCombatantEffectByIndex020730e0(int id, int index);
extern "C" int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
int GetField6b0_021b8470(void* obj);
extern "C" unsigned char* func_ov017_021b8478(void* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);

struct Struct_203dafc;
void ClearEightWords_0203dafc(struct Struct_203dafc* obj);
struct StreamHeader;
void RunOverlayScript0216d1c4(int arg0, struct StreamHeader* buffer, int length, int* out);

struct Obj02053cf8;
extern "C" void func_02053cf8(struct Obj02053cf8* obj);
struct Obj02053e10;
void FillNameBytes02053e10(struct Obj02053e10* self);
extern "C" void func_ov017_021917f0(int id, int flag);
void SetBit02026bc8(unsigned char* obj, int index);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
struct SearchStruct;
extern "C" struct SearchStruct* func_0202ae18(void);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
int IsEntryFlagBit11Set_0202be08(struct SearchStruct* search, int id);
struct Outer_02054000;
void* GetActiveSub_02054000(struct Outer_02054000* p);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
int TrySetFlags0x130_020483f0(unsigned char* obj, unsigned short flag);
extern "C" void func_02083e28(void* a, int arg2);
void ApplyCombatantBuffs(int world, int id);
extern "C" void func_ov017_021c6bc8(void);
extern "C" void func_ov017_021cf078(int combatantId, int slot, int flag);
struct StructDE234_020de234;
unsigned short GetPreferredPackedField020de234(struct StructDE234_020de234* p, int preferMid);

struct List021d6b34 {
    int v[8];
};
extern struct List021d6b34 data_ov017_021d6b34;
extern char data_ov017_021d7add[];
extern char data_ov017_021d7ae3[];

struct LoadWork021b3e14 {
    char pad0[8];
    short id;
    short pada;
    int stagingMode;
    int tasks[14];
};

typedef unsigned char PolygonIdRow[11];

struct Ext150 {
    char pad0[0x274];
    char sub274[0x49c - 0x274];
    unsigned char preferMid : 1;
};

struct Member021b3e14 {
    Object3D obj3D_;
    char padac[0x130 - 0xac];
    int* flags130;
    BaseCombatStats* baseStats134;
    ModifiableCombatStats* currentStats138;
    int* scriptState13c;
    char pad140[0x150 - 0x140];
    struct Ext150* ext150;
    GameResources::Substruct_12C8* models154;
    char pad158[0x18c - 0x158];
    int flags18c;
};

struct Active02054000 {
    char pad0[8];
    unsigned int pad8_0 : 18;
    unsigned int active : 1;
    char padc[0x18 - 0xc];
    short count;
};

static inline int SetScriptState(struct Member021b3e14* member, int value) {
    return member->scriptState13c ? (*member->scriptState13c = value) : 0;
}

// USA: func_ov017_021b3e14
extern "C" ARM int func_ov017_021b3e14(struct LoadWork021b3e14* self) {
    GameResources* res;
    int done;
    GameObject* obj;
    int world;
    GameObject* head;
    GameResources::Substruct_12C8* models;
    Model3D* model;
    int i;

    GameState* gs = GameState::GetInstance();
    res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Member021b3e14* member = (struct Member021b3e14*)gs->GetPartyMemberByIndex(self->id);
    models = member->models154;
    struct OffsetTable02072e34 table;
    BuildOffsetTable02072e34(self->id, &table);

    done = 1;
    for (i = 0; i < 11; i++) {
        if (self->tasks[i] < 0) {
            continue;
        }
        if (loader->GetTaskStatus(self->tasks[i]) == 0) {
            done = 0;
            continue;
        }
        if (loader->GetDetailedTaskStatus(self->tasks[i]) != 2) {
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
            continue;
        }
        obj = gs->GetGameObjectByIndex(table.v[i]);
        if (obj == NULL) {
            loader->RemoveTask(self->tasks[i]);
            self->tasks[i] = -1;
            continue;
        }
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->tasks[i], &file, &size);
        SafeAllocator* alloc = &models->allocator_array_4[i];
        char* pairs = models->unknown_cc + i * 0x70;
        CopyInternalFields0207df50((struct Foo0207df50*)pairs);
        RestorePairTables0207df90(pairs);
        obj->obj3D_.SetModelFromFile(alloc, file, size, (Model3D::TextureStagingMode)self->stagingMode);
        BackupPairTables0207dfac(pairs);
        model = obj->obj3D_.pModel_;
        if (i == 0) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 7);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        } else if (!(i == 1 || i == 6 || i == 5 || i == 4)) {
            model->CreateBoneMatrixAndMaterialArrays(alloc, 5);
            model->StoreBoneMatrixAndMaterialArrayPointers();
        }
        if (i == 9) {
            obj->obj3D_.position_.x = 0x1000;
            obj->obj3D_.position_.y = 0;
            obj->obj3D_.position_.z = 0;
        }
        if (i == 0 || i == 1 || i == 5 || i == 4 || i == 2 || i == 6 || i == 7) {
            ApplyCombatantEffectByIndex020730e0(self->id, i);
        }
        loader->RemoveTask(self->tasks[i]);
        self->tasks[i] = -1;
    }

    int isParty = 0;
    if (self->id >= 0 && self->id <= 3) {
        isParty = 1;
    }
    if (isParty) {
        struct List021d6b34 list = data_ov017_021d6b34;
        for (int j = 0; (i = list.v[j]) > -1; j++) {
            GameObject* obj = gs->GetGameObjectByIndex(table.v[i]);
            if (obj != NULL && obj->obj3D_.pModel_ != NULL && obj->obj3D_.pModel_->rawInternalModel_ != NULL) {
                (*(PolygonIdRow*)((unsigned char*)res + self->id * 11 + 0x445c))[i] =
                    NSBXX_Model_GetMaterialPolygonID(obj->obj3D_.pModel_->rawInternalModel_, 0);
            }
        }
    }

    int hasScript = 0;
    void* p3718 = res->unknown_ptr_3718;
    world = GetField6b0_021b8470(p3718);
    unsigned char* bits = func_ov017_021b8478(p3718);
    if (((unsigned char*)p3718)[2] != 0 && bits != NULL) {
        if (TestBitAt0x34_020a35e0(bits, (unsigned char)self->id)) {
            hasScript = 1;
        }
    }

    GameObject* body = gs->GetGameObjectByIndex(table.v[0]);
    head = gs->GetGameObjectByIndex(table.v[1]);
    for (int k = 0; k < 3; k++) {
        int slot = k + 11;
        if (self->tasks[slot] < 0) {
            continue;
        }
        if (loader->GetTaskStatus(self->tasks[slot]) == 0) {
            done = 0;
            continue;
        }
        if (loader->GetDetailedTaskStatus(self->tasks[slot]) != 2) {
            loader->RemoveTask(self->tasks[slot]);
            self->tasks[slot] = -1;
            continue;
        }
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->tasks[slot], &file, &size);
        if (file == NULL || size == 0) {
            loader->RemoveTask(self->tasks[slot]);
            self->tasks[slot] = -1;
            continue;
        }
        switch (slot) {
        case 11: {
            ObjectArchiveLoadInfo info;
            ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
            info.allocator = &models->allocator_52c;
            info.fileData = file;
            info.unk_8 = size;
            body->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
            break;
        }
        case 13: {
            ObjectArchiveLoadInfo info2;
            ClearEightWords_0203dafc((struct Struct_203dafc*)&info2);
            info2.allocator = &models->allocator_540;
            info2.fileData = file;
            info2.packageID = 1;
            info2.unk_10 = 1;
            info2.unk_8 = size;
            body->obj3D_.LoadFromCCHROrCMOTArchive(&info2, NULL);
            if (hasScript) {
                const void* script;
                unsigned int scriptSize;
                if (FindFilesInNarcBySubstring(file, data_ov017_021d7add, &script, &scriptSize, 1)) {
                    int state;
                    RunOverlayScript0216d1c4((int)&models->allocator_540, (struct StreamHeader*)script, scriptSize, &state);
                    SetScriptState(member, state);
                }
            }
            break;
        }
        }
        loader->RemoveTask(self->tasks[slot]);
        self->tasks[slot] = -1;
    }

    if (done) {
        GameResources* res2 = func_ov017_0218b5b0();
        func_02053cf8((struct Obj02053cf8*)member);
        FillNameBytes02053e10((struct Obj02053e10*)member);
        int f = 0;
        if (hasScript) {
            f = 1;
        }
        func_ov017_021917f0(self->id, f);
        SetBit02026bc8((unsigned char*)res2->unknown_ptr_36d0, self->id);

        GameObject* dst = gs->GetGameObjectByIndex(table.v[3]);
        GameObject* src = gs->GetGameObjectByIndex(table.v[4]);
        if (dst != NULL && src != NULL && dst->obj3D_.pModel_ != NULL && src->obj3D_.pModel_ != NULL) {
            dst->obj3D_.pModel_->ApplyTexturesFromModel(src->obj3D_.pModel_);
        }
        SetByte0xbeShiftPrev((struct Bytes02033b88*)member, 0);
        member->obj3D_.EnableFlag(4);

        if (world == 0) {
            struct SearchStruct* search = func_0202ae18();
            int v = member->obj3D_.unknown_4_;
            GameObject* c = GetCombatantWithFlag0x1000_0200ff58(gs, v);
            if (c != NULL) {
                v = GetSignedByte0x2d0_020546a8(c);
            }
            int set = IsEntryFlagBit11Set_0202be08(search, v);
            if (*member->flags130 & 1) {
                if (set == 0) {
                    member->flags18c |= 1;
                }
            }
        }

        if (hasScript) {
            body->obj3D_.MakeHidden();
            ((unsigned char*)member)[0xc2] |= 0x20;
            if (*(int*)((char*)member->currentStats138 + 0x14) & 1) {
                SetByte0xbeShiftPrev((struct Bytes02033b88*)member, 4);
            } else {
                member->obj3D_.MaybeSetRegularAnimation(data_ov017_021d7ae3, 0);
            }
            if (world != 0) {
                struct Member021b3e14* c = (struct Member021b3e14*)GetCombatantWithFlag0x100_0200ff1c(gs, self->id);
                if (c != NULL) {
                    struct Active02054000* act = (struct Active02054000*)GetActiveSub_02054000((struct Outer_02054000*)c);
                    if (act != NULL && act->count > 0 && act->active) {
                        int* f = (int*)GetFieldAt0x150_02053c6c((unsigned char*)c);
                        if (f != NULL) {
                            TrySetFlags0x130_020483f0((unsigned char*)c, 4);
                            f[0xa8 / 4] |= 4;
                        }
                    }
                    func_02083e28(c->ext150, 0);
                    ModifiableCombatStats* cur = c->currentStats138;
                    unsigned short maxMP = c->baseStats134->primaryStats.maxMP;
                    cur->primaryStats.maxMP = maxMP;
                    if (maxMP < cur->primaryStats.currMP) {
                        cur->primaryStats.currMP = maxMP;
                    }
                }
                ApplyCombatantBuffs(world, self->id);
                func_ov017_021c6bc8();
                func_ov017_021cf078(self->id, (unsigned char)*(int*)((char*)c->ext150 + 0x950), 1);
            }
        } else {
            member->obj3D_.MakeVisible();
        }

        Model3D* bodyModel = NULL;
        Model3D* headModel = NULL;
        if (body != NULL) {
            bodyModel = body->obj3D_.pModel_;
        }
        if (head != NULL) {
            headModel = head->obj3D_.pModel_;
        }
        if (bodyModel != NULL && headModel != NULL) {
            headModel->SetBoneMatrixRenderData(bodyModel->GetBoneMatrixRenderData());
            headModel->CreateBoneMatrixAndMaterialArrays(NULL, 0);
        }

        {
            int id = self->id;
            GameState* state = GameState::GetInstance();
            GameObject* obj = state->GetGameObjectByIndex(id);
            Model3D* model;
            if (obj != NULL && (model = obj->obj3D_.pModel_) != NULL) {
                model->RemoveTextures();
                GameObject* from = state->GetGameObjectByIndex(id * 12 + 0x17);
                if (from != NULL && from->obj3D_.unknown_2_ >= 0 && from->obj3D_.pModel_ != NULL) {
                    model->ApplyTexturesFromModel(from->obj3D_.pModel_);
                }
                model->ApplyTexturesFromModel(model);
            }
        }
        {
            short id = self->id;
            GameState* state = GameState::GetInstance();
            GameObject* obj = state->GetGameObjectByIndex(id * 12 + 0x13);
            Model3D* model;
            if (obj != NULL && (model = obj->obj3D_.pModel_) != NULL) {
                model->RemoveTextures();
                GameObject* from = state->GetGameObjectByIndex(id * 12 + 0x19);
                if (from != NULL && from->obj3D_.unknown_2_ >= 0 && from->obj3D_.pModel_ != NULL) {
                    model->ApplyTexturesFromModel(from->obj3D_.pModel_);
                }
                model->ApplyTexturesFromModel(model);
            }
        }

        GameObject* extra = gs->GetGameObjectByIndex(self->id * 12 + 0x14);
        if (extra != NULL) {
            extra->obj3D_.MakeVisible();
            struct Ext150* ext = member->ext150;
            struct StructDE234_020de234* packed = (struct StructDE234_020de234*)ext->sub274;
            if (packed != NULL) {
                if (GetPreferredPackedField020de234(packed, ext->preferMid) / 100 == 5) {
                    extra->obj3D_.MakeHidden();
                }
            }
        }
    }
    return done;
}
