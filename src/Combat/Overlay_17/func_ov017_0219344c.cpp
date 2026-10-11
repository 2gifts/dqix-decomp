#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct HeadNode02046b24;
struct ByteFlags02033f2c;
struct BitFlag02033f44;
struct Bytes02033b88;
struct Obj020397cc;
struct ActorListManager;
struct Vec3;

class Actor0219344c : public Object3D {
public:
    short fieldAC;
    unsigned char pad_ae[0xc1 - 0xae];
    unsigned char lowC1 : 3;
    unsigned char flagC1 : 1;
    unsigned char highC1 : 4;
    unsigned char pad_c2[0x18c - 0xc2];
    unsigned int field18c;
};

struct Zone0219344c {
    unsigned short id;
    unsigned char pad_2[0x82c - 0x2];
    int count82c;
    unsigned char pad_830[0x23b8 - 0x830];
    unsigned char useCell;
};

struct Probe0219344c {
    Vector3i top;
    Vector3i bottom;
};

struct Grid0219344c {
    unsigned char data[0x980];
};

struct Link0219344c {
    unsigned char kind;
    unsigned char pad_1;
    unsigned short index;
};

struct LinkHolder0219344c {
    unsigned char pad[0x3400];
    Link0219344c link;
};

extern unsigned short data_02114e30;

extern "C" void* func_02012fe4(void);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
int TestFlagMask(unsigned short* pad, int buttons);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** head);
void ClearFlags0x40And0x80At0xe0(ByteFlags02033f2c* p);
extern "C" int _Z29NotifyEntriesFlag256_0218df50PvS_(void* a, void* b);
extern "C" int func_ov017_0218dfd8(Actor0219344c* self);
int GetField0xe4IfFlag0x40(BitFlag02033f44* p);
int IsFlag0x1ceBit0x8Set(unsigned char* p);
extern "C" int func_ov017_02193290(Probe0219344c* probe, Actor0219344c* self, Vector3i* dest, Vector3i* pos, int* y, int* yLow, int hidden);
extern "C" int func_02017d90(Zone0219344c* zone, int index, Grid0219344c* grid, Probe0219344c probe, Actor0219344c* self);
extern "C" int func_ov017_02192b48(Grid0219344c* grid, Probe0219344c* probe, int count, Actor0219344c* self, int arg, Vector3i* dest, Vector3i* pos, int* y, int* yLow, int enable, int* reset, int inCell, int index, int hidden);
unsigned char GetField0x397cValue(GameState* gs);
void SetByteField0x253(void* obj);
int SetByte0xbeShiftPrev(Bytes02033b88* p, int val);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int val);
extern "C" void func_020531f0(GameObject* obj);
unsigned char* GetElementStride0x24(unsigned char* p, int i);
extern "C" void _Z27GetDeltaAndForward_0218daa8PvP4Vec3iih(void* res, Vec3* pos, int speed, int a, unsigned char b);
unsigned char* GetActorEntryByIndex(ActorListManager* list, int i);

#define SETUP_PROBE()                                          \
    do {                                                       \
        probe.top = pos;                                       \
        probe.bottom = pos;                                    \
        probe.top.x += self->GetRadius() / 2;                  \
        probe.top.y += self->GetHeight();                      \
        probe.top.z += self->GetRadius() / 2;                  \
        probe.bottom.x -= self->GetRadius() / 2;               \
        probe.bottom.y -= 0xa000;                              \
        probe.bottom.z -= self->GetRadius() / 2;               \
    } while (0)

// USA: func_ov017_0219344c
extern "C" ARM int func_ov017_0219344c(Actor0219344c* self, int arg, Vector3i* target, int mode, int* outA, int* outB) {
    Grid0219344c grid;
    int reset;
    int yLow;
    int y;
    GameState* gs;
    Zone0219344c* zone;
    int total;
    int hidden;
    int enable;
    int cell;
    int inCell;
    int useCell;
    int hits;
    int found;
    int pathHits;
    int notifyA;
    int notifyB;
    int zoneId;
    int oldAC;

    gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    zone = (Zone0219344c*)func_02012fe4();
    total = 0;
    HeadNode02046b24** head = (HeadNode02046b24**)res->unknown_ptr_array_36fc[0];
    zoneId = zone->id;
    Vector3i startPos = self->position_;
    oldAC = self->fieldAC;
    hidden = self->GetFlags() & 0x4000000;
    self->DisableFlag(0x4000000);
    enable = 1;
    if (GetBitsInField0((unsigned int*)res, 0x400) != 0 && TestFlagMask(&data_02114e30, 1) != 0) {
        enable = 0;
    }
    if ((self->unknown_0_ & 0x100) && (self->field18c & 1)) {
        enable = 0;
    }
    Probe0219344c probe;
    Vector3i pos = self->position_;
    Vector3i step;
    Vector3i saved;
    SETUP_PROBE();
    reset = 1;
    if (GetHeadNodeIdOrMinusOne(head) != 3 || self->flagC1) {
        self->fieldAC += 0x51;
    }
    if (self->fieldAC > 0x1000) {
        self->fieldAC = 0x1000;
    }
    ClearFlags0x40And0x80At0xe0((ByteFlags02033f2c*)self);
    inCell = 1;
    useCell = zone->useCell;
    if (useCell != 0) {
        cell = (int)(((float)(self->position_.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(self->position_.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }
    yLow = self->position_.y - 0xa000;
    y = self->position_.y;

    if (mode == 2 && target != NULL) {
        mode = 2;
        Vector3fix_Subtract(&pos, target, &step);
        Vector3fixMultiplyScalar(&step, 0x800, &step);
        Vector3i next = *target;
        Vector3fix_Add(&next, &step, &next);
        self->position_ = next;
        pos = next;
    } else {
        mode = 1;
    }

    Vector3i* dest = target;
    hits = 0;
    found = 0;
    notifyA = 0;
    notifyB = 0;
    for (int i = 0; i < mode; i++) {
        if (mode == 2 && i == 0 && outA != NULL && outB != NULL) {
            saved = self->position_;
            dest = &saved;
            notifyA |= _Z29NotifyEntriesFlag256_0218df50PvS_(self, 0);
            notifyB |= notifyA;
            notifyB |= func_ov017_0218dfd8(self);
            Vector3i cur = self->position_;
            pos = cur;
            *outA = notifyA;
            *outB = notifyB;
            SETUP_PROBE();
        }
        if (i == 1) {
            saved = self->position_;
            dest = &saved;
            if (outA != NULL && outB != NULL) {
                if (GetField0xe4IfFlag0x40((BitFlag02033f44*)self) && !IsFlag0x1ceBit0x8Set((unsigned char*)self) && notifyB != 0) {
                    self->position_ = *target;
                    break;
                }
                if (GetField0xe4IfFlag0x40((BitFlag02033f44*)self)) {
                    *outA |= _Z29NotifyEntriesFlag256_0218df50PvS_(self, 0);
                    *outB |= *outA;
                    *outB |= func_ov017_0218dfd8(self);
                    if (*outB != 0) {
                        self->position_ = *target;
                        break;
                    }
                }
            }
            Vector3i next = self->position_;
            Vector3fix_Add(&next, &step, &next);
            self->position_ = next;
            if (outA != NULL && outB != NULL) {
                *outA |= _Z29NotifyEntriesFlag256_0218df50PvS_(self, 0);
                *outB |= *outA;
                *outB |= func_ov017_0218dfd8(self);
                if (GetField0xe4IfFlag0x40((BitFlag02033f44*)self) && *outB != 0) {
                    self->position_ = *target;
                    break;
                }
            }
            pos = self->position_;
            SETUP_PROBE();
        }
        pathHits = 0;
        hits = 0;
        if (enable != 0) {
            hits += func_ov017_02193290(&probe, self, dest, &pos, &y, &yLow, hidden);
        }
        for (int j = 0; j < zone->count82c; j++) {
            if (useCell != 0) {
                if (j == 0x100) {
                    inCell = 0;
                } else if (j != cell) {
                    continue;
                }
            }
            int count = func_02017d90(zone, j, &grid, probe, self);
            if (count > 0) {
                total += count;
                pathHits += func_ov017_02192b48(&grid, &probe, count, self, arg, dest, &pos, &y, &yLow, enable, &reset, inCell, j, hidden);
            }
        }
        if (dest != NULL && pathHits != 0) {
            short id = self->unknown_4_;
            if (id != GetField0x397cValue(gs)) {
                continue;
            }
            found = func_ov017_02193290(&probe, self, dest, &pos, &y, &yLow, hidden);
            if (found != 0) {
                pos.x = dest->x;
                pos.z = dest->z;
                self->position_ = *target;
                break;
            }
        }
    }

    GameObject* player = gs->GetUnknownGameObject();
    if (player->obj3D_.GetFlag(0x8000000)) {
        reset = 0;
    }
    if (zoneId == 10000) {
        reset = 1;
    }
    if (reset != 0) {
        if (oldAC != 0 && player->obj3D_.unknown_4_ == self->unknown_4_) {
            SetByteField0x253(player);
        }
        self->fieldAC = 0;
    } else if (oldAC == 0) {
        SetByte0xbeShiftPrev((Bytes02033b88*)self, 0);
        if (player->obj3D_.unknown_4_ == self->unknown_4_) {
            _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)player, 1);
            if (!player->obj3D_.GetFlag(0x1000)) {
                func_020531f0(player);
            }
        }
    }

    GameResources* res2 = func_ov017_0218b5b0();
    unsigned char* zone2 = (unsigned char*)func_02012fe4();
    Vector3i endPos = self->position_;
    Link0219344c* link = &((LinkHolder0219344c*)((char*)res2 + 0x2b4))->link;
    if (link != NULL && !(startPos.x == endPos.x && startPos.y == endPos.y && startPos.z == endPos.z)) {
        if (link->kind == 2) {
            unsigned char* elem = GetElementStride0x24(zone2, link->index);
            if (elem != NULL) {
                _Z27GetDeltaAndForward_0218daa8PvP4Vec3iih(res2, (Vec3*)elem, 0xccc, 0, 0);
            }
        } else if (hits == 0 && found == 0 && link->kind == 5) {
            unsigned char* actor = GetActorEntryByIndex((ActorListManager*)zone2, link->index);
            if (actor != NULL) {
                _Z27GetDeltaAndForward_0218daa8PvP4Vec3iih(res2, (Vec3*)(actor + 0x24), 0xc51, 0, 0);
            }
        }
    }
    return total;
}
