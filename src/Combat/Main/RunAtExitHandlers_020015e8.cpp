#include <globaldefs.h>
#pragma optimize_for_size off

struct Mutex;
int TryLockMutex(Mutex*);
void LockMutex(Mutex*);
void UnlockMutex(Mutex*);
extern "C" void func_02001878(int status);
extern "C" void func_0200f368();

struct ThreadInfo020015e8 {
    unsigned char pad[0x6c];
    int id;
};

struct ThreadTable020015e8 {
    int unk0;
    ThreadInfo020015e8* current;
};

struct HandlerList020015e8 {
    void (*finalizer)();
    int unk4;
    int count;
    int unkc;
    void (*funcs[64])();
};

extern int data_020f2fb8;
extern ThreadTable020015e8 data_02111304;
extern int data_020f2f70;
extern int data_020f2f94;
extern HandlerList020015e8 data_020f2e60;

// USA: func_020015e8  (semantic: RunAtExitHandlers_020015e8)
extern "C" ARM void func_020015e8() {
    do {
        if (TryLockMutex((Mutex*)&data_020f2fb8) == 0) {
            data_020f2f70 = data_02111304.current->id;
            data_020f2f94 = 1;
            break;
        }
        if (data_020f2f70 == data_02111304.current->id) {
            data_020f2f94 = data_020f2f94 + 1;
            break;
        }
        LockMutex((Mutex*)&data_020f2fb8);
        data_020f2f70 = data_02111304.current->id;
        data_020f2f94 = 1;
    } while (0);

    if (data_020f2e60.count > 0) {
        do {
            int next = *(volatile int*)&data_020f2e60.count - 1;
            void (*handler)() = data_020f2e60.funcs[next];
            data_020f2e60.count = next;
            handler();
        } while (data_020f2e60.count > 0);
    }

    data_020f2f94 = data_020f2f94 - 1;
    if (data_020f2f94 == 0) {
        UnlockMutex((Mutex*)&data_020f2fb8);
    }

    if (data_020f2e60.finalizer != 0) {
        data_020f2e60.finalizer();
        data_020f2e60.finalizer = 0;
    }

    func_02001878(0);
    func_0200f368();
}
