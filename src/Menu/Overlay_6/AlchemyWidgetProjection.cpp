#if defined(jpn)
#define R(j,u) (j)
#define _Z25ForwardTableValue02075db0P14Struct02075db0ii func_02076ccc
#define data_0210a00c data_02109cc4
#define data_ov005_0215cd74 data_ov005_0215e154
#define data_ov006_0215ff6c data_ov006_021612d0
#define func_ov005_021556e4 func_ov005_02156cd4
#define func_ov005_02158878 func_ov005_02159e70
#define func_ov005_0215cb4c func_ov005_0215df2c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "GameState/GameState.h"

struct AlchemyProjectedWidgetView {
    char unknown00[0x14];
    void* resource;
    char unknown18[0x2c];
    int resourceIndex;
    char unknown48[4];
    int renderFlags;
    char unknown50[0x26];
    short x;
    short y;
    char unknown7a[2];
};
struct AlchemyProjectionView {
    char unknown00[R(0x54, 0x1d4)];
    void* auxiliary;
    char unknown1d8[0x130];
    int phase;
    char unknown30c[0x1c];
    Vector3fix position;
    char unknown334[0x560];
    AlchemyProjectedWidgetView widgets[4];
    char unknowna84[0x58];
    unsigned char active;
    char unknownadd[5];
    unsigned short flags;
    char unknownae4[R(0x717, 0x79b)];
    unsigned char unknownMode : 1;
    unsigned char hidden : 1;
    unsigned char otherModeFlags : 6;
    char unknown1280[0x3b];
    unsigned char layout;
};
extern "C" {
void _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(void*);
void _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(void*);
void func_020c5414();
extern Matrix4x3* data_ov006_0216038c[3];
struct AlchemyProjectionLayout { unsigned char entries[4][4]; };
extern AlchemyProjectionLayout data_ov006_0215ff6c;
extern int data_0210a00c;
void* _Z18GetField0x3b0ValueP9GameState(GameState*);
void _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, const Vector3fix*, int*, int*);
void func_0203bd08();
void* func_0203be40();
void _Z30SetFieldsAt0x28And0x2c02076988Piii(AlchemyProjectedWidgetView*, int, int);
void _Z25ForwardTableValue02075db0P14Struct02075db0ii(AlchemyProjectedWidgetView*, short, short);
}
inline int MultiplyProjected(int a, int b)
{
    return (int)(((int64_t)a * b + 0x800) >> 12);
}
extern "C" ARM void func_ov006_02154a60(AlchemyProjectionView* state)
{
    if (state->hidden) return;
    if (!state->active) return;
    void* auxiliary = state->auxiliary;
    _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(auxiliary);
    _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(auxiliary);
    if (state->flags & 8) return;
    Matrix4x3 matrices[3];
    for (int index = 0; index < 3; index++) data_ov006_0216038c[index] = &matrices[index];
    func_020c5414();
    RenderConfig::SubmitToFifo();
    ((Object3D*)((char*)state + R(0x368, 0x4e8)))->MaybeUpdateBonePositions();
    for (int index = 0; index < 3; index++) data_ov006_0216038c[index] = NULL;
    Vector3fix positions[3] = {
        {matrices[0].translation.x, matrices[0].translation.y, matrices[0].translation.z},
        {matrices[1].translation.x, matrices[1].translation.y, matrices[1].translation.z},
        {matrices[2].translation.x, matrices[2].translation.y, matrices[2].translation.z}};
    int widths[3] = {matrices[0].entries[0], matrices[1].entries[0], matrices[2].entries[0]};
    int heights[3] = {matrices[0].entries[4], matrices[1].entries[4], matrices[2].entries[4]};
    for (int index = 0; index < 3; index++) {
        if (widths[index] < 40) widths[index] = 40;
        if (heights[index] < 40) heights[index] = 40;
    }
    unsigned char layout = state->layout;
    AlchemyProjectionLayout lookup = data_ov006_0215ff6c;
    void* camera = _Z18GetField0x3b0ValueP9GameState(GameState::GetInstance());
    if (camera) {
        AlchemyProjectedWidgetView* widget = state->widgets;
        for (unsigned char index = 0; index < 4; index++, widget++) {
            Vector3fix position = positions[lookup.entries[layout][index]];
            position.x = MultiplyProjected(position.x, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().x);
            position.y = MultiplyProjected(position.y, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().y);
            position.z = MultiplyProjected(position.z, ((Object3D*)((char*)state + R(0x164, 0x2e4)))->GetScale().z);
            Vector3fix world;
            Vector3fix offset = state->position;
            Vector3fix_Add(&position, &offset, &world);
            int x, y;
            _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(camera, &world, &x, &y);
            widget->x = x - 18;
            widget->y = y - 12;
        }
    }
    func_0203bd08();
    void* resource = func_0203be40();
    AlchemyProjectedWidgetView* widget;
    unsigned char index;
    int phase = state->phase;
    if ((state->flags & 0x2000) || (state->flags & 0x80)) {
        if (!((Object3D*)((char*)state + R(0x368, 0x4e8)))->HasAnimationStopped()) {
            index = 1;
            widget = &state->widgets[1];
            for (; index < 4; index++) {
                int positionIndex = lookup.entries[layout][index];
                int resourceOffset = index * 4 + 0x20;
                widget->renderFlags = 0x300;
                widget->resource = (char*)resource + resourceOffset * 8;
                widget->resourceIndex = resourceOffset / 4;
                _Z30SetFieldsAt0x28And0x2c02076988Piii(widget, widths[positionIndex], heights[positionIndex]);
                _Z25ForwardTableValue02075db0P14Struct02075db0ii(widget, widget->x, widget->y);
                widget++;
            }
        }
    }
    if (state->flags & 0x200) {
        data_0210a00c = 0;
        AlchemyProjectedWidgetView* widget = &state->widgets[0];
        if (phase > 983 && widget->y < 192) {
            widget->renderFlags = 0x300;
            widget->resource = (char*)resource + 0x120;
            widget->resourceIndex = 9;
            _Z30SetFieldsAt0x28And0x2c02076988Piii(widget, widths[0], heights[0]);
            _Z25ForwardTableValue02075db0P14Struct02075db0ii(widget, widget->x, widget->y);
        }
    }
}
