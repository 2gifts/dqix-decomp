#include <globaldefs.h>

struct Node0208036c;
struct Slot0208010c {
    short* itemIds;
    unsigned int unknown4;
    short id;
    short tileX;
    short tileY;
    short tileWidth;
    short tileHeight;
    unsigned char unknown12;
    unsigned char itemCount;
    char unknown14[4];
};
struct List0207f6ac {
    Node0208036c* entries;
    short count;
};
struct GroupList0208010c {
    Slot0208010c* entries;
    short count;
};
struct Ctx0208010c {
    void* table;
    List0207f6ac items;
    GroupList0208010c groups;
#if defined(jpn)
    char unknown14[0x2f - 0x14];
#else
    char unknown14[0x3b - 0x14];
#endif
    signed char horizontalEdgePixels;
    signed char verticalEdgePixels;
};

struct Node0208036c {
    char pad0[4];
    short f4;
    char pad1[0x18 - 6];
    struct Node0208036c* f18;
    struct Node0208036c* f1c;
    struct Node0208036c* f20;
    struct Node0208036c* f24;
    char pad2[0x2a - 0x28];
    unsigned char f2a;
};

struct Flags0208036c {
    unsigned int f0;
};

extern "C" void* _Z25FindSlotWithValue020810b4Phs(unsigned char* self, short val);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" int func_02080e40(void* obj, int p1, int p2, int p3);
extern "C" struct Node0208036c* _Z26FindEntryByShortId0207f6acP12List0207f6aci(struct List0207f6ac* list, int id);
extern "C" struct Node0208036c* _Z22WalkListByMode0208036cPvP12Node0208036ciP13Flags0208036ch(void* unused, struct Node0208036c* start, int mode, struct Flags0208036c* flags, unsigned char setFlag);

extern unsigned char data_02114e54[];

// JPN: func_02080c38
// USA: func_020800fc
extern "C" ARM int func_020800fc(struct Ctx0208010c* self, short* outId, short id, int mode, unsigned char sel, unsigned char setFlag) {
    struct Flags0208036c flags;
    struct Node0208036c* node;
    struct Node0208036c* e;
    struct Slot0208010c* slot;
    int x;
    int y;
    int ret;

    flags.f0 = 0;
    *outId = id;
    if (data_02114e54[0x55] != 0) {
        slot = (struct Slot0208010c*)_Z25FindSlotWithValue020810b4Phs((unsigned char*)self, id);
        if (slot != NULL) {
            SelectCoordsByFlag0x24(data_02114e54, &x, &y);
            ret = func_02080e40(self, slot->id, (short)x, (short)y);
            if (ret >= 0) {
                *outId = (short)ret;
            }
            if (setFlag != 0) {
                short rightTile = (short)(slot->tileX + slot->tileWidth);
                short bottomTile = (short)(slot->tileY + slot->tileHeight);
                if ((short)(bottomTile << 3) - self->verticalEdgePixels <= y && y < (short)(bottomTile << 3)) {
                    short leftPixel = (short)(slot->tileX << 3);
                    if (leftPixel <= x && x < leftPixel + self->horizontalEdgePixels) {
                        flags.f0 |= 0x20;
                    }
                    if ((short)(rightTile << 3) - self->horizontalEdgePixels <= x && x < (short)(rightTile << 3)) {
                        flags.f0 |= 0x10;
                    }
                }
            }
        }
        return flags.f0;
    }

    if (sel == 0) {
        return flags.f0;
    }
    e = _Z26FindEntryByShortId0207f6acP12List0207f6aci(&self->items, *outId);
    if (e == NULL) {
        return flags.f0;
    }
    node = NULL;
    switch (mode) {
    case 0x10:
        node = e->f24;
        flags.f0 |= 8;
        break;
    case 0x20:
        node = e->f20;
        flags.f0 |= 4;
        break;
    case 0x40:
        node = e->f18;
        flags.f0 |= 1;
        break;
    case 0x80:
        node = e->f1c;
        flags.f0 |= 2;
        break;
    }
    if (node != NULL) {
        if (node->f2a & 2) {
            node = _Z22WalkListByMode0208036cPvP12Node0208036ciP13Flags0208036ch(self, e, mode, &flags, setFlag);
        }
        if (node != NULL) {
            *outId = node->f4;
        }
    } else {
        if (sel == 1) {
            e = _Z22WalkListByMode0208036cPvP12Node0208036ciP13Flags0208036ch(self, e, mode, &flags, setFlag);
        } else if (sel == 2 && setFlag != 0) {
            switch (mode) {
            case 0x10:
                flags.f0 |= 0x10;
                break;
            case 0x20:
                flags.f0 |= 0x20;
                break;
            }
        }
        *outId = e->f4;
    }
    return flags.f0;
}
