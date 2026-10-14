#include <globaldefs.h>

extern void* data_ov031_0224e60c;

struct Mutex;
void* LockMutex(Mutex*);

struct RefNode020c80f8;
void UnlockMutex(Mutex*);

// USA: func_ov031_022191e0  (semantic: GetField1000AndReleaseRef_022191e0)
extern "C" ARM int func_ov031_022191e0(void) {
    void *base = data_ov031_0224e60c;
    LockMutex((Mutex*)((char*)base + 0x1000 + 0x1dc));
    base = data_ov031_0224e60c;
    void *node = (char*)base + 0x1000 + 0x1dc;
    int r4 = *(int*)((char*)base + 0x1000);
    UnlockMutex((Mutex*)node);
    return r4;
}
