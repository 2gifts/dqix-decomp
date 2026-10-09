#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);

struct PackedTriple02082cdc {
    unsigned int x : 10;
    unsigned int y : 10;
    unsigned int z : 10;
    unsigned int reserved : 2;
};
struct Obj02082cdc { PackedTriple02082cdc values[3]; };
struct Obj020827c4 { char data[0x1c]; };
struct CombatSelection {
    signed char selected : 6;
    unsigned char active : 1;
    unsigned char reserved : 1;
    unsigned char count : 4;
    unsigned char ready : 1;
    unsigned char mode : 3;
    unsigned char enabled[13];
    unsigned char status[13];
    int entries[13];
    int current;
    unsigned short selectionMask;
    char pad56[2];
    Obj02082cdc triples[13];
    unsigned short fieldf4;
    unsigned char flags[27];
    unsigned char groupFlags[9];
    unsigned char commandFlags[36];
    unsigned char field13e;
    unsigned char cursor : 3;
    unsigned char capacity : 5;
    unsigned char field140[12];
    PackedTriple02082cdc vectors[4];
    unsigned int timer : 10;
    unsigned int timerLimit : 10;
    unsigned int reserved15c : 12;
    Obj020827c4 timers;
    unsigned char history[0xc0];
};
extern "C" void _Z26ClearPackedTriples02082cdcP11Obj02082cdc(Obj02082cdc*);
extern "C" void _Z26InitFlagsAndTimers020827c4P11Obj020827c4(Obj020827c4*);

// USA: func_02086404
extern "C" ARM void func_02086404(CombatSelection* selection) {
    selection->selected = -1;
    selection->active = 0;
    selection->count = 0;
    selection->ready = 0;
    for (int i = 0; i < 13; ++i) {
        selection->entries[i] = 0;
        selection->enabled[i] = 1;
        selection->status[i] = 0;
        _Z26ClearPackedTriples02082cdcP11Obj02082cdc(&selection->triples[i]);
    }
    selection->current = 0;
    selection->selectionMask = 0;
    selection->fieldf4 = 0;
    memset(selection->flags, 0, sizeof(selection->flags));
    memset(selection->groupFlags, 0, sizeof(selection->groupFlags));
    memset(selection->commandFlags, 0, sizeof(selection->commandFlags));
    selection->field13e = 0;
    memset(selection->field140, 0, sizeof(selection->field140));
    selection->vectors[0].x = 0;
    selection->vectors[0].y = 0;
    selection->vectors[0].z = 0;
    selection->vectors[1].x = 0;
    selection->vectors[1].y = 0;
    selection->vectors[1].z = 0;
    selection->vectors[2].x = 0;
    selection->vectors[2].y = 1;
    selection->vectors[2].z = 0;
    selection->vectors[3].x = 1;
    selection->vectors[3].y = 0;
    selection->vectors[3].z = 0;
    selection->timer = 0;
    selection->timerLimit = 0;
    _Z26InitFlagsAndTimers020827c4P11Obj020827c4(&selection->timers);
    memset(selection->history, -1, sizeof(selection->history));
    selection->mode = 0;
    selection->cursor = 0;
    selection->capacity = 5;
}
