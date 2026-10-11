#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"


struct Vec3 { int x; int y; int z; };

struct Vec3_02030ef0;
extern "C" void _Z22Vector3fixDivideScalarPK8Vector3iiPS_(Vec3_02030ef0* src, unsigned int a, Vec3_02030ef0* dst);

struct Vec3Fixed02030e2c { int x; int y; int z; };
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(Vec3Fixed02030e2c* in, int scale, Vec3Fixed02030e2c* out);


extern "C" int func_ov001_02164578(void* table, int index, void* arg2, int arg3, float arg4);
extern "C" int func_02012fe4(void);
extern "C" int func_02018fbc(int seed, void* v);
extern void* data_ov001_02165884;

// USA: func_ov001_021592bc
// JPN: func_ov001_0215a994
extern "C" ARM int func_ov001_021592bc(char* req, char* state) {
    int flag = 0;
    GameState* battleStruct = GameState::GetInstance();
    int fixedScale = (int)(battleStruct->GetTickCount() << 12);

    if (*(int*)(state + 0x48) >= *(int*)(req + 0x10) * 2) {
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            memcpy(state + 0x74, req + 0x4, 0xc);
        } else if (mode == 1) {
            *(int*)(state + 0x74) = *(int*)(req + 0x4);
            *(int*)(state + 0x7c) = *(int*)(req + 0xc);
        }
        void* arg2 = req + 0x1c;
        if (arg2) {
            func_ov001_02164578(data_ov001_02165884, *(int*)(state + 0x70), arg2, flag, 0.0f);
        }
        *(int*)(state + 0x48) = 0;
        return 0;
    }

    if (*(int*)(state + 0x48) <= 0) {
        Vec3 delta;
        Vector3fix_Subtract((const Vector3fix*)((Vec3*)(req + 0x4)), (const Vector3fix*)((Vec3*)(state + 0x74)), (Vector3fix*)&delta);
        _Z22Vector3fixDivideScalarPK8Vector3iiPS_((Vec3_02030ef0*)&delta, (*(unsigned int*)(req + 0x10)) << 13, (Vec3_02030ef0*)(state + 0x94));
    } else {
        Vec3Fixed02030e2c tmp = *(Vec3Fixed02030e2c*)(state + 0x94);
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&tmp, fixedScale, &tmp);
        int mode = *(int*)(req + 0x14);
        if (mode == 0) {
            Vector3fix_Add((const Vector3fix*)((Vec3*)(state + 0x74)), (const Vector3fix*)((Vec3*)&tmp), (Vector3fix*)((Vec3*)(state + 0x74)));
        } else if (mode == 1) {
            Vector3fix_Add((const Vector3fix*)((Vec3*)(state + 0x74)), (const Vector3fix*)((Vec3*)&tmp), (Vector3fix*)((Vec3*)(state + 0x74)));
            int seed = func_02012fe4();
            *(int*)(state + 0x78) = func_02018fbc(seed, state + 0x74);
        }
    }

    *(int*)(state + 0x48) += (int)battleStruct->GetTickCount();
    return 1;
}
