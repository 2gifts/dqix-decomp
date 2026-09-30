#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "System/Matrix.h"

struct Entry021dcf14 {
    char pad0[4];
    int mode;
    char pad8[4];
    int nodeIndex;
    char pad10[8];
    short actorId;
    short targetId;
    unsigned short elapsed;
    unsigned short remaining;
};

struct First021dcf14 {
    char pad0[0x20];
    unsigned short combatantId;
    char pad22[4];
    unsigned char flags[6];
};

struct Node021dcf14 {
    char pad0[0xe];
    short ids[3];
    unsigned char codes[3];
    unsigned char pad17;
    unsigned char counts[3];
};

struct TableEntry021dcf14 {
    char pad0[0x18];
    unsigned int pad18a : 12;
    unsigned int kind18 : 4;
    unsigned int pad18b : 16;
};

struct Rec021dcf14 {
    int f0;
    int f4;
    short id;
    short val;
    union {
        Vector3fix pos;
        short angle;
    };
    void* next;
};

struct Pending021dcf14 {
    char pad0[0x20];
    short id;
    char pad22[6];
    unsigned int flags;
    char pad2c[0x14];
};

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char flags11;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Obj0205eaa0;

extern "C" void* __clear(void* dst, int count);
extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void func_ov000_0216df00(void* obj, int id, int b, int c, float scale);
extern "C" void _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(void* obj);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" void _Z13ApplyVec3TailPvPi(void* obj, Vector3fix* vec);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void _ZN8Vector3iaSERKS_(Vector3fix* dst, const Vector3fix* src);
extern "C" void func_ov000_02167f10(void* obj);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(GameObject* obj, int value);
extern "C" void _Z20ResetFields_021de110Pv(struct Rec021dcf14* rec);
extern "C" void _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(void* obj, struct Rec021dcf14* rec);
extern "C" void _Z16SetFlag0x4At0xe0P13Flags02033fcc(GameObject* obj);
extern "C" void _Z18ClearFlag0x4At0xe0P13Flags02033fdc(GameObject* obj);
extern "C" int _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(GameObject* obj, int value);
extern "C" void* _Z15GetData02108e10v(void);
extern "C" struct TableEntry021dcf14* _Z24SearchBothTables02079e2cPci(void* table, int key);
extern "C" struct Node021dcf14* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int index);
extern "C" struct First021dcf14* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" void _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(void* obj, struct Entry021dcf14* entry);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" void _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(void* obj, int a, int b);
extern "C" void _Z20SetShortTriple0x6e44Pvttt(void* obj, unsigned short a, unsigned short b, unsigned short c);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* node, int index, unsigned char depth);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
extern "C" int _Z23CheckSubstructFlag0x100Ph(GameObject* obj);
extern "C" int _Z20GetSubstructByte0x56Ph(GameObject* obj);
extern "C" void _Z21SetSubstructFlag0x400Ph(GameObject* obj);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" int _Z20TryDispatch_021dce7cPhP10In021dce7ci(void* obj, void* slot, int id);
extern "C" void* func_02057924(void);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, struct InitStruct02078484Struct* req);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov025_021eabd0(void* obj, bool party);
extern "C" void func_ov025_021ead5c(void* obj, bool party);

extern Vector3fix data_ov025_021eeed4;
extern char data_ov025_021ef460[];
struct Timer021ef974 {
    int f0;
    unsigned short timer;
    char pad6[0xc - 6];
};
inline struct Timer021ef974& GetTimer021ef974() {
    static struct Timer021ef974 s;
    return s;
}
extern struct Obj0205eaa0 data_02108760;
extern Vector3fix data_ov025_021eeee0;
extern int data_ov025_021eeeec[];
extern int data_ov025_021eeef8[];

#define TIMER (GetTimer021ef974().timer)

static inline void SetPhase(unsigned char* sl, int phase, unsigned short time) {
    TIMER = time;
    sl[0x6e4b] = phase;
}

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline struct Pending021dcf14 GetPending(unsigned char* work) {
    return *(struct Pending021dcf14*)(work + 0x378 + 0x6c00);
}

// USA: func_ov025_021dcf14
extern "C" ARM int func_ov025_021dcf14(unsigned char* sl) {
    GameState* battle = GameState::GetInstance();
    struct Entry021dcf14* cur;
    GameObject* objs[5];

    if (sl[0x6e4b] != 0) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        struct Entry021dcf14* e = (struct Entry021dcf14*)(sl + 0x6e50);
        for (int i = 0; i < sl[0x6e4d]; i++, e++) {
            if (dt < e->remaining) {
                e->remaining -= dt;
            } else {
                e->remaining = 0;
            }
            e->elapsed += dt;
        }
    }

    cur = (struct Entry021dcf14*)(sl + 0x6e50) + sl[0x6e4c];
    __clear(objs, sizeof(objs));

    if (sl[0x6e4b] == 0) {
        return 0;
    }

    if (sl[0x6e4b] == 1) {
        func_ov000_0216d370(sl + 0x18 + 0xc00, 1, 1, 1);
        func_ov000_0216df00(sl + 0x18 + 0xc00, cur->targetId, 0, 0, 1.8f);
        _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(sl);
        void* slot = _Z18GetSlotPtr02160f20Pv(sl);
        if (*(unsigned short*)slot == 0x11b || *(unsigned short*)slot == 0x116) {
            Vector3fix cam = *(Vector3fix*)(sl + 0x88 + 0xc00);
            cam.z = 0x847a;
            _Z13ApplyVec3TailPvPi(sl + 0x18 + 0xc00, &cam);
        }
        func_ov000_021626a0(sl, 4, 0);
        for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + 0x6ef0))[i]);
            objs[i] = c;
            if (c) {
                c->obj3D_.MakeVisible();
            }
        }

        GameObject* lead = battle->GetCombatantByIndex(cur->targetId);
        if (lead) {
            lead->obj3D_.MakeVisible();
        }
        Vector3fix leadPos;
        if (lead) {
            _ZN8Vector3iaSERKS_(&leadPos, &lead->obj3D_.position_);
        }
        func_ov000_02167f10(sl);
        if (lead) {
            _ZN8Vector3iaSERKS_(&lead->obj3D_.position_, &leadPos);
            int radius = lead->obj3D_.GetRadius();
            Vector3fix base;
            __clear(&base, sizeof(base));
            base.x = radius / 4;
            base.z = radius;
            if (*(short*)(sl + 0x6efa) >= 2) {
                if (*(short*)(sl + 0x6efa) == 4) {
                    base.x = radius + radius / 8;
                }
                base.x = (int)(4096.0f * (0.6f * (radius / 4096.0f)));
            }

            int maxRadius = 0;
            for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
                GameObject* c = objs[i];
                if (c == NULL) {
                    continue;
                }
                Vector3fix off = base;
                Vector3fix face = data_ov025_021eeed4;
                if (*(short*)(sl + 0x6efa) >= 3) {
                    if (*(short*)(sl + 0x6efa) == 4) {
                        if (i >= 2) {
                            off.x = (int)(4096.0f * (0.2f * (radius / 4096.0f)));
                            off.z = radius + maxRadius / 2;
                        }
                    } else if (i == 2) {
                        off.x = 0;
                        off.z = radius + maxRadius / 2;
                    }
                }
                if (maxRadius < c->obj3D_.GetRadius()) {
                    maxRadius = objs[i]->obj3D_.GetRadius();
                }
                if (i % 2 != 0) {
                    off.x = -off.x;
                    face.x = -face.x;
                }
                Matrix4x3 rot = RotationMatrixY(lead->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&off, &rot, &off);
                Vector3fix dst = objs[i]->obj3D_.position_;
                Vector3fix src = lead->obj3D_.position_;
                Vector3fix_Add(&src, &off, &dst);
                Matrix4x3 rot2 = RotationMatrixY(lead->obj3D_.rotation_.y);
                Mat4x3_ApplyToVector(&face, &rot2, &face);
                Vector3fix look;
                Vector3fix_Add(&dst, &face, &look);
                Vector3fix dir;
                Vector3fix_Subtract(&dst, &look, &dir);
                Vector3fix_Normalize(&dir, &dir);
                int angle = fix32_Atan2(dir.x, dir.z);
                _ZN8Vector3iaSERKS_(&objs[i]->obj3D_.position_, &look);
                _Z24SetVecYFromValue02033874P11Obj02033874i(objs[i], angle);
                struct Rec021dcf14 rec;
                _Z20ResetFields_021de110Pv(&rec);
                rec.f0 = 0;
                rec.id = ((short*)(sl + 0x6ef0))[i];
                rec.val = 0x96;
                _ZN8Vector3iaSERKS_(&rec.pos, &dst);
                _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + 0xb30, &rec);
                objs[i]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                _Z16SetFlag0x4At0xe0P13Flags02033fcc(objs[i]);
            }
        }

        int maxHeight = 0;
        for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + 0x6ef0))[i]);
            if (c && maxHeight < c->obj3D_.GetHeight()) {
                maxHeight = c->obj3D_.GetHeight();
            }
        }
        if (maxHeight >= 0x1800) {
            float scale = 1.0f + 0.8f * (maxHeight / 4096.0f - 1.5f) / 2.5f;
            if (scale >= 1.8f) {
                scale = 1.8f;
            }
            Vector3fix cam = *(Vector3fix*)(sl + 0x88 + 0xc00);
            cam.z = (int)(4096.0f * (cam.z / 4096.0f * scale));
            _Z13ApplyVec3TailPvPi(sl + 0x18 + 0xc00, &cam);
        }
        SetPhase(sl, 2, 0x9b);
    } else if (sl[0x6e4b] == 2) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
                objs[i] = battle->GetCombatantByIndex(((short*)(sl + 0x6ef0))[i]);
            }
            int maxHeight = 0;
            int j;
            for (j = 0; j < *(short*)(sl + 0x6efa); j++) {
                if (objs[j] == NULL) {
                    continue;
                }
                if (maxHeight < objs[j]->obj3D_.GetHeight()) {
                    maxHeight = objs[j]->obj3D_.GetHeight();
                }
                int turn = 0x1922;
                if (j % 2 != 0) {
                    turn = -0x1922;
                }
                int rot = objs[j]->obj3D_.rotation_.y;
                _Z24SetVecYFromValue02033874P11Obj02033874i(objs[j], fix32ReduceAngle0To2Pi(rot + turn));
                _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(objs[j], 0);
            }
            float scale = 1.0f;
            if (maxHeight >= 0x1800) {
                scale = scale + 0.8f * (maxHeight / 4096.0f - 1.5f) / 2.5f;
                if (scale >= 1.8f) {
                    scale = 1.8f;
                }
            }
            Vector3fix cam = *(Vector3fix*)(sl + 0x88 + 0xc00);
            fix32_Divide((int)(4096.0f * (6.0f * scale)), cam.z);
            TIMER = 0xc8;
            if (sl[0x6e4d] != 0) {
                sl[0x6e4b] = 6;
            } else {
                sl[0x6e4b] = 3;
            }
        }
        if (sl[0x6e4b] == 6) {
            void* slot = _Z18GetSlotPtr02160f20Pv(sl);
            struct TableEntry021dcf14* entry =
                _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), *(short*)slot);
            if (entry && entry->kind18 == 2) {
                struct Node021dcf14* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, cur->nodeIndex);
                if (node == NULL) {
                    return 0;
                }
                if (node == NULL) {
                    return 0;
                }
                if (node->codes[2] != 1 && node->codes[2] != 2) {
                    unsigned int wait = *(unsigned int*)(sl + 0x6f8c);
                    *(unsigned int*)(sl + 0x6fc8) = wait;
                    if (wait > 0x9b) {
                        TIMER = wait - 0x9b;
                    }
                }
            }
        }
    } else if (sl[0x6e4b] == 6) {
        if (*(unsigned short*)(sl + 0x6e6e) != 0) {
            return 0;
        }
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            GameObject* actor = battle->GetCombatantByIndex(cur->actorId);
            if (actor) {
                _Z18ClearFlag0x4At0xe0P13Flags02033fdc(actor);
            }
            void* slot = _Z18GetSlotPtr02160f20Pv(sl);
            struct First021dcf14* first = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0);
            if (first == NULL) {
                return 0;
            }
            if (first == NULL) {
                return 0;
            }
            struct Node021dcf14* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, cur->nodeIndex);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int miss = 0;
            int crit = 0;
            if (node->codes[2] == 3 || node->codes[2] == 1) {
                if (node->codes[2] == 1) {
                    crit = 1;
                } else {
                    miss = 1;
                }
                cur->mode = 2;
            }
            if (!miss && first->flags[4] != 0) {
                sl[0x6e4e] = 6;
            }
            _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
            if (sl[0x7745] != node->ids[1] || sl[0x7746] != node->ids[0]) {
                int msgId = 0x7f;
                int party = 0;
                if (node->ids[0] >= 0 && node->ids[0] <= 3) {
                    party = 1;
                }
                if (party) {
                    msgId = 0x7e;
                }
                func_ov025_021ed444(sl + 0x890, msgId, node->ids[0], 0, 0, node->ids[1], 0);
                sl[0x7745] = node->ids[1];
                sl[0x7746] = node->ids[0];
            }
            if (miss || crit) {
                _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(sl + 0x18 + 0xc00, 0xcc, 0x1f4);
                _Z20SetShortTriple0x6e44Pvttt(sl, 0x199, 0x1f4, 0x64);
                if (crit) {
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x43, 0);
                }
            }
            cur->mode = 1;
            if (sl[0x6e4d] <= ++sl[0x6e4c]) {
                TIMER = 0x64;
                if (miss) {
                    TIMER = 0x96;
                }
                sl[0x6e4b] = 3;
            } else {
                TIMER = 0x12c;
                if (*(unsigned short*)slot == 1 || *(unsigned short*)slot == 2 || *(unsigned short*)slot == 0xdb) {
                    int k;
                    for (k = 0; k < 3; k++) {
                        int found = 0;
                        int d;
                        for (d = 0; d < node->counts[k]; d++) {
                            void* hit = _Z23FindNodeAtDepth0215fff4Pvii(node, d, k);
                            if (hit && func_ov000_0215fd90(hit, 0x2a)) {
                                found = 1;
                                TIMER = 0;
                                break;
                            }
                        }
                        if (found) {
                            break;
                        }
                    }
                }
            }
        }
    } else if (sl[0x6e4b] == 3) {
        if (sl[0x6e4d] > sl[0x6e4c]) {
            sl[0x6e4b] = 6;
        } else {
            unsigned int dt = battle->GetEffectiveDeltaTime();
            if (dt < TIMER) {
                TIMER -= dt;
            } else {
                TIMER = 0;
            }
        }
    } else if (sl[0x6e4b] == 4) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            void* slot = _Z18GetSlotPtr02160f20Pv(sl);
            struct First021dcf14* first = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0);
            if (first == NULL) {
                return 0;
            }
            if (first == NULL) {
                return 0;
            }
            struct Node021dcf14* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, cur->nodeIndex);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int miss = 0;
            int crit = 0;
            unsigned char found = 0;
            unsigned short foundId = 0;
            if (node->codes[2] == 3) {
                miss = 1;
            } else if (node->codes[2] == 1) {
                crit = 1;
            }
            int any = 0;
            if (!miss && !crit) {
                int k;
                for (k = 0; k < 6; k++) {
                    if (first->flags[k] != 0) {
                        any = 1;
                        if (k == 4) {
                            foundId = first->combatantId;
                            found = 1;
                            sl[0x6e4e] = 4;
                        }
                    }
                }
            }
            if (!miss && !found && !crit) {
                for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
                    GameObject* c = battle->GetCombatantByIndex(((short*)(sl + 0x6ef0))[i]);
                    if (c && !_Z23CheckSubstructFlag0x100Ph(c)) {
                        objs[i] = c;
                        if (!any && objs[i]) {
                            objs[i]->obj3D_.MakeVisible();
                        }
                    }
                }
                for (int i = 0; i < *(short*)(sl + 0x6efa); i++) {
                    int rotY;
                    GameObject* c = objs[i];
                    if (c == NULL) {
                        continue;
                    }
                    if (_Z20GetSubstructByte0x56Ph(c) == 0 || _Z23CheckSubstructFlag0x100Ph(c) != 0) {
                        c->obj3D_.TransitionInheritedAlpha(0, 0x12c);
                        int party = 0;
                        if (c->obj3D_.unknown_4_ >= 0 && c->obj3D_.unknown_4_ <= 3) {
                            party = 1;
                        }
                        if (party || _Z23CheckSubstructFlag0x100Ph(c)) {
                            _Z21SetSubstructFlag0x400Ph(c);
                        }
                    } else {
                        Vector3fix off = data_ov025_021eeee0;
                        off.x = data_ov025_021eeeec[i];
                        rotY = c->obj3D_.rotation_.y;
                        Matrix4x3 rot = RotationMatrixY(rotY);
                        Mat4x3_ApplyToVector(&off, &rot, &off);
                        Vector3fix pos = c->obj3D_.position_;
                        Vector3fix dst;
                        Vector3fix_Add(&pos, &off, &dst);
                        struct Rec021dcf14 rec;
                        _Z20ResetFields_021de110Pv(&rec);
                        rec.f0 = 1;
                        rec.id = cur->actorId;
                        rec.val = 0x64;
                        rec.angle = fix32ReduceAngle0To2Pi(rotY + data_ov025_021eeef8[i]);
                        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + 0xb30, &rec);
                        _Z20ResetFields_021de110Pv(&rec);
                        rec.f0 = 0;
                        rec.id = ((short*)(sl + 0x6ef0))[i];
                        rec.val = 0x12c;
                        _ZN8Vector3iaSERKS_(&rec.pos, &dst);
                        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + 0xb30, &rec);
                        objs[i]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                        _Z16SetFlag0x4At0xe0P13Flags02033fcc(objs[i]);
                    }
                }
                sl[0x6e4e] = 0;
                SetPhase(sl, 5, 0x12c);
            } else {
                func_ov000_021626a0(sl, 4, 0);
                GameObject* target = NULL;
                int id = func_ov000_0215ffa0(node);
                if (miss || crit) {
                    if (!_Z20TryDispatch_021dce7cPhP10In021dce7ci(sl, slot, id)) {
                        func_ov000_0216df00(sl + 0x18 + 0xc00, id, 0, 0, 1.8f);
                    }
                    target = battle->GetCombatantByIndex(id);
                } else if (found) {
                    func_ov000_0216df00(sl + 0x18 + 0xc00, foundId, 0, 0, 1.8f);
                    target = battle->GetCombatantByIndex(foundId);
                    cur->mode = 0;
                }
                target->obj3D_.MakeVisible();
                if (crit) {
                    int objectId = func_ov000_0215ffa0(node);
                    struct Pending021dcf14 pending = GetPending(sl);
                    void* list = func_02057924();
                    struct InitStruct02078484Struct req;
                    _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
                    req.objectId = objectId;
                    if (pending.flags & 1) {
                        req.offset.y += target->obj3D_.GetHeight() / 2;
                    }
                    _Z26FindNodeAndProcess02057fb4Pvii(list, pending.id, &req);
                    _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(short*)(sl + 0x6f9a), 0);
                }
                if (!crit) {
                    if (miss) {
                        cur->mode = 3;
                    }
                    _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
                    cur->mode = 1;
                    if (sl[0x6e4d] <= ++sl[0x6e4c]) {
                        sl[0x6e4e] = 0;
                        SetPhase(sl, 5, 1000);
                    }
                } else {
                    unsigned int wait = *(unsigned int*)(sl + 0x6f8c);
                    *(unsigned int*)(sl + 0x6fc8) = wait;
                    sl[0x6e4e] = 0;
                    SetPhase(sl, 7, wait);
                }
            }
        }
    } else if (sl[0x6e4b] == 7) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            struct Node021dcf14* node =
                _Z22GetNodeAtIndex021600f8P12List021600f8i(_Z18GetSlotPtr02160f20Pv(sl), cur->nodeIndex);
            if (node == NULL) {
                return 0;
            }
            if (node == NULL) {
                return 0;
            }
            int id = func_ov000_0215ffa0(node);
            func_ov025_021eabd0(sl + 0x2a8, IsPartyMember(id));
            _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
            func_ov025_021ead5c(sl + 0x2a8, IsPartyMember(id));
            SetPhase(sl, 5, 1000);
        }
    } else if (sl[0x6e4b] == 5) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            for (int i = 0; i < sl[0x6e4d]; i++) {
                GameObject* c = battle->GetCombatantByIndex(((struct Entry021dcf14*)(sl + 0x6e50))[i].actorId);
                if (c) {
                    _Z18ClearFlag0x4At0xe0P13Flags02033fdc(c);
                }
                ((struct Entry021dcf14*)(sl + 0x6e50))[i].actorId = -1;
                ((struct Entry021dcf14*)(sl + 0x6e50))[i].targetId = -1;
            }
            sl[0x6e4d] = 0;
            sl[0x6e4b] = 0;
        }
    }
    return 0;
}
