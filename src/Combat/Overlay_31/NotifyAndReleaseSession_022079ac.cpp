#include <globaldefs.h>

struct Mutex;
void* LockMutex(Mutex*);
void SetActiveContextByte9_0220aa68(unsigned char v);
struct RefNode020c80f8;
void UnlockMutex(Mutex*);

// USA: func_ov031_022079ac  (semantic: NotifyAndReleaseSession_022079ac)
extern "C" ARM int func_ov031_022079ac(void* p0) {
    void* session = *(void**)((char*)p0 + 4);
    void* mgr = *(void**)((char*)session + 0x64);
    void* ctx = *(void**)((char*)mgr + 0xc4);
    LockMutex((Mutex*)((char*)mgr + 0xe0));
    int v = *(int*)((char*)p0 + 0x10);
    if (v != 0) {
        *(int*)((char*)ctx + 0xc) = v;
        SetActiveContextByte9_0220aa68(1);
        *(unsigned char*)((char*)session + 0x73) = 4;
    } else {
        *(unsigned char*)((char*)session + 0x73) = 0;
        SetActiveContextByte9_0220aa68(0);
        *(int*)((char*)ctx + 0xc) = 0;
    }
    UnlockMutex((Mutex*)((char*)mgr + 0xe0));
    return 0;
}
