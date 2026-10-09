#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov001_02158f64(void* node, EventVec3 v1, EventVec3 v2, int d, int one, int ip);
char* GetField0x3b0Value(GameState* gs);

struct Data24_0215dbd0 { char pad[0x24]; void* field24; };
extern Data24_0215dbd0 data_ov001_02165880 __attribute__((aligned(4)));

static inline int FixedMulRound_0215dbd0(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_ov001_0215dbd0
extern "C" ARM int func_ov001_0215dbd0(void* self) {
    GameState* gs = GameState::GetInstance();
    EventVec3 target;
    memset(&target, 0, 0xc);
    EventVec3 origin;
    memset(&origin, 0, 0xc);
    origin.a = (int)(4096.0f * func_ov017_021d6110(self));
    origin.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    origin.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));

    Vector3fix polar = *(Vector3fix*)(GetField0x3b0Value(gs) + 0x70);
    Vector3fix offset;
    offset.x = 0;
    offset.y = polar.y;
    offset.z = fix32_Sqrt(FixedMulRound_0215dbd0(polar.z, polar.z) - FixedMulRound_0215dbd0(polar.y, polar.y));

    Matrix4x3 rot = RotationMatrixY(polar.x);
    Mat4x3_ApplyToVector(&offset, &rot, &offset);
    Vector3fix_Add((Vector3fix*)&origin, &offset, (Vector3fix*)&target);

    int d = func_ov017_021d60f4((char*)self + 0x18);
    func_ov001_02158f64(data_ov001_02165880.field24, target, origin, d, 1, 0);
    return 1;
}
