#include <globaldefs.h>

struct Message022397bc { unsigned short field0; unsigned short error; unsigned short type; };
struct Session022397bc { char pad[0x40]; int phase; int state; char pad48[0x1398]; char request[1]; };
struct State022397bc { void (*handler)(unsigned int, void*, ...); Session022397bc* session; };
extern State022397bc data_ov031_02290d18;
extern char data_ov031_0224c3c4[];
extern char data_ov031_0224c3a4[];
void SetField54IfTagNot9Or10_ov031_022393e4(int);
extern "C" void func_ov031_02239368(int);
int InvokeMaskAndSetField54_022398e8();
extern "C" int func_020d5d34(void*, int, int, int, int);

// USA: func_ov031_022397bc
extern "C" ARM void func_ov031_022397bc(Message022397bc* message) {
    if (message->error) {
        SetField54IfTagNot9Or10_ov031_022393e4(message->error);
        func_ov031_02239368(9);
        return;
    }
    switch (message->type) {
    case 10:
        if (data_ov031_02290d18.session->state == 2) {
            if (data_ov031_02290d18.session->phase == 4) {
                if (InvokeMaskAndSetField54_022398e8()) return;
                if (data_ov031_02290d18.handler) data_ov031_02290d18.handler(0x08000000, data_ov031_0224c3c4);
                func_ov031_02239368(9);
                return;
            } else if (data_ov031_02290d18.session->phase == 6) {
                return;
            }
        } else if (data_ov031_02290d18.session->state == 4) {
            int result = func_020d5d34(data_ov031_02290d18.session->request, 13, 7, 68, 1);
            if (result) {
                SetField54IfTagNot9Or10_ov031_022393e4(result);
                func_ov031_02239368(9);
            } else {
                func_ov031_02239368(5);
            }
            return;
        }
        func_ov031_02239368(4);
        break;
    case 11:
        break;
    case 12:
    case 13:
    default:
        if (data_ov031_02290d18.handler) data_ov031_02290d18.handler(0x08000000, data_ov031_0224c3a4, message->type);
    }
}
