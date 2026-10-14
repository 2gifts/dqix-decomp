#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    short field_e;
    int field_10;
    void* field_14;
};

struct SafeAllocator;
struct Obj020dfe88;
int ResetHandleState020dfe88(Obj020dfe88*);
extern "C" void func_020dfec0(void* p, void* a, void* b, unsigned int c);
extern "C" void func_020e0028(void* p, void* a, void* b, unsigned int c, short* e, int f);
extern "C" int func_020dfd40(void* self, void* a, void* b);

// USA: func_020dfd40
extern "C" ARM int func_020dfd40(void* self, void* a, void* b) {
    Struct020dfc40* p = (Struct020dfc40*)self;
    void* loader = BackgroundLoader::GetInstance();

    switch (p->field_e) {
    case 1:
        if (a == 0) {
            ResetHandleState020dfe88((Obj020dfe88*)p);
            return 1;
        }
        if (b != 0) {
            p->field_10 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2((const char*)a, (const char*)b, (SafeAllocator*)0);
        } else {
            p->field_10 = ((BackgroundLoader*)loader)->QueueLoadFile((const char*)a, (SafeAllocator*)0);
        }
        p->field_e = 2;
        return func_020dfd40(p, 0, 0);
    case 2:
        if (((BackgroundLoader*)loader)->GetTaskStatus(p->field_10) == 0) {
            return 0;
        }
        p->field_e = 3;
        return func_020dfd40(p, 0, 0);
    case 3: {
        void* data = 0;
        unsigned int size = 0;
        short idx;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(p->field_10, &data, &size);
        if (p->field_c < 0) {
            func_020dfec0(p, p->field_14, data, size);
        } else {
            idx = p->field_c;
            func_020e0028(p, p->field_14, data, size, &idx, 1);
        }
        ResetHandleState020dfe88((Obj020dfe88*)p);
        return 1;
    }
    default:
        return 1;
    }
}
