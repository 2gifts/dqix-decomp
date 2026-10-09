#include <globaldefs.h>
#include "GameState/GameState.h"

struct Request021d3950 {
    unsigned char mode;
    signed char idx;
    unsigned char mask;
    unsigned char id;
};

struct Entry021d3950 {
    unsigned int timer : 9;
    unsigned int unk9 : 8;
    unsigned int flags : 8;
    unsigned int count : 4;
    unsigned int unk29 : 2;
    unsigned int active : 1;
};

struct Node021d3950 {
    unsigned int unk0 : 16;
    unsigned int id : 7;
    unsigned int unk23 : 9;
    unsigned int unk4_0 : 21;
    unsigned int flags : 8;
    unsigned int unk4_29 : 3;
    char pad8[0x6c - 8];
    struct Node021d3950* next;
};

struct Head0208e7a4 {
    char pad0[4];
    struct Node021d3950* head;
};

struct Cont0208f3b4;

extern "C" Head0208e7a4* func_0208e0a8(void);
Entry021d3950* GetNegativeEntry(char* obj, int index);
extern "C" Node021d3950* _Z26FindNodeByPackedId0208e7a4P12Head0208e7a4j(Head0208e7a4* owner, unsigned int key);
Cont0208f3b4* GetData02109020(void);
extern "C" void _Z23RemoveNodeByKey0208f3b4P12Cont0208f3b4i(Cont0208f3b4* c, int key);

// USA: func_ov017_021d3950
extern "C" ARM int func_ov017_021d3950(Request021d3950* req) {
    GameState* gs = GameState::GetInstance();
    Head0208e7a4* list = func_0208e0a8();
    Entry021d3950* entry = GetNegativeEntry((char*)gs, req->id);
    if (entry != NULL && (req->mask & entry->flags) != 0) {
        entry->flags = ~req->mask & entry->flags;
        entry->timer = entry->count * 30;
        Node021d3950* node = _Z26FindNodeByPackedId0208e7a4P12Head0208e7a4j(list, req->id);
        if (node == NULL) {
            return 1;
        }
        node->flags = ~req->mask & node->flags;
        Node021d3950* p;
        int i = 0;
        for (p = list->head; p != NULL; p = p->next, i++) {
            if (p->id == req->id) {
                break;
            }
        }
        if (p == NULL) {
            return 1;
        }
        int bit;
        for (bit = 0; bit < 8; bit++) {
            if (req->mask & (1 << bit)) {
                break;
            }
        }
        if (p != NULL && bit < 8) {
            _Z23RemoveNodeByKey0208f3b4P12Cont0208f3b4i(GetData02109020(), bit + i * 8);
        }
        return 1;
    }
    return 0;
}
