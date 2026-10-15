#include <globaldefs.h>

extern "C" int _Z38GetBattleSubField0xbcForState_020d4ac8v(void);

struct TurnCounter_0202c04c {
    int seq;
    int reset;
};

inline TurnCounter_0202c04c& GetTurnCounter() {
    static TurnCounter_0202c04c s;
    return s;
}

struct TurnFlags_0202c04c {
    unsigned short type : 3;
    unsigned short state : 2;
    unsigned short actor : 3;
    unsigned short pad0 : 8;
    unsigned short pad1 : 5;
    unsigned short slotA : 2;
    unsigned short slotB : 2;
    unsigned short slotC : 2;
};

struct BattleTurn_0202c04c {
    char pad000[8];
    int swing;
    char pad00c[0x7b4];
    TurnFlags_0202c04c flags;
    char pad7c4[0x7fc];
    int guard;
    char padfc4[0x40];
    int actorId;
    int pendingActor;
    char pad100c[0x2c];
    char pad1038;
    signed char slotA;
    signed char slotB;
    signed char slotC;
};

// USA: func_0202c04c
extern "C" ARM void func_0202c04c(BattleTurn_0202c04c* turn) {
    if (turn->guard != 0) {
        return;
    }
    turn->flags.type = 1;
    GetTurnCounter().seq++;
    turn->flags.actor = (unsigned short)turn->actorId;
    TurnFlags_0202c04c* flags = &turn->flags;
    turn->flags.state = (unsigned short)_Z38GetBattleSubField0xbcForState_020d4ac8v();

    int pending = turn->pendingActor;
    if (pending != -1) {
        flags->actor = (unsigned short)pending;
        turn->pendingActor = -1;
    }

    int swing = turn->swing;
    if (swing != 0) {
        if (swing > 0) {
            turn->swing = 1 - swing;
        } else {
            turn->swing = -1 - swing;
        }
    }

    flags->slotA = turn->slotA;
    flags->slotB = turn->slotB;
    flags->slotC = turn->slotC;
}
