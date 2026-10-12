#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneObjectResourceLoading.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/NarcHandle.h"

struct ModelTracker14D {
    short status, field2;
    Model3D* model;
    Animation3D* animations[4];
};
struct ResourceRecord14D {
    short lightingIndex;
    unsigned char flags, textureMask;
    int id;
    ResourceRecord14D* next;
};
struct Container_1f368 { unsigned char padding[0x18]; const char* entries[8]; unsigned char count; };
struct ResourceNode14D { int field0; Container_1f368 names; };
struct AnimationResource14D {
    unsigned int mask;
    char extension[8];
    Animation3D** destination;
    int field10;
};
union AnimationTable14D { AnimationResource14D entries[5]; unsigned int words[25]; };
extern const AnimationTable14D data_020e6fa8;
const char* GetPointerFromArray0x18(Container_1f368*, int);
void CallHandlerFlag0_020e2fc0(void*);

// USA: func_02014d80
extern "C" ARM int func_02014d80(Zone3D* zone, void* nodeData, Struct02012ff0* trackerData, Src02015134* recordData) {
    ResourceNode14D* node = (ResourceNode14D*)nodeData;
    ModelTracker14D* tracker = (ModelTracker14D*)trackerData;
    ResourceRecord14D* record = (ResourceRecord14D*)recordData;
    GameState* game = GameState::GetInstance();
    char* tables = (char*)zone->unknown_ptr_50_;
    SafeAllocator* allocator = zone->pAllocator_68_;
    LightingManager* lighting = LightingManager::GetInstance();
    int lightingIndex = lighting->timeOfDayIndex_;
    Zone3D::Model3DListNode* alternate = 0;
    int tinted = ((ZoneLoadState*)GetField0x3f8Address(game))->unknown20 < 0;
    zone->unknown_834_ = tinted;
    for (ResourceRecord14D* candidate = record->next; candidate; candidate = candidate->next) {
        if (candidate->lightingIndex == lightingIndex) { record = candidate; break; }
    }
    char filename[80];
    unsigned int fileLength;
    FormatFilenameAndSetExtension02014d18(record->id, data_020ef1e8, filename);
    const void* file = GetFileFromNARCInMemory(filename);
    if (file) {
        tracker->model = (Model3D*)allocator->Allocate(0xac);
        void* raw = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, fileLength);
        if (raw && tracker->model) {
            tracker->model->Clear();
            RestorePairTables0207df90(tables);
            tracker->model->SetAndProcessRawFile(raw, fileLength, Model3D::TextureStagingMode_Normal);
            BackupPairTables0207dfac(tables);
            NSBXXTex* texture = tracker->model->GetTEX0();
            if (texture) {
                zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
            }
            ModelRenderContext* context = tracker->model->unknown_flags_a8_0_ ? &tracker->model->renderContext_ : 0;
            if (context) SetModelRenderContextRenderCommandHook(context, (RenderCommandHook)CallHandlerFlag0_020e2fc0, 0, 8, 1);
            if (!(record->flags & 0x20) && tinted) lighting->ModelTransformTintBrightnessContrast(tracker->model->rawInternalModel_);
            for (Zone3D::Model3DListNode* model = zone->firstModel_418_; model; model = model->pNext_) {
                tracker->model->ApplyTexturesFromModel(&model->model_);
                tracker->model->SetTEX0(model->model_.GetTEX0());
            }
            Zone3D::Model3DListNode* first = zone->firstModel_418_;
            const char* name;
            int index;
            for (index = 0; index < 8; index++) {
                if (record->textureMask & (1 << index)) {
                    name = GetPointerFromArray0x18(&node->names, index);
                    if (name) {
                        alternate = first;
                        while (alternate) {
                            if (strstr(alternate->filename_, name)) goto selected;
                            alternate = alternate->pNext_;
                        }
                    }
                }
            }
            alternate = 0;
    selected:
            int flags = 0;
            if (!(record->flags & 1)) flags |= 1;
            if (flags) tracker->model->CreateBoneMatrixAndMaterialArrays(allocator, flags);
        }
        if (!tracker->model) { tracker->status = -1; return 0; }
    } else { tracker->status = -1; return 0; }
    if (tracker->model) {
        AnimationTable14D animations;
        animations = data_020e6fa8;
        animations.entries[0].destination = &tracker->animations[3];
        animations.entries[1].destination = &tracker->animations[2];
        animations.entries[2].destination = &tracker->animations[1];
        animations.entries[3].destination = &tracker->animations[0];
        AnimationResource14D* entry = animations.entries;
        while (entry->mask) {
            if (entry->mask & record->flags) {
                FormatFilenameAndSetExtension02014d18(record->id, entry->extension, filename);
                file = GetFileFromNARCInMemory(filename);
                if (file) {
                    Animation3D* animation = (Animation3D*)allocator->Allocate(0x10);
                    void* animationFile = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, fileLength);
                    if (animationFile && animation) {
                        animation->DefaultInitialize();
                        animation->SetRawFile((NSBXXContainer*)animationFile);
                        if (alternate) {
                            animation->CreateData(tracker->model, allocator, &alternate->model_);
                            tracker->model->AddAnimation(animation);
                            *entry->destination = animation;
                        } else {
                            animation->CreateData(tracker->model, allocator, 0);
                            tracker->model->AddAnimation(animation);
                            *entry->destination = animation;
                        }
                    }
                }
            }
            entry++;
        }
    }
    tracker->status = 0;
    return 1;
}
