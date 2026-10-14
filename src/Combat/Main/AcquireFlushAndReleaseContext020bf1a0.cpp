#include <globaldefs.h>

struct RefNode020c80f8;
struct Mutex;
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);

struct Foo020bcbc4;
void CallIfFlag0x24Bit0(struct Foo020bcbc4* obj);

struct Obj020bf238;
void ReleaseAndFlushContext020bf238(struct Obj020bf238* obj);

struct Ctx020bf1a0 { int f0; unsigned char* f4; };

extern char data_02110a28;
extern struct Ctx020bf1a0 data_021103b0;

// USA: func_020bf1a0  (semantic: AcquireFlushAndReleaseContext020bf1a0)
extern "C" ARM void func_020bf1a0(void* obj) {
    LockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        LockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }

    if ((*(int*)((char*)obj + 0x110) << 30) >> 31) {
        CallIfFlag0x24Bit0((struct Foo020bcbc4*)obj);
    }
    if ((*(int*)((char*)obj + 0x110) << 31) >> 31) {
        void (*fp)(void*) = *(void(**)(void*))((char*)obj + 0x170);
        fp(obj);
    }

    ReleaseAndFlushContext020bf238((struct Obj020bf238*)obj);
    UnlockMutex((Mutex*)&data_02110a28);
    if (data_021103b0.f4 != 0) {
        UnlockMutex((Mutex*)(data_021103b0.f4 + 0x4c8));
    }
}
