#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/NSBXX/RenderConfig.h"

struct CombatEntryList;
struct RenderFlags02016874 {
    float unknown0;
    float unknown4;
    float unknown8;
    int normalPending;
    float unknown10;
};
extern RenderFlags02016874 data_020ef0dc;
extern "C" void func_0201730c(CombatEntryList*);
extern "C" void func_02017540(Zone3D*);
int IsInRange0201b5b0(int);
void ClearGlobalFlagBits02016d8c(void*);
void PushMatrixAndRender02016db4(void*, void*);
extern "C" void func_020ca528(const void*, void*);

// USA: func_02016874
// JPN: func_02016614
extern "C" ARM void func_02016874(Zone3D* self) {
    if (self->unknown_424_ != 0) return;
    func_0201730c((CombatEntryList*)self);
    func_02017540(self);
    self->unk_276c[0xb0] = 0;
    data_020ef0dc.normalPending = 1;
    if (IsInRange0201b5b0(self->currentZoneID_)) {
        if (((unsigned char*)self->unk_23bc)[0] == 0) return;
        ProcessNode0201aedc(self);
        int environment;
        int minX;
        int z;
        GrottoTileMapRecord* tile;
        int mapWidth;
        environment = self->grotto_.GetActiveGrottoEnviron();
        mapWidth = self->grotto_.floorWidth_;
        GameObject* player = GameState::GetInstance()->GetUnknownGameObject();
        int playerX = (int)(((float)(player->obj3D_.position_.x + 0x4000) / 4096.0f) / 8.0f);
        int playerZ = (int)(((float)(player->obj3D_.position_.z + 0x4000) / 4096.0f) / 8.0f);
        int x;
        int maxX, minZ;
        int maxZ = 1;
        maxZ += playerZ;
        if (environment == 5) {
            minX = playerX - 4;
            maxX = playerX + 4;
            minZ = playerZ - 4;
        } else {
            minX = playerX - 2;
            maxX = playerX + 2;
            minZ = playerZ - 2;
        }
        if (minX < 0) minX = 0;
        if (minZ < 0) minZ = 0;
        maxX++;
        if (maxX > 16) maxX = 16;
        maxZ++;
        if (maxZ > 16) maxZ = 16;
        z = minZ;
        for (; z < maxZ; z++) {
            for (x = minX; x < maxX; x++) {
                tile = &self->grottoTileMapData_420_[z * 16];
                tile = &tile[x];
                if (tile->node == 0) continue;
                BmdjSceneElement* render = tile->node->elements;
                if (render->flags & 4) continue;
                Model3D* model;
                model = render->resource->model;
                if (model == 0 || model->rawInternalModel_ == 0) continue;
                LightingManager* manager = LightingManager::GetInstance();
                manager->ApplyAmbientColorToModel(model->rawInternalModel_);
                func_020ca528(&tile->rotation, &data_0210a010.objectRotationPosition);
                data_0210a010.flags &= ~0xa4;
                RenderConfig::SetObjectPosition(&tile->position);
                RenderConfig::SubmitToFifo();
                model->Draw(true);
                if (environment == 4) {
                    model = GetNodeAtDepth020196fc(self, 11)->elements->resource->model;
                    NSBXXInternalModel* internal = model->rawInternalModel_;
                    if (model != 0 && internal != 0) {
                        Matrix3x3 identity;
                        Mat3x3_WriteIdentity(&identity);
                        ClearGlobalFlagBits02016d8c(&identity);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (environment != 5) return;
        Model3D* model = GetNodeAtDepth020196fc(self, 12)->elements->resource->model;
        LightingManager* manager = LightingManager::GetInstance();
        manager->ApplyAmbientColorToModel(model->rawInternalModel_);
        if (playerZ < 4) {
            for (int z = playerZ - 4; z < playerZ; z++) {
                if (z < 0) {
                    for (int x = playerX - 4; x < playerX + 5; x++) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (playerX < 4) {
            for (int z = playerZ - 4; z < playerZ + 2; z++) {
                for (int x = playerX - 4; x < playerX; x++) {
                    if (x < 0) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (playerX > mapWidth - 5) {
            for (int z = minZ; z < maxZ; z++) {
                for (int x = playerX; x < playerX + 5; x++) {
                    if (x >= mapWidth) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
    } else {
        LightingManager* lighting = LightingManager::GetInstance();
        int time = lighting->timeOfDayIndex_;
        if (time != (unsigned char)self->unk_830[1]) self->unk_830[2] = 1;
        else self->unk_830[2] = 0;
        self->unk_830[1] = time;
        BmdjScriptNode* node = self->firstBMDJStruct_41c_;
        while (node != 0) {
            PushMatrixAndRender02016db4(self, node);
            node = node->next;
        }
        self->unk_830[3] = 0;
    }
}
