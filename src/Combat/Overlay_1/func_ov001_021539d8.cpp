#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Memory/SafeAllocator.h"

struct PairTables021539d8 {
    char storage[0x70];
};

struct ArchiveInfo021539d8 {
    int unused0;
    void* data;
    unsigned int size;
    SafeAllocator* allocator;
    int flag;
    int pad14;
    int pad18;
    int mode;
};

struct ObjState021539d8 {
    unsigned int flag : 1;
};

struct ObjModel021539d8 {
    char pad0[0x54];
    NSBXXInternalModel* model;
};

struct Obj021539d8 {
    unsigned short flags;
    char pad2[6];
    struct ObjModel021539d8* holder;
    struct ObjState021539d8* state;
    char pad10[0x34];
    int posX;
    int posY;
    int posZ;
    char pad50[0x84];
    unsigned char active : 1;
    char padd5[0x5b];
    unsigned int* status;
};

struct Stream021539d8 {
    int owner;
    char pad4[0x4c];
    unsigned int flags;
};

struct Emitter021539d8 {
    unsigned int flags;
    int unk4;
    void* name;
    void* record;
    int unk10;
    struct Stream021539d8* stream;
    struct Obj021539d8* object;
    int unk1c;
};

struct Label021539d8 {
    char pad0[2];
    unsigned char kind;
    char pad3;
    char text[0x10];
};

struct LoadNode021539d8 {
    unsigned char type : 4;
    unsigned char unused : 4;
    unsigned char index;
    short slot;
    unsigned char flags;
    char pad5[3];
    union {
        int key;
        char name[0x24];
    };
    int task;
    unsigned char kind;
    unsigned char done;
    char pad32[2];
    struct LoadNode021539d8* next;
};

struct MotionNode021539d8 {
    unsigned char index;
    char pad1[0x23];
    int task;
    struct MotionNode021539d8* next;
    unsigned char pending;
};

struct Global021539d8 {
    char pad0[0x98];
    unsigned int flags;
};

struct Self021539d8 {
    char pad0[0x50];
    unsigned short flags;
    char pad52[0x7e];
    struct LoadNode021539d8* loads;
    struct MotionNode021539d8* motions;
    char padd8[0x1c];
    int task;
    unsigned int mode : 27;
};

extern char data_ov001_02164bb0[];
extern char data_ov001_02164bb6[];
extern char data_ov001_02164bc0[];
extern char data_ov001_02164bc5[];
extern char data_ov001_02164bc8[];
extern char data_ov001_02164bcb[];

extern "C" {
struct Global021539d8* _Z20GetGlobalPtr021075f4v(void);

void* func_0202ae18(void);
int func_0202c508(void* obj);
unsigned char _Z19GetField0x397cValueP9GameState(GameState* gs);
int _Z18GetField0x3acValueP9GameState(GameState* gs);
void _Z26CopyInternalFields0207df50P11Foo0207df50(struct PairTables021539d8* p);
void _Z25RestorePairTables0207df90Pc(struct PairTables021539d8* p);
void _Z24BackupPairTables0207dfacPc(struct PairTables021539d8* p);
void func_ov001_0215ab54(int kind, int id, int index);
struct Emitter021539d8* _Z29FindEntryPointerByKey0203df78Pvi(void* list, int key);
int _Z22FindEntryByKey0203dfdcPvi(void* list, int key);
void _Z21RegisterCombatantSlotP9GameStateiP10GameObject(GameState* gs, int id, struct Obj021539d8* obj);
SafeAllocator* _Z22GetGlobalValue0215aab8v(void);
void _ZN8Object3D10InitializeEv(struct Obj021539d8* obj);
void _ZN8Object3D11MakeVisibleEv(struct Obj021539d8* obj);
void _ZN8Object3D10MakeHiddenEv(struct Obj021539d8* obj);
void _ZN8Object3D10EnableFlagEi(struct Obj021539d8* obj, int mask);
void _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(struct Obj021539d8* obj, struct ArchiveInfo021539d8* info);
void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(struct Obj021539d8* obj, struct ArchiveInfo021539d8* info, void* callback);
void _ZN8Object3D8SetScaleEiii(struct Obj021539d8* obj, int x, int y, int z);
void _ZN8Object3D21MaybeSetBCFGAnimationEii(struct Obj021539d8* obj, int a, int b);
void _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(struct Obj021539d8* obj, SafeAllocator* allocator, void* data, unsigned int size, int mode);
void func_02012fe4(void);
void _Z12Init020404c0Pi(struct Emitter021539d8* emitter);
void _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(void* record);
void _Z30InitializeRandomMotion0203c794Pv(struct Stream021539d8* stream);
char* strstr(const char* text, const char* needle);
void* memcpy(void* dst, const void* src, unsigned int size);
int sprintf(char* dst, const char* format, ...);
void _Z11SetField0xcPii(struct Emitter021539d8* emitter, void* record);
void _Z11SetField0x8Pii(struct Emitter021539d8* emitter, struct Label021539d8* label);
int _Z17EmptyStub0203d004v(void* list);
void _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(struct Stream021539d8* stream, char* name, SafeAllocator* allocator, struct PairTables021539d8* pair, void* data, unsigned int size);
void func_0203f138(struct Stream021539d8* stream, int enabled);
void _Z28SetActiveChildShorts020408c8P12Node020408c8sss(struct Emitter021539d8* emitter, int a, int b, int c);
int _Z18FindEmptySlotIndexP18SlotArray_0203e03c(void* list);
void _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(void* list, int index, struct Emitter021539d8* emitter);
int _Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(void* narc, const char* text, void** outFile, unsigned int* outSize, unsigned int count);
void* _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(SafeAllocator* allocator, void* file, unsigned int* outSize);
void NSBXX_Model_SetPolygonID(NSBXXInternalModel* model, int id);
void _Z15SetBitsInField4Pjj(char* obj, unsigned int bits);
void __clear(unsigned char* flags, int count);
}

static inline void UpdateStream021539d8(struct Emitter021539d8* emitter, char* name, SafeAllocator* allocator,
                                        struct PairTables021539d8* pair, void* data, unsigned int size) {
    if (emitter->stream != 0) {
        _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(emitter->stream, name, allocator, pair, data, size);
    }
}

static inline void EnableStream021539d8(struct Emitter021539d8* emitter, int enabled) {
    if (emitter->stream != 0) {
        func_0203f138(emitter->stream, enabled);
    }
}

// USA: func_ov001_021539d8
extern "C" ARM void func_ov001_021539d8(struct Self021539d8* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    struct Global021539d8* global = _Z20GetGlobalPtr021075f4v();
    char* base = (char*)func_ov017_0218b5b0();
    void* search = func_0202ae18();
    struct LoadNode021539d8* node;
    struct MotionNode021539d8* motion;
    bool copied;
    LightingManager* lighting;
    unsigned int meshIndex;
    unsigned char* fifoBlob;
    unsigned char opcode1;
    unsigned char opcode2;
    unsigned char opcode3;
    SafeAllocator* pool;
    void* record;
    unsigned char length;
    NSBXXMesh* mesh;
    NSBXXInternalModel* model;
    struct Emitter021539d8* emitter;
    struct Label021539d8* label;
    struct PairTables021539d8* pair;

    for (node = self->loads; node != 0; node = node->next) {
        if (node->type == 1) {
            if (func_0202c508(search) == 0 || !(self->mode & 0x10)) {
                int current = _Z19GetField0x397cValueP9GameState(gs);
                if (current != 0) {
                    struct LoadNode021539d8* other;
                    for (other = self->loads; other != 0; other = other->next) {
                        if (other->type >= 0xb && other->type <= 0xd && other->slot == current) {
                            other->slot = 0;
                            other->unused = 0;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }

    copied = false;
    node = self->loads;
    while (node != 0) {

        if (node->done != 0) {
            node = node->next;
            continue;
        }

        pair = &((struct PairTables021539d8*)(base + 0x2cc))[27];
        if (node->kind == 1) {
            pair = &((struct PairTables021539d8*)(base + 0x2cc))[7];
            if (!copied) {
                if ((self->flags & 4) || (self->flags & 1)) {
                    _Z26CopyInternalFields0207df50P11Foo0207df50(pair);
                    copied = true;
                }
            }
        }

        switch (node->type) {
        case 0: {
            struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetPartyMemberByIndex(0);
            if (obj == 0) {
                break;
            }
            if ((self->mode & 0x10) || !(*obj->status & 1)) {
                func_ov001_0215ab54(4, 0, node->index);
            } else if (func_0202c508(search) != 0) {
                func_ov001_0215ab54(5, _Z19GetField0x397cValueP9GameState(gs), node->index);
            } else {
                int current = _Z18GetField0x3acValueP9GameState(gs);
                int i;
                for (i = 3; i > 0; i--) {
                    if (current != i) {
                        obj = (struct Obj021539d8*)gs->GetPartyMemberByIndex(i);
                        if (obj != 0 && (obj->flags & 0x1000) && !(*obj->status & 1)) {
                            func_ov001_0215ab54(5, i, node->index);
                            break;
                        }
                    }
                }
                if (i == 0) {
                    break;
                }
            }
            _ZN8Object3D11MakeVisibleEv(obj);
            break;
        }
        case 1:
            func_ov001_0215ab54(5, _Z19GetField0x397cValueP9GameState(gs), node->index);
            break;
        case 9:
        case 11:
        case 12:
        case 13:
            func_ov001_0215ab54(5, node->slot, node->index);
            break;
        case 10:
            func_ov001_0215ab54(1, node->slot, node->index);
            break;
        case 4: {
            struct Emitter021539d8* emitter = _Z29FindEntryPointerByKey0203df78Pvi(global, node->key);
            if (emitter != 0 && emitter->object != 0) {
                emitter->object->active = 1;
                _Z21RegisterCombatantSlotP9GameStateiP10GameObject(gs, node->slot, emitter->object);
                emitter->flags |= 0x10000;
                func_ov001_0215ab54(6, _Z22FindEntryByKey0203dfdcPvi(global, node->key), node->index);
            }
            break;
        }
        case 2: {
            char name[0x50];
            struct ArchiveInfo021539d8 info;
            void* data;
            unsigned int size;
            int format;
            SafeAllocator* allocator;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            format = 0;
            if (loader->GetTaskFilename(node->task, name)) {
                if (strstr(name, data_ov001_02164bb0) != 0 || strstr(name, data_ov001_02164bb6) != 0) {
                    format = 1;
                }
            }
            allocator = _Z22GetGlobalValue0215aab8v();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            _Z25RestorePairTables0207df90Pc(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.allocator = allocator;
            info.data = data;
            info.size = size;
            info.flag = 1;
            if (format == 0) {
                _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            } else if (format == 1) {
                _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
            }
            _Z24BackupPairTables0207dfacPc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, 0, 0);
            _Z21RegisterCombatantSlotP9GameStateiP10GameObject(gs, node->slot, obj);
            if (node->flags & 1) {
                func_02012fe4();
                lighting = LightingManager::GetInstance();
                model = obj->holder->model;
                NSBXXNameList* meshList = model->GetMeshListSafe();
                unsigned int readPos;
                unsigned int* operandPtr;
                int totalNumOperands;

                for (meshIndex = 0; meshIndex < model->numMeshes_; meshIndex++) {
                    unsigned char opcode0;
                    void* pOffset;

                    if (meshList != NULL && (pOffset = meshList->GetEntryv3Safe(meshIndex)))
                        mesh = (NSBXXMesh*)meshList->GetEntryFromPtrOffset(pOffset);
                    else
                        mesh = NULL;

                    if (!(mesh->unk_4 & 2))
                        continue;

                    fifoBlob = (unsigned char*)mesh + mesh->gpuCommandsOffset_;
                    readPos = 0;
                    while (readPos < mesh->gpuCommandsLength_) {
                        opcode0 = fifoBlob[readPos];
                        opcode1 = fifoBlob[readPos + 1];
                        opcode2 = fifoBlob[readPos + 2];
                        opcode3 = fifoBlob[readPos + 3];
                        readPos += 4;

                        int oneCommandNumOperands = 0;
                        operandPtr = (unsigned int*)(fifoBlob + readPos);

                        totalNumOperands = 0;

                        if (lighting->GetFifoCommandData(opcode0, &oneCommandNumOperands))
                            operandPtr[totalNumOperands] = lighting->ColorTransformTintBrightnessContrast(operandPtr[totalNumOperands]);
                        totalNumOperands += oneCommandNumOperands;

                        if (lighting->GetFifoCommandData(opcode1, &oneCommandNumOperands))
                            operandPtr[totalNumOperands] = lighting->ColorTransformTintBrightnessContrast(operandPtr[totalNumOperands]);
                        totalNumOperands += oneCommandNumOperands;

                        if (lighting->GetFifoCommandData(opcode2, &oneCommandNumOperands))
                            operandPtr[totalNumOperands] = lighting->ColorTransformTintBrightnessContrast(operandPtr[totalNumOperands]);
                        totalNumOperands += oneCommandNumOperands;

                        if (lighting->GetFifoCommandData(opcode3, &oneCommandNumOperands))
                            operandPtr[totalNumOperands] = lighting->ColorTransformTintBrightnessContrast(operandPtr[totalNumOperands]);
                        totalNumOperands += oneCommandNumOperands;

                        readPos += 4 * totalNumOperands;
                    }
                }
            }
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 5: {
            struct Emitter021539d8* emitter = _Z29FindEntryPointerByKey0203df78Pvi(global, node->key);
            if (emitter != 0 && emitter->stream != 0) {
                emitter->flags |= 0x10000;
                func_ov001_0215ab54(2, _Z22FindEntryByKey0203dfdcPvi(global, node->key), node->index);
            }
            break;
        }
        case 3: {
            void* data;
            unsigned int size;
            int owner;
            struct Stream021539d8* stream;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            pool = _Z22GetGlobalValue0215aab8v();
            loader->GetLoadedFileByID(node->task, &data, &size);
            emitter = (struct Emitter021539d8*)pool->Allocate(0x20);
            record = pool->Allocate(0x78);
            label = (struct Label021539d8*)pool->Allocate(0x14);
            stream = (struct Stream021539d8*)pool->Allocate(0x9c);
            if (emitter == 0 || label == 0 || record == 0 || stream == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            _Z12Init020404c0Pi(emitter);
            _Z23ClearWorkRecord0206bf2cP11Rec0206bf2c(record);
            _Z30InitializeRandomMotion0203c794Pv(stream);
            label->kind = 3;
            if (strstr(node->name, data_ov001_02164bc0) != 0) {
                length = 5;
                if (strstr(node->name, data_ov001_02164bc5) != 0) {
                    length = 7;
                    stream->flags |= 8;
                }
                memcpy(label->text, node->name + 9, length);
                if (length < 7u) {
                    label->text[length] = 0;
                }
            } else {
                sprintf(label->text, data_ov001_02164bc8, node->name);
            }
            emitter->stream = stream;
            _Z11SetField0xcPii(emitter, record);
            _Z11SetField0x8Pii(emitter, label);
            owner = _Z17EmptyStub0203d004v(global);
            if (emitter->stream != 0) {
                emitter->stream->owner = owner;
            }
            UpdateStream021539d8(emitter, node->name + 9, pool, pair, data, size);
            EnableStream021539d8(emitter, 1);
            _Z28SetActiveChildShorts020408c8P12Node020408c8sss(emitter, 0x8f, 0x8f, 0x8f);
            node->slot = _Z18FindEmptySlotIndexP18SlotArray_0203e03c(global);
            if (node->slot != -1) {
                _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(global, node->slot, emitter);
                emitter->flags |= 0x10000;
                func_ov001_0215ab54(2, node->slot, node->index);
                loader->RemoveTask(node->task);
                node->done = 1;
            }
            break;
        }
        case 6: {
            char name[0x50];
            struct ArchiveInfo021539d8 info;
            void* data;
            unsigned int size;
            unsigned int fileSize;
            void* file;
            unsigned int unpackedSize;
            SafeAllocator* allocator;
            struct Obj021539d8* obj;
            void* unpacked;
            int format;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = _Z22GetGlobalValue0215aab8v();
            loader->GetLoadedFileByID(node->task, &data, &size);
            obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            format = 0;
            if (loader->GetTaskFilename(node->task, name)) {
                if (strstr(name, data_ov001_02164bb0) != 0 || strstr(name, data_ov001_02164bb6) != 0) {
                    format = 1;
                }
            }
            if (_Z26FindFilesInNarcBySubstringPKvPKcPS0_Pjj(data, data_ov001_02164bcb, &file, &fileSize, 1) == 0) {
                break;
            }
            unpacked = _Z36DecompressLZ77FileIntoAllocatedSpaceR13SafeAllocatorPKvRj(allocator, file, &unpackedSize);
            if (unpacked == 0) {
                break;
            }
            _Z25RestorePairTables0207df90Pc(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = unpacked;
            info.allocator = allocator;
            info.size = unpackedSize;
            info.flag = 1;
            if (format == 0) {
                _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            } else if (format == 1) {
                _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
            }
            _Z24BackupPairTables0207dfacPc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, 0, 0);
            _Z21RegisterCombatantSlotP9GameStateiP10GameObject(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 7: {
            void* data;
            unsigned int size;
            SafeAllocator* allocator;
            void* copy;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = _Z22GetGlobalValue0215aab8v();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            copy = allocator->Allocate(size);
            memcpy(copy, data, size);
            _Z25RestorePairTables0207df90Pc(pair);
            _ZN8Object3D10InitializeEv(obj);
            _ZN8Object3D16SetModelFromFileEP13SafeAllocatorPvjN7Model3D18TextureStagingModeE(obj, allocator, copy, size, 0);
            _Z24BackupPairTables0207dfacPc(pair);
            _ZN8Object3D8SetScaleEiii(obj, 0x10a, 0x10a, 0x10a);
            _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, 0, 0);
            _Z21RegisterCombatantSlotP9GameStateiP10GameObject(gs, node->slot, obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        case 8: {
            struct ArchiveInfo021539d8 info;
            void* data;
            unsigned int size;
            SafeAllocator* allocator;

            if (loader->GetDetailedTaskStatus(node->task) != 2) {
                loader->RemoveTask(node->task);
                break;
            }
            allocator = _Z22GetGlobalValue0215aab8v();
            loader->GetLoadedFileByID(node->task, &data, &size);
            struct Obj021539d8* obj = (struct Obj021539d8*)allocator->Allocate(0xac);
            if (obj == 0) {
                loader->RemoveTask(node->task);
                break;
            }
            _Z25RestorePairTables0207df90Pc(pair);
            _ZN8Object3D10InitializeEv(obj);
            info.data = data;
            info.size = size;
            info.flag = 1;
            info.allocator = allocator;
            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
            _Z24BackupPairTables0207dfacPc(pair);
            NSBXX_Model_SetPolygonID(obj->holder->model, 0x3d);
            obj->posX = 0;
            obj->posY = -0xa000;
            obj->posZ = 0x1000;
            _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, 0, 0);
            _Z21RegisterCombatantSlotP9GameStateiP10GameObject(gs, node->slot, obj);
            _ZN8Object3D10MakeHiddenEv(obj);
            func_ov001_0215ab54(1, node->slot, node->index);
            loader->RemoveTask(node->task);
            node->done = 1;
            break;
        }
        }
        node = node->next;
    }

    motion = self->motions;
    while (motion != 0) {
        if (motion->pending != 0 || motion->task < 0) {
            motion = motion->next;
            continue;
        }
        if (loader->GetDetailedTaskStatus(motion->task) == 2) {
            struct LoadNode021539d8* target = self->loads;
            while (target != 0) {
                if (target->index == motion->index && target->type != 3 && target->type != 5) {
                    struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetGameObjectByIndex(target->slot);
                    if (obj != 0) {
                        struct ArchiveInfo021539d8 info;
                        void* data;
                        unsigned int size;
                        SafeAllocator* allocator = _Z22GetGlobalValue0215aab8v();
                        int format;

                        loader->GetLoadedFileByID(motion->task, &data, &size);
                        format = 0;
                        if (obj->state != 0) {
                            format = obj->state->flag;
                        }
                        info.allocator = allocator;
                        info.data = data;
                        info.size = size;
                        info.flag = 1;
                        info.mode = 3;
                        if (format == 0) {
                            _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(obj, &info);
                        } else if (format == 1) {
                            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(obj, &info, 0);
                        }
                        _ZN8Object3D21MaybeSetBCFGAnimationEii(obj, 0, 0);
                        break;
                    }
                }
                target = target->next;
                motion->pending = 1;
            }
        }
        loader->RemoveTask(motion->task);
        motion = motion->next;
    }

    if (self->task > -1) {
        loader->GetDetailedTaskStatus(self->task);
        loader->RemoveTask(self->task);
    }

    if (self->mode != 0) {
        if (self->mode & 1) {
            _Z15SetBitsInField4Pjj(base, 8);
        }
        if (self->mode & 2) {
            _Z15SetBitsInField4Pjj(base, 0x10);
        }
        if (self->mode & 4) {
            unsigned char used[4];
            struct LoadNode021539d8* entry;
            int i;

            __clear(used, 4);
            for (entry = self->loads; entry != 0; entry = entry->next) {
                if (entry->type == 0 || entry->type == 1 || entry->type == 9) {
                    used[entry->slot] = 1;
                }
            }
            for (i = 0; i < 4; i++) {
                if (used[i] == 0) {
                    struct Obj021539d8* obj = (struct Obj021539d8*)gs->GetGameObjectByIndex(i);
                    if (obj != 0) {
                        _ZN8Object3D10EnableFlagEi(obj, 1);
                    }
                }
            }
        }
        if (self->mode & 8) {
            _Z15SetBitsInField4Pjj(base, 0x400);
        }
        if (self->mode & 0x20) {
            _Z20GetGlobalPtr021075f4v()->flags |= 2;
        }
    }
}
