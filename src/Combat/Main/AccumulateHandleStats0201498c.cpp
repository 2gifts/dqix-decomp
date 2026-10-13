#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Graphics/NSBXX/NSBXX.h"

// USA: func_0201498c
ARM int AccumulateHandleStats0201498c(void* zoneRaw) {
    Zone3D* zone = static_cast<Zone3D*>(zoneRaw);
    AtmosphericEffectSet* effects = &zone->atmosphericEffects_;
    if (!effects->IsArchiveLoaded())
        return 0;

    effects->ProcessArchive(effects, zone->pAllocator_68_, zone->unknown_ptr_50_);
    AtmosphericEffect* effect = effects->GetFirstEffect();
    while (effect != NULL) {
        Model3D* model = effect->object_.pModel_;
        if (model != NULL) {
            NSBXXTex* texture = model->GetTEX0();
            if (texture != NULL) {
                zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
            }
        }
        effect = effect->pNext_;
    }
    return 1;
}
