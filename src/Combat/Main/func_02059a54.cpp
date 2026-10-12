#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/NSBXX/RenderConfig.h>

struct State02059a2c;
struct S02055080;
struct EffectModelInfo02059a54 {
    char pad0[5];
    unsigned char complex;
};
struct Effect02059a54 {
    int field0;
    unsigned int time;
    char pad8[8];
    Vector3fix origin;
    char pad1c[0xc];
    S02055080* resource;
    unsigned char active;
    char pad2d[0x23];
    float scaleX, scaleY;
    char pad58[0x14];
    float velocityX, velocityY, velocityZ, speed;
    Object3D object;
    int polygonId;
    float red, green, blue, alpha, width, height;
};
int CheckByte0xcZeroAndField8LeField4(State02059a2c*);
EffectModelInfo02059a54* GetSubField0x14(S02055080*);
void* GetField0x3b0Value(GameState*);
void* GetPtrField0x144(void*);
extern "C" void func_020ca528(void*, const void*);
extern "C" void NSBXX_Model_SetPolygonID(void*, int);
extern int data_0210a0cc;
extern Vector3fix data_020e7da4;
static inline NSBXXInternalModel* GetEffectModel(Effect02059a54* effect) { return effect->object.pModel_->rawInternalModel_; }

// USA: func_02059a54
extern "C" ARM void func_02059a54(Effect02059a54* self) {
    if (self->active && !CheckByte0xcZeroAndField8LeField4((State02059a2c*)self)) {
        EffectModelInfo02059a54* info = GetSubField0x14(self->resource);
        int x;
        int y;
        unsigned int time;
        time = self->time;
        x = self->origin.x + (int)(4096.0f * ((float)time * (self->velocityX * self->speed)));
        y = self->origin.y + (int)(4096.0f * ((float)time * (self->velocityY * self->speed)));
        int z = self->origin.z + (int)(4096.0f * ((float)time * (self->velocityZ * self->speed)));
        self->object.position_.x = x;
        self->object.position_.y = y;
        self->object.position_.z = z;
        if (!info->complex) {
            NSBXXInternalModel* model = GetEffectModel(self);
            int blue = (int)self->blue;
            int red = (int)self->red;
            int green = (int)self->green;
            NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)(red | (green << 5) | (blue << 10)));
            NSBXX_Model_SetPolygonID(self->object.pModel_->rawInternalModel_, self->polygonId);
            Vector3fix position = self->object.position_;
            RenderConfig::SetObjectPosition(&position);
            void* camera = GetField0x3b0Value(GameState::GetInstance());
            if (camera) {
                func_020ca528(GetPtrField0x144(camera), &data_0210a0cc);
                data_0210a010.flags &= ~0xa4;
            }
            Vector3fix scale = data_020e7da4;
            scale.x = (int)((float)(int)(4096.0f * self->width) * self->scaleX);
            scale.y = (int)((float)(int)(4096.0f * self->height) * self->scaleY);
            RenderConfig::SetObjectScale(&scale);
            self->object.SetInheritedAlpha((int)self->alpha);
            self->object.DrawSimple(true);
        } else {
            self->object.Draw(true);
        }
    }
}
