#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "System/Matrix.h"

#if defined(jpn)
enum { CameraBase = 0xb94, CameraPosition = 0xc04, PendingList = 0xaac, MessageQueue = 0x80c, Auxiliary = 0x224, ModeByte = 0xdb4, PendingRequest = 0x7168, RecordsHigh = 0x7000, RecordFlag = 0xfc, Field6e4b = 0x703b, Field6e4c = 0x703c, Field6e4d = 0x703d, Field6e4e = 0x703e, Field6e50 = 0x7040, Field6e6e = 0x705e, Field6ef0 = 0x70e0, Field6efa = 0x70ea, Field6efc = 0x70ec, Field6efe = 0x70ee, Field6eff = 0x70ef, Field6f00 = 0x70f0, Field6f01 = 0x70f1, Field6f02 = 0x70f2, Field6f04 = 0x70f4, Field6f08 = 0x70f8, Field6f14 = 0x7104, Field6f84 = 0x7174, Field6f8c = 0x717c, Field6f98 = 0x7188, Field6f9a = 0x718a, Field6fa0 = 0x7190, Field6fba = 0x71aa, Field6fc4 = 0x71b4, Field6fc8 = 0x71b8, Field6fcc = 0x71bc, Field6fd0 = 0x71c0, Field7745 = 0x7935, Field7746 = 0x7936 };
#else
enum { CameraBase = 0xc18, CameraPosition = 0xc88, PendingList = 0xb30, MessageQueue = 0x890, Auxiliary = 0x2a8, ModeByte = 0xe38, PendingRequest = 0x6f78, RecordsHigh = 0x6000, RecordFlag = 0xf0c, Field6e4b = 0x6e4b, Field6e4c = 0x6e4c, Field6e4d = 0x6e4d, Field6e4e = 0x6e4e, Field6e50 = 0x6e50, Field6e6e = 0x6e6e, Field6ef0 = 0x6ef0, Field6efa = 0x6efa, Field6efc = 0x6efc, Field6efe = 0x6efe, Field6eff = 0x6eff, Field6f00 = 0x6f00, Field6f01 = 0x6f01, Field6f02 = 0x6f02, Field6f04 = 0x6f04, Field6f08 = 0x6f08, Field6f14 = 0x6f14, Field6f84 = 0x6f84, Field6f8c = 0x6f8c, Field6f98 = 0x6f98, Field6f9a = 0x6f9a, Field6fa0 = 0x6fa0, Field6fba = 0x6fba, Field6fc4 = 0x6fc4, Field6fc8 = 0x6fc8, Field6fcc = 0x6fcc, Field6fd0 = 0x6fd0, Field7745 = 0x7745, Field7746 = 0x7746 };
#endif

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
    unsigned char count;
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
void ResetFields_021de110(void* obj);
extern "C" void _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(void* obj, struct Rec021dcf14* rec);
extern "C" void _Z16SetFlag0x4At0xe0P13Flags02033fcc(GameObject* obj);
extern "C" void _Z18ClearFlag0x4At0xe0P13Flags02033fdc(GameObject* obj);
extern "C" int _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(GameObject* obj, int value);
extern "C" void* _Z15GetData02108e10v(void);
extern "C" struct TableEntry021dcf14* _Z24SearchBothTables02079e2cPci(void* table, int key);
extern "C" struct Node021dcf14* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int index);
extern "C" struct First021dcf14* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" void _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(void* obj, void* entry);
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
    unsigned short timer2;
    int f8;
    int fc;
    int f10;
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
    sl[Field6e4b] = phase;
}

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline struct Pending021dcf14 GetPending(unsigned char* work) {
    return *(struct Pending021dcf14*)(work + PendingRequest);
}

// JPN: func_ov025_021dd808
// USA: func_ov025_021dcf14
extern "C" ARM int func_ov025_021dcf14(unsigned char* sl) {
    GameState* battle = GameState::GetInstance();
    struct Entry021dcf14* cur;
    GameObject* objs[5];

    if (sl[Field6e4b] != 0) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        struct Entry021dcf14* e = (struct Entry021dcf14*)(sl + Field6e50);
        for (int i = 0; i < sl[Field6e4d]; i++, e++) {
            if (dt < e->remaining) {
                e->remaining -= dt;
            } else {
                e->remaining = 0;
            }
            e->elapsed += dt;
        }
    }

    cur = (struct Entry021dcf14*)(sl + Field6e50) + sl[Field6e4c];
    __clear(objs, sizeof(objs));

    if (sl[Field6e4b] == 0) {
        return 0;
    }

    if (sl[Field6e4b] == 1) {
        func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
        func_ov000_0216df00(sl + CameraBase, cur->targetId, 0, 0, 1.8f);
        _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(sl);
        void* slot = _Z18GetSlotPtr02160f20Pv(sl);
        if (*(unsigned short*)slot == 0x11b || *(unsigned short*)slot == 0x116) {
            Vector3fix cam = *(Vector3fix*)(sl + CameraPosition);
            cam.z = 0x847a;
            _Z13ApplyVec3TailPvPi(sl + CameraBase, &cam);
        }
        func_ov000_021626a0(sl, 4, 0);
        for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Field6ef0))[i]);
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
            if (*(short*)(sl + Field6efa) >= 2) {
                if (*(short*)(sl + Field6efa) == 4) {
                    base.x = radius + radius / 8;
                }
                base.x = (int)(4096.0f * (0.6f * (radius / 4096.0f)));
            }

            int maxRadius = 0;
            for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
                GameObject* c = objs[i];
                if (c == NULL) {
                    continue;
                }
                Vector3fix off = base;
                Vector3fix face = data_ov025_021eeed4;
                if (*(short*)(sl + Field6efa) >= 3) {
                    if (*(short*)(sl + Field6efa) == 4) {
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
                ResetFields_021de110(&rec);
                rec.f0 = 0;
                rec.id = ((short*)(sl + Field6ef0))[i];
                rec.val = 0x96;
                _ZN8Vector3iaSERKS_(&rec.pos, &dst);
                _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + PendingList, &rec);
                objs[i]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                _Z16SetFlag0x4At0xe0P13Flags02033fcc(objs[i]);
            }
        }

        int maxHeight = 0;
        for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
            GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Field6ef0))[i]);
            if (c && maxHeight < c->obj3D_.GetHeight()) {
                maxHeight = c->obj3D_.GetHeight();
            }
        }
        if (maxHeight >= 0x1800) {
            float scale = 1.0f + 0.8f * (maxHeight / 4096.0f - 1.5f) / 2.5f;
            if (scale >= 1.8f) {
                scale = 1.8f;
            }
            Vector3fix cam = *(Vector3fix*)(sl + CameraPosition);
            cam.z = (int)(4096.0f * (cam.z / 4096.0f * scale));
            _Z13ApplyVec3TailPvPi(sl + CameraBase, &cam);
        }
        SetPhase(sl, 2, 0x9b);
    } else if (sl[Field6e4b] == 2) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
                objs[i] = battle->GetCombatantByIndex(((short*)(sl + Field6ef0))[i]);
            }
            int maxHeight = 0;
            int j;
            for (j = 0; j < *(short*)(sl + Field6efa); j++) {
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
            Vector3fix cam = *(Vector3fix*)(sl + CameraPosition);
            fix32_Divide((int)(4096.0f * (6.0f * scale)), cam.z);
            TIMER = 0xc8;
            if (sl[Field6e4d] != 0) {
                sl[Field6e4b] = 6;
            } else {
                sl[Field6e4b] = 3;
            }
        }
        if (sl[Field6e4b] == 6) {
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
                    unsigned int wait = *(unsigned int*)(sl + Field6f8c);
                    *(unsigned int*)(sl + Field6fc8) = wait;
                    if (wait > 0x9b) {
                        TIMER = wait - 0x9b;
                    }
                }
            }
        }
    } else if (sl[Field6e4b] == 6) {
        if (*(unsigned short*)(sl + Field6e6e) != 0) {
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
                sl[Field6e4e] = 6;
            }
            _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
            if (sl[Field7745] != node->ids[1] || sl[Field7746] != node->ids[0]) {
                int msgId = 0x7f;
                int party = 0;
                if (node->ids[0] >= 0 && node->ids[0] <= 3) {
                    party = 1;
                }
                if (party) {
                    msgId = 0x7e;
                }
                func_ov025_021ed444(sl + MessageQueue, msgId, node->ids[0], 0, 0, node->ids[1], 0);
                sl[Field7745] = node->ids[1];
                sl[Field7746] = node->ids[0];
            }
            if (miss || crit) {
                _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(sl + CameraBase, 0xcc, 0x1f4);
                _Z20SetShortTriple0x6e44Pvttt(sl, 0x199, 0x1f4, 0x64);
                if (crit) {
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x43, 0);
                }
            }
            cur->mode = 1;
            if (sl[Field6e4d] <= ++sl[Field6e4c]) {
                TIMER = 0x64;
                if (miss) {
                    TIMER = 0x96;
                }
                sl[Field6e4b] = 3;
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
    } else if (sl[Field6e4b] == 3) {
        if (sl[Field6e4d] > sl[Field6e4c]) {
            sl[Field6e4b] = 6;
        } else {
            unsigned int dt = battle->GetEffectiveDeltaTime();
            if (dt < TIMER) {
                TIMER -= dt;
            } else {
                TIMER = 0;
            }
        }
    } else if (sl[Field6e4b] == 4) {
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
                            sl[Field6e4e] = 4;
                        }
                    }
                }
            }
            if (!miss && !found && !crit) {
                for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
                    GameObject* c = battle->GetCombatantByIndex(((short*)(sl + Field6ef0))[i]);
                    if (c && !_Z23CheckSubstructFlag0x100Ph(c)) {
                        objs[i] = c;
                        if (!any && objs[i]) {
                            objs[i]->obj3D_.MakeVisible();
                        }
                    }
                }
                for (int i = 0; i < *(short*)(sl + Field6efa); i++) {
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
                        ResetFields_021de110(&rec);
                        rec.f0 = 1;
                        rec.id = cur->actorId;
                        rec.val = 0x64;
                        rec.angle = fix32ReduceAngle0To2Pi(rotY + data_ov025_021eeef8[i]);
                        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + PendingList, &rec);
                        ResetFields_021de110(&rec);
                        rec.f0 = 0;
                        rec.id = ((short*)(sl + Field6ef0))[i];
                        rec.val = 0x12c;
                        _ZN8Vector3iaSERKS_(&rec.pos, &dst);
                        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(sl + PendingList, &rec);
                        objs[i]->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef460, 0);
                        _Z16SetFlag0x4At0xe0P13Flags02033fcc(objs[i]);
                    }
                }
                sl[Field6e4e] = 0;
                SetPhase(sl, 5, 0x12c);
            } else {
                func_ov000_021626a0(sl, 4, 0);
                GameObject* target = NULL;
                int id = func_ov000_0215ffa0(node);
                if (miss || crit) {
                    if (!_Z20TryDispatch_021dce7cPhP10In021dce7ci(sl, slot, id)) {
                        func_ov000_0216df00(sl + CameraBase, id, 0, 0, 1.8f);
                    }
                    target = battle->GetCombatantByIndex(id);
                } else if (found) {
                    func_ov000_0216df00(sl + CameraBase, foundId, 0, 0, 1.8f);
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
                    _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(short*)(sl + Field6f9a), 0);
                }
                if (!crit) {
                    if (miss) {
                        cur->mode = 3;
                    }
                    _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
                    cur->mode = 1;
                    if (sl[Field6e4d] <= ++sl[Field6e4c]) {
                        sl[Field6e4e] = 0;
                        SetPhase(sl, 5, 1000);
                    }
                } else {
                    unsigned int wait = *(unsigned int*)(sl + Field6f8c);
                    *(unsigned int*)(sl + Field6fc8) = wait;
                    sl[Field6e4e] = 0;
                    SetPhase(sl, 7, wait);
                }
            }
        }
    } else if (sl[Field6e4b] == 7) {
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
            func_ov025_021eabd0(sl + Auxiliary, IsPartyMember(id));
            _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
            func_ov025_021ead5c(sl + Auxiliary, IsPartyMember(id));
            SetPhase(sl, 5, 1000);
        }
    } else if (sl[Field6e4b] == 5) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            for (int i = 0; i < sl[Field6e4d]; i++) {
                GameObject* c = battle->GetCombatantByIndex(((struct Entry021dcf14*)(sl + Field6e50))[i].actorId);
                if (c) {
                    _Z18ClearFlag0x4At0xe0P13Flags02033fdc(c);
                }
                ((struct Entry021dcf14*)(sl + Field6e50))[i].actorId = -1;
                ((struct Entry021dcf14*)(sl + Field6e50))[i].targetId = -1;
            }
            sl[Field6e4d] = 0;
            sl[Field6e4b] = 0;
        }
    }
    return 0;
}

// JPN: func_ov025_021dea10
// USA: func_ov025_021de110
ARM void ResetFields_021de110(void* obj) {
    *(int*)((char*)obj + 0x0) = 0;
    *(int*)((char*)obj + 0x4) = 0;
    *(int*)((char*)obj + 0x18) = 0;
}

struct List021de124 {
    unsigned short id;
    char pad02[7];
    unsigned char count;
};

struct Entry021de124 {
    struct List021de124* list;
    int mode;
    char pad8[4];
    int nodeIndex;
    char pad10[8];
    unsigned short elapsed;
    unsigned short remaining;
};

struct Pending021de124 {
    char pad0[0x2c];
    unsigned short flags;
    short a;
    short b;
    char pad32[6];
    unsigned char mode;
};


extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
extern "C" void func_ov000_0216df00(void* obj, int id, int b, int c, float scale);
extern "C" void func_ov000_0216dbf0(void* obj, int* id, int a, int b);
extern "C" void _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(void* obj);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void _ZN8Vector3iaSERKS_(Vector3fix* dst, const Vector3fix* src);
extern "C" void func_ov000_02167f10(void* obj);
extern "C" void _Z18ClearFlag0x4At0xe0P13Flags02033fdc(GameObject* obj);
extern "C" void* _Z15GetData02108e10v(void);
extern "C" int func_ov025_021ed444(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" int func_ov025_021ed564(void* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" void _Z20SetShortTriple0x6e44Pvttt(void* obj, unsigned short a, unsigned short b, unsigned short c);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" int _Z24GetShortAtField0xEBound3Pci(void* node, int idx);
extern "C" void* _Z19GetActiveCombatWorkv(void);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021eabd0(void* obj, bool party);
extern "C" void func_ov025_021ead5c(void* obj, bool party);
extern "C" void func_ov025_021ed344(void* obj, int val);
extern "C" int _Z13Check021ed2f4Pv(void* obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_02043124(int obj);
extern "C" int _Z20TryDispatch_021dce7cPhP10In021dce7ci(void* obj, void* slot, int id);
extern "C" void* func_02057924(void);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, struct InitStruct02078484Struct* req);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(struct Obj0205eaa0* obj, int a, int b);
extern "C" short _Z24ClampScaledStat_0216352ciff(int id, float a, float b);
extern "C" int func_ov000_021635e4(int id, int mode);

extern Vector3fix data_ov025_021eef04;
extern struct Obj0205eaa0 data_02108760;

#undef TIMER
#define TIMER (GetTimer021ef974().timer2)

static inline int IsFirstShortParty(void* node) {
    return _Z24GetShortAtField0xEBound3Pci(node, 0) >= 0 && _Z24GetShortAtField0xEBound3Pci(node, 0) <= 3;
}

static inline int IsInRange(int id) {
    return id >= 0xc0 && id <= 0xc7;
}

// JPN: func_ov025_021dea24
// USA: func_ov025_021de124
extern "C" ARM int func_ov025_021de124(unsigned char* sl) {
    GameState* battle = GameState::GetInstance();
    struct List021de124* list;
    struct Entry021de124* cur;

    if (sl[Field6efe] != 0) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        struct Entry021de124* e = (struct Entry021de124*)(sl + Field6f08);
        for (int i = 0; i < sl[Field6f00]; i++, e++) {
            if (dt < e->remaining) {
                e->remaining -= dt;
            } else {
                e->remaining = 0;
            }
            e->elapsed += dt;
        }
    }

    if (sl[Field6efe] == 0) {
        return 0;
    }
    cur = (struct Entry021de124*)(sl + Field6f08) + sl[Field6eff];

    if (sl[Field6efe] == 1) {
        list = cur->list;
        struct Node021dcf14* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, cur->nodeIndex);
        int n = list->count - 1;
        if (n <= 0) {
            n = 1;
        }
        *(unsigned int*)(sl + Field6fc8) = *(unsigned int*)(sl + Field6f8c);
        if (list->count > 1) {
            if (*(unsigned int*)(sl + Field6f8c) > *(unsigned int*)(sl + Field6f84)) {
                *(unsigned int*)(sl + Field6fc8) = *(unsigned int*)(sl + Field6f8c) - *(unsigned int*)(sl + Field6f84);
            }
        }
        *(unsigned int*)(sl + Field6fcc) = *(unsigned int*)(sl + Field6f84) / n;
        *(unsigned int*)(sl + Field6fc4) = 0;
        if (*(unsigned int*)(sl + Field6fcc) > *(unsigned int*)(sl + Field6fc8)) {
            *(unsigned int*)(sl + Field6fc4) = *(unsigned int*)(sl + Field6fcc) - *(unsigned int*)(sl + Field6fc8);
        }
        if (!(sl[ModeByte] != 0 && list->id != 0x246 && list->id != 0x30d)
            && !(list->id == 0x30f || list->id == 0x243)) {
            func_ov000_0216d370(sl + CameraBase, 0, 1, 1);
            func_ov000_0216df00(sl + CameraBase, node->ids[0], 0, 0, 1.8f);
            _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(sl);
            func_ov000_021626a0(sl, 4, 0);
            GameObject* obj = battle->GetCombatantByIndex(node->ids[0]);
            if (obj) {
                obj->obj3D_.MakeVisible();
            }
        }
        sl[Field6efe] = 2;
    } else if (sl[Field6efe] == 2) {
        list = cur->list;
        int index = cur->nodeIndex;
        int found = 0;
        TIMER = 0;
        struct Node021dcf14* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, index);
        for (int i = 1; i < node->count; i++) {
            if (node->codes[i] == 1 || node->codes[i] == 2) {
                found = 1;
            }
        }
        int id = node->ids[0];
        if (node->count > 1) {
            if (node->codes[1] == 8 || node->codes[1] == 7 || node->codes[1] == 6) {
                id = node->ids[1];
            }
        }
        GameObject* obj = battle->GetCombatantByIndex(id);
        if (obj && !found) {
            void* fx = func_02057924();
            struct InitStruct02078484Struct req;
            _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
            req.objectId = id;
            if (*(unsigned int*)(sl + Field6fa0) & 1) {
                req.offset.y += obj->obj3D_.GetHeight() / 2;
            }
            _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(short*)(sl + Field6f9a), 0);
            _Z26FindNodeAndProcess02057fb4Pvii(fx, *(short*)(sl + Field6f98), &req);
            TIMER = *(unsigned int*)(sl + Field6fc8);
        }
        sl[Field6efe] = 3;
    } else if (sl[Field6efe] == 3) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            struct List021de124* list = cur->list;
            struct Node021dcf14* node;
            int hit = 0;
            int flag8;
            int index = cur->nodeIndex;
            TIMER = 0;
            node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, index);
            int i = 1;
            flag8 = 0;
            for (; i < node->count; i++) {
                if (node->codes[i] == 8 || node->codes[i] == 7 || node->codes[i] == 6) {
                    flag8 = 1;
                }
                if (node->codes[i] == 1 || node->codes[i] == 2) {
                    cur->mode = 2;
                    hit = 1;
                    break;
                }
            }
            _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, cur);
            if (flag8) {
                int msgId = 0x7f;
                int party = 0;
                if (node->ids[1] >= 0 && node->ids[1] <= 3) {
                    party = 1;
                }
                if (party) {
                    msgId = 0x7e;
                }
                unsigned short msg = msgId;
                if (func_ov025_021ed564(sl + MessageQueue, msg, node->ids[0], 0, 0, node->ids[1], 0) < 0) {
                    func_ov025_021ed444(sl + MessageQueue, msg, node->ids[0], 0, 0, node->ids[1], 0);
                }
            }
            sl[Field6eff]++;
            sl[Field6efe] = 4;
            TIMER = *(unsigned int*)(sl + Field6fc4);
            if (hit) {
                if (sl[ModeByte] != 2) {
                    _Z20SetShortTriple0x6e44Pvttt(sl, 0xcc, 0xc8, 0x64);
                }
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x43, 0);
                TIMER = *(unsigned int*)(sl + Field6fc4) + 0x1f4;
            }
            if (list->count <= sl[Field6eff]) {
                sl[Field6f01] = 1;
                bool party = IsFirstShortParty(node);
                struct List021de124* slot = (struct List021de124*)_Z18GetSlotPtr02160f20Pv(_Z19GetActiveCombatWorkv());
                int found = -1;
                for (int i = 0; i < slot->count; i++) {
                    struct Node021dcf14* n = _Z22GetNodeAtIndex021600f8P12List021600f8i(slot, i);
                    if (n == 0) {
                        continue;
                    }
                    int v = func_ov000_0215ffa0(n);
                    if (party) {
                        int m = v >= 0 && v <= 3;
                        if (m) {
                            found = v;
                            break;
                        }
                    } else {
                        int m = v >= 0 && v <= 3;
                        if (!m) {
                            found = v;
                            break;
                        }
                    }
                }
                if (found >= 0) {
                    func_ov025_021eabd0(sl + Auxiliary, party);
                    func_ov025_021ead5c(sl + Auxiliary, party);
                    func_ov025_021ed344(sl + MessageQueue, 0);
                }
                TIMER = 0x5dc;
            }
        }
    } else if (sl[Field6efe] == 4) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            if (_Z13Check021ed2f4Pv(sl + MessageQueue)) {
                if (sl[Field6f00] > sl[Field6eff]) {
                    sl[Field6efe] = 2;
                }
                if (sl[Field6f01] == 1) {
                    sl[Field6efe] = 5;
                    sl[Field6f01] = 0;
                    sl[Field6eff] = 0;
                }
            }
        }
    } else if (sl[Field6efe] == 5) {
        if (!_Z13Check021ed2f4Pv(sl + MessageQueue)) {
            return 1;
        }
        func_02043124(_Z26GetGlobalField0x1c020421a0v());
        func_ov000_021626a0(sl, 4, 0);
        GameObject* lead = battle->GetCombatantByIndex(*(short*)(sl + Field6efc));
        if (lead) {
            lead->obj3D_.MakeVisible();
        }
        list = cur->list;
        struct TableEntry021dcf14* row =
            _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), *(short*)list);
        int kind2 = 0;
        int r7 = 0;
        int r8 = 0;
        if (row) {
            if (row->kind18 == 2) {
                kind2 = 1;
            }
        }
        if (list->id == 0x246 || list->id == 0x30d) {
            r7 = 1;
        }
        if (list->id == 0x30f || list->id == 0x243) {
            r8 = 1;
        }
        void* fx = func_02057924();
        struct InitStruct02078484Struct req;
        _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
        if (r7 || (sl[ModeByte] != 3 && kind2 != 0 && r8 == 0)) {
            func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
            if (!_Z20TryDispatch_021dce7cPhP10In021dce7ci(sl, list, *(short*)(sl + Field6efc))) {
                func_ov000_0216df00(sl + CameraBase, *(short*)(sl + Field6efc), 0, 0, 1.8f);
            }
            req.objectId = *(short*)(sl + Field6efc);
            if (*(unsigned int*)(sl + Field6fa0) & 1) {
                req.offset.y += lead->obj3D_.GetHeight() / 2;
            }
            struct Pending021de124* p;
            int id = *(short*)(sl + Field6efc);
            int inRange = 0;
            if (id >= 0xc0) {
                inRange = id <= 0xc7;
            }
            if (inRange) {
                p = (struct Pending021de124*)(sl + PendingRequest);
                if (p->flags & 1) {
                    int v = 0x1000;
                    switch (p->mode) {
                    case 0:
                        v = _Z24ClampScaledStat_0216352ciff(id, p->a / 4096.0f, p->b / 4096.0f);
                        break;
                    case 1:
                        v = func_ov000_021635e4(id, (unsigned char)p->a);
                        if (p->b <= v) {
                            v = p->b;
                        }
                        break;
                    }
                    Vector3fix sc;
                    sc.x = v;
                    sc.y = v;
                    sc.z = v;
                    _ZN8Vector3iaSERKS_(&req.scale, &sc);
                }
            }
            _Z26FindNodeAndProcess02057fb4Pvii(fx, *(short*)(sl + Field6f98), &req);
            if (*(short*)(sl + Field6f9a) != -1) {
                _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(short*)(sl + Field6f9a), 0);
            } else if (*(unsigned short*)(sl + Field6f04) != -1) {
                _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(unsigned short*)(sl + Field6f04), 0);
            }
            TIMER = *(unsigned int*)(sl + Field6fc8);
        } else if (sl[ModeByte] == 3 || kind2 == 0 || r8 != 0) {
            int savedId;
            func_ov000_0216d370(sl + CameraBase, 1, 1, 1);
            savedId = *(short*)(sl + Field6efc);
            if (kind2) {
                func_ov000_0216dbf0(sl + CameraBase, &savedId, 1, 1);
            } else {
                func_ov000_0216df00(sl + CameraBase, *(short*)(sl + Field6efc), 0, 0, 1.8f);
            }
            func_ov000_021626a0(sl, 4, 0);
            GameObject* obj = battle->GetCombatantByIndex(savedId);
            if (obj) {
                func_ov000_02167f10(sl);
                Vector3fix v = data_ov025_021eef04;
                _ZN8Vector3iaSERKS_(&obj->obj3D_.position_, &v);
                obj->obj3D_.MakeVisible();
            }
            _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(unsigned short*)(sl + Field6f04), 0);
            req.objectId = savedId;
            _Z26FindNodeAndProcess02057fb4Pvii(fx, *(unsigned short*)(sl + Field6f02), &req);
            TIMER = *(unsigned int*)(sl + Field6fd0);
            if (TIMER == 0) {
                TIMER = 0x1f4;
            }
        }
        sl[Field6efe] = 6;
    } else if (sl[Field6efe] == 6) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            struct List021de124* list;
            struct Node021dcf14* node;
            int v, first, i;
            i = 0;
            list = cur->list;
            TIMER = i;
            v = -1;
            first = 1;
            for (; i < list->count; i++) {
                int off = i * 0x1c;
                node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, *(int*)(sl + off + Field6f14));
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 1 || node->codes[j] == 2) {
                        *(int*)(sl + RecordsHigh + off + RecordFlag) = 1;
                        if (v < 0) {
                            v = func_ov000_0215ffa0(node);
                        }
                        if (first) {
                            bool party = IsPartyMember(v);
                            func_ov025_021eabd0(sl + Auxiliary, party);
                            first = 0;
                        }
                        _Z28ForwardPackedFields_021d8bfcPvP21PackedFields_021d8bfc(sl, (struct Entry021de124*)(sl + Field6f08 + off));
                    }
                }
            }
            bool party = IsPartyMember(v);
            func_ov025_021ead5c(sl + Auxiliary, party);
            TIMER = *(unsigned int*)(sl + Field6fc8);
            sl[Field6efe] = 8;
        }
    } else if (sl[Field6efe] == 8) {
        unsigned int dt = battle->GetEffectiveDeltaTime();
        if (dt < TIMER) {
            TIMER -= dt;
        } else {
            TIMER = 0;
            for (int i = 0; i < 4; i++) {
                GameObject* obj = battle->GetCombatantByIndex(((short*)(sl + Field6fba))[i]);
                if (obj) {
                    _Z18ClearFlag0x4At0xe0P13Flags02033fdc(obj);
                }
                ((short*)(sl + Field6fba))[i] = -1;
            }
            GameObject* obj = battle->GetCombatantByIndex(*(short*)(sl + Field6efc));
            if (obj) {
                _Z18ClearFlag0x4At0xe0P13Flags02033fdc(obj);
            }
            sl[Field6f01] = 0;
            sl[Field6eff] = 0;
            sl[Field6efe] = 0;
            *(unsigned short*)(sl + Field6f02) = 0;
            *(unsigned short*)(sl + Field6f04) = 0xffff;
            *(unsigned int*)(sl + Field6fd0) = 0;
        }
    }
    return 0;
}
