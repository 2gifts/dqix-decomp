#include <globaldefs.h>

struct Node02097844 {
    struct Node02097844* next;
    char pad[0xe];
    signed char familyTextID;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    unsigned char* data;
    unsigned char len;
    char pad2[0x20 - 0x19];
};

struct MonsterList {
    struct Node02097844* head;
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Node02097844* arr;
};

extern "C" void _Z24BuildSortedChain02097628Pv(void*);
extern "C" void _Z24BuildSortedChain020976e0Pv(void*);
extern "C" void _Z25RegroupMarkedRuns02097844PP12Node02097844i(struct Node02097844**, int);

extern "C" {
// USA: func_020974b0
extern "C" ARM struct Node02097844* func_020974b0(struct MonsterList* list, int family, int target, bool sort, short groupSize, short* outCount) {
    unsigned short n = list->count;
    struct Node02097844* arr = list->arr;
    list->head = NULL;
    short i1;
    for (i1 = 0; i1 < n; i1++) {
        struct Node02097844* f = &arr[i1];
        f->next = NULL;
        f->bit0 = 1;
    }
    if (family >= 0) {
        short i2;
        for (i2 = 0; i2 < n; i2++) {
            struct Node02097844* e = &arr[i2];
            e->bit0 = (e->familyTextID == family);
        }
    }
    if (target >= 0) {
        unsigned char t = target;
        short i3;
        for (i3 = 0; i3 < n; i3++) {
            struct Node02097844* e = &arr[i3];
            e->bit0 = 0;
            unsigned char j;
            for (j = 0; j < e->len; j++) {
                if (e->data[j] == t) {
                    e->bit0 = 1;
                    break;
                }
            }
        }
    }
    if (!sort) {
        _Z24BuildSortedChain02097628Pv(list);
    } else {
        _Z24BuildSortedChain020976e0Pv(list);
    }
    *outCount = 0;
    struct Node02097844* p = list->head;
    while (p != NULL) {
        (*outCount)++;
        p = p->next;
    }
    _Z25RegroupMarkedRuns02097844PP12Node02097844i((struct Node02097844**)&list->head, groupSize);
    return list->head;
}
}