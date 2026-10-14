#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02049c08;
struct Obj02033874;
struct Node021df5cc;

struct Node021df568 {
    int key;
    struct Node021df568* prev;
    struct Node021df568* next;
    GameObject* obj;
};

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
Vector3fix GetSubTriple02049c08(struct Obj02049c08* obj);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);
void ResetFields_021df554(void* obj);
struct Node021df568* InsertSorted_021df568(struct Node021df568* head, struct Node021df568* newNode);
struct Node021df5cc* FindLastNode021df5cc(struct Node021df5cc* node);
extern "C" fix32_t fix32_Divide(fix32_t a, fix32_t b);

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Obj021def64 {
    char pad[0x29c];
    void* list;
};

// USA: func_ov025_021def64
extern "C" ARM void func_ov025_021def64(struct Obj021def64* self, int slot, int index) {
    struct Node021df568 nodesX[16];
    struct Node021df568 nodesZ[16];
    int ids[16];
    GameObject* objs[16];
    GameState* gs = GameState::GetInstance();
    int count = DispatchByIndex021820bc(self->list, slot, index, (int)ids);
    if (count == 0) return;

    int n = 0;
    int i;
    for (i = 0; i < count; i++) {
        objs[n] = gs->GetCombatantByIndex(ids[i]);
        if (objs[n] == NULL) continue;
        GameObject* o = objs[i];
        o->obj3D_.position_ = GetSubTriple02049c08((struct Obj02049c08*)o);
        SetVecYFromValue02033874((struct Obj02033874*)o, 0);
        n++;
    }
    count = n;

    {
        int k;
        int gapSum;
        int radSum;
        struct Node021df568* head;
        struct Node021df568* next;
        fix32_t scale;
        int pos;
        int r;
        int gap;
        struct Node021df568* cur;
        struct Node021df568* last;
        int span;
        int i2;
        for (i = 0; i < count; i++) {
            ResetFields_021df554(&nodesX[i]);
            GameObject* o = objs[i];
            nodesX[i].key = GetSubTriple02049c08((struct Obj02049c08*)o).x;
            nodesX[i].obj = o;
        }
        head = &nodesX[0];
        for (i2 = 1; i2 < count; i2++) {
            head = InsertSorted_021df568(head, &nodesX[i2]);
        }
        last = (struct Node021df568*)FindLastNode021df5cc((struct Node021df5cc*)head);
        span = (last->key + last->obj->obj3D_.GetRadius() / 2) - (head->key - head->obj->obj3D_.GetRadius() / 2);
        if (span > 0x4000 && n > 1) {
            int gaps[16];
            gapSum = 0;
            radSum = 0;
            cur = head;
            k = 0;
            for (; (next = cur->next) != NULL; cur = cur->next) {
                r = cur->obj->obj3D_.GetRadius();
                gap = (next->key - cur->key) - (next->obj->obj3D_.GetRadius() / 2 + r / 2);
                gaps[k] = gap;
                gapSum += gap;
                k++;
            }
            for (cur = head; cur != NULL; cur = cur->next) {
                radSum += cur->obj->obj3D_.GetRadius();
            }
            scale = 0;
            if (radSum < 0x4000 && gapSum != 0) {
                scale = fix32_Divide(0x4000 - radSum, gapSum);
            }
            k = 0;
            cur = head;
            gapSum = 0;
            while ((cur = cur->next) != NULL) {
                gaps[k] = FxMul(gaps[k], scale);
                gapSum += gaps[k];
                k++;
            }
            pos = -((radSum + gapSum) / 2);
            k = 0;
            for (cur = head; cur != NULL; cur = cur->next, k++) {
                pos += cur->obj->obj3D_.GetRadius() / 2;
                Vector3fix p = cur->obj->obj3D_.position_;
                p.x = pos;
                cur->key = pos;
                cur->obj->obj3D_.position_ = p;
                pos += cur->obj->obj3D_.GetRadius() / 2;
                pos += gaps[k];
            }
        } else {
            int off = -((head->key - head->obj->obj3D_.GetRadius() / 2) + span / 2);
            for (; head != NULL; head = head->next) {
                Vector3fix p = head->obj->obj3D_.position_;
                p.x += off;
                head->obj->obj3D_.position_ = p;
            }
        }
    }

    {
        int k;
        int gapSum;
        int radSum;
        struct Node021df568* head;
        struct Node021df568* last;
        int span;
        struct Node021df568* next;
        fix32_t scale;
        int pos;
        int r;
        int gap;
        struct Node021df568* cur;
        int i2;
        for (i = 0; i < count; i++) {
            ResetFields_021df554(&nodesZ[i]);
            GameObject* o = objs[i];
            nodesZ[i].key = GetSubTriple02049c08((struct Obj02049c08*)o).z;
            nodesZ[i].obj = o;
        }
        head = &nodesZ[0];
        for (i2 = 1; i2 < count; i2++) {
            head = InsertSorted_021df568(head, &nodesZ[i2]);
            for (struct Node021df568* p = head; p != NULL; p = p->next) {
            }
        }
        last = (struct Node021df568*)FindLastNode021df5cc((struct Node021df5cc*)head);
        span = (last->key + last->obj->obj3D_.GetRadius() / 2) - (head->key - head->obj->obj3D_.GetRadius() / 2);
        if (span > 0x4000 && n > 1) {
            int gaps[16];
            gapSum = 0;
            radSum = 0;
            cur = head;
            k = 0;
            for (; (next = cur->next) != NULL; cur = cur->next) {
                r = cur->obj->obj3D_.GetRadius();
                gap = (next->key - cur->key) - (next->obj->obj3D_.GetRadius() / 2 + r / 2);
                gaps[k] = gap;
                gapSum += gap;
                k++;
            }
            for (cur = head; cur != NULL; cur = cur->next) {
                radSum += cur->obj->obj3D_.GetRadius();
            }
            scale = 0;
            if (radSum < 0x4000 && gapSum != 0) {
                scale = fix32_Divide(0x4000 - radSum, gapSum);
            }
            k = 0;
            cur = head;
            gapSum = 0;
            while ((cur = cur->next) != NULL) {
                gaps[k] = FxMul(gaps[k], scale);
                gapSum += gaps[k];
                k++;
            }
            pos = -((radSum + gapSum) / 2);
            k = 0;
            for (cur = head; cur != NULL; cur = cur->next) {
                pos += cur->obj->obj3D_.GetRadius() / 2;
                Vector3fix p = cur->obj->obj3D_.position_;
                p.z = pos;
                cur->key = pos;
                cur->obj->obj3D_.position_ = p;
                pos += cur->obj->obj3D_.GetRadius() / 2;
                pos += gaps[k];
                k++;
            }
        } else {
            int off = -((head->key - head->obj->obj3D_.GetRadius() / 2) + span / 2);
            for (; head != NULL; head = head->next) {
                Vector3fix p = head->obj->obj3D_.position_;
                p.z += off;
                head->obj->obj3D_.position_ = p;
            }
        }
    }
}
