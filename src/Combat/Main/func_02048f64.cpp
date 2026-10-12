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

extern "C" int _Z20GetSubstructByte0x56Ph(FormationPathActor* actor);
extern "C" void _Z26DispatchTargetByte020494c0P11Obj020494c0(FormationPathActor* actor);
extern "C" void _Z21SetByteSavingPreviousP11Foo02033b58h(FormationPathActor* actor, unsigned char v);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(FormationPathActor* actor, int v);
extern "C" void _ZN8Object3D25SetAnimationPlaybackSpeedEsi(FormationPathActor* actor, short speed, int frames);
extern "C" void _Z29ClearSubFieldsAndFlag02049520P11Obj02049520(FormationPathActor* actor);
extern "C" void _Z30ApplyFlag0x4IfEligible02049a74P11Obj02049a74(FormationPathActor* actor);
extern "C" void _Z23ResetInnerState02048c90P11Obj02048c90(FormationPathActor* actor);
extern "C" void _Z20SetSubstructByte0x1cPhh(FormationPathActor* actor, unsigned char v);
extern "C" void _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(FormationPathActor* actor, int v);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(FormationPathActor* actor, int angle);
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
        if (_Z20GetSubstructByte0x56Ph(actor)) {
            if (actor->unknownBe != 0) {
                _Z26DispatchTargetByte020494c0P11Obj020494c0(actor);
            }
            _Z21SetByteSavingPreviousP11Foo02033b58h(actor, 0);
            keepFacing = 0;
        }
    } else if (_Z20GetSubstructByte0x56Ph(actor)) {
        _Z24SetByteIfChanged02033b68P11Obj02033b68i(actor, 1);
    }

    short animSpeed = advance * 12;
    if (animSpeed < 0xc00) {
        animSpeed = 0xc00;
    } else if (animSpeed > 0x1400) {
        animSpeed = 0x1400;
    }
    _ZN8Object3D25SetAnimationPlaybackSpeedEsi(actor, animSpeed, 0);
    path->progress = progress + advance;

    Vector3i target;
    if (remaining > 4) {
        target = func_ov025_021ee488(points, n, progress + advance);
    } else {
        target = points[lastIndex];
        if (_Z20GetSubstructByte0x56Ph(actor) && (actor->path->flags & 0x40)) {
            _Z29ClearSubFieldsAndFlag02049520P11Obj02049520(actor);
            _Z30ApplyFlag0x4IfEligible02049a74P11Obj02049a74(actor);
        }
        _Z23ResetInnerState02048c90P11Obj02048c90(actor);
        _ZN8Object3D25SetAnimationPlaybackSpeedEsi(actor, 0x1000, 500);
        _Z20SetSubstructByte0x1cPhh(actor, path->cell1d);
        if (_Z20GetSubstructByte0x56Ph(actor) && actor->unknownBe == 1) {
            _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(actor, 0);
        }
        _Z26DispatchTargetByte020494c0P11Obj020494c0(actor);
        keepFacing = 0;
    }

    Vector3i current = actor->position;
    Vector3i delta;
    Vector3fix_Subtract(&target, &current, &delta);
    Vector3fix_Normalize(&delta, &delta);
    fix32_t angle   = fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    actor->position = target;
    if (keepFacing) {
        _Z21SetVecYByMode02033834P11Obj02033834i(actor, angle);
    }
}
