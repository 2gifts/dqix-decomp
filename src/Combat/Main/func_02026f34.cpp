#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagWord02046708;

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708* flags, unsigned int mask);

struct StateObj0201fa2c {
    unsigned char state;
    unsigned char f1;
    unsigned char flags;
    unsigned char pad3;
    unsigned short timer;
    char pad6[0x14 - 6];
};

struct StateObj0201fc40 {
    unsigned char state;
    unsigned char f1;
    unsigned char flags;
    unsigned char pad3;
    unsigned short timer;
    char pad6[0x14 - 6];
};

struct Stopwatch0201fbac {
    unsigned char state;
    unsigned char b1;
    unsigned char flags;
    unsigned char pad3;
    unsigned short timer;
    char pad6[0x14 - 6];
};

struct Entry02026f34 {
    char pad[0x1c];
    unsigned char flag1c;
    unsigned char flag1d;
};

struct Member02026f34 {
    char pad[0x1b2];
    unsigned short hp;
};

extern StateObj0201fa2c data_020fdc60[4];
extern Entry02026f34 data_020fdcb0[4];

extern "C" void _Z28UpdateStopwatchState0201fbacP17Stopwatch0201fbac(struct Stopwatch0201fbac* t);
extern "C" void _Z23ResetStateTimer0201fc40P16StateObj0201fc40i(struct StateObj0201fc40* p, int arg);
extern "C" void _Z24UpdateStateTimer0201fa2cP16StateObj0201fa2cj(StateObj0201fa2c* obj, unsigned int arg);
extern "C" void func_020200c0(int index, void* obj);

typedef void (*UpdateStateTimer0201fa2cFn)(StateObj0201fa2c* obj, unsigned int arg, unsigned char id);

// USA: func_02026f34
extern "C" ARM void func_02026f34(void* objv) {
    unsigned char* obj = (unsigned char*)objv;
    char* base;
    if (_Z17TestFlags02046708P16FlagWord02046708j((FlagWord02046708*)_Z27GetDataPtr02114e04_020d6c00v(), 0x41)) return;

    GameState* gs = GameState::GetInstance();
    unsigned int dt = gs->GetEffectiveDeltaTime();
    base = (char*)obj;
    base += 0xe8;

    for (int i = 0; i < obj[0x75c]; i++) {
        unsigned char* p = obj + i;
        unsigned char id = p[0x758];
        StateObj0201fa2c* sw;
        Entry02026f34* ent;
        unsigned int mask = (unsigned char)(1 << id);

        if (!(obj[0x55d] & mask)) continue;

        sw = (StateObj0201fa2c*)((char*)data_020fdc60 + i * 0x14);
        ent = (Entry02026f34*)((char*)data_020fdcb0 + (id << 5));
        void* member = gs->GetPartyMemberByIndex(id);
        if (member == NULL) continue;

        int timer = 0;
        if (ent->flag1c) timer = 0x7d0;

        if (ent->flag1d || (obj[0x55e] & mask)) {
            func_020200c0((signed char)id, base + id * 0x28);
            obj[0x55e] &= ~mask;
        }

        if (data_020fdc60[0].flags & 2) {
            _Z28UpdateStopwatchState0201fbacP17Stopwatch0201fbac((struct Stopwatch0201fbac*)sw);
        } else {
            if ((sw->flags & 1) && ((Member02026f34*)member)->hp == 0) {
                sw->flags &= ~1;
                sw->timer = 0x7d0;
            } else if (((Member02026f34*)member)->hp != 0) {
                _Z28UpdateStopwatchState0201fbacP17Stopwatch0201fbac((struct Stopwatch0201fbac*)sw);
                sw->flags |= 1;
            } else if (timer > 0 && (obj + id)[0x558]) {
                _Z23ResetStateTimer0201fc40P16StateObj0201fc40i((struct StateObj0201fc40*)sw, timer);
            }
        }
        ((UpdateStateTimer0201fa2cFn)_Z24UpdateStateTimer0201fa2cP16StateObj0201fa2cj)(sw, dt, id);

        if (ent->flag1c) {
            (obj + id)[0x558] = 1;
        }
        ent->flag1d = 0;
        ent->flag1c = 0;
    }
}
