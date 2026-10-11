#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0208e0a8(void);
extern "C" void* func_02057924(void);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int size);
extern "C" int rand(void);
extern "C" int _s32_div_f(int a, int b);
extern "C" int func_02018fbc(int seed, void* v);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int a, int b);
extern "C" void* _ZN8Object3D25GetCurrentAnimationConfigEv(void* obj);
extern "C" BCFG::AnimationRecord* _ZN4BCFG18GetAnimationRecordEi(void* list, int index);
extern "C" int _Z22IsMatchingName0208e824PvPc(void* unused, char* str);

struct Entry0208f168 {
    unsigned int low9 : 9;
    unsigned int nibA : 4;
    unsigned int nibB : 4;
    unsigned int id8 : 8;
    unsigned int type4 : 4;
    unsigned int kind : 2;
    unsigned int flag : 1;
};

struct NodeFlags0208f168 {
    unsigned int a21 : 21;
    unsigned int b21 : 8;
    unsigned int c29 : 3;
};

struct Node0208f168 {
    unsigned int packed;
    struct NodeFlags0208f168 f4;
    struct Entry0208f168* owner;
    Vector3i vec[8];
    struct Node0208f168* next;
};

struct Head0208f168 {
    char pad[4];
    struct Node0208f168* head;
};

struct Item0208f168 {
    int index;
    Vector3i vec;
    int frame;
    struct Item0208f168* link;
};

struct Self0208f168 {
    char pad[8];
    void* obj;
    struct Item0208f168* head;
};

// USA: func_0208f168
extern "C" ARM void func_0208f168(struct Self0208f168* self, void* alloc) {
    if (alloc == 0) {
        return;
    }

    void* g = func_02012fe4();
    char* name = *(char**)((char*)g + 8);
    struct Head0208f168* h = (struct Head0208f168*)func_0208e0a8();

    if (name == 0) {
        return;
    }
    if (_Z22IsMatchingName0208e824PvPc(h, name + 5) == 0) {
        return;
    }

    if (self->obj != 0) {
        _ZN8Object3D21MaybeSetBCFGAnimationEii(self->obj, 0, 0);
        void* cfg = _ZN8Object3D25GetCurrentAnimationConfigEv(self->obj);
        if (cfg == 0) {
            return;
        }
        BCFG::AnimationRecord* rec = _ZN4BCFG18GetAnimationRecordEi(cfg, 0);
        if (rec == 0) {
            return;
        }

        GameState* bs = GameState::GetInstance();
        struct Entry0208f168* table = (struct Entry0208f168*)((char*)bs + 0xdc + 0x5c00);
        struct Node0208f168* node = h->head;
        func_02057924();
        bs->GetProtagonist();

        unsigned int counter = 0;
        while (node != 0) {
            int idx = (node->packed << 9) >> 25;
            struct Entry0208f168* e = &table[idx];
            if (e->flag) {
                node->owner = e;
                node->f4.b21 = ((*(unsigned int*)e << 7) >> 24);
                int count = e->nibA;
                if (idx >= 0x62) {
                    count = 8;
                }
                int j = 0;
                for (; j < count; j++) {
                    Vector3i* v = node->vec;
                    if (((*(unsigned int*)e << 7) >> 24) & (1 << j)) {
                        struct Item0208f168* item = (struct Item0208f168*)_ZN13SafeAllocator8AllocateEj(alloc, 0x18);
                        if (item == 0) {
                            return;
                        }
                        item->index = j + (counter << 3);
                        int base = rec->startTime;
                        item->frame = base + (rand() % (rec->endTime - base));
                        node->vec[j].y = func_02018fbc((int)g, (void*)&v[j]);
                        _ZN8Vector3iaSERKS_((int*)&item->vec, (int*)&v[j]);
                        struct Item0208f168* n = self->head;
                        if (n == 0) {
                            self->head = item;
                            item->link = 0;
                        } else {
                            while (n->link != 0) {
                                n = n->link;
                            }
                            n->link = item;
                            item->link = 0;
                        }
                    }
                }
            }
            counter = (counter + 1) & 0xff;
            node = node->next;
        }
    } else {
        return;
    }
}
