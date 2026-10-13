#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Graphics.h"

struct Obj02061bd8;

struct Battle0218eafc {
    unsigned char pad0[0x36c8];
    Model3D* model;
};

struct Combatant0218eafc {
    Object3D object;
    unsigned char padAc[0x18c - 0xac];
    unsigned int status;
};

extern "C" void* func_02057924(void);
extern "C" void func_02057ab8(void* list, int id);
extern "C" int _Z29CheckByteFlagsAt4488_021922acPvj(void* self, unsigned int idx);
int GetField0x3b0Value(GameState* battleStruct);
int CheckFlag0x1ceBit2Set(unsigned char* obj);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
int IsField0x1b4Or0x1b8Positive(int* obj);
int GetFieldAt0x1b8(unsigned char* obj);
extern "C" int func_02032fdc(void* obj, int clip, Vector3i* out);
int CheckField0x56bLowNibble(Obj02061bd8* obj);
unsigned char GetByteFieldAt0x1a0(void* obj, int extra);
extern "C" void func_02031234(int angle);
extern "C" Object3D* func_ov017_021bdbcc(void* obj);
extern "C" Object3D* _Z21GetField4334_021bdbc0Ph(unsigned char* ov);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218eafc
extern "C" ARM void func_ov017_0218eafc(Battle0218eafc* battle, int idx) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    int flagged = _Z29CheckByteFlagsAt4488_021922acPvj(battle, (unsigned char)idx);
    if (flagged) func_02057ab8(list, idx);
    if (GetField0x3b0Value(gs) == 0) return;

    Combatant0218eafc* member = (Combatant0218eafc*)gs->GetPartyMemberByIndex(idx);
    int shadowId = idx * 12 + 0x13;
    Object3D* shadow = (Object3D*)gs->GetGameObjectByIndex(shadowId);
    if (member->object.GetFlag(0x200)) return;
    if (CheckFlag0x1ceBit2Set((unsigned char*)member)) return;
    if (member->object.IsChild()) return;
    Model3D* model = member->object.pModel_;
    if (model == NULL) return;
    ModelRenderContext* context = model->unknown_flags_a8_0_ ? &model->renderContext_ : NULL;
    if (context == NULL) return;

    bool clip = true;
    if (GetBitsInField4((unsigned int*)battle, 0x1000)) clip = false;
    int alpha = member->object.GetCombinedAlpha();
    fix32_t alphaScale = member->object.GetAlphaScaleFactor();

    Vector3i saved;
    if (IsField0x1b4Or0x1b8Positive((int*)member)) {
        saved = member->object.position_;
        Vector3i raised = saved;
        raised.y += GetFieldAt0x1b8((unsigned char*)member);
        member->object.position_ = raised;
        if (shadow) shadow->position_ = raised;
    }

    if ((member->status & 1) && !(member->status & 2) && member->object.IsVisible()) {
        member->object.PopulateRenderConfigWorld();
        RenderConfig::SubmitToFifo();
        battle->model->SetAlpha(alpha);
        battle->model->Draw(clip);
        if (!flagged) func_02057ab8(list, idx);
        return;
    }

    member->object.EnableFlag(0x20000);
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
            int handBone = GetByteFieldAt0x1a0(member, 0);
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
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, GetByteFieldAt0x1a0(member, 3));
            part = (Object3D*)gs->GetGameObjectByIndex(extraId);
            if (part && part->unknown_2_ > 0) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            if (member->status & 0x20) {
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
            if (member->object.IsParent()) member->object.DrawChildren(&member->object);
            if (idx == 0) {
                Object3D* effect = _Z21GetField4334_021bdbc0Ph((unsigned char*)battle);
                if (effect) {
                    GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, GetByteFieldAt0x1a0(member, 2));
                    effect->EnableFlag(0x8000);
                    effect->Draw(false);
                }
            }
            if (shadow) {
                shadow->position_ = shadowPos;
                shadow->rotation_ = member->object.rotation_;
                shadow->Draw(false);
            }
        }
        func_ov017_0218dba0(idx);
        if (!flagged) func_02057ab8(list, idx);
    }

    if (IsField0x1b4Or0x1b8Positive((int*)member)) {
        member->object.position_ = saved;
        if (shadow) shadow->position_ = saved;
    }
}
