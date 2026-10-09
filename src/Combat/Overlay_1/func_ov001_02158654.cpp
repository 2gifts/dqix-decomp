#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"

struct MoveCmd_02158654 {
    int header;
    Vector3fix delta;
    char pad10[0xc];
    int duration;
};

struct MoveObj_02158654 {
    char pad0[0x44];
    int frame;
    char pad48[0x10];
    Vector3fix pos;
    char pad64[0xd0];
    int moving;
    Vector3fix offset;
    char pad144[0xc];
    Vector3fix prevPos;
    char pad15c[0x8c8];
    int dirty;
};

// USA: func_ov001_02158654
extern "C" ARM int func_ov001_02158654(struct MoveCmd_02158654* cmd, struct MoveObj_02158654* obj) {
    if (cmd->duration <= -1) {
        obj->moving = 1;
        memcpy(&obj->prevPos, &obj->pos, 0xc);
        int phase = obj->frame % 4;
        if (phase == 0) {
            Vector3fix_Add(&obj->pos, &cmd->delta, &obj->pos);
        } else if (phase == 2) {
            Vector3fix_Subtract(&obj->pos, &cmd->delta, &obj->pos);
        }
        obj->frame++;
        obj->dirty = 1;
    } else {
        if (obj->frame >= cmd->duration) {
            obj->frame = 0;
            obj->moving = 0;
            return 0;
        }

        if (obj->frame <= 0) {
            obj->moving = 1;
            memcpy(&obj->offset, &cmd->delta, 0xc);
            obj->dirty = 1;
        }

        memcpy(&obj->prevPos, &obj->pos, 0xc);
        int phase = obj->frame % 4;
        if (phase == 0) {
            Vector3fix_Add(&obj->pos, &obj->offset, &obj->pos);
        } else if (phase == 2) {
            Vector3fix_Subtract(&obj->pos, &obj->offset, &obj->pos);
            Vector3fix step;
            Vector3fixDivideScalar(&cmd->delta, cmd->duration << 12, &step);
            Vector3fixMultiplyScalar(&step, obj->frame << 12, &step);
            Vector3fix_Subtract(&step, &obj->offset, &cmd->delta);
        }

        obj->frame++;
    }
    return 1;
}
