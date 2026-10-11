#include <globaldefs.h>

struct GamecardBusLock
{
    volatile unsigned int atomic;
    unsigned short ownerID;
    unsigned short unknown_6;
};

extern "C"
{
    void WaitByLoop(int);
    void func_020ca3ec(int val, void* dst, unsigned len);
}

int WeakLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)());
int WeakUnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)());

// USA: func_020c6d7c // KEEP-NAME
ARM void InitializeGamecardBusOwnership()
{
    static int isInitialized = false;
    if (isInitialized)
    {
        return;
    }

    GamecardBusLock* ndsLock = (GamecardBusLock*)0x027ffff0;
    isInitialized = true;
    ndsLock->atomic = 0;

    WeakLockGamecardBusLock(126, ndsLock, NULL);

    if (ndsLock->unknown_6)
    {
        do
        {
            WaitByLoop(0x400);
        } while (ndsLock->unknown_6);
    }

    ((unsigned int*)0x027fffb0)[0] = 0xffffffff;
    ((unsigned int*)0x027fffb0)[1] = 0xffff0000;

    func_020ca3ec(0, (void*)0x027fffc0, 0x28);
    *(volatile unsigned short*)0x04000204 |= (1 << 11);
    *(volatile unsigned short*)0x04000204 |= (1 << 7);

    WeakUnlockGamecardBusLock(126, ndsLock, NULL);
    WeakLockGamecardBusLock(127, ndsLock, NULL);
}
