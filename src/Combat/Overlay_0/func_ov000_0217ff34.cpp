#include <globaldefs.h>

class GameState { public: static GameState* GetInstance(); };
struct Unit0217ff34;
Unit0217ff34* GetCombatantWithFlag0x400(GameState*,int);
int GetGlobalField0x1c020421a0();
struct Random;
Random* GetBTRandom();
int NextRandomMax(Random*,int);
struct Details0217ff34 {
    char p0[0x14]; unsigned int flags, flags18;
    char p1[6]; unsigned short low:2, category:4, subcategory:3, unused:7;
    unsigned char mode; char p2[9]; short amount;
    char p3[0x58-0x30];
    signed int level0:3,level1:3,level2:3,level3:3,level4:3,level5:3,level6:3,level7:3,level8:3,level9:3,rest:2;
};
struct Unit0217ff34 { char p[0x138]; Details0217ff34* details; };
// USA: func_ov000_0217ff34
// JPN: func_ov000_0217ff34
extern "C" ARM int func_ov000_0217ff34(void* self,int id,int* amount) {
    int result = -1;
    GameState* gs = GameState::GetInstance();
    GetGlobalField0x1c020421a0();
    Unit0217ff34* unit = GetCombatantWithFlag0x400(gs,id);
    if (!unit) return result;
    int special = 0;
    if (unit) {
        special = (unit->details->flags18 & 0x1000) != 0;
    }
    unsigned int flags = unit->details->flags;
    unsigned char mode = unit->details->mode;
    if (special) {
        switch (NextRandomMax(GetBTRandom(),2)) {
        case 0: result = 4; break;
        case 1: result = 5; break;
        }
        *amount = unit->details->amount;
    } else if (mode) {
        switch (mode) {
        case 1: result = 0x3b; break;
        case 2: result = 0x3a; break;
        case 3: result = 0x39; break;
        case 4: result = 0x38; break;
        }
    } else if (flags & 0x400) {
        switch (unit->details->level0) {
        case 2: result = 0x1f; break;
        case 1: result = 0x20; break;
        case -1: result = 0x21; break;
        case -2: result = 0x22; break;
        }
    } else if (flags & 0x800) {
        switch (unit->details->level1) {
        case 2: result = 0x23; break;
        case 1: result = 0x24; break;
        case -1: result = 0x25; break;
        case -2: result = 0x26; break;
        }
    } else if (flags & 0x1000) {
        switch (unit->details->level2) {
        case 2: result = 0x27; break;
        case 1: result = 0x28; break;
        case -1: result = 0x29; break;
        case -2: result = 0x2a; break;
        }
    } else if (flags & 0x200) result = 0x15;
    else if (flags & 0x10000000) result = 0x18;
    else if (flags & 0x200000) result = 0x19;
    else if (flags & 0x10000) {
        switch (unit->details->level6) {
        case 2: result = 0x30; break;
        case 1: result = 0x31; break;
        case -1: result = 0x32; break;
        case -2: result = 0x33; break;
        }
    } else if ((flags & 0x2000000) && unit->details->level9 == 2) result = 0x37;
    else if (flags & 0x4000) {
        switch (unit->details->level4) {
        case 1: result = 0x2d; break;
        case 2: result = 0x2c; break;
        }
    } else if (flags & 0x8000) {
        switch (unit->details->level5) {
        case 1: result = 0x2f; break;
        case 2: result = 0x2e; break;
        }
    } else if (flags & 8) result = 6;
    else if (flags & 0x10) result = 7;
    else if (flags & 0x20) result = 8;
    else if (flags & 0x80000) {
        switch (unit->details->category) {
        case 2: result = 9; break;
        case 5: result = 10; break;
        case 3: result = 11; break;
        case 4: result = 12; break;
        case 7: result = 14; break;
        case 8: result = 15; break;
        }
    } else if (flags & 0x40) {
        switch (unit->details->subcategory) {
        case 1: result = 0x10; break;
        case 3: result = 0x11; break;
        case 2: result = 0x12; break;
        case 4: result = 0x13; break;
        }
    } else if (flags & 0x100) result = 0x14;
    else if (flags & 2) {
        switch (unit->details->low) {
        case 1: result = 0x17; break;
        case 2: result = 0x16; break;
        }
    } else if ((flags & 0x2000) && unit->details->level3 == 1) result = 0x2b;
    else if (flags & 0x20000) {
        switch (unit->details->level7) {
        case 1: result = 0x34; break;
        case 2: result = 0x35; break;
        }
    }
    return result;
}
