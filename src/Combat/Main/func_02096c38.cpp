#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <System/Graphics.h>

struct StructAt020473c8 { char data[0x88]; };
struct StructAt020472e4 { char data[0x88]; };
union TouchRenderEntry02096c38 {
    StructAt020473c8 plain;
    StructAt020472e4 transformed;
};
struct Obj020968d0 {
    TouchRenderEntry02096c38 entries[4];
    unsigned char startX, startY, endX, endY, flag;
};
struct Facing02096c38 { char pad_0[0xae]; short angle; };
int CheckAndComputeDistance020968d0(Obj020968d0*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
void RenderTransformedFlaggedIndexedEntry(StructAt020472e4*, int);
void IssueCommand0x19(int);
extern "C" void __clear(void*, int);

// USA: func_02096c38
extern "C" ARM void func_02096c38(Obj020968d0* object, int startX, int startY, int endX, int endY) {
    float converted;
    int firstX, firstY, lastX, lastY;
    int scaled = startX << 12;
    if (startX > 0) converted = 0.5f + (float)scaled;
    else converted = (float)scaled - 0.5f;
    firstX = (int)converted;
    scaled = startY << 12;
    if (startY > 0) converted = 0.5f + (float)scaled;
    else converted = (float)scaled - 0.5f;
    firstY = (int)converted;
    scaled = endX << 12;
    if (endX > 0) converted = 0.5f + (float)scaled;
    else converted = (float)scaled - 0.5f;
    lastX = (int)converted;
    scaled = endY << 12;
    if (endY > 0) converted = 0.5f + (float)scaled;
    else converted = (float)scaled - 0.5f;
    lastY = (int)converted;
    Vector3fix start, end;
    Matrix4x3 rotation;
    Vector3fix direction;
    int distance;
    __clear(&start, 12);
    start.x = firstX;
    start.y = firstY;
    __clear(&end, 12);
    end.x = lastX;
    end.y = lastY;
    int useFacing = 0;
    if (!CheckAndComputeDistance020968d0(object, &distance)) {
        if (!object->flag) return;
        distance = 0x8000;
        useFacing = 1;
    }
    if (useFacing) {
        GameState* game = GameState::GetInstance();
        if (game) {
            GameObject* protagonist = game->GetProtagonist();
            if (protagonist) {
                int angle = ((Facing02096c38*)protagonist)->angle;
                int cosine = fix32cos(angle);
                direction.x = fix32sin(angle);
                direction.y = 0;
                direction.z = cosine;
                Vector3fix_Normalize(&direction, &direction);
            }
        }
    } else {
        Vector3fix_Subtract(&end, &start, &direction);
        Vector3fix_Normalize(&direction, &direction);
    }
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = firstX;
    GXFIFO_MATRIX_TRANSLATE = firstY;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = -0x8000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    RenderFlaggedIndexedEntry(&object->entries[0].plain, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    short angle = fix32ReduceAngle0To2Pi(-fix32_Atan2(direction.x, direction.y));
    rotation = RotationMatrixZ(angle);
    IssueCommand0x19((int)&rotation);
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = 0x1000;
    GXFIFO_MATRIX_PUSH = 0;
    int scale = fix32_Divide(distance - 0x5000, 0x8000);
    GXFIFO_MATRIX_SCALE = 0x800;
    GXFIFO_MATRIX_SCALE = scale;
    GXFIFO_MATRIX_SCALE = 0x1000;
    RenderTransformedFlaggedIndexedEntry(&object->entries[1].transformed, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    int currentDistance = distance;
    int depth = 0x3000;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = currentDistance;
    GXFIFO_MATRIX_TRANSLATE = depth;
    GXFIFO_MATRIX_SCALE = 0xc00;
    GXFIFO_MATRIX_SCALE = -0xc00;
    GXFIFO_MATRIX_SCALE = 0x1000;
    RenderTransformedFlaggedIndexedEntry(&object->entries[2].transformed, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = -0x4000;
    GXFIFO_MATRIX_TRANSLATE = 0x2000;
    RenderFlaggedIndexedEntry(&object->entries[3].plain, 1);
    GXFIFO_MATRIX_POP = 1;
    GXFIFO_MATRIX_POP = 1;
}
