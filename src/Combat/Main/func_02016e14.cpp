#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Model3D.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "System/Matrix.h"
#include "World/Object3D.h"

struct Pair02016e14 { unsigned char a; unsigned char b; };

struct Bits02016e14 { char pad[0xc]; unsigned char nibble : 4; unsigned char hi : 4; };

struct Entry02016e14 { short type; short pad; Model3D* model; };

struct State02016e14 { short unk0; short val2; short unk4; unsigned short flags6; };

struct Context02016e14 {
    char pad0[0x8];
    struct Bits02016e14* info8;
    char pad1[0x832 - 0xc];
    unsigned char visible832;
    unsigned char visible833;
    char pad2[0x27dc - 0x834];
    struct Pair02016e14 pairs[0x20];
    unsigned char count;
};

struct Node02016e14 {
    unsigned short unk0;
    unsigned short flags2;
    signed char alphaBits : 7;
    signed char alphaFlag : 1;
    char pad5;
    short angleY;
    Vector3i pos;
    Vector3i scale;
    struct State02016e14* state;
    struct Entry02016e14* entry;
    char pad28[0x4];
    struct Node02016e14* child;
    struct Node02016e14* sibling;
    char pad34[0x4];
    short offset38;
    char pad3a[0x54 - 0x3a];
    Object3D* object;
};

struct LightingShift02016e14 { char pad[0x98]; int shift; };

extern "C" void _Z27ClearGlobalFlagBits02016d8cPv(void* arg0);
extern "C" void Mat3x3_WriteRotationY(Matrix3x3* out, int sine, int cosine);

// USA: func_02016e14
extern "C" ARM void func_02016e14(struct Context02016e14* ctx, void* parent, struct Node02016e14* node, int visit) {
    GameState::GetInstance();
    struct LightingShift02016e14* lighting = (struct LightingShift02016e14*)LightingManager::GetInstance();
    struct Entry02016e14* entry = node->entry;
    struct State02016e14* state = node->state;
    int shift = lighting->shift;

    if ((ctx->visible832 != 0 || ctx->visible833 != 0) && ctx->info8 != NULL) {
        unsigned int nibble = ctx->info8->nibble;
        if (nibble == 0 || nibble == 7 || ctx->visible833 != 0) {
            if (!(state->flags6 & 0x10)) {
                if (state->flags6 & (1 << shift)) {
                    node->flags2 &= ~4;
                } else {
                    node->flags2 |= 4;
                }
            }
        }
    }

    *(int*)0x40004c0 = 0x7fff7fff;

    Model3D* model = NULL;
    Object3D* object = NULL;
    int childVisit = 0;
    if (visit == 0 && !(node->flags2 & 4) && entry != NULL) {
        if (entry->type == 0) {
            model = entry->model;
        } else if (entry->type == 2) {
            object = node->object;
            if (object != NULL) {
                model = object->pModel_;
            }
        }
    }

    if (model != NULL) {
        RenderConfig::SetObjectPosition(&node->pos);

        int angle = node->angleY;
        if (node->offset38 != 0) {
            angle = fix32ReduceAngle0To2Pi(angle + node->offset38);
        }
        fix32_t cosine = fix32cos(angle);
        fix32_t sine = fix32sin(angle);
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        _Z27ClearGlobalFlagBits02016d8cPv(&rotation);

        Vector3i scale;
        scale.x = node->scale.x;
        scale.y = node->scale.y;
        scale.z = node->scale.z;
        RenderConfig::SetObjectScale(&scale);

        if ((node->flags2 & 8) || node->alphaFlag != 0) {
            model->SetAlpha(node->alphaBits);
        }

        if (model->rawInternalModel_ != NULL) {
            LightingManager* manager = LightingManager::GetInstance();
            manager->ApplyAmbientColorToModel(model->rawInternalModel_);

            int ok = 0;
            if (entry->type == 0) {
                RenderConfig::SubmitToFifo();
                ok = model->Draw(true);
            } else if (entry->type == 2) {
                object->AdvanceEffects();
                ok = object->DrawSimple(true);
            }

            if (ok) {
                ctx->pairs[ctx->count].a = (unsigned char)state->val2;
                ctx->pairs[ctx->count].b = (unsigned char)*(int*)parent;
                ctx->count++;
            }
        }
    } else {
        childVisit = 1;
    }
    if (node->child != NULL) {
        func_02016e14(ctx, parent, node->child, childVisit);
    }
    if (node->sibling != NULL) {
        func_02016e14(ctx, parent, node->sibling, visit);
    }
}
