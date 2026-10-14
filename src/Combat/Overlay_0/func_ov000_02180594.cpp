#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define REGION_BASE 0x1f38
#else
#define REGION_BASE 0x1d00
#endif

ARM int ClearEntryFlagsAndInit02180528(char* obj);

struct Point02180594 {
    short x;
    short y;
    unsigned short delay;
};

struct Offsets02180594 {
    int x[7];
};

extern Offsets02180594 data_ov000_021836b0;

struct Obj02180594 {
    char pad0[0x910];
    int state;
    int timer;
    int field918;
    int field91c;
    int field920;
    int field924;
    int field928;
    int field92c;
    char pad930[REGION_BASE + 0x5e - 0x930];
    short scroll;
    char pad1d60[0x72 - 0x60];
    unsigned short flags;
    char pad1d74[0x7c - 0x74];
    Point02180594* points;
};

// USA: func_ov000_02180594
extern "C" ARM int func_ov000_02180594(Obj02180594* obj, int speed, SafeAllocator* allocator) {
    Offsets02180594 offsets = data_ov000_021836b0;
    int i;
    int j;
    int k;

    if (speed <= 0) {
        speed = 1;
    }
    if (obj->state < 5 && allocator != 0 && obj->points == 0) {
        obj->points = (Point02180594*)allocator->Allocate(sizeof(Point02180594) * 7);
        for (i = 0; i < 7; i++) {
            obj->points[i].x = offsets.x[i] + 0x100;
            obj->points[i].y = 8;
            obj->points[i].delay = i * 2;
        }
        obj->flags |= 8;
    }

    if (obj->state == 0) {
        obj->timer = 0;
        obj->field918 = 0;
        obj->field91c = 0;
        obj->state++;
        ClearEntryFlagsAndInit02180528((char*)obj);
        obj->flags |= 8;
        return 1;
    } else if (obj->state == 1) {
        obj->timer = 0;
        obj->scroll -= speed * 2;
        if (obj->scroll < 0) {
            obj->scroll = 0;
            obj->state++;
        }
        return 1;
    } else if (obj->state == 2) {
        if (obj->flags & 0x20) {
            obj->field928 -= speed * 16;
            if (obj->field928 <= 0x56) {
                obj->field928 = 0x56;
                obj->field91c = (obj->field91c + speed) & 0x3f;
                obj->state = 5;
            }
        } else if (obj->flags & 0x10) {
            obj->field924 -= speed * 16;
            if (obj->field924 <= 0x5c) {
                obj->field924 = 0x5c;
                obj->field918 = (obj->field918 + speed) & 0x3f;
                obj->state = 5;
            }
        } else if ((obj->flags & 8) && obj->points != 0) {
            int step = 0.0f - 1.5f * (float)(speed * 16);
            for (j = 0; j < 7; j++) {
                obj->points[j].x += step;
            }
            if (obj->points[0].x <= 0x48) {
                for (k = 0; k < 7; k++) {
                    obj->points[k].x = offsets.x[k] + 0x48;
                }
                obj->timer = 0;
                obj->state++;
            }
        }
        return 1;
    } else if (obj->state == 3) {
        if (obj->timer >= 10) {
            obj->state++;
        }
        return 1;
    } else if (obj->state == 4) {
        Point02180594* points = obj->points;
        if (points == 0) {
            obj->field92c = (float)obj->field92c - 1.5f * (float)(speed * 4);
            if (obj->field92c < -0x20) {
                obj->state++;
            }
        } else {
            int count = 0;
            int step = 0.0f - 1.5f * (float)(speed * 4);
            for (i = 0; i < 7; i++) {
                if (speed < obj->points[i].delay) {
                    obj->points[i].delay -= speed;
                } else {
                    obj->points[i].delay = 0;
                    obj->points[i].y += step;
                }
                if (obj->points[i].y < -0x20) {
                    count++;
                }
            }
            if (count == 7) {
                obj->points = 0;
                obj->state++;
            }
            if (count > 0) {
                return 0;
            }
        }
        return 1;
    }
    obj->points = 0;
    return 0;
}
