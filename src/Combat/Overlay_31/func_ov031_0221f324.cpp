#include <globaldefs.h>
struct BattleEvent0221f324 {
    short type;
    short result;
};
struct EventState0221f324 {
    unsigned char unknown0[0x28];
    unsigned char *fieldData;
    int state;
    unsigned char unknown30[0x14];
    int pairA;
    int pairB;
    void *actor;
    unsigned char unknown50[8];
    int flags;
    int unknown5c;
    int pairFlags;
};
extern EventState0221f324 data_ov031_0224f670;
extern void (*data_ov031_0224f6f0)(int, int);
int DispatchOnZeroPair_0220cdd4(int, int, int);
extern "C" int func_ov031_0220d010(void *, unsigned char *, int);
extern "C" int func_ov031_0220cce4();
void ClearHandleIfStatusReady_0220ca88();
static inline int DispatchBattlePair(int a, int b, int flags) {
    return DispatchOnZeroPair_0220cdd4(a, b, flags);
}

// USA: func_ov031_0221f324
extern "C" THUMB void func_ov031_0221f324(BattleEvent0221f324 *event) {
    if (!event) return;
    switch (event->type) {
    case 1:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 4) {
                data_ov031_0224f670.state = 3;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(6, 0);
            } else if (data_ov031_0224f670.state == 6) {
                if (DispatchBattlePair(data_ov031_0224f670.pairA, data_ov031_0224f670.pairB, data_ov031_0224f670.pairFlags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f670.actor, data_ov031_0224f670.fieldData, data_ov031_0224f670.flags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            }
        } else {
            data_ov031_0224f670.state = 1;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
        }
        break;
    case 3:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 6) {
                data_ov031_0224f670.state = 5;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(8, 0);
            }
        } else {
            data_ov031_0224f670.state = 3;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(9, 0);
        }
        break;
    case 5:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 8) {
                data_ov031_0224f670.state = 7;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(12, 0);
            }
        } else {
            data_ov031_0224f670.state = 3;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(13, 0);
        }
        break;
    case 4:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 4) {
                data_ov031_0224f670.state = 3;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(10, 0);
            } else if (data_ov031_0224f670.state == 6) {
                if (DispatchBattlePair(data_ov031_0224f670.pairA, data_ov031_0224f670.pairB, data_ov031_0224f670.pairFlags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 2) {
                if (func_ov031_0220cce4() != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f670.actor, data_ov031_0224f670.fieldData, data_ov031_0224f670.flags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            }
        } else {
            data_ov031_0224f670.state = 3;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(11, 0);
        }
        break;
    case 6:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 4) {
                data_ov031_0224f670.state = 3;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(14, 0);
            } else if (data_ov031_0224f670.state == 6) {
                if (DispatchBattlePair(data_ov031_0224f670.pairA, data_ov031_0224f670.pairB, data_ov031_0224f670.pairFlags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 2) {
                if (func_ov031_0220cce4() != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f670.actor, data_ov031_0224f670.fieldData, data_ov031_0224f670.flags) != 3) {
                    data_ov031_0224f670.state = 3;
                    if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
                }
            } else if (data_ov031_0224f670.state == 7) {
                data_ov031_0224f670.state = 3;
            }
        } else {
            data_ov031_0224f670.state = 3;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(15, 0);
        }
        break;
    case 2:
        if (event->result == 0) {
            if (data_ov031_0224f670.state == 2) {
                ClearHandleIfStatusReady_0220ca88();
                data_ov031_0224f670.state = 0;
                if (data_ov031_0224f6f0) data_ov031_0224f6f0(20, 0);
            }
        } else {
            data_ov031_0224f670.state = 3;
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(2, 0);
        }
        break;
    case 7:
        if (data_ov031_0224f670.state == 5)
            if (data_ov031_0224f6f0) data_ov031_0224f6f0(5, 0);
        break;
    case 8:
        if (data_ov031_0224f6f0) data_ov031_0224f6f0(4, 0);
        break;
    case 9:
        data_ov031_0224f670.state = 0;
        if (data_ov031_0224f6f0) data_ov031_0224f6f0(3, 0);
        break;
    case 0:
    default:
        if (data_ov031_0224f6f0) data_ov031_0224f6f0(1, 0);
        break;
    }
}
