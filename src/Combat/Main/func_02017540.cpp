#include <globaldefs.h>
#include <World/Zone3D.h>
#include <Graphics/NSBXX/RenderConfig.h>

extern Vector3i data_020e6e2c;
extern Vector3i data_020e6e38;
extern "C" void _Z27ClearGlobalFlagBits02016d8cPv(void* rotation);

// USA: func_02017540
extern "C" ARM void func_02017540(Zone3D* zone) {
    if (zone->chestRenderingEnabled_274c_ == 0) return;
    NSBXXInternalModel* models[3] = {};
    models[0] = zone->models_498_[0].rawInternalModel_;
    models[1] = zone->models_498_[1].rawInternalModel_;
    NSBXXTex* textures[3] = {};
    textures[0] = zone->models_498_[0].GetTEX0();
    textures[1] = zone->models_498_[1].GetTEX0();
    Vector3i scale = data_020e6e2c;
    RenderConfig::SetObjectScale(&scale);
    int* palette = zone->chestPaletteOffsets_5f0_;
    for (int pass = 0; pass < 2; pass++) {
        NSBXXTex** texture;
        NSBXXInternalModel** model;
        model = models;
        texture = textures;
        while (*texture != NULL && *model != NULL) {
            int offset = *palette;
            palette++;
            NSBXX_Tex_WritePaletteVRAMOffset(*texture, offset);
            NSBXX_DetachTexturePaletteFromModel(*model);
            NSBXXInternalModel* currentModel = *model++;
            NSBXXTex* currentTexture = *texture++;
            NSBXX_AttachTexturePaletteToModel(currentModel, currentTexture);
        }
        ZoneChestRenderRecord* record = zone->unknown_47c_;
        for (int i = 0; i < zone->numChests_; record++, i++) {
            if (record->active != 0 && ((pass == 0 && record->secondPass == 0) || (pass == 1 && record->secondPass != 0))) {
                Vector3i position = record->position;
                short angleY = record->angleY;
                short angleX = record->angleX;
                RenderConfig::SetObjectPosition(&position);
                Matrix3x3 rotationY;
                fix32_t cosineY = fix32cos(angleY);
                fix32_t sineY = fix32sin(angleY);
                Mat3x3_WriteRotationY(&rotationY, sineY, cosineY);
                _Z27ClearGlobalFlagBits02016d8cPv(&rotationY);
                RenderConfig::SubmitToFifo();
                zone->models_498_[0].DrawMeshWithMaterial(true, 0, 0, 1);
                Vector3i offset = data_020e6e38;
                Mat3x3_ApplyToVector(&offset, &rotationY, &offset);
                Vector3fix_Add(&position, &offset, &position);
                RenderConfig::SetObjectPosition(&position);
                Matrix3x3 rotationX;
                fix32_t cosineX = fix32cos(angleX);
                fix32_t sineX = fix32sin(angleX);
                Mat3x3_WriteRotationX(&rotationX, sineX, cosineX);
                Matrix3x3 rotation;
                Mat3x3_Multiply(&rotationX, &rotationY, &rotation);
                _Z27ClearGlobalFlagBits02016d8cPv(&rotation);
                RenderConfig::SubmitToFifo();
                zone->models_498_[1].DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    }
}
