#include <globaldefs.h>

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    short field_e;
    int field_10;
    void* field_14;
};

extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void* loader, const char* a, const char* b, void* alloc);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void* loader, const char* a, void* alloc);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void* loader, int taskID);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void* loader, int id, void** outPtr, unsigned int* outLength);
extern "C" int _Z24ResetHandleState020dfe88P11Obj020dfe88(void* obj);
extern "C" void func_020dfec0(void* p, void* a, void* b, unsigned int c);
extern "C" void func_020e0028(void* p, void* a, void* b, unsigned int c, short* e, int f);
extern "C" int func_020dfd40(void* self, void* a, void* b);

// USA: func_020dfd40
extern "C" ARM int func_020dfd40(void* self, void* a, void* b) {
    Struct020dfc40* p = (Struct020dfc40*)self;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();

    switch (p->field_e) {
    case 1:
        if (a == 0) {
            _Z24ResetHandleState020dfe88P11Obj020dfe88(p);
            return 1;
        }
        if (b != 0) {
            p->field_10 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, (const char*)a, (const char*)b, 0);
        } else {
            p->field_10 = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, (const char*)a, 0);
        }
        p->field_e = 2;
        return func_020dfd40(p, 0, 0);
    case 2:
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, p->field_10) == 0) {
            return 0;
        }
        p->field_e = 3;
        return func_020dfd40(p, 0, 0);
    case 3: {
        void* data = 0;
        unsigned int size = 0;
        short idx;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, p->field_10, &data, &size);
        if (p->field_c < 0) {
            func_020dfec0(p, p->field_14, data, size);
        } else {
            idx = p->field_c;
            func_020e0028(p, p->field_14, data, size, &idx, 1);
        }
        _Z24ResetHandleState020dfe88P11Obj020dfe88(p);
        return 1;
    }
    default:
        return 1;
    }
}