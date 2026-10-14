#include <globaldefs.h>
#include "GameState/GameState.h"

extern char data_020feffc[];

int GetGlobalField0x10_0202d6a8(void);
int AdvanceStateIfState2_0202d0b4(void);
void SleepCurrentContext(unsigned int);
int Init0202dc40(int mode, void* src);
unsigned long long GetCurrentTimestamp(void);
extern "C" int func_02001aec(void* a, void* b, int n);

// USA: func_0202b900
extern "C" ARM int func_0202b900(int* obj, unsigned char* key) {
    char* entries;
    int i;
    int result;
    int count;
    int j;
    int stride;
    GameState* battleStruct;
    unsigned long long ts;

    i = 0;
    while (GetGlobalField0x10_0202d6a8() == 2) {
        AdvanceStateIfState2_0202d0b4();
        i++;
        if (i > 0x1388) {
            return -1;
        }
        SleepCurrentContext(1);
    }

    i = 0;
    while (GetGlobalField0x10_0202d6a8() != 1) {
        i++;
        if (i > 0x1388) {
            return -1;
        }
        SleepCurrentContext(1);
    }

    count = obj[3];
    result = -1;
    j = 0;
    stride = 0xc0;
    entries = (char*)obj;
    entries += 0x10;

    for (; j < count; j++) {
        if (func_02001aec(key, entries + j * stride + 4, 6) == 0) {
            Init0202dc40(5, data_020feffc + j * stride);
            *obj = 6;
            battleStruct = GameState::GetInstance();
            ts = GetCurrentTimestamp();
            *(unsigned int*)((char*)battleStruct + 0x3f0) = (unsigned int)ts;
            result = j;
            *(unsigned int*)((char*)battleStruct + 0x3f4) = (unsigned int)(ts >> 32);
            break;
        }
    }
    return result;
}
