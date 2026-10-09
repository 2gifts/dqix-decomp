#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Vec2_0216f74c { int x; int y; };
extern "C" struct Vec2_0216f74c func_ov000_0216f74c(int* in);

// USA: func_ov025_021e1540
extern "C" ARM unsigned char func_ov025_021e1540(int index) {
    GameObject* obj = GameState::GetInstance()->GetGameObjectByIndex(index);
    int nearest = 0;
    if (obj != NULL) {
        Vector3fix origin = obj->obj3D_.position_;
        origin.y = 0;
        fix32_t minDist = 0x400000;
        int cell;
        for (cell = 0; cell < 0x51; cell++) {
            if (cell % 18 == 17) {
                continue;
            }
            Vec2_0216f74c pos = func_ov000_0216f74c(&cell);
            Vector3fix target = {0};
            target.x = pos.x;
            target.z = pos.y;
            fix32_t dist = Vector3fix_Distance(&origin, &target);
            if (dist < minDist) {
                nearest = cell;
                minDist = dist;
            }
        }
    }
    return nearest;
}
