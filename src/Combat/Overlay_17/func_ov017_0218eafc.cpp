#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct Obj02061bd8;

struct Battle0218eafc {
#if defined(jpn)
    unsigned char pad0[0x34b8];
#else
    unsigned char pad0[0x36c8];
#endif
    Model3D* model;
};

extern "C" void* func_02057924(void);
extern "C" void func_02057ab8(void* list, int id);
int CheckByteFlagsAt4488_021922ac(void* self, unsigned int idx);
int CheckFlag0x1ceBit2Set_02039d68(unsigned char* obj);
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GetFieldAt0x1b8_02053cd4(unsigned char* obj);
extern "C" int func_02032fdc(void* obj, int clip, Vector3i* out);
int CheckField0x56bLowNibble(Obj02061bd8* obj);
unsigned char GetByteFieldAt0x1a0_02053eb4(void* obj, int extra);
extern "C" void func_02031234(int angle);
extern "C" Object3D* func_ov017_021bdbcc(void* obj);
Object3D* GetField4334_021bdbc0(unsigned char* ov);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218eafc
extern "C" ARM void func_ov017_0218eafc(Battle0218eafc* battle, int idx) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    int flagged = CheckByteFlagsAt4488_021922ac(battle, (unsigned char)idx);
    if (flagged) func_02057ab8(list, idx);
    if (GetField0x3b0Value_020100bc(gs) == 0) return;

    CombatantRecovery* member = (CombatantRecovery*)gs->GetPartyMemberByIndex(idx);
    int shadowId = idx * 12 + 0x13;
    Object3D* shadow = (Object3D*)gs->GetGameObjectByIndex(shadowId);
    if (member->obj3D_.GetFlag(0x200)) return;
    if (CheckFlag0x1ceBit2Set_02039d68((unsigned char*)member)) return;
    if (member->obj3D_.IsChild()) return;
    Model3D* model = member->obj3D_.pModel_;
    if (model == NULL) return;
    ModelRenderContext* context = model->unknown_flags_a8_0_ ? &model->renderContext_ : NULL;
    if (context == NULL) return;

    bool clip = true;
    if (GetBitsInField4_0203b4fc((unsigned int*)battle, 0x1000)) clip = false;
    int alpha = member->obj3D_.GetCombinedAlpha();
    fix32_t alphaScale = member->obj3D_.GetAlphaScaleFactor();

    Vector3i saved;
    if (IsField0x1b4Or0x1b8Positive_02053cdc((int*)member)) {
        saved = member->obj3D_.position_;
        Vector3i raised = saved;
        raised.y += GetFieldAt0x1b8_02053cd4((unsigned char*)member);
        member->obj3D_.position_ = raised;
        if (shadow) shadow->position_ = raised;
    }

    if ((member->recoveryFlags & 1) && !(member->recoveryFlags & 2) && member->obj3D_.IsVisible()) {
        member->obj3D_.PopulateRenderConfigWorld();
        RenderConfig::SubmitToFifo();
        battle->model->SetAlpha(alpha);
        battle->model->Draw(clip);
        if (!flagged) func_02057ab8(list, idx);
        return;
    }

    member->obj3D_.EnableFlag(0x20000);
    Vector3i shadowPos;
    if (func_02032fdc(member, clip, &shadowPos)) {
        int weaponId = idx * 12 + 0x14;
        int shieldId = idx * 12 + 0x15;
        int headId = idx * 12 + 0x1b;
        int accessoryId = idx * 12 + 0x1c;
        int extraId = idx * 12 + 0x1d;
        unsigned char ids[6] = {
            (unsigned char)(idx * 12 + 0x13), (unsigned char)weaponId, (unsigned char)shieldId,
            (unsigned char)headId, (unsigned char)accessoryId, (unsigned char)extraId
        };
        for (unsigned int i = 0; i < 6; i++) {
            Object3D* part = (Object3D*)gs->GetGameObjectByIndex(ids[i]);
            if (part) {
                part->SetInheritedAlpha(alpha);
                part->SetAlphaScaleFactor((fix16_t)alphaScale);
            }
        }

        if (!CheckField0x56bLowNibble((Obj02061bd8*)member)) {
            int handBone = GetByteFieldAt0x1a0_02053eb4(member, 0);
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, handBone);
            Object3D* part = (Object3D*)gs->GetGameObjectByIndex(weaponId);
            if (part) {
                Vector3fix s = part->GetScale();
                GXFIFO_MATRIX_SCALE = s.x;
                GXFIFO_MATRIX_SCALE = s.y;
                GXFIFO_MATRIX_SCALE = s.z;
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            part = (Object3D*)gs->GetGameObjectByIndex(shieldId);
            if (part) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            part = (Object3D*)gs->GetGameObjectByIndex(headId);
            if (part && part->unknown_2_ >= 0) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, GetByteFieldAt0x1a0_02053eb4(member, 3));
            part = (Object3D*)gs->GetGameObjectByIndex(extraId);
            if (part && part->unknown_2_ > 0) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            if (member->recoveryFlags & 0x20) {
                part = (Object3D*)gs->GetGameObjectByIndex(accessoryId);
                if (part) {
                    part->EnableFlag(0x8000);
                    func_02031234(0x3244);
                    part->Draw(false);
                    part->DisableFlag(0x8000);
                }
            }
            if (idx == 0) {
                Object3D* effect = func_ov017_021bdbcc(battle);
                if (effect) {
                    GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, handBone);
                    effect->EnableFlag(0x8000);
                    effect->Draw(false);
                }
            }
            if (member->obj3D_.IsParent()) member->obj3D_.DrawChildren(&member->obj3D_);
            if (idx == 0) {
                Object3D* effect = GetField4334_021bdbc0((unsigned char*)battle);
                if (effect) {
                    GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, GetByteFieldAt0x1a0_02053eb4(member, 2));
                    effect->EnableFlag(0x8000);
                    effect->Draw(false);
                }
            }
            if (shadow) {
                shadow->position_ = shadowPos;
                shadow->rotation_ = member->obj3D_.rotation_;
                shadow->Draw(false);
            }
        }
        func_ov017_0218dba0(idx);
        if (!flagged) func_02057ab8(list, idx);
    }

    if (IsField0x1b4Or0x1b8Positive_02053cdc((int*)member)) {
        member->obj3D_.position_ = saved;
        if (shadow) shadow->position_ = saved;
    }
}
