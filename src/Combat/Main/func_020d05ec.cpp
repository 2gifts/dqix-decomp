#include <globaldefs.h>
#include "Filesystem/FSInnerDefs.h"
#include "System/Interrupts.h"

#define BACKUP_MIDDLEWARE ((const void*)0x02000bc4)
#define CARD_STAT_BUSY 0x4
#define CARD_RESULT_SUCCESS 0

typedef void (*CardBackupCallback)(void* arg);

extern "C" void func_02000b9c(const void* symbol);
extern "C" void func_020d03fc(CardReadManager* p);

// USA: func_020d05ec
extern "C" ARM int func_020d05ec(unsigned long src, unsigned long dst, unsigned long len, CardBackupCallback callback,
    void* arg, int isAsync, int reqType, int reqRetry, int reqMode)
{
    CardReadManager* const p = &data_021118e0;
    func_02000b9c(BACKUP_MIDDLEWARE);
    {
        const int lastState = DisableIRQInterrupts();
        if (p->flags & CARD_STAT_BUSY)
            do
                BlockCurrentContext(&p->ongoingReadBlock);
            while (p->flags & CARD_STAT_BUSY);
        p->flags |= CARD_STAT_BUSY;
        p->onComplete = (CardReadManager::CompletionCallback)callback;
        p->handle = (NitroHandle*)arg;
        SetIRQInterruptState(lastState);
    }
    p->cartridgeReadOffset = src;
    p->writeDst = (unsigned char*)dst;
    p->writeLength = len;
    p->unknown_2c[0] = reqType;
    p->unknown_2c[1] = reqRetry;
    p->unknown_2c[2] = reqMode;
    if (isAsync)
    {
        SendTaskToReadContext(func_020d03fc);
        return true;
    }
    data_021118e0.currentTaskExecutionContext = data_02111304.activeContext;
    func_020d03fc(p);
    return p->pSharedData->unknown_0 == CARD_RESULT_SUCCESS;
}
