#include <globaldefs.h>

int GetGlobal02109400(void);
extern "C" int _Z18AlwaysTrue02094b4cv(void);
extern "C" void _Z21BlankFunction02094b3cv(void);
extern "C" void _Z21BlankFunction02094b34v(void);
struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);

struct LoaderSub_021561b0 {
    char pad[0x47a];
    unsigned char state;
    unsigned char pad47b;
    unsigned int flags;
};

struct Loader_021561b0 {
    char pad[0x2000];
    struct LoaderSub_021561b0 sub;
};

// USA: func_ov002_021561b0  (semantic: ResetOrFinalizeLoaderState_021561b0)
extern "C" ARM void func_ov002_021561b0(struct Loader_021561b0* self) {
    unsigned int flags = self->sub.flags;
    if ((flags & 2) == 0) {
        return;
    }
    unsigned char state = self->sub.state;
    if (state == 0) {
        void* g = (void*)GetGlobal02109400();
        func_02094ab0((struct Obj02094ab0*)g);
        ((void (*)(void*, int)) & _Z21BlankFunction02094b3cv)(g, 0xc);
        ((void (*)(void*, int, int, int, int)) & _Z21BlankFunction02094b34v)(g, 0x64, 0x208, 0, 0);
        self->sub.state = self->sub.state + 1;
        return;
    }
    if (state != 1) {
        return;
    }
    GetGlobal02109400();
    if (!_Z18AlwaysTrue02094b4cv()) {
        return;
    }
    self->sub.flags = self->sub.flags & ~2;
    self->sub.state = 0;
}
