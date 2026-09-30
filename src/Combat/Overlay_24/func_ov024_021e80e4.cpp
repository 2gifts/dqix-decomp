#include <globaldefs.h>

struct Bits8_021e80e4 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

struct Id12_021e80e4 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Kind7_021e80e4 {
    unsigned int gap : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Pack10_021e80e4 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Rec_021e80e4 {
    char pad0[4];
    struct Id12_021e80e4 f4;
    char pad1[0x10];
    struct Kind7_021e80e4 f18;
    char pad2[8];
    struct Pack10_021e80e4 f24;
    struct Pack10_021e80e4 f28;
};

struct Step_021e80e4 {
    unsigned short f0;
    char pad0[2];
    struct Step_021e80e4* next;
};

struct Entry_021e80e4 {
    char pad0[8];
    struct Step_021e80e4* f8;
    short fc;
    char pad1[0x12];
    struct Entry_021e80e4* next;
};

struct Node_021e80e4 {
    struct Entry_021e80e4* f0;
    char pad0[4];
    struct Entry_021e80e4* f8;
    char pad1[0xc];
    unsigned char f18;
    char pad2[7];
    struct Node_021e80e4* next;
};

struct Chain_021e80e4 {
    char pad0[0x20];
    unsigned short f20;
};

struct List_021e80e4 {
    char pad0[6];
    short f6;
    char pad1;
    unsigned char count;
    char pad2[2];
    struct Bits8_021e80e4 fc;
    char pad3[7];
    struct Node_021e80e4* head;
    char pad4[2];
    unsigned short f1a;
    unsigned short f1c;
    unsigned short f1e;
    unsigned short f20;
};

struct Act_021e80e4 {
    int f0;
    struct List_021e80e4* f4;
    char pad0[8];
    void* f10;
    int f14;
    char pad1[0x2c];
    short f44;
    char pad2[0x31];
    unsigned char f77;
};

struct Ids16_021e80e4 {
    short v[16];
};

#define IN_RANGE_021e80e4(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

extern "C" struct Ids16_021e80e4 data_ov024_021fe800;

extern "C" int _Z19ClassifyField0x81fePc(void* world);
extern "C" struct Chain_021e80e4* _Z22GetNodeAtIndex02160094P12List02160094i(struct List_021e80e4* list, int index);
extern "C" struct Node_021e80e4* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List_021e80e4* list, int index);
extern "C" short func_ov000_0215ffa0(struct Node_021e80e4* node);
extern "C" int _Z26CheckAnyBitOrFlag_02159f7cPvP15Bits64_02159f7c(void* world, struct Entry_021e80e4* entry);
extern "C" int func_ov000_0215fd90(struct Entry_021e80e4* entry, int kind);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, struct Entry_021e80e4* entry, unsigned short v);
extern "C" unsigned short func_ov024_021e9b24(struct Act_021e80e4* self, int id, struct Rec_021e80e4* rec, int flag);

// USA: func_ov024_021e80e4
extern "C" ARM void func_ov024_021e80e4(struct Act_021e80e4* self, struct List_021e80e4* list, struct Rec_021e80e4* rec, int fillExtra, unsigned char forced, struct Rec_021e80e4* altRec) {
    struct Ids16_021e80e4 ids;

    if (_Z19ClassifyField0x81fePc(self->f10) != 0) {
        struct Chain_021e80e4* chain = _Z22GetNodeAtIndex02160094P12List02160094i(list, 0);
        if (chain != 0) {
            if (chain->f20 == 0) {
                list->f1a = 0x260;
                return;
            }
        }
    }
    if (rec->f4.id == 0x61 && forced == 0) return;

    int idCount = 0;
    int allyGroups = 0;
    int foeGroups = 0;
    int allyMarked = 0;
    int foeMarked = 0;
    int allyBlocked = 0;
    int foeBlocked = 0;
    unsigned char allyOk = 1;
    unsigned char foeOk = 1;
    int allyHits = self->f14;
    int foeHits = allyHits;
    if (rec->f18.kind == 1) {
        allyHits = foeHits = 0;
    }
    ids = data_ov024_021fe800;

    for (int i = 0; i < list->count; i++) {
        struct Node_021e80e4* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
        if (node == 0) continue;
        int id = func_ov000_0215ffa0(node);
        struct Entry_021e80e4* e;
        int active = 1;
        if (rec->f18.kind == 1) {
            active = 0;
            for (e = node->f0; e != 0; e = e->next) {
                if (_Z26CheckAnyBitOrFlag_02159f7cPvP15Bits64_02159f7c(self->f10, e) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        allyOk = 0;
                        allyMarked++;
                    } else {
                        foeOk = 0;
                        foeMarked++;
                    }
                } else if (func_ov000_0215fd90(e, 0xd) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        allyBlocked++;
                    } else {
                        foeBlocked = 0;
                    }
                    continue;
                } else if (func_ov000_0215fd90(e, 4) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        allyMarked++;
                    } else {
                        foeMarked++;
                    }
                }
                if (e->fc != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        allyHits++;
                    } else {
                        foeHits++;
                    }
                    active = 1;
                }
            }
            for (e = node->f8; e != 0; e = e->next) {
                if (func_ov000_0215fd90(e, 0xd) != 0) {
                    if (IN_RANGE_021e80e4(id)) {
                        allyBlocked++;
                    } else {
                        foeBlocked++;
                    }
                }
            }
        }
        if (active == 0) continue;
        int found = 0;
        for (int j = 0; j < idCount; j++) {
            if (id == ids.v[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            ids.v[idCount++] = id;
            if (IN_RANGE_021e80e4(id)) {
                allyGroups++;
            } else {
                foeGroups++;
            }
        }
        if (i == 0xf) break;
    }

    unsigned char allyAll = 0;
    unsigned char foeAll = 0;
    int foeMsg;
    unsigned char grouped;
    int allyMsg;
    allyMsg = foeMsg = 0;
    grouped = 0;
    int kind = rec->f18.kind;
    if (kind == 1) {
        if (allyGroups > 1) {
            allyMsg = 3;
        } else {
            allyMsg = allyHits > 1 ? 0x261 : 2;
        }
        if (foeGroups > 1) {
            foeMsg = 6;
        } else {
            foeMsg = foeHits > 1 ? 0x262 : 5;
        }
        grouped = 1;
        if (allyHits + allyMarked >= 2) {
            allyOk = 1;
            allyAll = 1;
        }
        if (foeHits + foeMarked >= 2) {
            foeOk = 1;
            foeAll = 1;
        }
        if (allyBlocked != 0) allyOk = 0;
        if (foeBlocked != 0) foeOk = 0;
    }
    if (rec->f4.id == 0x166 || rec->f4.id == 0x167 || rec->f4.id == 0x38c || rec->f4.id == 0x38d || rec->f4.id == 0x38e || rec->f4.id == 0x38f) {
        foeMsg = list->count > 1 ? 0x218 : 0x38;
    }
    if (kind == 0x31) {
        if (self->f14 > 1) {
            foeMsg = 0xf2;
            allyMsg = foeMsg;
        } else {
            foeMsg = 0xf1;
            allyMsg = foeMsg;
        }
        if (self->f14 == 0) {
            if (list->count >= 2) {
                foeAll = 1;
                allyAll = 1;
            } else {
                struct Node_021e80e4* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, 0);
                if (node != 0 && node->f0 != 0) {
                    if (_Z26CheckAnyBitOrFlag_02159f7cPvP15Bits64_02159f7c(self->f10, node->f0) != 0) {
                        foeOk = 0;
                        allyOk = 0;
                    }
                }
            }
        }
        list->f6 = self->f44;
    }
    if (rec->f4.id == 0x9a) {
        if (self->f14 == 0) {
            allyMsg = 0x1f;
        } else {
            allyMsg = list->count <= 1 ? 0xcb : 0xcc;
        }
        foeMsg = allyMsg;
    }
    if (rec->f4.id == 0x20f) {
        struct List_021e80e4* all;
        int count = 0;
        struct Node_021e80e4* first = 0;
        all = self->f4;
        for (int k = 0; k < all->count; k++) {
            struct Node_021e80e4* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(all, k);
            if (node == 0) continue;
            if (IN_RANGE_021e80e4(func_ov000_0215ffa0(node))) continue;
            if (first == 0) first = node;
            count++;
        }
        int msg = count > 1 ? 0x24a : 0x5b;
        if (first != 0 && first->f0 != 0) {
            _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, first->f0, msg);
        }
        return;
    }

    if (allyAll != 0 || foeAll != 0) {
        for (int i = 0; i < list->count; i++) {
            struct Node_021e80e4* node = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
            if (node == 0) continue;
            int id = func_ov000_0215ffa0(node);
            if (IN_RANGE_021e80e4(id) && allyAll == 0) continue;
            if (!IN_RANGE_021e80e4(id) && foeAll == 0) continue;
            for (struct Entry_021e80e4* e = node->f0; e != 0; e = e->next) {
                for (struct Step_021e80e4* step = e->f8; step != 0; step = step->next) {
                    if (step->f0 == 0x96 || step->f0 == 0x255 || step->f0 == 0x97 || step->f0 == 0x1b9 || step->f0 == 0x24d || step->f0 == 0x2b) {
                        step->f0 = 0;
                    }
                }
            }
        }
    }

    struct Rec_021e80e4* allyRec = rec;
    struct Rec_021e80e4* foeRec = rec;
    if (rec->f18.kind == 1 && forced != 0) {
        struct Chain_021e80e4* chain = _Z22GetNodeAtIndex02160094P12List02160094i(list, 0);
        if (chain != 0) {
            if (IN_RANGE_021e80e4(chain->f20)) {
                foeRec = altRec;
            } else {
                allyRec = altRec;
            }
        }
    }

    if (allyGroups < 1) {
        if (allyOk != 0) list->f1a = allyRec->f24.b;
    } else {
        struct Node_021e80e4* head = list->head;
        struct Entry_021e80e4* e = head->f0;
        if (!(e != 0 && e->f8 != 0 && allyMsg == 0)) {
            if (list->count > 1) {
                if (allyHits > 0) {
                    list->f1a = allyMsg;
                } else if (allyOk != 0) {
                    list->f1a = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), allyRec, 1);
                }
            } else if (allyHits > 0) {
                if (head->f18 > 1) {
                    list->f1a = allyMsg;
                } else if (e == 0 || func_ov000_0215fd90(e, 0xd) == 0) {
                    list->f1a = func_ov024_021e9b24(self, func_ov000_0215ffa0(list->head), allyRec, 0);
                    if (list->f1a == 0) {
                        if (grouped != 0) list->f1a = 2;
                    }
                }
            } else if (allyOk != 0) {
                list->f1a = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), allyRec, 1);
            }
        }
    }

    if (foeGroups < 1) {
        if (foeOk != 0) list->f1c = foeRec->f24.c;
    } else {
        struct Node_021e80e4* head = list->head;
        struct Entry_021e80e4* e = head->f0;
        if (!(e != 0 && e->f8 != 0 && foeMsg == 0)) {
            if (list->count > 1) {
                if (foeHits > 0) {
                    list->f1c = foeMsg;
                } else if (foeOk != 0) {
                    list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), foeRec, 1);
                }
            } else if (foeHits > 0) {
                if (head->f18 > 1) {
                    list->f1c = foeMsg;
                } else if (e == 0 || func_ov000_0215fd90(e, 0xd) == 0) {
                    list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(list->head), foeRec, 0);
                    if (list->f1c == 0) {
                        if (grouped != 0) list->f1c = 5;
                    }
                }
            } else if (foeOk != 0) {
                list->f1c = func_ov024_021e9b24(self, func_ov000_0215ffa0(head), foeRec, 1);
            }
        }
    }

    if (rec->f18.kind == 1) {
        if (list->f1a == 3 || list->f1a == 0x261) {
            list->fc.b0 = 1;
            list->fc.b1 = 1;
        } else if (list->f1a == 2) {
            list->fc.b0 = 1;
            if (allyHits + allyMarked >= 2) list->fc.b1 = 1;
        } else {
            if (allyAll != 0) list->fc.b1 = 1;
        }
        if (list->f1c == 6 || list->f1c == 0x262) {
            list->fc.b3 = 1;
            list->fc.b4 = 1;
        } else if (list->f1c == 5) {
            list->fc.b3 = 1;
            if (foeHits + foeMarked >= 2) list->fc.b4 = 1;
        } else {
            if (foeAll != 0) list->fc.b4 = 1;
        }
    }

    if (fillExtra == 0) return;
    list->f1e = allyRec->f28.a;
    list->f20 = foeRec->f28.b;
    if (forced == 0 && self->f77 == 0) return;
    if (foeRec->f28.a != 0) {
        if (foeRec->f28.b == 0) list->f20 = 9;
    }
}
