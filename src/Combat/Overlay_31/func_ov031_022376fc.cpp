#include <globaldefs.h>

struct Command022376fc {
    unsigned short type;
    unsigned short error;
    unsigned char padding_0x4[4];
    unsigned short action;
};
struct Context022376fc {
    unsigned char pad0[0x1b94];
    unsigned char state;
    unsigned char padding_0x1b95;
    unsigned char extended;
};
extern Context022376fc* data_ov031_02290d0c;
extern "C" void func_ov031_022378e4(Command022376fc*);
extern "C" void func_ov031_0223778c(Command022376fc*);
extern "C" int func_ov031_022375cc();
extern "C" void func_020c9be0(Command022376fc*);

// USA: func_ov031_022376fc
extern "C" ARM void func_ov031_022376fc(Command022376fc* command) {
    if (command->error) return;
    Context022376fc* context = data_ov031_02290d0c;
    if (context->state) {
        if (command->type == 2) context->state = 2;
        return;
    }
    if (command->type != 0x26) return;
    switch (command->action) {
    case 5:
        if (context->extended) func_ov031_022378e4(command);
        else func_ov031_0223778c(command);
        func_ov031_022375cc();
        break;
    case 4:
        func_ov031_022375cc();
        break;
    default:
        func_020c9be0(command);
        break;
    }
}
