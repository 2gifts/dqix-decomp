#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);

struct Entry020e3054 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

struct Ctx020e30f0 {
    char pad[0xfc0];
    int busy;
};

Entry020e3054* FindEntryByField1(Entry020e3054* list, int key);
void Dispatch020e3428(void* a, int b);
void Dispatch020e3328(void* a, int b);

// USA: func_020e30f0
extern "C" ARM void func_020e30f0(Entry020e3054* list) {
    void* ctx = func_0202ae18();
    if (!CheckField0NonZero((int*)ctx)) return;

    Entry020e3054* e = list;
    int i;
    for (i = 0; i < 8; i++, e++) {
        if (e->f2 == 2 && ((Ctx020e30f0*)ctx)->busy == 0) {
            if (e->f3 <= 0x1e) {
                e->f3 = e->f3 + 1;
            } else {
                unsigned char owner = e->f0;
                unsigned char key = e->f1;
                Dispatch020e3428(list, key);
                e->f1 = key;
                e->f0 = owner;
                e->f2 = 4;
            }
        }
    }

    unsigned char* ids = (unsigned char*)list + 0x20;
    int j;
    for (j = 0; j < 8; j++, ids++) {
        int id = *ids;
        if (id == 0) continue;
        Entry020e3054* found = FindEntryByField1(list, id);
        if (found != NULL) {
            unsigned char state = found->f2;
            int cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)ctx);
            if (found->f0 != cur && state == 1) state = 3;
            if (state == 1 || state == 4 || state == 5) {
                *ids = 0;
            } else if (state != 2) {
                Dispatch020e3328(list, id);
            }
        } else {
            Dispatch020e3328(list, id);
        }
    }
}
