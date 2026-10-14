#include <globaldefs.h>
#include "Combat/FormationPosition.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct FormationPathState {
    char unknown00[0x1c];
    unsigned char cell1c;
    unsigned char cell1d;
    unsigned char cell1e;
    unsigned char cell1f;
    unsigned int flags;
    unsigned char cells[0x10];
    unsigned char cellCount;
    char unknown35[0x3];
    int progress;
    short speedScale;
    char unknown3e[0x2];
    int currentPosition[3];
};

struct FormationPathActor {
    char unknown00[0x44];
    Vector3i position;
    char unknown50[0x6e];
    unsigned char unknownBe;
    char unknownbf[0x7d];
    FormationPathState* path;
};

int GetSubstructByte0x56_02049ee8(unsigned char*);
struct Obj020494c0;
void DispatchTargetByte020494c0(Obj020494c0*);
struct Foo02033b58;
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
struct Obj02033b68;
void SetByteIfChanged02033b68(Obj02033b68*, int);
struct Obj02049520;
void ClearSubFieldsAndFlag02049520(Obj02049520*);
struct Obj02049a74;
void ApplyFlag0x4IfEligible02049a74(Obj02049a74*);
struct Obj02048c90;
void ResetInnerState02048c90(Obj02048c90*);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct Obj02033834;
void SetVecYByMode02033834(Obj02033834*, int);
extern "C" Vector3i func_ov025_021ee488(Vector3i* points, int count, int progress);

static inline Vec2_0216f74c GetFormationPosition(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_02048f64
extern "C" ARM void func_02048f64(FormationPathActor* actor) {
    if (!(actor->path->flags & 0x10)) {
        return;
    }
    fix32_t step;
    GameState* gs            = GameState::GetInstance();
    FormationPathState* path = actor->path;
    int count                = path->cellCount;
    unsigned char* cells     = path->cells;
    if (count == 0) {
        path->flags &= ~0x10;
        return;
    }
    step             = FIX32_MULTIPLY((short)gs->GetAnimationDeltaTime(), 0xcc);
    fix32_t progress = path->progress;
    if (progress < 0) {
        path->progress = progress + step;
        return;
    }

    Vector3i points[16];
    int i;
    for (i = 0; i < count; i++) {
        Vec2_0216f74c pos = GetFormationPosition(cells[i]);
        points[i].x       = pos.x;
        points[i].y       = 0xcc;
        points[i].z       = pos.y;
    }
    int startZ  = path->currentPosition[2];
    int startX  = path->currentPosition[0];
    points[0].x = startX;
    points[0].y = 0xcc;
    points[0].z = startZ;

    int n = count;
    if (path->cell1f != 0xff) {
        Vec2_0216f74c pos = GetFormationPosition(path->cell1f);
        points[count].x   = pos.x;
        points[count].y   = 0xcc;
        points[count].z   = pos.y;
        n                 = count + 1;
    }
    if (n < 4) {
        int last = n - 1;
        for (int j = n; j < 4; j++) {
            points[j] = points[last];
        }
        n = 4;
    }

    int seg       = (int)((float)path->progress / 4096.0f);
    Vector3i a    = points[seg];
    Vector3i b    = points[seg + 1];
    fix32_t inverse = fix32_Divide(0x3000, Vector3fix_Distance(&a, &b));
    fix32_t speed   = FIX32_MULTIPLY(inverse, step);
    int lastIndex  = count - 1;
    if (path->speedScale < 0x1000) {
        path->speedScale += 0xcc;
    }
    fix32_t advance   = FIX32_MULTIPLY(speed, path->speedScale);
    int keepFacing    = 1;
    fix32_t remaining = FIX32_MULTIPLY((lastIndex << 12) - progress, 0x333);
    if (remaining < advance) {
        advance = remaining;
        if (GetSubstructByte0x56_02049ee8((unsigned char*)actor)) {
            if (actor->unknownBe != 0) {
                DispatchTargetByte020494c0((Obj020494c0*)actor);
            }
            SetByteSavingPrevious((Foo02033b58*)actor, 0);
            keepFacing = 0;
        }
    } else if (GetSubstructByte0x56_02049ee8((unsigned char*)actor)) {
        SetByteIfChanged02033b68((Obj02033b68*)actor, 1);
    }

    short animSpeed = advance * 12;
    if (animSpeed < 0xc00) {
        animSpeed = 0xc00;
    } else if (animSpeed > 0x1400) {
        animSpeed = 0x1400;
    }
    ((Object3D*)actor)->SetAnimationPlaybackSpeed(animSpeed, 0);
    path->progress = progress + advance;

    Vector3i target;
    if (remaining > 4) {
        target = func_ov025_021ee488(points, n, progress + advance);
    } else {
        target = points[lastIndex];
        if (GetSubstructByte0x56_02049ee8((unsigned char*)actor) && (actor->path->flags & 0x40)) {
            ClearSubFieldsAndFlag02049520((Obj02049520*)actor);
            ApplyFlag0x4IfEligible02049a74((Obj02049a74*)actor);
        }
        ResetInnerState02048c90((Obj02048c90*)actor);
        ((Object3D*)actor)->SetAnimationPlaybackSpeed(0x1000, 500);
        SetSubstructByte0x1c_02049390((unsigned char*)actor, path->cell1d);
        if (GetSubstructByte0x56_02049ee8((unsigned char*)actor) && actor->unknownBe == 1) {
            SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        }
        DispatchTargetByte020494c0((Obj020494c0*)actor);
        keepFacing = 0;
    }

    Vector3i current = actor->position;
    Vector3i delta;
    Vector3fix_Subtract(&target, &current, &delta);
    Vector3fix_Normalize(&delta, &delta);
    fix32_t angle   = fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    actor->position = target;
    if (keepFacing) {
        SetVecYByMode02033834((Obj02033834*)actor, angle);
    }
}
