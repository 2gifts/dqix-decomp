// JPN: func_ov025_021e3668
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "System/Matrix.h"

#if defined(jpn)
enum { NotificationField = 0x4, CombatantSubobject = 0x144, WorkFlag = 0x71c5 };
#else
enum { NotificationField = 0xc, CombatantSubobject = 0x150, WorkFlag = 0x6fd5 };
#endif

struct Pos021e3178 { int x, y, z; };

struct Trig021e3178 {
    char pad0[8];
    unsigned short slot;
    unsigned short kind;
    int limit;
};


struct Ent021e3178 {
    char pad0[0x20];
    unsigned short id;
    char pad22[0xe];
    struct Ent021e3178* next;
};

struct Chain021e3178 {
    struct Chain021e3178* head;
    char pad4[0xa];
    short s0e;
    char pad10[0xb];
    unsigned char b1b;
    char pad1c[4];
    struct Chain021e3178* next;
};

struct Ev021e3178 {
    short id;
    char pad2[2];
    short s4;
    char pad6[2];
    unsigned char n8;
    unsigned char n9;
    char padA[6];
    struct Ent021e3178* ents;
    struct Chain021e3178* chains;
    unsigned short s18;
};

struct Node021e3178 {
    char pad0[0x14];
    unsigned char codes[3];
    unsigned char count;
    char pad18[4];
    unsigned char b1c;
    char pad1d[3];
    unsigned short id20;
    char pad22[4];
    unsigned char b26[6];
};

static inline unsigned char* Codes021e3178(Node021e3178* n) { return n->codes; }

struct Rec021e3178 {
    char pad0[0x18];
    unsigned int lo : 5;
    unsigned int kind : 7;
    unsigned int hi : 20;
};

struct Buf021e3178 {
    char pad0[6];
    unsigned short s6;
    char pad8[4];
};

struct Combatant021e3178 {
    char pad0[CombatantSubobject];
    unsigned char* flags;
};

extern int data_ov025_021ef988;
extern int data_ov025_021eef40[];

extern "C" void func_ov025_021eb044(void* obj, ...);
extern "C" int func_ov000_0215fd90(void* entry, unsigned char effect);
extern "C" void func_ov000_02162c14(void* work, int id, struct Buf021e3178* out);
extern "C" void* _Z19GetActiveCombatWorkv(void);
extern "C" void* _Z15GetData02108e10v(void);
extern "C" struct Rec021e3178* _Z24SearchBothTables02079e2cPci(void* table, int key);
extern "C" struct Node021e3178* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" struct Node021e3178* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int index);
extern "C" struct Node021e3178* _Z22GetNodeAtIndex0215feb4Pcii(void* base, int index, int slot);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* node, int index, int depth);
extern "C" struct Combatant021e3178* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" int _Z15TestBit2At0x2f4Ph(unsigned char* flags);
extern "C" int _ZNK8Object3D9GetRadiusEv(void* obj);
extern "C" void __clear(void* p, int n);

#define NOTIFY() func_ov025_021eb044(*(void**)((char*)&data_ov025_021ef988 + NotificationField), a->slot)

// USA: func_ov025_021e3178
extern "C" ARM int func_ov025_021e3178(struct Trig021e3178* a, struct Ev021e3178* b) {
    GameState* gs = GameState::GetInstance();
    if (a->slot == 0) return 1;
    switch (a->kind) {
    case 1:
    case 2:
    case 3:
    case 4: {
        Vector3fix sum;
        struct Ent021e3178* e;
        void* o;
        int n;
        int rad;
        __clear(&sum, 0xc);
        n = 0;
        rad = 0;
        for (e = b->ents; e; e = e->next) {
            o = gs->GetGameObjectByIndex(e->id);
            if (o) {
                Pos021e3178 tmp = *(Pos021e3178*)((char*)o + 0x44);
                Vector3fix_Add(&sum, (Vector3fix*)&tmp, &sum);
                rad += _ZNK8Object3D9GetRadiusEv(o) / 2;
                n++;
            }
        }
        if (n > 0) {
            int d = n << 12;
            Vector3fixMultiplyScalar(&sum, fix32_Divide(0x1000, d), &sum);
            rad = fix32_Divide(rad, d);
        }
        Vector3fix sum2;
        __clear(&sum2, 0xc);
        int n2 = 0;
        int rad2 = 0;
        for (struct Chain021e3178* c = b->chains; c; c = c->next) {
            void* o = gs->GetGameObjectByIndex(c->s0e);
            if (o) {
                Pos021e3178 tmp2 = *(Pos021e3178*)((char*)o + 0x44);
                Vector3fix_Add(&sum2, (Vector3fix*)&tmp2, &sum2);
                rad2 += _ZNK8Object3D9GetRadiusEv(o) / 2;
                n2++;
            }
        }
        if (n2 > 0) {
            int d = n2 << 12;
            Vector3fixMultiplyScalar(&sum2, fix32_Divide(0x1000, d), &sum2);
            rad2 = fix32_Divide(rad2, d);
        }
        int diff = Vector3fix_Distance(&sum, &sum2) - rad - rad2;
        switch (a->kind) {
        case 1:
            if (diff < a->limit) NOTIFY();
            break;
        case 2:
            if (diff > a->limit) NOTIFY();
            break;
        case 3:
            if (diff <= a->limit) NOTIFY();
            break;
        case 4:
            if (diff >= a->limit) NOTIFY();
            break;
        }
        break;
    }
    case 5: {
        if (b->n8 == 1 && b->n9 == 1) {
            struct Node021e3178* n6 = _Z22GetNodeAtIndex02160094P12List02160094i(b, 0);
            struct Node021e3178* n0 = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, 0);
            if (n6 && n0) {
                if (n6->id20 == *(short*)((char*)n0 + 0xe)) NOTIFY();
            }
        }
        break;
    }
    case 6: {
        struct Rec021e3178* rec = _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), b->id);
        if (!rec) return 0;
        unsigned short id = b->id;
        if (id == 0x74) {
            for (struct Chain021e3178* c = b->chains; c; c = c->next) {
                if (c->b1b) {
                    NOTIFY();
                    return 1;
                }
            }
        } else if (id == 0xa5) {
            if (b->s4 > 0) {
                NOTIFY();
                return 1;
            }
        } else if (rec->kind == 0x12) {
            for (struct Chain021e3178* c = b->chains; c; c = c->next) {
                for (struct Chain021e3178* m = c->head; m; m = m->next) {
                    if (func_ov000_0215fd90(m, 3)) {
                        NOTIFY();
                        return 1;
                    }
                }
            }
        }
        break;
    }
    case 11: {
        if (b->n9 == 0) break;
        struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, 0);
        if (!node) break;
        for (int j = 0; j < node->count; j++) {
            int v = ((unsigned char*)((int)node + 0x14))[j];
            if (!(v != 8 && v != 6 && v != 7)) {
                NOTIFY();
                break;
            }
        }
        break;
    }
    case 10: {
        if (b->n9 == 0) break;
        for (int i = 0; i < b->n9; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, i);
            if (node) {
                unsigned char* codes = node->codes;
                for (int j = 1; j < node->count; j++) {
                    int v = codes[j];
                    if (v == 3) {
                        NOTIFY();
                        break;
                    }
                    if (v == 8 || v == 7 || v == 6) break;
                }
            }
        }
        break;
    }
    case 7: {
        if (b->n9 == 0) break;
        for (int i = 0; i < b->n9; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, i);
            if (node) {
                unsigned char* codes = node->codes;
                for (int j = 1; j < node->count; j++) {
                    int v = codes[j];
                    if (!(v != 2 && v != 5 && v != 4 && v != 3)) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 13: {
        if (b->n9 == 0) break;
        for (int i = 0; i < b->n9; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, i);
            if (node) {
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 1) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 8: {
        for (int i = 0; i < b->n8; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex02160094P12List02160094i(b, i);
            if (node) {
                for (int j = 0; j < 6; j++) {
                    if (node->b26[j]) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        break;
    }
    case 12:
    case 14:
    case 17: {
        for (int i = 0; i < b->n8; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex02160094P12List02160094i(b, i);
            if (node) {
                for (int k = 0; k < 6; k++) {
                    int found = 0;
                    for (int m = 0; m < node->b26[k]; m++) {
                        void* x = _Z22GetNodeAtIndex0215feb4Pcii(node, m, k & 0xff);
                        if (x) {
                            if (func_ov000_0215fd90(x, 0x22) && a->kind == 0xc) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                            if (func_ov000_0215fd90(x, 0x25) && a->kind == 0xe) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                            if (a->kind == 0x11 && (func_ov000_0215fd90(x, 0x23) || func_ov000_0215fd90(x, 7))) {
                                NOTIFY();
                                found = 1;
                                break;
                            }
                        }
                    }
                    if (found) break;
                }
            }
        }
        break;
    }
    case 15: {
        void* w = _Z19GetActiveCombatWorkv();
        if (w && *(unsigned char*)((char*)w + WorkFlag)) NOTIFY();
        break;
    }
    case 22:
        if (b->s18 == 0x1ef) {
            NOTIFY();
            break;
        }
        // fallthrough
    case 16: {
        for (struct Chain021e3178* c = b->chains; c; c = c->next) {
            for (struct Chain021e3178* m = c->head; m; m = m->next) {
                if (func_ov000_0215fd90(m, 7)) {
                    NOTIFY();
                    return 1;
                }
            }
        }
        break;
    }
    case 18: {
        struct Ent021e3178* ent = b->ents;
        if (!ent) break;
        int id = ent->id;
        void* w = _Z19GetActiveCombatWorkv();
        if (!w) break;
        struct Buf021e3178 buf;
        func_ov000_02162c14(w, id, &buf);
        if (buf.s6 == 0x520e) {
            NOTIFY();
            return 1;
        }
        break;
    }
    case 23: {
        struct Ent021e3178* ent = b->ents;
        if (!ent) break;
        int id = ent->id;
        GameState* g = GameState::GetInstance();
        if (!g) break;
        struct Combatant021e3178* c = _Z25GetCombatantWithFlag0x100P9GameStatei(g, id);
        if (!c) break;
        if (_Z15TestBit2At0x2f4Ph(c->flags)) {
            NOTIFY();
            return 1;
        }
        break;
    }
    case 19:
    case 20:
    case 21: {
        if (b->n9 == 0) break;
        int fa = 0;
        int fb = 0;
        for (int i = 0; i < b->n9; i++) {
            struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, i);
            if (node) {
                for (int j = 1; j < node->count; j++) {
                    if (node->codes[j] == 0xa) {
                        fa = 1;
                        if (a->kind == 0x14) {
                            NOTIFY();
                            break;
                        }
                    }
                }
                struct Ent021e3178* first = *(struct Ent021e3178**)node;
                if (first && *(unsigned char*)((char*)first + 0x1c)) {
                    fb = 1;
                    if (a->kind == 0x13) {
                        NOTIFY();
                        break;
                    }
                }
            }
        }
        if (a->kind == 0x15 && fa && fb) NOTIFY();
        break;
    }
    case 9: {
        struct Rec021e3178* rec = _Z24SearchBothTables02079e2cPci(_Z15GetData02108e10v(), b->id);
        if (!rec) return 0;
        struct Node021e3178* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(b, 0);
        if (!node) return 0;
        if (!node) return 0;
        void* p = _Z23FindNodeAtDepth0215fff4Pvii(node, 0, 0);
        if (!p) return 0;
        if (!p) return 0;
        for (int* t = data_ov025_021eef40; *t != -1; t++) {
            if (func_ov000_0215fd90(p, *t)) {
                NOTIFY();
                return 1;
            }
        }
        break;
    }
    default:
    case 0:
        func_ov025_021eb044(*(void**)((char*)&data_ov025_021ef988 + NotificationField));
        break;
    }
    return 1;
}
