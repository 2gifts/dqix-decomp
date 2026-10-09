#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Model3D.h"
#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"

struct Param021e7ec0 {
    char pad0[8];
    unsigned short index;
    unsigned short key;
};

extern "C" int _Z23DispatchByIndex021820bcPviii(void* obj, int unused, int index, int arg);
void* GetActiveCombatWork(void);
extern "C" GameObject* _Z26FindNodeByShortKey02162d88Pvs(void* obj, unsigned short key);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" void _Z24CopyObjectFields02048588PhS_(unsigned char* self, unsigned char* dst);
extern "C" void func_ov000_021677fc(void* work);

// USA: func_ov025_021e7ec0
extern "C" ARM int func_ov025_021e7ec0(struct Param021e7ec0* p, int unused, int unusedR2, void* obj) {
    GameState* gs = GameState::GetInstance();
    int ids[8];
    int count = _Z23DispatchByIndex021820bcPviii(obj, unused, p->index, (int)&ids[0]);
    void* work = GetActiveCombatWork();
    GameObject* source = _Z26FindNodeByShortKey02162d88Pvs(work, p->key);
    if (source == NULL) return 1;
    if (source->obj3D_.pModel_ == NULL) return 1;
    NSBXXTex* tex = source->obj3D_.pModel_->GetTEX0();
    if (tex == NULL) return 1;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantWithFlag0x400(gs, ids[i]);
        if (c) {
            _Z24CopyObjectFields02048588PhS_((unsigned char*)source, (unsigned char*)c);
            unsigned int offset = c->obj3D_.GetTexturePaletteOffset();
            CleanInvalidateCacheRange((char*)tex + tex->block4Offset_, tex->block4NumEightBytes_ << 3);
            NSBXX_Tex_WritePaletteVRAMOffset(tex, offset);
            StageTexFilePaletteData(tex, true);
        }
    }
    func_ov000_021677fc(work);
    return 1;
}
