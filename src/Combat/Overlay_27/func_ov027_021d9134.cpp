#include <globaldefs.h>
#include "System/Memory.h"

struct Record021d9134 {
    int f0;
    unsigned char f4[0x16];
    unsigned short f1a;
    unsigned char f1c;
};

struct Query021d9134 {
    unsigned char kind;
    unsigned char pad1;
    unsigned short f2;
    unsigned char pad4[0x10];
};

struct RoomInfo021d9134 {
    unsigned char pad0[0x14];
    int f14;
    unsigned char f18;
};

struct Room021d9134 {
    unsigned char pad0[0x1d40];
    RoomInfo021d9134* info;
    unsigned char pad44[4];
    unsigned short f48;
    unsigned short f4a;
    unsigned short f4c;
    unsigned short f4e;
    unsigned short f50;
    unsigned char f52;
};

struct Slot021d9134 {
    unsigned char lo : 4;
    unsigned char owner : 4;
    unsigned char rest[0x15];
};

extern unsigned char* data_ov027_021e33ec;
extern unsigned int data_ov027_021dd920;

extern "C" Record021d9134* func_ov027_021dd6bc(void* src, Query021d9134* out, unsigned int id);
extern "C" unsigned short func_ov027_021d9dd8(unsigned short cur, unsigned short arg);
void SetEntryCallbackAndDispatch_021d8c20(int id, int event, int param);

#define GBASE data_ov027_021e33ec
#define ROOM(n) ((Room021d9134*)(GBASE + (n) * 0x5d4))
#define ROOMH(n, off) (*(unsigned short*)(GBASE + (off) + (n) * 0x5d4))
#define SLOTS ((Slot021d9134*)(GBASE + 0x1340))
#define STATES ((unsigned short*)(GBASE + 0x1754))
#define OWNERS (GBASE + 0x1526)
#define KEYS ((int*)(GBASE + 0x14a8))
#define MODES ((int*)(GBASE + 0x14e8))

#pragma optimize_for_size off
#pragma opt_common_subs off

// USA: func_ov027_021d9134
extern "C" ARM void func_ov027_021d9134(void* obj, unsigned int id) {
    Query021d9134 query;
    Record021d9134 copy;
    int mode;
    Record021d9134* rec;

    if (id == 0) {
        return;
    }
    if (id > 0xf) {
        return;
    }

    rec = func_ov027_021dd6bc((char*)obj + 0xa, &query, id);
    mode = MODES[id - 1];

    switch (query.kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 11:
        break;

    case 7:
        if (mode == 2) {
            if (rec == 0) {
                return;
            }
            VectorizedInvertedMemcpy(rec, &copy, 0x1d);
            KEYS[id - 1] = copy.f0;
            ((unsigned short*)(GBASE + 0x148a))[id - 1] = copy.f1a;
            VectorizedInvertedMemcpy(copy.f4, &SLOTS[id - 1], 0x16);
            SLOTS[id - 1].owner = (unsigned char)id;
            SetEntryCallbackAndDispatch_021d8c20(id, 0xa, (int)copy.f4);
        }
        if (mode == 0xa) {
            unsigned char room = rec->f1c;
            unsigned char count = 0;
            unsigned short state;

            if (room >= 0x10 || ROOM(room)->f52 == 0 || KEYS[id - 1] != ROOM(room)->info->f14) {
                STATES[id - 1] = 4;
            } else {
                unsigned char i = 0;
                while (i < 0x10) {
                    if ((ROOM(room)->f4e & (1 << i)) != 0) {
                        count++;
                    }
                    i++;
                }
                if (count >= ROOM(room)->info->f18) {
                    STATES[id - 1] = 0;
                    SetEntryCallbackAndDispatch_021d8c20(id, 0xb, 0);
                    return;
                }
            }

            state = STATES[id - 1];
            switch (state) {
            case 3:
                if ((*(unsigned short*)(GBASE + 0x1536) & (1 << id)) != 0) {
                    return;
                }
                GBASE[0x1535]++;
                *(unsigned short*)(GBASE + 0x1536) |= 1 << id;
                OWNERS[id - 1] = room;
                ROOMH(room, 0x1d4e) |= 1 << id;
                ROOMH(room, 0x1d50) |= 1 << id;
                STATES[id - 1] = 0;
                SetEntryCallbackAndDispatch_021d8c20(id, 5, 0);
                break;

            case 4:
                STATES[id - 1] = 0;
                SetEntryCallbackAndDispatch_021d8c20(id, 4, 0);
                break;
            }
        }
        break;

    case 8:
        if (mode == 5) {
            SetEntryCallbackAndDispatch_021d8c20(id, 0xe, 0);
            return;
        }
        if (mode == 0xe) {
            if (STATES[id - 1] == 2) {
                unsigned char room = OWNERS[id - 1];
                ROOMH(room, 0x1d4c) |= 1 << id;
                ROOM(room)->f48 = 0;
                STATES[id - 1] = 0;
                SetEntryCallbackAndDispatch_021d8c20(id, 6, 0);
            }
        }
        break;

    case 9:
        if (mode == 6) {
            unsigned char room = OWNERS[id - 1];
            if (room != 0xff) {
                ROOM(room)->f4a = func_ov027_021d9dd8(ROOM(room)->f4a, query.f2);
                data_ov027_021dd920 |= 1 << room;
            }
        }
        break;

    case 10:
        if (mode == 6) {
            unsigned char room = OWNERS[id - 1];
            if (room != 0xff) {
                ROOMH(room, 0x1d4c) &= ~(1 << id);
                SetEntryCallbackAndDispatch_021d8c20(id, 7, 0);
            }
            return;
        }
        if (mode == 7) {
            if (STATES[id - 1] == 5) {
                STATES[id - 1] = 0;
                SetEntryCallbackAndDispatch_021d8c20(id, 8, 0);
            }
        }
        break;
    }
}
