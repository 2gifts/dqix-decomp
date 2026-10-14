#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;
struct Struct0205cf1c;

void* GetPtrField0x2a04_02010828(GameState*);
void CopyStaticData02174da4(int, void*);
extern "C" void* func_0202ae18();
int CheckField0NonZero_0202b7d8(int*);
int GetField0x3acValue_020100a8(GameState*);
int CountSetBitsLow12_0x68_ov000_0218155c(void*);
extern "C" void* func_ov000_02161318(void*, int);
void* GetFieldAt0x150_02053c6c(unsigned char*);
void ClearChannelAFlag0205cf10(void*);
void ClearFlagByte0205cf1c(Struct0205cf1c*);
void SetChannelAFlag0205cef8(void*);
void SetChannelBFlag0205cf04(void*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
void SetIndexIfValid0205bcdc(Struct_0205bcdc*, int);
extern "C" void func_0205bb04(void*, int);

#if defined(jpn)
extern int data_ov000_02184294[3];
#else
extern int data_ov000_02184294[2];
#endif

struct Party {
    char pad[0xf7c];
    unsigned char count;
};

struct Member {
#if defined(jpn)
    char pad[0x8b4];
#else
    char pad[0x94c];
#endif
    int value;
};

struct Panel {
    int head;
    int level;
    char rest[0x48];
};

struct Battle0217c638 {
    char pad0[0x1a];
    signed char byte1a;
    char pad1b;
    signed char byte1c;
    char pad1d[0x66 - 0x1d];
    short word66;
    char pad68[0x79 - 0x68];
    unsigned char limit;
    char pad7a[0x188 - 0x7a];
    char flags[4];
    Panel first;
    Panel second;
#if defined(jpn)
    char pad22c[0x1f98 - 0x22c];
#else
    char pad22c[0x1d60 - 0x22c];
#endif
    signed char commands[8];
    signed char index;
    signed char sel[7];
    char pad1d70[4];
    signed char table[8];
};

// USA: func_ov000_0217c638
extern "C" ARM void func_ov000_0217c638(Battle0217c638* battle, int a, int b) {
    int columns = 1;
    int total = b;
    int rows;
    int pages = columns;
    signed char selected;
#if defined(jpn)
    data_ov000_02184294[2] = a;
    data_ov000_02184294[1] = b;
#else
    data_ov000_02184294[1] = a;
    data_ov000_02184294[0] = b;
#endif
    GameState* gs = GameState::GetInstance();
    Party* party = (Party*)GetPtrField0x2a04_02010828(gs);
    switch (battle->commands[battle->index]) {
    case 1: {
        int buf[4];
        total = 0;
        CopyStaticData02174da4((int)battle, buf);
        for (int i = 0; i < 4; i++) {
            if (buf[i] >= 0) total++;
        }
        rows = total;
        selected = battle->sel[0];
        break;
    }
    case 2: {
        void* state = func_0202ae18();
        rows = 3;
        if (CheckField0NonZero_0202b7d8((int*)state)) {
            if (GetField0x3acValue_020100a8(gs) == 0) rows = 4;
        }
        total = rows;
        selected = battle->sel[1];
        break;
    }
    case 3:
        total = party->count;
        selected = battle->sel[2];
        rows = total;
        break;
    case 5:
        total = party->count;
        selected = battle->sel[2];
        rows = total;
        break;
    case 6: {
        rows = 4;
        int n = CountSetBitsLow12_0x68_ov000_0218155c(battle);
        total = n;
        selected = battle->sel[5];
        if (n < 4) rows = n;
        pages = (n + 3) / 4;
        break;
    }
    case 7: {
        total = battle->word66;
        selected = battle->sel[6];
        rows = 4;
        if (total < 4) rows = total;
        pages = (total + 3) / 4;
        break;
    }
    case 4: {
        columns = 2;
        rows = 3;
        int slot = battle->table[battle->sel[2]];
        total = 6;
        signed char sl = 0;
        int ok = slot >= 0 && slot <= 3;
        if (ok && func_ov000_02161318(battle, slot)) {
            GameObject* member = gs->GetPartyMemberByIndex(slot);
            if (member) {
                sl = (signed char)((Member*)GetFieldAt0x150_02053c6c((unsigned char*)member))->value;
            }
        }
        battle->sel[3] = sl;
        selected = battle->sel[3];
        break;
    }
    case 8:
        total = battle->limit;
        selected = battle->sel[2];
        rows = total;
        break;
    case 23:
        rows = battle->byte1a;
        selected = battle->sel[4];
        total = rows;
        break;
    case 25:
        rows = 1;
        columns = total;
        pages = rows;
        selected = battle->byte1c;
        break;
    default:
        ClearChannelAFlag0205cf10(battle->flags);
        ClearFlagByte0205cf1c((Struct0205cf1c*)battle->flags);
        return;
    }
    SetChannelAFlag0205cef8(battle->flags);
    SetChannelBFlag0205cf04(battle->flags);
    SetupPointerTable0205ba68((Struct_0205ba68*)&battle->first, columns, rows, 0);
    SetupPointerTable0205ba68((Struct_0205ba68*)&battle->second, columns, rows, 0);
    SetField0AndPropagate0205bacc((Node0205bacc*)&battle->first, total);
    SetField0AndPropagate0205bacc((Node0205bacc*)&battle->second, total);
    battle->first.level = pages;
    battle->second.level = pages;
    SetIndexIfValid0205bcdc((Struct_0205bcdc*)&battle->first, selected);
    func_0205bb04(&battle->second, selected);
}
