#include <globaldefs.h>
#include <System/Interrupts.h>

struct ConnectionArena {
    int kind;
    unsigned char* allocation;
    unsigned int size;
    int field_0xc;
};

struct ConnectionWorkspace {
    char field_0x0[8];
    ConnectionArena* arena;
    char field_0xc[0x1c];
    unsigned char* memory;
    int state;
    char field_0x30[0xc];
    void* field_0x3c;
    char field_0x40[0xc];
    void* field_0x4c;
};

extern ConnectionWorkspace data_ov031_0224f670;
extern int data_ov031_0224f6f0;
extern "C" int func_ov031_0220c970(void* workspace, unsigned int size);
extern "C" int func_ov031_0220cae0(ConnectionArena* arena, void (*callback)());
extern "C" void func_ov031_0221f324();

// USA: func_ov031_0221f8d8
extern "C" THUMB int func_ov031_0221f8d8(int mode, unsigned char* memory, unsigned int size) {
    int interruptState = DisableIRQInterrupts();
    ConnectionArena* arena = (ConnectionArena*)(((unsigned int)memory + 0x63) & ~3);
    unsigned int address = (unsigned int)arena + 0x2f;
    data_ov031_0224f670.memory = memory;
    data_ov031_0224f670.arena = arena;
    address &= ~0x1f;
    data_ov031_0224f670.field_0x3c = (void*)address;
    address = (address + 0x231f) & ~0x1f;
    data_ov031_0224f670.field_0x4c = (void*)address;
    address = (address + 0xdf) & ~0x1f;
    arena->allocation = (unsigned char*)address;
    data_ov031_0224f670.arena->size = memory + size - data_ov031_0224f670.arena->allocation;
    data_ov031_0224f670.arena->field_0xc = 0;
    data_ov031_0224f670.arena->kind = 3;
    data_ov031_0224f6f0 = mode;
    if (data_ov031_0224f670.state == 0) {
        if (func_ov031_0220c970(data_ov031_0224f670.field_0x3c, 0x2300) != 0) {
            SetIRQInterruptState(interruptState);
            return 0;
        }
        data_ov031_0224f670.state = 1;
    }
    if (data_ov031_0224f670.state == 1) {
        if (func_ov031_0220cae0(data_ov031_0224f670.arena, func_ov031_0221f324) != 3) {
            SetIRQInterruptState(interruptState);
            return 0;
        }
        data_ov031_0224f670.state = 4;
        SetIRQInterruptState(interruptState);
        return 1;
    }
    SetIRQInterruptState(interruptState);
    return 0;
}
