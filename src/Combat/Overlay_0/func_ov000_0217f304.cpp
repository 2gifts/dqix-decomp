#include <globaldefs.h>

struct Struct_0205c570;
struct Struct_0205bb84;

extern "C" int func_0205bf58(void* obj, int v);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(struct Struct_0205bb84* s);
extern "C" int func_ov000_021753d8(void* obj, int targetIndex);
extern "C" void func_0205bb04(void* obj, int value);
extern "C" void func_0205d7a0(unsigned char* obj, int val);

struct Command_0217f304 {
    char pad0[0x10];
    signed char types[8];
    signed char typeIndex;
    char pad19[0x1d - 0x19];
    signed char targetPosition;
};

struct Menu_0217f304 {
    char pad0[0x1c];
    signed char defaultPosition;
    char pad1d[0x118 - 0x1d];
    int dirty;
    char pad11c[0x188 - 0x11c];
    unsigned char cursor[0x244 - 0x188];
    unsigned char groupCursor[0x1d1c - 0x244];
    int groupIds[1];
};

// USA: func_ov000_0217f304
extern "C" ARM void func_ov000_0217f304(struct Menu_0217f304* menu, int unused, int count, struct Command_0217f304* cmd) {
    int position;
    if (cmd == NULL) return;
    int type = cmd->types[cmd->typeIndex];
    if (type != 0xe && type != 0x19) return;
    func_0205bf58(menu->groupCursor, 1);
    position = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)menu->cursor);
    int group = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((struct Struct_0205bb84*)menu->groupCursor);
    int target = cmd->targetPosition;
    int currentGroup = func_ov000_021753d8(menu, position);
    if (type == 0x19) target = menu->defaultPosition;
    if (position != target) {
        func_0205bb04(menu->groupCursor, currentGroup);
        return;
    }
    if (group == currentGroup) return;
    int prev = -1;
    int groupIndex = -1;
    for (int i = 0; i < count; i++) {
        int id = menu->groupIds[i];
        if (prev != id) {
            groupIndex++;
            prev = id;
            if (group == groupIndex) {
                func_0205d7a0(menu->cursor, i);
                menu->dirty = 1;
                return;
            }
        }
    }
}
