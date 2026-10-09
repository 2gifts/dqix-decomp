#include <globaldefs.h>

struct Obj0205eaa0;
struct List02160094;

struct Entry021eb6fc {
    char pad_00[8];
    unsigned int pad_8_0 : 8;
    unsigned int kind : 2;
    unsigned int pad_8_a : 22;
    char pad_0c[0xc];
    unsigned int pad_18_0 : 5;
    unsigned int subKind : 7;
    unsigned int mode : 4;
    unsigned int pad_18_10 : 16;
};

struct Obj021eb6fc {
    char pad_000[0x1c4];
    unsigned int flags;
};

void* GetActiveCombatWork(void);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
void* GetData02108e10(void);
extern "C" Entry021eb6fc* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" int _Z20IsMatchingID02163690i(int id);
extern "C" unsigned char* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094*, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov025_021eb6fc
extern "C" ARM void func_ov025_021eb6fc(Obj021eb6fc* obj, int force) {
    if ((obj->flags & 8) && force == 0) {
        return;
    }
    short* slot = (short*)_Z18GetSlotPtr02160f20Pv(GetActiveCombatWork());
    Entry021eb6fc* entry = _Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), *slot);
    if (_Z20IsMatchingID02163690i(*(unsigned short*)slot)) {
        force = 1;
    } else if (entry != 0 && entry->kind == 1 && entry->subKind == 1 && entry->mode != 2) {
        force = 1;
    }
    if (force != 0) {
        unsigned char* node = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)slot, 0);
        if (node != 0) {
            int id = *(unsigned short*)(node + 0x20);
            int inRange;
            if (id >= 0 && id <= 3) {
                inRange = 1;
            } else {
                inRange = 0;
            }
            if (inRange) {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 7, 0);
            } else {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 8, 0);
            }
        }
    }
    obj->flags |= 8;
}
