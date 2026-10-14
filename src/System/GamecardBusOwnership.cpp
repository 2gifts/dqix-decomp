#include "System/GamecardBusOwnership.h"
#include "System/Interrupts.h"
#include <globaldefs.h>
#include <asmhacks.h>
#include "std_library_functions.h"

#define REG_EXTMEMCTRL (*(volatile unsigned short*)0x04000204)
#define EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS (1 << 7)
#define EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS (1 << 11)

#define ADDR_REGISTERED_OWNERS_LOW 0x027fffb0
#define REGISTERED_OWNER_FLAGS ((unsigned int*)ADDR_REGISTERED_OWNERS_LOW)

#define PTR_NDS_BUS_LOCK ((GamecardBusLock*)0x027fffe0)
#define PTR_GBA_BUS_LOCK ((GamecardBusLock*)0x027fffe8)
#define PTR_UNKNOWN_BUS_LOCK ((GamecardBusLock*)0x027ffff0)

#pragma optimize_for_size off

extern "C"
{
    void WaitByLoop(int);

    void func_020ca3ec(int val, void* dst, unsigned len);

    extern "C" unsigned int _Z19AtomicSwap_020ca7e0iPi(unsigned int newValue, volatile unsigned int* atomic);
}

int TryLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict);
int WeakLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)());
int WeakUnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)());

void MarkGBABusAcquired();
void MarkGBABusReleased();

void MarkNDSBusAcquired();
void MarkNDSBusReleased();

int LockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict)
{
    if (TryLockGamecardBusLock(owner, lock, onLock, strict) > 0)
    {
        do {
            WaitByLoop(0x400);
        } while (TryLockGamecardBusLock(owner, lock, onLock, strict) > 0);
    }
}

int WeakLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)())
{
    return LockGamecardBusLock(owner, lock, onLock, false);
}

int UnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)(), bool strict)
{
    if (owner != lock->ownerID)
        return -2;

    int priorState;
    if (strict)
        priorState = DisableIRQAndFIQInterrupts();
    else
        priorState = DisableIRQInterrupts();

    lock->ownerID = 0;
    if (onUnlock != NULL)
        onUnlock();

    lock->atomic = 0;

    if (strict)
        SetIRQAndFIQInterruptState(priorState);
    else
        SetIRQInterruptState(priorState);
    return 0;
}

int WeakUnlockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onUnlock)())
{
    return UnlockGamecardBusLock(owner, lock, onUnlock, false);
}

int TryLockGamecardBusLock(unsigned short owner, GamecardBusLock* lock, void (*onLock)(), bool strict)
{
    int priorState;
    if (strict)
        priorState = DisableIRQAndFIQInterrupts();
    else
        priorState = DisableIRQInterrupts();

    int oldAtomic = _Z19AtomicSwap_020ca7e0iPi(owner, &lock->atomic);
    if (oldAtomic == 0)
    {
        if (onLock != NULL)
            onLock();
        lock->ownerID = owner;
    }

    if (strict)
        SetIRQAndFIQInterruptState(priorState);
    else
        SetIRQInterruptState(priorState);
    return oldAtomic;
}

int InternalReleaseGBABus(unsigned short owner)
{
    return UnlockGamecardBusLock(owner, PTR_GBA_BUS_LOCK, &MarkGBABusReleased, true);
}

#ifdef __MWERKS__
asm int ReleaseGBABus(unsigned short owner)
{
    ldr r1, =InternalReleaseGBABus
    bx r1
}
#else
int ReleaseGBABus(unsigned short owner)
{
    return InternalReleaseGBABus(owner);
}
#endif

int TryAcquireGBABus(unsigned short owner)
{
    return TryLockGamecardBusLock(owner, PTR_GBA_BUS_LOCK, &MarkGBABusAcquired, true);
}

void MarkGBABusAcquired()
{
    REG_EXTMEMCTRL &= ~EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS;
}

void MarkGBABusReleased()
{
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_GBA_BUS;
}

int AcquireNDSBus(unsigned short owner)
{
    return WeakLockGamecardBusLock(owner, PTR_NDS_BUS_LOCK, &MarkNDSBusAcquired);
}

int ReleaseNDSBus(unsigned short owner)
{
    return WeakUnlockGamecardBusLock(owner, PTR_NDS_BUS_LOCK, &MarkNDSBusReleased);
}

void MarkNDSBusAcquired()
{
    REG_EXTMEMCTRL &= ~EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS;
}

void MarkNDSBusReleased()
{
    REG_EXTMEMCTRL |= EXTMEMCTRL_FLAG_RELINQUISH_NDS_BUS;
}

unsigned short GetLockOwner(GamecardBusLock* lock)
{
    return lock->ownerID;
}

inline int leadZeroCount(unsigned int what)
{
    int ret;
    __asm("clz %[output], %[input]" : : [output] "=r" (ret), [input] "r" (what));
    return ret;
}
