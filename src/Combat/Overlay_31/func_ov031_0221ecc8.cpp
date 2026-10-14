#include <globaldefs.h>

struct Event0221ecc8 { short type; short result; };
struct State0221ecc8 {
    int field0, field4, field8, fieldc;
    int first, second;
    int state;
    void (*handler)(int, int);
    int third, fourth;
};
extern State0221ecc8 data_ov031_0224f620;
int DispatchOnZeroPair_0220cdd4(int, int, int);
extern "C" int func_ov031_0220d010(int, int, int);
extern "C" int func_ov031_0220cce4();
void ClearHandleIfStatusReady_0220ca88();

// USA: func_ov031_0221ecc8
extern "C" THUMB void func_ov031_0221ecc8(Event0221ecc8* event) {
    if (!event) return;
    switch (event->type) {
    case 1:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 4) {
                data_ov031_0224f620.state = 3;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(6, 0);
            } else if (data_ov031_0224f620.state == 6) {
                if (DispatchOnZeroPair_0220cdd4(data_ov031_0224f620.first, data_ov031_0224f620.second, data_ov031_0224f620.field4) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else if (data_ov031_0224f620.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f620.third, data_ov031_0224f620.fourth, data_ov031_0224f620.fieldc) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            }
        } else {
            data_ov031_0224f620.state = 1;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
        }
        break;
    case 3:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 6) {
                data_ov031_0224f620.state = 5;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(8, 0);
            }
        } else {
            data_ov031_0224f620.state = 3;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(9, 0);
        }
        break;
    case 5:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 8) {
                data_ov031_0224f620.state = 7;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(12, 0);
            }
        } else {
            data_ov031_0224f620.state = 3;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(13, 0);
        }
        break;
    case 4:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 4) {
                data_ov031_0224f620.state = 3;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(10, 0);
            } else if (data_ov031_0224f620.state == 6) {
                if (DispatchOnZeroPair_0220cdd4(data_ov031_0224f620.first, data_ov031_0224f620.second, data_ov031_0224f620.field4) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else if (data_ov031_0224f620.state == 2) {
                if (func_ov031_0220cce4() != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else if (data_ov031_0224f620.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f620.third, data_ov031_0224f620.fourth, data_ov031_0224f620.fieldc) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            }
        } else {
            data_ov031_0224f620.state = 3;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(11, 0);
        }
        break;
    case 6:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 4) {
                data_ov031_0224f620.state = 3;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(14, 0);
            } else if (data_ov031_0224f620.state == 6) {
                if (DispatchOnZeroPair_0220cdd4(data_ov031_0224f620.first, data_ov031_0224f620.second, data_ov031_0224f620.field4) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else if (data_ov031_0224f620.state == 2) {
                if (func_ov031_0220cce4() != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else if (data_ov031_0224f620.state == 8) {
                if (func_ov031_0220d010(data_ov031_0224f620.third, data_ov031_0224f620.fourth, data_ov031_0224f620.fieldc) != 3) {
                    data_ov031_0224f620.state = 3;
                    if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
                }
            } else data_ov031_0224f620.state = 3;
        } else {
            data_ov031_0224f620.state = 3;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(15, 0);
        }
        break;
    case 2:
        if (event->result == 0) {
            if (data_ov031_0224f620.state == 2) {
                ClearHandleIfStatusReady_0220ca88();
                data_ov031_0224f620.state = 0;
                if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(20, 0);
            }
        } else {
            data_ov031_0224f620.state = 3;
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(2, 0);
        }
        break;
    case 7:
        if (data_ov031_0224f620.state == 5)
            if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(5, 0);
        break;
    case 0:
    default:
        if (data_ov031_0224f620.handler) data_ov031_0224f620.handler(1, 0);
        break;
    }
}
