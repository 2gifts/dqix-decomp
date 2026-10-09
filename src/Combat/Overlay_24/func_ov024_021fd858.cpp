#include <globaldefs.h>

struct Action_021fd858 {
    char pad0[0x18];
    unsigned int kind : 5;
    unsigned int rest18 : 27;
};

class Obj_021fd858 {
public:
    char pad0[0x64c];
    Action_021fd858* action;
    char pad650[0x665 - 0x650];
    unsigned char flags665;
};

typedef void (Obj_021fd858::*Handler_021fd858)();

struct InitGuard_021fd858 { char pad0[8]; unsigned int flags; };
extern InitGuard_021fd858 data_ov024_02200150;
extern Handler_021fd858 data_ov024_021ffcec[23];
extern const Handler_021fd858 data_020e6d5c;

// USA: func_ov024_021fd858
extern "C" ARM void func_ov024_021fd858(Obj_021fd858* obj) {
    Action_021fd858* action = obj->action;
    obj->flags665 |= 0x80;
    unsigned int guard = data_ov024_02200150.flags;
    if (!(guard & 1)) {
        data_ov024_021ffcec[0] = data_020e6d5c;
        data_ov024_021ffcec[3] = data_020e6d5c;
        data_ov024_021ffcec[12] = data_020e6d5c;
        data_ov024_021ffcec[13] = data_020e6d5c;
        data_ov024_021ffcec[14] = data_020e6d5c;
        data_ov024_021ffcec[15] = data_020e6d5c;
        data_ov024_021ffcec[16] = data_020e6d5c;
        data_ov024_021ffcec[17] = data_020e6d5c;
        data_ov024_021ffcec[18] = data_020e6d5c;
        data_ov024_021ffcec[21] = data_020e6d5c;
        data_ov024_021ffcec[22] = data_020e6d5c;
        data_ov024_02200150.flags = guard | 1;
    }
    unsigned int kind = action->kind;
    if (kind < 23 && data_ov024_021ffcec[kind] != 0) {
        (obj->*data_ov024_021ffcec[kind])();
    }
}
