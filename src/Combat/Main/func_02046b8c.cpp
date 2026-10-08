#include <globaldefs.h>

struct Node02046b8c {
    signed char id;
    char pad[3];
    struct Node02046b8c* next;
};

struct List02046b8c {
    struct Node02046b8c* head;
    struct Node02046b8c* tail;
};

// USA: func_02046b8c
extern "C" ARM void func_02046b8c(struct List02046b8c* list, int id) {
    struct Node02046b8c* prev;
    struct Node02046b8c* mhead;
    struct Node02046b8c* p = list->head;
    struct Node02046b8c* t = p;
    while (t != 0) {
        t = t->next;
    }
    prev = 0;
    mhead = 0;
    while (p != 0) {
        struct Node02046b8c* next = p->next;
        if (p->id == id) {
            if (prev != 0) {
                prev->next = next;
            } else {
                list->head = next;
            }
            p->next = 0;
            if (mhead != 0) {
                struct Node02046b8c* q = mhead;
                struct Node02046b8c* n;
                while ((n = q->next) != 0) {
                    q = n;
                }
                q->next = p;
            } else {
                mhead = p;
            }
        } else {
            prev = p;
        }
        p = next;
    }
    if (mhead != 0) {
        t = mhead;
        while (t->next != 0) {
            t = t->next;
        }
        struct Node02046b8c* h = list->head;
        t->next = h;
        list->head = mhead;
        t = mhead;
        while (t->next != 0) {
            t = t->next;
        }
        list->tail = t;
        t = list->head;
        while (t != 0) {
            t = t->next;
        }
    }
}