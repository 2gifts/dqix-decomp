#include <globaldefs.h>
#pragma optimize_for_size off

struct Mutex;
int TryLockMutex(Mutex*);
void LockMutex(Mutex*);
extern "C" void _Z11UnlockMutexP5Mutex(void* mutex);
extern "C" void func_0200159c(int status);

struct ThreadInfo02003ddc {
    unsigned char pad[0x6c];
    int id;
};

struct ThreadTable02003ddc {
    int unk0;
    ThreadInfo02003ddc* current;
};

typedef void (*SlotHandler02003ddc)(int slot);

extern int data_020f3060;
extern ThreadTable02003ddc data_02111304;
extern int data_020f2f70[];
extern int data_020f2f94[];
extern SlotHandler02003ddc data_020f3394[];

// USA: func_02003ddc
extern "C" ARM int func_02003ddc(int slot) {
    SlotHandler02003ddc handler;

    if (slot < 1 || slot > 7) {
        return -1;
    }

    do {
        if (TryLockMutex((Mutex*)&data_020f3060) == 0) {
            data_020f2f70[7] = data_02111304.current->id;
            data_020f2f94[7] = 1;
            break;
        }
        if (data_020f2f70[7] == data_02111304.current->id) {
            data_020f2f94[7] = data_020f2f94[7] + 1;
            break;
        }
        LockMutex((Mutex*)&data_020f3060);
        data_020f2f70[7] = data_02111304.current->id;
        data_020f2f94[7] = 1;
    } while (0);

    handler = data_020f3394[slot - 1];
    if (handler != (SlotHandler02003ddc)1) {
        data_020f3394[slot - 1] = 0;
    }

    data_020f2f94[7] = data_020f2f94[7] - 1;
    if (data_020f2f94[7] == 0) {
        _Z11UnlockMutexP5Mutex(&data_020f3060);
    }

    if (handler == (SlotHandler02003ddc)1 || (handler == 0 && slot == 1)) {
        return 0;
    }
    if (handler == 0) {
        func_0200159c(0);
    }
    handler(slot);
    return 0;
}
