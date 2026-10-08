#include <globaldefs.h>

#define COMMAND_SYNC 0x60
#define COMMAND_UTILITY 0x61
#define COMMAND_SLEEP_START 0x62
#define COMMAND_SLEEP_END 0x63

#define RESULT_SEND_FAILED 1
#define RESULT_ERROR 2

#define PM_SUCCESS 0

typedef void (*PMCallback)(unsigned long result, void* arg);

struct PMiWork
{
    volatile int lock;
    PMCallback callback;
    void* callbackArg;
    void* work;
};

struct PMStatics
{
    char unknown_0[0xc];
    volatile int sleepEndFlag;
    char unknown_10[0xc];
    PMiWork work;
};

extern PMStatics data_021117ec;

void FirePendingCallback(int result);

// USA: func_020ce308
extern "C" ARM void func_020ce308(unsigned int tag, unsigned int data, unsigned int err)
{
    const unsigned short command = (data & 0x7f00) >> 8;
    unsigned short result = data & 0xff;
    if (err)
    {
        switch (command)
        {
        case COMMAND_UTILITY:
        case COMMAND_SLEEP_START:
            result = RESULT_SEND_FAILED;
            break;
        default:
            result = RESULT_ERROR;
            break;
        }
        FirePendingCallback(result);
        return;
    }
    switch (command)
    {
    case COMMAND_UTILITY:
        if (data_021117ec.work.work)
            *(unsigned short*)data_021117ec.work.work = result;
        result = PM_SUCCESS;
        break;
    case COMMAND_SYNC:
        result = PM_SUCCESS;
        break;
    case COMMAND_SLEEP_START:
        break;
    case COMMAND_SLEEP_END:
        data_021117ec.sleepEndFlag = true;
        break;
    }
    FirePendingCallback(result);
}
